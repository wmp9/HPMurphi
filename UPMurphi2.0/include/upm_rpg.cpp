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


upm_rpg::upm_rpg() {
	// TODO Auto-generated constructor stub
	rpg_facts = std::vector<std::set<std::string> >();
	rpg_actions = std::vector<std::set<std::string> >();
	goal_fact_layer = std::set<std::string>();
	goal_fact_layer.insert("x");
	rpg_length = -1;
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

void upm_rpg::compute_rpg(state* ws){

	state* temp_ws = new state();
	state* temp_ws2 = new state();

	RuleManager *RulesCopy = new RuleManager();
	*RulesCopy = *Rules;

//	StateManager *StateSetCopy = new StateManager(true, nums);
//	StateManager StateSetCopy = *StateSet;

	StateCopy(temp_ws, workingstate);
	StateCopy(temp_ws2, workingstate);

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

		for (int ix = 0; ix < RULES_IN_WORLD; ix++){
//			//		RulesCopy->NextState()->print();list<char>::iterator theIterator;
//			//		RulesCopy->AllNextStates();
//
//			//			RulesCopy->SeqNextState();
//
//
			if (RulesCopy->generator->Condition(ix)){

//				cout << "PRE" << endl;
//				workingstate->print();
//				cout << "\n" << endl;

//				cout << RulesCopy->RuleName(ix) << endl;


				RulesCopy->generator->Code(ix);
				action_layer.insert(RulesCopy->RuleName(ix));


//				cout << "POST" << endl;
//				workingstate->print();
//				cout << "\n" << endl;

				for (int ix2 = 0; ix2 < (v_temp2.size()); ix2++){

								if (v_temp2.at(ix2)->value() == 1){
									f_l.insert(v_temp2.at(ix2)->name);
								}
				}


			}





//			StateCopy(workingstate, temp_ws2);
		}

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
//
//		std::cout << "myset contains:";
//		  for (it=action_layer.begin(); it!=action_layer.end(); ++it)
//		    std::cout << ' ' << *it;
//		  std::cout << '\n';

		if (mu_x.value()==1){
			break;
		}
	}


//	rpg_length = rpg.size();
	rpg_length = rpg_facts.size();

	StateCopy(workingstate, temp_ws);


}

double upm_rpg::get_rpg_value(){

	if (rpg_length < 0){
		compute_rpg(workingstate);
	}

	return (rpg_length);
}
