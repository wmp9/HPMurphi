/*
* Universal Planner CGMurphi Release 2.0.b1
* Copyright (C) 2007 - 2010: G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio
*
* Read the file "license" distributed with these sources, or call
* UPMurphi with the -l switch for additional information.
* Current release developed by G. Della Penna (giuseppe.dellapenna@univaq.it)
*
*/

/****************************************
  There are 4 groups of implementations:
  0) local #define switches
  1) Error_handler class implementation
  2) argclass implementation
  3) general printing routine (not belong to any class)
  4) trace info file

  to set default options, set parameter at
  argclass::argclass(...)
  ****************************************/

/****************************************
  #defines for switches to the program.
  ****************************************/

#include <ctype.h>

// General
#define HELP_FLAG       "-h"    /* for help list. */
#define LICENSE_FLAG "-c"    /*  print license. */

// Verification Strategy
#define SIMULATE_FLAG   "-s"    /* simulate instead of verifying. */
#define VERIFY_FLAG     "-v"    /* verify with breadth-first search. */
#define EXPLORE_ALG_BFS_FLAG "-vbfs" /* Ditto. */
#define EXPLORE_ALG_DFS_FLAG "-vdfs" /* verify with depth-first search. */

// main options
#define MEM_MEG_PREFIX  "-m"    /* Memory allotment in Meg. */
#define MEM_K_PREFIX    "-k"    /* Memory allotment in K. */
#define LOOPMAX_PREFIX  "-loop" /* number of times you can go around a loop. */

// progress
#define VERBOSE_FROM "-pfrom"
#define VERBOSE_FLAG    "-p"    /* Print every time, with lots of detail. */
#define PRINT_PROGRESS_FLAG   "-pi"   /* Print progress interval. */
#define PRINT_NONE_FLAG  "-pn"  /* Don't print progress reports at all. */

// error detection
#define CHECK_DEADLOCK_FLAG "-cdl" /* verify with deadlock checking */
#define CONTINUE_AFTER_ERROR_FLAG "-finderrors" /* verify without stopping at error */
#define MAX_NUM_ERRORS_PREFIX "-errorsmax" /* verify without stopping at error */

// error trace handling
#define TRACE_VIOLATE_FLAG "-tv"/* Print a violating trace. */
#define TRACE_DIFF_FLAG  "-td" /* Print state differences instead of full states. */
#define TRACE_FULL_FLAG "-tf"   /* print full states in traces. */
#define TRACE_ALL_FLAG  "-ta"   /* Print traces containing all states. */
#define TRACE_NONE_FLAG "-tn"   /* no traces. */

// #define TRACE_LONGEST_FLAG "-tl"/* Print the longest trace. */
// I don\'t know that -tl is for (Norris)

// analysis of state space
#define PRINT_RULE_FLAG "-pr"   /* Print out rule information. */
#define PRINT_HASH_FLAG "-ph"   /* Print out hash table. */
// #define PRINT_STATE_FLAG "-ps"  /* "Print start, progress, and final state. "*/

// symmetry
#define NO_SYM_FLAG "-nosym"      /* do not use symmmetry reduction technique */
#define SYMMETRY_PREFIX "-sym"    /* use symmetry reduction technique */
#define NO_MULTISET_FLAG "-nomultiset"    /* do not use multiset reduction technique */
#define PERM_LIMIT "-permlimit"   /* maximum number of permutations wasted on canon */

// debug symmetry
#define TEST1_PREFIX "-testa"     /* use to enter testing parameter */
#define TEST2_PREFIX "-testb"     /* use to enter testing parameter */
#define DEBUG_SYM_FLAG "-debugsym"     /* use to enter testing parameter */

// Uli: hash compaction options
#ifdef HASHC
#define NUM_BITS_PREFIX     "-b"     // number of bits to store
#define TRACE_DIR_PREFIX    "-d"     // directory for error trace info file
#endif

// just for your information
#define DEFAULT_FLAGS   VERIFY_FLAG PRINT_100_FLAG TRACE_VIOLATE_FLAG

#define HORIZON "-l" /*Max length of a trajectory (i.e. max level of BFS)*/
#define PHASE "-phase"

#define SEARCH_MODE_UNIVERSAL_OPTIMAL_FLAG "-search:uo"
#define SEARCH_MODE_UNIVERSAL_FLAG "-search:u"
#define SEARCH_MODE_OPTIMAL_FLAG "-search:o"
#define SEARCH_MODE_FEASIBLE_FLAG "-search:f"

#define OUTPUT_FORMAT_RAW "-format:raw"
#define OUTPUT_FORMAT_TEXT "-format:text"
#define OUTPUT_FORMAT_VERBOSE_TEXT "-format:verbose"
#define OUTPUT_FORMAT_OBDD "-format:obdd"
#define OUTPUT_FORMAT_PDDL "-format:pddl"
#define OUTPUT_FORMAT_VERBOSE_PDDL "-format:pddlv"
#define OUTPUT_FORMAT_VERY_VERBOSE_PDDL "-format:pddlvv"
#define OUTPUT_FORMAT_CSV "-format:csv"

#define OUTPUT_FILE_PREFIX "-output"

#define NODELETE_INTERMEDIATE_SWITCH "-noclear"

/****************************************
  Implementation for the Error class.
  ****************************************/

// make sure that you have executed fflush(stdout) when
// you change from printf to cout, and cout.flush() when
// you change from cout to printf.

// on second thought, I am rewriting everything to only use cout.
// We may well be placing ourselves wholly within the hands of
// flaky ostreams, but we won\'t have weirdnesses with not flushing
// things properly. RLM 7/23/93

void Error_handler::Error( const char *fmt... )
{
  // Uli: assumptions:
  // - curstate points to the state whose successors are currently being
  //  generated
  // - NumCurState is set to the number of curstate in the trace info file
  // - curstate may not point to workingstate buffer
  // - an error occurred during the generation of one of the successors
  // - for startstates: what_startstate is set correctly

  // we regenerate the trace; this is necessary
  // with symmetry extension, since
  // [s1] -[a]-> [s2] in the hash table does not imply s1-a->s2

  // there are two phases for error reporting with trace printing
  // phase 1) first call to Error(...); error detected and regenerate
  //          trace from the rules recorded in state set.
  //          print trace until the last state
  // phase 2) second call to Error(...); error detected again when
  //          regenerate the error state; print the last state and
  //          print summary

  // Uli: in simulation mode call "notrace" version
  if (args->main_alg.mode==argmain_alg::Simulate)
  {
    cout << "\nStatus:\n\n";
    cout << "\t" << Rules->NumRulesFired()
         << " rules fired in simulation in "
         << SecondsSinceStart() << "s.\n";
    Notrace(fmt);
  }

  static int phase = 1;

  //  unsigned last_rule = what_rule;   // Uli: unsigned short -> unsigned

  // set up error statement in buffer.
  va_list argp;
  va_start ( argp, fmt);
  vsprintf(buffer,fmt,argp);
  va_end(argp);

  if (args->print_trace.value)
    {
      // please print trace

      if (curstate == NULL)
	{
	  // Error when generating startstate

	  // header
	  cout << "\nThe following is the error occured during the construction of a startstate:\n\n\t";
	  cout << buffer << "\n\n";

	  // print fragment of startstate created so far
	  cout << "Fragment of startstate "
	       << StartState->LastStateName()
	       << " obtained when the error is found is:\n";
	  theworld.print();
	  cout << "----------\n\n";

	}
      else
	{
	  // Error when firing the rule "what_rule"
	  // spit into two phases Error reporting

	  if (phase == 1)
	    {
	      // phase 1 of Error reporting with trace
	      phase = 2;

              // header
	      cout << "\nThe following is the error trace for the error:\n\n\t";
	      cout << buffer << "\n\n";

	      // print violate trace
	      // the procedure will not return; in fact, it will execute
	      // the same rule again and call Error(...) again and enter
	      // phase 2 of trace generation
	      Reporter->print_trace_with_theworld();
	    }
	  else
	    {
	      // phase 2 of Error reporting with trace

	      if (category == CONDITION)
		{
		  // print last state
		  cout << "Guard of the rule\n\t"
		       << Rules->LastRuleName()
		       << "\nchecked and caused Error.\n";
		  cout << "----------\n\n";
		}
	      else
		{
		  // print last state
		  cout << "Rule "
		       << Rules->LastRuleName()
		       << " fired.\n";
		  cout << "The last state of the trace (in full) is:\n";
		  theworld.print();
		  cout << "----------\n\n";
		}

	    }
	}

      // print end of trace
      cout << "End of the error trace.\n";

    }

  // section separator
  cout << "\n====================================="
       << "=====================================\n";

  // print summary of result
  cout << "\nResult:\n\n\t";
  cout << buffer << '\n';
  Reporter->print_summary(FALSE);
  cout.flush();
#ifdef HASHC
  if (TraceFile!=NULL)
    delete TraceFile;
#endif
  exit(1);
}

void Error_handler::Deadlocked( const char *fmt... )
{
  // Uli: assumptions:
  // - curstate points to the state that exposes the error
  // - NumCurState is set to the number of the error state in the trace
  //  info file
  // - curstate may not point to workingstate buffer

  // set up error statement fmt in argp.
  va_list argp;
  va_start ( argp, fmt);
  vsprintf(buffer, fmt, argp);
  va_end (argp);

  // print violate trace
  if (args->print_trace.value)
    {
      // header
      cout << "\nThe following is the error trace for the error:\n\n\t";
      cout << buffer << "\n\n";

      // trace
      Reporter->print_trace_with_curstate();

      // print end of trace
      cout << "End of the error trace.\n";
    }

  // section separator
  cout << "\n====================================="
       << "=====================================\n";

  // print summary of result
  cout << "\nResult:\n\n\t";
  cout << buffer << '\n';
  Reporter->print_summary(FALSE);
  cout.flush();
#ifdef HASHC
  if (TraceFile!=NULL)
    delete TraceFile;
#endif
  exit(1);
}

void Error_handler::Notrace( const char *fmt... )
{
  // set up error statement fmt in argp.
  va_list argp;
  va_start ( argp, fmt);
  vsprintf( buffer, fmt, argp);
  va_end(argp);

  // print error
  cout << "\nError:\n\n\t";
  cout << buffer << "\n\n";
  va_end(argp);

  // print progress upto point of error
  if (StateSet != NULL) /* queue has been declared */
    {
      Reporter->print_progress();
      cout << "\n\n";
    }
  cout.flush();
#ifdef HASHC
  if (TraceFile!=NULL)
    delete TraceFile;
#endif
  exit(1);
}

/****************************************
  Implementation for the argclass class for handling runtime arguments.
  ****************************************/

argclass::argclass(int ac, char** av)
: argc(ac), argv(av),
  print_trace     (FALSE, "trace printing"),
  full_trace      (FALSE, "printing diff/full states in trace"),
  trace_all       (FALSE, "printing all states"),
  find_errors     (FALSE, "continuing after error"),
  max_errors      (DEFAULT_MAX_ERRORS, "maximium number of errors"),
  mem             (DEFAULT_MEM, "memory allocation"),
  progress_count  (1000,  "progress count"),
  print_progress  (TRUE,  "progress printing"),
  main_alg        (argmain_alg::Explore_bfs, "main algorithm"),
  loopmax         (DEF_LOOPMAX,"maximium loop count"),
  verbose         (FALSE, "verbose (whether to print out every action"),
  verbose_from_state (0,"verbose controlled mode"),
  use_verbose_from_state (FALSE,"use verbose controlled mode"),
  no_deadlock     (TRUE, "deadlock detection"),
  print_options   (FALSE, "options printing"),
  print_license   (FALSE, "license printing"),
  print_rule      (FALSE, "rule information printing"),
  print_hash      (FALSE, "hashtable information printing"),
  symmetry_reduction (TRUE, "symmetry option"),
  sym_alg         (argsym_alg::Heuristic_Small_Mem_Canonicalize, "symmetry algorithm"),
  perm_limit      (10,"permutation limit"),
  multiset_reduction (TRUE, "multiset option"),
  test_parameter1 (100,"testing parameter1"),
  test_parameter2 (100,"testing parameter2"),
#ifdef HASHC
  num_bits        (DEFAULT_BITS, "stored bits"),   // added by Uli
  trace_file      (FALSE, "trace info file"),
#endif
  debug_sym       (FALSE, "debug symmetry"),
  sim_report (FALSE,"activate sim report "),
//UPMURPHI_BEGIN
  deleteintermediate (TRUE,"delete intermediate files"),
  horizon (1000000,"bfs limit"),
  phase (0,"algorithm phase"),
  search_alg (argsearch_alg::Optimal, "search algorithm"),
  output_fmt (argoutput_fmt::PDDL, "output format"),
  output_file ("","output file")
  
//UPMURPHI_END
  {
  string_iterator *temp = NULL;

  temp = new arg_iterator(ac, av);
MEMTRACKALLOC
  ProcessOptions( temp );
  delete temp;
  temp = NULL;

#ifdef HASHC
  // Uli: do not use trace info file in dfs case
  if (main_alg.mode == argmain_alg::Explore_dfs) {
    if (trace_file.value) {
      delete TraceFile;
      trace_file.reset(FALSE);
    }
  }

  // Uli: check if trace is wanted but cannot be generated
  if (main_alg.mode == argmain_alg::Explore_bfs)
    if (print_trace.value  && !trace_file.value)
      Error.Notrace
        ("Cannot print error trace if you do not specify trace info file.");

  // Uli: set number of bytes in trace info file
  //      cannot be done earlier since number of bits may be unknown
  if (trace_file.value) {
    TraceFile->setBytes(int(num_bits.value));
    print_trace.reset(TRUE);
  }
#endif

  // avoid mixing verbose and progress report
  if (verbose.value) print_progress.set(FALSE);

  if (main_alg.mode != argmain_alg::Explore_bfs && find_errors.value)
  // changed by Uli
    {
      Error.Notrace("Please use -vbfs for finding multiple errors in single run.");
    }

  if (sym_alg.mode != argsym_alg::Heuristic_Small_Mem_Canonicalize
      && perm_limit.value !=0)
    {
      perm_limit.set(0);
    }

  if (debug_sym.value) symmetry_reduction.reset(FALSE);

  PrintInfo();
}

void argclass::PrintInfo( void )
{
  if (print_license.value) PrintLicense();

		cout << "\n======================================================\n"
		<< "\nUPMurphi Release 2.0.b4\n"
		<< "Universal Planner for Discrete Time Hybrid Systems\n\n"
		<< "Copyright (C) 2007 - 2010\n"
		<< "G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio\n\n";

  if (!print_license.value)
    cout << "Call with the -c flag or read the license file for terms\n"
         << "and conditions of use.\n";

  if (!print_options.value)
    cout << "Run this program with \"-h\" for the list of options.\n";

    cout << "Send bugs and comments to giuseppe.dellapenna@univaq.it\n";
	cout << "\n======================================================\n";  // cout.flush();

  if (print_options.value) PrintOptions();
}

void argclass::ProcessOptions(string_iterator *options)
{
  const char* option;
  bool no_verification = FALSE;
  unsigned long temp;
  char temp_str[256];

  for ( options->start();
	!options->done();
	options->next()  )
    {
      option = options->value();

	/* Reading of maximum length of BFS*/
      if ( strncmp(option, HORIZON, strlen(HORIZON) ) == 0 )
        {
          if ( strlen(option) <= strlen(HORIZON) ) /* We cannot have a space before the number */
			{
			  sscanf( options->nextvalue(), "%s", temp_str );
			  if (isdigit(temp_str[0]))
				{
				  sscanf( temp_str, "%lu", &temp );
				  options->next();
				}
			  else
				Error.Notrace("Unrecognized horizon value.  Do '%s -h' for list of valid arguments.", argv[0]);
			}
          else
			{
			  sscanf( options->value() + strlen(HORIZON), "%s", temp_str );
			  if (isdigit(temp_str[0]))
				sscanf( temp_str, "%lu", &temp );
			  else
				Error.Notrace("Unrecognized horizon value.  Do '%s -h' for list of valid arguments.",  argv[0]);
			}
			horizon.set(temp * 1); /* times 1 Meg. */
			continue;
        };


      /* we have to handle memory as a special case. */
      if ( strncmp(option, MEM_MEG_PREFIX, 2 ) == 0 )
        {
          if ( strlen(option) <= strlen(MEM_MEG_PREFIX) ) /* We cannot have a space before the number */
	    {
	      sscanf( options->nextvalue(), "%s", temp_str );
	      if (isdigit(temp_str[0]))
		{
		  sscanf( temp_str, "%lu", &temp );
		  options->next();
		}
	      else
		Error.Notrace("Unrecognized memory size.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          else
	    {
              sscanf( options->value() + strlen(MEM_MEG_PREFIX), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized memory size.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  mem.set(temp * 0x100000L); /* times 1 Meg. */
          continue;
        };
      if ( strncmp(option, MEM_K_PREFIX, strlen(MEM_K_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(MEM_K_PREFIX) ) /* We cannot have a space before the number */
	    {
	      sscanf( options->nextvalue(), "%s", temp_str );
	      if (isdigit(temp_str[0]))
		{
		  sscanf( temp_str, "%lu", &temp );
		  options->next();
		}
	      else
		Error.Notrace("Unrecognized memory size.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          else
	    {
              sscanf( options->value() + strlen(MEM_K_PREFIX), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized memory size.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  mem.set(temp * 0x400L); /* times 1 Kilobyte. */
          continue;
        };

#ifdef HASHC
      // added by Uli
      if ( strncmp(option, NUM_BITS_PREFIX, strlen(NUM_BITS_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(NUM_BITS_PREFIX) )
          // there is a space before the number
            {
              sscanf( options->nextvalue(), "%s", temp_str );
              if (isdigit(temp_str[0]))
                {
                  sscanf( temp_str, "%lu", &temp );
                  options->next();
                }
              else
                Error.Notrace("Unrecognized number of bits.",
                              argv[0]);
            }
          else   // no space
            {
              sscanf( options->value() + strlen(NUM_BITS_PREFIX), "%s", temp_str );
              if (isdigit(temp_str[0]))
                sscanf( temp_str, "%lu", &temp );
              else
                Error.Notrace("Unrecognized number of bits.",
                              argv[0]);
            }
          if (temp>64 || temp<1)
            Error.Notrace("Number of bits not allowed.");
          num_bits.set(temp);
          continue;
        };

      // added by Uli
      if ( strncmp(option, TRACE_DIR_PREFIX, strlen(TRACE_DIR_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(TRACE_DIR_PREFIX) )
          // there is a space before the filename
            {
              sscanf( options->nextvalue(), "%s", temp_str );
              options->next();
            }
          else   // no space
            {
              sscanf( options->value() + strlen(TRACE_DIR_PREFIX), "%s", temp_str
);
            }
          TraceFile = new TraceFileManager(temp_str);
MEMTRACKALLOC	  
          trace_file.set(TRUE);
          continue;
        };
#endif

      if ( strncmp(option, LOOPMAX_PREFIX, strlen(LOOPMAX_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(LOOPMAX_PREFIX) ) /* We cannot have a space before the number */
	    {
	      sscanf( options->nextvalue(), "%s", temp_str );
	      if (isdigit(temp_str[0]))
		{
		  sscanf( temp_str, "%lu", &temp );
		  options->next();
		}
	      else
		Error.Notrace("Unrecognized iterations number.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          else
	    {
              sscanf( options->value() + strlen(LOOPMAX_PREFIX), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized iterator number.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  loopmax.set(temp);
          continue;
        };
      if ( strncmp(option, PERM_LIMIT, strlen(PERM_LIMIT) ) == 0 )
        {
          if ( strlen(option) <= strlen(PERM_LIMIT) ) /* We cannot have a space before the number */
	    {
	      sscanf( options->nextvalue(), "%s", temp_str );
	      if (isdigit(temp_str[0]))
		{
		  sscanf( temp_str, "%lu", &temp );
		  options->next();
		}
	      else
		Error.Notrace("Unrecognized permutation limit number.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          else
	    {
              sscanf( options->value() + strlen(PERM_LIMIT), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized permutation limit number.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  perm_limit.set(temp);
          continue;
        };
      if ( strncmp(option, TEST1_PREFIX, strlen(TEST1_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(TEST1_PREFIX) ) /* We cannot have a space before the number */
	    Error.Notrace("Unrecognized test parameter 1.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
          else
	    {
	      sscanf( options->value() + strlen(TEST1_PREFIX), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized test parameter 1.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  test_parameter1.set(temp);
          continue;
        };
      if ( strncmp(option, TEST2_PREFIX, strlen(TEST2_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(TEST2_PREFIX) ) /* We cannot have a space before the number */
	    Error.Notrace("Unrecognized test parameter 2.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
          else
	    {
	      sscanf( options->value() + strlen(TEST2_PREFIX), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized test parameter 2.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  test_parameter2.set(temp);
          continue;
        };
      if( strcmp( option, SIMULATE_FLAG ) == 0 )
        {
          main_alg.set(argmain_alg::Simulate);
          continue;
        }
      if( strcmp( option, VERIFY_FLAG ) == 0 )
        {
          main_alg.set(argmain_alg::Explore_bfs);
          continue;
        }
      if( strcmp( option, EXPLORE_ALG_BFS_FLAG ) == 0 )
        {
          main_alg.set(argmain_alg::Explore_bfs);
          continue;
        }
      if( strcmp( option, EXPLORE_ALG_DFS_FLAG ) == 0 )
        {
          main_alg.set(argmain_alg::Explore_dfs);
          continue;
        }
      if( strcmp( option, CHECK_DEADLOCK_FLAG ) == 0 )
        {
          no_deadlock.set(FALSE);
          continue;
        }
      if( strcmp( option, CONTINUE_AFTER_ERROR_FLAG ) == 0 )
        {
          find_errors.set(TRUE);
          continue;
        }
      if( strncmp( option, MAX_NUM_ERRORS_PREFIX, strlen(MAX_NUM_ERRORS_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(MAX_NUM_ERRORS_PREFIX) )
	    {
	      sscanf( options->nextvalue(), "%s", temp_str );
	      if (isdigit(temp_str[0]))
		{
		  sscanf( temp_str, "%lu", &temp );
		  options->next();
		}
	      else
		Error.Notrace("Unrecognized maximum number of errors.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          else
	    {
              sscanf( options->value() + strlen(MAX_NUM_ERRORS_PREFIX), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized maximum number of errors.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  max_errors.set(temp); /* times 1 Meg. */
          continue;
        };
      /* control frequency of printouts. */
      if ( strcmp( option, VERBOSE_FLAG ) == 0 )
        {
          verbose.set(TRUE);
          continue;
        }
      if ( strcmp ( option, VERBOSE_FROM ) == 0 )
        {
    	     sscanf( options->nextvalue(), "%s", temp_str );
    	     if (isdigit(temp_str[0]))
  	        {
	          sscanf( temp_str, "%lu", &temp );
	          options->next();
	        }
	        else
   	       Error.Notrace("Unrecognized number for verbose mode.");
           verbose_from_state.set(temp);
           print_progress.set(TRUE);
           use_verbose_from_state.set(TRUE);
           continue;
        }
      if( strncmp( option, PRINT_PROGRESS_FLAG, strlen(PRINT_PROGRESS_FLAG) ) == 0 )
        {
          if ( strlen(option) <= strlen(PRINT_PROGRESS_FLAG) )
	    {
	      sscanf( options->nextvalue(), "%s", temp_str );
	      if (isdigit(temp_str[0]))
		{
		  sscanf( temp_str, "%lu", &temp );
		  options->next();
		}
	      else
		Error.Notrace("Unrecognized progress interval.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          else
	    {
              sscanf( options->value() + strlen(PRINT_PROGRESS_FLAG), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized progress interval.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          progress_count.set(temp);
          print_progress.set(TRUE);
          continue;
        };
      if ( strcmp( option, PRINT_NONE_FLAG ) == 0 )
        {
          print_progress.set(FALSE);
          continue;
        }
      /* handle trace types. */
      if ( strcmp( option, TRACE_VIOLATE_FLAG ) == 0 )
        {
          print_trace.set(TRUE);
          continue;
        }
      if ( strcmp( option, TRACE_DIFF_FLAG ) == 0 )
        {
          print_trace.set(TRUE);
          full_trace.set(FALSE);
          continue;
        }
      if ( strcmp( option, TRACE_FULL_FLAG ) == 0 )
        {
          print_trace.set(TRUE);
          full_trace.set(TRUE);
          continue;
        }
      if ( strcmp( option, TRACE_ALL_FLAG ) == 0 )
       {
          print_trace.set(TRUE);
          trace_all.set(TRUE);
          continue;
        }
      if ( strcmp( option, TRACE_NONE_FLAG ) == 0 )
        {
          print_trace.set(FALSE);
          continue;
        }
      if ( strcmp( option, HELP_FLAG ) == 0 )
        {
          print_options.set(TRUE);
          no_verification = TRUE;
          continue;
        }
      if ( strcmp( option, LICENSE_FLAG ) == 0 )
        {
          print_license.set(TRUE);
          continue;
        }
      if( strcmp( option, PRINT_RULE_FLAG ) == 0 )
        {
	  print_rule.set(TRUE);
          continue;
        }
      if( strcmp( option, NO_SYM_FLAG ) == 0 )
        {
	  symmetry_reduction.set(FALSE);
          continue;
        }
       if( strcmp( option, NO_MULTISET_FLAG ) == 0 )
         {
 	  multiset_reduction.set(FALSE);
           continue;
         }
      if ( strncmp(option, SYMMETRY_PREFIX, strlen(SYMMETRY_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(SYMMETRY_PREFIX) ) /* We cannot have a space before the number */
	    temp = 1;
          else
	    {
	      sscanf( options->value() + strlen(SYMMETRY_PREFIX), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized symmetry algorithm.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }

	  symmetry_reduction.set(TRUE);
	  switch (temp) {
 	  case 1:
	    sym_alg.set(argsym_alg::Exhaustive_Fast_Canonicalize);
 	    break;
	  case 2:
	    sym_alg.set(argsym_alg::Heuristic_Fast_Canonicalize);
	    break;
	  case 3:
	    sym_alg.set(argsym_alg::Heuristic_Small_Mem_Canonicalize);
	    break;
 	  case 4:
 	    sym_alg.set(argsym_alg::Heuristic_Fast_Normalize);
 	    break;
	  default:
	    Error.Notrace("Unrecognized symmetry algorithm %lu.  Do '%s -h' for list of valid arguments.",
			  temp, argv[0]);
	  }
          continue;
        };
	if ( strncmp(option, PHASE, strlen(PHASE) ) == 0 )
        {
          if ( strlen(option) <= strlen(PHASE) ) /* We cannot have a space before the number */
	    {
	      sscanf( options->nextvalue(), "%s", temp_str );
	      if (isdigit(temp_str[0]))
		{
		  sscanf( temp_str, "%lu", &temp );
		  options->next();
		}
	      else
		Error.Notrace("Unrecognized phase number.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
          else
	    {
              sscanf( options->value() + strlen(PHASE), "%s", temp_str );
	      if (isdigit(temp_str[0]))
	        sscanf( temp_str, "%lu", &temp );
	      else
		Error.Notrace("Unrecognized phase number.  Do '%s -h' for list of valid arguments.",
			      argv[0]);
	    }
	  phase.set(temp);
          continue;
        };
	  if( strcmp( option, SEARCH_MODE_UNIVERSAL_OPTIMAL_FLAG ) == 0 )
        {
          search_alg.set(argsearch_alg::Universal_Optimal);
          continue;
        }
  if( strcmp( option, SEARCH_MODE_UNIVERSAL_FLAG ) == 0 )
        {
          search_alg.set(argsearch_alg::Universal);
          continue;
        }
  if( strcmp( option, SEARCH_MODE_OPTIMAL_FLAG ) == 0 )
        {
          search_alg.set(argsearch_alg::Optimal);
          continue;
        }
  if( strcmp( option, SEARCH_MODE_FEASIBLE_FLAG ) == 0 )
        {
          search_alg.set(argsearch_alg::Feasible);
          continue;
        }	
  if( strcmp( option, OUTPUT_FORMAT_RAW ) == 0 )
        {
          output_fmt.set(argoutput_fmt::Raw);
          continue;
        }	
  if( strcmp( option, OUTPUT_FORMAT_TEXT ) == 0 )
        {
          output_fmt.set(argoutput_fmt::Text);
          continue;
        }	
  if( strcmp( option, OUTPUT_FORMAT_VERBOSE_TEXT ) == 0 )
        {
          output_fmt.set(argoutput_fmt::Text_Verbose);
          continue;
        }	
#ifdef OBDD_COMPRESSION
	if( strcmp( option, OUTPUT_FORMAT_OBDD ) == 0 )
        {
          output_fmt.set(argoutput_fmt::OBDD);
          continue;
        }	
#endif		
  if( strcmp( option, OUTPUT_FORMAT_PDDL ) == 0 )
        {
          output_fmt.set(argoutput_fmt::PDDL);
          continue;
        }			
	if( strcmp( option, OUTPUT_FORMAT_VERBOSE_PDDL ) == 0 )
        {
          output_fmt.set(argoutput_fmt::PDDL_Verbose);
          continue;
        }	
	if( strcmp( option, OUTPUT_FORMAT_VERY_VERBOSE_PDDL ) == 0 )
        {
          output_fmt.set(argoutput_fmt::PDDL_VeryVerbose);
          continue;
        }	
	if( strcmp( option, OUTPUT_FORMAT_CSV ) == 0 )
        {
          output_fmt.set(argoutput_fmt::CSV);
          continue;
        }			
	if( strcmp( option, NODELETE_INTERMEDIATE_SWITCH ) == 0 )
        {
          deleteintermediate.set(FALSE);
          continue;
        }			
	if ( strncmp(option, OUTPUT_FILE_PREFIX, strlen(OUTPUT_FILE_PREFIX) ) == 0 )
        {
          if ( strlen(option) <= strlen(OUTPUT_FILE_PREFIX) )
          // there is a space before the filename
            {
              sscanf( options->nextvalue(), "%s", temp_str );
              options->next();
            }
          else   // no space
            {
              sscanf( options->value() + strlen(OUTPUT_FILE_PREFIX), "%s", temp_str
);
            }
          output_file.set(temp_str);
          continue;
        };
		
//       if ( StrStr( ALLOWED_FLAGS, option ) == NULL )
        /* strstr isn\'t in std.h.  Sheesh. And likewise bleah. */
//         {
          Error.Notrace("Unrecognized flag %s.  Do '%s -h' for list of valid arguments.",
                        option, argv[0]);
          continue;
//        }
    }
  if (no_verification) main_alg.set(argmain_alg::Nothing);
}

void argclass::PrintOptions( void )   // changes by Uli
{
cout << "Options:\n"
<< "General:\n"
<< "\t-h            help.\n"
<< "\t-c            print license.\n"
<< "\t-noclear      do not delete working disk files (useful with -phase).\n"
<< "\t-phase<1..5>	start with phase n (default: 0) - experimental.\n"
<< "\t-search:o	    create an optimal plan for each startstate (default).\n"
<< "\t-search:u	    create an universal plan.\n"
<< "\t-search:uo	create an universal optimal plan.\n"
<< "\t-search:f	    create a feasible plan for each startstate.\n"
<< "Exploration Strategy: (default: -v)\n"
//<< "\t-s            simulate.\n"
//<< "\t-v or -vbfs   breadth-first search.\n"
//<< "\t-vdfs         depth-first search.\n"
<< "\t-cdl          check for deadlock.\n"
<< "\t-l<n>         maximum bfs level (default: unlimited).\n"
<< "Memory: (default: -m8, -p3, -loop1000)\n"
<< "\t-m<n>         amount of memory for closed hash table in Mb.\n"
<< "\t-k<n>         same, but in Kb.\n"
<< "\t-loop<n>      allow loops to be executed at most n times.\n"
#ifdef HASHC
<< "\t-b<n>         hash compaction: number of bits to store (default: "<< DEFAULT_BITS << ").\n"
//<< "\t-d dir        write trace info into file dir/" << PROTOCOL_NAME << TRACE_FILE << ".\n"
#endif
<< "Reporting: \n"
<< "\t-p            make exploration verbose.\n"
//<< "\t-pfrom<n>     make verification (via bfs) verbose from state n.\n"
<< "\t-pi<n>         report progress every n events.\n"
<< "\t-pn           print no progress reports.\n"
//<< "\t-pr           print out rule information.\n"
<< "Output: \n"
<< "\t-output file  write output in file (default: stdout).\n"
<< "\t-format:pddl  output plans in pddl format (default).\n"
<< "\t-format:pddlv output plans in pddl format with verbose comments.\n"
<< "\t-format:pddlvv output plans in pddl format with very verbose comments.\n"
<< "\t-format:text  output plans/actions in text format.\n"
<< "\t-format:verbose  output plans/actions in verbose text format.\n"
<< "\t-format:raw  output actions in binary format.\n"
<< "\t-format:csv  output actions in csv format.\n"
#ifdef OBDD_COMPRESSION
<< "\t-format:obdd  output actions in obdd-compressed binary format.\n"
#endif
/*
<< "4) Error Trace Handling: (default: -tn)\n"
<< "\t-tv           write a violating trace (with default -td).\n"
<< "\t-td           write only state differences from the previous states.\n"
<< "\t              (in simulation mode, write only state differences in\n"
<< "\t               verbose mode.)\n"
<< "\t-tf           write full states in trace.\n"
<< "\t              (in simulation mode, write full states in verbose mode.)\n"
<< "\t-ta           write all generated states at least once.\n"
<< "\t-tn           write no trace (default).\n"
*/
<< "Reduction Techniques: (default:-sym3 with -permlimit 10 and multiset reduction)\n"
<< "\t-nosym        no symmetry reduction (multiset reduction still effective)\n"
<< "\t-nomultiset   no multiset reduction\n"
<< "\t-sym<n>       reduction by symmetry\n"
<< "\t-permlimit<n> max num of permutation checked in alg 3\n"
<< "\t              (for canonicalization, set it to zero)\n"
<< "\t              n | methods\n"
<< "\t              -----------------------------------\n"
<< "\t              1 | exhaustive canonicalize\n"
<< "\t              2 | heuristic fast canonicalization\n"
<< "\t                  (can be slower or faster than alg 3 canonicalization)\n"
<< "\t                  (use a lot of auxiliary memory for large scalarsets)\n"
<< "\t              3 | heuristic small mem canonicaliztion/normalization\n"
<< "\t                  (depends on -permlimit)\n"
<< "\t              4 | heuristic fast normalization (alg 3 with -permlimit 1)\n"
//<< "Planning: \n"
//<< "\t-sim<n.m>     generate and VALidate n.m % of controlled states \n\t\t      (assumes CTRL_table was already hashed with -hash option) \n"
//<< "\t-simreport<n> (only with -sim<n1.n2>) print progress report every n % of total plans\n"
//<< "\t-hash         hash (and write on disk) the controller table \n"
//<< "\t-startstates  generate .pddl+ optimal plan for each (controllable) startstate\n\t\t      (assumes CTRL_table was already hashed with -hash option) \n"
//UPMURPHI_END
<< "\n";
//  cout.flush();
/*
<< "6) Debug :"
<< "\t-ph           print out hashtable information.\n"
<< "\t-debugsym     run two hashtable in parallel.\n"
<< "\t-test1 <n>    enter test parameter 1.\n"
<< "\t\test2 <n>    enter test parameter 2.\n"
*/
}

void argclass::PrintLicense( void )
{
  cout << "License Notice:\n\n";
  cout << "To be written :)\n\n";
/*  
  cout << "\
Copyright (C) 1992 - 1999 by the Board of Trustees of \n\
Leland Stanford Junior University.\n\
\n\
License to use, copy, modify, sell and/or distribute this software\n\
and its documentation any purpose is hereby granted without royalty,\n\
subject to the following terms and conditions:\n\
\n\
1.  The above copyright notice and this permission notice must\n\
appear in all copies of the software and related documentation.\n\
\n\
2.  The name of Stanford University may not be used in advertising or\n\
publicity pertaining to distribution of the software without the\n\
specific, prior written permission of Stanford.\n\
\n\
3.  This software may not be called \"Murphi\" if it has been modified\n\
in any way, without the specific prior written permission of David L.\n\
Dill.\n\
\n\
4.  THE SOFTWARE IS PROVIDED \"AS-IS\" AND STANFORD MAKES NO\n\
REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, BY WAY OF EXAMPLE,\n\
BUT NOT LIMITATION.  STANFORD MAKES NO REPRESENTATIONS OR WARRANTIES\n\
OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE\n\
USE OF THE SOFTWARE WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS\n\
TRADEMARKS OR OTHER RIGHTS. STANFORD SHALL NOT BE LIABLE FOR ANY\n\
LIABILITY OR DAMAGES WITH RESPECT TO ANY CLAIM BY LICENSEE OR ANY\n\
THIRD PARTY ON ACCOUNT OF, OR ARISING FROM THE LICENSE, OR ANY\n\
SUBLICENSE OR USE OF THE SOFTWARE OR ANY SERVICE OR SUPPORT.\n\
\n\
LICENSEE shall indemnify, hold harmless and defend STANFORD and its\n\
trustees, officers, employees, students and agents against any and all\n\
claims arising out of the exercise of any rights under this Agreement,\n\
including, without limiting the generality of the foregoing, against\n\
any damages, losses or liabilities whatsoever with respect to death or\n\
injury to person or damage to property arising from or out of the\n\
possession, use, or operation of Software or Licensed Program(s) by\n\
LICENSEE or its customers.\n\
\n\
Notes:\n\
\n\
A.  Responsible use:\n\
\n\
Murphi is to be used as a DEBUGGING AID, not as a means of \n\
guaranteeing the correctness of a design.  We do not guarantee\n\
that all errors can be caught with Murphi.  There are many\n\
reasons for this:\n\
\n\
1. Specifications and verification conditions do not necessarily\n\
capture the conditions necessary for correct operation in practice.\n\
\n\
2. Many properties cannot be stated Murphi, including timing\n\
requirements, performance requirements, \"liveness\" properties\n\
(such as \"x will eventually occur\") and many others.\n\
\n\
3. Murphi cannot verify \"large\" systems.  Almost always, the sizes of\n\
various objects in the description must be modelled as being much\n\
smaller than they are in reality, in order to make verification\n\
feasible.  There is a high probability that design errors will only be\n\
manifested when the objects are large.\n\
\n\
4. The description of a design may not be consistent with what\n\
is actually implemented.\n\
\n\
5.  Murphi may have bugs that cause errors to be overlooked.\n\
\n\
In short, Murphi is totally inadequate for guaranteeing that there are\n\
no errors; however, it is sometimes effective for discovering errors\n\
that are difficult to detect by other means.\n\
\n\
B.  Courtesy\n\
\n\
Our motivation in distributing this software freely is to encourage\n\
others to evaluate its effectiveness on a wider range of applications\n\
than we have resources to attempt, and to provide a foundation for\n\
further development of automatic verification techniques.\n\
\n\
We would very much appreciate learning about other's experiences with\n\
the system and suggestions for improvements.  Even more, we would\n\
appreciate contributions of two kinds: additional verification\n\
examples that can be added to the distribution, and enhancements to\n\
the verification system.  Although we do not promise to distribute the\n\
examples or enhancements, we may do so if feasible.\n\
\n\
C.  Historical Notes\n\
\n\
The first version of the Murphi language and verification system was\n\
originally designed in 1990-1991 by David Dill, Andreas Drexler, Alan\n\
Hu, and C. Han Yang of the Stanford University Computer Systems\n\
Laboratory.  The first version of the program was primarily\n\
implemented by Andreas Drexler.\n\
\n\
The Murphi language was extensively modified and extended by David\n\
Dill, Alan Hu, Norris Ip, Ralph Melton, Seungjoon Park, and C. Han Yang\n\
in 1992.  The new version was almost entirely reimplemented by Ralph\n\
Melton during the summer and fall of 1992.\n\
\n\
Financial and other support for the design and implementation of\n\
Murphi has come from many sources, the Defense Advanced Research\n\
Projects Agency (under contract number N00039-91-C-0138), the National\n\
Science Foundation (grant number MIP-8858807), the Powell Foundation,\n\
the Stanford Center for Integrated Systems, the U.S. Office of Naval\n\
Research, and Mitsubishi Electronic Laboratories America.  Equipment\n\
was provided by Sun Microsystems, the Digital Equipment Corporation,\n\
and IBM.\n\
\n\
These notes are based on information provided to Stanford that has\n\
not been independently verified or checked.\n\
\n\
D.  Support, comments, feedback\n\
\n\
If you need help or have comments or suggestions regarding Murphi,\n\
please send electronic mail to \"murphi@verify.stanford.edu\".  We do\n\
not have the resources to provide commercial-quality support,\n\
but we may be able to help you.\n\
\n\
End of license.\n\
\n\
===========================================================================\n\
" ;
*/
}

/************************************************************/
/* ReportManager */
/************************************************************/

ReportManager::ReportManager()
{
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
}

void ReportManager::PrintFormattedTime(double seconds) {
	//out.precision(0);
	
	unsigned int h = ((unsigned long long)seconds) / 3600; 
	unsigned int m = ((unsigned long long)(seconds-h*3600)) / 60; 
	double s = (seconds-h*3600-m*60); 
	//unsigned int f = ((unsigned long long)(seconds-h*3600-m*60)); 
	
	cout << h << ":" << m << ":" << s;

	//cout.precision(2);
}

void ReportManager::print_algorithm()
{
  switch(Algorithm->Phase()) {
	  case 1:
	  cout << "* State Space Expansion Algorithm: ";
	  switch( args->main_alg.mode ) {
		case argmain_alg::Explore_bfs:
		  cout << "breadth first search.\n";
		  break;
		case argmain_alg::Explore_dfs:
		  cout << "depth first search.\n";
		  break;
		case argmain_alg::Simulate:
		  cout << "simulation.\n";
		  break;
		default:
		  cout << "none.\n";
		  break;
	  }

	  if (  args->symmetry_reduction.value && (  args->main_alg.mode == argmain_alg::Explore_dfs || args->main_alg.mode == argmain_alg::Explore_bfs)) {
		  cout << "  with symmetry algorithm ";
		  switch(args->sym_alg.mode) {
			case argsym_alg::Exhaustive_Fast_Canonicalize:
				cout << "1 -- Exhaustive Fast Canonicalization.\n"; break;
			case argsym_alg::Heuristic_Fast_Canonicalize:
				cout << "2 -- Heuristic Fast Canonicalization.\n"; break;
			case argsym_alg::Heuristic_Small_Mem_Canonicalize:
				if (args->perm_limit.value ==0) { 
					cout << "3 -- Heuristic Small Memory Canonicalization.\n"; break; 
				} else { cout << "3 -- Heuristic Small Memory Normalization\n"
						   << "  with permutation trial limit "
						   << args->perm_limit.value << ".\n"; break; 
				}
			case argsym_alg::Heuristic_Fast_Normalize:
				cout << "4 -- Heuristic Small Memory/Fast Normalization.\n"; break;
			default:
				cout << "??.\n"; break;
		  }
	  }
	  
	  cout << "* Maximum size of the state space: "  << StateSet->Capacity() << " states.\n";
#ifdef HASHC
	  cout << "  with states hash-compressed to "  << args->num_bits.value << " bits.\n\n";
#endif
	  break;
	  case 2:
		cout << "* Transition Graph mode: " << StateGraph->ModeLabel();
		cout << "\n* Maximum size of graph: " << StateGraph->MaxElts() << " transitions";
		cout << ".\n\n";
		break;
	  case 3:
		cout << "* Search Algorithm: ";
		switch(args->search_alg.mode) {
			case argsearch_alg::Universal_Optimal: cout << "Universal Optimal Plan"; break;
			case argsearch_alg::Universal: cout << "Universal Plan"; break;
			case argsearch_alg::Optimal: cout << "Optimal Plan"; break;
			case argsearch_alg::Feasible: cout << "Feasible Plan"; break;
		}
		if (metric!=0) {
			cout << "\n* Optimization mode: ";
			if (metric<0) cout << "Minimize";
			if (metric>0) cout << "Maximize";
		}
	  cout << ".\n\n";
	  break;
	  
	  case 5:
		cout << "* Output format: ";
		switch(args->output_fmt.mode) {
			case argoutput_fmt::Raw: cout << "Binary"; break;
			case argoutput_fmt::Text: cout << "Text"; break;
			case argoutput_fmt::Text_Verbose: cout << "Verbose Text"; break;
#ifdef OBDD_COMPRESSION
			case argoutput_fmt::OBDD: cout << "OBDD Compressed Binary"; break;
#endif			
			case argoutput_fmt::PDDL: cout << "PDDL+"; break;
			case argoutput_fmt::PDDL_Verbose: cout << "Verbose PDDL+"; break;
			case argoutput_fmt::PDDL_VeryVerbose: cout << "Very Verbose PDDL+"; break;
			case argoutput_fmt::CSV: cout << "Comma separated values"; break;
		}
		cout << "\n* Output target: ";
		if (*(args->output_file.value) != 0) cout << "\"" << args->output_file.value << "\"";
		else cout << "stdout";
		cout << ".\n\n";
	  break;
		
  }
}

// added by Uli
void ReportManager::print_warning()
{
  if ((args->main_alg.mode==argmain_alg::Explore_bfs ||
       args->main_alg.mode==argmain_alg::Explore_dfs) &&
      !args->print_trace.value)
    cout << "\nWarning: No trace will not be printed "
         << "in the case of protocol errors!\n"
         << "         Check the options if you want to have error traces.\n";
}

void ReportManager::CheckConsistentVersion()
{
  if (strcmp(MURPHI_VERSION, INCLUDE_FILE_VERSION) !=0 )
    {
      cout << "\nWarning: Different versions of include files and mu are used\n";
    }
}

void ReportManager::StartSimulation()
{
  cout << "Start Simulation :\n\n";
}

/****************************************
  Printing functions.

  Coordinated by class ReportManager
  ****************************************/

/************************************************************/
void ReportManager::print_header( void )   // changes by Uli
{
  cout << "\n======================================================\n";
  cout << "\nModel: " << PROTOCOL_NAME << "\n";
  
   cout << "* the state size is " << BITS_IN_WORLD << " bits "
	    << "(rounded up to " << BLOCKS_IN_WORLD << " bytes).\n";
		
  cout << "\n======================================================\n";

}


// since we may use symmetry, which permute entries in the state,
// the pointer in the state set doesn`t exactly point to its
// parent, but to a permutation of its parent.
//
// therefore we have to regenerate the trace from the rules used to
// generate the states

/************************************************************/
/* Norris: to be moved to state set */
void ReportManager::print_trace_with_theworld()   // changes by Uli
{
#ifdef HASHC
  if ( args->main_alg.mode == argmain_alg::Explore_bfs &&
       !args->trace_file.value )
      return;
  if (args->trace_file.value)
    StateSet->print_trace_aux(NumCurState);
  else
#endif
    StateSet->print_trace_aux(curstate);

  // execute the last rule to call
  // Error_handler::Error(...) again, so that
  // variable "theworld" will have the fragment of the last state.
  //StateCopy(workingstate, curstate);
  (void) Rules->AllNextStates();
  Error.Notrace("Internal: The error assertion associated with the last state disappeared.");
}

/************************************************************/
/* Norris: to be moved to state set */
void ReportManager::print_trace_with_curstate()   // changes by Uli
{
#ifdef HASHC
  if ( args->main_alg.mode == argmain_alg::Explore_bfs &&
       !args->trace_file.value )
      return;
  if (args->trace_file.value)
    StateSet->print_trace(NumCurState);
  else
#endif
    StateSet->print_trace(curstate);
}

/************************************************************/
void ReportManager::print_progress( void )
{
  unsigned long  transitions=0;
  unsigned long  controlled=0;
  unsigned long  plans=0;
  cout.precision(2);
  switch (Algorithm->Phase()) {
	case 1:
		if (args->print_progress.value && StateSet->NumElts() % args->progress_count.value == 0 )	{			
			cout << "[";
			PrintFormattedTime(SecondsSinceStart());
			cout << "] "
				 << "states explored: " << StateSet->NumElts() << ", "
				 << "rules fired: " << Rules->NumRulesFired()
				 << "\n  BFS level: "<< StateSet->CurrentLevel() << ", "
				 << "states queued: " << StateSet->QueueNumElts() << ", "  			     
				 << "goals found: "<<StateSet->NumGoals()  << ", "
				 << "errors: "<<StateSet->NumErrors() 
				 << "\n  " << ((double)StateSet->NumElts()/(double)SecondsSinceStart()) << " states/sec" << ", "
				 << ((double)Rules->NumRulesFired()/(double)SecondsSinceStart()) << " rules/sec" << ", "
				 //valida solo con il MemGraphManager!
				 << ((double)StateSet->NumElts()/(double)StateSet->MaxElts()*100) << "% memory used\n";				 
		}
		break;
	case 2:
		transitions = StateGraph->OutDegreeTot();
		if (args->print_progress.value && transitions % args->progress_count.value == 0 )	{			
			cout << "[";
			PrintFormattedTime(SecondsSinceStart());
			cout << "] "
				 << transitions << " transitions generated, "
				 << ((double)StateGraph->OutDegreeTot()/(double)StateGraph->MaxElts()*100) << "% memory used\n";				 
		}
		break;
	case 3:
		controlled = Algorithm->ControlledStates();
		if (args->print_progress.value && controlled % args->progress_count.value == 0 )	{			
			cout << "[";
			PrintFormattedTime(SecondsSinceStart());
			cout << "] "
				 << controlled << " states controlled\n";
		}
		break;
	case 4:
		plans = Algorithm->NumPlans();
		if (args->print_progress.value && plans % args->progress_count.value == 0 )	{			
			cout << "[";
			PrintFormattedTime(SecondsSinceStart());
			cout << "] "
				 << plans << " plans generated\n";
		}
		break;		
  }
  cout.flush();
}
/************************************************************/
void ReportManager::print_no_error( void )
{
  cout << "\n====================================="
       << "=====================================\n"
       << "\nStatus:\n"
       << "\n\tNo error found.\n";
}

/************************************************************/
void ReportManager::print_summary(bool prob)
{
  bool exist = FALSE;

  cout << "\nState Space Explored:\n\n"
       << "\t"
       << StateSet->NumElts() << " states, "
       << Rules->NumRulesFired() << " rules fired in "
       << SecondsSinceStart() << "s.\n\t"
	   //<< num_predecessors << " predecessors saved into PT (average: " << StateSet->NumElts()*1.0/num_predecessors<< " per list), "
	   << StateSet->NumGoals() << " goal states reached. \n\n";

  if (prob) {
#ifdef HASHC
    // Uli: print omission probabilities
    StateSet->PrintProb();
#endif
  }

  Rules->print_rules_information();
  theworld.print_statistic();

}

void ReportManager::print_status()
{
  switch (Algorithm->Phase()) {
	case 1:
		cout << "\n=== Analyzing model... ===============================\n\n";
		break;
	case 2:
		cout << "\n=== Building model dynamics... =======================\n\n";
		break;
	case 3:
		cout << "\n=== Finding control paths... =========================\n\n";
		break;
	case 4:
		cout << "\n=== Collecting plans... ==============================\n\n";
		break;		
	case 5:
		cout << "\n=== Writing final results... =========================\n\n";
		break;		
	}

}

void ReportManager::print_report()
{
  switch (Algorithm->Phase()) {
  case 1:
	cout << "\n======================================================\n";
	cout << "\nModel exploration complete (in " << SecondsSinceStart() << " seconds).\n"
		 << "\t" << Rules->NumRulesFired() << " rules fired\n"
		 << "\t" << StartState->numstartstates << " start states\n"
		 << "\t" << StateSet->NumElts() << " reachable states\n"
		 << "\t" << StateSet->NumGoals() << " goals found\n\n";
		 break;
	case 2:
		cout << "\n======================================================\n";
		cout << "\nModel dynamics rebuilding complete (in " << SecondsSinceStart() << " seconds).\n"
		<< "\t" << StateGraph->NumStates() << " states\n"
		<< "\t" << StateGraph->OutDegreeTot() << " transitions\n"
		<< "\t" << "out degree: min " << StateGraph->OutDegreeMin() 
			   << " max " << StateGraph->OutDegreeMax() 
			   << " avg " << StateGraph->OutDegreeAvg() 
			   << "\n\n";
		break;	
	case 3:
		cout << "\n======================================================\n";
		cout << "\nControl paths calculation complete (in " << SecondsSinceStart() << " seconds).\n"
		<< "\t" << StateGraph->NumStates() << " states\n"
		<< "\t" << Algorithm->ControlledStates() << " controllable"
	    << "\n\n";
		break;	
	case 4:
		cout << "\n======================================================\n";
		cout << "\nPlan(s) generation complete (in " << SecondsSinceStart() << " seconds).\n"
		<< "\t" << Algorithm->NumPlans() << " plans\n"
		<< "\t" << "plan length (actions): min " << Algorithm->MinPlanLen() 
			   << " max " << Algorithm->MaxPlanLen() 
			   << " avg " << Algorithm->AvgPlanLen() 		
		<< "\n\t" << "plan duration (time): min " << Algorithm->MinPlanDuration() 
			   << " max " << Algorithm->MaxPlanDuration() 
			   << " avg " << Algorithm->AvgPlanDuration() 		
		<< "\n\t" << "plan weight: min " << Algorithm->MinPlanWeight() 
			   << " max " << Algorithm->MaxPlanWeight() 
			   << " avg " << Algorithm->AvgPlanWeight() 		

	   << "\n\n";
		break;		
	case 5:
		cout << "\n======================================================\n";
		cout << "\nResults Written (in " << SecondsSinceStart() << " seconds).\n"
	    << "\n\n";
		break;		
	}
}


// for bfs only -- curstate valid
/************************************************************/
void ReportManager::print_curstate( void )
{
  if (StateSet->NumElts() >= args->verbose_from_state.value)
  {
  StateCopy(workingstate, curstate);
  cout << "------------------------------\n"
       << "Unpacking state from queue:\n";
  theworld.print();
  cout << "\nThe following next states are obtained:\n"
       << '\n';
  }
}

// for dfs only
/************************************************************/
void ReportManager::print_dfs_deadlock( void )
{
  cout << "------------------------------\n"
       << "No more rule can be fired.\n"
       << "------------------------------\n";
}

// for dfs only
/************************************************************/
void ReportManager::print_retrack( void )
{
  if (!StateSet->QueueIsEmpty())
    {
      //curstate = (StateSet->QueueTop()).s;
      curstate = &(StateSet->QueueTop()->s);
      StateCopy(workingstate, curstate);
      cout << "------------------------------\n";
      cout << "No more rule can be fired. Backup one state from the stack:\n";
      theworld.print();
      cout << '\n';
    }
}

/************************************************************/
void ReportManager::print_fire_startstate()
{
  cout << "Firing startstate "
       << StartState->LastStateName()
       << "\n"
       << "Obtained state:\n";
  theworld.print();
  cout << '\n';
}

/************************************************************/
void ReportManager::print_fire_rule()
{
  cout << "Firing rule "
       << Rules->LastRuleName()
       << '\n'
       << "Obtained state:\n";
  theworld.print();
  cout << '\n';
}

/************************************************************/
void ReportManager::print_fire_rule_diff(state * s)
{
  cout << "Firing rule "
       << Rules->LastRuleName()
       << '\n'
       << "Obtained state:\n";
  theworld.print_diff(s);
  cout << '\n';
}

/************************************************************/
void ReportManager::print_trace_all()
{
  static unsigned long statenum = 1;
  cout << "State " << statenum++ << ":\n";
  theworld.print();
  cout << '\n';
}

/************************************************************/
void ReportManager::print_verbose_header()
{
  cout << "\n====================================="
       << "=====================================\n";
  if (args->verbose_from_state.value)
    cout << "Verbose controlled option selected.  The following is the detailed progress.\n\n";
  else
    cout << "Verbose option selected.  The following is the detailed progress.\n\n";
}

/************************************************************/
void ReportManager::print_hashtable()
{
  StateSet->print_all_states();
}

/************************************************************/
void ReportManager::print_final_report()
{
  print_no_error();
  print_summary(TRUE);
  if (args->print_hash.value) print_hashtable();
}


/****************************************   // added by Uli
  trace info file
  ****************************************/

#ifdef HASHC
TraceFileManager::TraceFileManager(char* s)
: inBuf(0), last(0)
{
  assert (sizeof(unsigned long)==4);   // the implementation is pretty
                                       // dependent on the 4 bytes

  // check directory
  if (strlen(s)==0)
    Error.Notrace("No directory for trace info file specified.");
  if (strlen(s)+strlen(PROTOCOL_NAME)+strlen(TRACE_FILE) > 254)
    Error.Notrace("Filename for trace info file too long.");

  // set filename
  strcpy(name,s);
  if (name[strlen(name)-1] != '/')
    strcat(name,"/");
  strcat(name,PROTOCOL_NAME);
  strcat(name,TRACE_FILE);

  // open file
  if ((fp = fopen(name,"w+b")) == NULL)
    Error.Notrace("Problems opening trace info file %s.", name);
}

TraceFileManager::~TraceFileManager()
{
  // delete file
  remove(name);
}

void TraceFileManager::setBytes(int bits)
{
  numBytes = (bits-1)/8 + 1;
}

unsigned long TraceFileManager::numLast()
{
  return last;
}

// routines for reading and writing
// remarks:
// - format: 4 bytes   for the number of the previous state
//           numBytes  for the compressed value
// - states are numbered beginning with 1

void TraceFileManager::writeLong(unsigned long l, int bytes)
{
  for (int i=0; i<bytes; i++)
    if (fputc(int(l>>(3-i)*8 & 0xffUL), fp) == EOF)
      Error.Notrace("Problems writing to trace info file %s.", name);
}

void TraceFileManager::write(unsigned long c1, unsigned long c2,
                        unsigned long previous)
{
  writeLong(previous, 4);
  writeLong(c1, numBytes>4 ? 4 : numBytes);
  if (numBytes>4)
    writeLong(c2, numBytes-4);
  last++;
}

unsigned long TraceFileManager::readLong(int bytes)
{
  unsigned long ret=0;
  int g;

  for (int i=0; i<bytes; i++)
    if ((g=fgetc(fp)) == EOF)
      Error.Notrace("Problems reading from trace info file %s.", name);
    else
      ret |= ((unsigned long)g & 0xffUL) << (3-i)*8;

  return ret;
}

const TraceFileManager::Buffer* TraceFileManager::read(unsigned long number)
{
  if (number!=inBuf)
  {
    if (fseek(fp, (number-1)*(4+numBytes), SEEK_SET))
      Error.Notrace("Problems during seek in trace info file %s.", name);

    buf.previous = readLong(4);
    buf.c1 = readLong(numBytes>4 ? 4 : numBytes);
    if (numBytes>4)
      buf.c2 = readLong(numBytes-4);

    inBuf = number;
  }

  return &buf;
}
#endif


/****************************************
  * 1 Dec 93 Norris Ip:
  add -sym option to select symmetry reduction
  * 8 Feb 94 Norris Ip:
  add print hashtable for debugging
  * 8 March 94 Norris Ip:
  merge with the latest rel2.6
  * 6 April 94 Norris Ip:
  fixed error trace
  * 12 April 94 Norris Ip:
  add information about error in the condition of the rules
  category = CONDITION
  * 14 April 94 Norris Ip:
  change numbering of symmetry algorithms
  * 14 April 94 Norris Ip:
  change io so that numbers are checked to be really number
  * 14 April 94 Norris Ip:
  change io so that sym is default
  added -nosym flag
  * 18 April 94 Norris Ip:
  error trace printing fixed (internal error when invariant failed)
  * 20 Oct 94
  Tidy up and Objectized the code
****************************************/

/********************
  $Log: mu_io.C,v $
  Revision 1.3  1999/01/29 08:28:09  uli
  efficiency improvements for security protocols

  Revision 1.2  1999/01/29 07:49:10  uli
  bugfixes

  Revision 1.4  1996/08/07 18:54:33  ip
  last bug fix on NextRule/SetNextEnabledRule has a bug; fixed this turn

  Revision 1.3  1996/08/07 01:00:18  ip
  Fixed bug on what_rule setting during guard evaluation; otherwise, bad diagnoistic message on undefine error on guard

  Revision 1.2  1996/08/07 00:15:26  ip
  fixed while code generation bug

  Revision 1.1  1996/08/07 00:14:46  ip
  Initial revision

********************/
