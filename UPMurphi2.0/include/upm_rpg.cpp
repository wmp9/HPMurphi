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
	init_facts = std::set<mu_0_boolean*>();
//	rpg_actions = std::vector<std::set<int> >();
	goal_fact_layer = get_goal_conditions();
	rpg_state_facts = std::vector<state*>();

	achieved_by = std::map<mu_0_boolean*, int>();
	action_pre = std::map<int, std::vector<mu_0_boolean*> >();

	for( int i = 0; i < RULES_IN_WORLD; i++ )
	    remaining_rules.push_back(i);
}


std::set<mu_0_boolean*> upm_rpg::get_fact_layer(){

	std::set<mu_0_boolean*> f_list;

	std::vector<mu_0_boolean*> v_temp = workingstate->get_mu_bools();
	std::vector<mu_0_boolean*> v_tempp = workingstate->get_mu_bool_arrays();
	v_temp.insert(v_temp.end(), v_tempp.begin(), v_tempp.end());

	for (int ix2 = 0; ix2 < (v_temp.size()); ix2++){
				if (v_temp.at(ix2)->value() == 1){
					f_list.insert(v_temp.at(ix2));
				}
	}

	return (f_list);
}


double upm_rpg::compute_rpg(){

//	clock_t start_total = clock();

	action_pre.clear();
	achieved_by.clear();

	double rpg_length;

	init_facts = get_fact_layer();

	state* temp_ws = new state(workingstate);
	state* backup_state = new state();

	std::vector<int> temp_rem_rules = remaining_rules;
	std::set<int> temp_rem_rules2(remaining_rules.begin(), remaining_rules.end());

	state* next_rpg_state = new state(workingstate);

	rpg_state_facts.push_back(workingstate);

//	std::set <int> action_layer;
	std::set<mu_0_boolean*> f_l;

	while (true){

		StateCopy(backup_state, workingstate);

		for (int ix = 0; ix < temp_rem_rules.size(); ix++){

			int ixxx = temp_rem_rules.at(ix);

			StateCopy(workingstate, backup_state);

			if (Rules->generator->Condition(ixxx)){

				action_pre.insert(std::make_pair(ixxx, Rules->generator->precond_array(ixxx)));

				std::vector<mu_0_boolean*> aef = Rules->generator->effects_add_array(ixxx);

				for (int ix44 = 0; ix44 < aef.size(); ix44++){
						achieved_by[aef.at(ix44)] = ixxx;

//					achieved_by.insert(std::make_pair(aef.at(ix44), ixxx));
				}

				StateCopy(workingstate, next_rpg_state);

				Rules->generator->Code_ff(ixxx);
//				action_layer.insert(ixxx);

				temp_rem_rules2.erase(ixxx);

				StateCopy(next_rpg_state, workingstate);

			}

		}  // FOR LOOP END

		StateCopy(workingstate, next_rpg_state);

		temp_rem_rules.resize(temp_rem_rules2.size());
		std::copy(temp_rem_rules2.begin(), temp_rem_rules2.end(), temp_rem_rules.begin());

		StateCopy(backup_state, next_rpg_state);

		rpg_state_facts.push_back(backup_state);

		if (mu__goal__00())	break;

	} // WHILE END


	/*************************
	 *
	 * BACKWARDS SEARCH
	 *
	 */


	std::set<mu_0_boolean*> backwards = goal_fact_layer;
	std::set<int> rpg_final;
	int curr_action_layer = rpg_state_facts.size();

	std::set<mu_0_boolean*>::iterator itt;
	std::set<mu_0_boolean*> temp_set;

	while (curr_action_layer >= 0 ){

		for (itt=backwards.begin(); itt!=backwards.end(); ++itt){

				if ( rpg_final.count(achieved_by[*itt]) >= 1) continue;

					std::copy(action_pre[achieved_by[*itt]].begin(), action_pre[achieved_by[*itt]].end(), std::inserter(temp_set, temp_set.end()));

				if (init_facts.count(*itt) == 0){
					rpg_final.insert(achieved_by[*itt]);
				}

		}

		backwards = temp_set;
		curr_action_layer--;
		temp_set.clear();

		if (backwards.size() == 0) break;

	}

	rpg_length = rpg_final.size();

	StateCopy(workingstate, temp_ws);

	delete next_rpg_state;
	delete temp_ws;
	delete backup_state;

//	start_total = clock() - start_total;
//	cout << "\nTOTAL RPG TIME: " << (((float)start_total)/CLOCKS_PER_SEC) << " (" << start_total << " clicks)\n\n ----------------------------------------------------" << endl;

	return (rpg_length);
}
