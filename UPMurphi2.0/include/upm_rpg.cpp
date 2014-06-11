/*
 * upm_rpg.cpp
 *
 *  Created on: 7 Mar 2014
 *      Author: k1328088
 */

#include "upm_rpg.hpp"
//#include <std>
#include <string>
#include <set>
#include <list>
#include <iterator>
#include <vector>
#include <map>
#include <ctime>
#include <time.h>



upm_rpg::upm_rpg() {
	// TODO Auto-generated constructor stub
	rpg_facts = std::vector<std::set<std::string> >();
	rpg_actions = std::vector<std::set<std::string> >();
	goal_fact_layer = std::set<std::string>();
	create_goal_layer();

	rpg = std::set<std::string>();
	achieved_by = std::map<std::string, std::string>();
	action_pre = std::map<std::string, std::vector<std::string> >();
	rpg_length = -1;

	for( int i = 0; i < RULES_IN_WORLD; i++ )
	    remaining_rules.push_back(i);
}

void upm_rpg::create_goal_layer(){

	cout << "NEW GOAL LAYER" << endl;

//  BLOCKS
//	goal_fact_layer.insert(mu_on[mu_a][mu_b].name);
//	goal_fact_layer.insert(mu_on[mu_b][mu_c].name);
//	goal_fact_layer.insert(mu_on[mu_c][mu_d].name);

//  BW6
//	goal_fact_layer.insert(mu_on[mu_b1][mu_b4].name);
//	goal_fact_layer.insert(mu_on[mu_b2][mu_b6].name);
//	goal_fact_layer.insert(mu_on[mu_b3][mu_b5].name);
//	goal_fact_layer.insert(mu_on[mu_b5][mu_b1].name);
//	goal_fact_layer.insert(mu_on[mu_b6][mu_b3].name);

//	BW8
//	goal_fact_layer.insert(mu_on[mu_b1][mu_b6].name);
//	goal_fact_layer.insert(mu_on[mu_b3][mu_b1].name);
//	goal_fact_layer.insert(mu_on[mu_b4][mu_b3].name);
//	goal_fact_layer.insert(mu_on[mu_b5][mu_b8].name);
//	goal_fact_layer.insert(mu_on[mu_b6][mu_b7].name);
//	goal_fact_layer.insert(mu_on[mu_b7][mu_b5].name);

//	BW11
//	goal_fact_layer.insert(mu_on[mu_b2][mu_b8].name);
//	goal_fact_layer.insert(mu_on[mu_b3][mu_b1].name);
//	goal_fact_layer.insert(mu_on[mu_b4][mu_b11].name);
//	goal_fact_layer.insert(mu_on[mu_b5][mu_b3].name);
//	goal_fact_layer.insert(mu_on[mu_b7][mu_b2].name);
//	goal_fact_layer.insert(mu_on[mu_b9][mu_b7].name);
//	goal_fact_layer.insert(mu_on[mu_b10][mu_b4].name);
//	goal_fact_layer.insert(mu_on[mu_b11][mu_b9].name);

//  BW15
	goal_fact_layer.insert(mu_on[mu_b1][mu_b5].name);
	goal_fact_layer.insert(mu_on[mu_b3][mu_b12].name);
	goal_fact_layer.insert(mu_on[mu_b4][mu_b13].name);
	goal_fact_layer.insert(mu_on[mu_b5][mu_b2].name);
	goal_fact_layer.insert(mu_on[mu_b6][mu_b8].name);
	goal_fact_layer.insert(mu_on[mu_b7][mu_b9].name);
	goal_fact_layer.insert(mu_on[mu_b8][mu_b15].name);
	goal_fact_layer.insert(mu_on[mu_b9][mu_b1].name);
	goal_fact_layer.insert(mu_on[mu_b10][mu_b6].name);
	goal_fact_layer.insert(mu_on[mu_b12][mu_b11].name);
	goal_fact_layer.insert(mu_on[mu_b13][mu_b10].name);
	goal_fact_layer.insert(mu_on[mu_b14][mu_b4].name);
	goal_fact_layer.insert(mu_on[mu_b15][mu_b3].name);

}

bool upm_rpg::goal_check(std::set<std::string> set_layer){

//	std::set<std::string> set_layer;
//	set_layer = rpg_facts.at(rpg_facts.size()-1);


//	BLOCKS (BW4)
//	if ( (set_layer.count(mu_on[mu_a][mu_b].name)!=0) && (set_layer.count(mu_on[mu_b][mu_c].name)!=0) && (set_layer.count(mu_on[mu_c][mu_d].name)!=0))


//	BW6
//	if ( (set_layer.count(mu_on[mu_b1][mu_b4].name)!=0) && (set_layer.count(mu_on[mu_b2][mu_b6].name)!=0) &&
//			(set_layer.count(mu_on[mu_b3][mu_b5].name)!=0) && (set_layer.count(mu_on[mu_b5][mu_b1].name)!=0) &&
//			(set_layer.count(mu_on[mu_b6][mu_b3].name)!=0))

//	BW8
//	if ( (set_layer.count(mu_on[mu_b1][mu_b6].name)!=0) && (set_layer.count(mu_on[mu_b3][mu_b1].name)!=0) &&
//			(set_layer.count(mu_on[mu_b4][mu_b3].name)!=0) && (set_layer.count(mu_on[mu_b5][mu_b8].name)!=0) &&
//			(set_layer.count(mu_on[mu_b6][mu_b7].name)!=0) && (set_layer.count(mu_on[mu_b7][mu_b5].name)!=0) )

//	if ( mu_on[mu_b1][mu_b6]== true && mu_on[mu_b3][mu_b1]== true &&
//				mu_on[mu_b4][mu_b3]== true && mu_on[mu_b5][mu_b8]== true &&
//				mu_on[mu_b6][mu_b7]== true && mu_on[mu_b7][mu_b5]== true )

//	BW11
//	if ( (set_layer.count(mu_on[mu_b2][mu_b8].name)!=0) && (set_layer.count(mu_on[mu_b3][mu_b1].name)!=0) && (set_layer.count(mu_on[mu_b4][mu_b11].name)!=0) &&
//	 (set_layer.count(mu_on[mu_b5][mu_b3].name)!=0) && (set_layer.count(mu_on[mu_b7][mu_b2].name)!=0) && (set_layer.count(mu_on[mu_b9][mu_b7].name)!=0) &&
//	 (set_layer.count(mu_on[mu_b10][mu_b4].name)!=0) && (set_layer.count(mu_on[mu_b11][mu_b9].name)!=0))

//	BW15
	if ( (set_layer.count(mu_on[mu_b1][mu_b5].name)!=0) && (set_layer.count(mu_on[mu_b3][mu_b12].name)!=0) && (set_layer.count(mu_on[mu_b4][mu_b13].name)!=0) &&
	 (set_layer.count(mu_on[mu_b5][mu_b2].name)!=0) && (set_layer.count(mu_on[mu_b6][mu_b8].name)!=0) && (set_layer.count(mu_on[mu_b7][mu_b9].name)!=0) &&
	 (set_layer.count(mu_on[mu_b8][mu_b15].name)!=0) && (set_layer.count(mu_on[mu_b9][mu_b1].name)!=0) && (set_layer.count(mu_on[mu_b10][mu_b6].name)!=0) &&
	 (set_layer.count(mu_on[mu_b12][mu_b11].name)!=0) && (set_layer.count(mu_on[mu_b13][mu_b10].name)!=0) &&
	 (set_layer.count(mu_on[mu_b14][mu_b4].name)!=0) && (set_layer.count(mu_on[mu_b15][mu_b3].name)!=0) )


	{
		return true;
	}
	else {
		return false;
	}
}

std::set<std::string> upm_rpg::get_fact_layer(){

	std::set<std::string> f_list;

	std::vector<mu_0_boolean*> v_temp = workingstate->get_mu_bools();
	std::vector<mu_0_boolean*> v_tempp = workingstate->get_mu_bool_arrays();
	v_temp.insert(v_temp.end(), v_tempp.begin(), v_tempp.end());

	for (int ix2 = 0; ix2 < (v_temp.size()); ix2++){
				if (v_temp.at(ix2)->value() == 1){
					f_list.insert(v_temp.at(ix2)->name);
				}
	}

	return (f_list);
}


void upm_rpg::compute_rpg(){

	clock_t start_total = clock();

	state* temp_ws = new state();
	state* backup_state = new state();

	StateCopy(temp_ws, workingstate);

	std::vector<int> temp_rem_rules(remaining_rules.size());
	std::copy(remaining_rules.begin(), remaining_rules.end(), temp_rem_rules.begin());

	std::set<int> temp_rem_rules2(temp_rem_rules.begin(), temp_rem_rules.end());

	state* next_rpg_state = new state(workingstate);

	while (true){

		std::set <std::string> action_layer;

		std::set<std::string> f_l;
		if (rpg_facts.size() == 0){
			f_l = get_fact_layer();
		}
		else {
		    f_l = rpg_facts.at(rpg_facts.size()-1);
		}

		std::vector<mu_0_boolean*> v_temp2 = next_rpg_state->get_mu_bools();
		std::vector<mu_0_boolean*> v_temp4 = next_rpg_state->get_mu_bool_arrays();
		v_temp2.insert(v_temp2.end(), v_temp4.begin(), v_temp4.end());

		StateCopy(backup_state, workingstate);

		std::vector<int> temp_rem_rules(temp_rem_rules2.size());
		std::copy(temp_rem_rules2.begin(), temp_rem_rules2.end(), temp_rem_rules.begin());


//		clock_t total_rules = clock();

		for (int ix = 0; ix < temp_rem_rules.size(); ix++){

			StateCopy(workingstate, backup_state);

			char * r_name = Rules->RuleName(temp_rem_rules.at(ix));

			if (Rules->generator->Condition(temp_rem_rules.at(ix))){

				std::vector<std::string> pres = Rules->generator->precond_array(temp_rem_rules.at(ix));

				action_pre[r_name] = pres;

				std::vector<std::string> aef = Rules->generator->effects_add_array(temp_rem_rules.at(ix));
				for (int ix44 = 0; ix44 < aef.size(); ix44++){
					if (achieved_by.count(aef.at(ix44)) == 0){
						achieved_by[aef.at(ix44)] = r_name;
						f_l.insert(aef.at(ix44));
//						cout << "*+*+*+*+*+*+*\n" << aef.at(ix44) << endl;
					}
				}

//				cout << "\n\n\nBACKUP: \n" << endl;
//				workingstate->print();

				StateCopy(workingstate, next_rpg_state);
//
//				cout << "\n\n\nNEXT RPG BEFORE CODE: \n" << endl;
//				workingstate->print();

				Rules->generator->Code_ff(temp_rem_rules.at(ix));
				action_layer.insert(r_name);
//
//				cout << "\n\n\nNEXT RPG AFTER CODE: \n\n" << endl;
//				workingstate->print();

				temp_rem_rules2.erase(temp_rem_rules.at(ix));

				StateCopy(next_rpg_state, workingstate);
			}

			delete [] r_name;

//			StateCopy(workingstate, next_rpg_state);

		}  // FOR LOOP END


		StateCopy(workingstate, next_rpg_state);


//		total_rules = clock() - total_rules;
//		cout << "Time of FOR TOTAL RULES: " << (((float)total_rules)/CLOCKS_PER_SEC) << " (" << total_rules << " clicks)" << endl;


		temp_rem_rules.resize(temp_rem_rules2.size());
		std::copy(temp_rem_rules2.begin(), temp_rem_rules2.end(), temp_rem_rules.begin());

		StateCopy(backup_state, next_rpg_state);
//		StateCopy(workingstate, next_rpg_state);


//		clock_t start_v_temp = clock();

//		std::set<std::string>::iterator it;
//		std::set<std::string> f_l_copy(f_l);

//		StateCopy(workingstate, backup_state);
//		v_temp2 = next_rpg_state->get_mu_bools();
//		std::vector<mu_0_boolean*> v_temp5 = next_rpg_state->get_mu_bool_arrays();
//		v_temp2.insert(v_temp2.end(), v_temp5.begin(), v_temp5.end());

//		if(rpg_facts.size()==4){
//				cout << "\n\nBEFORE: " << endl;
//				for (int ix55 = 0; ix55 < v_temp2.size(); ix55++){
//
//					v_temp2.at(ix55)->print();
//				}
//				cout << "\n\n" << endl;
//		}


//						for (int ix3 = 0; ix3 < v_temp2.size(); ix3++){
//							if (v_temp2.at(ix3)->value() == 0){
//								for (it=f_l_copy.begin(); it!=f_l_copy.end(); ++it){
//									  if ((v_temp2.at(ix3)->name == *it)/** && (v_temp2.at(ix3)->value() == 0)*/){
//										  v_temp2.at(ix3)->value(1);
//										  f_l_copy.erase(*it);
//										  break;
//									  }
//								}
//							}
//						}



//		if(rpg_facts.size()==4){
//		cout << "\n\nAFTER: " << endl;
//		for (int ix55 = 0; ix55 < v_temp2.size(); ix55++){
//
//			v_temp2.at(ix55)->print();
//		}
//		cout << "\n\n---------------------------------------\n\n" << endl;
//		}


//			std::set<std::string>::iterator it;
//
//			  for (it=f_l.begin(); it!=f_l.end(); ++it){
//				  for (int ix3 = 0; ix3 < v_temp2.size(); ix3++){
//					  if ((v_temp2.at(ix3)->name == *it) && (v_temp2.at(ix3)->value() == 0)){
//						  v_temp2.at(ix3)->value(1);
//					  }
//				  }
//			  }



//	  start_v_temp = clock() - start_v_temp;
//	  cout << "Time of V TEMP: " << (((float)start_v_temp)/CLOCKS_PER_SEC) << " (" << start_v_temp << " clicks)\n" << endl;


		rpg_actions.push_back(action_layer);
		rpg_facts.push_back(f_l);


//		delete next_rpg_state;

		//		cout << "\nSHANANA " << endl;
		//		for (int i = 0; i < rpg_facts.size(); i++){
		//			cout << rpg_facts.at(i).size() << endl;
		//		}
		//
		//		cout << "\n" << endl;

/* TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * GOAL IS HARDCODED RIGHT NOW BUT THIS NEEDS TO BE TAKEN CARE OF!
 */

		if (goal_check(f_l)){
//			cout << "GOOAL" << endl;
			break;
		}


//		cout << "\n\n--------------------------------------------\nWHILE\n" << endl;
//
//		workingstate->print();

	} // WHILE END


//	delete next_rpg_state;

	std::set<std::string> backwards = goal_fact_layer;
	std::set<std::string> rpg_final;
	int curr_action_layer = rpg_actions.size()-1;

//			clock_t start2 = clock();


	while(curr_action_layer > 0){

		std::set<std::string>::iterator itt;
		std::set<std::string> temp_set;

		for (itt=backwards.begin(); itt!=backwards.end(); ++itt){

			if (rpg_facts.at(0).count(*itt) == 0){
				rpg_final.insert(achieved_by[*itt]);
			}

				for (int i = 0; i < action_pre[achieved_by[*itt]].size(); i++){
					temp_set.insert(action_pre[achieved_by[*itt]][i]);
				}
		}

		backwards = temp_set;
		curr_action_layer--;
//		if (temp_set.size() == 0) break;

	}

//			start2 = clock() - start2;
//			cout << "Time of backwards search: " << (((float)start2)/CLOCKS_PER_SEC) << " (" << start2 << " clicks)" << endl;

	rpg_length = rpg_final.size();

//	std::set<std::string>::iterator itt2;
//	cout << "\n\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-\n FINAL: \n" << endl;
//	for (itt2=rpg_final.begin(); itt2!=rpg_final.end(); ++itt2){
//
//			cout << *itt2 << endl;
//	}
//	cout << "===-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-\n\n" << endl;

//	cout << "FACT LAYER: " << rpg_facts.size() << endl;
//	cout << "ACTION LAYER: " << rpg_actions.size() << "\n\n" << endl;

	StateCopy(workingstate, temp_ws);

	delete next_rpg_state;
	delete temp_ws;
	delete backup_state;

	start_total = clock() - start_total;
	cout << "\nTOTAL RPG TIME: " << (((float)start_total)/CLOCKS_PER_SEC) << " (" << start_total << " clicks)\n\n" << endl;

}



double upm_rpg::get_rpg_value(){

	if (rpg_length < 0){
		compute_rpg();
	}

	return (rpg_length);
}
