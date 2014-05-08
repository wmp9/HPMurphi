#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

double round_k_digits(double n, unsigned k){
	double prec = pow(0.1,k);
	double round = (n>0) ? (n+prec/2) : (n-prec/2);
	return round-fmod(round,prec);
}

double increase_soc_process_charging(double soc, double T, double supply, double demand, double charge_rate ) {
	 return round_k_digits(soc+(( T ) * ((((supply) - (demand)) * (charge_rate)) * ((100.0000000) - (soc)))),10); 
}

double decrease_soc_process_discharging(double soc, double T, double demand, double supply ) {
	 return round_k_digits(soc-(( T ) * ((demand) - (supply))),10); 
}

double increase_daytime_process_generating(double daytime, double T ) {
	 return round_k_digits(daytime+(( T ) * (1.000000000)),10); 
}

double increase_supply_process_generating(double supply, double T, double solar_const, double daytime ) {
	 return round_k_digits(supply+(( T ) * (((solar_const) * (daytime)) * (((daytime) * (((4.000000000) * (daytime)) - (90.00000000))) + (450.0000000)))),10); 
}

double decrease_soc_process_night_operations(double soc, double T, double heater_rate ) {
	 return round_k_digits(soc-(( T ) * (heater_rate)),10); 
}

double increase_daytime_process_night_operations(double daytime, double T ) {
	 return round_k_digits(daytime+(( T ) * (1.000000000)),10); 
}

double assign_daytime_event_nightfall(double dawn ) {
	 return round_k_digits(-dawn,10); 
}

double decrease_demand_duraction_end_fullprepare(double demand, double a_rate ) {
	 return round_k_digits(demand-(a_rate),10); 
}

double increase_demand_duraction_start_fullprepare(double demand, double a_rate ) {
	 return round_k_digits(demand+(a_rate),10); 
}

double decrease_demand_duraction_end_prepareobs1(double demand, double b_rate ) {
	 return round_k_digits(demand-(b_rate),10); 
}

double increase_demand_duraction_start_prepareobs1(double demand, double b_rate ) {
	 return round_k_digits(demand+(b_rate),10); 
}

double decrease_demand_duraction_end_prepareobs2(double demand, double c_rate ) {
	 return round_k_digits(demand-(c_rate),10); 
}

double increase_demand_duraction_start_prepareobs2(double demand, double c_rate ) {
	 return round_k_digits(demand+(c_rate),10); 
}

double decrease_demand_duraction_end_observe1(double demand, double obs1_rate ) {
	 return round_k_digits(demand-(obs1_rate),10); 
}

double increase_demand_duraction_start_observe1(double demand, double obs1_rate ) {
	 return round_k_digits(demand+(obs1_rate),10); 
}

double decrease_demand_duraction_end_observe2(double demand, double obs2_rate ) {
	 return round_k_digits(demand-(obs2_rate),10); 
}

double increase_demand_duraction_start_observe2(double demand, double obs2_rate ) {
	 return round_k_digits(demand+(obs2_rate),10); 
}

