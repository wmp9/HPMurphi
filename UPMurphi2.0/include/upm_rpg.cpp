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


upm_rpg::upm_rpg() {
	// TODO Auto-generated constructor stub
	rpg_facts = std::vector<std::set<std::string> >();
	rpg_actions = std::vector<std::set<std::string> >();
	all_fired_actions = std::set<std::string>();

	goal_fact_layer = std::set<std::string>();
	goal_fact_layer.insert(mu_on[mu_a][mu_b].name);
	goal_fact_layer.insert(mu_on[mu_b][mu_c].name);
	goal_fact_layer.insert(mu_on[mu_c][mu_d].name);

	rpg = std::set<std::string>();
	achieved_by = std::map<std::string, std::string>();
	action_pre = std::map<std::string, std::vector<std::string> >();
	rpg_length = -1;
}

void upm_rpg::clear_all(){

	rpg_actions.clear();
	rpg.clear();
	rpg_facts.clear();
	rpg_length = -1;
	achieved_by.clear();
	action_pre.clear();
	all_fired_actions.clear();
}

void upm_rpg::create_fact_layer(){

}

void upm_rpg::create_action_layer(){

}

std::set<std::string> upm_rpg::get_fact_layer(){

	std::set<std::string> f_list;

	std::vector<mu_0_boolean*> v_temp = workingstate->get_mu_bools();
	//		cout << "[" << v_temp[0]->name << "] == ["<< mu_x.name <<"]!! " << endl;

	for (int ix2 = 0; ix2 < (v_temp.size()); ix2++){

				if (v_temp.at(ix2)->value() == 1){
					f_list.insert(v_temp.at(ix2)->name);
				}

//		cout << "Awesome "<< (v_temp).at(ix2)->name << ": " << (v_temp).at(ix2)->value() << endl;
	//			cout << mu_x.name << endl;

	}

//	cout << "\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n" << f_list.size() << endl;

	return (f_list);

}

class mu_1__type_2;
class mu_1__type_1;

void upm_rpg::compute_rpg(state* ws){

	state* temp_ws = new state();
	state* backup_state = new state();

	RuleManager *RulesCopy = new RuleManager();
	*RulesCopy = *Rules;

//	StateManager *StateSetCopy = new StateManager(true, nums);
//	StateManager StateSetCopy = *StateSet;

	StateCopy(temp_ws, workingstate);
//	StateCopy(backup_state, workingstate);

//	cout << "\n\nYAAAAAAAAAATTTTTTTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!" << endl;

//	int l = 0;

	while (true){

//		cout << "SHAMAAA\n\n" << endl;
		std::set <std::string> action_layer;

		std::set<std::string> f_l;
		if (rpg_facts.size() == 0){
			f_l = get_fact_layer();
		}
		else {
		    f_l = rpg_facts.at(rpg_facts.size()-1);
		}

		std::vector<mu_0_boolean*> v_temp2 = workingstate->get_mu_bools();
		std::vector<mu_0_boolean*> v_temp4 = workingstate->get_mu_bool_arrays();
		v_temp2.insert(v_temp2.end(), v_temp4.begin(), v_temp4.end());

//		cout << "\n\n\nALL FACTSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n\n" << endl;

//		for (int ix17 = 0; ix17 < v_temp2.size(); ix17++){
//			v_temp2.at(ix17)->print();
//		}


		StateCopy(backup_state, workingstate);

		state* next_rpg_state = new state();
		StateCopy(next_rpg_state, workingstate);



//		cout << "\n\n\n FACT LAYER: " << rpg_facts.size() << endl;
//		cout << "\n\n*****************************************************************\n\n";
		for (int ix = 0; ix < RULES_IN_WORLD; ix++){
//			//		RulesCopy->NextState()->print();
//			//      list<char>::iterator theIterator;
//			//		RulesCopy->AllNextStates();
//
//			//			RulesCopy->SeqNextState();

			StateCopy(workingstate, backup_state);

			if (RulesCopy->generator->Condition(ix) && all_fired_actions.count(RulesCopy->RuleName(ix))==0){

//				cout << "PRE" << endl;
//				workingstate->print();
//				cout << "\n" << endl;

//				cout << "\n\n\n //////////////////////////////////////////////////////////////////// \n" << endl;
//
				std::vector<std::string> pres = RulesCopy->generator->precond_array(ix);

				action_pre[RulesCopy->RuleName(ix)] = pres;


				std::vector<std::string> aef = RulesCopy->generator->effects_add_array(ix);
				for (int ix44 = 0; ix44 < aef.size(); ix44++){
					if (achieved_by.find(aef.at(ix44)) == achieved_by.end()){
						achieved_by[aef.at(ix44)] = RulesCopy->RuleName(ix);
//						cout << "\n\nADDED : " << aef.at(ix44) << "\n\n" << endl;
					}
				}
//
//				cout << "\n //////////////////////////////////////////////////////////////////// \n\n\n" << endl;


				StateCopy(workingstate, next_rpg_state);

//				cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
//				cout << "\n" << RulesCopy->RuleName(ix) << "\n\n" << endl;


				RulesCopy->generator->Code(ix);
				action_layer.insert(RulesCopy->RuleName(ix));
				all_fired_actions.insert(RulesCopy->RuleName(ix));


//				cout << "POST" << endl;
//				workingstate->print();
//				cout << "\n" << endl;


				for (int ix2 = 0; ix2 < (v_temp2.size()); ix2++){

								if (v_temp2.at(ix2)->value() == 1){
									f_l.insert(v_temp2.at(ix2)->name);
//									cout << "\n\n\nFACT LAYER STUFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n\n" << endl;
//									v_temp2.at(ix2)->print();
//									cout << "\n\n\n" << endl;
								}

				}

//				  std::set<std::string>::iterator it2;
//				  cout << "FactL contains:";
//				  for (it2=f_l.begin(); it2!=f_l.end(); ++it2)
//					  cout << ' ' << *it2;
//				  cout << "\n\n*****************************************************************\n\n";


			}

//			StateCopy(workingstate, temp_ws2);


		}  // FOR LOOP END

				std::set<std::string>::iterator it;

				  for (it=f_l.begin(); it!=f_l.end(); ++it){
					  for (int ix3 = 0; ix3 < v_temp2.size(); ix3++){
						  if (v_temp2.at(ix3)->name == *it){
							  v_temp2.at(ix3)->value(1);
						  }
					  }
				  }


		rpg_actions.push_back(action_layer);
		rpg_facts.push_back(f_l);




//		std::set<std::string>::iterator it;
//		std::cout << "myset contains:";
//		  for (it=action_layer.begin(); it!=action_layer.end(); ++it)
//		    std::cout << ' ' << *it;
//		  std::cout << '\n';


/* TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * GOAL IS HARDCODED RIGHT NOW BUT THIS NEEDS TO BE TAKEN CARE OF!
 */


		if ((f_l.count(mu_on[mu_a][mu_b].name)!=0) && (f_l.count(mu_on[mu_b][mu_c].name)!=0) && (f_l.count(mu_on[mu_c][mu_d].name)!=0)){
//		if (mu_on[mu_a][mu_b] && mu_on[mu_b][mu_c] && mu_on[mu_c][mu_d]){
			cout << "\n\n\nGOOAL" << endl;
			break;
		}

//		if (rpg_facts.size() > 50){ break; }



	} // WHILE END

	std::set<std::string> backwards = goal_fact_layer;
	std::set<std::string> rpg_final;
	int curr_action_layer = rpg_actions.size()-1;
	while(curr_action_layer > 0){

		std::set<std::string>::iterator itt;
		std::set<std::string> temp_set;

		for (itt=backwards.begin(); itt!=backwards.end(); ++itt){
//			if (achieved_by.find(*itt) != achieved_by.end())
//			cout << " RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR \n" << achieved_by[*itt] << "\n\n" << endl;


			if (rpg_facts.at(0).count(*itt) == 0){
				rpg_final.insert(achieved_by[*itt]);
			}

				for (int i = 0; i < action_pre[achieved_by[*itt]].size(); i++){
					temp_set.insert(action_pre[achieved_by[*itt]][i]);
	//				cout << " TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT \n" << action_pre[achieved_by[*itt]][i] << "\n\n" << endl;
				}



		}

		backwards = temp_set;
//		cout << "\n\n BACKWARDS SIZE: " << backwards.size() << "\n\n\n" << endl;
		curr_action_layer--;
//		if (temp_set.size() == 0) break;

	}

//	cout << "ACHIEVED: " << achieved_by["on[a][b]"] << "\n\n\n" << endl;

	rpg_length = rpg_final.size();

	std::set<std::string>::iterator itt2;
	cout << "\n\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-\n FINAL: \n" << endl;
	for (itt2=rpg_final.begin(); itt2!=rpg_final.end(); ++itt2){

			cout << *itt2 << endl;
	}
	cout << "===-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-\n\n" << endl;



	StateCopy(workingstate, temp_ws);

}



double upm_rpg::get_rpg_value(){

	if (rpg_length < 0){
		compute_rpg(workingstate);
	}

	return (rpg_length);
}
