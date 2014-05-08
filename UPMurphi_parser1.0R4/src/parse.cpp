/*
 main() for the PDDL2.2 parser

 $Date: 2001/08/02 16:44:19 $
 $Revision: 3.2 $

 This expects any number of filenames as arguments, although
 it probably doesn't ever make sense to supply more than two.

 stephen.cresswell@cis.strath.ac.uk

 Strathclyde Planning Group
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include "ptree.h"
#include "FlexLexer.h"

extern int yyparse();
extern int yydebug;
using std::ifstream;
using std::ofstream;
using namespace std;

namespace PDDL2UPMurphi_parser {

parse_category* top_thing = NULL;
analysis an_analysis;
analysis* current_analysis;
bool state_creation_assistent;
bool goal_printing;
bool make_ground_parameters_now;
bool mod_external_func;
string mantissa = "5";
string exponent = "8";
string precision;
string time_quantum;
ofstream ext_func_stream;
vector<external_effect_> external_effects;
external_effect_ actual_external_effect;
yyFlexLexer* yfl;
string ext_func_filename;
string operator_in_parsing;
string action_in_parsing;
string action_in_parsing_without_pars;

}
;

char * current_filename;

using namespace PDDL2UPMurphi_parser;

void print_usage() {
	cout << "\n\n Usage: parser input_file.pddl. The file must contain both pddl domain and problem description \n";
}

string simplify(string s) {
	string toReturn;
	string tosearch1 = "& (true)";
	string tosearch2 = "& true";
	size_t pos;
	while (((pos = s.find(tosearch1)) != string::npos)) {
		s.replace(pos, tosearch1.length(), "");
	}
	while (((pos = s.find(tosearch2)) != string::npos)) {
		s.replace(pos, tosearch2.length(), "");
	}
	return s;
}

void check_syntax() {
	string cont;
	if (current_analysis->error_list.errors_number() != 0
			|| current_analysis->error_list.warnings_number() != 0) {
		cout << "Your model has "
				<< current_analysis->error_list.errors_number()
				<< " errors and "
				<< current_analysis->error_list.warnings_number()
				<< " warning.\n Are you sure you want to proceed? (Y\\N)\n";
		cin >> cont;
		if (cont == "N" || cont == "n") {
			exit(-1);
		}
	}
}

void preanalisys(ofstream& outstream, ofstream& ext_func_stream,
		char* current_filename) {

	check_syntax();
	cout << "\n\n UPMURPHI PARSER STARTING \n\n";
	//cout << "Insert PDDL+ output file name (including path)\n";
	string filename = current_filename;
	ext_func_filename = current_filename;
	if (filename.find(".pddl") != string::npos) {
		filename = filename.replace(filename.find(".pddl"), 5, ".m");
		ext_func_filename = ext_func_filename.replace(ext_func_filename.find(
				".pddl"), 5, ".h");
	} else {
		filename += ".m";
		ext_func_filename += ".h";
	}
	outstream.open(filename.c_str());
	if (!outstream.is_open()) {
		log_error(E_FATAL, "Failed to create output file\n");
		exit(-1);
	}
	ext_func_stream.open(ext_func_filename.c_str());
	if (!ext_func_stream.is_open()) {
		log_error(E_FATAL, "Failed to create external functions file\n");
		exit(-1);
	} else {
		ext_func_stream
				<< "#include <cmath>\n#include <iostream>\n#include <stdlib.h>\n#include <stdio.h>\n\n"
				<< "double round_k_digits(double n, unsigned k){\n\t"
				<< "double prec = pow(0.1,k);\n\t"
				<< "double round = (n>0) ? (n+prec/2) : (n-prec/2);\n\t"
				<< "return round-fmod(round,prec);\n" << "}\n\n" << flush;
	}
	cout << "The output model will be written on file: " << filename << "\n";
	cout << "The output external function file will be written on file: "
			<< ext_func_filename << "\n";
	cout << "Insert the dicretisation quantum\n";
	cin >> time_quantum;
	cout << "Insert the number of decimal digits\n";
	cin >> precision;

	

	state_creation_assistent = true;
	goal_printing = true;
	make_ground_parameters_now = true;

}

int main(int argc, char * argv[]) {
	arguments_checker ac(argv,argc);

	current_analysis = &an_analysis;
	ifstream* current_in_stream;
	ofstream outstream;
	yydebug = 0; // Set to 1 to output yacc trace

	yfl = new yyFlexLexer;

	// Loop over given args

	current_filename = argv[1];
	cout << "File: " << current_filename << '\n';
	current_in_stream = new ifstream(current_filename);
	if (current_in_stream->bad()) {
		// Output a message now
		cout << "Failed to open\n";

		// Log an error to be reported in summary later
		line_no = 0;
		log_error(E_FATAL, "Failed to open file");
	} else {
		line_no = 1;

		// Switch the tokeniser to the current input stream
		yfl->switch_streams(current_in_stream, &cout);
		yyparse();

		// some initialisations
		precision = "1";

		current_analysis->error_list.report();
		preanalisys(outstream, ext_func_stream, current_filename);
		string to_print;
		to_print += current_analysis->toMurphi_declaration(0);
		to_print += current_analysis->the_domain->toMurphi(0);
		mod_external_func = false;
		to_print += current_analysis->the_problem->toMurphi(
				current_analysis->the_domain);
		to_print += current_analysis->the_problem->toMurphi_goal(
				current_analysis->the_domain);
		to_print += current_analysis->the_problem->toMurphi_invariant(
				current_analysis->the_domain);
		to_print += current_analysis->the_problem->toMurphi_metric(
				current_analysis->the_domain);
		to_print = current_analysis->the_problem->toMurphi_ext_fun(
				current_analysis->the_domain, to_print);
		current_analysis->error_list.report();
		cout << "\n\n END OF PARSER \n\n";
		outstream << simplify(to_print);
		outstream.close();
		ext_func_stream.close();
		delete current_in_stream;
	}
	// Output the errors from all input files

	delete yfl;
}
