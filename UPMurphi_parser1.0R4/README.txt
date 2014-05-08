[HOW TO USE THE PARSER]

1) create your pddl file <filename.pddl> containing both the PDDL+ domain and problem description
2) execute ./parser <filename.pddl> to start the parsing
3) you can recompile the pddl2upmurphi by typing ./src/compile
4) PDDL_domains folder contains some example of pddl domains

[detailed instructions to use UPMurphi from a PDDL+ file]

1) create your pddl file <filename.pddl> containing both the PDDL+ domain and problem description
2) move <filename.pddl> to UPMurphi2.0/ex directory
2bis) eventually  copy the <parser> executable into the UPMurphi2.0/ex directory
3) type "./parser <filename.pddl>"
4) please answer to parser questions carefully. 
   a) insert the time discretisation quantum properly (e.g., if a durative action has a duration like "?t = 10" then the discretisation quantum should be a multiple of 10. In such a case, you can decide to replace the durative action condition from = to <=)
   b) insert the number of digits to use for rounding real values.
   c) PDDL+ functions are used to describe costant numeric values as well as fluents. In order to minimise the UPMurphi state encoding you should specify either a function can be considered as constant or fluent. (e.g., Do you want to use function a_rate as a constant value? Y/N or A for " no to all ").  
   d) a file named <filename.m> will be created containing the UPMurphi model generated from the PDDL
   e) a file named <filename.h> will be created containing the external functions used by UPMurphi.
5) now compile che UPMurphi .m model into c++ code by typing "./compile_model.sh <filename> (without .m extension)
   a) Note: UPMurphi has been developed and tested to work under 32bit architecture. Then, the compile_model.sh contains the -m32 flag to always generate a 32bit code (also under x64 machines). However, you can try to use it by removing -m32 and -c flags from <compile_model.sh>  (-c flag enables the "hash compaction" technique which cannot work on x64 arch).
6) Now you have a <filename> executable. Launch it as "<filename> -h" for a list of parameters, e.g. "<filename> -search:f -format:pddl -m500" looks for a single feasible plan using at most 500MB of RAM and generating the PDDL+ plan (if any)."


[FAST PROCEDURE FROM THE PDDL+ DOMAIN]

1) move to UPMurphi2.0/ex directory
2) type "./pddl_and_go.sh <filename>" (without .pddl extension)
3) follow the istructions and wait for a plan (if any)


--------------------------------------------------------------------------


UPMurphi PDDL+ Compiler Release 1.0R3
 Copyright (C) 2010 G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio
 Parts of this software are derived from the VAL PDDL+ validator
 developed by D. Long, R. Howey, S. Cresswell and M. Fox

UPMurphiParser is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation; either of the License, or
(at your option) any later version.

UPMurphiParser is currently in BETA, and is distributed in the hope that
it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of  MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE. See the GNU Lesser General Public License for more details.

Part of the UPMurphiParser is derived from from the VAL PDDL+ validator
 developed by D. Long, R. Howey, S. Cresswell and M. Fox.

If you need help or have comments or suggestions regarding the parser,
please send electronic mail to "fabio.mercorio@univaq.it".  We do
not have the resources to provide commercial-quality support, but we
may be able to help you.


