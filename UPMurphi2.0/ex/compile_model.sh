#!/bin/bash
../src/upmc -b -c $1.m 
g++ -ggdb -m32 -Wno-unused-result -Wno-write-strings -Wno-deprecated  -O0  -g3 -DNO_RUN_TIME_CHECKING -DCATCH_DIV -DSYSCONF_RDCL  $1.cpp -I../include -o $1
