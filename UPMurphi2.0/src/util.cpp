/*
* Universal Planner CGMurphi Release 2.0.b1
* Copyright (C) 2007 - 2010: G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio
*
* Read the file "license" distributed with these sources, or call
* UPMurphi with the -l switch for additional information.
* Current release developed by G. Della Penna (giuseppe.dellapenna@univaq.it)
*
*/

#include "mu.hpp"
#include <stdarg.h>

/********************
  variable declaration
  ********************/
TNode *error = new TNode;

/********************
  int CeilLog2( int n )
  -- Number of bits needed to represent a type with n distinct values.
  ********************/
int CeilLog2(int n)
{
  /* Except 0 maps to 1. */// now fixed. 
  /* taken from Andreas Drexler's code. */
  /* This is the number of bits required to represent `n' different numbers. */
  int retval, i = 0;
  Error.CondError(n < 0, "Internal:NumBits: Negative number.");
  if (n == 0 || n == 1) {
    retval = 0;			// Changed from 1.
  } else {
    n--;
    while (n > 0) {
      i++;
      n >>= 1;
    }
    retval = i;
  }
  return retval;
}

/********************
  char *tsprintf (const char *fmt, ...)
  -- sprintf's the arguments into dynamically allocated memory.  Returns the
  -- dynamically allocated string. 
  ********************/
char *tsprintf(const char *fmt, ...)
{
  static char temp_buffer[BUFFER_SIZE];	// hope that\'s enough.
  va_list argp;
  char *retval;

  va_start(argp, fmt);
  vsprintf(temp_buffer, fmt, argp);
  va_end(argp);

  if (strlen(temp_buffer) >= BUFFER_SIZE)
    Error.Error("Temporary buffer overflow.\n\
Please increase the constant BUFFER_SIZE in file mu.h and recompile Murphi\n\
(you may also reduce the length of expression by using function call.");

  retval = new char[strlen(temp_buffer) + 1];	// + 1 for the \0.
  strcpy(retval, temp_buffer);
  return (retval);
}

/********************
  int new_int()
  -- generate a new integer
  ********************/
int new_int()
{
  static int n = 0;
  return n++;
}

