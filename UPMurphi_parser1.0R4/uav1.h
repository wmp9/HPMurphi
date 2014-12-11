#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

double round_k_digits(double n, unsigned k){
	double prec = pow(0.1,k);
	double round = (n>0) ? (n+prec/2) : (n-prec/2);
	return round-fmod(round,prec);
}

double increase_reward_duraction_end_dospiral(double reward, double rewardof ) {
	 return round_k_digits(reward+(rewardof),5); 
}

double increase_reward_duraction_end_dosmalllawnmower(double reward, double rewardof ) {
	 return round_k_digits(reward+(rewardof),5); 
}

