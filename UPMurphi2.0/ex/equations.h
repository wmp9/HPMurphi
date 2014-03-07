/*
 * header.h
 *
 *  Created on: Jul 28, 2009
 *      Author: john
 */

#ifndef HEADER_H_
#define HEADER_H_


#define A 380.0				// A_k, 		cm^2, 		area della sezione di un serbatoio; nel nome della costante non è presente "_k" (con 1<=k<=7) perche' dovrebbe essere uguali per tutti

#define V_7 75.0		 	// V_7, 		cm^3/s, 	flusso che attraversa la valvola 7;

#define K_2_3 14.0 			// K_2,3, 		cm^3, 		flusso (in unita' di volume) dal serbatoio 2 al 3;
#define x_2_max 1.3			//

#define V_p_3_1 11.0		// V_p_3_1,		cm^3/s, 	flusso (in unita' di volume) che attraversa la pompa dal serbatoio 3 all'1;

#define K_1_3 9.7 			// K_1_3,		cm^3/s, 	flusso (in unita' di volume) dal serbatoio 1 al 3;
#define x_1_max 1.32		//

#define K_3_4 9.1			// K_3_4,		cm^3/s, 	flusso (in unita' di volume) dal serbatoio 3 al 4;
#define x_3_max 1.35		//

#define K_4_5 17.0 			// K_4_5,		cm^3/s, 	flusso (in unita' di volume) dal serbatoio 4 al 5;
#define x_4_max 1.18		//

#define P_el 5.8			// P_el,		kW,			potenza di riscaldamento del serbaotio 5; DA CORREGGERE
#define c_p_sol 3.94		// c_p,sol,		kJ/kgK,		calore specifico;
#define rho_sol 1034.4		// rho_sol,		kg/m^3,		densita' della soluzione;

#define K_5_7 12.0			// K_5_7,		cm^3/s, 	flusso (in unita' di volume) dal serbatoio 5 al 7;
#define x_5_max 1.32		//

#define P_7_cool 2.0		// P_7,cool,	KW, 		potenza di raffreddamento del serbatoito 7; DA CORREGGERE
#define c_p_lo 4.037		// c_p,lo,		kJ/kgK, 	calore specifico;
#define rho_lo 1020.0		// rho_lo,		kg/m^3,		densita' della soluzione;

#define V_p_7_1 18.18		// V_p7,1,		cm^3/s, 	flusso (in unita' di volume) che attraversa la pompa dal serbatoio 7 all'1;

#define P_6_cool 2.7		// P6,cool, 	KW, 		potenza di raffreddamento del serbatoito 6; DA CORREGGERE
#define c_p_w 4.182			// c_p,w,		kJ/kgK, 	calore specifico;
#define rho_w 998.0			// rho_w,		kw/m^3,		densita' della soluzione;

#define V_p_6_1 10.8		// V_p6,1,		cm^3/s, 	flusso (in unita' di volume) che attraversa la pompa dal serbatoio 6 all'1;

#define m_vap 2.4			// m_vap,		g/s, 		;
#define lambda_h_vap 2257	// lambda_h_vap,kJ/kg,		entalpia di vaporizzazione specifica;

#define c_lo 3.0			// c_lo,		g/l,		concentrazione DA VERIFICARE: che concentrazione è? non è presente da altre parti se non a pag 4 tra le equazioni e non tra le costanti. Perché?;
#define c_hi 5.0			// c_hi,		g/l,		concentrazione DA VERIFICARE: come sopra;

#define H_1_3 10.7758
#define H_2_3 11.5942
#define H_3_4 8.5106
#define H_4_5 35.6778
#define H_5_7 9.4288

double round_k_digits(double);

/*
 * EQUAZIONI
 *
 * Articolo di riferimento: "A switched continuous model of VHS Case Study 1"
 *
 * Convenzione nomi funzioni:
 * [fase del processo]_[su cosa agisce la funzione]_[nome serbatoio]_[eventuale direzione del flusso]_[nome serbatoio comunicante]
 *
 * */

/* Preparazione della soluzione (fase preliminare)*/

/* Tapwater -> B2 */
double prep_level_b2_in_tapwater(double, int);

/* B2 -> B3 */
double prep_level_b2_out_b3(double, int);
double prep_level_b3_in_b2(double, double, int);

double prep_level_b2_b3(double, int);

/* manual addition of salt in B3 */
double prep_concentration_b3_in_manual();

/* B3 -> B1 */
double prep_level_b1_in_b3(double, int);
double prep_level_b3_out_b1(double, int);

double prep_level_b3_b1(double, int);

/* Processo ciclico */

/* B1 -> B3 */

double cyclic_level_b1_out_b3(double, int);
double cyclic_level_b3_in_b1(double, double, int);

double cyclic_level_b1_b3(double, int);

/* Dilution B2 -> B3 */
double cyclic_level_b2_out_b3(double, int);
double cyclic_level_b3_in_b2(double, double, int);

double cyclic_level_b2_b3(double, int);

double cyclic_concentration_b3_in_b2(double, double, double, double, int);

/* B3 -> B4 */
double cyclic_level_b3_out_b4(double, int);
double cyclic_level_b4_in_b3(double, double, int);

double cyclic_level_b3_b4(double, int);

/* B4 -> B5 */
double cyclic_level_b4_out_b5(double, int);
double cyclic_level_b5_in_b4(double, double, int);

double cyclic_level_b4_b5(double, int);

/* Heating until boiling temperature */

double cyclic_temperature_b5(double, double, int);

/* Evaporation */
double cyclic_level_b5_out_b6(double, int);
double cyclic_level_b6_in_b5(double, int);

double cyclic_level_b5_b6(double, int);

double cyclic_concentration_b5(double, double, int);
double cyclic_temperature_b_5(double, int);

/* B5 -> B7 */
double cyclic_level_b5_out_b7(double, int);
double cyclic_level_b7_in_b5(double, double, int);

double cyclic_level_b5_b7(double, int);

/* Cooling in B7 */
double cyclic_temperature_b7(double, double, int);

/* B7 -> B1 */
double cyclic_level_b7_out_b1(double, int);
double cyclic_level_b1_in_b7(double, int);

double cyclic_level_b7_b1(double, int);

/* Cooling in B6 */
double cyclic_temperature_b6(double, double, int);

/* B6 -> B2 */
double cyclic_level_b6_out_b2(double, int);
double cyclic_level_b2_in_b6(double, int);

double cyclic_level_b6_b2(double, int);

#endif /* HEADER_H_ */
