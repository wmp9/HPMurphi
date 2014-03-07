#!/bin/bash
../src/upmc -b -c $1.m 
g++ -Wno-unused-result -Wno-write-strings -Wno-deprecated  -O4 -DOBDD_COMPRESSION -DNO_RUN_TIME_CHECKING -DCATCH_DIV -DSYSCONF_RDCL  $1.cpp ../cudd/cudd/libcudd.a ../cudd/dddmp/libdddmp.a ../cudd/mtr/libmtr.a ../cudd/util/libutil.a ../cudd/epd/libepd.a ../cudd/st/libst.a -I../include -I../cudd/include -Wno-deprecated -o $1
