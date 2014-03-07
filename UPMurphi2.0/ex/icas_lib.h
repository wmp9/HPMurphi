#include <cmath>
#include <stdio.h>
#include <stdlib.h>



double round_k_digits(double n, unsigned k)
{
    double prec=pow((double).1,(double)k);
    double round= (n>0) ? (n+prec/2) : (n-prec/2);
    return round-fmod(round,prec);
}

int double_to_int(double n){
	double integer_part;
	double fract_part;
	fract_part = modf(n,&integer_part); // splitta in parte intera e parte decimale
	int to_return = (int) integer_part;
	if (fract_part > 0.5) 
		to_return++;
	return to_return;

}

double update1_v(double v, double a)
{
       double new_v;
       //new_v = v + ( mu_T * a);
       new_v = v + ( mu_T * (a ));
       return round_k_digits(new_v,2);
       
}


double update_d(double d, double v, double a)
{
       double new_d;
       //new_d = d + ( mu_T *v);
	   new_d = d + ( mu_T *v) + 0.5 * (a) * mu_T * mu_T;
       return round_k_digits(new_d,2);
}

int update_f(double rho, double v, double m, double g, double a, double h, double f)
{
       double new_f;
	double coulomb;
       //new_f = f - (a+0.1*(s-old_s))*T*T;
	double g_in_meter = g / 100 ; 
	double v_in_meter = v / 100;
	double a_in_meter = a / 100;

	
	coulomb = (((0.5 * rho * v_in_meter*v_in_meter * mu_Cd * mu_A* + m * g_in_meter * (mu_Crr +  (a_in_meter )/g_in_meter + h/100 ) ) * v_in_meter) / mu_Voltage);
	//g_c = (mu_cooling_constant * m * g_in_meter * v_in_meter) / mu_Voltage;
	
	if (mu_a <= -1){
		coulomb = 0;	// per evitare che si ricarichi durante la frenata	
	}
	new_f = f -(coulomb) - (mu_g_s/mu_Voltage); 
        //return round_k_digits(new_f,1);
	return double_to_int(new_f);
}

int update_cooling(double f,double g, double v, double m){
	double g_in_meter = g / 100 ; 
	double v_in_meter = v / 100;
	//double g_c = (mu_cooling_constant * m * g_in_meter * v_in_meter) / mu_Voltage;
	
	double new_f = f - (mu_g_s/mu_Voltage) - (mu_g_c / mu_Voltage);
	//return round_k_digits(new_f,1);
	return double_to_int(new_f);
}

/*
int update_f_at_startup(double rho, double v, double m, double g, double a, double h, double f)
{
       double new_f;
	double coulomb;
       //new_f = f - (a+0.1*(s-old_s))*T*T;
	double g_in_meter = g / 100 ; 
	double v_in_meter = v / 100;
	double a_in_meter = a / 100;
	//double g_c;

	//new_f = f - (0.5 * rho * v_in_meter*v_in_meter * mu_Cd * mu_A* + m * g_in_meter * (mu_Crr +  (a_in_meter - mu_mu*g_in_meter)/g_in_meter + h/100 ) ) * v_in_meter ;
	//new_f = f - (0.5 * rho * v*v *mu_A* + m * g * (mu_Crr +  (a - mu_mu*g)/g + h/100 ) ) * v ;
	coulomb = (((5.5 * rho * v_in_meter*v_in_meter * mu_Cd * mu_A* + m * g_in_meter * (mu_Crr +  (a_in_meter - mu_mu*g_in_meter)/g_in_meter + h/100 ) ) * v_in_meter) / mu_Voltage);
	//g_c = (mu_cooling_constant * m * g_in_meter * v_in_meter) / mu_Voltage;
	if (mu_a <= 303){
		coulomb = 0;	// per evitare che si ricarichi durante la frenata	
	}
	new_f = f -(coulomb) - mu_g_s - mu_restart_energy_cost ; 
        //return round_k_digits(new_f,1);
	return double_to_int(new_f);
}
*/
