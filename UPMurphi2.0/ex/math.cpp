/******************************
  Program "math.m" compiled by "Universal Planner Murphi Release 2.0.R8"

  Murphi Last Compiled date: "Mar  5 2014"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Universal Planner Murphi Release 2.0.R8"
#define MURPHI_DATE "Mar  5 2014"
#define PROTOCOL_NAME "math"
#define BITS_IN_WORLD 44
#define HASHC

/********************
  Include
 ********************/
#include "upm_prolog.hpp"
#include <cmath>

/********************
  Decl declaration
 ********************/

class mu_1_integer: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_integer& val) { return mu__long::operator=((int) val); };
  mu_1_integer (const char *name, int os): mu__long(-1000, 1000, 11, name, os) {};
  mu_1_integer (void): mu__long(-1000, 1000, 11) {};
  mu_1_integer (int val): mu__long(-1000, 1000, 11, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_integer mu_1_integer_undefined_var;

const int mu_G = 40;
/*** Variable declaration ***/
mu_1_integer mu_x("x",0);

/*** Variable declaration ***/
mu_1_integer mu_h_n("h_n",11);

/*** Variable declaration ***/
mu_1_integer mu_g_n("g_n",22);

/*** Variable declaration ***/
mu_1_integer mu_f_n("f_n",33);





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_x.clear();
  mu_h_n.clear();
  mu_g_n.clear();
  mu_f_n.clear();
}
void world_class::undefine()
{
  mu_x.undefine();
  mu_h_n.undefine();
  mu_g_n.undefine();
  mu_f_n.undefine();
}
void world_class::reset()
{
  mu_x.reset();
  mu_h_n.reset();
  mu_g_n.reset();
  mu_f_n.reset();
}
//WP
double world_class::get_f_val()
{
  double f_val = mu_f_n.value();
  return f_val;
}
//WP
void world_class::set_f_val()
{
  double f_val = mu_g_n.value() + mu_h_n.value();
  mu_f_n.value(f_val);
}
//WP
double world_class::get_h_val()
{
  double h_val = mu_h_n.value();
  return h_val;
}
//WP
void world_class::set_h_val()
{
  double h_val = 0;
  mu_h_n.value(h_val);
}
//WP
double world_class::get_g_val()
{
  double g_val = mu_g_n.value();
  return g_val;
}
//WP
void world_class::set_g_val(double g_val)
{
  mu_g_n.value(g_val);
}
void world_class::print(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_x.print(target, separator);
  mu_h_n.print(target, separator);
  mu_g_n.print(target, separator);
  mu_f_n.print(target, separator);
    num_calls--;
}
}
void world_class::pddlprint(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_x.print_statistic();
  mu_h_n.print_statistic();
  mu_g_n.print_statistic();
  mu_f_n.print_statistic();
    num_calls--;
}
}
void world_class::print_diff(state *prevstate, FILE *target, const char *separator)
{
  if ( prevstate != NULL )
  {
    mu_x.print_diff(prevstate,target,separator);
    mu_h_n.print_diff(prevstate,target,separator);
    mu_g_n.print_diff(prevstate,target,separator);
    mu_f_n.print_diff(prevstate,target,separator);
  }
  else
print(target,separator);
}
void world_class::to_state(state *newstate)
{
  mu_x.to_state( newstate );
  mu_h_n.to_state( newstate );
  mu_g_n.to_state( newstate );
  mu_f_n.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf(" dec_5 ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return (mu_x) >= (-2);
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_x) >= (-2)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_x = (mu_x) - (5);
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf(" dec_5 ");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf(" dec_1 ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return (mu_x) >= (-2);
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 1;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_x) >= (-2)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 1;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_x = (mu_x) - (1);
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf(" dec_1 ");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf(" add_10 ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return (mu_x) < (40);
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 2;
    while (what_rule < 3 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_x) < (40)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 2;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_x = (mu_x) + (10);
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf(" add_10 ");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf(" add_5 ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return (mu_x) < (40);
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 3;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_x) < (40)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 3;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_x = (mu_x) + (5);
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf(" add_5 ");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf(" add_1 ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return (mu_x) < (40);
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 4;
    while (what_rule < 5 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_x) < (40)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 4;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_x = (mu_x) + (1);
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf(" add_1 ");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
public:
void SetNextEnabledRule(RULE_INDEX_TYPE & what_rule)
{
  category = CONDITION;
  if (what_rule<1)
    { R0.NextRule(what_rule);
      if (what_rule<1) return; }
  if (what_rule>=1 && what_rule<2)
    { R1.NextRule(what_rule);
      if (what_rule<2) return; }
  if (what_rule>=2 && what_rule<3)
    { R2.NextRule(what_rule);
      if (what_rule<3) return; }
  if (what_rule>=3 && what_rule<4)
    { R3.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<5)
    { R4.NextRule(what_rule);
      if (what_rule<5) return; }
}
bool Condition(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
  if (r>=2 && r<=2) return R2.Condition(r-2);
  if (r>=3 && r<=3) return R3.Condition(r-3);
  if (r>=4 && r<=4) return R4.Condition(r-4);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code(r-2); return; } 
  if (r>=3 && r<=3) { R3.Code(r-3); return; } 
  if (r>=4 && r<=4) { R4.Code(r-4); return; } 
}
int Priority(RULE_INDEX_TYPE r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
  if (r>=2 && r<=2) { return R2.Priority(); } 
  if (r>=3 && r<=3) { return R3.Priority(); } 
  if (r>=4 && r<=4) { return R4.Priority(); } 
}
char * Name(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  if (r>=2 && r<=2) return R2.Name(r-2);
  if (r>=3 && r<=3) return R3.Name(r-3);
  if (r>=4 && r<=4) return R4.Name(r-4);
  return NULL;
}
int Duration(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Duration(r-0);
  if (r>=1 && r<=1) return R1.Duration(r-1);
  if (r>=2 && r<=2) return R2.Duration(r-2);
  if (r>=3 && r<=3) return R3.Duration(r-3);
  if (r>=4 && r<=4) return R4.Duration(r-4);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
int Weight(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Weight(r-0);
  if (r>=1 && r<=1) return R1.Weight(r-1);
  if (r>=2 && r<=2) return R2.Weight(r-2);
  if (r>=3 && r<=3) return R3.Weight(r-3);
  if (r>=4 && r<=4) return R4.Weight(r-4);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
char * PDDLName(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLName(r-0);
  if (r>=1 && r<=1) return R1.PDDLName(r-1);
  if (r>=2 && r<=2) return R2.PDDLName(r-2);
  if (r>=3 && r<=3) return R3.PDDLName(r-3);
  if (r>=4 && r<=4) return R4.PDDLName(r-4);
  return NULL;
}
RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLClass(r-0);
  if (r>=1 && r<=1) return R1.PDDLClass(r-1);
  if (r>=2 && r<=2) return R2.PDDLClass(r-2);
  if (r>=3 && r<=3) return R3.PDDLClass(r-3);
  if (r>=4 && r<=4) return R4.PDDLClass(r-4);
Error.Notrace("Internal: NextStateGenerator -- querying PDDL class for nonexisting rule.");
}
};
const RULE_INDEX_TYPE numrules = 5;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 5


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("start");
  }
  void Code(unsigned short r)
  {
mu_x = 3;
mu_h_n = (mu_G) - (mu_x);
mu_g_n = 0;
mu_f_n = (mu_h_n) + (mu_g_n);
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Goal records
 ********************/
int mu__goal_0() // Goal "enjoy"
{
return (mu_x) == (mu_G);
};

bool mu__condition_1() // Condition for Rule "enjoy"
{
  return mu__goal_0( );
}

/**** end rule declaration ****/

const rulerec goals[] = {
{"enjoy", &mu__condition_1, NULL, },
};
const unsigned short numgoals = 1;

/********************
  Metric related stuff
 ********************/
const short metric = 0;

/********************
  Invariant records
 ********************/
const rulerec invariants[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numinvariants = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
g_n:NoScalarset
x:NoScalarset
h_n:NoScalarset
f_n:NoScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { unsigned long ret=0; for (unsigned long i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_g_n.MultisetSort();
        mu_x.MultisetSort();
        mu_h_n.MultisetSort();
        mu_f_n.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_integer::Permute(PermSet& Perm, int i) {};
void mu_1_integer::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_integer::Canonicalize(PermSet& Perm) {};
void mu_1_integer::SimpleLimit(PermSet& Perm) {};
void mu_1_integer::ArrayLimit(PermSet& Perm) {};
void mu_1_integer::Limit(PermSet& Perm) {};
void mu_1_integer::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  unsigned int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_g_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_x.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_x.MultisetSort();
              mu_h_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_f_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_g_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_g_n.MultisetSort();
          mu_x.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_x.MultisetSort();
          mu_h_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_h_n.MultisetSort();
          mu_f_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_f_n.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_g_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_x.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_x.MultisetSort();
              mu_h_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_f_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_g_n.MultisetSort();
      mu_x.MultisetSort();
      mu_h_n.MultisetSort();
      mu_f_n.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  unsigned int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_g_n.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_g_n.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_x.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_x.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_h_n.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_h_n.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_f_n.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_f_n.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
  Include
 ********************/
#include "upm_epilog.hpp"
