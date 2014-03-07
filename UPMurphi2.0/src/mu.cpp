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
#include <string.h>
#include <new>
#include <cstdlib>
#include <sys/stat.h>
using namespace std;

/********************
  variable declarations
  ********************/
program *theprog = NULL;
symboltable *symtab = NULL;
FILE *codefile;
char *app_path; //for invoking gcc

/********************
  class argclass
  ********************/
bool Sw(char *a, int ac, char **av)
{
  for (int i = 1; i < ac; i++)
    if (strcmp(av[i], a) == 0)
      return TRUE;
  return FALSE;
}

argclass::argclass(int ac, char **av)
:  
argc(ac), argv(av), print_license(FALSE), help(FALSE), checking(TRUE),
no_compression(TRUE), hash_compression(FALSE), UPMurphi_planner (FALSE), UPMurphi_disk(FALSE),
variable_weight(FALSE),variable_duration(FALSE),
keep_source(TRUE),compile_source(FALSE),force_recompile(FALSE)
{
  bool initialized_filename = FALSE;
  int i;

  if (ac == 1) {		// if there is no argument, print help
    help = TRUE;
    PrintInfo();
    exit(1);
  }
  for (i = 1; i < ac; i++) {
    if (strcmp(av[i], "-l") == 0) {
      print_license = TRUE;
      continue;
    }
    if (strcmp(av[i], "-b") == 0) {
      no_compression = FALSE;
      continue;
    }
    if (strcmp(av[i], "-c") == 0) {
      hash_compression = TRUE;
      continue;
    }

//UPMURPHI_BEGIN
    if (strcmp(av[i], "--planner") == 0) {
      UPMurphi_planner = TRUE;
      continue;
    }
	
    if (strcmp(av[i], "--disk") == 0) {
      UPMurphi_disk = TRUE;
      continue;
    }
	
	if (strcmp(av[i], "--clean") == 0) {
      keep_source = FALSE;
      continue;
    }
	
	 if (strcmp(av[i], "--compile") == 0) {
      compile_source = TRUE;
      continue;
    }
	
	 if (strcmp(av[i], "--force") == 0) {
      force_recompile = TRUE;
      continue;
    }
	
	if (strcmp(av[i], "--varweight") == 0) {
      variable_weight = TRUE;
      continue;
    }
	
	if (strcmp(av[i], "--varduration") == 0) {
      variable_duration = TRUE;
      continue;
    }
	
	
//UPMURPHI_END
    if (strcmp(av[i], "-h") == 0) {
      help = TRUE;
      PrintInfo();
      exit(1);
    }
//       if ( strncmp(av[i], "-sym", strlen("-sym") ) == 0 )
//       {
//        // we should change it to check whether the number after prefix
//        // is really a number
//         if ( strlen(av[i]) <= strlen("-sym") ) /* We have a space before the number,
//                                     * so it\'s in the next argument. */
//           sscanf( av[++i], "%d", &symmetry_algorithm_number);
//         else
//           sscanf( av[i] + strlen("-sym"), "%d", &symmetry_algorithm_number);
//         continue;
//       }

    if (av[i][0] != '-' && !initialized_filename) {
      initialized_filename = TRUE;
      filename = av[i];
      continue;
    } else if (av[i][0] != '-' && initialized_filename) {
      fprintf(stderr, "Duplicated input filename.\n");
      exit(1);
    }
    fprintf(stderr,
	    "Unrecognized flag. Do '%s -h' for a list of valid arguments.\n",
	    av[0]);
    exit(1);
  }

  if (!initialized_filename) {	// print help
    help = TRUE;
    PrintInfo();
    exit(0);
  }
  
  if (!keep_source && !compile_source) {
	keep_source=TRUE;
	fprintf(stderr,"Warning: --clean without --compile has no effect.\n");
  }

  PrintInfo();
}

void argclass::PrintInfo(void)
{
  if (print_license)
    PrintLicense();

  if (!print_license) {
    printf("Call with the -l flag or read the license file for terms\n");
    printf("and conditions of use.\n");
  }

  if (!help)
    printf("Run this program with \"-h\" for the list of options.\n");

  printf("Bugs, questions, and comments should be directed to\n");
  printf("\"giuseppe.dellapenna@univaq.it\".\n\n");

  printf("UPMurphi compiler last compiled date: %s\n", __DATE__);
  printf("\
===========================================================================\n");

  if (help)
    PrintOptions();
  fflush(stdout);
}

void argclass::PrintOptions(void)
{
  printf("The options are shown as follows:\n\
\n\
\t-h          \t\t   \thelp\n\
\t-l          \t\t   \tprint license\n\
\t-b          \t\t   \tuse bit-compacted states\n\
\t-c          \t\t   \tuse hash compaction\n\
\t--varweight      \t\t   \tsupport state-dependant rule weight\n\
\t--varduration      \t\t   \tsupport state-dependant rule duration\n\
\t--force      \t\t   \tskip timestamp checks (force recompilation)\n\
\n\
An argument without a leading '-' is taken to be the input filename,\n\
\twhich must end with '.m'\n\
");
//\t--clean      \t\t   \tremove source (.cpp) file after compilation n\
//\t--compile      \t\t   \tcompile executable planner\n\
// \t-sym <num> \t\tsymmetry reduction algorithm <num>\n
}

void argclass::PrintLicense(void)
{
  printf("License Notice: \n\n");

  printf("UPMurphi is free software; you can redistribute it and/or modify it\n\
under the terms of the GNU Lesser General Public License as\n\
published by the Free Software Foundation; either of the License, or\n\
(at your option) any later version.\n\
\n\
UPMurphi is currently in BETA, and is distributed in the hope that\n\
it will be useful, but WITHOUT ANY WARRANTY; without even the\n\
implied warranty of  MERCHANTABILITY or FITNESS FOR A PARTICULAR\n\
PURPOSE. See the GNU Lesser General Public License for more details.\n\
\n\
You should have received a copy of the GNU Lesser General Public\n\
License along with this library; if not, write to the Free Software\n\
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307\n\
USA.\n\
\n\
The UPMurphi modelling language and state space exploration\n\
algorithm are derived from the CMurphi model checker, which in turn\n\
is derived from the Murphi model checker by Stanford. The planning\n\
algorithms have been developed at the University of L'Aquila, Italy.\n\
\n\
To contact the UPMurphi development team, email to\n\
<giuseppe.dellapenna@univaq.it>\n\
\n\
===========================================================================\n\
");

  fflush(stdout);
}

/********************
  variable declarations
  ********************/
argclass *args;


/********************
  void err_new_handler()
  ********************/
void err_new_handler()
{
  Error.FatalError("Unable to allocate enough memory.");
}

/********************
  void init_globals()
  -- initialize all global variables
  ********************/
void init_globals()
{
  set_new_handler(&err_new_handler);
  booltype = new enumtypedecl(0, 1);
  booltype->declared = TRUE;
  booltype->mu_name = tsprintf("mu_0_boolean");
  inttype = new enumtypedecl(0, 10000);
  inttype->declared = TRUE;
  realtype = new realtypedecl(6, 2);
  realtype->declared = TRUE;

  /* An enum, not a subrange, because an integer is a primitive type. */
  /* The upper bound doesn\'t really matter; it doesn\'t get used. MAXINT
   * seems like a logical value, but that causes an overflow in the
   * arithmetic used to calculate the number of bits it requires. I\'ve
   * chosen a value that shouldn\'t create any problems, even with small
   * ints. */
  errortype = new errortypedecl((char *) "ERROR");
  voidtype = new typedecl((char *) "VOID_TYPE");
  errorparam = new param(errortype);
  errordecl = new error_decl((char *) "ERROR_DECL");
  error_expr = new expr(0, errortype);
  true_expr = new expr(TRUE, booltype);
  false_expr = new expr(FALSE, booltype);
  error_designator = new designator(NULL, errortype, FALSE, FALSE, FALSE);
  nullstmt = new stmt;
  error_rule = new simplerule(NULL, NULL, NULL, NULL, 0, simplerule::Other, NULL, NULL);
  symtab = new symboltable;
  theprog = new program;
  typedecl::origin = NULL;
}

int check_infile()
{
  char *filename = args->filename;
  /* pre-checking on filename. */
  int len = strlen(filename);
  if (filename[len - 2] != '.' || filename[len - 1] != 'm') {
    Error.FatalError("Model files must end with \".m\"");
	return 1;
  }
  return 0;
}

/********************
  void setup_infile(char *filename)
  -- setup input file handler
  ********************/
void setup_infile()
{
  char *filename = args->filename;
  gFileName = filename;
  yyin = fopen(filename, "r");	// yyin is flex\'s global for the input file
  if (yyin == NULL) {
    Error.FatalError("%s:No such file or directory.", filename);
  }
}

char *get_infilename() {
	
	return args->filename;
}

char *get_outfilename() {
	
	static char outfilename[1024];
	int len = strlen(args->filename);
	
	if (Error.CondError(len >= 1021, "Model file name %s must have at most 1021 characters", args->filename))
		exit(10);
	strcpy(outfilename, args->filename);
	strcpy(outfilename+(len-1),"cpp");  
	
	return outfilename;
}

char *get_execfilename() {
	
	static char execfilename[1024];
	int len = strlen(args->filename);
	
	if (Error.CondError(len >= 1021, "Model file name %s must have at most 1021 characters", args->filename))
		exit(10);
	strcpy(execfilename, args->filename);
	execfilename[len-2]='\0';
	
	return execfilename;
}

FILE *setup_outfile()
{
  
  FILE *outfile;
  char *outfilename = get_outfilename();

  outfile = fopen(outfilename, "w");
  if (outfile == NULL) {
    Error.FatalError("Unable to open/create %s", outfilename);
  };
  return outfile;
}


/********************
  various print routines  
  ********************/
void print_header()
{
 printf ("\n\
===========================================================================\n");

  printf ("%s\nOptimal Universal Planner for Finite-state Systems.\n\n", MURPHI_VERSION);
  printf
    ("%s :\nCopyright (C) 2007 - 2010: G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio.\n",
     MURPHI_VERSION);
  printf ("%s is based on CMurphi release 5.4.\n\n", MURPHI_VERSION);
  
  printf
    ("CMurphi Release 5.4 :\nCopyright (C) 2001 - 2003 by E. Tronci, G. Della Penna, B. Intrigila, I. Melatti, M. Zilli.");
  printf ("\nCMurphi Release 5.4 is based on Murphi release 3.1.\n\n");	
  printf
      ("Murphi Release 3.1 :\nCopyright (C) 1992 - 1999 by the Board of Trustees of\nLeland Stanford Junior University.\n\n");
  printf("===========================================================================\n");
}


//#ifndef COMPILER
#define COMPILER_NAME "g++"
//#endif

//#ifdef STDDEFINES
#define COMPILER_DEFINES "-DNO_RUN_TIME_CHECKING -DCATCH_DIV -DSYSCONF_RDCL"
//#endif


time_t get_last_modified(char *filename) 
{
	struct stat s;
	if (stat(filename,&s)) return 0;
	return s.st_mtime;
}

int compile_model() {
		
	if (!args->force_recompile && (get_last_modified(get_infilename())<=get_last_modified(get_outfilename()))) {
		printf("C++ source code is up to date\n");
		return 0;
	} else {
		setup_infile();
		printf("Compiling model...\n");
		int error = yyparse();
		if (!error && Error.getnumerrors() == 0) {
			codefile = setup_outfile();
			theprog->generate_code();
			fclose(codefile);
			printf("Model compilation successful, no errors\n");
			if (args->keep_source) printf("C++ source code generated in file %s\n", get_outfilename());
			return error+Error.getnumerrors();
		}
	}
}	

int compile_planner() {
	char *outfilename = get_outfilename();
	char *upmurphi_home = getenv("UPMURPHI_HOME");
	char base_installation_path[1024];
	char commandline[2048];	
	
	if (!args->force_recompile && (get_last_modified(get_infilename())<=get_last_modified(get_execfilename()))) {
			printf("Executable planner is up to date\n");
			return 0;
	} else {		
		if (!upmurphi_home) {
			//if (!app_path || app_path[0]==0) {
				base_installation_path[0]='\0';
				printf("Warning: UPMURPHI_HOME environment variable not set\n"); 
			//} else {
			//	printf("%s",app_path); exit(3);
			//}
		} else {
			strcpy(base_installation_path,upmurphi_home);
			if (upmurphi_home[strlen(upmurphi_home)-1]!='/') strcat(base_installation_path,"/");
		}		
		printf("Compiling executable planner, please wait...\n");
		sprintf(commandline,"%s %s %s -I%sinclude -Wno-deprecated -o %s",COMPILER_NAME,COMPILER_DEFINES,get_outfilename(),base_installation_path,get_execfilename());
		int error = system(commandline);
		if (!error) {
			printf("Planner compilation successful, no errors\n");
			printf("Executable planner generated in file %s\n", get_execfilename());
		} else fprintf(stderr,"Executed command line: %s\n",commandline); 
		return error;
	}
}

/********************
  main routines
  ********************/
int main(int argc, char *argv[])
{
  int error;
  args = new argclass(argc, argv);
  init_globals();
  print_header();
  check_infile();
  error = compile_model();
  if (!error) {    
	if (args->compile_source) {
		error = compile_planner();
		if (error) exit(2);
		if (!args->keep_source) remove(get_outfilename());
	}
    exit(0);
  } else {
    exit(1);
  }
}

