#ifndef EXTERN_LIB
#define  EXTERN_LIB
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#endif



double round_k_digits(double n, unsigned k)
{
    // NB da aggiustare nn prende la POW in compilazione
    //double prec=pow(.1,k);
    double prec = 0.1 * 0.1 ;
    double round= (n>0) ? (n+prec/2) : (n-prec/2);
    return round-fmod(round,prec);
}

double night_op_ext(double soc, double heater_rate, double T){
	double value = soc - heater_rate*T;
	return round_k_digits(value,2);
}

double generating_ext(double supply, double solar_const, double daytime, double T){
	double value = supply + (( (solar_const*daytime) * ((((4*daytime)-90)*daytime)+450))*T);
	return round_k_digits(value,2);
}

double discharging_ext(double soc, double demand, double supply, double T){
	double value = soc - (T * (demand - supply));
	return round_k_digits(value,2);
}

double charging_ext(double demand, double supply, double soc, double charge_rate,double T){
	double value =soc + (T * (supply - demand) * charge_rate * (100 - soc));
	return round_k_digits(value,2);
}
