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
	std::set<std::string> rpg;
	std::map<std::string, std::vector<std::string> > action_pre;
	std::map<std::string, std::string> achieved_by;
	std::vector<int> remaining_rules;
	double rpg_length;
	void create_goal_layer();
	bool goal_check(std::set <std::string> sl);

	upm_rpg();
	upm_rpg(upm_rpg const&);
	void operator=(upm_rpg const&);

public:
//	upm_rpg();
//	~upm_rpg(){delete this;};
//		delete this;
////		upm_rpg();
//	}

	static upm_rpg& getInstance(){
			static upm_rpg instance;
//			instance.clear_all();
			return instance;
	}

	void compute_rpg();
	double get_rpg_value();
	std::set<std::string> get_fact_layer();
	void clear_all(){
		std::vector<std::set<std::string> >().swap(rpg_facts);
		std::vector<std::set<std::string> >().swap(rpg_actions);
		rpg.clear();
		action_pre.clear();
		achieved_by.clear();
		rpg_length = -1;
	}
};

#endif /* UPM_RPG_HPP_ */
