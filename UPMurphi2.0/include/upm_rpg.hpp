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
#include <map>


class upm_rpg {

private:
	std::set<std::string> goal_fact_layer;
	std::vector<std::set<std::string> > rpg_facts;
	std::vector<std::set<std::string> > rpg_actions;
	std::set<std::string> all_fired_actions;
	std::set<std::string> rpg;
	std::map<std::string, std::vector<std::string> > action_pre;
	std::map<std::string, std::string> achieved_by;
	double rpg_length;
	upm_rpg();
	upm_rpg(upm_rpg const&);
	void operator=(upm_rpg const&);

public:
	static upm_rpg& getInstance(){
		static upm_rpg instance;
		instance.clear_all();
		return instance;
	}
	void compute_rpg(state* ws);
	double get_rpg_value();
	void create_fact_layer();
	void create_action_layer();
	std::set<std::string> get_fact_layer();

	void clear_all();
//	~upm_rpg();
};

#endif /* UPM_RPG_HPP_ */
