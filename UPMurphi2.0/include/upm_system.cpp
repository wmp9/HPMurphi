/*
* Universal Planner CGMurphi Release 2.0.b1
* Copyright (C) 2007 - 2010: G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio
*
* Read the file "license" distributed with these sources, or call
* UPMurphi with the -l switch for additional information.
* Current release developed by G. Della Penna (giuseppe.dellapenna@univaq.it)
*
*/

/************************************************************/
/* StateManager */
/************************************************************/
StateManager::StateManager(bool createqueue, unsigned long NumStates)
: NumStates(NumStates),num_goals(0),transitions(NULL),goals(NULL),errors(NULL),
  statesCurrentLevel(0), statesNextLevel(0), currentLevel(0),
  pno(1.0),num_errors(0)
{



  if (createqueue) {
      queue = new state_queue((unsigned long) (gPercentActiveStates * NumStates) );
MEMTRACKALLOC
PAUSE

  } else {
      queue = new state_stack((unsigned long) (gPercentActiveStates * NumStates) );
MEMTRACKALLOC  
  }
  the_states = new state_set(NumStates);  
MEMTRACKALLOC
PAUSE
  
  transitions = Storage->getTransitionsFile(true);
  PAUSE
  
  goals = Storage->getGoalsFile(true);
  errors = Storage->getErrorsFile(true);
  PAUSE
    
}

StateManager::~StateManager()
{
  if (queue != NULL) delete queue;
  if (the_states != NULL) delete the_states;
}

bool StateManager::Add(state * s, bool valid, bool permanent, unsigned long *index, bool *iserror)
{
  unsigned long state_index;
  if (iserror!=NULL) (*iserror)=false;
  
  
  if ( !the_states->was_present(s, valid, permanent, &state_index) ) {
  
  	  //fprintf(stderr,"stato di arrivo (fresh) %lu ",state_index);
  
      // Uli: invariant check moved here
      if (!Properties->CheckInvariants()) {
		if (iserror!=NULL) (*iserror)=true;
		num_errors++;
#ifdef HASHC
	//fprintf(stderr,"DELETING STATE %x",s);
	delete s;
#endif  			
/* GDP: do not stop on invariant fail, simply exclude them from exploration
	  curstate = s;
#ifdef HASHC
        if (args->trace_file.value)  NumCurState = TraceFile->numLast();
#endif
        Error.Deadlocked("Invariant \"%s\" failed.",Properties->LastInvariantName());
      }
*/	  			
      } else if (Properties->CheckGoals()!=-1) {
			AddGoal(state_index);
			num_goals++;		
#ifdef HASHC
	//fprintf(stderr,"DELETING STATE %x",s);
	delete s;
#endif  			
	  } else {
			statesNextLevel++;
			queue->enqueue(s,state_index);

//			queue->Print();
	  }

	  if (index!=NULL) *index = state_index;
	  
      if ( args->trace_all.value ) Reporter->print_trace_all();
      Reporter->print_progress();

#ifdef HASHC
	//fprintf(stderr,"DELETING STATE %x",s);
	//delete s;
#endif		
      return TRUE;
  
  } else {
	if (iserror!=NULL && !Properties->CheckInvariants()) { 
		(*iserror)=true;
	}
	
	//fprintf(stderr,"stato di arrivo (old) %lu ",state_index);
	
	if (index!=NULL) *index = state_index;
    return FALSE;
  }
}

void StateManager::AddGoal(unsigned long s) {
	fwrite(&s,sizeof(unsigned long),1,goals);
}

void StateManager::AddTransitions(unsigned long from, unsigned long *to, RULE_INDEX_TYPE *rule
#ifdef VARIABLE_WEIGHT	
	, int *weight
#endif
#ifdef VARIABLE_DURATION
	, int *duration
#endif	
, int num)
{
	if (num>0) {		
		fwrite(&from,sizeof(unsigned long),1,transitions);
		fwrite(&num,sizeof(int),1,transitions);
		for(--num;num>=0;num--) {
#ifdef VARIABLE_WEIGHT	
			fwrite(&(weight[num]),sizeof(int),1,transitions);
#endif
#ifdef VARIABLE_DURATION
			fwrite(&(duration[num]),sizeof(int),1,transitions);
#endif	
			fwrite(&(rule[num]),sizeof(RULE_INDEX_TYPE),1,transitions);
			fwrite(&(to[num]),sizeof(unsigned long),1,transitions);
			
			//fprintf(stderr,"scritta transizione %lu->(%lu)->%lu (peso %d, durata %d)\n",from,rule[num],to[num],weight[num],duration[num]);
		}
	}
}

void StateManager::AddErrorTransition(unsigned long from, unsigned long to, RULE_INDEX_TYPE rule
#ifdef VARIABLE_WEIGHT	
	, int weight
#endif
#ifdef VARIABLE_DURATION
	, int duration
#endif	
)
{
	fwrite(&from,sizeof(unsigned long),1,errors);
#ifdef VARIABLE_WEIGHT	
	fwrite(&weight,sizeof(int),1,errors);
#endif
#ifdef VARIABLE_DURATION
	fwrite(&duration,sizeof(int),1,errors);
#endif	
	fwrite(&rule,sizeof(RULE_INDEX_TYPE),1,errors);
	fwrite(&to,sizeof(unsigned long),1,errors);
	
	//fprintf(stderr,"scritta transizione di errore %lu->(%lu)->%lu\n",from,rule,to);
}

bool StateManager::QueueIsEmpty()
{
  return queue->isempty();
}

state_and_index * StateManager::QueueTop()
{
  return queue->top();
}

state_and_index * StateManager::QueueDequeue()
{
  return queue->dequeue();
}

RULE_INDEX_TYPE StateManager::NextRuleToTry()   // Uli: unsigned short -> unsigned
{
  return queue->NextRuleToTry();
}

void StateManager::NextRuleToTry(RULE_INDEX_TYPE r)
{
  queue->NextRuleToTry(r);
}

// -------------------------------------------------------------------------
// Uli: added omission probability calculation & printing
#ifndef HASHC
void StateManager::CheckLevel()
// check if we are done with the level currently expanded
{
  if (--statesCurrentLevel <= 0)
  // all the states of the current level have been expanded
  {
    // proceed to next level
    statesCurrentLevel = statesNextLevel;
    statesNextLevel = 0;

    // check if there are states in the following level
    if (statesCurrentLevel!=0)
    {
		currentLevel++;
    }
  }
}
#endif


#ifdef HASHC

#include <math.h>

double StateManager::harmonic(double n)
// return harmonic number H_n
{
  return (n<1) ? 0 :
                 log(n) + 0.577215665 + 1/(2*n) - 1/(12*n*n);
}

void StateManager::CheckLevel()
// check if we are done with the level currently expanded
{
  static double p = 1.0;    // current bound on state omission probability
  static double l = pow(2, double(args->num_bits.value));   // l=2^b
  static double k = -1;       // sum of the number of states - 1
  static double m = NumStates;   // size of the state table

  if (--statesCurrentLevel <= 0)
  // all the states of the current level have been expanded
  {
    // proceed to next level
    statesCurrentLevel = statesNextLevel;
    statesNextLevel = 0;

    // check if there are states in the following level
    if (statesCurrentLevel!=0)
    {
      currentLevel++;

      // calculate p_k with equation (2) from FORTE/PSTV paper for
      // the following level
      k += statesCurrentLevel;
      double pk = 1 - 2/l * (harmonic(m+1) - harmonic(m-k))
                  + ((2*m)+k*(m-k)) / (m*l*(m-k+1));
      pno *= pk;
    }
  }
}

void StateManager::PrintProb()
{
  // calculate Pr(not even one omission) with equation (12) from CHARME
  //  paper
  double l = pow(2,double(args->num_bits.value));
  double m = NumStates;
  double n = the_states->NumElts();
  double exp = (m+1) * (harmonic(m+1) - harmonic(m-n+1)) - n;
  double pNO = pow(1-1/l, (m+1) * (harmonic(m+1) - harmonic(m-n+1)) - n);

  // print omission probabilities
  cout.precision(6);
  cout << "Omission Probabilities (caused by Hash Compaction):\n\n"
       << "\tPr[even one omitted state]    <= " << 1-pNO << "\n";
  if (args->main_alg.mode == argmain_alg::Explore_bfs)
    cout << "\tPr[even one undetected error] <= " << 1-pno << "\n"
         << "\tDiameter of reachability graph: "
           << currentLevel-1 << "\n\n";
           // remark: startstates had incremented the currentLevel counter
  else
    cout << "\n";
}

#endif

// -------------------------------------------------------------------------

void StateManager::print_all_states()
{
  the_states->print();
}

unsigned long StateManager::NumElts()
{
  return the_states->NumElts();
}

unsigned long StateManager::MaxElts()
{
  return the_states->MaxElts();
}

unsigned long StateManager::NumGoals()
{
  return num_goals;
}

unsigned long StateManager::NumErrors()
{
  return num_errors;
}

unsigned long StateManager::NumEltsReduced()
{
  return the_states->NumEltsReduced();
}

unsigned long StateManager::QueueNumElts()
{
  return queue->NumElts();
}

void StateManager::print_trace_aux(StatePtr p)   // changes by Uli
{
  state original;
  char *s;

  if (p.isStart())
    {
      // this is a startstate
      // expand it into global variable `theworld`
      // StateCopy(workingstate, s);   // Uli: workingstate is set in StateName()

      // output startstate
      cout << "Startstate "
 	   << (s=StartState->StateName(p))
 	   << " fired.\n";
      delete[] s;   // Uli: avoid memory leak
      theworld.print();
      cout << "----------\n\n";
    }
  else
    {
      // print the prefix
      print_trace_aux(p.previous());

      // print the next state, which should be equivalent to state s
      // and set theworld to that state.
      // FALSE: no need to print full state
      Rules->print_world_to_state(p, FALSE);
    }
}

void StateManager::print_trace(StatePtr p)
{
  // print the prefix
  if (p.isStart())
    {
      print_trace_aux(p);
    }
  else
    {
      print_trace_aux(p.previous());

      // print the next state, which should be equivalent to state s
      // and set theworld to that state.
      // TRUE: print full state please;
      Rules->print_world_to_state(p, TRUE);
    }
}


/************************************************************/
/* StartStateManager */
/************************************************************/
StartStateManager::StartStateManager()
{
  generator = new StartStateGenerator;
MEMTRACKALLOC 
  starts = Storage->getStartsFile(true);
}

state *
StartStateManager::RandomStartState()
{
  what_startstate = (unsigned short)(random.next() % numstartstates);
  return StartState();
}

state *
StartStateManager::LastStartState()
{
  what_startstate = (unsigned short)0;
  return StartState();
}

void
StartStateManager::AllStartStates()
{
  state *nextstate = NULL;
  unsigned long state_index;

  for(what_startstate=0; what_startstate<numstartstates; what_startstate++)
    {
//BREAKPOINT("nextstate-gen")	
      nextstate = StartState();   // nextstate points to internal data at theworld.getstate()
//BREAKPOINT("nextstate-gend")
      if (StateSet->Add(nextstate, FALSE, TRUE, &state_index)) AddStartState(state_index);
//BREAKPOINT("nextstate added")	  
    }
    
	//cout << "\nNumber of startstate: "<<numstartstates<<endl;
}

void StartStateManager::AddStartState(unsigned long s) {
	fwrite(&s,sizeof(unsigned long),1,starts);
}

state *
StartStateManager::NextStartState()
{
  static int next_startstate=0;
  if (next_startstate >= numstartstates) return NULL;
  what_startstate = next_startstate++;
  return StartState();
}

state *
StartStateManager::StartState()
{
  state *next_state = NULL;

  category = STARTSTATE;

  // preparation
  theworld.reset();

  // fire state rule
  generator->Code(what_startstate);

  // print verbose message
  if (args->verbose.value || args->use_verbose_from_state.value) Reporter->print_fire_startstate();

  // Uli: invariant check moved

  // Uli: mark as startstate
  workingstate->previous.clear();

  //fprintf(stdout,"\n------------------------------\n");
  //theworld.print();
  
  return workingstate;
}

char *
StartStateManager::LastStateName()
{
  return generator->Name(what_startstate);
}

char *
StartStateManager::StateName(StatePtr p)
{
  state nextstate;
  if (!p.isStart()) Error.Notrace("Internal: Cannot find startstate name for non startstate");
  for(what_startstate=0; what_startstate<numstartstates; what_startstate++)
    {
      StartState();
      StateCopy(&nextstate, workingstate);

      if (StateEquivalent(&nextstate, p))
	return LastStateName();
    }

//  Norris: it is very funny, but the following code is supposed to work, but it doesn't
//
//   state * nextstate;
//   for(what_startstate=0; what_startstate<numstartstates; what_startstate++)
//     {
//       nextstate = StartState();                  // nextstate points to internal data at theworld.getstate()
//       if (p.compare(nextstate))
// 	return LastStateName();
//     }

  Error.Notrace("Internal: Cannot find startstate name for funny startstate");
  return NULL;
}


/************************************************************/
/* RuleManager */
/************************************************************/
RuleManager::RuleManager() : rules_fired(0),num_transitions(0)
{
  NumTimesFired = new unsigned long [RULES_IN_WORLD];
MEMTRACKALLOC 
  generator = new NextStateGenerator;
MEMTRACKALLOC  

  // initialize check timesfired
  for (RULE_INDEX_TYPE i=0; i<RULES_IN_WORLD; i++)
    NumTimesFired[i]=0;
};

RuleManager::~RuleManager()
{
  delete[ OLD_GPP(RULES_IN_WORLD) ] NumTimesFired;
}

void
RuleManager::ResetRuleNum()
{
  what_rule = 0;
}

void
RuleManager::SetRuleNum(RULE_INDEX_TYPE r)
{
  what_rule = r;
}

state *
RuleManager::SeqNextState()
{
  state * ret;

  what_rule = StateSet->NextRuleToTry();

  generator->SetNextEnabledRule(what_rule);

  if ( what_rule<numrules )
    {
      ret = NextState();
      StateSet->NextRuleToTry(what_rule+1);
      return ret;
    }
  else
    return NULL;
}

// Uli: un-commented, fixed memory leak
state *
RuleManager::RandomNextState()
{
  RULE_INDEX_TYPE PickARule;
  setofrules rulesleft;
  static state *originalstate = new state;  // buffer, for deadlock checking
MEMTRACKALLOC 

  // save workingstate
  StateCopy(originalstate, workingstate);

  // setup set of rules to be checked
  rulesleft.includeall();

  // nondeterministically fire rules until a different state is obtained
  // or no rule available
  category = CONDITION;

  while (StateCmp(originalstate,curstate)==0 && rulesleft.size()!=0 )
    {
      PickARule = (RULE_INDEX_TYPE) (random.next() % rulesleft.size());
      what_rule = rulesleft.getnthrule(PickARule);
      if ( generator->Condition(what_rule) )
	{
	  category = RULE;
	  generator->Code(what_rule);
	}
      curstate = workingstate;
    }

  // if deadlock occurs
  if (!args->no_deadlock.value && StateCmp(originalstate,curstate)==0)
    {
      cout << "\nStatus:\n\n";
      cout << "\t" << rules_fired << " rules fired in simulation in "
	   << SecondsSinceStart() << "s.\n";
      Error.Notrace("Deadlocked state found.");
    }

  rules_fired++;

  // print verbose message
  if (args->verbose.value & !args->full_trace.value) Reporter->print_fire_rule_diff( originalstate );
  if (args->verbose.value & args->full_trace.value) Reporter->print_fire_rule();

  if (!Properties->CheckInvariants())
    {
      cout << "\nStatus:\n\n";
      cout << "\t" << rules_fired << " rules fired in simulation in "
	   << SecondsSinceStart() << "s.\n";
      Error.Notrace("Invariant %s failed.", Properties->LastInvariantName() );
    }

  // progress report
  if ( !args->verbose.value && rules_fired % args->progress_count.value == 0 )
    {
      cout << "\t" << rules_fired << " rules fired in simulation in "
	   << SecondsSinceStart() << "s.\n";
      cout.flush();
    }
  return curstate;
}

bool
RuleManager::AllNextStates()
{
  setofrules * fire;

  // get set of rules to fire
  fire = EnabledTransition();

  // generate the set of next states
  return AllNextStates(fire);
}

/****************************************
  Generate set of transitions to be made:
  setofrules transitionset_enabled()
  -- future extension
  -- setofrules transitionset_sleepset_rr(sleepset s)
  -- setofrules transitionset_gode_dl(setofrules rs)
  ****************************************/
setofrules *
RuleManager::EnabledTransition()
{
  static setofrules ret;
  int p;	// Priority of the current rule

  ret.removeall();

  // record what kind of analysis is currently carried out
  category = CONDITION;

  // Minimum priority among all rules
  minp = INT_MAX;
  // get enabled
  for ( what_rule=0; what_rule<numrules; what_rule++)
    {
      generator->SetNextEnabledRule(what_rule);
      if ( what_rule<numrules ) {
		ret.add(what_rule);
        // Compute minimum priority
        if ((p = generator->Priority(what_rule)) < minp)
          minp = p;
      }
    }
  return &ret;
}

/****************************************
  The BFS verification supporting routines:
  void generate_startstateset()
  bool generate_nextstateset_standard(setofrules fire)
  -- future extension
  -- bool generate_nextstateset_sym()
  -- bool generate_nextstateset_gode_dl()
  -- bool generate_nextstateset_sleepset_rr(setofrules fire, sleepset cursleepset)
  -- bool generate_nextstateset_gode_sleepset_dl(sleepset cursleepset)
  ****************************************/



//TODO: MODIFY THIS TO SUPPORT HEURISTICS DEFINED IN MODEL (.m)!!!!



// Uli: corrected a memory-leak, improved performance
bool
RuleManager::AllNextStates(setofrules * fire)
{
	// this will unconditionally fire rule in "fire"
	// please make sure the conditions are true for the rules in "fire"
	// before calling this function.

	static state * originalstate = new state;   // buffer for workingstate
	MEMTRACKALLOC 
	state * nextstate;
	bool deadlocked_so_far = TRUE;
	bool permanent;
	unsigned long next_indexes[255]; //LIMITE --meglio dinamico, forse troppo piccolo o troppo grande--
#ifdef VARIABLE_WEIGHT	
	int next_weights[255]; 
#endif
#ifdef VARIABLE_DURATION
	int next_durations[255]; 
#endif	
	RULE_INDEX_TYPE next_rules[255]; 
	int nexts = 0;

	StateCopy(originalstate, workingstate);   // make copy of workingstate
	unsigned long index;
	bool iserror;
	unsigned long from_index = curstateindex; /*StateSet->find_disk_index(originalstate);*/
	
	//Questo for scorre tutte le rules applicabili allo stato currente e le applica
	for ( what_rule=0; what_rule<numrules; what_rule++) {
		if (fire->in(what_rule) && generator->Priority(what_rule)<=minp)
		// if (fire->in(what_rule) )
		{
			int weight = Rules->RuleWeight(what_rule); //NextState sovrascrive workingstate quindi il calcolo va fatto prima
			int duration = Rules->RuleDuration(what_rule); //NextState sovrascrive workingstate quindi il calcolo va fatto prima
			//fprintf(stderr,"weight=%d, duration=%d\n",weight,duration);
			//theworld.pddlprint(stderr,"/");
			nextstate = NextState();			
			LOG("nextstate-gen")
			if ( StateCmp(curstate,nextstate)!=0 ) {
				deadlocked_so_far = FALSE;
				permanent = (generator->Priority(what_rule)<50);   // Uli			
				//theworld.print(stdout," ");
				//fprintf(stderr,"\n regola %lu ",what_rule);				
















				//TODO:

				(void) StateSet->Add(nextstate, TRUE, permanent, &(next_indexes[nexts]),&iserror);
















				if (!iserror) {
					//BREAKPOINT("nextstate-add")
					num_transitions++;
					//fprintf(stderr,"RULEWEIGHT sulla rule %lu per lo stato %lu restituisce %d\n",what_rule,curstateindex,weight);
#ifdef VARIABLE_WEIGHT	
					next_weights[nexts]=weight;
#endif
#ifdef VARIABLE_DURATION
					next_durations[nexts]=duration;
#endif	
					next_rules[nexts]=what_rule; //ricalcolarla dopo  pesantissimo
					nexts++;					
					if (nexts>=255) {
						//dump del buffer delle transizioni -- scritte a blocchi di max 255
						LOG("AddTransitions")
						StateSet->AddTransitions(from_index,next_indexes,next_rules
#ifdef VARIABLE_WEIGHT	
							,next_weights
#endif
#ifdef VARIABLE_DURATION
							,next_durations
#endif						
							,nexts);  
						nexts=0;
					}
					//BREAKPOINT("nextstate-weighted")					
					//fprintf(stderr,"preparata transizione %lu->(%lu)->%lu\n",from_index,next_rules[nexts-1],next_indexes[nexts-1]);
				} else {
					StateSet->AddErrorTransition(from_index,next_indexes[nexts],what_rule
#ifdef VARIABLE_WEIGHT	
						,weight
#endif
#ifdef VARIABLE_DURATION
						,duration
#endif						
						);  					 
				}
				StateCopy(workingstate, originalstate);   // restore workingstate
			}
		}
	}
	LOG("AddTransitions")
	if (nexts>0) {
		StateSet->AddTransitions(from_index,next_indexes,next_rules
#ifdef VARIABLE_WEIGHT	
			,next_weights
#endif
#ifdef VARIABLE_DURATION
			,next_durations
#endif					
			,nexts);  
	}
	return deadlocked_so_far;
}


/**
 *
 * TODO:
 *
 *
 * Add a heuristic method so that NextState() can generate a heuristic value for the following state!!!!!!
 *
 *
 *
 */




// the following global variables have been set:
// theworld, curstate and what_rule
state *
RuleManager::NextState()
{

  category = RULE;

  // fire rule
  generator->Code(what_rule);
  rules_fired++;

  // update timesfired record
  NumTimesFired[what_rule]++;

//  // print verbose message
//  if (args->verbose.value || (args->use_verbose_from_state.value &
//      StateSet->NumElts() >= args->verbose_from_state.value ) ) Reporter->print_fire_rule();

  // Uli: invariant check moved
//  if (!Properties->CheckInvariants())
//    {
//      Error.Error("Invariant \"%s\" failed.",Properties->LastInvariantName());
//    }

  // get next state
#ifdef HASHC
  if (args->trace_file.value) {
    workingstate->previous.set(NumCurState);
  	workingstate->set_g_val(99);
    workingstate->set_h_val();
    workingstate->get_f_val();
    //TODO: F value add
  } else
#endif
   {
	 workingstate->previous.set(curstate);
   	 workingstate->set_g_val(curstate->get_g_val()+1);
	 workingstate->set_h_val();
	 workingstate->set_f_val();
	 //TODO: F value add
   }

  // print verbose message
  if (args->verbose.value || (args->use_verbose_from_state.value &
      StateSet->NumElts() >= args->verbose_from_state.value ) ) Reporter->print_fire_rule();



  return workingstate;
}

void
RuleManager::print_world_to_state(StatePtr p, bool fullstate)
{
  state original;
  state nextstate;
  char *s;

  // save last state
  StateCopy(&original, workingstate);

  // generate next state
  for ( what_rule=0; what_rule<numrules; what_rule++)
    {
      category = CONDITION;
      if (generator->Condition(what_rule))
 	{
	  category = RULE;
	  generator->Code(what_rule);
	  StateCopy(&nextstate, workingstate);

	  if (StateEquivalent(&nextstate, p))
	    {
    	      // output the name of the rule and the last state in full
	      cout << "Rule "
		   // << rules[ what_rule ].name
		   << (s=generator->Name(what_rule))
		   << " fired.\n";
              delete[] s;   // Uli: avoid memory leak
	      if (fullstate)
		cout << "The last state of the trace (in full) is:\n";
	      if (args->full_trace.value || fullstate)
		theworld.print();
	      else
		theworld.print_diff( &original );
	      cout << "----------\n\n";
	      return;
	    }
	  else
	      StateCopy(workingstate, &original);
 	}
    }
  Error.Notrace("Internal Error:print_world_to_state().");
}

char *
RuleManager::LastRuleName()
{
  return generator->Name(what_rule);
}

char *
RuleManager::RuleName(RULE_INDEX_TYPE rule)
{
  return generator->Name(rule);
}

char *
RuleManager::RulePDDLName(RULE_INDEX_TYPE rule)
{
  return generator->PDDLName(rule);
}

int
RuleManager::RuleDuration(RULE_INDEX_TYPE rule)
{
	return generator->Duration(rule);
}

int
RuleManager::RuleWeight(RULE_INDEX_TYPE rule)
{
	return generator->Weight(rule);
}

RuleManager::rule_pddlclass
RuleManager::RulePDDLClass(RULE_INDEX_TYPE rule)
{
	return generator->PDDLClass(rule);
}

const char *
RuleManager::RulePDDLClassName(RULE_INDEX_TYPE rule)
{
	switch (RulePDDLClass(rule)) {
	case Action: return "Action"; break;
	case Event: return "Event"; break;
	case Clock: return "Clock tick"; break;
	case DurativeStart: return "Durative action begin"; break;
	case DurativeEnd: return "Durative action end"; break;
	default: return "(Unknown happening)"; break;
	}
}

unsigned long RuleManager::NumRulesFired()
{
  return rules_fired;
}

unsigned long RuleManager::NumTransitions()
{
  return num_transitions;
}

void
RuleManager::print_rules_information()
{
  bool exist;

  if (args->print_rule.value)
    {

      cout << "Rules Information:\n\n";
      for (RULE_INDEX_TYPE i=0; i<RULES_IN_WORLD; i++)
	cout << "\tFired " << NumTimesFired[i] << " times\t- Rule \""
	     << generator->Name(i)
	     << "\"\n";
    }
  else
    {
      for (RULE_INDEX_TYPE i=0; i<RULES_IN_WORLD; i++)
	if (NumTimesFired[i]==0)
	  exist = TRUE;
      if (exist)
	cout << "Analysis of State Space:\n\n"
	     << "\tThere are rules that are never fired.\n"
	     << "\tIf you are running with symmetry, this may be why.  Otherwise,\n"
	     << "\tplease run this program with \"-pr\" for the rules information.\n";
    }
}

/************************************************************/
/* PropertyManager */
/************************************************************/
PropertyManager::PropertyManager()
{
}

bool
PropertyManager::CheckInvariants()
{
  category = INVARIANT;
  unsigned short temp_numinvariants;
  temp_numinvariants = (unsigned short)numinvariants;
  for ( what_invariant = 0; what_invariant < temp_numinvariants; what_invariant++ )
    {
      if ( !( *invariants[ what_invariant ].condition )() )
        /* Uh oh, invariant blown. */
        {
	  return FALSE;
        }
    }
  return TRUE;
}

char *
PropertyManager::LastInvariantName()
{
  return invariants[what_invariant].name;
}


int
PropertyManager::CheckGoals()
{
  category = GOAL;
  unsigned short temp_numgoals;
  temp_numgoals = (unsigned short)numgoals;
  for ( what_goal = 0; what_goal < temp_numgoals; what_goal++ )
    {
      if ( ( *goals[ what_goal ].condition )() )
        /* Yeah, it is a goal! */
        {
	  return what_goal;
        }
    }
  return -1;
}

char *
PropertyManager::LastGoalName()
{
  return goals[what_goal].name;
}


/************************************************************/
/* SymmetryManager */
/************************************************************/
SymmetryManager::SymmetryManager()
{
}

/************************************************************/
/* POManager */
/************************************************************/
POManager::POManager()
{
}

/************************************************************/
/* AlgorithmManager */
/************************************************************/
AlgorithmManager::AlgorithmManager() : 
	num_controlled_states(0), num_plans(0), min_plan_length(UINT_MAX), max_plan_length(0), avg_plan_length(0)
{
  // create managers
  Rules = new RuleManager;
MEMTRACKALLOC 
  Reporter = new ReportManager;
MEMTRACKALLOC 

#ifdef HASHC
  h3 = new hash_function(BLOCKS_IN_WORLD);
MEMTRACKALLOC
  //h4 = new hash_function_compr((args->num_bits.value)/8);
#endif

  Reporter->CheckConsistentVersion();
  if (args->main_alg.mode!=argmain_alg::Nothing) Reporter->print_header();
  
  //Reporter->print_warning();
  signal(SIGFPE, &catch_div_by_zero);

};

  
void AlgorithmManager::Plan() {
  
  	if (args->phase.value<=1) {
		if ( args->main_alg.mode == argmain_alg::Explore_bfs ) {
			Explore_bfs(); 
		} else if ( args->main_alg.mode == argmain_alg::Explore_dfs ) {
			Explore_dfs();
		}
	}
	
	if (args->phase.value<=2) {
		Build_Dynamics();
	}

	if (args->phase.value<=3) {
		Find_Paths();
	}
	
	//create plans only if PDDL output is required	
	if (args->phase.value<=4 &&
	(args->output_fmt.mode == argoutput_fmt::PDDL ||
	args->output_fmt.mode == argoutput_fmt::PDDL_Verbose ||
	args->output_fmt.mode == argoutput_fmt::PDDL_VeryVerbose)
	) {
		Collect_Plans();
	}
	
	if (args->phase.value<=5) {
		Output_Results();
	}
}

void
AlgorithmManager::Output_Results() {
	phase = 5;
	
	if (*(args->output_file.value) != 0)
		Output = new OutputManager(args->output_file.value);
	else 
		Output = new OutputManager();
MEMTRACKALLOC
	
	Reporter->print_status();
	Reporter->print_algorithm();
	
	switch (args->output_fmt.mode) {
	case argoutput_fmt::Raw:
		Output->WriteBinaryController();
		break;
	case argoutput_fmt::CSV:
		Output->WriteController(&OutputManager::actionwriter_actioncsv,false);
		break;		
	case argoutput_fmt::Text:
		Output->WriteController(&OutputManager::actionwriter_actiontext,false);
		break;
	case argoutput_fmt::Text_Verbose:
		Output->WriteController(&OutputManager::actionwriter_actiontext_verbose,true);
		break;
#ifdef OBDD_COMPRESSION		
	case argoutput_fmt::OBDD:
		Output->WriteOBDDController();
		break;
#endif		
	case argoutput_fmt::PDDL:
	case argoutput_fmt::PDDL_Verbose:
	case argoutput_fmt::PDDL_VeryVerbose:
		Output->WritePlans();
		break;
	}
	
	Reporter->print_report();
	
	//free structures
	delete Output; Output=NULL; //check
}

unsigned
AlgorithmManager::Build_Plan_From(unsigned long from, FILE *target) {
	unsigned long to;
	RULE_INDEX_TYPE zero=0;
	int wzero=0;
	edge *e;
	unsigned len=0,dur=0,wei=0;

	if (StateGraph->OutDegree(from) > 0) { //controllable
		//cout << "PLAN: ";
		while(true) {
			fwrite(&from,sizeof(unsigned long),1,target);
			//cout << "S" << from;
			if (StateGraph->OutDegree(from) > 0) {
				e = StateGraph->GetOutgoing(from,0);				
				fwrite(&e->rule,sizeof(RULE_INDEX_TYPE),1,target);
#ifdef VARIABLE_WEIGHT	
				fwrite(&e->weight,sizeof(int),1,target);
#endif
#ifdef VARIABLE_DURATION
				fwrite(&e->duration,sizeof(int),1,target);
#endif	
				//cout << "-R" << e->rule << "-";
				from = e->to;
				len++; //plan length
#ifdef VARIABLE_WEIGHT	
				wei+=e->weight;
#else
				wei+=Rules->RuleWeight(e->rule);
#endif
#ifdef VARIABLE_DURATION
				dur+=e->duration;
#else			
				dur+=Rules->RuleDuration(e->rule);
#endif					
			} else {
				fwrite(&zero,sizeof(RULE_INDEX_TYPE),1,target);
#ifdef VARIABLE_WEIGHT	
				fwrite(&wzero,sizeof(int),1,target);
#endif
#ifdef VARIABLE_DURATION
				fwrite(&wzero,sizeof(int),1,target);
#endif	
				fwrite(&from,sizeof(unsigned long),1,target); //loop = plan end
				//cout << endl;
				break;
			}
		}
		
		//update global statistics
		num_plans++;
		//
		if (len > max_plan_length) max_plan_length = len;
		if (len < min_plan_length) min_plan_length = len;
		avg_plan_length = (float)(avg_plan_length * (float)(num_plans-1) + len) / (float)num_plans;
		//
		if (dur > max_plan_duration) max_plan_duration = dur;
		if (dur < min_plan_duration) min_plan_duration = dur;
		avg_plan_duration = (float)(avg_plan_duration * (float)(num_plans-1) + dur) / (float)num_plans;
		//
		if (wei > max_plan_weight) max_plan_weight = wei;
		if (wei < min_plan_weight) min_plan_weight = wei;
		avg_plan_weight = (float)(avg_plan_weight * (float)(num_plans-1) + wei) / (float)num_plans;

	}
	
	return len;
}

void
AlgorithmManager::Collect_Plans() {
	unsigned long from, to, start;
	int weight;
	int duration;
	RULE_INDEX_TYPE rule;
	unsigned long num_states=0;	
	
	phase = 4;
	Reporter->print_status();
	Reporter->print_algorithm();

	//open files
	FILE* actions = Storage->getActionsFile(false);
	FILE* plans = Storage->getPlansFile(true);

	num_states = Stats->getStatistic(StatsManager::NumStates);
	/*
	FILE *reachables = Storage->getReachablesFile(false); 
	fseek(reachables,0,SEEK_END);
	num_states = ftell(reachables)/sizeof(state);
	*/
	
	//create structures
	StateGraph = new MemGraphManager(num_states);
MEMTRACKALLOC	
	for(from=0; from < num_states; ++from) StateGraph->set_outgoing_num(from,1);

	//build path graph
	fseek(actions,0,SEEK_SET);
	while(!feof(actions) && (fread(&from,sizeof(unsigned long),1,actions)==1)) {
		(void) fread(&rule,sizeof(RULE_INDEX_TYPE),1,actions);
		(void) fread(&to,sizeof(unsigned long),1,actions);
#ifdef VARIABLE_WEIGHT	
		(void) fread(&weight,sizeof(int),1,actions);
#endif
#ifdef VARIABLE_DURATION
		(void) fread(&duration,sizeof(int),1,actions);
#endif	
		StateGraph->add_outgoing(from,to,rule
#ifdef VARIABLE_WEIGHT	
		,weight
#endif
#ifdef VARIABLE_DURATION
		,duration
#endif			
		); 
	}
	
	if (args->search_alg.mode == argsearch_alg::Universal || 
	    args->search_alg.mode == argsearch_alg::Universal_Optimal)	{
		//universal plan: every reachable state is a potential start state
		for(start=0; start < num_states; ++start) {
			Build_Plan_From(start,plans);
			Reporter->print_progress();
		}
	} else {
		//single plan: use declared start states only
		FILE* starts = Storage->getStartsFile(false);
		fseek(starts,0,SEEK_SET);
		while(!feof(starts) && (fread(&start,sizeof(unsigned long),1,starts)==1)) {
			Build_Plan_From(start,plans);			
			Reporter->print_progress();
		}
	}
	
	Reporter->print_report();
	
	//free structures
	delete StateGraph; StateGraph=NULL; //check
}


void
AlgorithmManager::Find_Paths() {

	unsigned long is;
	edge *e;
	disk_queue<unsigned long> *dij_queue;
	dynBitVec *has_next;
	edge *chosen_edge;
	unsigned long *distance;
	
	phase = 3;
	Reporter->print_status();
	Reporter->print_algorithm();

	//open files
	FILE* goals = Storage->getGoalsFile(false);
	FILE* actions = Storage->getActionsFile(true);
	
	//create structures
	dij_queue = new disk_queue<unsigned long>(100);
MEMTRACKALLOC
	has_next = new dynBitVec(StateGraph->NumStates());
MEMTRACKALLOC
	chosen_edge = new edge[StateGraph->NumStates()];
MEMTRACKALLOC
	distance = new unsigned long[StateGraph->NumStates()];
MEMTRACKALLOC	
	
	for(is=0; is < StateGraph->NumStates(); ++is) {
		distance[is] = (metric<=0)?ULONG_MAX:0;
	}
	
	//init queue with goals
	fseek(goals,0,SEEK_SET);
	while(!feof(goals) && (fread(&is,sizeof(unsigned long),1,goals)==1)) {
		//fprintf(stderr,"Goal: %lu\n",is);
		dij_queue->enqueue(is);
		distance[is]=(metric<=0)?0:ULONG_MAX;
		//chosen_edge[is] = ??
	}
	//StateGraph->print();
	//build paths
	while (!dij_queue->isempty()) {
		is = dij_queue->dequeue();
		if (StateGraph->OutDegree(is)>0) {		
			if (args->search_alg.mode == argsearch_alg::Universal_Optimal || 
				args->search_alg.mode == argsearch_alg::Optimal)
				StateGraph->reorder_list(is,(metric<=0));
			for(RULE_INDEX_TYPE i=0; i<StateGraph->OutDegree(is); ++i) {
				e = StateGraph->GetOutgoing(is,i); 
				if (!has_next->get(e->to) //il DynBitVector potrebbe non "resistere" agli unsigned long!!!
				|| ((metric<=0) && (distance[e->to] > 
#ifdef VARIABLE_WEIGHT	
				e->weight 
#else
				Rules->RuleWeight(e->rule)
#endif		
				+ distance[is])) || ((metric>0) && (distance[e->to] < 
#ifdef VARIABLE_WEIGHT	
				e->weight 
#else
				Rules->RuleWeight(e->rule)
#endif	
				+ distance[is]))
				) { 				
					chosen_edge[e->to].to = is;
					chosen_edge[e->to].rule = e->rule;
#ifdef VARIABLE_WEIGHT						
					chosen_edge[e->to].weight = e->weight;
#endif					
#ifdef VARIABLE_DURATION
					chosen_edge[e->to].duration = e->duration;
#endif					
					distance[e->to] = distance[is]+
#ifdef VARIABLE_WEIGHT	
						e->weight;
#else
						Rules->RuleWeight(e->rule);
#endif						
					if (!has_next->get(e->to)) {
						//fprintf(stderr,"Controllato: %lu\n",e->to);
						num_controlled_states++;
						dij_queue->enqueue(e->to);	
					}
					has_next->set(e->to);
					
					if (args->search_alg.mode == argsearch_alg::Feasible) break; //only one needed ... but not if optimizing?				
				} 
			}			
			Reporter->print_progress();
		}
	}
	
	unsigned long nactions = 0;
	for(is=0; is < StateGraph->NumStates(); ++is) {
		if(has_next->get(is)) {
			fwrite(&is,sizeof(unsigned long),1,actions);
			fwrite(&(chosen_edge[is].rule),sizeof(RULE_INDEX_TYPE),1,actions);
			fwrite(&(chosen_edge[is].to),sizeof(unsigned long),1,actions);
#ifdef VARIABLE_WEIGHT	
			fwrite(&(chosen_edge[is].weight),sizeof(int),1,actions);
#endif
#ifdef VARIABLE_DURATION
			fwrite(&(chosen_edge[is].duration),sizeof(int),1,actions);
#endif	
			nactions++;
		}
	}
	Stats->setStatistic(StatsManager::NumActions,nactions);
		
	Reporter->print_report();

	//free structures
	delete StateGraph; StateGraph=NULL; //check
	delete dij_queue;
	delete has_next;
	delete[] chosen_edge;
	delete[] distance;
}

void
AlgorithmManager::Build_Dynamics() {

	phase = 2;
	Reporter->print_status();
	
	unsigned long num_states,num_transitions;
	int nexts, weight, duration;
	RULE_INDEX_TYPE rule;
	unsigned long from, to;
	//state  *s = new state;
MEMTRACKALLOC	
	
	num_states = Stats->getStatistic(StatsManager::NumStates);
	num_transitions = Stats->getStatistic(StatsManager::NumTransitions);
	/*
	FILE *reachables = Storage->getReachablesFile(false); 
	fseek(reachables,0,SEEK_END);
	num_states = ftell(reachables)/sizeof(state);
	*/
	
	//create structures
	if (MemGraphManager::estimate_max_transitions()>num_transitions)
		StateGraph = new MemGraphManager(num_states);
	else 
		StateGraph = new DiskGraphManager(num_states);
MEMTRACKALLOC	

	Reporter->print_algorithm(); //here we know the kind of GraphManager used

	//fprintf(stderr,"Creata tabella di adiacenza\n");
	FILE *transitions = Storage->getTransitionsFile(false);
	//fprintf(stderr,"scanning out degrees\n");
	//first round: calculate node out degrees (for inverted graph!)
	fseek(transitions,0,SEEK_SET);
	while(!feof(transitions) && (fread(&to,sizeof(unsigned long),1,transitions)==1)) {
		(void) fread(&nexts,sizeof(int),1,transitions);
		for(--nexts;nexts>=0;nexts--) {
#ifdef VARIABLE_WEIGHT	
			(void) fread(&weight,sizeof(int),1,transitions);
#endif
#ifdef VARIABLE_DURATION
			(void) fread(&duration,sizeof(int),1,transitions);
#endif	
			(void) fread(&rule,sizeof(RULE_INDEX_TYPE),1,transitions);
			(void) fread(&from,sizeof(unsigned long),1,transitions);
			//fprintf(stderr,"\t transizione %lu->%lu (peso %lu)\n",from,to,weight);
			StateGraph->inc_outgoing_num(from);
		}
		Reporter->print_progress();
	}
	
	//fprintf(stderr,"creating lists\n");
	StateGraph->setup_outgoing_lists();
	
	//fprintf(stderr,"reading transitions\n");
	//second round: load transitions as outgoing list
	fseek(transitions,0,SEEK_SET);
	//fprintf(stderr,"Rewind del file delle transizioni\n");
	while(!feof(transitions) && (fread(&to,sizeof(unsigned long),1,transitions)==1)) {
		(void) fread(&nexts,sizeof(int),1,transitions);
		//fprintf(stderr,"letto stato di partenza %lu con %d transizioni\n",to,nexts);
		for(--nexts;nexts>=0;nexts--) {
#ifdef VARIABLE_WEIGHT	
			(void) fread(&weight,sizeof(int),1,transitions);
#endif
#ifdef VARIABLE_DURATION
			(void) fread(&duration,sizeof(int),1,transitions);
#endif	
			(void) fread(&rule,sizeof(RULE_INDEX_TYPE),1,transitions);			
			(void) fread(&from,sizeof(unsigned long),1,transitions);
			//fprintf(stderr,"\tstato di successivo: %lu (peso %d)\n",from,weight);
			StateGraph->add_outgoing(from,to,rule
#ifdef VARIABLE_WEIGHT	
				,weight
#endif
#ifdef VARIABLE_DURATION
				,duration
#endif				
			);
		}
		Reporter->print_progress();
	}
	
	//StateGraph->print();	
	
	Reporter->print_report();
}

void
AlgorithmManager::Explore_bfs()
{
	// Use Global Variables: what_rule, curstate, theworld, queue, the_states
	setofrules fire;  // set of rule to be fired
	bool deadlocked;  // boolean for checking deadlock
	int horizon=args->horizon.value;
	state_and_index *sid;
	
	phase = 1;
		
PAUSE
		
	//create structures	
	StartState = new StartStateManager;
MEMTRACKALLOC
PAUSE

	Properties = new PropertyManager;
MEMTRACKALLOC
PAUSE

	Symmetry = new SymmetryManager;
MEMTRACKALLOC
PAUSE

	PO = new POManager;
MEMTRACKALLOC	
PAUSE

	StateSet = new StateManager(TRUE, NumStatesGivenBytes( args->mem.value ));
MEMTRACKALLOC
PAUSE

	Reporter->print_status();
	Reporter->print_algorithm();
	
	curstate=NULL; //dovrebbe migliorare le cose?
	
	// print verbose message
	if (args->verbose.value || args->verbose_from_state.value) Reporter->print_verbose_header();

//BREAKPOINT("info")
	
	cout.flush();
	
//BREAKPOINT("flush")
	
	theworld.to_state(NULL); // trick : marks variables in world

//BREAKPOINT("tostate")	
	
	//Pred_State=NULL; //this notifies that we are in the Start State Phase (see mu_state.C)
	StartState->AllStartStates();
	//Pred_State=new state;

//BREAKPOINT("startstates ok")	
	
	StateSet->CheckLevel();
	
BREAKPOINT("checklevel-ok")
	
	// search state space
	while (( !StateSet->QueueIsEmpty() ) && (StateSet->CurrentLevel()<=horizon) )
	{

//		TODO: Check this works!!!!!!

//		curstate = &((StateSet->QueueTop())->s);
//		StateCopy(workingstate, curstate);
//		StateSet->getQueue()->Print();
//		//curstate->print();


		sid = StateSet->QueueDequeue();
		curstate = &(sid->s);
		curstateindex = sid->i;
		NumCurState++;
		StateCopy(workingstate, curstate);
	
		//Make a copy of curstate, since it will be a predecessor of NextStates
		//StateCopy(Pred_State,curstate);

		//print verbose message
		if (args->verbose.value || args->use_verbose_from_state.value) Reporter->print_curstate();

BREAKPOINT("allnextstates")
		
		//generate all next state and insert predecessors into PT
		deadlocked = Rules->AllNextStates();

BREAKPOINT("allnextstates-ok")		

		//check deadlock
		if ( deadlocked && !args->no_deadlock.value ) Error.Deadlocked("Deadlocked state found.");
		StateSet->CheckLevel();
		
		//check if work is done :)
		if (args->search_alg.mode == argsearch_alg::Feasible && StateSet->NumGoals()>0) {
			break;
		}
	}
		
	Stats->setStatistic(StatsManager::NumStates,StateSet->NumElts());
	Stats->setStatistic(StatsManager::NumGoals,StateSet->NumGoals());
	Stats->setStatistic(StatsManager::NumTransitions,Rules->NumTransitions());
	Stats->setStatistic(StatsManager::NumErrors,StateSet->NumErrors());
	
	Reporter->print_report();
	
	//free structures
	delete StartState; StartState=NULL; //check
	delete Properties; Properties=NULL; //check
	delete Symmetry; Symmetry=NULL; //check
	delete PO; PO=NULL; //check
	delete StateSet; StateSet=NULL; //check
	
	//END_PROCEDURE_EXPLORE
}



/****************************************
  The DFS verification routine:
  void Explore_dfs()
  -- not changed yet
  ****************************************/

void
AlgorithmManager::Explore_dfs()
{
  // use global variables: what_rule, curstate, theworld, queue, the_states
  state *nextstate;
  bool deadlocked_so_far = TRUE;
  state_and_index *sid;
  
  phase = 1;
  
  //create structures
  StartState = new StartStateManager;
MEMTRACKALLOC
  Properties = new PropertyManager;
MEMTRACKALLOC
  Symmetry = new SymmetryManager;
MEMTRACKALLOC 
  PO = new POManager;
MEMTRACKALLOC 
  StateSet = new StateManager(FALSE, NumStatesGivenBytes( args->mem.value ));
MEMTRACKALLOC 

  Reporter->print_status();
  Reporter->print_algorithm();
  
  // print verbose message
  if (args->verbose.value) Reporter->print_verbose_header();

  theworld.to_state(NULL); // trick : marks variables in world

  // for each startstate start a DFS search
  while ((curstate = StartState->NextStartState()) != NULL)
    {
      (void) StateSet->Add(curstate, FALSE, TRUE);

      while ( !StateSet->QueueIsEmpty() )
 	{
 	  // get the last state from the stack
	  sid = StateSet->QueueTop();
	  curstate = &(sid->s);
	  curstateindex = sid->i;
	  StateCopy(workingstate, curstate);

 	  // l) method:
 	  // get a different next state by incrementing what_rule
 	  // until a rule is enabled and the new state is different from the
 	  // old state or all the rules are exhausted
 	  // 2) setting of varibles
 	  // what_rule is set by previous iteration
 	  // curstate is set at the beginning of the iteration
 	  // theworld is set at the beginning of the iteration

 	  // get next rule that is enabled and fire it
          // set global variable what_rule

 	  nextstate = Rules->SeqNextState();

 	  if ( nextstate!=NULL )
	    {
	      if ( StateCmp(curstate,nextstate)!=0 )
	      {
	        // curstate state does not deadlock
	        deadlocked_so_far = FALSE;

	        // check if the next state has been searched or not
	        if (StateSet->Add(nextstate, TRUE, TRUE))
		{
 		  // curstate state does not deadlock, but the next state might
 		  deadlocked_so_far = TRUE;
 		}
 	        else
 		{
 		  // a rule has been fired and the next state has been searched
 		  // ==> check next rule
 		  if (args->verbose.value)
 		    cout << "This state has been examined, try another rule.\n";
 		}
              }
              else
                if (args->verbose.value)
                  cout << "This state has been examined, try another rule.\n";
 	    }
 	  else
 	    {
	      // check deadlock
	      if ( deadlocked_so_far && !args->no_deadlock.value )
		{
		  if (args->verbose.value) Reporter->print_dfs_deadlock();
		  Error.Deadlocked("Deadlocked state found.");
		}

	      // remove explored state
 	      (void) StateSet->QueueDequeue();

 	      // print verbose message
 	      if (args->verbose.value) Reporter->print_retrack();

 	      // previous state does not deadlock, as it gives the state just removed
 	      deadlocked_so_far = FALSE;

#ifdef HASHC
	      delete curstate;
#endif
 	    } // if
 	} // while

       // print verbose message
       if (args->verbose.value)
 	cout << "------------------------------\n"
 	     << "Finished working on one statestate.\n"
 	     << "------------------------------\n";
     } // for
  Reporter->print_final_report();
}

/****************************************
  The simulation main routine:
  void simulate()
  ****************************************/

// Uli: added required call to theworld.to_state()
void
AlgorithmManager::simulate()
{
  // progress report must be printed out so as to make sense
  // otherwise, if there is no bug, the program just run on for ever
  // without any message.

  // print verbose message
  if (args->verbose.value) Reporter->print_verbose_header();

  Reporter->StartSimulation();

  theworld.to_state(NULL);   // trick: marks variables in world

  // GetRandomStartState will choose a Startstate randomly
  curstate = StartState->RandomStartState();
  // simulate
  while(1)
    {
      // SimulateRandomRule always executes a rule that leads to
      // a different state.
      curstate = Rules->RandomNextState();
    }
}

/********************
  $Log: mu_system.C,v $
  Revision 1.3  1999/01/29 08:28:09  uli
  efficiency improvements for security protocols

  Revision 1.2  1999/01/29 07:49:11  uli
  bugfixes

  Revision 1.4  1996/08/07 18:54:33  ip
  last bug fix on NextRule/SetNextEnabledRule has a bug; fixed this turn

  Revision 1.3  1996/08/07 01:07:55  ip
  Fixed bug on what_rule setting during guard evaluation; otherwise, bad diagnoistic message on undefine error on guard

  Revision 1.2  1996/08/07 00:15:26  ip
  fixed while code generation bug

  Revision 1.1  1996/08/07 00:14:46  ip
  Initial revision

********************/
