/******************************
  Program "model_cyclic.m" compiled by "Universal Planner Murphi Release 2.0.R8"

  Murphi Last Compiled date: "Nov 26 2013"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Universal Planner Murphi Release 2.0.R8"
#define MURPHI_DATE "Nov 26 2013"
#define PROTOCOL_NAME "model_cyclic"
#define BITS_IN_WORLD 618
#define HASHC

/********************
  Include
 ********************/
#include "upm_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_interval_time: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_interval_time& val) { return mu__long::operator=((int) val); };
  mu_1_interval_time (const char *name, int os): mu__long(0, 10000, 14, name, os) {};
  mu_1_interval_time (void): mu__long(0, 10000, 14) {};
  mu_1_interval_time (int val): mu__long(0, 10000, 14, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_interval_time mu_1_interval_time_undefined_var;

class mu_1_real_type: public mu__real
{
 public:
  inline double operator=(double val) { return mu__real::operator=(val); };
  inline double operator=(const mu_1_real_type& val) { return mu__real::operator=((double) val); };
  mu_1_real_type (const char *name, int os): mu__real(4,10,32,name, os) {};
  mu_1_real_type (void): mu__real(4,10,32) {};
  mu_1_real_type (double val): mu__real(4,10,32,"Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%le",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of real decl ***/
mu_1_real_type mu_1_real_type_undefined_var;

const double mu_LEVEL_B1_MAX = +2.105000e+01;
const double mu_LEVEL_B2_MAX = +1.578000e+01;
const double mu_LEVEL_B3_MAX = +1.842000e+01;
const double mu_LEVEL_B4_MAX = +3.684000e+01;
const double mu_LEVEL_B5_MAX = +1.842000e+01;
const double mu_LEVEL_B6_MAX = +1.578000e+01;
const double mu_LEVEL_B7_MAX = +2.105000e+01;
const double mu_LEVEL_B5_SAFETY = +8.000000e+00;
const double mu_START_LEVEL_B1 = +1.315000e+01;
const double mu_START_LEVEL_B2 = +1.578000e+01;
const int mu_START_CONCENTRATION_B1 = 5;
const int mu_CONCENTRATION_MAX = 5;
const double mu_CONCENTRATION_TARGET = +3.000000e+00;
const int mu_STEP_TIME = 10;
/*** Variable declaration ***/
mu_0_boolean mu_valve_1("valve_1",0);

/*** Variable declaration ***/
mu_0_boolean mu_valve_2("valve_2",2);

/*** Variable declaration ***/
mu_0_boolean mu_valve_3("valve_3",4);

/*** Variable declaration ***/
mu_0_boolean mu_valve_4("valve_4",6);

/*** Variable declaration ***/
mu_0_boolean mu_valve_5("valve_5",8);

/*** Variable declaration ***/
mu_0_boolean mu_valve_6("valve_6",10);

/*** Variable declaration ***/
mu_0_boolean mu_valve_7("valve_7",12);

/*** Variable declaration ***/
mu_0_boolean mu_valve_8("valve_8",14);

/*** Variable declaration ***/
mu_0_boolean mu_valve_9("valve_9",16);

/*** Variable declaration ***/
mu_0_boolean mu_valve_10("valve_10",18);

/*** Variable declaration ***/
mu_0_boolean mu_valve_11("valve_11",20);

/*** Variable declaration ***/
mu_0_boolean mu_valve_12("valve_12",22);

/*** Variable declaration ***/
mu_0_boolean mu_valve_13("valve_13",24);

/*** Variable declaration ***/
mu_0_boolean mu_valve_14("valve_14",26);

/*** Variable declaration ***/
mu_0_boolean mu_valve_15("valve_15",28);

/*** Variable declaration ***/
mu_0_boolean mu_valve_16("valve_16",30);

/*** Variable declaration ***/
mu_0_boolean mu_valve_17("valve_17",32);

/*** Variable declaration ***/
mu_0_boolean mu_valve_18("valve_18",34);

/*** Variable declaration ***/
mu_0_boolean mu_valve_19("valve_19",36);

/*** Variable declaration ***/
mu_0_boolean mu_valve_20("valve_20",38);

/*** Variable declaration ***/
mu_0_boolean mu_valve_21("valve_21",40);

/*** Variable declaration ***/
mu_0_boolean mu_valve_22("valve_22",42);

/*** Variable declaration ***/
mu_0_boolean mu_valve_23("valve_23",44);

/*** Variable declaration ***/
mu_0_boolean mu_valve_24("valve_24",46);

/*** Variable declaration ***/
mu_0_boolean mu_valve_25("valve_25",48);

/*** Variable declaration ***/
mu_0_boolean mu_valve_26("valve_26",50);

/*** Variable declaration ***/
mu_0_boolean mu_valve_27("valve_27",52);

/*** Variable declaration ***/
mu_0_boolean mu_valve_28("valve_28",54);

/*** Variable declaration ***/
mu_0_boolean mu_valve_29("valve_29",56);

/*** Variable declaration ***/
mu_1_real_type mu_LEVEL_TARGET("LEVEL_TARGET",58);

/*** Variable declaration ***/
mu_0_boolean mu_pump_1("pump_1",90);

/*** Variable declaration ***/
mu_0_boolean mu_pump_2("pump_2",92);

/*** Variable declaration ***/
mu_0_boolean mu_heater_5("heater_5",94);

/*** Variable declaration ***/
mu_1_real_type mu_c_1("c_1",96);

/*** Variable declaration ***/
mu_1_real_type mu_c_2("c_2",128);

/*** Variable declaration ***/
mu_1_real_type mu_c_3("c_3",160);

/*** Variable declaration ***/
mu_1_real_type mu_c_5("c_5",192);

/*** Variable declaration ***/
mu_1_real_type mu_T_5("T_5",224);

/*** Variable declaration ***/
mu_1_real_type mu_T_6("T_6",256);

/*** Variable declaration ***/
mu_1_real_type mu_T_7("T_7",288);

/*** Variable declaration ***/
mu_1_real_type mu_level_b1("level_b1",320);

/*** Variable declaration ***/
mu_1_real_type mu_level_b2("level_b2",352);

/*** Variable declaration ***/
mu_1_real_type mu_level_b3("level_b3",384);

/*** Variable declaration ***/
mu_1_real_type mu_level_b3_recycle("level_b3_recycle",416);

/*** Variable declaration ***/
mu_1_real_type mu_level_b4("level_b4",448);

/*** Variable declaration ***/
mu_1_real_type mu_level_b5("level_b5",480);

/*** Variable declaration ***/
mu_1_real_type mu_level_b6("level_b6",512);

/*** Variable declaration ***/
mu_1_real_type mu_level_b7("level_b7",544);

/*** Variable declaration ***/
mu_1_interval_time mu_time("time",576);

/*** Variable declaration ***/
mu_0_boolean mu_isGoal_part("isGoal_part",590);

/*** Variable declaration ***/
mu_0_boolean mu_isGoal_final("isGoal_final",592);

/*** Variable declaration ***/
mu_0_boolean mu_systemProperties("systemProperties",594);

/*** Variable declaration ***/
mu_0_boolean mu_filling_b3_done("filling_b3_done",596);

/*** Variable declaration ***/
mu_0_boolean mu_concentration_reached("concentration_reached",598);

/*** Variable declaration ***/
mu_0_boolean mu_get_production_done("get_production_done",600);

/*** Variable declaration ***/
mu_0_boolean mu_filling_b4_done("filling_b4_done",602);

/*** Variable declaration ***/
mu_0_boolean mu_filling_b5_done("filling_b5_done",604);

/*** Variable declaration ***/
mu_0_boolean mu_high_concentration_reached("high_concentration_reached",606);

/*** Variable declaration ***/
mu_0_boolean mu_filling_b7_done("filling_b7_done",608);

/*** Variable declaration ***/
mu_0_boolean mu_filling_b1_done("filling_b1_done",610);

/*** Variable declaration ***/
mu_0_boolean mu_filling_b2_done("filling_b2_done",612);

/*** Variable declaration ***/
mu_0_boolean mu_cooled_b6("cooled_b6",614);

/*** Variable declaration ***/
mu_0_boolean mu_cooled_b7("cooled_b7",616);


#include "equations.c"

void mu_heater_5_failure()
{
bool mu__boolexpr0;
bool mu__boolexpr1;
  if (!((mu_heater_5) == (mu_true))) mu__boolexpr1 = FALSE ;
  else {
bool mu__boolexpr2;
bool mu__boolexpr3;
  if (!((mu_valve_12) == (mu_false))) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr3)) mu__boolexpr2 = FALSE ;
  else {
  mu__boolexpr2 = ((mu_valve_16) == (mu_false)) ; 
}
  mu__boolexpr1 = (!(mu__boolexpr2)) ; 
}
  if (mu__boolexpr1) mu__boolexpr0 = TRUE ;
  else {
bool mu__boolexpr4;
  if (!((mu_heater_5) == (mu_true))) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = (!((mu_valve_13) == (mu_true))) ; 
}
  mu__boolexpr0 = (mu__boolexpr4) ; 
}
if ( mu__boolexpr0 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_cooling_failure()
{
bool mu__boolexpr5;
bool mu__boolexpr6;
  if (!((mu_valve_13) == (mu_true))) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = ((mu_valve_17) == (mu_true)) ; 
}
  if (!(mu__boolexpr6)) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = ((mu_valve_29) == (mu_true)) ; 
}
if ( mu__boolexpr5 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_flow_b1_failure()
{
bool mu__boolexpr7;
  if (!((mu_valve_3) == (mu_true))) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_valve_8) == (mu_true)) ; 
}
if ( mu__boolexpr7 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_flow_b2_failure()
{
bool mu__boolexpr8;
bool mu__boolexpr9;
  if ((mu_valve_6) == (mu_true)) mu__boolexpr9 = TRUE ;
  else {
  mu__boolexpr9 = ((mu_valve_7) == (mu_true)) ; 
}
  if (!(mu__boolexpr9)) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_valve_9) == (mu_true)) ; 
}
if ( mu__boolexpr8 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_flow_b3_failure()
{
bool mu__boolexpr10;
bool mu__boolexpr11;
  if ((mu_valve_8) == (mu_true)) mu__boolexpr11 = TRUE ;
  else {
  mu__boolexpr11 = ((mu_valve_9) == (mu_true)) ; 
}
  if (!(mu__boolexpr11)) mu__boolexpr10 = FALSE ;
  else {
bool mu__boolexpr12;
  if ((mu_valve_10) == (mu_true)) mu__boolexpr12 = TRUE ;
  else {
  mu__boolexpr12 = ((mu_valve_11) == (mu_true)) ; 
}
  mu__boolexpr10 = (mu__boolexpr12) ; 
}
if ( mu__boolexpr10 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_flow_b4_failure()
{
bool mu__boolexpr13;
  if (!((mu_valve_11) == (mu_true))) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_valve_12) == (mu_true)) ; 
}
if ( mu__boolexpr13 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_flow_b5_failure()
{
bool mu__boolexpr14;
  if (!((mu_valve_12) == (mu_true))) mu__boolexpr14 = FALSE ;
  else {
bool mu__boolexpr15;
  if ((mu_valve_15) == (mu_true)) mu__boolexpr15 = TRUE ;
  else {
  mu__boolexpr15 = ((mu_valve_16) == (mu_true)) ; 
}
  mu__boolexpr14 = (mu__boolexpr15) ; 
}
if ( mu__boolexpr14 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_flow_b6_failure()
{
bool mu__boolexpr16;
bool mu__boolexpr17;
  if (!(mu_valve_13)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_valve_14) == (mu_true)) ; 
}
  if (!(mu__boolexpr17)) mu__boolexpr16 = FALSE ;
  else {
bool mu__boolexpr18;
bool mu__boolexpr19;
  if ((mu_valve_19) == (mu_true)) mu__boolexpr19 = TRUE ;
  else {
  mu__boolexpr19 = ((mu_valve_20) == (mu_true)) ; 
}
  if (mu__boolexpr19) mu__boolexpr18 = TRUE ;
  else {
  mu__boolexpr18 = ((mu_valve_27) == (mu_true)) ; 
}
  mu__boolexpr16 = (mu__boolexpr18) ; 
}
if ( mu__boolexpr16 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_flow_b7_failure()
{
bool mu__boolexpr20;
  if (!((mu_valve_15) == (mu_true))) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_valve_18) == (mu_true)) ; 
}
if ( mu__boolexpr20 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_level_b1_failure()
{
bool mu__boolexpr21;
  if ((mu_level_b1) < (0)) mu__boolexpr21 = TRUE ;
  else {
  mu__boolexpr21 = ((mu_level_b1) > (mu_LEVEL_B1_MAX)) ; 
}
if ( mu__boolexpr21 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_level_b2_failure()
{
bool mu__boolexpr22;
  if ((mu_level_b2) < (0)) mu__boolexpr22 = TRUE ;
  else {
  mu__boolexpr22 = ((mu_level_b2) > (mu_LEVEL_B2_MAX)) ; 
}
if ( mu__boolexpr22 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_level_b3_failure()
{
bool mu__boolexpr23;
  if ((mu_level_b3) < (0)) mu__boolexpr23 = TRUE ;
  else {
  mu__boolexpr23 = ((mu_level_b3) > (mu_LEVEL_B3_MAX)) ; 
}
if ( mu__boolexpr23 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_level_b4_failure()
{
bool mu__boolexpr24;
  if ((mu_level_b4) < (0)) mu__boolexpr24 = TRUE ;
  else {
  mu__boolexpr24 = ((mu_level_b4) > (mu_LEVEL_B4_MAX)) ; 
}
if ( mu__boolexpr24 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_level_b5_failure()
{
bool mu__boolexpr25;
  if ((mu_level_b5) < (0)) mu__boolexpr25 = TRUE ;
  else {
  mu__boolexpr25 = ((mu_level_b5) > (mu_LEVEL_B5_MAX)) ; 
}
if ( mu__boolexpr25 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_level_b6_failure()
{
bool mu__boolexpr26;
  if ((mu_level_b6) < (0)) mu__boolexpr26 = TRUE ;
  else {
  mu__boolexpr26 = ((mu_level_b6) > (mu_LEVEL_B6_MAX)) ; 
}
if ( mu__boolexpr26 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_level_b7_failure()
{
bool mu__boolexpr27;
  if ((mu_level_b7) < (0)) mu__boolexpr27 = TRUE ;
  else {
  mu__boolexpr27 = ((mu_level_b7) > (mu_LEVEL_B7_MAX)) ; 
}
if ( mu__boolexpr27 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_pump_1_failure()
{
bool mu__boolexpr28;
  if (!((mu_pump_1) == (mu_true))) mu__boolexpr28 = FALSE ;
  else {
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
bool mu__boolexpr32;
bool mu__boolexpr33;
bool mu__boolexpr34;
bool mu__boolexpr35;
  if (!((mu_valve_22) == (mu_true))) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_valve_26) == (mu_true)) ; 
}
  if (mu__boolexpr35) mu__boolexpr34 = TRUE ;
  else {
bool mu__boolexpr36;
bool mu__boolexpr37;
  if (!((mu_valve_22) == (mu_true))) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_valve_3) == (mu_true)) ; 
}
  mu__boolexpr34 = (mu__boolexpr36) ; 
}
  if (mu__boolexpr34) mu__boolexpr33 = TRUE ;
  else {
bool mu__boolexpr38;
bool mu__boolexpr39;
bool mu__boolexpr40;
bool mu__boolexpr41;
  if (!((mu_valve_10) == (mu_true))) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr39)) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_valve_3) == (mu_true)) ; 
}
  mu__boolexpr33 = (mu__boolexpr38) ; 
}
  if (mu__boolexpr33) mu__boolexpr32 = TRUE ;
  else {
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
bool mu__boolexpr45;
bool mu__boolexpr46;
bool mu__boolexpr47;
bool mu__boolexpr48;
  if (!((mu_valve_20) == (mu_true))) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_valve_21) == (mu_true)) ; 
}
  if (!(mu__boolexpr48)) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr47)) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr45)) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_valve_2) == (mu_true)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_valve_4) == (mu_true)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_valve_6) == (mu_true)) ; 
}
  mu__boolexpr32 = (mu__boolexpr42) ; 
}
  if (mu__boolexpr32) mu__boolexpr31 = TRUE ;
  else {
bool mu__boolexpr49;
bool mu__boolexpr50;
bool mu__boolexpr51;
bool mu__boolexpr52;
  if (!((mu_valve_18) == (mu_true))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_valve_3) == (mu_true)) ; 
}
  mu__boolexpr31 = (mu__boolexpr49) ; 
}
  if (mu__boolexpr31) mu__boolexpr30 = TRUE ;
  else {
bool mu__boolexpr53;
bool mu__boolexpr54;
bool mu__boolexpr55;
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
bool mu__boolexpr59;
  if (!((mu_valve_10) == (mu_true))) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr59)) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr57)) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_valve_2) == (mu_true)) ; 
}
  if (!(mu__boolexpr56)) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_valve_4) == (mu_true)) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_valve_28) == (mu_true)) ; 
}
  mu__boolexpr30 = (mu__boolexpr53) ; 
}
  if (mu__boolexpr30) mu__boolexpr29 = TRUE ;
  else {
bool mu__boolexpr60;
bool mu__boolexpr61;
bool mu__boolexpr62;
bool mu__boolexpr63;
bool mu__boolexpr64;
bool mu__boolexpr65;
bool mu__boolexpr66;
  if (!((mu_valve_19) == (mu_true))) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr65)) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr64)) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_valve_2) == (mu_true)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_valve_4) == (mu_true)) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_valve_28) == (mu_true)) ; 
}
  mu__boolexpr29 = (mu__boolexpr60) ; 
}
  mu__boolexpr28 = (!(mu__boolexpr29)) ; 
}
if ( mu__boolexpr28 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_pump_2_failure()
{
bool mu__boolexpr67;
  if (!((mu_pump_2) == (mu_true))) mu__boolexpr67 = FALSE ;
  else {
bool mu__boolexpr68;
bool mu__boolexpr69;
bool mu__boolexpr70;
  if (!((mu_valve_25) == (mu_true))) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = ((mu_valve_28) == (mu_true)) ; 
}
  if (mu__boolexpr70) mu__boolexpr69 = TRUE ;
  else {
bool mu__boolexpr71;
bool mu__boolexpr72;
  if (!((mu_valve_25) == (mu_true))) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr72)) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = ((mu_valve_6) == (mu_true)) ; 
}
  mu__boolexpr69 = (mu__boolexpr71) ; 
}
  if (mu__boolexpr69) mu__boolexpr68 = TRUE ;
  else {
bool mu__boolexpr73;
bool mu__boolexpr74;
bool mu__boolexpr75;
bool mu__boolexpr76;
bool mu__boolexpr77;
  if (!((mu_valve_25) == (mu_true))) mu__boolexpr77 = FALSE ;
  else {
  mu__boolexpr77 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr77)) mu__boolexpr76 = FALSE ;
  else {
  mu__boolexpr76 = ((mu_valve_4) == (mu_true)) ; 
}
  if (!(mu__boolexpr76)) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_valve_2) == (mu_true)) ; 
}
  if (!(mu__boolexpr75)) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr74)) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = ((mu_valve_3) == (mu_true)) ; 
}
  mu__boolexpr68 = (mu__boolexpr73) ; 
}
  mu__boolexpr67 = (!(mu__boolexpr68)) ; 
}
if ( mu__boolexpr67 )
{
mu_systemProperties = mu_false;
}
};
/*** end procedure declaration ***/

void mu_dynamic_check()
{
mu_heater_5_failure (  );
mu_cooling_failure (  );
mu_flow_b1_failure (  );
mu_flow_b2_failure (  );
mu_flow_b3_failure (  );
mu_flow_b4_failure (  );
mu_flow_b5_failure (  );
mu_flow_b6_failure (  );
mu_flow_b7_failure (  );
mu_level_b1_failure (  );
mu_level_b2_failure (  );
mu_level_b3_failure (  );
mu_level_b4_failure (  );
mu_level_b5_failure (  );
mu_level_b6_failure (  );
mu_level_b7_failure (  );
mu_pump_1_failure (  );
mu_pump_2_failure (  );
};
/*** end procedure declaration ***/

mu_0_boolean mu_IsSafety()
{
bool mu__boolexpr78;
bool mu__boolexpr79;
bool mu__boolexpr80;
bool mu__boolexpr81;
bool mu__boolexpr82;
bool mu__boolexpr83;
bool mu__boolexpr84;
bool mu__boolexpr85;
bool mu__boolexpr86;
bool mu__boolexpr87;
bool mu__boolexpr88;
bool mu__boolexpr89;
bool mu__boolexpr90;
bool mu__boolexpr91;
bool mu__boolexpr92;
bool mu__boolexpr93;
bool mu__boolexpr94;
bool mu__boolexpr95;
bool mu__boolexpr96;
bool mu__boolexpr97;
bool mu__boolexpr98;
bool mu__boolexpr99;
bool mu__boolexpr100;
bool mu__boolexpr101;
bool mu__boolexpr102;
bool mu__boolexpr103;
bool mu__boolexpr104;
bool mu__boolexpr105;
bool mu__boolexpr106;
bool mu__boolexpr107;
  if (!((mu_valve_1) == (mu_false))) mu__boolexpr107 = FALSE ;
  else {
  mu__boolexpr107 = ((mu_valve_2) == (mu_false)) ; 
}
  if (!(mu__boolexpr107)) mu__boolexpr106 = FALSE ;
  else {
  mu__boolexpr106 = ((mu_valve_3) == (mu_false)) ; 
}
  if (!(mu__boolexpr106)) mu__boolexpr105 = FALSE ;
  else {
  mu__boolexpr105 = ((mu_valve_4) == (mu_false)) ; 
}
  if (!(mu__boolexpr105)) mu__boolexpr104 = FALSE ;
  else {
  mu__boolexpr104 = ((mu_valve_5) == (mu_false)) ; 
}
  if (!(mu__boolexpr104)) mu__boolexpr103 = FALSE ;
  else {
  mu__boolexpr103 = ((mu_valve_6) == (mu_false)) ; 
}
  if (!(mu__boolexpr103)) mu__boolexpr102 = FALSE ;
  else {
  mu__boolexpr102 = ((mu_valve_7) == (mu_false)) ; 
}
  if (!(mu__boolexpr102)) mu__boolexpr101 = FALSE ;
  else {
  mu__boolexpr101 = ((mu_valve_8) == (mu_false)) ; 
}
  if (!(mu__boolexpr101)) mu__boolexpr100 = FALSE ;
  else {
  mu__boolexpr100 = ((mu_valve_9) == (mu_false)) ; 
}
  if (!(mu__boolexpr100)) mu__boolexpr99 = FALSE ;
  else {
  mu__boolexpr99 = ((mu_valve_10) == (mu_false)) ; 
}
  if (!(mu__boolexpr99)) mu__boolexpr98 = FALSE ;
  else {
  mu__boolexpr98 = ((mu_valve_11) == (mu_false)) ; 
}
  if (!(mu__boolexpr98)) mu__boolexpr97 = FALSE ;
  else {
  mu__boolexpr97 = ((mu_valve_12) == (mu_false)) ; 
}
  if (!(mu__boolexpr97)) mu__boolexpr96 = FALSE ;
  else {
  mu__boolexpr96 = ((mu_valve_13) == (mu_false)) ; 
}
  if (!(mu__boolexpr96)) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = ((mu_valve_14) == (mu_false)) ; 
}
  if (!(mu__boolexpr95)) mu__boolexpr94 = FALSE ;
  else {
  mu__boolexpr94 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr94)) mu__boolexpr93 = FALSE ;
  else {
  mu__boolexpr93 = ((mu_valve_16) == (mu_false)) ; 
}
  if (!(mu__boolexpr93)) mu__boolexpr92 = FALSE ;
  else {
  mu__boolexpr92 = ((mu_valve_17) == (mu_false)) ; 
}
  if (!(mu__boolexpr92)) mu__boolexpr91 = FALSE ;
  else {
  mu__boolexpr91 = ((mu_valve_18) == (mu_false)) ; 
}
  if (!(mu__boolexpr91)) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = ((mu_valve_19) == (mu_false)) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = FALSE ;
  else {
  mu__boolexpr89 = ((mu_valve_20) == (mu_false)) ; 
}
  if (!(mu__boolexpr89)) mu__boolexpr88 = FALSE ;
  else {
  mu__boolexpr88 = ((mu_valve_21) == (mu_false)) ; 
}
  if (!(mu__boolexpr88)) mu__boolexpr87 = FALSE ;
  else {
  mu__boolexpr87 = ((mu_valve_22) == (mu_false)) ; 
}
  if (!(mu__boolexpr87)) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = ((mu_valve_23) == (mu_false)) ; 
}
  if (!(mu__boolexpr86)) mu__boolexpr85 = FALSE ;
  else {
  mu__boolexpr85 = ((mu_valve_24) == (mu_false)) ; 
}
  if (!(mu__boolexpr85)) mu__boolexpr84 = FALSE ;
  else {
  mu__boolexpr84 = ((mu_valve_25) == (mu_false)) ; 
}
  if (!(mu__boolexpr84)) mu__boolexpr83 = FALSE ;
  else {
  mu__boolexpr83 = ((mu_valve_26) == (mu_false)) ; 
}
  if (!(mu__boolexpr83)) mu__boolexpr82 = FALSE ;
  else {
  mu__boolexpr82 = ((mu_valve_27) == (mu_false)) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = ((mu_valve_28) == (mu_false)) ; 
}
  if (!(mu__boolexpr81)) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_valve_29) == (mu_false)) ; 
}
  if (!(mu__boolexpr80)) mu__boolexpr79 = FALSE ;
  else {
  mu__boolexpr79 = ((mu_pump_1) == (mu_false)) ; 
}
  if (!(mu__boolexpr79)) mu__boolexpr78 = FALSE ;
  else {
  mu__boolexpr78 = ((mu_pump_2) == (mu_false)) ; 
}
return mu__boolexpr78;
	Error.Error("The end of function IsSafety reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_IsOK()
{
if ( (mu_systemProperties) == (mu_false) )
{
return mu_false;
}
bool mu__boolexpr108;
bool mu__boolexpr109;
bool mu__boolexpr110;
bool mu__boolexpr111;
  if (!((mu_filling_b1_done) == (mu_true))) mu__boolexpr111 = FALSE ;
  else {
  mu__boolexpr111 = ((mu_filling_b2_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr111)) mu__boolexpr110 = FALSE ;
  else {
  mu__boolexpr110 = ((mu_concentration_reached) == (mu_true)) ; 
}
  if (!(mu__boolexpr110)) mu__boolexpr109 = FALSE ;
  else {
  mu__boolexpr109 = ((mu_isGoal_part) == (mu_true)) ; 
}
  if (!(mu__boolexpr109)) mu__boolexpr108 = FALSE ;
  else {
  mu__boolexpr108 = (mu_IsSafety(  )) ; 
}
if ( mu__boolexpr108 )
{
mu_isGoal_final = mu_true;
return mu_false;
}
else
{
bool mu__boolexpr112;
bool mu__boolexpr113;
bool mu__boolexpr114;
bool mu__boolexpr115;
  if (!((mu_concentration_reached) == (mu_true))) mu__boolexpr115 = FALSE ;
  else {
  mu__boolexpr115 = ((mu_filling_b3_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr115)) mu__boolexpr114 = FALSE ;
  else {
  mu__boolexpr114 = ((mu_valve_11) == (mu_false)) ; 
}
  if (!(mu__boolexpr114)) mu__boolexpr113 = FALSE ;
  else {
  mu__boolexpr113 = ((mu_filling_b4_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr113)) mu__boolexpr112 = FALSE ;
  else {
  mu__boolexpr112 = ((mu_level_b3) < (mu_LEVEL_TARGET)) ; 
}
if ( mu__boolexpr112 )
{
return mu_false;
}
else
{
bool mu__boolexpr116;
bool mu__boolexpr117;
bool mu__boolexpr118;
bool mu__boolexpr119;
  if (!((mu_concentration_reached) == (mu_true))) mu__boolexpr119 = FALSE ;
  else {
  mu__boolexpr119 = ((mu_filling_b3_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr119)) mu__boolexpr118 = FALSE ;
  else {
  mu__boolexpr118 = ((mu_valve_11) == (mu_false)) ; 
}
  if (!(mu__boolexpr118)) mu__boolexpr117 = FALSE ;
  else {
  mu__boolexpr117 = ((mu_filling_b4_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr117)) mu__boolexpr116 = FALSE ;
  else {
  mu__boolexpr116 = ((mu_level_b3) >= (mu_LEVEL_TARGET)) ; 
}
if ( mu__boolexpr116 )
{
mu_isGoal_part = mu_true;
}
return mu_true;
}
}
	Error.Error("The end of function IsOK reached without returning values.");
};
/*** end function declaration ***/

void mu_compute_new_state()
{
/*** Variable declaration ***/
mu_1_real_type mu_temp_c_1("temp_c_1",0);

/*** Variable declaration ***/
mu_1_real_type mu_temp_c_2("temp_c_2",32);

/*** Variable declaration ***/
mu_1_real_type mu_temp_c_3("temp_c_3",64);

/*** Variable declaration ***/
mu_1_real_type mu_temp_c_5("temp_c_5",96);

/*** Variable declaration ***/
mu_1_real_type mu_temp_T_5("temp_T_5",128);

/*** Variable declaration ***/
mu_1_real_type mu_temp_T_6("temp_T_6",160);

/*** Variable declaration ***/
mu_1_real_type mu_temp_T_7("temp_T_7",192);

/*** Variable declaration ***/
mu_1_real_type mu_temp_level_b1("temp_level_b1",224);

/*** Variable declaration ***/
mu_1_real_type mu_temp_level_b2("temp_level_b2",256);

/*** Variable declaration ***/
mu_1_real_type mu_temp_level_b3("temp_level_b3",288);

/*** Variable declaration ***/
mu_1_real_type mu_temp_level_b4("temp_level_b4",320);

/*** Variable declaration ***/
mu_1_real_type mu_temp_level_b5("temp_level_b5",352);

/*** Variable declaration ***/
mu_1_real_type mu_temp_level_b6("temp_level_b6",384);

/*** Variable declaration ***/
mu_1_real_type mu_temp_level_b7("temp_level_b7",416);

/*** Variable declaration ***/
mu_1_real_type mu_temp_flow("temp_flow",448);

if (mu_level_b1.isundefined())
  mu_temp_level_b1.undefine();
else
  mu_temp_level_b1 = mu_level_b1;
if (mu_level_b2.isundefined())
  mu_temp_level_b2.undefine();
else
  mu_temp_level_b2 = mu_level_b2;
if (mu_level_b3.isundefined())
  mu_temp_level_b3.undefine();
else
  mu_temp_level_b3 = mu_level_b3;
if (mu_level_b4.isundefined())
  mu_temp_level_b4.undefine();
else
  mu_temp_level_b4 = mu_level_b4;
if (mu_level_b5.isundefined())
  mu_temp_level_b5.undefine();
else
  mu_temp_level_b5 = mu_level_b5;
if (mu_level_b6.isundefined())
  mu_temp_level_b6.undefine();
else
  mu_temp_level_b6 = mu_level_b6;
if (mu_level_b7.isundefined())
  mu_temp_level_b7.undefine();
else
  mu_temp_level_b7 = mu_level_b7;
if (mu_c_1.isundefined())
  mu_temp_c_1.undefine();
else
  mu_temp_c_1 = mu_c_1;
if (mu_c_2.isundefined())
  mu_temp_c_2.undefine();
else
  mu_temp_c_2 = mu_c_2;
if (mu_c_3.isundefined())
  mu_temp_c_3.undefine();
else
  mu_temp_c_3 = mu_c_3;
if (mu_c_5.isundefined())
  mu_temp_c_5.undefine();
else
  mu_temp_c_5 = mu_c_5;
if (mu_T_5.isundefined())
  mu_temp_T_5.undefine();
else
  mu_temp_T_5 = mu_T_5;
if (mu_T_6.isundefined())
  mu_temp_T_6.undefine();
else
  mu_temp_T_6 = mu_T_6;
if (mu_T_7.isundefined())
  mu_temp_T_7.undefine();
else
  mu_temp_T_7 = mu_T_7;
mu_temp_flow = 0;
if ( (mu_valve_8) == (mu_true) )
{
mu_temp_flow = cyclic_level_b1_b3( mu_level_b1, mu_STEP_TIME );
if ( (mu_temp_flow) >= (mu_level_b1) )
{
mu_temp_level_b1 = 0;
mu_temp_level_b3 = (mu_level_b3) + (mu_level_b1);
}
else
{
mu_temp_level_b1 = (mu_level_b1) - (mu_temp_flow);
mu_temp_level_b3 = (mu_level_b3) + (mu_temp_flow);
}
if (mu_c_1.isundefined())
  mu_temp_c_3.undefine();
else
  mu_temp_c_3 = mu_c_1;
}
if ( (mu_valve_9) == (mu_true) )
{
mu_temp_flow = cyclic_level_b2_b3( mu_level_b2, mu_STEP_TIME );
if ( (mu_temp_flow) >= (mu_level_b2) )
{
mu_temp_level_b2 = 0;
mu_temp_level_b3 = (mu_level_b3) + (mu_level_b2);
}
else
{
mu_temp_level_b2 = (mu_level_b2) - (mu_temp_flow);
mu_temp_level_b3 = (mu_level_b3) + (mu_temp_flow);
}
mu_temp_c_3 = cyclic_concentration_b3_in_b2( mu_c_3, mu_c_2, mu_level_b2, mu_level_b2, mu_STEP_TIME );
}
bool mu__boolexpr120;
bool mu__boolexpr121;
  if (!((mu_valve_10) == (mu_true))) mu__boolexpr121 = FALSE ;
  else {
  mu__boolexpr121 = ((mu_valve_19) == (mu_true)) ; 
}
  if (!(mu__boolexpr121)) mu__boolexpr120 = FALSE ;
  else {
  mu__boolexpr120 = (mu_valve_27) ; 
}
if ( mu__boolexpr120 )
{
mu_temp_flow = 2.000000e+00;
if ( (mu_temp_flow) >= (mu_level_b3) )
{
mu_temp_level_b3 = 0;
}
else
{
mu_temp_level_b3 = (mu_level_b3) - (mu_temp_flow);
}
}
if ( (mu_valve_11) == (mu_true) )
{
mu_temp_flow = cyclic_level_b3_b4( mu_level_b3, mu_STEP_TIME );
if ( (mu_temp_flow) >= (mu_level_b3) )
{
mu_temp_level_b3 = 0;
mu_temp_level_b4 = (mu_level_b4) + (mu_level_b3);
}
else
{
mu_temp_level_b3 = (mu_level_b3) - (mu_temp_flow);
mu_temp_level_b4 = (mu_level_b4) + (mu_temp_flow);
}
}
if ( (mu_valve_12) == (mu_true) )
{
mu_temp_flow = cyclic_level_b4_b5( mu_level_b4, mu_STEP_TIME );
if ( (mu_temp_flow) >= (mu_level_b4) )
{
mu_temp_level_b4 = 0;
mu_temp_level_b5 = (mu_level_b5) + (mu_level_b4);
}
else
{
mu_temp_level_b4 = (mu_level_b4) - (mu_temp_flow);
mu_temp_level_b5 = (mu_level_b5) + (mu_temp_flow);
}
}
if ( (mu_valve_15) == (mu_true) )
{
if (mu_T_5.isundefined())
  mu_temp_T_7.undefine();
else
  mu_temp_T_7 = mu_T_5;
mu_temp_flow = cyclic_level_b5_b7( mu_level_b5, mu_STEP_TIME );
if ( (mu_temp_flow) >= (mu_level_b5) )
{
mu_temp_level_b5 = 0;
mu_temp_level_b7 = (mu_level_b7) + (mu_level_b5);
}
else
{
mu_temp_level_b5 = (mu_level_b5) - (mu_temp_flow);
mu_temp_level_b7 = (mu_level_b7) + (mu_temp_flow);
}
}
bool mu__boolexpr122;
  if (!((mu_heater_5) == (mu_true))) mu__boolexpr122 = FALSE ;
  else {
  mu__boolexpr122 = ((mu_T_5) < (1.000000e+02)) ; 
}
if ( mu__boolexpr122 )
{
mu_temp_T_5 = cyclic_temperature_b5( mu_T_5, mu_level_b5, mu_STEP_TIME );
}
bool mu__boolexpr123;
  if (!((mu_T_5) >= (1.000000e+02))) mu__boolexpr123 = FALSE ;
  else {
  mu__boolexpr123 = ((mu_heater_5) == (mu_true)) ; 
}
if ( mu__boolexpr123 )
{
mu_temp_level_b5 = cyclic_level_b5_out_b6( mu_level_b5, mu_STEP_TIME );
mu_temp_level_b6 = cyclic_level_b6_in_b5( mu_level_b6, mu_STEP_TIME );
mu_temp_c_5 = cyclic_concentration_b5( mu_c_5, mu_level_b5, mu_STEP_TIME );
}
bool mu__boolexpr124;
  if (!((mu_T_5) >= (100))) mu__boolexpr124 = FALSE ;
  else {
  mu__boolexpr124 = ((mu_heater_5) == (mu_true)) ; 
}
if ( mu__boolexpr124 )
{
mu_temp_T_5 = cyclic_temperature_b_5( mu_T_5, mu_STEP_TIME );
}
bool mu__boolexpr125;
bool mu__boolexpr126;
bool mu__boolexpr127;
bool mu__boolexpr128;
bool mu__boolexpr129;
  if (!((mu_pump_1) == (mu_true))) mu__boolexpr129 = FALSE ;
  else {
  mu__boolexpr129 = ((mu_valve_18) == (mu_true)) ; 
}
  if (!(mu__boolexpr129)) mu__boolexpr128 = FALSE ;
  else {
  mu__boolexpr128 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr128)) mu__boolexpr127 = FALSE ;
  else {
  mu__boolexpr127 = (mu_valve_22) ; 
}
  if (!(mu__boolexpr127)) mu__boolexpr126 = FALSE ;
  else {
  mu__boolexpr126 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr126)) mu__boolexpr125 = FALSE ;
  else {
  mu__boolexpr125 = ((mu_valve_3) == (mu_true)) ; 
}
if ( mu__boolexpr125 )
{
mu_temp_flow = cyclic_level_b7_b1( mu_level_b7, mu_STEP_TIME );
if ( (mu_temp_flow) >= (mu_level_b7) )
{
mu_temp_level_b7 = 0;
mu_temp_level_b1 = (mu_level_b1) + (mu_level_b7);
}
else
{
mu_temp_level_b7 = (mu_level_b7) - (mu_temp_flow);
mu_temp_level_b1 = (mu_level_b1) + (mu_temp_flow);
}
}
bool mu__boolexpr130;
bool mu__boolexpr131;
bool mu__boolexpr132;
bool mu__boolexpr133;
bool mu__boolexpr134;
  if (!((mu_pump_2) == (mu_true))) mu__boolexpr134 = FALSE ;
  else {
  mu__boolexpr134 = ((mu_valve_20) == (mu_true)) ; 
}
  if (!(mu__boolexpr134)) mu__boolexpr133 = FALSE ;
  else {
  mu__boolexpr133 = ((mu_valve_24) == (mu_true)) ; 
}
  if (!(mu__boolexpr133)) mu__boolexpr132 = FALSE ;
  else {
  mu__boolexpr132 = ((mu_valve_25) == (mu_true)) ; 
}
  if (!(mu__boolexpr132)) mu__boolexpr131 = FALSE ;
  else {
  mu__boolexpr131 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr131)) mu__boolexpr130 = FALSE ;
  else {
  mu__boolexpr130 = ((mu_valve_6) == (mu_true)) ; 
}
if ( mu__boolexpr130 )
{
mu_temp_flow = cyclic_level_b6_b2( mu_level_b6, mu_STEP_TIME );
if ( (mu_temp_flow) >= (mu_level_b6) )
{
mu_temp_level_b6 = 0;
mu_temp_level_b2 = (mu_level_b2) + (mu_level_b6);
}
else
{
mu_temp_level_b6 = (mu_level_b6) - (mu_temp_flow);
mu_temp_level_b2 = (mu_level_b2) + (mu_temp_flow);
}
}
if ( (mu_valve_29) == (mu_true) )
{
mu_temp_T_6 = cyclic_temperature_b6( mu_T_6, mu_level_b6, mu_STEP_TIME );
}
if ( (mu_valve_17) == (mu_true) )
{
mu_temp_T_7 = cyclic_temperature_b7( mu_T_7, mu_level_b7, mu_STEP_TIME );
}
if ( mu_IsOK(  ) )
{
if (mu_temp_level_b1.isundefined())
  mu_level_b1.undefine();
else
  mu_level_b1 = mu_temp_level_b1;
if (mu_temp_level_b2.isundefined())
  mu_level_b2.undefine();
else
  mu_level_b2 = mu_temp_level_b2;
if (mu_temp_level_b3.isundefined())
  mu_level_b3.undefine();
else
  mu_level_b3 = mu_temp_level_b3;
if (mu_temp_level_b4.isundefined())
  mu_level_b4.undefine();
else
  mu_level_b4 = mu_temp_level_b4;
if (mu_temp_level_b5.isundefined())
  mu_level_b5.undefine();
else
  mu_level_b5 = mu_temp_level_b5;
if (mu_temp_level_b6.isundefined())
  mu_level_b6.undefine();
else
  mu_level_b6 = mu_temp_level_b6;
if (mu_temp_level_b7.isundefined())
  mu_level_b7.undefine();
else
  mu_level_b7 = mu_temp_level_b7;
if (mu_temp_c_1.isundefined())
  mu_c_1.undefine();
else
  mu_c_1 = mu_temp_c_1;
if (mu_temp_c_2.isundefined())
  mu_c_2.undefine();
else
  mu_c_2 = mu_temp_c_2;
if (mu_temp_c_3.isundefined())
  mu_c_3.undefine();
else
  mu_c_3 = mu_temp_c_3;
if (mu_temp_c_5.isundefined())
  mu_c_5.undefine();
else
  mu_c_5 = mu_temp_c_5;
if (mu_temp_T_5.isundefined())
  mu_T_5.undefine();
else
  mu_T_5 = mu_temp_T_5;
if (mu_temp_T_6.isundefined())
  mu_T_6.undefine();
else
  mu_T_6 = mu_temp_T_6;
if (mu_temp_T_7.isundefined())
  mu_T_7.undefine();
else
  mu_T_7 = mu_temp_T_7;
mu_time = (mu_time) + (mu_STEP_TIME);
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_valve_1.clear();
  mu_valve_2.clear();
  mu_valve_3.clear();
  mu_valve_4.clear();
  mu_valve_5.clear();
  mu_valve_6.clear();
  mu_valve_7.clear();
  mu_valve_8.clear();
  mu_valve_9.clear();
  mu_valve_10.clear();
  mu_valve_11.clear();
  mu_valve_12.clear();
  mu_valve_13.clear();
  mu_valve_14.clear();
  mu_valve_15.clear();
  mu_valve_16.clear();
  mu_valve_17.clear();
  mu_valve_18.clear();
  mu_valve_19.clear();
  mu_valve_20.clear();
  mu_valve_21.clear();
  mu_valve_22.clear();
  mu_valve_23.clear();
  mu_valve_24.clear();
  mu_valve_25.clear();
  mu_valve_26.clear();
  mu_valve_27.clear();
  mu_valve_28.clear();
  mu_valve_29.clear();
  mu_LEVEL_TARGET.clear();
  mu_pump_1.clear();
  mu_pump_2.clear();
  mu_heater_5.clear();
  mu_c_1.clear();
  mu_c_2.clear();
  mu_c_3.clear();
  mu_c_5.clear();
  mu_T_5.clear();
  mu_T_6.clear();
  mu_T_7.clear();
  mu_level_b1.clear();
  mu_level_b2.clear();
  mu_level_b3.clear();
  mu_level_b3_recycle.clear();
  mu_level_b4.clear();
  mu_level_b5.clear();
  mu_level_b6.clear();
  mu_level_b7.clear();
  mu_time.clear();
  mu_isGoal_part.clear();
  mu_isGoal_final.clear();
  mu_systemProperties.clear();
  mu_filling_b3_done.clear();
  mu_concentration_reached.clear();
  mu_get_production_done.clear();
  mu_filling_b4_done.clear();
  mu_filling_b5_done.clear();
  mu_high_concentration_reached.clear();
  mu_filling_b7_done.clear();
  mu_filling_b1_done.clear();
  mu_filling_b2_done.clear();
  mu_cooled_b6.clear();
  mu_cooled_b7.clear();
}
void world_class::undefine()
{
  mu_valve_1.undefine();
  mu_valve_2.undefine();
  mu_valve_3.undefine();
  mu_valve_4.undefine();
  mu_valve_5.undefine();
  mu_valve_6.undefine();
  mu_valve_7.undefine();
  mu_valve_8.undefine();
  mu_valve_9.undefine();
  mu_valve_10.undefine();
  mu_valve_11.undefine();
  mu_valve_12.undefine();
  mu_valve_13.undefine();
  mu_valve_14.undefine();
  mu_valve_15.undefine();
  mu_valve_16.undefine();
  mu_valve_17.undefine();
  mu_valve_18.undefine();
  mu_valve_19.undefine();
  mu_valve_20.undefine();
  mu_valve_21.undefine();
  mu_valve_22.undefine();
  mu_valve_23.undefine();
  mu_valve_24.undefine();
  mu_valve_25.undefine();
  mu_valve_26.undefine();
  mu_valve_27.undefine();
  mu_valve_28.undefine();
  mu_valve_29.undefine();
  mu_LEVEL_TARGET.undefine();
  mu_pump_1.undefine();
  mu_pump_2.undefine();
  mu_heater_5.undefine();
  mu_c_1.undefine();
  mu_c_2.undefine();
  mu_c_3.undefine();
  mu_c_5.undefine();
  mu_T_5.undefine();
  mu_T_6.undefine();
  mu_T_7.undefine();
  mu_level_b1.undefine();
  mu_level_b2.undefine();
  mu_level_b3.undefine();
  mu_level_b3_recycle.undefine();
  mu_level_b4.undefine();
  mu_level_b5.undefine();
  mu_level_b6.undefine();
  mu_level_b7.undefine();
  mu_time.undefine();
  mu_isGoal_part.undefine();
  mu_isGoal_final.undefine();
  mu_systemProperties.undefine();
  mu_filling_b3_done.undefine();
  mu_concentration_reached.undefine();
  mu_get_production_done.undefine();
  mu_filling_b4_done.undefine();
  mu_filling_b5_done.undefine();
  mu_high_concentration_reached.undefine();
  mu_filling_b7_done.undefine();
  mu_filling_b1_done.undefine();
  mu_filling_b2_done.undefine();
  mu_cooled_b6.undefine();
  mu_cooled_b7.undefine();
}
void world_class::reset()
{
  mu_valve_1.reset();
  mu_valve_2.reset();
  mu_valve_3.reset();
  mu_valve_4.reset();
  mu_valve_5.reset();
  mu_valve_6.reset();
  mu_valve_7.reset();
  mu_valve_8.reset();
  mu_valve_9.reset();
  mu_valve_10.reset();
  mu_valve_11.reset();
  mu_valve_12.reset();
  mu_valve_13.reset();
  mu_valve_14.reset();
  mu_valve_15.reset();
  mu_valve_16.reset();
  mu_valve_17.reset();
  mu_valve_18.reset();
  mu_valve_19.reset();
  mu_valve_20.reset();
  mu_valve_21.reset();
  mu_valve_22.reset();
  mu_valve_23.reset();
  mu_valve_24.reset();
  mu_valve_25.reset();
  mu_valve_26.reset();
  mu_valve_27.reset();
  mu_valve_28.reset();
  mu_valve_29.reset();
  mu_LEVEL_TARGET.reset();
  mu_pump_1.reset();
  mu_pump_2.reset();
  mu_heater_5.reset();
  mu_c_1.reset();
  mu_c_2.reset();
  mu_c_3.reset();
  mu_c_5.reset();
  mu_T_5.reset();
  mu_T_6.reset();
  mu_T_7.reset();
  mu_level_b1.reset();
  mu_level_b2.reset();
  mu_level_b3.reset();
  mu_level_b3_recycle.reset();
  mu_level_b4.reset();
  mu_level_b5.reset();
  mu_level_b6.reset();
  mu_level_b7.reset();
  mu_time.reset();
  mu_isGoal_part.reset();
  mu_isGoal_final.reset();
  mu_systemProperties.reset();
  mu_filling_b3_done.reset();
  mu_concentration_reached.reset();
  mu_get_production_done.reset();
  mu_filling_b4_done.reset();
  mu_filling_b5_done.reset();
  mu_high_concentration_reached.reset();
  mu_filling_b7_done.reset();
  mu_filling_b1_done.reset();
  mu_filling_b2_done.reset();
  mu_cooled_b6.reset();
  mu_cooled_b7.reset();
}
void world_class::print(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_valve_1.print(target, separator);
  mu_valve_2.print(target, separator);
  mu_valve_3.print(target, separator);
  mu_valve_4.print(target, separator);
  mu_valve_5.print(target, separator);
  mu_valve_6.print(target, separator);
  mu_valve_7.print(target, separator);
  mu_valve_8.print(target, separator);
  mu_valve_9.print(target, separator);
  mu_valve_10.print(target, separator);
  mu_valve_11.print(target, separator);
  mu_valve_12.print(target, separator);
  mu_valve_13.print(target, separator);
  mu_valve_14.print(target, separator);
  mu_valve_15.print(target, separator);
  mu_valve_16.print(target, separator);
  mu_valve_17.print(target, separator);
  mu_valve_18.print(target, separator);
  mu_valve_19.print(target, separator);
  mu_valve_20.print(target, separator);
  mu_valve_21.print(target, separator);
  mu_valve_22.print(target, separator);
  mu_valve_23.print(target, separator);
  mu_valve_24.print(target, separator);
  mu_valve_25.print(target, separator);
  mu_valve_26.print(target, separator);
  mu_valve_27.print(target, separator);
  mu_valve_28.print(target, separator);
  mu_valve_29.print(target, separator);
  mu_LEVEL_TARGET.print(target, separator);
  mu_pump_1.print(target, separator);
  mu_pump_2.print(target, separator);
  mu_heater_5.print(target, separator);
  mu_c_1.print(target, separator);
  mu_c_2.print(target, separator);
  mu_c_3.print(target, separator);
  mu_c_5.print(target, separator);
  mu_T_5.print(target, separator);
  mu_T_6.print(target, separator);
  mu_T_7.print(target, separator);
  mu_level_b1.print(target, separator);
  mu_level_b2.print(target, separator);
  mu_level_b3.print(target, separator);
  mu_level_b3_recycle.print(target, separator);
  mu_level_b4.print(target, separator);
  mu_level_b5.print(target, separator);
  mu_level_b6.print(target, separator);
  mu_level_b7.print(target, separator);
  mu_time.print(target, separator);
  mu_isGoal_part.print(target, separator);
  mu_isGoal_final.print(target, separator);
  mu_systemProperties.print(target, separator);
  mu_filling_b3_done.print(target, separator);
  mu_concentration_reached.print(target, separator);
  mu_get_production_done.print(target, separator);
  mu_filling_b4_done.print(target, separator);
  mu_filling_b5_done.print(target, separator);
  mu_high_concentration_reached.print(target, separator);
  mu_filling_b7_done.print(target, separator);
  mu_filling_b1_done.print(target, separator);
  mu_filling_b2_done.print(target, separator);
  mu_cooled_b6.print(target, separator);
  mu_cooled_b7.print(target, separator);
    num_calls--;
}
}
void world_class::pddlprint(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_valve_1.print_statistic();
  mu_valve_2.print_statistic();
  mu_valve_3.print_statistic();
  mu_valve_4.print_statistic();
  mu_valve_5.print_statistic();
  mu_valve_6.print_statistic();
  mu_valve_7.print_statistic();
  mu_valve_8.print_statistic();
  mu_valve_9.print_statistic();
  mu_valve_10.print_statistic();
  mu_valve_11.print_statistic();
  mu_valve_12.print_statistic();
  mu_valve_13.print_statistic();
  mu_valve_14.print_statistic();
  mu_valve_15.print_statistic();
  mu_valve_16.print_statistic();
  mu_valve_17.print_statistic();
  mu_valve_18.print_statistic();
  mu_valve_19.print_statistic();
  mu_valve_20.print_statistic();
  mu_valve_21.print_statistic();
  mu_valve_22.print_statistic();
  mu_valve_23.print_statistic();
  mu_valve_24.print_statistic();
  mu_valve_25.print_statistic();
  mu_valve_26.print_statistic();
  mu_valve_27.print_statistic();
  mu_valve_28.print_statistic();
  mu_valve_29.print_statistic();
  mu_LEVEL_TARGET.print_statistic();
  mu_pump_1.print_statistic();
  mu_pump_2.print_statistic();
  mu_heater_5.print_statistic();
  mu_c_1.print_statistic();
  mu_c_2.print_statistic();
  mu_c_3.print_statistic();
  mu_c_5.print_statistic();
  mu_T_5.print_statistic();
  mu_T_6.print_statistic();
  mu_T_7.print_statistic();
  mu_level_b1.print_statistic();
  mu_level_b2.print_statistic();
  mu_level_b3.print_statistic();
  mu_level_b3_recycle.print_statistic();
  mu_level_b4.print_statistic();
  mu_level_b5.print_statistic();
  mu_level_b6.print_statistic();
  mu_level_b7.print_statistic();
  mu_time.print_statistic();
  mu_isGoal_part.print_statistic();
  mu_isGoal_final.print_statistic();
  mu_systemProperties.print_statistic();
  mu_filling_b3_done.print_statistic();
  mu_concentration_reached.print_statistic();
  mu_get_production_done.print_statistic();
  mu_filling_b4_done.print_statistic();
  mu_filling_b5_done.print_statistic();
  mu_high_concentration_reached.print_statistic();
  mu_filling_b7_done.print_statistic();
  mu_filling_b1_done.print_statistic();
  mu_filling_b2_done.print_statistic();
  mu_cooled_b6.print_statistic();
  mu_cooled_b7.print_statistic();
    num_calls--;
}
}
void world_class::print_diff(state *prevstate, FILE *target, const char *separator)
{
  if ( prevstate != NULL )
  {
    mu_valve_1.print_diff(prevstate,target,separator);
    mu_valve_2.print_diff(prevstate,target,separator);
    mu_valve_3.print_diff(prevstate,target,separator);
    mu_valve_4.print_diff(prevstate,target,separator);
    mu_valve_5.print_diff(prevstate,target,separator);
    mu_valve_6.print_diff(prevstate,target,separator);
    mu_valve_7.print_diff(prevstate,target,separator);
    mu_valve_8.print_diff(prevstate,target,separator);
    mu_valve_9.print_diff(prevstate,target,separator);
    mu_valve_10.print_diff(prevstate,target,separator);
    mu_valve_11.print_diff(prevstate,target,separator);
    mu_valve_12.print_diff(prevstate,target,separator);
    mu_valve_13.print_diff(prevstate,target,separator);
    mu_valve_14.print_diff(prevstate,target,separator);
    mu_valve_15.print_diff(prevstate,target,separator);
    mu_valve_16.print_diff(prevstate,target,separator);
    mu_valve_17.print_diff(prevstate,target,separator);
    mu_valve_18.print_diff(prevstate,target,separator);
    mu_valve_19.print_diff(prevstate,target,separator);
    mu_valve_20.print_diff(prevstate,target,separator);
    mu_valve_21.print_diff(prevstate,target,separator);
    mu_valve_22.print_diff(prevstate,target,separator);
    mu_valve_23.print_diff(prevstate,target,separator);
    mu_valve_24.print_diff(prevstate,target,separator);
    mu_valve_25.print_diff(prevstate,target,separator);
    mu_valve_26.print_diff(prevstate,target,separator);
    mu_valve_27.print_diff(prevstate,target,separator);
    mu_valve_28.print_diff(prevstate,target,separator);
    mu_valve_29.print_diff(prevstate,target,separator);
    mu_LEVEL_TARGET.print_diff(prevstate,target,separator);
    mu_pump_1.print_diff(prevstate,target,separator);
    mu_pump_2.print_diff(prevstate,target,separator);
    mu_heater_5.print_diff(prevstate,target,separator);
    mu_c_1.print_diff(prevstate,target,separator);
    mu_c_2.print_diff(prevstate,target,separator);
    mu_c_3.print_diff(prevstate,target,separator);
    mu_c_5.print_diff(prevstate,target,separator);
    mu_T_5.print_diff(prevstate,target,separator);
    mu_T_6.print_diff(prevstate,target,separator);
    mu_T_7.print_diff(prevstate,target,separator);
    mu_level_b1.print_diff(prevstate,target,separator);
    mu_level_b2.print_diff(prevstate,target,separator);
    mu_level_b3.print_diff(prevstate,target,separator);
    mu_level_b3_recycle.print_diff(prevstate,target,separator);
    mu_level_b4.print_diff(prevstate,target,separator);
    mu_level_b5.print_diff(prevstate,target,separator);
    mu_level_b6.print_diff(prevstate,target,separator);
    mu_level_b7.print_diff(prevstate,target,separator);
    mu_time.print_diff(prevstate,target,separator);
    mu_isGoal_part.print_diff(prevstate,target,separator);
    mu_isGoal_final.print_diff(prevstate,target,separator);
    mu_systemProperties.print_diff(prevstate,target,separator);
    mu_filling_b3_done.print_diff(prevstate,target,separator);
    mu_concentration_reached.print_diff(prevstate,target,separator);
    mu_get_production_done.print_diff(prevstate,target,separator);
    mu_filling_b4_done.print_diff(prevstate,target,separator);
    mu_filling_b5_done.print_diff(prevstate,target,separator);
    mu_high_concentration_reached.print_diff(prevstate,target,separator);
    mu_filling_b7_done.print_diff(prevstate,target,separator);
    mu_filling_b1_done.print_diff(prevstate,target,separator);
    mu_filling_b2_done.print_diff(prevstate,target,separator);
    mu_cooled_b6.print_diff(prevstate,target,separator);
    mu_cooled_b7.print_diff(prevstate,target,separator);
  }
  else
print(target,separator);
}
void world_class::to_state(state *newstate)
{
  mu_valve_1.to_state( newstate );
  mu_valve_2.to_state( newstate );
  mu_valve_3.to_state( newstate );
  mu_valve_4.to_state( newstate );
  mu_valve_5.to_state( newstate );
  mu_valve_6.to_state( newstate );
  mu_valve_7.to_state( newstate );
  mu_valve_8.to_state( newstate );
  mu_valve_9.to_state( newstate );
  mu_valve_10.to_state( newstate );
  mu_valve_11.to_state( newstate );
  mu_valve_12.to_state( newstate );
  mu_valve_13.to_state( newstate );
  mu_valve_14.to_state( newstate );
  mu_valve_15.to_state( newstate );
  mu_valve_16.to_state( newstate );
  mu_valve_17.to_state( newstate );
  mu_valve_18.to_state( newstate );
  mu_valve_19.to_state( newstate );
  mu_valve_20.to_state( newstate );
  mu_valve_21.to_state( newstate );
  mu_valve_22.to_state( newstate );
  mu_valve_23.to_state( newstate );
  mu_valve_24.to_state( newstate );
  mu_valve_25.to_state( newstate );
  mu_valve_26.to_state( newstate );
  mu_valve_27.to_state( newstate );
  mu_valve_28.to_state( newstate );
  mu_valve_29.to_state( newstate );
  mu_LEVEL_TARGET.to_state( newstate );
  mu_pump_1.to_state( newstate );
  mu_pump_2.to_state( newstate );
  mu_heater_5.to_state( newstate );
  mu_c_1.to_state( newstate );
  mu_c_2.to_state( newstate );
  mu_c_3.to_state( newstate );
  mu_c_5.to_state( newstate );
  mu_T_5.to_state( newstate );
  mu_T_6.to_state( newstate );
  mu_T_7.to_state( newstate );
  mu_level_b1.to_state( newstate );
  mu_level_b2.to_state( newstate );
  mu_level_b3.to_state( newstate );
  mu_level_b3_recycle.to_state( newstate );
  mu_level_b4.to_state( newstate );
  mu_level_b5.to_state( newstate );
  mu_level_b6.to_state( newstate );
  mu_level_b7.to_state( newstate );
  mu_time.to_state( newstate );
  mu_isGoal_part.to_state( newstate );
  mu_isGoal_final.to_state( newstate );
  mu_systemProperties.to_state( newstate );
  mu_filling_b3_done.to_state( newstate );
  mu_concentration_reached.to_state( newstate );
  mu_get_production_done.to_state( newstate );
  mu_filling_b4_done.to_state( newstate );
  mu_filling_b5_done.to_state( newstate );
  mu_high_concentration_reached.to_state( newstate );
  mu_filling_b7_done.to_state( newstate );
  mu_filling_b1_done.to_state( newstate );
  mu_filling_b2_done.to_state( newstate );
  mu_cooled_b6.to_state( newstate );
  mu_cooled_b7.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b2");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr135;
bool mu__boolexpr136;
bool mu__boolexpr137;
bool mu__boolexpr138;
bool mu__boolexpr139;
bool mu__boolexpr140;
  if (!((mu_level_b6) > (0))) mu__boolexpr140 = FALSE ;
  else {
  mu__boolexpr140 = ((mu_valve_20) == (mu_true)) ; 
}
  if (!(mu__boolexpr140)) mu__boolexpr139 = FALSE ;
  else {
  mu__boolexpr139 = ((mu_valve_24) == (mu_true)) ; 
}
  if (!(mu__boolexpr139)) mu__boolexpr138 = FALSE ;
  else {
  mu__boolexpr138 = ((mu_valve_25) == (mu_true)) ; 
}
  if (!(mu__boolexpr138)) mu__boolexpr137 = FALSE ;
  else {
  mu__boolexpr137 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr137)) mu__boolexpr136 = FALSE ;
  else {
  mu__boolexpr136 = ((mu_valve_6) == (mu_true)) ; 
}
  if (!(mu__boolexpr136)) mu__boolexpr135 = FALSE ;
  else {
  mu__boolexpr135 = ((mu_pump_2) == (mu_true)) ; 
}
    return mu__boolexpr135;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr141;
bool mu__boolexpr142;
bool mu__boolexpr143;
bool mu__boolexpr144;
bool mu__boolexpr145;
bool mu__boolexpr146;
  if (!((mu_level_b6) > (0))) mu__boolexpr146 = FALSE ;
  else {
  mu__boolexpr146 = ((mu_valve_20) == (mu_true)) ; 
}
  if (!(mu__boolexpr146)) mu__boolexpr145 = FALSE ;
  else {
  mu__boolexpr145 = ((mu_valve_24) == (mu_true)) ; 
}
  if (!(mu__boolexpr145)) mu__boolexpr144 = FALSE ;
  else {
  mu__boolexpr144 = ((mu_valve_25) == (mu_true)) ; 
}
  if (!(mu__boolexpr144)) mu__boolexpr143 = FALSE ;
  else {
  mu__boolexpr143 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr143)) mu__boolexpr142 = FALSE ;
  else {
  mu__boolexpr142 = ((mu_valve_6) == (mu_true)) ; 
}
  if (!(mu__boolexpr142)) mu__boolexpr141 = FALSE ;
  else {
  mu__boolexpr141 = ((mu_pump_2) == (mu_true)) ; 
}
	      if (mu__boolexpr141) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b2");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b1");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr147;
bool mu__boolexpr148;
bool mu__boolexpr149;
bool mu__boolexpr150;
bool mu__boolexpr151;
bool mu__boolexpr152;
  if (!((mu_level_b7) > (0))) mu__boolexpr152 = FALSE ;
  else {
  mu__boolexpr152 = ((mu_valve_18) == (mu_true)) ; 
}
  if (!(mu__boolexpr152)) mu__boolexpr151 = FALSE ;
  else {
  mu__boolexpr151 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr151)) mu__boolexpr150 = FALSE ;
  else {
  mu__boolexpr150 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr150)) mu__boolexpr149 = FALSE ;
  else {
  mu__boolexpr149 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr149)) mu__boolexpr148 = FALSE ;
  else {
  mu__boolexpr148 = ((mu_valve_3) == (mu_true)) ; 
}
  if (!(mu__boolexpr148)) mu__boolexpr147 = FALSE ;
  else {
  mu__boolexpr147 = ((mu_pump_1) == (mu_true)) ; 
}
    return mu__boolexpr147;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 1;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr153;
bool mu__boolexpr154;
bool mu__boolexpr155;
bool mu__boolexpr156;
bool mu__boolexpr157;
bool mu__boolexpr158;
  if (!((mu_level_b7) > (0))) mu__boolexpr158 = FALSE ;
  else {
  mu__boolexpr158 = ((mu_valve_18) == (mu_true)) ; 
}
  if (!(mu__boolexpr158)) mu__boolexpr157 = FALSE ;
  else {
  mu__boolexpr157 = ((mu_valve_23) == (mu_true)) ; 
}
  if (!(mu__boolexpr157)) mu__boolexpr156 = FALSE ;
  else {
  mu__boolexpr156 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr156)) mu__boolexpr155 = FALSE ;
  else {
  mu__boolexpr155 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr155)) mu__boolexpr154 = FALSE ;
  else {
  mu__boolexpr154 = ((mu_valve_3) == (mu_true)) ; 
}
  if (!(mu__boolexpr154)) mu__boolexpr153 = FALSE ;
  else {
  mu__boolexpr153 = ((mu_pump_1) == (mu_true)) ; 
}
	      if (mu__boolexpr153) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 1;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b1");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_cooling_b6");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr159;
  if (!((mu_T_6) > (2.500000e+01))) mu__boolexpr159 = FALSE ;
  else {
  mu__boolexpr159 = ((mu_valve_29) == (mu_true)) ; 
}
    return mu__boolexpr159;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 2;
    while (what_rule < 3 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr160;
  if (!((mu_T_6) > (2.500000e+01))) mu__boolexpr160 = FALSE ;
  else {
  mu__boolexpr160 = ((mu_valve_29) == (mu_true)) ; 
}
	      if (mu__boolexpr160) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 2;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_cooling_b6");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_cooling_b7");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr161;
  if (!((mu_T_7) > (2.500000e+01))) mu__boolexpr161 = FALSE ;
  else {
  mu__boolexpr161 = ((mu_valve_17) == (mu_true)) ; 
}
    return mu__boolexpr161;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 3;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr162;
  if (!((mu_T_7) > (2.500000e+01))) mu__boolexpr162 = FALSE ;
  else {
  mu__boolexpr162 = ((mu_valve_17) == (mu_true)) ; 
}
	      if (mu__boolexpr162) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 3;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_cooling_b7");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b7");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr163;
  if (!((mu_valve_15) == (mu_true))) mu__boolexpr163 = FALSE ;
  else {
  mu__boolexpr163 = ((mu_level_b5) > (0)) ; 
}
    return mu__boolexpr163;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 4;
    while (what_rule < 5 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr164;
  if (!((mu_valve_15) == (mu_true))) mu__boolexpr164 = FALSE ;
  else {
  mu__boolexpr164 = ((mu_level_b5) > (0)) ; 
}
	      if (mu__boolexpr164) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 4;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b7");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_evaporation_b5");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr165;
bool mu__boolexpr166;
  if (!((mu_heater_5) == (mu_true))) mu__boolexpr166 = FALSE ;
  else {
  mu__boolexpr166 = ((mu_valve_13) == (mu_true)) ; 
}
  if (!(mu__boolexpr166)) mu__boolexpr165 = FALSE ;
  else {
  mu__boolexpr165 = ((mu_c_5) < (mu_CONCENTRATION_MAX)) ; 
}
    return mu__boolexpr165;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 5;
    while (what_rule < 6 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr167;
bool mu__boolexpr168;
  if (!((mu_heater_5) == (mu_true))) mu__boolexpr168 = FALSE ;
  else {
  mu__boolexpr168 = ((mu_valve_13) == (mu_true)) ; 
}
  if (!(mu__boolexpr168)) mu__boolexpr167 = FALSE ;
  else {
  mu__boolexpr167 = ((mu_c_5) < (mu_CONCENTRATION_MAX)) ; 
}
	      if (mu__boolexpr167) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 5;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_evaporation_b5");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b5");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr169;
  if (!((mu_valve_12) == (mu_true))) mu__boolexpr169 = FALSE ;
  else {
  mu__boolexpr169 = ((mu_level_b4) > (0)) ; 
}
    return mu__boolexpr169;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 6;
    while (what_rule < 7 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr170;
  if (!((mu_valve_12) == (mu_true))) mu__boolexpr170 = FALSE ;
  else {
  mu__boolexpr170 = ((mu_level_b4) > (0)) ; 
}
	      if (mu__boolexpr170) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 6;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b5");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b4");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr171;
  if (!((mu_valve_11) == (mu_true))) mu__boolexpr171 = FALSE ;
  else {
  mu__boolexpr171 = ((mu_level_b3) > (0)) ; 
}
    return mu__boolexpr171;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 7;
    while (what_rule < 8 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr172;
  if (!((mu_valve_11) == (mu_true))) mu__boolexpr172 = FALSE ;
  else {
  mu__boolexpr172 = ((mu_level_b3) > (0)) ; 
}
	      if (mu__boolexpr172) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 7;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b4");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase8 ********************/
class RuleBase8
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_empting_b3");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr173;
bool mu__boolexpr174;
  if (!((mu_valve_10) == (mu_true))) mu__boolexpr174 = FALSE ;
  else {
  mu__boolexpr174 = ((mu_valve_19) == (mu_true)) ; 
}
  if (!(mu__boolexpr174)) mu__boolexpr173 = FALSE ;
  else {
  mu__boolexpr173 = ((mu_valve_27) == (mu_true)) ; 
}
    return mu__boolexpr173;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 8;
    while (what_rule < 9 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr175;
bool mu__boolexpr176;
  if (!((mu_valve_10) == (mu_true))) mu__boolexpr176 = FALSE ;
  else {
  mu__boolexpr176 = ((mu_valve_19) == (mu_true)) ; 
}
  if (!(mu__boolexpr176)) mu__boolexpr175 = FALSE ;
  else {
  mu__boolexpr175 = ((mu_valve_27) == (mu_true)) ; 
}
	      if (mu__boolexpr175) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 8;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_empting_b3");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase9 ********************/
class RuleBase9
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_diluition_b3");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr177;
bool mu__boolexpr178;
  if (!((mu_c_3) >= (mu_CONCENTRATION_TARGET))) mu__boolexpr178 = FALSE ;
  else {
  mu__boolexpr178 = ((mu_valve_9) == (mu_true)) ; 
}
  if (!(mu__boolexpr178)) mu__boolexpr177 = FALSE ;
  else {
  mu__boolexpr177 = ((mu_level_b2) > (0)) ; 
}
    return mu__boolexpr177;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 9;
    while (what_rule < 10 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr179;
bool mu__boolexpr180;
  if (!((mu_c_3) >= (mu_CONCENTRATION_TARGET))) mu__boolexpr180 = FALSE ;
  else {
  mu__boolexpr180 = ((mu_valve_9) == (mu_true)) ; 
}
  if (!(mu__boolexpr180)) mu__boolexpr179 = FALSE ;
  else {
  mu__boolexpr179 = ((mu_level_b2) > (0)) ; 
}
	      if (mu__boolexpr179) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 9;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_diluition_b3");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase10 ********************/
class RuleBase10
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b3");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr181;
  if (!((mu_valve_8) == (mu_true))) mu__boolexpr181 = FALSE ;
  else {
  mu__boolexpr181 = ((mu_level_b1) > (0)) ; 
}
    return mu__boolexpr181;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 10;
    while (what_rule < 11 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr182;
  if (!((mu_valve_8) == (mu_true))) mu__boolexpr182 = FALSE ;
  else {
  mu__boolexpr182 = ((mu_level_b1) > (0)) ; 
}
	      if (mu__boolexpr182) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 10;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("wait_filling_b3");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase11 ********************/
class RuleBase11
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_controller_heater_off_valve_13_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr183;
bool mu__boolexpr184;
  if (!((mu_c_5) >= (mu_CONCENTRATION_MAX))) mu__boolexpr184 = FALSE ;
  else {
  mu__boolexpr184 = ((mu_valve_13) == (mu_true)) ; 
}
  if (!(mu__boolexpr184)) mu__boolexpr183 = FALSE ;
  else {
  mu__boolexpr183 = ((mu_heater_5) == (mu_true)) ; 
}
    return mu__boolexpr183;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 11;
    while (what_rule < 12 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr185;
bool mu__boolexpr186;
  if (!((mu_c_5) >= (mu_CONCENTRATION_MAX))) mu__boolexpr186 = FALSE ;
  else {
  mu__boolexpr186 = ((mu_valve_13) == (mu_true)) ; 
}
  if (!(mu__boolexpr186)) mu__boolexpr185 = FALSE ;
  else {
  mu__boolexpr185 = ((mu_heater_5) == (mu_true)) ; 
}
	      if (mu__boolexpr185) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 11;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_heater_5 = mu_false;
mu_valve_13 = mu_false;
mu_high_concentration_reached = mu_true;
mu_T_6 = 99;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_controller_heater_off_valve_13_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase12 ********************/
class RuleBase12
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_controller_heater_on_valve_13_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr187;
bool mu__boolexpr188;
bool mu__boolexpr189;
bool mu__boolexpr190;
bool mu__boolexpr191;
bool mu__boolexpr192;
bool mu__boolexpr193;
bool mu__boolexpr194;
  if (!((mu_heater_5) == (mu_false))) mu__boolexpr194 = FALSE ;
  else {
  mu__boolexpr194 = ((mu_valve_13) == (mu_false)) ; 
}
  if (!(mu__boolexpr194)) mu__boolexpr193 = FALSE ;
  else {
  mu__boolexpr193 = ((mu_filling_b5_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr193)) mu__boolexpr192 = FALSE ;
  else {
  mu__boolexpr192 = ((mu_high_concentration_reached) == (mu_false)) ; 
}
  if (!(mu__boolexpr192)) mu__boolexpr191 = FALSE ;
  else {
  mu__boolexpr191 = ((mu_level_b5) > (mu_LEVEL_B5_SAFETY)) ; 
}
  if (!(mu__boolexpr191)) mu__boolexpr190 = FALSE ;
  else {
  mu__boolexpr190 = ((mu_valve_12) == (mu_false)) ; 
}
  if (!(mu__boolexpr190)) mu__boolexpr189 = FALSE ;
  else {
  mu__boolexpr189 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr189)) mu__boolexpr188 = FALSE ;
  else {
  mu__boolexpr188 = ((mu_valve_16) == (mu_false)) ; 
}
  if (!(mu__boolexpr188)) mu__boolexpr187 = FALSE ;
  else {
bool mu__boolexpr195;
  if ((mu_valve_17) == (mu_false)) mu__boolexpr195 = TRUE ;
  else {
  mu__boolexpr195 = ((mu_valve_29) == (mu_false)) ; 
}
  mu__boolexpr187 = (mu__boolexpr195) ; 
}
    return mu__boolexpr187;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 12;
    while (what_rule < 13 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr196;
bool mu__boolexpr197;
bool mu__boolexpr198;
bool mu__boolexpr199;
bool mu__boolexpr200;
bool mu__boolexpr201;
bool mu__boolexpr202;
bool mu__boolexpr203;
  if (!((mu_heater_5) == (mu_false))) mu__boolexpr203 = FALSE ;
  else {
  mu__boolexpr203 = ((mu_valve_13) == (mu_false)) ; 
}
  if (!(mu__boolexpr203)) mu__boolexpr202 = FALSE ;
  else {
  mu__boolexpr202 = ((mu_filling_b5_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr202)) mu__boolexpr201 = FALSE ;
  else {
  mu__boolexpr201 = ((mu_high_concentration_reached) == (mu_false)) ; 
}
  if (!(mu__boolexpr201)) mu__boolexpr200 = FALSE ;
  else {
  mu__boolexpr200 = ((mu_level_b5) > (mu_LEVEL_B5_SAFETY)) ; 
}
  if (!(mu__boolexpr200)) mu__boolexpr199 = FALSE ;
  else {
  mu__boolexpr199 = ((mu_valve_12) == (mu_false)) ; 
}
  if (!(mu__boolexpr199)) mu__boolexpr198 = FALSE ;
  else {
  mu__boolexpr198 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr198)) mu__boolexpr197 = FALSE ;
  else {
  mu__boolexpr197 = ((mu_valve_16) == (mu_false)) ; 
}
  if (!(mu__boolexpr197)) mu__boolexpr196 = FALSE ;
  else {
bool mu__boolexpr204;
  if ((mu_valve_17) == (mu_false)) mu__boolexpr204 = TRUE ;
  else {
  mu__boolexpr204 = ((mu_valve_29) == (mu_false)) ; 
}
  mu__boolexpr196 = (mu__boolexpr204) ; 
}
	      if (mu__boolexpr196) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 12;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_13 = mu_true;
mu_heater_5 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_controller_heater_on_valve_13_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase13 ********************/
class RuleBase13
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_close_pump_2_off");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr205;
bool mu__boolexpr206;
bool mu__boolexpr207;
bool mu__boolexpr208;
bool mu__boolexpr209;
bool mu__boolexpr210;
  if (!((mu_level_b6) == (0.000000e+00))) mu__boolexpr210 = FALSE ;
  else {
  mu__boolexpr210 = ((mu_pump_2) == (mu_true)) ; 
}
  if (!(mu__boolexpr210)) mu__boolexpr209 = FALSE ;
  else {
  mu__boolexpr209 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr209)) mu__boolexpr208 = FALSE ;
  else {
  mu__boolexpr208 = ((mu_valve_6) == (mu_true)) ; 
}
  if (!(mu__boolexpr208)) mu__boolexpr207 = FALSE ;
  else {
  mu__boolexpr207 = ((mu_valve_20) == (mu_true)) ; 
}
  if (!(mu__boolexpr207)) mu__boolexpr206 = FALSE ;
  else {
  mu__boolexpr206 = ((mu_valve_24) == (mu_true)) ; 
}
  if (!(mu__boolexpr206)) mu__boolexpr205 = FALSE ;
  else {
  mu__boolexpr205 = ((mu_valve_25) == (mu_true)) ; 
}
    return mu__boolexpr205;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 13;
    while (what_rule < 14 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr211;
bool mu__boolexpr212;
bool mu__boolexpr213;
bool mu__boolexpr214;
bool mu__boolexpr215;
bool mu__boolexpr216;
  if (!((mu_level_b6) == (0.000000e+00))) mu__boolexpr216 = FALSE ;
  else {
  mu__boolexpr216 = ((mu_pump_2) == (mu_true)) ; 
}
  if (!(mu__boolexpr216)) mu__boolexpr215 = FALSE ;
  else {
  mu__boolexpr215 = ((mu_valve_5) == (mu_true)) ; 
}
  if (!(mu__boolexpr215)) mu__boolexpr214 = FALSE ;
  else {
  mu__boolexpr214 = ((mu_valve_6) == (mu_true)) ; 
}
  if (!(mu__boolexpr214)) mu__boolexpr213 = FALSE ;
  else {
  mu__boolexpr213 = ((mu_valve_20) == (mu_true)) ; 
}
  if (!(mu__boolexpr213)) mu__boolexpr212 = FALSE ;
  else {
  mu__boolexpr212 = ((mu_valve_24) == (mu_true)) ; 
}
  if (!(mu__boolexpr212)) mu__boolexpr211 = FALSE ;
  else {
  mu__boolexpr211 = ((mu_valve_25) == (mu_true)) ; 
}
	      if (mu__boolexpr211) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 13;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_20 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_pump_2 = mu_false;
mu_filling_b2_done = mu_true;
mu_T_6 = 2.500000e+01;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_close_pump_2_off");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase14 ********************/
class RuleBase14
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_open_pump_2_on");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr217;
bool mu__boolexpr218;
bool mu__boolexpr219;
  if (!((mu_cooled_b6) == (mu_true))) mu__boolexpr219 = FALSE ;
  else {
  mu__boolexpr219 = ((mu_pump_2) == (mu_false)) ; 
}
  if (!(mu__boolexpr219)) mu__boolexpr218 = FALSE ;
  else {
  mu__boolexpr218 = ((mu_level_b6) > (0)) ; 
}
  if (!(mu__boolexpr218)) mu__boolexpr217 = FALSE ;
  else {
  mu__boolexpr217 = ((mu_high_concentration_reached) == (mu_true)) ; 
}
    return mu__boolexpr217;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 14;
    while (what_rule < 15 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr220;
bool mu__boolexpr221;
bool mu__boolexpr222;
  if (!((mu_cooled_b6) == (mu_true))) mu__boolexpr222 = FALSE ;
  else {
  mu__boolexpr222 = ((mu_pump_2) == (mu_false)) ; 
}
  if (!(mu__boolexpr222)) mu__boolexpr221 = FALSE ;
  else {
  mu__boolexpr221 = ((mu_level_b6) > (0)) ; 
}
  if (!(mu__boolexpr221)) mu__boolexpr220 = FALSE ;
  else {
  mu__boolexpr220 = ((mu_high_concentration_reached) == (mu_true)) ; 
}
	      if (mu__boolexpr220) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 14;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_5 = mu_true;
mu_valve_6 = mu_true;
mu_valve_20 = mu_true;
mu_valve_24 = mu_true;
mu_valve_25 = mu_true;
mu_pump_2 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_open_pump_2_on");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase15 ********************/
class RuleBase15
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_close_pump_1_off");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr223;
bool mu__boolexpr224;
bool mu__boolexpr225;
bool mu__boolexpr226;
bool mu__boolexpr227;
  if (!((mu_level_b7) == (0.000000e+00))) mu__boolexpr227 = FALSE ;
  else {
  mu__boolexpr227 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr227)) mu__boolexpr226 = FALSE ;
  else {
  mu__boolexpr226 = ((mu_valve_3) == (mu_true)) ; 
}
  if (!(mu__boolexpr226)) mu__boolexpr225 = FALSE ;
  else {
  mu__boolexpr225 = ((mu_valve_18) == (mu_true)) ; 
}
  if (!(mu__boolexpr225)) mu__boolexpr224 = FALSE ;
  else {
  mu__boolexpr224 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr224)) mu__boolexpr223 = FALSE ;
  else {
  mu__boolexpr223 = ((mu_valve_23) == (mu_true)) ; 
}
    return mu__boolexpr223;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 15;
    while (what_rule < 16 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr228;
bool mu__boolexpr229;
bool mu__boolexpr230;
bool mu__boolexpr231;
bool mu__boolexpr232;
  if (!((mu_level_b7) == (0.000000e+00))) mu__boolexpr232 = FALSE ;
  else {
  mu__boolexpr232 = ((mu_valve_1) == (mu_true)) ; 
}
  if (!(mu__boolexpr232)) mu__boolexpr231 = FALSE ;
  else {
  mu__boolexpr231 = ((mu_valve_3) == (mu_true)) ; 
}
  if (!(mu__boolexpr231)) mu__boolexpr230 = FALSE ;
  else {
  mu__boolexpr230 = ((mu_valve_18) == (mu_true)) ; 
}
  if (!(mu__boolexpr230)) mu__boolexpr229 = FALSE ;
  else {
  mu__boolexpr229 = ((mu_valve_22) == (mu_true)) ; 
}
  if (!(mu__boolexpr229)) mu__boolexpr228 = FALSE ;
  else {
  mu__boolexpr228 = ((mu_valve_23) == (mu_true)) ; 
}
	      if (mu__boolexpr228) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 15;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_1 = mu_false;
mu_valve_3 = mu_false;
mu_valve_18 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_pump_1 = mu_false;
mu_filling_b1_done = mu_true;
mu_T_7 = 2.500000e+01;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_close_pump_1_off");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase16 ********************/
class RuleBase16
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_open_pump_1_on");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr233;
bool mu__boolexpr234;
bool mu__boolexpr235;
  if (!((mu_cooled_b7) == (mu_true))) mu__boolexpr235 = FALSE ;
  else {
  mu__boolexpr235 = ((mu_pump_1) == (mu_false)) ; 
}
  if (!(mu__boolexpr235)) mu__boolexpr234 = FALSE ;
  else {
  mu__boolexpr234 = ((mu_level_b7) > (0)) ; 
}
  if (!(mu__boolexpr234)) mu__boolexpr233 = FALSE ;
  else {
  mu__boolexpr233 = ((mu_valve_15) == (mu_false)) ; 
}
    return mu__boolexpr233;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 16;
    while (what_rule < 17 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr236;
bool mu__boolexpr237;
bool mu__boolexpr238;
  if (!((mu_cooled_b7) == (mu_true))) mu__boolexpr238 = FALSE ;
  else {
  mu__boolexpr238 = ((mu_pump_1) == (mu_false)) ; 
}
  if (!(mu__boolexpr238)) mu__boolexpr237 = FALSE ;
  else {
  mu__boolexpr237 = ((mu_level_b7) > (0)) ; 
}
  if (!(mu__boolexpr237)) mu__boolexpr236 = FALSE ;
  else {
  mu__boolexpr236 = ((mu_valve_15) == (mu_false)) ; 
}
	      if (mu__boolexpr236) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 16;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_1 = mu_true;
mu_valve_3 = mu_true;
mu_valve_18 = mu_true;
mu_valve_22 = mu_true;
mu_valve_23 = mu_true;
mu_pump_1 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("group_valve_open_pump_1_on");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase17 ********************/
class RuleBase17
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_29_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr239;
  if (!((mu_T_6) <= (2.500000e+01))) mu__boolexpr239 = FALSE ;
  else {
  mu__boolexpr239 = ((mu_valve_29) == (mu_true)) ; 
}
    return mu__boolexpr239;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 17;
    while (what_rule < 18 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr240;
  if (!((mu_T_6) <= (2.500000e+01))) mu__boolexpr240 = FALSE ;
  else {
  mu__boolexpr240 = ((mu_valve_29) == (mu_true)) ; 
}
	      if (mu__boolexpr240) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 17;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_29 = mu_false;
mu_cooled_b6 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_29_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase18 ********************/
class RuleBase18
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_29_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr241;
bool mu__boolexpr242;
bool mu__boolexpr243;
bool mu__boolexpr244;
bool mu__boolexpr245;
  if (!((mu_high_concentration_reached) == (mu_true))) mu__boolexpr245 = FALSE ;
  else {
  mu__boolexpr245 = ((mu_heater_5) == (mu_false)) ; 
}
  if (!(mu__boolexpr245)) mu__boolexpr244 = FALSE ;
  else {
  mu__boolexpr244 = ((mu_level_b6) > (0)) ; 
}
  if (!(mu__boolexpr244)) mu__boolexpr243 = FALSE ;
  else {
  mu__boolexpr243 = ((mu_cooled_b6) == (mu_false)) ; 
}
  if (!(mu__boolexpr243)) mu__boolexpr242 = FALSE ;
  else {
  mu__boolexpr242 = ((mu_valve_29) == (mu_false)) ; 
}
  if (!(mu__boolexpr242)) mu__boolexpr241 = FALSE ;
  else {
bool mu__boolexpr246;
  if ((mu_valve_13) == (mu_false)) mu__boolexpr246 = TRUE ;
  else {
  mu__boolexpr246 = ((mu_valve_17) == (mu_false)) ; 
}
  mu__boolexpr241 = (mu__boolexpr246) ; 
}
    return mu__boolexpr241;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 18;
    while (what_rule < 19 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr247;
bool mu__boolexpr248;
bool mu__boolexpr249;
bool mu__boolexpr250;
bool mu__boolexpr251;
  if (!((mu_high_concentration_reached) == (mu_true))) mu__boolexpr251 = FALSE ;
  else {
  mu__boolexpr251 = ((mu_heater_5) == (mu_false)) ; 
}
  if (!(mu__boolexpr251)) mu__boolexpr250 = FALSE ;
  else {
  mu__boolexpr250 = ((mu_level_b6) > (0)) ; 
}
  if (!(mu__boolexpr250)) mu__boolexpr249 = FALSE ;
  else {
  mu__boolexpr249 = ((mu_cooled_b6) == (mu_false)) ; 
}
  if (!(mu__boolexpr249)) mu__boolexpr248 = FALSE ;
  else {
  mu__boolexpr248 = ((mu_valve_29) == (mu_false)) ; 
}
  if (!(mu__boolexpr248)) mu__boolexpr247 = FALSE ;
  else {
bool mu__boolexpr252;
  if ((mu_valve_13) == (mu_false)) mu__boolexpr252 = TRUE ;
  else {
  mu__boolexpr252 = ((mu_valve_17) == (mu_false)) ; 
}
  mu__boolexpr247 = (mu__boolexpr252) ; 
}
	      if (mu__boolexpr247) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 18;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_29 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_29_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase19 ********************/
class RuleBase19
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_17_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr253;
  if (!((mu_T_7) <= (2.500000e+01))) mu__boolexpr253 = FALSE ;
  else {
  mu__boolexpr253 = ((mu_valve_17) == (mu_true)) ; 
}
    return mu__boolexpr253;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 19;
    while (what_rule < 20 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr254;
  if (!((mu_T_7) <= (2.500000e+01))) mu__boolexpr254 = FALSE ;
  else {
  mu__boolexpr254 = ((mu_valve_17) == (mu_true)) ; 
}
	      if (mu__boolexpr254) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 19;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_17 = mu_false;
mu_cooled_b7 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_17_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase20 ********************/
class RuleBase20
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_17_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr255;
bool mu__boolexpr256;
bool mu__boolexpr257;
  if (!((mu_filling_b7_done) == (mu_true))) mu__boolexpr257 = FALSE ;
  else {
  mu__boolexpr257 = ((mu_cooled_b7) == (mu_false)) ; 
}
  if (!(mu__boolexpr257)) mu__boolexpr256 = FALSE ;
  else {
  mu__boolexpr256 = ((mu_valve_17) == (mu_false)) ; 
}
  if (!(mu__boolexpr256)) mu__boolexpr255 = FALSE ;
  else {
bool mu__boolexpr258;
  if ((mu_valve_13) == (mu_false)) mu__boolexpr258 = TRUE ;
  else {
  mu__boolexpr258 = ((mu_valve_29) == (mu_false)) ; 
}
  mu__boolexpr255 = (mu__boolexpr258) ; 
}
    return mu__boolexpr255;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 20;
    while (what_rule < 21 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr259;
bool mu__boolexpr260;
bool mu__boolexpr261;
  if (!((mu_filling_b7_done) == (mu_true))) mu__boolexpr261 = FALSE ;
  else {
  mu__boolexpr261 = ((mu_cooled_b7) == (mu_false)) ; 
}
  if (!(mu__boolexpr261)) mu__boolexpr260 = FALSE ;
  else {
  mu__boolexpr260 = ((mu_valve_17) == (mu_false)) ; 
}
  if (!(mu__boolexpr260)) mu__boolexpr259 = FALSE ;
  else {
bool mu__boolexpr262;
  if ((mu_valve_13) == (mu_false)) mu__boolexpr262 = TRUE ;
  else {
  mu__boolexpr262 = ((mu_valve_29) == (mu_false)) ; 
}
  mu__boolexpr259 = (mu__boolexpr262) ; 
}
	      if (mu__boolexpr259) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 20;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_17 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_17_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase21 ********************/
class RuleBase21
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_15_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr263;
  if (!((mu_level_b5) == (0.000000e+00))) mu__boolexpr263 = FALSE ;
  else {
  mu__boolexpr263 = ((mu_valve_15) == (mu_true)) ; 
}
    return mu__boolexpr263;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 21;
    while (what_rule < 22 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr264;
  if (!((mu_level_b5) == (0.000000e+00))) mu__boolexpr264 = FALSE ;
  else {
  mu__boolexpr264 = ((mu_valve_15) == (mu_true)) ; 
}
	      if (mu__boolexpr264) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 21;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_15 = mu_false;
mu_T_5 = 2.500000e+01;
mu_filling_b7_done = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_15_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase22 ********************/
class RuleBase22
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_15_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr265;
bool mu__boolexpr266;
bool mu__boolexpr267;
bool mu__boolexpr268;
bool mu__boolexpr269;
  if (!((mu_high_concentration_reached) == (mu_true))) mu__boolexpr269 = FALSE ;
  else {
  mu__boolexpr269 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr269)) mu__boolexpr268 = FALSE ;
  else {
  mu__boolexpr268 = ((mu_filling_b7_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr268)) mu__boolexpr267 = FALSE ;
  else {
  mu__boolexpr267 = ((mu_heater_5) == (mu_false)) ; 
}
  if (!(mu__boolexpr267)) mu__boolexpr266 = FALSE ;
  else {
  mu__boolexpr266 = ((mu_valve_12) == (mu_false)) ; 
}
  if (!(mu__boolexpr266)) mu__boolexpr265 = FALSE ;
  else {
  mu__boolexpr265 = ((mu_valve_18) == (mu_false)) ; 
}
    return mu__boolexpr265;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 22;
    while (what_rule < 23 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr270;
bool mu__boolexpr271;
bool mu__boolexpr272;
bool mu__boolexpr273;
bool mu__boolexpr274;
  if (!((mu_high_concentration_reached) == (mu_true))) mu__boolexpr274 = FALSE ;
  else {
  mu__boolexpr274 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr274)) mu__boolexpr273 = FALSE ;
  else {
  mu__boolexpr273 = ((mu_filling_b7_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr273)) mu__boolexpr272 = FALSE ;
  else {
  mu__boolexpr272 = ((mu_heater_5) == (mu_false)) ; 
}
  if (!(mu__boolexpr272)) mu__boolexpr271 = FALSE ;
  else {
  mu__boolexpr271 = ((mu_valve_12) == (mu_false)) ; 
}
  if (!(mu__boolexpr271)) mu__boolexpr270 = FALSE ;
  else {
  mu__boolexpr270 = ((mu_valve_18) == (mu_false)) ; 
}
	      if (mu__boolexpr270) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 22;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_15 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_15_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase23 ********************/
class RuleBase23
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_12_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr275;
  if (!((mu_level_b4) == (0.000000e+00))) mu__boolexpr275 = FALSE ;
  else {
  mu__boolexpr275 = ((mu_valve_12) == (mu_true)) ; 
}
    return mu__boolexpr275;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 23;
    while (what_rule < 24 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr276;
  if (!((mu_level_b4) == (0.000000e+00))) mu__boolexpr276 = FALSE ;
  else {
  mu__boolexpr276 = ((mu_valve_12) == (mu_true)) ; 
}
	      if (mu__boolexpr276) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 23;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_12 = mu_false;
mu_filling_b5_done = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_12_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase24 ********************/
class RuleBase24
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_12_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr277;
bool mu__boolexpr278;
bool mu__boolexpr279;
bool mu__boolexpr280;
bool mu__boolexpr281;
  if (!((mu_valve_12) == (mu_false))) mu__boolexpr281 = FALSE ;
  else {
  mu__boolexpr281 = ((mu_filling_b4_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr281)) mu__boolexpr280 = FALSE ;
  else {
  mu__boolexpr280 = ((mu_filling_b5_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr280)) mu__boolexpr279 = FALSE ;
  else {
  mu__boolexpr279 = ((mu_valve_11) == (mu_false)) ; 
}
  if (!(mu__boolexpr279)) mu__boolexpr278 = FALSE ;
  else {
  mu__boolexpr278 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr278)) mu__boolexpr277 = FALSE ;
  else {
  mu__boolexpr277 = ((mu_valve_16) == (mu_false)) ; 
}
    return mu__boolexpr277;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 24;
    while (what_rule < 25 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr282;
bool mu__boolexpr283;
bool mu__boolexpr284;
bool mu__boolexpr285;
bool mu__boolexpr286;
  if (!((mu_valve_12) == (mu_false))) mu__boolexpr286 = FALSE ;
  else {
  mu__boolexpr286 = ((mu_filling_b4_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr286)) mu__boolexpr285 = FALSE ;
  else {
  mu__boolexpr285 = ((mu_filling_b5_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr285)) mu__boolexpr284 = FALSE ;
  else {
  mu__boolexpr284 = ((mu_valve_11) == (mu_false)) ; 
}
  if (!(mu__boolexpr284)) mu__boolexpr283 = FALSE ;
  else {
  mu__boolexpr283 = ((mu_valve_15) == (mu_false)) ; 
}
  if (!(mu__boolexpr283)) mu__boolexpr282 = FALSE ;
  else {
  mu__boolexpr282 = ((mu_valve_16) == (mu_false)) ; 
}
	      if (mu__boolexpr282) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 24;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_12 = mu_true;
if (mu_c_3.isundefined())
  mu_c_5.undefine();
else
  mu_c_5 = mu_c_3;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_12_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase25 ********************/
class RuleBase25
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_11_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr287;
  if (!((mu_level_b3) == (0.000000e+00))) mu__boolexpr287 = FALSE ;
  else {
  mu__boolexpr287 = ((mu_valve_11) == (mu_true)) ; 
}
    return mu__boolexpr287;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 25;
    while (what_rule < 26 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr288;
  if (!((mu_level_b3) == (0.000000e+00))) mu__boolexpr288 = FALSE ;
  else {
  mu__boolexpr288 = ((mu_valve_11) == (mu_true)) ; 
}
	      if (mu__boolexpr288) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 25;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_11 = mu_false;
mu_filling_b4_done = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_11_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase26 ********************/
class RuleBase26
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_11_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr289;
bool mu__boolexpr290;
bool mu__boolexpr291;
bool mu__boolexpr292;
bool mu__boolexpr293;
  if (!((mu_get_production_done) == (mu_true))) mu__boolexpr293 = FALSE ;
  else {
  mu__boolexpr293 = ((mu_valve_11) == (mu_false)) ; 
}
  if (!(mu__boolexpr293)) mu__boolexpr292 = FALSE ;
  else {
  mu__boolexpr292 = ((mu_filling_b4_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr292)) mu__boolexpr291 = FALSE ;
  else {
  mu__boolexpr291 = ((mu_valve_8) == (mu_false)) ; 
}
  if (!(mu__boolexpr291)) mu__boolexpr290 = FALSE ;
  else {
  mu__boolexpr290 = ((mu_valve_9) == (mu_false)) ; 
}
  if (!(mu__boolexpr290)) mu__boolexpr289 = FALSE ;
  else {
  mu__boolexpr289 = ((mu_valve_12) == (mu_false)) ; 
}
    return mu__boolexpr289;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 26;
    while (what_rule < 27 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr294;
bool mu__boolexpr295;
bool mu__boolexpr296;
bool mu__boolexpr297;
bool mu__boolexpr298;
  if (!((mu_get_production_done) == (mu_true))) mu__boolexpr298 = FALSE ;
  else {
  mu__boolexpr298 = ((mu_valve_11) == (mu_false)) ; 
}
  if (!(mu__boolexpr298)) mu__boolexpr297 = FALSE ;
  else {
  mu__boolexpr297 = ((mu_filling_b4_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr297)) mu__boolexpr296 = FALSE ;
  else {
  mu__boolexpr296 = ((mu_valve_8) == (mu_false)) ; 
}
  if (!(mu__boolexpr296)) mu__boolexpr295 = FALSE ;
  else {
  mu__boolexpr295 = ((mu_valve_9) == (mu_false)) ; 
}
  if (!(mu__boolexpr295)) mu__boolexpr294 = FALSE ;
  else {
  mu__boolexpr294 = ((mu_valve_12) == (mu_false)) ; 
}
	      if (mu__boolexpr294) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 26;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_11 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_11_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase27 ********************/
class RuleBase27
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_10_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr299;
bool mu__boolexpr300;
bool mu__boolexpr301;
  if (!((mu_valve_10) == (mu_true))) mu__boolexpr301 = FALSE ;
  else {
  mu__boolexpr301 = ((mu_valve_19) == (mu_true)) ; 
}
  if (!(mu__boolexpr301)) mu__boolexpr300 = FALSE ;
  else {
  mu__boolexpr300 = ((mu_valve_27) == (mu_true)) ; 
}
  if (!(mu__boolexpr300)) mu__boolexpr299 = FALSE ;
  else {
  mu__boolexpr299 = ((mu_level_b3) <= (mu_level_b3_recycle)) ; 
}
    return mu__boolexpr299;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 27;
    while (what_rule < 28 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr302;
bool mu__boolexpr303;
bool mu__boolexpr304;
  if (!((mu_valve_10) == (mu_true))) mu__boolexpr304 = FALSE ;
  else {
  mu__boolexpr304 = ((mu_valve_19) == (mu_true)) ; 
}
  if (!(mu__boolexpr304)) mu__boolexpr303 = FALSE ;
  else {
  mu__boolexpr303 = ((mu_valve_27) == (mu_true)) ; 
}
  if (!(mu__boolexpr303)) mu__boolexpr302 = FALSE ;
  else {
  mu__boolexpr302 = ((mu_level_b3) <= (mu_level_b3_recycle)) ; 
}
	      if (mu__boolexpr302) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 27;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_10 = mu_false;
mu_valve_19 = mu_false;
mu_valve_27 = mu_false;
mu_get_production_done = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_10_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase28 ********************/
class RuleBase28
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_10_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr305;
bool mu__boolexpr306;
bool mu__boolexpr307;
bool mu__boolexpr308;
bool mu__boolexpr309;
bool mu__boolexpr310;
bool mu__boolexpr311;
bool mu__boolexpr312;
bool mu__boolexpr313;
bool mu__boolexpr314;
  if (!((mu_get_production_done) == (mu_false))) mu__boolexpr314 = FALSE ;
  else {
  mu__boolexpr314 = ((mu_filling_b3_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr314)) mu__boolexpr313 = FALSE ;
  else {
  mu__boolexpr313 = ((mu_level_b3) >= (mu_LEVEL_TARGET)) ; 
}
  if (!(mu__boolexpr313)) mu__boolexpr312 = FALSE ;
  else {
  mu__boolexpr312 = ((mu_concentration_reached) == (mu_true)) ; 
}
  if (!(mu__boolexpr312)) mu__boolexpr311 = FALSE ;
  else {
  mu__boolexpr311 = ((mu_valve_10) == (mu_false)) ; 
}
  if (!(mu__boolexpr311)) mu__boolexpr310 = FALSE ;
  else {
  mu__boolexpr310 = ((mu_valve_19) == (mu_false)) ; 
}
  if (!(mu__boolexpr310)) mu__boolexpr309 = FALSE ;
  else {
  mu__boolexpr309 = ((mu_valve_27) == (mu_false)) ; 
}
  if (!(mu__boolexpr309)) mu__boolexpr308 = FALSE ;
  else {
  mu__boolexpr308 = ((mu_get_production_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr308)) mu__boolexpr307 = FALSE ;
  else {
  mu__boolexpr307 = ((mu_valve_8) == (mu_false)) ; 
}
  if (!(mu__boolexpr307)) mu__boolexpr306 = FALSE ;
  else {
  mu__boolexpr306 = ((mu_valve_9) == (mu_false)) ; 
}
  if (!(mu__boolexpr306)) mu__boolexpr305 = FALSE ;
  else {
  mu__boolexpr305 = ((mu_valve_12) == (mu_false)) ; 
}
    return mu__boolexpr305;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 28;
    while (what_rule < 29 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr315;
bool mu__boolexpr316;
bool mu__boolexpr317;
bool mu__boolexpr318;
bool mu__boolexpr319;
bool mu__boolexpr320;
bool mu__boolexpr321;
bool mu__boolexpr322;
bool mu__boolexpr323;
bool mu__boolexpr324;
  if (!((mu_get_production_done) == (mu_false))) mu__boolexpr324 = FALSE ;
  else {
  mu__boolexpr324 = ((mu_filling_b3_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr324)) mu__boolexpr323 = FALSE ;
  else {
  mu__boolexpr323 = ((mu_level_b3) >= (mu_LEVEL_TARGET)) ; 
}
  if (!(mu__boolexpr323)) mu__boolexpr322 = FALSE ;
  else {
  mu__boolexpr322 = ((mu_concentration_reached) == (mu_true)) ; 
}
  if (!(mu__boolexpr322)) mu__boolexpr321 = FALSE ;
  else {
  mu__boolexpr321 = ((mu_valve_10) == (mu_false)) ; 
}
  if (!(mu__boolexpr321)) mu__boolexpr320 = FALSE ;
  else {
  mu__boolexpr320 = ((mu_valve_19) == (mu_false)) ; 
}
  if (!(mu__boolexpr320)) mu__boolexpr319 = FALSE ;
  else {
  mu__boolexpr319 = ((mu_valve_27) == (mu_false)) ; 
}
  if (!(mu__boolexpr319)) mu__boolexpr318 = FALSE ;
  else {
  mu__boolexpr318 = ((mu_get_production_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr318)) mu__boolexpr317 = FALSE ;
  else {
  mu__boolexpr317 = ((mu_valve_8) == (mu_false)) ; 
}
  if (!(mu__boolexpr317)) mu__boolexpr316 = FALSE ;
  else {
  mu__boolexpr316 = ((mu_valve_9) == (mu_false)) ; 
}
  if (!(mu__boolexpr316)) mu__boolexpr315 = FALSE ;
  else {
  mu__boolexpr315 = ((mu_valve_12) == (mu_false)) ; 
}
	      if (mu__boolexpr315) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 28;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_10 = mu_true;
mu_valve_19 = mu_true;
mu_valve_27 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_10_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase29 ********************/
class RuleBase29
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_9_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr325;
bool mu__boolexpr326;
  if (!((mu_level_b3) >= (mu_LEVEL_TARGET))) mu__boolexpr326 = FALSE ;
  else {
  mu__boolexpr326 = ((mu_c_3) <= (mu_CONCENTRATION_TARGET)) ; 
}
  if (!(mu__boolexpr326)) mu__boolexpr325 = FALSE ;
  else {
  mu__boolexpr325 = ((mu_valve_9) == (mu_true)) ; 
}
    return mu__boolexpr325;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 29;
    while (what_rule < 30 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr327;
bool mu__boolexpr328;
  if (!((mu_level_b3) >= (mu_LEVEL_TARGET))) mu__boolexpr328 = FALSE ;
  else {
  mu__boolexpr328 = ((mu_c_3) <= (mu_CONCENTRATION_TARGET)) ; 
}
  if (!(mu__boolexpr328)) mu__boolexpr327 = FALSE ;
  else {
  mu__boolexpr327 = ((mu_valve_9) == (mu_true)) ; 
}
	      if (mu__boolexpr327) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 29;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_9 = mu_false;
mu_concentration_reached = mu_true;
mu_level_b3_recycle = (mu_level_b3) - (mu_LEVEL_TARGET);
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_9_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase30 ********************/
class RuleBase30
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_9_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr329;
bool mu__boolexpr330;
bool mu__boolexpr331;
bool mu__boolexpr332;
bool mu__boolexpr333;
bool mu__boolexpr334;
  if (!((mu_valve_9) == (mu_false))) mu__boolexpr334 = FALSE ;
  else {
  mu__boolexpr334 = ((mu_filling_b3_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr334)) mu__boolexpr333 = FALSE ;
  else {
  mu__boolexpr333 = ((mu_concentration_reached) == (mu_false)) ; 
}
  if (!(mu__boolexpr333)) mu__boolexpr332 = FALSE ;
  else {
  mu__boolexpr332 = ((mu_valve_6) == (mu_false)) ; 
}
  if (!(mu__boolexpr332)) mu__boolexpr331 = FALSE ;
  else {
  mu__boolexpr331 = ((mu_valve_7) == (mu_false)) ; 
}
  if (!(mu__boolexpr331)) mu__boolexpr330 = FALSE ;
  else {
  mu__boolexpr330 = ((mu_valve_10) == (mu_false)) ; 
}
  if (!(mu__boolexpr330)) mu__boolexpr329 = FALSE ;
  else {
  mu__boolexpr329 = ((mu_valve_11) == (mu_false)) ; 
}
    return mu__boolexpr329;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 30;
    while (what_rule < 31 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr335;
bool mu__boolexpr336;
bool mu__boolexpr337;
bool mu__boolexpr338;
bool mu__boolexpr339;
bool mu__boolexpr340;
  if (!((mu_valve_9) == (mu_false))) mu__boolexpr340 = FALSE ;
  else {
  mu__boolexpr340 = ((mu_filling_b3_done) == (mu_true)) ; 
}
  if (!(mu__boolexpr340)) mu__boolexpr339 = FALSE ;
  else {
  mu__boolexpr339 = ((mu_concentration_reached) == (mu_false)) ; 
}
  if (!(mu__boolexpr339)) mu__boolexpr338 = FALSE ;
  else {
  mu__boolexpr338 = ((mu_valve_6) == (mu_false)) ; 
}
  if (!(mu__boolexpr338)) mu__boolexpr337 = FALSE ;
  else {
  mu__boolexpr337 = ((mu_valve_7) == (mu_false)) ; 
}
  if (!(mu__boolexpr337)) mu__boolexpr336 = FALSE ;
  else {
  mu__boolexpr336 = ((mu_valve_10) == (mu_false)) ; 
}
  if (!(mu__boolexpr336)) mu__boolexpr335 = FALSE ;
  else {
  mu__boolexpr335 = ((mu_valve_11) == (mu_false)) ; 
}
	      if (mu__boolexpr335) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 30;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_9 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_9_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase31 ********************/
class RuleBase31
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_8_close");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return (mu_valve_8) == (mu_true);
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 31;
    while (what_rule < 32 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_valve_8) == (mu_true)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 31;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_8 = mu_false;
mu_filling_b3_done = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_8_close");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
/******************** RuleBase32 ********************/
class RuleBase32
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_8_open");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr341;
bool mu__boolexpr342;
bool mu__boolexpr343;
bool mu__boolexpr344;
bool mu__boolexpr345;
bool mu__boolexpr346;
  if (!((mu_valve_8) == (mu_false))) mu__boolexpr346 = FALSE ;
  else {
  mu__boolexpr346 = ((mu_level_b3) == (0.000000e+00)) ; 
}
  if (!(mu__boolexpr346)) mu__boolexpr345 = FALSE ;
  else {
  mu__boolexpr345 = ((mu_level_b1) > (0.000000e+00)) ; 
}
  if (!(mu__boolexpr345)) mu__boolexpr344 = FALSE ;
  else {
  mu__boolexpr344 = ((mu_filling_b3_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr344)) mu__boolexpr343 = FALSE ;
  else {
  mu__boolexpr343 = ((mu_valve_3) == (mu_false)) ; 
}
  if (!(mu__boolexpr343)) mu__boolexpr342 = FALSE ;
  else {
  mu__boolexpr342 = ((mu_valve_10) == (mu_false)) ; 
}
  if (!(mu__boolexpr342)) mu__boolexpr341 = FALSE ;
  else {
  mu__boolexpr341 = ((mu_valve_11) == (mu_false)) ; 
}
    return mu__boolexpr341;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 32;
    while (what_rule < 33 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr347;
bool mu__boolexpr348;
bool mu__boolexpr349;
bool mu__boolexpr350;
bool mu__boolexpr351;
bool mu__boolexpr352;
  if (!((mu_valve_8) == (mu_false))) mu__boolexpr352 = FALSE ;
  else {
  mu__boolexpr352 = ((mu_level_b3) == (0.000000e+00)) ; 
}
  if (!(mu__boolexpr352)) mu__boolexpr351 = FALSE ;
  else {
  mu__boolexpr351 = ((mu_level_b1) > (0.000000e+00)) ; 
}
  if (!(mu__boolexpr351)) mu__boolexpr350 = FALSE ;
  else {
  mu__boolexpr350 = ((mu_filling_b3_done) == (mu_false)) ; 
}
  if (!(mu__boolexpr350)) mu__boolexpr349 = FALSE ;
  else {
  mu__boolexpr349 = ((mu_valve_3) == (mu_false)) ; 
}
  if (!(mu__boolexpr349)) mu__boolexpr348 = FALSE ;
  else {
  mu__boolexpr348 = ((mu_valve_10) == (mu_false)) ; 
}
  if (!(mu__boolexpr348)) mu__boolexpr347 = FALSE ;
  else {
  mu__boolexpr347 = ((mu_valve_11) == (mu_false)) ; 
}
	      if (mu__boolexpr347) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 32;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_dynamic_check (  );
mu_valve_8 = mu_true;
mu_compute_new_state (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("controller_valve_8_open");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Action;
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
  RuleBase9 R9;
  RuleBase10 R10;
  RuleBase11 R11;
  RuleBase12 R12;
  RuleBase13 R13;
  RuleBase14 R14;
  RuleBase15 R15;
  RuleBase16 R16;
  RuleBase17 R17;
  RuleBase18 R18;
  RuleBase19 R19;
  RuleBase20 R20;
  RuleBase21 R21;
  RuleBase22 R22;
  RuleBase23 R23;
  RuleBase24 R24;
  RuleBase25 R25;
  RuleBase26 R26;
  RuleBase27 R27;
  RuleBase28 R28;
  RuleBase29 R29;
  RuleBase30 R30;
  RuleBase31 R31;
  RuleBase32 R32;
public:
void SetNextEnabledRule(RULE_INDEX_TYPE & what_rule)
{
  category = CONDITION;
  if (what_rule<1)
    { R0.NextRule(what_rule);
      if (what_rule<1) return; }
  if (what_rule>=1 && what_rule<2)
    { R1.NextRule(what_rule);
      if (what_rule<2) return; }
  if (what_rule>=2 && what_rule<3)
    { R2.NextRule(what_rule);
      if (what_rule<3) return; }
  if (what_rule>=3 && what_rule<4)
    { R3.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<5)
    { R4.NextRule(what_rule);
      if (what_rule<5) return; }
  if (what_rule>=5 && what_rule<6)
    { R5.NextRule(what_rule);
      if (what_rule<6) return; }
  if (what_rule>=6 && what_rule<7)
    { R6.NextRule(what_rule);
      if (what_rule<7) return; }
  if (what_rule>=7 && what_rule<8)
    { R7.NextRule(what_rule);
      if (what_rule<8) return; }
  if (what_rule>=8 && what_rule<9)
    { R8.NextRule(what_rule);
      if (what_rule<9) return; }
  if (what_rule>=9 && what_rule<10)
    { R9.NextRule(what_rule);
      if (what_rule<10) return; }
  if (what_rule>=10 && what_rule<11)
    { R10.NextRule(what_rule);
      if (what_rule<11) return; }
  if (what_rule>=11 && what_rule<12)
    { R11.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<13)
    { R12.NextRule(what_rule);
      if (what_rule<13) return; }
  if (what_rule>=13 && what_rule<14)
    { R13.NextRule(what_rule);
      if (what_rule<14) return; }
  if (what_rule>=14 && what_rule<15)
    { R14.NextRule(what_rule);
      if (what_rule<15) return; }
  if (what_rule>=15 && what_rule<16)
    { R15.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<17)
    { R16.NextRule(what_rule);
      if (what_rule<17) return; }
  if (what_rule>=17 && what_rule<18)
    { R17.NextRule(what_rule);
      if (what_rule<18) return; }
  if (what_rule>=18 && what_rule<19)
    { R18.NextRule(what_rule);
      if (what_rule<19) return; }
  if (what_rule>=19 && what_rule<20)
    { R19.NextRule(what_rule);
      if (what_rule<20) return; }
  if (what_rule>=20 && what_rule<21)
    { R20.NextRule(what_rule);
      if (what_rule<21) return; }
  if (what_rule>=21 && what_rule<22)
    { R21.NextRule(what_rule);
      if (what_rule<22) return; }
  if (what_rule>=22 && what_rule<23)
    { R22.NextRule(what_rule);
      if (what_rule<23) return; }
  if (what_rule>=23 && what_rule<24)
    { R23.NextRule(what_rule);
      if (what_rule<24) return; }
  if (what_rule>=24 && what_rule<25)
    { R24.NextRule(what_rule);
      if (what_rule<25) return; }
  if (what_rule>=25 && what_rule<26)
    { R25.NextRule(what_rule);
      if (what_rule<26) return; }
  if (what_rule>=26 && what_rule<27)
    { R26.NextRule(what_rule);
      if (what_rule<27) return; }
  if (what_rule>=27 && what_rule<28)
    { R27.NextRule(what_rule);
      if (what_rule<28) return; }
  if (what_rule>=28 && what_rule<29)
    { R28.NextRule(what_rule);
      if (what_rule<29) return; }
  if (what_rule>=29 && what_rule<30)
    { R29.NextRule(what_rule);
      if (what_rule<30) return; }
  if (what_rule>=30 && what_rule<31)
    { R30.NextRule(what_rule);
      if (what_rule<31) return; }
  if (what_rule>=31 && what_rule<32)
    { R31.NextRule(what_rule);
      if (what_rule<32) return; }
  if (what_rule>=32 && what_rule<33)
    { R32.NextRule(what_rule);
      if (what_rule<33) return; }
}
bool Condition(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
  if (r>=2 && r<=2) return R2.Condition(r-2);
  if (r>=3 && r<=3) return R3.Condition(r-3);
  if (r>=4 && r<=4) return R4.Condition(r-4);
  if (r>=5 && r<=5) return R5.Condition(r-5);
  if (r>=6 && r<=6) return R6.Condition(r-6);
  if (r>=7 && r<=7) return R7.Condition(r-7);
  if (r>=8 && r<=8) return R8.Condition(r-8);
  if (r>=9 && r<=9) return R9.Condition(r-9);
  if (r>=10 && r<=10) return R10.Condition(r-10);
  if (r>=11 && r<=11) return R11.Condition(r-11);
  if (r>=12 && r<=12) return R12.Condition(r-12);
  if (r>=13 && r<=13) return R13.Condition(r-13);
  if (r>=14 && r<=14) return R14.Condition(r-14);
  if (r>=15 && r<=15) return R15.Condition(r-15);
  if (r>=16 && r<=16) return R16.Condition(r-16);
  if (r>=17 && r<=17) return R17.Condition(r-17);
  if (r>=18 && r<=18) return R18.Condition(r-18);
  if (r>=19 && r<=19) return R19.Condition(r-19);
  if (r>=20 && r<=20) return R20.Condition(r-20);
  if (r>=21 && r<=21) return R21.Condition(r-21);
  if (r>=22 && r<=22) return R22.Condition(r-22);
  if (r>=23 && r<=23) return R23.Condition(r-23);
  if (r>=24 && r<=24) return R24.Condition(r-24);
  if (r>=25 && r<=25) return R25.Condition(r-25);
  if (r>=26 && r<=26) return R26.Condition(r-26);
  if (r>=27 && r<=27) return R27.Condition(r-27);
  if (r>=28 && r<=28) return R28.Condition(r-28);
  if (r>=29 && r<=29) return R29.Condition(r-29);
  if (r>=30 && r<=30) return R30.Condition(r-30);
  if (r>=31 && r<=31) return R31.Condition(r-31);
  if (r>=32 && r<=32) return R32.Condition(r-32);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code(r-2); return; } 
  if (r>=3 && r<=3) { R3.Code(r-3); return; } 
  if (r>=4 && r<=4) { R4.Code(r-4); return; } 
  if (r>=5 && r<=5) { R5.Code(r-5); return; } 
  if (r>=6 && r<=6) { R6.Code(r-6); return; } 
  if (r>=7 && r<=7) { R7.Code(r-7); return; } 
  if (r>=8 && r<=8) { R8.Code(r-8); return; } 
  if (r>=9 && r<=9) { R9.Code(r-9); return; } 
  if (r>=10 && r<=10) { R10.Code(r-10); return; } 
  if (r>=11 && r<=11) { R11.Code(r-11); return; } 
  if (r>=12 && r<=12) { R12.Code(r-12); return; } 
  if (r>=13 && r<=13) { R13.Code(r-13); return; } 
  if (r>=14 && r<=14) { R14.Code(r-14); return; } 
  if (r>=15 && r<=15) { R15.Code(r-15); return; } 
  if (r>=16 && r<=16) { R16.Code(r-16); return; } 
  if (r>=17 && r<=17) { R17.Code(r-17); return; } 
  if (r>=18 && r<=18) { R18.Code(r-18); return; } 
  if (r>=19 && r<=19) { R19.Code(r-19); return; } 
  if (r>=20 && r<=20) { R20.Code(r-20); return; } 
  if (r>=21 && r<=21) { R21.Code(r-21); return; } 
  if (r>=22 && r<=22) { R22.Code(r-22); return; } 
  if (r>=23 && r<=23) { R23.Code(r-23); return; } 
  if (r>=24 && r<=24) { R24.Code(r-24); return; } 
  if (r>=25 && r<=25) { R25.Code(r-25); return; } 
  if (r>=26 && r<=26) { R26.Code(r-26); return; } 
  if (r>=27 && r<=27) { R27.Code(r-27); return; } 
  if (r>=28 && r<=28) { R28.Code(r-28); return; } 
  if (r>=29 && r<=29) { R29.Code(r-29); return; } 
  if (r>=30 && r<=30) { R30.Code(r-30); return; } 
  if (r>=31 && r<=31) { R31.Code(r-31); return; } 
  if (r>=32 && r<=32) { R32.Code(r-32); return; } 
}
int Priority(RULE_INDEX_TYPE r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
  if (r>=2 && r<=2) { return R2.Priority(); } 
  if (r>=3 && r<=3) { return R3.Priority(); } 
  if (r>=4 && r<=4) { return R4.Priority(); } 
  if (r>=5 && r<=5) { return R5.Priority(); } 
  if (r>=6 && r<=6) { return R6.Priority(); } 
  if (r>=7 && r<=7) { return R7.Priority(); } 
  if (r>=8 && r<=8) { return R8.Priority(); } 
  if (r>=9 && r<=9) { return R9.Priority(); } 
  if (r>=10 && r<=10) { return R10.Priority(); } 
  if (r>=11 && r<=11) { return R11.Priority(); } 
  if (r>=12 && r<=12) { return R12.Priority(); } 
  if (r>=13 && r<=13) { return R13.Priority(); } 
  if (r>=14 && r<=14) { return R14.Priority(); } 
  if (r>=15 && r<=15) { return R15.Priority(); } 
  if (r>=16 && r<=16) { return R16.Priority(); } 
  if (r>=17 && r<=17) { return R17.Priority(); } 
  if (r>=18 && r<=18) { return R18.Priority(); } 
  if (r>=19 && r<=19) { return R19.Priority(); } 
  if (r>=20 && r<=20) { return R20.Priority(); } 
  if (r>=21 && r<=21) { return R21.Priority(); } 
  if (r>=22 && r<=22) { return R22.Priority(); } 
  if (r>=23 && r<=23) { return R23.Priority(); } 
  if (r>=24 && r<=24) { return R24.Priority(); } 
  if (r>=25 && r<=25) { return R25.Priority(); } 
  if (r>=26 && r<=26) { return R26.Priority(); } 
  if (r>=27 && r<=27) { return R27.Priority(); } 
  if (r>=28 && r<=28) { return R28.Priority(); } 
  if (r>=29 && r<=29) { return R29.Priority(); } 
  if (r>=30 && r<=30) { return R30.Priority(); } 
  if (r>=31 && r<=31) { return R31.Priority(); } 
  if (r>=32 && r<=32) { return R32.Priority(); } 
}
char * Name(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  if (r>=2 && r<=2) return R2.Name(r-2);
  if (r>=3 && r<=3) return R3.Name(r-3);
  if (r>=4 && r<=4) return R4.Name(r-4);
  if (r>=5 && r<=5) return R5.Name(r-5);
  if (r>=6 && r<=6) return R6.Name(r-6);
  if (r>=7 && r<=7) return R7.Name(r-7);
  if (r>=8 && r<=8) return R8.Name(r-8);
  if (r>=9 && r<=9) return R9.Name(r-9);
  if (r>=10 && r<=10) return R10.Name(r-10);
  if (r>=11 && r<=11) return R11.Name(r-11);
  if (r>=12 && r<=12) return R12.Name(r-12);
  if (r>=13 && r<=13) return R13.Name(r-13);
  if (r>=14 && r<=14) return R14.Name(r-14);
  if (r>=15 && r<=15) return R15.Name(r-15);
  if (r>=16 && r<=16) return R16.Name(r-16);
  if (r>=17 && r<=17) return R17.Name(r-17);
  if (r>=18 && r<=18) return R18.Name(r-18);
  if (r>=19 && r<=19) return R19.Name(r-19);
  if (r>=20 && r<=20) return R20.Name(r-20);
  if (r>=21 && r<=21) return R21.Name(r-21);
  if (r>=22 && r<=22) return R22.Name(r-22);
  if (r>=23 && r<=23) return R23.Name(r-23);
  if (r>=24 && r<=24) return R24.Name(r-24);
  if (r>=25 && r<=25) return R25.Name(r-25);
  if (r>=26 && r<=26) return R26.Name(r-26);
  if (r>=27 && r<=27) return R27.Name(r-27);
  if (r>=28 && r<=28) return R28.Name(r-28);
  if (r>=29 && r<=29) return R29.Name(r-29);
  if (r>=30 && r<=30) return R30.Name(r-30);
  if (r>=31 && r<=31) return R31.Name(r-31);
  if (r>=32 && r<=32) return R32.Name(r-32);
  return NULL;
}
int Duration(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Duration(r-0);
  if (r>=1 && r<=1) return R1.Duration(r-1);
  if (r>=2 && r<=2) return R2.Duration(r-2);
  if (r>=3 && r<=3) return R3.Duration(r-3);
  if (r>=4 && r<=4) return R4.Duration(r-4);
  if (r>=5 && r<=5) return R5.Duration(r-5);
  if (r>=6 && r<=6) return R6.Duration(r-6);
  if (r>=7 && r<=7) return R7.Duration(r-7);
  if (r>=8 && r<=8) return R8.Duration(r-8);
  if (r>=9 && r<=9) return R9.Duration(r-9);
  if (r>=10 && r<=10) return R10.Duration(r-10);
  if (r>=11 && r<=11) return R11.Duration(r-11);
  if (r>=12 && r<=12) return R12.Duration(r-12);
  if (r>=13 && r<=13) return R13.Duration(r-13);
  if (r>=14 && r<=14) return R14.Duration(r-14);
  if (r>=15 && r<=15) return R15.Duration(r-15);
  if (r>=16 && r<=16) return R16.Duration(r-16);
  if (r>=17 && r<=17) return R17.Duration(r-17);
  if (r>=18 && r<=18) return R18.Duration(r-18);
  if (r>=19 && r<=19) return R19.Duration(r-19);
  if (r>=20 && r<=20) return R20.Duration(r-20);
  if (r>=21 && r<=21) return R21.Duration(r-21);
  if (r>=22 && r<=22) return R22.Duration(r-22);
  if (r>=23 && r<=23) return R23.Duration(r-23);
  if (r>=24 && r<=24) return R24.Duration(r-24);
  if (r>=25 && r<=25) return R25.Duration(r-25);
  if (r>=26 && r<=26) return R26.Duration(r-26);
  if (r>=27 && r<=27) return R27.Duration(r-27);
  if (r>=28 && r<=28) return R28.Duration(r-28);
  if (r>=29 && r<=29) return R29.Duration(r-29);
  if (r>=30 && r<=30) return R30.Duration(r-30);
  if (r>=31 && r<=31) return R31.Duration(r-31);
  if (r>=32 && r<=32) return R32.Duration(r-32);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
int Weight(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Weight(r-0);
  if (r>=1 && r<=1) return R1.Weight(r-1);
  if (r>=2 && r<=2) return R2.Weight(r-2);
  if (r>=3 && r<=3) return R3.Weight(r-3);
  if (r>=4 && r<=4) return R4.Weight(r-4);
  if (r>=5 && r<=5) return R5.Weight(r-5);
  if (r>=6 && r<=6) return R6.Weight(r-6);
  if (r>=7 && r<=7) return R7.Weight(r-7);
  if (r>=8 && r<=8) return R8.Weight(r-8);
  if (r>=9 && r<=9) return R9.Weight(r-9);
  if (r>=10 && r<=10) return R10.Weight(r-10);
  if (r>=11 && r<=11) return R11.Weight(r-11);
  if (r>=12 && r<=12) return R12.Weight(r-12);
  if (r>=13 && r<=13) return R13.Weight(r-13);
  if (r>=14 && r<=14) return R14.Weight(r-14);
  if (r>=15 && r<=15) return R15.Weight(r-15);
  if (r>=16 && r<=16) return R16.Weight(r-16);
  if (r>=17 && r<=17) return R17.Weight(r-17);
  if (r>=18 && r<=18) return R18.Weight(r-18);
  if (r>=19 && r<=19) return R19.Weight(r-19);
  if (r>=20 && r<=20) return R20.Weight(r-20);
  if (r>=21 && r<=21) return R21.Weight(r-21);
  if (r>=22 && r<=22) return R22.Weight(r-22);
  if (r>=23 && r<=23) return R23.Weight(r-23);
  if (r>=24 && r<=24) return R24.Weight(r-24);
  if (r>=25 && r<=25) return R25.Weight(r-25);
  if (r>=26 && r<=26) return R26.Weight(r-26);
  if (r>=27 && r<=27) return R27.Weight(r-27);
  if (r>=28 && r<=28) return R28.Weight(r-28);
  if (r>=29 && r<=29) return R29.Weight(r-29);
  if (r>=30 && r<=30) return R30.Weight(r-30);
  if (r>=31 && r<=31) return R31.Weight(r-31);
  if (r>=32 && r<=32) return R32.Weight(r-32);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
char * PDDLName(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLName(r-0);
  if (r>=1 && r<=1) return R1.PDDLName(r-1);
  if (r>=2 && r<=2) return R2.PDDLName(r-2);
  if (r>=3 && r<=3) return R3.PDDLName(r-3);
  if (r>=4 && r<=4) return R4.PDDLName(r-4);
  if (r>=5 && r<=5) return R5.PDDLName(r-5);
  if (r>=6 && r<=6) return R6.PDDLName(r-6);
  if (r>=7 && r<=7) return R7.PDDLName(r-7);
  if (r>=8 && r<=8) return R8.PDDLName(r-8);
  if (r>=9 && r<=9) return R9.PDDLName(r-9);
  if (r>=10 && r<=10) return R10.PDDLName(r-10);
  if (r>=11 && r<=11) return R11.PDDLName(r-11);
  if (r>=12 && r<=12) return R12.PDDLName(r-12);
  if (r>=13 && r<=13) return R13.PDDLName(r-13);
  if (r>=14 && r<=14) return R14.PDDLName(r-14);
  if (r>=15 && r<=15) return R15.PDDLName(r-15);
  if (r>=16 && r<=16) return R16.PDDLName(r-16);
  if (r>=17 && r<=17) return R17.PDDLName(r-17);
  if (r>=18 && r<=18) return R18.PDDLName(r-18);
  if (r>=19 && r<=19) return R19.PDDLName(r-19);
  if (r>=20 && r<=20) return R20.PDDLName(r-20);
  if (r>=21 && r<=21) return R21.PDDLName(r-21);
  if (r>=22 && r<=22) return R22.PDDLName(r-22);
  if (r>=23 && r<=23) return R23.PDDLName(r-23);
  if (r>=24 && r<=24) return R24.PDDLName(r-24);
  if (r>=25 && r<=25) return R25.PDDLName(r-25);
  if (r>=26 && r<=26) return R26.PDDLName(r-26);
  if (r>=27 && r<=27) return R27.PDDLName(r-27);
  if (r>=28 && r<=28) return R28.PDDLName(r-28);
  if (r>=29 && r<=29) return R29.PDDLName(r-29);
  if (r>=30 && r<=30) return R30.PDDLName(r-30);
  if (r>=31 && r<=31) return R31.PDDLName(r-31);
  if (r>=32 && r<=32) return R32.PDDLName(r-32);
  return NULL;
}
RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLClass(r-0);
  if (r>=1 && r<=1) return R1.PDDLClass(r-1);
  if (r>=2 && r<=2) return R2.PDDLClass(r-2);
  if (r>=3 && r<=3) return R3.PDDLClass(r-3);
  if (r>=4 && r<=4) return R4.PDDLClass(r-4);
  if (r>=5 && r<=5) return R5.PDDLClass(r-5);
  if (r>=6 && r<=6) return R6.PDDLClass(r-6);
  if (r>=7 && r<=7) return R7.PDDLClass(r-7);
  if (r>=8 && r<=8) return R8.PDDLClass(r-8);
  if (r>=9 && r<=9) return R9.PDDLClass(r-9);
  if (r>=10 && r<=10) return R10.PDDLClass(r-10);
  if (r>=11 && r<=11) return R11.PDDLClass(r-11);
  if (r>=12 && r<=12) return R12.PDDLClass(r-12);
  if (r>=13 && r<=13) return R13.PDDLClass(r-13);
  if (r>=14 && r<=14) return R14.PDDLClass(r-14);
  if (r>=15 && r<=15) return R15.PDDLClass(r-15);
  if (r>=16 && r<=16) return R16.PDDLClass(r-16);
  if (r>=17 && r<=17) return R17.PDDLClass(r-17);
  if (r>=18 && r<=18) return R18.PDDLClass(r-18);
  if (r>=19 && r<=19) return R19.PDDLClass(r-19);
  if (r>=20 && r<=20) return R20.PDDLClass(r-20);
  if (r>=21 && r<=21) return R21.PDDLClass(r-21);
  if (r>=22 && r<=22) return R22.PDDLClass(r-22);
  if (r>=23 && r<=23) return R23.PDDLClass(r-23);
  if (r>=24 && r<=24) return R24.PDDLClass(r-24);
  if (r>=25 && r<=25) return R25.PDDLClass(r-25);
  if (r>=26 && r<=26) return R26.PDDLClass(r-26);
  if (r>=27 && r<=27) return R27.PDDLClass(r-27);
  if (r>=28 && r<=28) return R28.PDDLClass(r-28);
  if (r>=29 && r<=29) return R29.PDDLClass(r-29);
  if (r>=30 && r<=30) return R30.PDDLClass(r-30);
  if (r>=31 && r<=31) return R31.PDDLClass(r-31);
  if (r>=32 && r<=32) return R32.PDDLClass(r-32);
Error.Notrace("Internal: NextStateGenerator -- querying PDDL class for nonexisting rule.");
}
};
const RULE_INDEX_TYPE numrules = 33;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 33


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 19 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 8.940000e+00;
  };

};
/******************** StartStateBase1 ********************/
class StartStateBase1
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 18 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 8.680000e+00;
  };

};
/******************** StartStateBase2 ********************/
class StartStateBase2
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 17 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 8.420000e+00;
  };

};
/******************** StartStateBase3 ********************/
class StartStateBase3
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 16 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 8.160000e+00;
  };

};
/******************** StartStateBase4 ********************/
class StartStateBase4
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 15 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 7.900000e+00;
  };

};
/******************** StartStateBase5 ********************/
class StartStateBase5
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 14 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 7.640000e+00;
  };

};
/******************** StartStateBase6 ********************/
class StartStateBase6
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 13 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 7.380000e+00;
  };

};
/******************** StartStateBase7 ********************/
class StartStateBase7
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 12 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 7.120000e+00;
  };

};
/******************** StartStateBase8 ********************/
class StartStateBase8
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 11 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 6.860000e+00;
  };

};
/******************** StartStateBase9 ********************/
class StartStateBase9
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 10 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 6.600000e+00;
  };

};
/******************** StartStateBase10 ********************/
class StartStateBase10
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 9 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 6.340000e+00;
  };

};
/******************** StartStateBase11 ********************/
class StartStateBase11
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 8 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 6.080000e+00;
  };

};
/******************** StartStateBase12 ********************/
class StartStateBase12
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 7 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 5.820000e+00;
  };

};
/******************** StartStateBase13 ********************/
class StartStateBase13
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 6 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 5.560000e+00;
  };

};
/******************** StartStateBase14 ********************/
class StartStateBase14
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 5 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 5.300000e+00;
  };

};
/******************** StartStateBase15 ********************/
class StartStateBase15
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 4 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 5.040000e+00;
  };

};
/******************** StartStateBase16 ********************/
class StartStateBase16
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 3 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 4.780000e+00;
  };

};
/******************** StartStateBase17 ********************/
class StartStateBase17
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 2 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 4.520000e+00;
  };

};
/******************** StartStateBase18 ********************/
class StartStateBase18
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 1 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 4.260000e+00;
  };

};
/******************** StartStateBase19 ********************/
class StartStateBase19
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("startstate 0 ");
  }
  void Code(unsigned short r)
  {
mu_valve_1 = mu_false;
mu_valve_2 = mu_false;
mu_valve_3 = mu_false;
mu_valve_4 = mu_false;
mu_valve_5 = mu_false;
mu_valve_6 = mu_false;
mu_valve_7 = mu_false;
mu_valve_8 = mu_false;
mu_valve_9 = mu_false;
mu_valve_10 = mu_false;
mu_valve_11 = mu_false;
mu_valve_12 = mu_false;
mu_valve_13 = mu_false;
mu_valve_14 = mu_false;
mu_valve_15 = mu_false;
mu_valve_16 = mu_false;
mu_valve_17 = mu_false;
mu_valve_18 = mu_false;
mu_valve_19 = mu_false;
mu_valve_20 = mu_false;
mu_valve_21 = mu_false;
mu_valve_22 = mu_false;
mu_valve_23 = mu_false;
mu_valve_24 = mu_false;
mu_valve_25 = mu_false;
mu_valve_26 = mu_false;
mu_valve_27 = mu_false;
mu_valve_28 = mu_false;
mu_valve_29 = mu_false;
mu_filling_b3_done = mu_false;
mu_concentration_reached = mu_false;
mu_get_production_done = mu_false;
mu_filling_b4_done = mu_false;
mu_filling_b5_done = mu_false;
mu_high_concentration_reached = mu_false;
mu_filling_b7_done = mu_false;
mu_cooled_b6 = mu_false;
mu_cooled_b7 = mu_false;
mu_filling_b1_done = mu_false;
mu_filling_b2_done = mu_false;
mu_pump_1 = mu_false;
mu_pump_2 = mu_false;
mu_heater_5 = mu_false;
mu_c_1 = mu_START_CONCENTRATION_B1;
mu_c_2 = 0;
mu_c_3 = 0;
mu_c_5 = 0;
mu_T_5 = 25;
mu_T_6 = 25;
mu_T_7 = 25;
mu_level_b1 = mu_START_LEVEL_B1;
mu_level_b2 = mu_START_LEVEL_B2;
mu_level_b3 = 0;
mu_level_b3_recycle = 0;
mu_level_b4 = 0;
mu_level_b5 = 0;
mu_level_b6 = 0;
mu_level_b7 = 0;
mu_time = 0;
mu_isGoal_part = mu_false;
mu_isGoal_final = mu_false;
mu_systemProperties = mu_true;
mu_LEVEL_TARGET = 4.000000e+00;
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
  StartStateBase1 S1;
  StartStateBase2 S2;
  StartStateBase3 S3;
  StartStateBase4 S4;
  StartStateBase5 S5;
  StartStateBase6 S6;
  StartStateBase7 S7;
  StartStateBase8 S8;
  StartStateBase9 S9;
  StartStateBase10 S10;
  StartStateBase11 S11;
  StartStateBase12 S12;
  StartStateBase13 S13;
  StartStateBase14 S14;
  StartStateBase15 S15;
  StartStateBase16 S16;
  StartStateBase17 S17;
  StartStateBase18 S18;
  StartStateBase19 S19;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
  if (r>=1 && r<=1) { S1.Code(r-1); return; }
  if (r>=2 && r<=2) { S2.Code(r-2); return; }
  if (r>=3 && r<=3) { S3.Code(r-3); return; }
  if (r>=4 && r<=4) { S4.Code(r-4); return; }
  if (r>=5 && r<=5) { S5.Code(r-5); return; }
  if (r>=6 && r<=6) { S6.Code(r-6); return; }
  if (r>=7 && r<=7) { S7.Code(r-7); return; }
  if (r>=8 && r<=8) { S8.Code(r-8); return; }
  if (r>=9 && r<=9) { S9.Code(r-9); return; }
  if (r>=10 && r<=10) { S10.Code(r-10); return; }
  if (r>=11 && r<=11) { S11.Code(r-11); return; }
  if (r>=12 && r<=12) { S12.Code(r-12); return; }
  if (r>=13 && r<=13) { S13.Code(r-13); return; }
  if (r>=14 && r<=14) { S14.Code(r-14); return; }
  if (r>=15 && r<=15) { S15.Code(r-15); return; }
  if (r>=16 && r<=16) { S16.Code(r-16); return; }
  if (r>=17 && r<=17) { S17.Code(r-17); return; }
  if (r>=18 && r<=18) { S18.Code(r-18); return; }
  if (r>=19 && r<=19) { S19.Code(r-19); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  if (r>=1 && r<=1) return S1.Name(r-1);
  if (r>=2 && r<=2) return S2.Name(r-2);
  if (r>=3 && r<=3) return S3.Name(r-3);
  if (r>=4 && r<=4) return S4.Name(r-4);
  if (r>=5 && r<=5) return S5.Name(r-5);
  if (r>=6 && r<=6) return S6.Name(r-6);
  if (r>=7 && r<=7) return S7.Name(r-7);
  if (r>=8 && r<=8) return S8.Name(r-8);
  if (r>=9 && r<=9) return S9.Name(r-9);
  if (r>=10 && r<=10) return S10.Name(r-10);
  if (r>=11 && r<=11) return S11.Name(r-11);
  if (r>=12 && r<=12) return S12.Name(r-12);
  if (r>=13 && r<=13) return S13.Name(r-13);
  if (r>=14 && r<=14) return S14.Name(r-14);
  if (r>=15 && r<=15) return S15.Name(r-15);
  if (r>=16 && r<=16) return S16.Name(r-16);
  if (r>=17 && r<=17) return S17.Name(r-17);
  if (r>=18 && r<=18) return S18.Name(r-18);
  if (r>=19 && r<=19) return S19.Name(r-19);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 20;

/********************
  Goal records
 ********************/
int mu__goal_353() // Goal "goal"
{
bool mu__boolexpr354;
  if (!((mu_isGoal_final) == (mu_true))) mu__boolexpr354 = FALSE ;
  else {
  mu__boolexpr354 = ((mu_systemProperties) == (mu_true)) ; 
}
return mu__boolexpr354;
};

bool mu__condition_355() // Condition for Rule "goal"
{
  return mu__goal_353( );
}

/**** end rule declaration ****/

const rulerec goals[] = {
{"goal", &mu__condition_355, NULL, },
};
const unsigned short numgoals = 1;

/********************
  Metric related stuff
 ********************/
const short metric = -1;

/********************
  Invariant records
 ********************/
const rulerec invariants[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numinvariants = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
cooled_b6:NoScalarset
filling_b1_done:NoScalarset
high_concentration_reached:NoScalarset
filling_b4_done:NoScalarset
concentration_reached:NoScalarset
systemProperties:NoScalarset
isGoal_part:NoScalarset
level_b7:NoScalarset
level_b5:NoScalarset
level_b3_recycle:NoScalarset
level_b2:NoScalarset
T_7:NoScalarset
T_5:NoScalarset
c_3:NoScalarset
c_1:NoScalarset
pump_2:NoScalarset
LEVEL_TARGET:NoScalarset
valve_28:NoScalarset
valve_26:NoScalarset
valve_24:NoScalarset
valve_22:NoScalarset
valve_20:NoScalarset
valve_18:NoScalarset
valve_16:NoScalarset
valve_14:NoScalarset
valve_12:NoScalarset
valve_10:NoScalarset
valve_8:NoScalarset
valve_6:NoScalarset
valve_4:NoScalarset
valve_2:NoScalarset
valve_1:NoScalarset
valve_3:NoScalarset
valve_5:NoScalarset
valve_7:NoScalarset
valve_9:NoScalarset
valve_11:NoScalarset
valve_13:NoScalarset
valve_15:NoScalarset
valve_17:NoScalarset
valve_19:NoScalarset
valve_21:NoScalarset
valve_23:NoScalarset
valve_25:NoScalarset
valve_27:NoScalarset
valve_29:NoScalarset
pump_1:NoScalarset
heater_5:NoScalarset
c_2:NoScalarset
c_5:NoScalarset
T_6:NoScalarset
level_b1:NoScalarset
level_b3:NoScalarset
level_b4:NoScalarset
level_b6:NoScalarset
time:NoScalarset
isGoal_final:NoScalarset
filling_b3_done:NoScalarset
get_production_done:NoScalarset
filling_b5_done:NoScalarset
filling_b7_done:NoScalarset
filling_b2_done:NoScalarset
cooled_b7:NoScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { unsigned long ret=0; for (unsigned long i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_cooled_b6.MultisetSort();
        mu_filling_b1_done.MultisetSort();
        mu_high_concentration_reached.MultisetSort();
        mu_filling_b4_done.MultisetSort();
        mu_concentration_reached.MultisetSort();
        mu_systemProperties.MultisetSort();
        mu_isGoal_part.MultisetSort();
        mu_level_b7.MultisetSort();
        mu_level_b5.MultisetSort();
        mu_level_b3_recycle.MultisetSort();
        mu_level_b2.MultisetSort();
        mu_T_7.MultisetSort();
        mu_T_5.MultisetSort();
        mu_c_3.MultisetSort();
        mu_c_1.MultisetSort();
        mu_pump_2.MultisetSort();
        mu_LEVEL_TARGET.MultisetSort();
        mu_valve_28.MultisetSort();
        mu_valve_26.MultisetSort();
        mu_valve_24.MultisetSort();
        mu_valve_22.MultisetSort();
        mu_valve_20.MultisetSort();
        mu_valve_18.MultisetSort();
        mu_valve_16.MultisetSort();
        mu_valve_14.MultisetSort();
        mu_valve_12.MultisetSort();
        mu_valve_10.MultisetSort();
        mu_valve_8.MultisetSort();
        mu_valve_6.MultisetSort();
        mu_valve_4.MultisetSort();
        mu_valve_2.MultisetSort();
        mu_valve_1.MultisetSort();
        mu_valve_3.MultisetSort();
        mu_valve_5.MultisetSort();
        mu_valve_7.MultisetSort();
        mu_valve_9.MultisetSort();
        mu_valve_11.MultisetSort();
        mu_valve_13.MultisetSort();
        mu_valve_15.MultisetSort();
        mu_valve_17.MultisetSort();
        mu_valve_19.MultisetSort();
        mu_valve_21.MultisetSort();
        mu_valve_23.MultisetSort();
        mu_valve_25.MultisetSort();
        mu_valve_27.MultisetSort();
        mu_valve_29.MultisetSort();
        mu_pump_1.MultisetSort();
        mu_heater_5.MultisetSort();
        mu_c_2.MultisetSort();
        mu_c_5.MultisetSort();
        mu_T_6.MultisetSort();
        mu_level_b1.MultisetSort();
        mu_level_b3.MultisetSort();
        mu_level_b4.MultisetSort();
        mu_level_b6.MultisetSort();
        mu_time.MultisetSort();
        mu_isGoal_final.MultisetSort();
        mu_filling_b3_done.MultisetSort();
        mu_get_production_done.MultisetSort();
        mu_filling_b5_done.MultisetSort();
        mu_filling_b7_done.MultisetSort();
        mu_filling_b2_done.MultisetSort();
        mu_cooled_b7.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_interval_time::Permute(PermSet& Perm, int i) {};
void mu_1_interval_time::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_interval_time::Canonicalize(PermSet& Perm) {};
void mu_1_interval_time::SimpleLimit(PermSet& Perm) {};
void mu_1_interval_time::ArrayLimit(PermSet& Perm) {};
void mu_1_interval_time::Limit(PermSet& Perm) {};
void mu_1_interval_time::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_real_type::Permute(PermSet& Perm, int i) {};
void mu_1_real_type::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_real_type::Canonicalize(PermSet& Perm) {};
void mu_1_real_type::SimpleLimit(PermSet& Perm) {};
void mu_1_real_type::ArrayLimit(PermSet& Perm) {};
void mu_1_real_type::Limit(PermSet& Perm) {};
void mu_1_real_type::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for real type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  unsigned int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_cooled_b6.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cooled_b6.MultisetSort();
              mu_filling_b1_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_filling_b1_done.MultisetSort();
              mu_high_concentration_reached.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_high_concentration_reached.MultisetSort();
              mu_filling_b4_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_filling_b4_done.MultisetSort();
              mu_concentration_reached.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_concentration_reached.MultisetSort();
              mu_systemProperties.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_systemProperties.MultisetSort();
              mu_isGoal_part.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_isGoal_part.MultisetSort();
              mu_level_b7.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b7.MultisetSort();
              mu_level_b5.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b5.MultisetSort();
              mu_level_b3_recycle.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b3_recycle.MultisetSort();
              mu_level_b2.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b2.MultisetSort();
              mu_T_7.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_T_7.MultisetSort();
              mu_T_5.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_T_5.MultisetSort();
              mu_c_3.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_c_3.MultisetSort();
              mu_c_1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_c_1.MultisetSort();
              mu_pump_2.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_pump_2.MultisetSort();
              mu_LEVEL_TARGET.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LEVEL_TARGET.MultisetSort();
              mu_valve_28.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_28.MultisetSort();
              mu_valve_26.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_26.MultisetSort();
              mu_valve_24.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_24.MultisetSort();
              mu_valve_22.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_22.MultisetSort();
              mu_valve_20.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_20.MultisetSort();
              mu_valve_18.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_18.MultisetSort();
              mu_valve_16.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_16.MultisetSort();
              mu_valve_14.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_14.MultisetSort();
              mu_valve_12.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_12.MultisetSort();
              mu_valve_10.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_10.MultisetSort();
              mu_valve_8.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_8.MultisetSort();
              mu_valve_6.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_6.MultisetSort();
              mu_valve_4.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_4.MultisetSort();
              mu_valve_2.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_2.MultisetSort();
              mu_valve_1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_1.MultisetSort();
              mu_valve_3.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_3.MultisetSort();
              mu_valve_5.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_5.MultisetSort();
              mu_valve_7.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_7.MultisetSort();
              mu_valve_9.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_9.MultisetSort();
              mu_valve_11.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_11.MultisetSort();
              mu_valve_13.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_13.MultisetSort();
              mu_valve_15.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_15.MultisetSort();
              mu_valve_17.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_17.MultisetSort();
              mu_valve_19.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_19.MultisetSort();
              mu_valve_21.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_21.MultisetSort();
              mu_valve_23.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_23.MultisetSort();
              mu_valve_25.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_25.MultisetSort();
              mu_valve_27.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_27.MultisetSort();
              mu_valve_29.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_valve_29.MultisetSort();
              mu_pump_1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_pump_1.MultisetSort();
              mu_heater_5.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_heater_5.MultisetSort();
              mu_c_2.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_c_2.MultisetSort();
              mu_c_5.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_c_5.MultisetSort();
              mu_T_6.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_T_6.MultisetSort();
              mu_level_b1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b1.MultisetSort();
              mu_level_b3.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b3.MultisetSort();
              mu_level_b4.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b4.MultisetSort();
              mu_level_b6.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_level_b6.MultisetSort();
              mu_time.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_time.MultisetSort();
              mu_isGoal_final.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_isGoal_final.MultisetSort();
              mu_filling_b3_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_filling_b3_done.MultisetSort();
              mu_get_production_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_get_production_done.MultisetSort();
              mu_filling_b5_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_filling_b5_done.MultisetSort();
              mu_filling_b7_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_filling_b7_done.MultisetSort();
              mu_filling_b2_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_filling_b2_done.MultisetSort();
              mu_cooled_b7.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cooled_b7.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_cooled_b6.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cooled_b6.MultisetSort();
          mu_filling_b1_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_filling_b1_done.MultisetSort();
          mu_high_concentration_reached.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_high_concentration_reached.MultisetSort();
          mu_filling_b4_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_filling_b4_done.MultisetSort();
          mu_concentration_reached.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_concentration_reached.MultisetSort();
          mu_systemProperties.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_systemProperties.MultisetSort();
          mu_isGoal_part.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_isGoal_part.MultisetSort();
          mu_level_b7.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b7.MultisetSort();
          mu_level_b5.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b5.MultisetSort();
          mu_level_b3_recycle.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b3_recycle.MultisetSort();
          mu_level_b2.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b2.MultisetSort();
          mu_T_7.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_T_7.MultisetSort();
          mu_T_5.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_T_5.MultisetSort();
          mu_c_3.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_c_3.MultisetSort();
          mu_c_1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_c_1.MultisetSort();
          mu_pump_2.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_pump_2.MultisetSort();
          mu_LEVEL_TARGET.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LEVEL_TARGET.MultisetSort();
          mu_valve_28.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_28.MultisetSort();
          mu_valve_26.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_26.MultisetSort();
          mu_valve_24.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_24.MultisetSort();
          mu_valve_22.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_22.MultisetSort();
          mu_valve_20.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_20.MultisetSort();
          mu_valve_18.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_18.MultisetSort();
          mu_valve_16.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_16.MultisetSort();
          mu_valve_14.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_14.MultisetSort();
          mu_valve_12.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_12.MultisetSort();
          mu_valve_10.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_10.MultisetSort();
          mu_valve_8.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_8.MultisetSort();
          mu_valve_6.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_6.MultisetSort();
          mu_valve_4.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_4.MultisetSort();
          mu_valve_2.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_2.MultisetSort();
          mu_valve_1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_1.MultisetSort();
          mu_valve_3.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_3.MultisetSort();
          mu_valve_5.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_5.MultisetSort();
          mu_valve_7.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_7.MultisetSort();
          mu_valve_9.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_9.MultisetSort();
          mu_valve_11.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_11.MultisetSort();
          mu_valve_13.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_13.MultisetSort();
          mu_valve_15.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_15.MultisetSort();
          mu_valve_17.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_17.MultisetSort();
          mu_valve_19.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_19.MultisetSort();
          mu_valve_21.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_21.MultisetSort();
          mu_valve_23.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_23.MultisetSort();
          mu_valve_25.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_25.MultisetSort();
          mu_valve_27.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_27.MultisetSort();
          mu_valve_29.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_valve_29.MultisetSort();
          mu_pump_1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_pump_1.MultisetSort();
          mu_heater_5.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_heater_5.MultisetSort();
          mu_c_2.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_c_2.MultisetSort();
          mu_c_5.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_c_5.MultisetSort();
          mu_T_6.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_T_6.MultisetSort();
          mu_level_b1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b1.MultisetSort();
          mu_level_b3.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b3.MultisetSort();
          mu_level_b4.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b4.MultisetSort();
          mu_level_b6.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_level_b6.MultisetSort();
          mu_time.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_time.MultisetSort();
          mu_isGoal_final.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_isGoal_final.MultisetSort();
          mu_filling_b3_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_filling_b3_done.MultisetSort();
          mu_get_production_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_get_production_done.MultisetSort();
          mu_filling_b5_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_filling_b5_done.MultisetSort();
          mu_filling_b7_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_filling_b7_done.MultisetSort();
          mu_filling_b2_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_filling_b2_done.MultisetSort();
          mu_cooled_b7.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cooled_b7.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_cooled_b6.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cooled_b6.MultisetSort();
              mu_filling_b1_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_filling_b1_done.MultisetSort();
              mu_high_concentration_reached.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_high_concentration_reached.MultisetSort();
              mu_filling_b4_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_filling_b4_done.MultisetSort();
              mu_concentration_reached.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_concentration_reached.MultisetSort();
              mu_systemProperties.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_systemProperties.MultisetSort();
              mu_isGoal_part.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_isGoal_part.MultisetSort();
              mu_level_b7.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b7.MultisetSort();
              mu_level_b5.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b5.MultisetSort();
              mu_level_b3_recycle.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b3_recycle.MultisetSort();
              mu_level_b2.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b2.MultisetSort();
              mu_T_7.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_T_7.MultisetSort();
              mu_T_5.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_T_5.MultisetSort();
              mu_c_3.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_c_3.MultisetSort();
              mu_c_1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_c_1.MultisetSort();
              mu_pump_2.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_pump_2.MultisetSort();
              mu_LEVEL_TARGET.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LEVEL_TARGET.MultisetSort();
              mu_valve_28.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_28.MultisetSort();
              mu_valve_26.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_26.MultisetSort();
              mu_valve_24.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_24.MultisetSort();
              mu_valve_22.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_22.MultisetSort();
              mu_valve_20.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_20.MultisetSort();
              mu_valve_18.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_18.MultisetSort();
              mu_valve_16.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_16.MultisetSort();
              mu_valve_14.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_14.MultisetSort();
              mu_valve_12.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_12.MultisetSort();
              mu_valve_10.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_10.MultisetSort();
              mu_valve_8.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_8.MultisetSort();
              mu_valve_6.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_6.MultisetSort();
              mu_valve_4.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_4.MultisetSort();
              mu_valve_2.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_2.MultisetSort();
              mu_valve_1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_1.MultisetSort();
              mu_valve_3.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_3.MultisetSort();
              mu_valve_5.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_5.MultisetSort();
              mu_valve_7.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_7.MultisetSort();
              mu_valve_9.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_9.MultisetSort();
              mu_valve_11.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_11.MultisetSort();
              mu_valve_13.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_13.MultisetSort();
              mu_valve_15.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_15.MultisetSort();
              mu_valve_17.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_17.MultisetSort();
              mu_valve_19.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_19.MultisetSort();
              mu_valve_21.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_21.MultisetSort();
              mu_valve_23.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_23.MultisetSort();
              mu_valve_25.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_25.MultisetSort();
              mu_valve_27.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_27.MultisetSort();
              mu_valve_29.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_valve_29.MultisetSort();
              mu_pump_1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_pump_1.MultisetSort();
              mu_heater_5.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_heater_5.MultisetSort();
              mu_c_2.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_c_2.MultisetSort();
              mu_c_5.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_c_5.MultisetSort();
              mu_T_6.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_T_6.MultisetSort();
              mu_level_b1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b1.MultisetSort();
              mu_level_b3.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b3.MultisetSort();
              mu_level_b4.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b4.MultisetSort();
              mu_level_b6.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_level_b6.MultisetSort();
              mu_time.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_time.MultisetSort();
              mu_isGoal_final.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_isGoal_final.MultisetSort();
              mu_filling_b3_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_filling_b3_done.MultisetSort();
              mu_get_production_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_get_production_done.MultisetSort();
              mu_filling_b5_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_filling_b5_done.MultisetSort();
              mu_filling_b7_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_filling_b7_done.MultisetSort();
              mu_filling_b2_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_filling_b2_done.MultisetSort();
              mu_cooled_b7.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cooled_b7.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_cooled_b6.MultisetSort();
      mu_filling_b1_done.MultisetSort();
      mu_high_concentration_reached.MultisetSort();
      mu_filling_b4_done.MultisetSort();
      mu_concentration_reached.MultisetSort();
      mu_systemProperties.MultisetSort();
      mu_isGoal_part.MultisetSort();
      mu_level_b7.MultisetSort();
      mu_level_b5.MultisetSort();
      mu_level_b3_recycle.MultisetSort();
      mu_level_b2.MultisetSort();
      mu_T_7.MultisetSort();
      mu_T_5.MultisetSort();
      mu_c_3.MultisetSort();
      mu_c_1.MultisetSort();
      mu_pump_2.MultisetSort();
      mu_LEVEL_TARGET.MultisetSort();
      mu_valve_28.MultisetSort();
      mu_valve_26.MultisetSort();
      mu_valve_24.MultisetSort();
      mu_valve_22.MultisetSort();
      mu_valve_20.MultisetSort();
      mu_valve_18.MultisetSort();
      mu_valve_16.MultisetSort();
      mu_valve_14.MultisetSort();
      mu_valve_12.MultisetSort();
      mu_valve_10.MultisetSort();
      mu_valve_8.MultisetSort();
      mu_valve_6.MultisetSort();
      mu_valve_4.MultisetSort();
      mu_valve_2.MultisetSort();
      mu_valve_1.MultisetSort();
      mu_valve_3.MultisetSort();
      mu_valve_5.MultisetSort();
      mu_valve_7.MultisetSort();
      mu_valve_9.MultisetSort();
      mu_valve_11.MultisetSort();
      mu_valve_13.MultisetSort();
      mu_valve_15.MultisetSort();
      mu_valve_17.MultisetSort();
      mu_valve_19.MultisetSort();
      mu_valve_21.MultisetSort();
      mu_valve_23.MultisetSort();
      mu_valve_25.MultisetSort();
      mu_valve_27.MultisetSort();
      mu_valve_29.MultisetSort();
      mu_pump_1.MultisetSort();
      mu_heater_5.MultisetSort();
      mu_c_2.MultisetSort();
      mu_c_5.MultisetSort();
      mu_T_6.MultisetSort();
      mu_level_b1.MultisetSort();
      mu_level_b3.MultisetSort();
      mu_level_b4.MultisetSort();
      mu_level_b6.MultisetSort();
      mu_time.MultisetSort();
      mu_isGoal_final.MultisetSort();
      mu_filling_b3_done.MultisetSort();
      mu_get_production_done.MultisetSort();
      mu_filling_b5_done.MultisetSort();
      mu_filling_b7_done.MultisetSort();
      mu_filling_b2_done.MultisetSort();
      mu_cooled_b7.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  unsigned int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cooled_b6.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cooled_b6.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_filling_b1_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_filling_b1_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_high_concentration_reached.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_high_concentration_reached.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_filling_b4_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_filling_b4_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_concentration_reached.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_concentration_reached.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_systemProperties.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_systemProperties.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_isGoal_part.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_isGoal_part.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b7.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b7.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b5.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b5.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b3_recycle.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b3_recycle.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b2.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b2.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_T_7.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_T_7.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_T_5.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_T_5.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_c_3.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_c_3.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_c_1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_c_1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_pump_2.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_pump_2.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LEVEL_TARGET.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LEVEL_TARGET.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_28.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_28.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_26.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_26.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_24.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_24.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_22.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_22.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_20.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_20.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_18.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_18.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_16.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_16.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_14.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_14.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_12.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_12.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_10.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_10.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_8.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_8.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_6.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_6.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_4.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_4.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_2.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_2.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_3.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_3.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_5.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_5.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_7.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_7.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_9.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_9.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_11.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_11.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_13.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_13.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_15.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_15.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_17.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_17.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_19.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_19.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_21.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_21.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_23.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_23.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_25.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_25.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_27.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_27.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_valve_29.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_valve_29.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_pump_1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_pump_1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_heater_5.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_heater_5.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_c_2.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_c_2.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_c_5.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_c_5.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_T_6.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_T_6.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b3.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b3.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b4.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b4.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_level_b6.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_level_b6.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_time.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_time.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_isGoal_final.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_isGoal_final.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_filling_b3_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_filling_b3_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_get_production_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_get_production_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_filling_b5_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_filling_b5_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_filling_b7_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_filling_b7_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_filling_b2_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_filling_b2_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cooled_b7.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cooled_b7.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
  Include
 ********************/
#include "upm_epilog.hpp"
