/*
 * upm_rpg.hpp
 *
 *  Created on: 7 Mar 2014
 *      Author: k1328088
 */

#ifndef UPM_RPG_HPP_
#define UPM_RPG_HPP_
//#include <std>
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>


class upm_rpg {

private:
	std::set<std::string> goal_fact_layer;
	std::vector<std::set<std::string> > rpg_facts;
	std::vector<std::set<std::string> > rpg_actions;
	double rpg_length;

public:

	upm_rpg();
	void create_fact_layer();
	void create_action_layer();
	std::set<std::string> get_fact_layer();
	void compute_rpg(state* ws);
	double get_rpg_value();
};

#endif /* UPM_RPG_HPP_ */
