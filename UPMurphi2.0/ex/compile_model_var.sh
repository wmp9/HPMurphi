#!/bin/bash
../src/upmc -b -c --varweight --varduration $1.m 
g++ -m32 -Wno-write-strings -Wno-deprecated  -O4 -DCATCH_DIV -DSYSCONF_RDCL  $1.cpp -I../include -o $1
