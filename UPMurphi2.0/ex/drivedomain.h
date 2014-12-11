#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

double round_k_digits(double n, unsigned k){
	double prec = pow(0.1,k);
	double round = (n>0) ? (n+prec/2) : (n-prec/2);
	return round-fmod(round,prec);
}

double increase_speed_duraction_end_accelerate(double speed, double accelerate_clock ) {
	 return round_k_digits(speed+(accelerate_clock),10); 
}

double increase_traveltime_action_drive(double traveltime, double distance, double speed ) {
	 return round_k_digits(traveltime+((distance) / (speed)),10); 
}

