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
  header that depend on constants
  which is generated in the middle of the compiled program:
  RULES_IN_WORLD
  ****************************************/
#include "upm_util_dep.hpp"

/****************************************
  supporting routines
  ****************************************/
#ifdef HASHC
#include "upm_hash.cpp"
#endif

#include "upm_util.cpp"
#include "upm_io.cpp"
#include "upm_sym.cpp"
#include "upm_state.cpp"
#include "upm_graph.cpp"
#include "upm_storage.cpp"
#include "upm_system.cpp"

/****************************************
  real numbers extension
  ****************************************/
#include "upm_real.cpp"	//im

#ifdef OBDD_COMPRESSION
/****************************************
  OBDD compressor extension
  ****************************************/
#include "upm_OBDD.cpp"
#endif

/****************************************
  main routines
  ****************************************/

#include "upm_verifier.cpp"
