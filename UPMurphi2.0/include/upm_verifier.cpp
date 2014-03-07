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
  The Main() function:
  int main(int argc, char **argv)
  Note that Global Variables are in control.h
  ****************************************/

 //UPMURPHI_BEGIN
int main(int argc, char **argv)
{
  args = new argclass(argc, argv);
MEMTRACKALLOC 
  Stats = new StatsManager();
  Storage = new StorageManager();
MEMTRACKALLOC 
  Algorithm = new AlgorithmManager();
MEMTRACKALLOC

  
  if (args->main_alg.mode != argmain_alg::Nothing) Algorithm->Plan();

  cout.flush();
#ifdef HASHC
  if (args->trace_file.value)
    delete TraceFile;
#endif
  delete Algorithm; //gdp: fix: begin destruction chain
  delete Stats;
  delete Storage;

  /*---------*/
  exit(0);
}
//UPMURPHI_END

/****************************************
  * 8 Feb 94 Norris Ip:
  add print hashtable for debugging
  * 24 Feb 94 Norris Ip:
  added -debugsym option to run two hash tables in parallel
  for debugging purpose
  * 8 March 94 Norris Ip:
  merge with the latest rel2.6
  * 12 April 94 Norris Ip:
  add information about error in the condition of the rules
  category = CONDITION
  * 14 April 94 Norris Ip:
  fixed simlution mode printing when -h is used
  * 14 April 94 Norris Ip:
  change numbering of symmetry algorithms
  * 14 April 94 Norris Ip:
  fixed the number of digit in time output
****************************************/

/********************
  $Log: mu_verifier.C,v $

  Revision 2.0  2003/01/07 14:31:42  giuseppe
  added a call to delete in main() to delete Algorithm object

  Revision 1.2  1999/01/29 07:49:11  uli
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
