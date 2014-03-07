#include <stdio.h>
#include <math.h>
#include "equations.h"

/* Costanti per ottimizzare calcoli ripetuti */
const double dilution_b_3_in_b_2 = A;
const double const_1 = V_7/A;
const double const_2_1 = -K_2_3/A;
const double const_2_2 = K_2_3/A;
const double const_4_1 = V_p_3_1/A;
const double const_4_2 = -V_p_3_1/A;
const double const_5_1 = -K_1_3/A;
const double const_5_2 = K_1_3/A;
const double const_6_1 = -K_2_3/A;
const double const_6_2 = K_2_3/A;
const double const_7_1 = -K_3_4/A;
const double const_7_2 = K_3_4/A;
const double const_8_1 = -K_4_5/A;
const double const_8_2 = K_4_5/A;
const double const_9_1 = (P_el*10000*100)/(c_p_sol*rho_sol*A);
const double const_10_1 = ((m_vap)/((-rho_sol/1000)*A)); // -0,00610575161802 ; x3 = 0,0183172548541
const double const_10_2 = ((m_vap)/((rho_w/1000.0)*A)); // 0,00632844636642
const double const_10_3 = (-m_vap)/A;
const double const_10_4_2 = c_p_sol * rho_sol * A;
const double const_11_1 = -K_5_7/A;
const double const_11_2 = K_5_7/A;
const double const_12_1 = -P_7_cool/(c_p_lo*rho_lo*(A/10000)); // la divisione per 10000 serve ad accordare l'unità di misura di A al resto dell'equazione: da cm^2 a m^2
const double const_13_1 = -V_p_7_1/A;
const double const_13_2 = V_p_7_1/A;
const double const_14_1 = (-P_6_cool/(c_p_w*rho_w*(A/10000)))*100; // la divisione per 10000 serve ad accordare l'unità di misura di A al resto dell'equazione: da cm^2 a m^2
const double const_15_1 = -V_p_6_1/A;
const double const_15_2 = V_p_6_1/A;

double round_k_digits(double n){
	// NB da aggiustare nn prende la POW in compilazione
	//double prec=pow(.1,k);
	//double prec = 0.1 * 0.1 ;
	//double prec = 0.01;
	double round= (n>0) ? (n+0.05) : (n-0.05);
	return round-fmod(round,0.1);
}

/* Preparazione della soluzione (fase preliminare)*/

/* Tapwater -> B2 , id constants: 1*/
double prep_level_b2_in_tapwater(double old_h_1, int step_time){
	return round_k_digits((old_h_1 + (const_1 * step_time)));
}

/* B2 -> B3 , id constants: 2*/
double prep_level_b2_out_b3(double old_h_2, int step_time){
	double result = round_k_digits((old_h_2 + ((const_2_1 * sqrt((old_h_2/H_2_3)+1)) * step_time)));
	if(result > 0)
		return result;
	else
		return 0;
}

double prep_level_b3_in_b2(double old_h_2, double old_h_3, int step_time){
	return round_k_digits((old_h_3 + ((const_2_2 * sqrt((old_h_2/H_2_3)+1)) * step_time))); // secondo me ci va old_h_2 e non come sembra dall'articolo old_h_3, perché dovrebbe contare solo il livello del serbatoio più in alto
}

double prep_level_b2_b3(double old_h_2, int step_time){
	return round_k_digits((const_2_2 * sqrt((old_h_2/H_2_3)+1)) * step_time);
}


/* manual addition of salt in B3 , id constants: 3*/
double prep_concentration_b3_in_manual(){
	return round_k_digits(c_hi);
}

/* B3 -> B1 , id constants: 4*/
double prep_level_b1_in_b3(double old_h_1, int step_time){
	return round_k_digits((old_h_1 + (const_4_1 * step_time)));
}

double prep_level_b3_out_b1(double old_h_3, int step_time){
	double result = round_k_digits((old_h_3 + (const_4_2 * step_time)));
	if(result > 0)
		return result;
	else
		return 0;
}

double prep_level_b3_b1(double old_h_3, int step_time){
	return round_k_digits((const_4_1 * step_time));
}


/* Processo ciclico */

/* B1 -> B3 , id constants: 5*/

double cyclic_level_b1_out_b3(double old_h_1, int step_time){
	double result = round_k_digits((old_h_1 + ((const_5_1 * sqrt((old_h_1/H_1_3)+1)) * step_time)));
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b3_in_b1(double old_h_1, double old_h_3, int step_time){
	return round_k_digits((old_h_3 + ((const_5_2 * sqrt((old_h_1/H_1_3)+1)) * step_time))); // secondo me ci va...
}

double cyclic_level_b1_b3(double old_h_1, int step_time){
	return round_k_digits(((const_5_2 * sqrt((old_h_1/H_1_3)+1)) * step_time));
}


/* Dilution B2 -> B3 , id constants: 6*/
double cyclic_level_b2_out_b3(double old_h_2, int step_time){
	double result = round_k_digits((old_h_2 + ((const_6_1 * sqrt((old_h_2/H_2_3)+1)) * step_time)));
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b3_in_b2(double old_h_2, double old_h_3, int step_time){
	return round_k_digits((old_h_3 + ((const_6_2 * sqrt((old_h_2/H_2_3)+1)) * step_time))); // secondo me ci va...
}

double cyclic_level_b2_b3(double old_h_2, int step_time){
	return round_k_digits((const_6_2 * sqrt((old_h_2/H_2_3)+1)) * step_time);
}

double cyclic_concentration_b3_in_b2(double old_c_3, double c_2, double h_2, double h_3, int step_time){
	if(h_3 == 0){
		return old_c_3;
	}
	double v_9 = (const_6_2 * sqrt((h_2/H_2_3)+1));
	//printf("old_c_3: %f, %f\n", old_c_3, (((((v_9 * c_2) / A ) - (old_c_3 * v_9)))/h_3));
	return round_k_digits((old_c_3 + ((((((v_9 * c_2) / A ) - (old_c_3 * v_9)))/h_3) * step_time))); //DA VERIFICARE: E' corretta l'implementazione dell'equazione? c_3 è una costante di valore 3 o è una variabile?
}

/* B3 -> B4 , id constants: 7*/
double cyclic_level_b3_out_b4(double old_h_3, int step_time){
	double result = round_k_digits(old_h_3 + ((const_7_1 * sqrt((old_h_3/H_3_4)+1)) * step_time));
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b4_in_b3(double old_h_3, double old_h_4, int step_time){
	return round_k_digits(old_h_4 + ((const_7_2 * sqrt((old_h_3/H_3_4)+1)) * step_time)); // secondo me ci va...
}

double cyclic_level_b3_b4(double old_h_3, int step_time){
	return round_k_digits((const_7_2 * sqrt((old_h_3/H_3_4)+1)) * step_time);
}
/* B4 -> B5 , id constants: 8*/
double cyclic_level_b4_out_b5(double old_h_4, int step_time){
	double result = round_k_digits(old_h_4 + ((const_8_1 * sqrt((old_h_4/H_4_5)+1)) * step_time));
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b5_in_b4(double old_h_4, double old_h_5, int step_time){
	return round_k_digits(old_h_5 + ((const_8_2 * sqrt((old_h_4/H_4_5)+1)) * step_time)); // secondo me ci va...
}

double cyclic_level_b4_b5(double old_h_4, int step_time){
	return round_k_digits((const_8_2 * sqrt((old_h_4/H_4_5)+1)) * step_time);
}

/* Heating until boiling temperature , id constants: 9*/

double cyclic_temperature_b5(double old_T, double h_5, int step_time){
	if(h_5 == 0){
		return old_T;
	}
	double result = round_k_digits(old_T + ((const_9_1 / h_5) * step_time));
	if(result < 100.0)
		return result;
	else
		return 100.0;
}

/* Evaporation , id constants: 10*/
double cyclic_level_b5_out_b6(double old_h_5, int step_time){
	double result = round_k_digits(old_h_5 + (const_10_1 * step_time));
	/* Per evitare che venga restituito un numero negativo: ciò si potrebbe verificare quando il liquido sta per finire e l'intervallo di tempo è abbastanza lungo per far uscire una quantità di liquido superiore a quella contenuta*/
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b6_in_b5(double old_h_6, int step_time){
	return round_k_digits(old_h_6 + (const_10_2 * step_time));
}

/* Non si dovrebbe usare: le equazioni precedenti sono diverse: pare che il liquido che esce non sia uguale a quello che entra */
double cyclic_level_b5_b6(double old_h_5, int step_time){
	return round_k_digits(const_10_2 * step_time);
}

double cyclic_concentration_b5(double old_c_5, double old_h_5, int step_time){
	//	return old_c_5 + ((const_10_3 * old_c_5) - old_c_5 * cyclic_level_b5_out_b6(old_c_5)); // da controllare: attenzione ai segni, soprattutto al primo meno e a c_5: è una costante di valore 5 o una variabile?
	//printf("old_c: %f\n", (old_c_5 + ((const_10_3 * old_c_5) - old_c_5 * cyclic_level_b5_out_b6(old_c_5))/old_h_5));
	//printf("m_vap*c_5/A: %f\n", (const_10_3 * old_c_5));
	//printf("- c_5... : %f\n", old_c_5 * (const_10_1));
	//printf("level_5 : %f\n", ((const_10_3 * old_c_5) - old_c_5 * (const_10_1))/(old_h_5));
	if(old_h_5 == 0){
		return old_c_5;
	}
	double result = old_c_5 + (((((const_10_3 * old_c_5) - 2 * old_c_5 * (const_10_1))/(old_h_5)) * step_time)); // ERRORE MESSO DI PROPOSITO: la moltiplicazione per 2 non è presente nell'equazione dell'articolo
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_temperature_b_5(double old_T, int step_time){
	double result = round_k_digits(old_T + (((P_el - m_vap*(c_p_sol * old_T + lambda_h_vap)) / (old_T * const_10_4_2)) * step_time)); // da ottimizzare e da verificare: nell'equazione dell'articolo manca dT. Perché è un errore il dh_5?
	if(result < 100.0)
		return result;
	else
		return 100.0;
}

/* B5 -> B7 , id constants: 11*/
double cyclic_level_b5_out_b7(double old_h_5, int step_time){
	double result = round_k_digits(old_h_5 + ((const_11_1 * sqrt((old_h_5/H_5_7)+1)) * step_time));
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b7_in_b5(double old_h_5, double old_h_7, int step_time){
	return round_k_digits(old_h_7 + ((const_11_2 * sqrt((old_h_5/H_5_7)+1)) * step_time)); // secondo me ci va...
}

double cyclic_level_b5_b7(double old_h_5, int step_time){
	return round_k_digits((const_11_2 * sqrt((old_h_5/H_5_7)+1)) * step_time);
}

/* Cooling in B7 , id constants: 12*/
double cyclic_temperature_b7(double old_T, double h_7, int step_time){
	//printf("new T: %f\n", old_T + (const_12_1 / h_7));
	if(h_7 == 0){
		return old_T;
	}
	return round_k_digits(old_T + ((const_12_1 / (h_7/100) * step_time))); // la divisione per 100 serve ad accordare l'unità di misura di h_7 al resto dell'equazione: da cm a m
}
/* B7 -> B1 , id constants: 13*/
double cyclic_level_b7_out_b1(double old_h_7, int step_time){
	double result = round_k_digits(old_h_7 + (const_13_1 * step_time));
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b1_in_b7(double old_h_1, int step_time){
	return round_k_digits(old_h_1 + (const_13_2 * step_time));
}

double cyclic_level_b7_b1(double old_h_7, int step_time){
	return round_k_digits(const_13_2 * step_time);
}

/* Cooling in B6 , id constants: 14*/
double cyclic_temperature_b6(double old_T, double h_6, int step_time){
	if(h_6 == 0){
		return old_T;
	}
	return round_k_digits(old_T + ((const_14_1 / h_6) * step_time)); // la divisione per 100 serve ad accordare l'unità di misura di h6 al resto dell'equazione: da cm a m
}
/* B6 -> B2 , id constants: 15*/
double cyclic_level_b6_out_b2(double old_h_6, int step_time){
	double result = round_k_digits(const_15_1 * step_time);
	if(result > 0)
		return result;
	else
		return 0;
}

double cyclic_level_b2_in_b6(double old_h_2, int step_time){
	return round_k_digits(old_h_2 + (const_15_2 * step_time));
}

double cyclic_level_b6_b2(double old_h_6, int step_time){
	return round_k_digits(const_15_2 * step_time);
}

