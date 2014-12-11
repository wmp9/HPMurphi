#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

double round_k_digits(double n, unsigned k){
	double prec = pow(0.1,k);
	double round = (n>0) ? (n+prec/2) : (n-prec/2);
	return round-fmod(round,prec);
}

double increase_ringtime_process_ring(double ringtime, double T ) {
	 return round_k_digits(ringtime+(( T ) * (1.0000000000)),11); 
}

double increase_capacitance_process_chargecapacitor(double capacitance, double T, double resistance ) {
	 return round_k_digits(capacitance+(( T ) * ((1.0000000000) / (resistance))),11); 
}

