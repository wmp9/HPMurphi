/******************************
  Program "planety-SS99.m" compiled by "Universal Planner Murphi Release 2.0.R8"

  Murphi Last Compiled date: "Nov 26 2013"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Universal Planner Murphi Release 2.0.R8"
#define MURPHI_DATE "Nov 26 2013"
#define PROTOCOL_NAME "planety-SS99"
#define BITS_IN_WORLD 318
#define HASHC

/********************
  Include
 ********************/
#include "upm_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_int_type: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_int_type& val) { return mu__long::operator=((int) val); };
  mu_1_int_type (const char *name, int os): mu__long(0, 1000, 10, name, os) {};
  mu_1_int_type (void): mu__long(0, 1000, 10) {};
  mu_1_int_type (int val): mu__long(0, 1000, 10, "Parameter or function result.", 0)
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
mu_1_int_type mu_1_int_type_undefined_var;

class mu_1_real_type: public mu__real
{
 public:
  inline double operator=(double val) { return mu__real::operator=(val); };
  inline double operator=(const mu_1_real_type& val) { return mu__real::operator=((double) val); };
  mu_1_real_type (const char *name, int os): mu__real(4,5,32,name, os) {};
  mu_1_real_type (void): mu__real(4,5,32) {};
  mu_1_real_type (double val): mu__real(4,5,32,"Parameter or function result.", 0)
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

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 2, 2) {};
  mu_1__type_0 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu_1__type_0 mu_1__type_0_undefined_var;

const double mu_T = +1.000000e-01;
const double mu_solar_const = +3.000000e-02;
const double mu_safelevel = +1.500000e+01;
const double mu_dawn = +3.000000e+00;
const double mu_dusk = +9.000000e+00;
const double mu_heater_rate = +1.510000e+01;
const int mu_commsopen_deadline = 10;
const double mu_d_rate = +1.500000e+00;
const double mu_c_rate = +2.500000e+00;
const double mu_b_rate = +2.000000e+00;
const double mu_a_rate = +4.000000e+00;
const double mu_obs1_rate = +4.000000e+00;
const double mu_obs2_rate = +5.000000e+00;
const double mu_observe1_durtime = +7.000000e+00;
const double mu_observe2_durtime = +7.500000e+00;
const double mu_prepareobs1_durtime = +1.000000e+00;
const double mu_prepareobs2_durtime = +1.500000e+00;
const double mu_fullprepare_durtime = +3.200000e+00;
const double mu_charge_rate = +9.500000e-03;
/*** Variable declaration ***/
mu_1_real_type mu_observe2_clock("observe2_clock",0);

/*** Variable declaration ***/
mu_0_boolean mu_observe2_clock_started("observe2_clock_started",32);

/*** Variable declaration ***/
mu_1_real_type mu_observe1_clock("observe1_clock",34);

/*** Variable declaration ***/
mu_0_boolean mu_observe1_clock_started("observe1_clock_started",66);

/*** Variable declaration ***/
mu_1_real_type mu_prepareobs2_clock("prepareobs2_clock",68);

/*** Variable declaration ***/
mu_0_boolean mu_prepareobs2_clock_started("prepareobs2_clock_started",100);

/*** Variable declaration ***/
mu_1_real_type mu_prepareobs1_clock("prepareobs1_clock",102);

/*** Variable declaration ***/
mu_0_boolean mu_prepareobs1_clock_started("prepareobs1_clock_started",134);

/*** Variable declaration ***/
mu_1_real_type mu_fullprepare_clock("fullprepare_clock",136);

/*** Variable declaration ***/
mu_0_boolean mu_fullprepare_clock_started("fullprepare_clock_started",168);

/*** Variable declaration ***/
mu_1_real_type mu_daytime("daytime",170);

/*** Variable declaration ***/
mu_1_real_type mu_soc("soc",202);

/*** Variable declaration ***/
mu_1_real_type mu_supply("supply",234);

/*** Variable declaration ***/
mu_1_real_type mu_demand("demand",266);

/*** Variable declaration ***/
mu_1__type_0 mu_observe_complete_value("observe_complete_value",298);

/*** Variable declaration ***/
mu_0_boolean mu_gotobs2_value("gotobs2_value",300);

/*** Variable declaration ***/
mu_0_boolean mu_gotobs1_value("gotobs1_value",302);

/*** Variable declaration ***/
mu_0_boolean mu_ready_value("ready_value",304);

/*** Variable declaration ***/
mu_0_boolean mu_readyforobs2_value("readyforobs2_value",306);

/*** Variable declaration ***/
mu_0_boolean mu_readyforobs1_value("readyforobs1_value",308);

/*** Variable declaration ***/
mu_0_boolean mu_commsopen_value("commsopen_value",310);

/*** Variable declaration ***/
mu_0_boolean mu_day_value("day_value",312);

/*** Variable declaration ***/
mu_0_boolean mu_all_event_true("all_event_true",314);

/*** Variable declaration ***/
mu_0_boolean mu_busy("busy",316);


#include "planety_lib.h"

mu_0_boolean mu_observe_complete()
{
if ( (mu_observe_complete_value) == (2) )
{
return mu_true;
}
return mu_false;
	Error.Error("The end of function observe_complete reached without returning values.");
};
/*** end function declaration ***/

void mu_fail()
{
if ( (mu_soc) < (mu_safelevel) )
{
mu_all_event_true = mu_false;
}
};
/*** end procedure declaration ***/

void mu_set_gotobs2(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_gotobs2_value.undefine();
else
  mu_gotobs2_value = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_gotobs2()
{
return mu_gotobs2_value;
	Error.Error("The end of function gotobs2 reached without returning values.");
};
/*** end function declaration ***/

void mu_set_gotobs1(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_gotobs1_value.undefine();
else
  mu_gotobs1_value = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_gotobs1()
{
return mu_gotobs1_value;
	Error.Error("The end of function gotobs1 reached without returning values.");
};
/*** end function declaration ***/

void mu_set_ready(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_ready_value.undefine();
else
  mu_ready_value = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_ready()
{
return mu_ready_value;
	Error.Error("The end of function ready reached without returning values.");
};
/*** end function declaration ***/

void mu_set_readyforobs2(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_readyforobs2_value.undefine();
else
  mu_readyforobs2_value = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_readyforobs2()
{
return mu_readyforobs2_value;
	Error.Error("The end of function readyforobs2 reached without returning values.");
};
/*** end function declaration ***/

void mu_set_readyforobs1(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_readyforobs1_value.undefine();
else
  mu_readyforobs1_value = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_readyforobs1()
{
return mu_readyforobs1_value;
	Error.Error("The end of function readyforobs1 reached without returning values.");
};
/*** end function declaration ***/

void mu_set_commsopen(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_commsopen_value.undefine();
else
  mu_commsopen_value = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_commsopen()
{
return mu_commsopen_value;
	Error.Error("The end of function commsopen reached without returning values.");
};
/*** end function declaration ***/

void mu_set_day(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_day_value.undefine();
else
  mu_day_value = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_day()
{
return mu_day_value;
	Error.Error("The end of function day reached without returning values.");
};
/*** end function declaration ***/

void mu_process_observe2()
{
if ( mu_observe2_clock_started )
{
mu_observe2_clock = (mu_observe2_clock) + (mu_T);
}
};
/*** end procedure declaration ***/

void mu_event_observe2_failure()
{
bool mu__boolexpr1;
bool mu__boolexpr2;
bool mu__boolexpr3;
  if (!(!(mu_commsopen(  )))) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = ((mu_soc) > (mu_safelevel)) ; 
}
  if (!(!(mu__boolexpr3))) mu__boolexpr2 = FALSE ;
  else {
  mu__boolexpr2 = (mu_observe2_clock_started) ; 
}
  if (!(mu__boolexpr2)) mu__boolexpr1 = FALSE ;
  else {
  mu__boolexpr1 = ((mu_observe2_clock) != (mu_observe2_durtime)) ; 
}
if ( mu__boolexpr1 )
{
mu_observe2_clock = 7.600000e+00;
mu_all_event_true = mu_false;
}
};
/*** end procedure declaration ***/

void mu_process_observe1()
{
if ( mu_observe1_clock_started )
{
mu_observe1_clock = (mu_observe1_clock) + (mu_T);
}
};
/*** end procedure declaration ***/

void mu_event_observe1_failure()
{
bool mu__boolexpr4;
bool mu__boolexpr5;
bool mu__boolexpr6;
  if (!(!(mu_commsopen(  )))) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = ((mu_soc) > (mu_safelevel)) ; 
}
  if (!(!(mu__boolexpr6))) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = (mu_observe1_clock_started) ; 
}
  if (!(mu__boolexpr5)) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = ((mu_observe1_clock) != (mu_observe1_durtime)) ; 
}
if ( mu__boolexpr4 )
{
mu_observe1_clock = 7.100000e+00;
mu_all_event_true = mu_false;
}
};
/*** end procedure declaration ***/

void mu_process_prepareobs2()
{
if ( mu_prepareobs2_clock_started )
{
mu_prepareobs2_clock = (mu_prepareobs2_clock) + (mu_T);
}
};
/*** end procedure declaration ***/

void mu_event_prepareobs2_failure()
{
bool mu__boolexpr7;
bool mu__boolexpr8;
  if (!(!((mu_soc) > (mu_safelevel)))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = (mu_prepareobs2_clock_started) ; 
}
  if (!(mu__boolexpr8)) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_prepareobs2_clock) != (mu_prepareobs2_durtime)) ; 
}
if ( mu__boolexpr7 )
{
mu_prepareobs2_clock = 1.600000e+00;
mu_all_event_true = mu_false;
}
};
/*** end procedure declaration ***/

void mu_process_prepareobs1()
{
if ( mu_prepareobs1_clock_started )
{
mu_prepareobs1_clock = (mu_prepareobs1_clock) + (mu_T);
}
};
/*** end procedure declaration ***/

void mu_event_prepareobs1_failure()
{
bool mu__boolexpr9;
bool mu__boolexpr10;
  if (!(!((mu_soc) > (mu_safelevel)))) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = (mu_prepareobs1_clock_started) ; 
}
  if (!(mu__boolexpr10)) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_prepareobs1_clock) != (mu_prepareobs1_durtime)) ; 
}
if ( mu__boolexpr9 )
{
mu_prepareobs1_clock = 1.100000e+00;
mu_all_event_true = mu_false;
}
};
/*** end procedure declaration ***/

void mu_process_fullprepare()
{
if ( mu_fullprepare_clock_started )
{
mu_fullprepare_clock = (mu_fullprepare_clock) + (mu_T);
}
};
/*** end procedure declaration ***/

void mu_event_fullprepare_failure()
{
bool mu__boolexpr11;
bool mu__boolexpr12;
  if (!(!((mu_soc) > (mu_safelevel)))) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = (mu_fullprepare_clock_started) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_fullprepare_clock) != (mu_fullprepare_durtime)) ; 
}
if ( mu__boolexpr11 )
{
mu_fullprepare_clock = 3.300000e+00;
mu_all_event_true = mu_false;
}
};
/*** end procedure declaration ***/

void mu_daybreak()
{
bool mu__boolexpr13;
  if (!((mu_daytime) >= (0))) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = (!(mu_day(  ))) ; 
}
if ( mu__boolexpr13 )
{
mu_set_day ( mu_true );
}
};
/*** end procedure declaration ***/

void mu_nightfall()
{
bool mu__boolexpr14;
  if (!((mu_daytime) >= (mu_dusk))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = (mu_day(  )) ; 
}
if ( mu__boolexpr14 )
{
mu_daytime = -3.000000e+00;
mu_set_day ( mu_false );
}
};
/*** end procedure declaration ***/

void mu_night_operations()
{
if ( !(mu_day(  )) )
{
mu_daytime = (mu_daytime) + (mu_T);
mu_soc = night_op_ext( mu_soc, (double)mu_heater_rate, (double)mu_T );
}
};
/*** end procedure declaration ***/

void mu_generating()
{
if ( mu_day(  ) )
{
mu_supply = generating_ext( mu_supply, (double)mu_solar_const, mu_daytime, (double)mu_T );
mu_daytime = (mu_daytime) + (mu_T);
}
};
/*** end procedure declaration ***/

void mu_discharging()
{
if ( (mu_demand) > (mu_supply) )
{
mu_soc = discharging_ext( mu_soc, mu_demand, mu_supply, (double)mu_T );
}
};
/*** end procedure declaration ***/

void mu_charging()
{
bool mu__boolexpr15;
bool mu__boolexpr16;
  if (!((mu_demand) < (mu_supply))) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = (mu_day(  )) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_soc) < (100)) ; 
}
if ( mu__boolexpr15 )
{
mu_soc = charging_ext( mu_demand, mu_supply, mu_soc, (double)mu_charge_rate, (double)mu_T );
}
if ( (mu_soc) > (100) )
{
mu_soc = 100;
}
};
/*** end procedure declaration ***/

mu_0_boolean mu_inbound()
{
bool mu__boolexpr17;
bool mu__boolexpr18;
bool mu__boolexpr19;
  if (!((mu_soc) >= (0.000000e+00))) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_soc) <= (1.000000e+02)) ; 
}
  if (!(mu__boolexpr19)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_demand) >= (0.000000e+00)) ; 
}
  if (!(mu__boolexpr18)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_supply) >= (0.000000e+00)) ; 
}
return mu__boolexpr17;
	Error.Error("The end of function inbound reached without returning values.");
};
/*** end function declaration ***/

void mu_timed_initial_literals()
{
if ( (mu_daytime) >= (mu_commsopen_deadline) )
{
mu_set_commsopen ( mu_true );
}
};
/*** end procedure declaration ***/

void mu_dynamic_check_riold()
{
mu_fail (  );
mu_daybreak (  );
mu_nightfall (  );
mu_generating (  );
mu_charging (  );
mu_discharging (  );
mu_night_operations (  );
mu_timed_initial_literals (  );
mu_process_observe2 (  );
mu_event_observe2_failure (  );
mu_process_observe1 (  );
mu_event_observe1_failure (  );
mu_process_prepareobs2 (  );
mu_event_prepareobs2_failure (  );
mu_process_prepareobs1 (  );
mu_event_prepareobs1_failure (  );
mu_process_fullprepare (  );
mu_event_fullprepare_failure (  );
};
/*** end procedure declaration ***/

void mu_dynamic_check_old()
{
mu_fail (  );
mu_timed_initial_literals (  );
mu_process_observe2 (  );
mu_event_observe2_failure (  );
mu_process_observe1 (  );
mu_event_observe1_failure (  );
mu_process_prepareobs2 (  );
mu_event_prepareobs2_failure (  );
mu_process_prepareobs1 (  );
mu_event_prepareobs1_failure (  );
mu_process_fullprepare (  );
mu_event_fullprepare_failure (  );
mu_daybreak (  );
mu_nightfall (  );
mu_night_operations (  );
mu_generating (  );
mu_discharging (  );
mu_charging (  );
};
/*** end procedure declaration ***/

void mu_fire_events()
{
mu_fail (  );
mu_daybreak (  );
mu_nightfall (  );
mu_timed_initial_literals (  );
mu_event_observe2_failure (  );
mu_event_observe1_failure (  );
mu_event_prepareobs2_failure (  );
mu_event_prepareobs1_failure (  );
mu_event_fullprepare_failure (  );
};
/*** end procedure declaration ***/

void mu_update_processes()
{
mu_generating (  );
mu_charging (  );
mu_discharging (  );
mu_night_operations (  );
mu_process_observe2 (  );
mu_process_observe1 (  );
mu_process_prepareobs2 (  );
mu_process_prepareobs1 (  );
mu_process_fullprepare (  );
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_observe2_clock.clear();
  mu_observe2_clock_started.clear();
  mu_observe1_clock.clear();
  mu_observe1_clock_started.clear();
  mu_prepareobs2_clock.clear();
  mu_prepareobs2_clock_started.clear();
  mu_prepareobs1_clock.clear();
  mu_prepareobs1_clock_started.clear();
  mu_fullprepare_clock.clear();
  mu_fullprepare_clock_started.clear();
  mu_daytime.clear();
  mu_soc.clear();
  mu_supply.clear();
  mu_demand.clear();
  mu_observe_complete_value.clear();
  mu_gotobs2_value.clear();
  mu_gotobs1_value.clear();
  mu_ready_value.clear();
  mu_readyforobs2_value.clear();
  mu_readyforobs1_value.clear();
  mu_commsopen_value.clear();
  mu_day_value.clear();
  mu_all_event_true.clear();
  mu_busy.clear();
}
void world_class::undefine()
{
  mu_observe2_clock.undefine();
  mu_observe2_clock_started.undefine();
  mu_observe1_clock.undefine();
  mu_observe1_clock_started.undefine();
  mu_prepareobs2_clock.undefine();
  mu_prepareobs2_clock_started.undefine();
  mu_prepareobs1_clock.undefine();
  mu_prepareobs1_clock_started.undefine();
  mu_fullprepare_clock.undefine();
  mu_fullprepare_clock_started.undefine();
  mu_daytime.undefine();
  mu_soc.undefine();
  mu_supply.undefine();
  mu_demand.undefine();
  mu_observe_complete_value.undefine();
  mu_gotobs2_value.undefine();
  mu_gotobs1_value.undefine();
  mu_ready_value.undefine();
  mu_readyforobs2_value.undefine();
  mu_readyforobs1_value.undefine();
  mu_commsopen_value.undefine();
  mu_day_value.undefine();
  mu_all_event_true.undefine();
  mu_busy.undefine();
}
void world_class::reset()
{
  mu_observe2_clock.reset();
  mu_observe2_clock_started.reset();
  mu_observe1_clock.reset();
  mu_observe1_clock_started.reset();
  mu_prepareobs2_clock.reset();
  mu_prepareobs2_clock_started.reset();
  mu_prepareobs1_clock.reset();
  mu_prepareobs1_clock_started.reset();
  mu_fullprepare_clock.reset();
  mu_fullprepare_clock_started.reset();
  mu_daytime.reset();
  mu_soc.reset();
  mu_supply.reset();
  mu_demand.reset();
  mu_observe_complete_value.reset();
  mu_gotobs2_value.reset();
  mu_gotobs1_value.reset();
  mu_ready_value.reset();
  mu_readyforobs2_value.reset();
  mu_readyforobs1_value.reset();
  mu_commsopen_value.reset();
  mu_day_value.reset();
  mu_all_event_true.reset();
  mu_busy.reset();
}
void world_class::print(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_observe2_clock.print(target, separator);
  mu_observe2_clock_started.print(target, separator);
  mu_observe1_clock.print(target, separator);
  mu_observe1_clock_started.print(target, separator);
  mu_prepareobs2_clock.print(target, separator);
  mu_prepareobs2_clock_started.print(target, separator);
  mu_prepareobs1_clock.print(target, separator);
  mu_prepareobs1_clock_started.print(target, separator);
  mu_fullprepare_clock.print(target, separator);
  mu_fullprepare_clock_started.print(target, separator);
  mu_daytime.print(target, separator);
  mu_soc.print(target, separator);
  mu_supply.print(target, separator);
  mu_demand.print(target, separator);
  mu_observe_complete_value.print(target, separator);
  mu_gotobs2_value.print(target, separator);
  mu_gotobs1_value.print(target, separator);
  mu_ready_value.print(target, separator);
  mu_readyforobs2_value.print(target, separator);
  mu_readyforobs1_value.print(target, separator);
  mu_commsopen_value.print(target, separator);
  mu_day_value.print(target, separator);
  mu_all_event_true.print(target, separator);
  mu_busy.print(target, separator);
    num_calls--;
}
}
void world_class::pddlprint(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_daytime.print(target, separator);
  mu_soc.print(target, separator);
  mu_supply.print(target, separator);
  mu_demand.print(target, separator);
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_observe2_clock.print_statistic();
  mu_observe2_clock_started.print_statistic();
  mu_observe1_clock.print_statistic();
  mu_observe1_clock_started.print_statistic();
  mu_prepareobs2_clock.print_statistic();
  mu_prepareobs2_clock_started.print_statistic();
  mu_prepareobs1_clock.print_statistic();
  mu_prepareobs1_clock_started.print_statistic();
  mu_fullprepare_clock.print_statistic();
  mu_fullprepare_clock_started.print_statistic();
  mu_daytime.print_statistic();
  mu_soc.print_statistic();
  mu_supply.print_statistic();
  mu_demand.print_statistic();
  mu_observe_complete_value.print_statistic();
  mu_gotobs2_value.print_statistic();
  mu_gotobs1_value.print_statistic();
  mu_ready_value.print_statistic();
  mu_readyforobs2_value.print_statistic();
  mu_readyforobs1_value.print_statistic();
  mu_commsopen_value.print_statistic();
  mu_day_value.print_statistic();
  mu_all_event_true.print_statistic();
  mu_busy.print_statistic();
    num_calls--;
}
}
void world_class::print_diff(state *prevstate, FILE *target, const char *separator)
{
  if ( prevstate != NULL )
  {
    mu_observe2_clock.print_diff(prevstate,target,separator);
    mu_observe2_clock_started.print_diff(prevstate,target,separator);
    mu_observe1_clock.print_diff(prevstate,target,separator);
    mu_observe1_clock_started.print_diff(prevstate,target,separator);
    mu_prepareobs2_clock.print_diff(prevstate,target,separator);
    mu_prepareobs2_clock_started.print_diff(prevstate,target,separator);
    mu_prepareobs1_clock.print_diff(prevstate,target,separator);
    mu_prepareobs1_clock_started.print_diff(prevstate,target,separator);
    mu_fullprepare_clock.print_diff(prevstate,target,separator);
    mu_fullprepare_clock_started.print_diff(prevstate,target,separator);
    mu_daytime.print_diff(prevstate,target,separator);
    mu_soc.print_diff(prevstate,target,separator);
    mu_supply.print_diff(prevstate,target,separator);
    mu_demand.print_diff(prevstate,target,separator);
    mu_observe_complete_value.print_diff(prevstate,target,separator);
    mu_gotobs2_value.print_diff(prevstate,target,separator);
    mu_gotobs1_value.print_diff(prevstate,target,separator);
    mu_ready_value.print_diff(prevstate,target,separator);
    mu_readyforobs2_value.print_diff(prevstate,target,separator);
    mu_readyforobs1_value.print_diff(prevstate,target,separator);
    mu_commsopen_value.print_diff(prevstate,target,separator);
    mu_day_value.print_diff(prevstate,target,separator);
    mu_all_event_true.print_diff(prevstate,target,separator);
    mu_busy.print_diff(prevstate,target,separator);
  }
  else
print(target,separator);
}
void world_class::to_state(state *newstate)
{
  mu_observe2_clock.to_state( newstate );
  mu_observe2_clock_started.to_state( newstate );
  mu_observe1_clock.to_state( newstate );
  mu_observe1_clock_started.to_state( newstate );
  mu_prepareobs2_clock.to_state( newstate );
  mu_prepareobs2_clock_started.to_state( newstate );
  mu_prepareobs1_clock.to_state( newstate );
  mu_prepareobs1_clock_started.to_state( newstate );
  mu_fullprepare_clock.to_state( newstate );
  mu_fullprepare_clock_started.to_state( newstate );
  mu_daytime.to_state( newstate );
  mu_soc.to_state( newstate );
  mu_supply.to_state( newstate );
  mu_demand.to_state( newstate );
  mu_observe_complete_value.to_state( newstate );
  mu_gotobs2_value.to_state( newstate );
  mu_gotobs1_value.to_state( newstate );
  mu_ready_value.to_state( newstate );
  mu_readyforobs2_value.to_state( newstate );
  mu_readyforobs1_value.to_state( newstate );
  mu_commsopen_value.to_state( newstate );
  mu_day_value.to_state( newstate );
  mu_all_event_true.to_state( newstate );
  mu_busy.to_state( newstate );
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
    return tsprintf("fullprepare_start");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr20;
bool mu__boolexpr21;
bool mu__boolexpr22;
bool mu__boolexpr23;
bool mu__boolexpr24;
bool mu__boolexpr25;
  if (!(!(mu_fullprepare_clock_started))) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = (!(mu_prepareobs1_clock_started)) ; 
}
  if (!(mu__boolexpr25)) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = (!(mu_prepareobs2_clock_started)) ; 
}
  if (!(mu__boolexpr24)) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = (!(mu_readyforobs1(  ))) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = (!(mu_readyforobs2(  ))) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr21)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = (!(mu_busy)) ; 
}
    return mu__boolexpr20;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr26;
bool mu__boolexpr27;
bool mu__boolexpr28;
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
  if (!(!(mu_fullprepare_clock_started))) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = (!(mu_prepareobs1_clock_started)) ; 
}
  if (!(mu__boolexpr31)) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = (!(mu_prepareobs2_clock_started)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = (!(mu_readyforobs1(  ))) ; 
}
  if (!(mu__boolexpr29)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = (!(mu_readyforobs2(  ))) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = (!(mu_busy)) ; 
}
	      if (mu__boolexpr26) {
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
mu_fire_events (  );
mu_set_ready ( mu_false );
mu_demand = (mu_demand) + (mu_a_rate);
mu_fullprepare_clock = (mu_fullprepare_clock) + (mu_T);
mu_fullprepare_clock_started = mu_true;
mu_busy = mu_true;
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
    return tsprintf("fullprepare");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeStart;
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
    return tsprintf("fullprepare_end");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr32;
bool mu__boolexpr33;
bool mu__boolexpr34;
  if (!(mu_fullprepare_clock_started)) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_fullprepare_clock) == (mu_fullprepare_durtime)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = (mu_busy) ; 
}
    return mu__boolexpr32;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 1;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr35;
bool mu__boolexpr36;
bool mu__boolexpr37;
  if (!(mu_fullprepare_clock_started)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_fullprepare_clock) == (mu_fullprepare_durtime)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = (mu_busy) ; 
}
	      if (mu__boolexpr35) {
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
mu_fire_events (  );
mu_demand = (mu_demand) - (mu_a_rate);
mu_set_readyforobs1 ( mu_true );
mu_set_readyforobs2 ( mu_true );
mu_fullprepare_clock = (mu_fullprepare_clock) - (mu_T);
mu_fullprepare_clock_started = mu_false;
mu_busy = mu_false;
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
    return tsprintf("fullprepare");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeEnd;
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
    return tsprintf("prepareobs1_start");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr38;
bool mu__boolexpr39;
bool mu__boolexpr40;
bool mu__boolexpr41;
bool mu__boolexpr42;
  if (!(!(mu_prepareobs1_clock_started))) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = (!(mu_fullprepare_clock_started)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = (!(mu_readyforobs1(  ))) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = (!(mu_gotobs1(  ))) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr39)) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = (!(mu_busy)) ; 
}
    return mu__boolexpr38;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 2;
    while (what_rule < 3 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr43;
bool mu__boolexpr44;
bool mu__boolexpr45;
bool mu__boolexpr46;
bool mu__boolexpr47;
  if (!(!(mu_prepareobs1_clock_started))) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = (!(mu_fullprepare_clock_started)) ; 
}
  if (!(mu__boolexpr47)) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = (!(mu_readyforobs1(  ))) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = (!(mu_gotobs1(  ))) ; 
}
  if (!(mu__boolexpr45)) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = (!(mu_busy)) ; 
}
	      if (mu__boolexpr43) {
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
mu_fire_events (  );
mu_set_ready ( mu_false );
mu_demand = (mu_demand) + (mu_b_rate);
mu_prepareobs1_clock = (mu_prepareobs1_clock) + (mu_T);
mu_prepareobs1_clock_started = mu_true;
mu_busy = mu_true;
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
    return tsprintf("prepareobs1");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeStart;
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
    return tsprintf("prepareobs1_end");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr48;
bool mu__boolexpr49;
bool mu__boolexpr50;
  if (!(mu_prepareobs1_clock_started)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_prepareobs1_clock) == (mu_prepareobs1_durtime)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr49)) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = (mu_busy) ; 
}
    return mu__boolexpr48;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 3;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr51;
bool mu__boolexpr52;
bool mu__boolexpr53;
  if (!(mu_prepareobs1_clock_started)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_prepareobs1_clock) == (mu_prepareobs1_durtime)) ; 
}
  if (!(mu__boolexpr53)) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = (mu_busy) ; 
}
	      if (mu__boolexpr51) {
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
mu_fire_events (  );
mu_demand = (mu_demand) - (mu_b_rate);
mu_set_readyforobs1 ( mu_true );
mu_prepareobs1_clock = (mu_prepareobs1_clock) - (mu_T);
mu_prepareobs1_clock_started = mu_false;
mu_busy = mu_false;
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
    return tsprintf("prepareobs1");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeEnd;
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
    return tsprintf("prepareobs2_start");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr54;
bool mu__boolexpr55;
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
  if (!(!(mu_prepareobs2_clock_started))) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = (!(mu_fullprepare_clock_started)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = (!(mu_readyforobs2(  ))) ; 
}
  if (!(mu__boolexpr57)) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = (!(mu_gotobs2(  ))) ; 
}
  if (!(mu__boolexpr56)) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = (!(mu_busy)) ; 
}
    return mu__boolexpr54;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 4;
    while (what_rule < 5 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr59;
bool mu__boolexpr60;
bool mu__boolexpr61;
bool mu__boolexpr62;
bool mu__boolexpr63;
  if (!(!(mu_prepareobs2_clock_started))) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = (!(mu_fullprepare_clock_started)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = (!(mu_readyforobs2(  ))) ; 
}
  if (!(mu__boolexpr62)) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = (!(mu_gotobs2(  ))) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = (!(mu_busy)) ; 
}
	      if (mu__boolexpr59) {
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
mu_fire_events (  );
mu_set_ready ( mu_false );
mu_demand = (mu_demand) + (mu_c_rate);
mu_prepareobs2_clock = (mu_prepareobs2_clock) + (mu_T);
mu_prepareobs2_clock_started = mu_true;
mu_busy = mu_true;
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
    return tsprintf("prepareobs2");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeStart;
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
    return tsprintf("prepareobs2_end");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr64;
bool mu__boolexpr65;
bool mu__boolexpr66;
  if (!(mu_prepareobs2_clock_started)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_prepareobs2_clock) == (mu_prepareobs2_durtime)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr65)) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = (mu_busy) ; 
}
    return mu__boolexpr64;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 5;
    while (what_rule < 6 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr67;
bool mu__boolexpr68;
bool mu__boolexpr69;
  if (!(mu_prepareobs2_clock_started)) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_prepareobs2_clock) == (mu_prepareobs2_durtime)) ; 
}
  if (!(mu__boolexpr69)) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr68)) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = (mu_busy) ; 
}
	      if (mu__boolexpr67) {
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
mu_fire_events (  );
mu_demand = (mu_demand) - (mu_c_rate);
mu_set_readyforobs2 ( mu_true );
mu_prepareobs2_clock = (mu_prepareobs2_clock) - (mu_T);
mu_prepareobs2_clock_started = mu_false;
mu_busy = mu_false;
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
    return tsprintf("prepareobs2");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeEnd;
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
    return tsprintf("observe1_start");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr70;
bool mu__boolexpr71;
bool mu__boolexpr72;
bool mu__boolexpr73;
  if (!(mu_readyforobs1(  ))) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = (!(mu_observe1_clock_started)) ; 
}
  if (!(mu__boolexpr73)) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = (!(mu_gotobs1(  ))) ; 
}
  if (!(mu__boolexpr72)) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr71)) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = (!(mu_busy)) ; 
}
    return mu__boolexpr70;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 6;
    while (what_rule < 7 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr74;
bool mu__boolexpr75;
bool mu__boolexpr76;
bool mu__boolexpr77;
  if (!(mu_readyforobs1(  ))) mu__boolexpr77 = FALSE ;
  else {
  mu__boolexpr77 = (!(mu_observe1_clock_started)) ; 
}
  if (!(mu__boolexpr77)) mu__boolexpr76 = FALSE ;
  else {
  mu__boolexpr76 = (!(mu_gotobs1(  ))) ; 
}
  if (!(mu__boolexpr76)) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr75)) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = (!(mu_busy)) ; 
}
	      if (mu__boolexpr74) {
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
mu_fire_events (  );
mu_set_ready ( mu_false );
mu_demand = (mu_demand) + (mu_obs1_rate);
mu_observe1_clock = (mu_observe1_clock) + (mu_T);
mu_observe1_clock_started = mu_true;
mu_busy = mu_true;
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
    return tsprintf("observe1");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeStart;
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
    return tsprintf("observe1_end");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr78;
bool mu__boolexpr79;
bool mu__boolexpr80;
  if (!(mu_observe1_clock_started)) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_observe1_clock) == (mu_observe1_durtime)) ; 
}
  if (!(mu__boolexpr80)) mu__boolexpr79 = FALSE ;
  else {
  mu__boolexpr79 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr79)) mu__boolexpr78 = FALSE ;
  else {
  mu__boolexpr78 = (mu_busy) ; 
}
    return mu__boolexpr78;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 7;
    while (what_rule < 8 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr81;
bool mu__boolexpr82;
bool mu__boolexpr83;
  if (!(mu_observe1_clock_started)) mu__boolexpr83 = FALSE ;
  else {
  mu__boolexpr83 = ((mu_observe1_clock) == (mu_observe1_durtime)) ; 
}
  if (!(mu__boolexpr83)) mu__boolexpr82 = FALSE ;
  else {
  mu__boolexpr82 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = (mu_busy) ; 
}
	      if (mu__boolexpr81) {
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
mu_fire_events (  );
mu_demand = (mu_demand) - (mu_obs1_rate);
mu_set_readyforobs1 ( mu_false );
mu_set_gotobs1 ( mu_true );
mu_observe1_clock = (mu_observe1_clock) - (mu_T);
mu_observe1_clock_started = mu_false;
mu_observe_complete_value = (mu_observe_complete_value) + (1);
mu_busy = mu_false;
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
    return tsprintf("observe1");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeEnd;
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
    return tsprintf("observe2_start");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr84;
bool mu__boolexpr85;
bool mu__boolexpr86;
bool mu__boolexpr87;
  if (!(mu_readyforobs2(  ))) mu__boolexpr87 = FALSE ;
  else {
  mu__boolexpr87 = (!(mu_observe2_clock_started)) ; 
}
  if (!(mu__boolexpr87)) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = (!(mu_gotobs2(  ))) ; 
}
  if (!(mu__boolexpr86)) mu__boolexpr85 = FALSE ;
  else {
  mu__boolexpr85 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr85)) mu__boolexpr84 = FALSE ;
  else {
  mu__boolexpr84 = (!(mu_busy)) ; 
}
    return mu__boolexpr84;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 8;
    while (what_rule < 9 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr88;
bool mu__boolexpr89;
bool mu__boolexpr90;
bool mu__boolexpr91;
  if (!(mu_readyforobs2(  ))) mu__boolexpr91 = FALSE ;
  else {
  mu__boolexpr91 = (!(mu_observe2_clock_started)) ; 
}
  if (!(mu__boolexpr91)) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = (!(mu_gotobs2(  ))) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = FALSE ;
  else {
  mu__boolexpr89 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr89)) mu__boolexpr88 = FALSE ;
  else {
  mu__boolexpr88 = (!(mu_busy)) ; 
}
	      if (mu__boolexpr88) {
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
mu_fire_events (  );
mu_set_ready ( mu_false );
mu_demand = (mu_demand) + (mu_obs2_rate);
mu_observe2_clock = (mu_observe2_clock) + (mu_T);
mu_observe2_clock_started = mu_true;
mu_busy = mu_true;
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
    return tsprintf("observe2");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeStart;
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
    return tsprintf("observe2_end");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr92;
bool mu__boolexpr93;
bool mu__boolexpr94;
  if (!(mu_observe2_clock_started)) mu__boolexpr94 = FALSE ;
  else {
  mu__boolexpr94 = ((mu_observe2_clock) == (mu_observe2_durtime)) ; 
}
  if (!(mu__boolexpr94)) mu__boolexpr93 = FALSE ;
  else {
  mu__boolexpr93 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr93)) mu__boolexpr92 = FALSE ;
  else {
  mu__boolexpr92 = (mu_busy) ; 
}
    return mu__boolexpr92;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 9;
    while (what_rule < 10 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr95;
bool mu__boolexpr96;
bool mu__boolexpr97;
  if (!(mu_observe2_clock_started)) mu__boolexpr97 = FALSE ;
  else {
  mu__boolexpr97 = ((mu_observe2_clock) == (mu_observe2_durtime)) ; 
}
  if (!(mu__boolexpr97)) mu__boolexpr96 = FALSE ;
  else {
  mu__boolexpr96 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr96)) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = (mu_busy) ; 
}
	      if (mu__boolexpr95) {
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
mu_fire_events (  );
mu_demand = (mu_demand) - (mu_obs2_rate);
mu_set_readyforobs2 ( mu_false );
mu_set_gotobs2 ( mu_true );
mu_observe2_clock = (mu_observe2_clock) - (mu_T);
mu_observe2_clock_started = mu_false;
mu_observe_complete_value = (mu_observe_complete_value) + (1);
mu_busy = mu_false;
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
    return tsprintf("observe2");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeEnd;
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
    return tsprintf("time_passing");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr98;
bool mu__boolexpr99;
bool mu__boolexpr100;
bool mu__boolexpr101;
bool mu__boolexpr102;
bool mu__boolexpr103;
bool mu__boolexpr104;
bool mu__boolexpr105;
bool mu__boolexpr106;
  if (!(mu_true)) mu__boolexpr106 = FALSE ;
  else {
  mu__boolexpr106 = ((mu_daytime) >= (-10)) ; 
}
  if (!(mu__boolexpr106)) mu__boolexpr105 = FALSE ;
  else {
  mu__boolexpr105 = ((mu_daytime) <= (10)) ; 
}
  if (!(mu__boolexpr105)) mu__boolexpr104 = FALSE ;
  else {
  mu__boolexpr104 = ((mu_soc) >= (0)) ; 
}
  if (!(mu__boolexpr104)) mu__boolexpr103 = FALSE ;
  else {
  mu__boolexpr103 = ((mu_soc) <= (100)) ; 
}
  if (!(mu__boolexpr103)) mu__boolexpr102 = FALSE ;
  else {
  mu__boolexpr102 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr102)) mu__boolexpr101 = FALSE ;
  else {
  mu__boolexpr101 = ((mu_observe1_clock) <= (mu_observe1_durtime)) ; 
}
  if (!(mu__boolexpr101)) mu__boolexpr100 = FALSE ;
  else {
  mu__boolexpr100 = ((mu_observe2_clock) <= (mu_observe2_durtime)) ; 
}
  if (!(mu__boolexpr100)) mu__boolexpr99 = FALSE ;
  else {
  mu__boolexpr99 = ((mu_prepareobs1_clock) <= (mu_prepareobs1_durtime)) ; 
}
  if (!(mu__boolexpr99)) mu__boolexpr98 = FALSE ;
  else {
  mu__boolexpr98 = ((mu_prepareobs2_clock) <= (mu_prepareobs2_durtime)) ; 
}
    return mu__boolexpr98;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 10;
    while (what_rule < 11 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr107;
bool mu__boolexpr108;
bool mu__boolexpr109;
bool mu__boolexpr110;
bool mu__boolexpr111;
bool mu__boolexpr112;
bool mu__boolexpr113;
bool mu__boolexpr114;
bool mu__boolexpr115;
  if (!(mu_true)) mu__boolexpr115 = FALSE ;
  else {
  mu__boolexpr115 = ((mu_daytime) >= (-10)) ; 
}
  if (!(mu__boolexpr115)) mu__boolexpr114 = FALSE ;
  else {
  mu__boolexpr114 = ((mu_daytime) <= (10)) ; 
}
  if (!(mu__boolexpr114)) mu__boolexpr113 = FALSE ;
  else {
  mu__boolexpr113 = ((mu_soc) >= (0)) ; 
}
  if (!(mu__boolexpr113)) mu__boolexpr112 = FALSE ;
  else {
  mu__boolexpr112 = ((mu_soc) <= (100)) ; 
}
  if (!(mu__boolexpr112)) mu__boolexpr111 = FALSE ;
  else {
  mu__boolexpr111 = (mu_inbound(  )) ; 
}
  if (!(mu__boolexpr111)) mu__boolexpr110 = FALSE ;
  else {
  mu__boolexpr110 = ((mu_observe1_clock) <= (mu_observe1_durtime)) ; 
}
  if (!(mu__boolexpr110)) mu__boolexpr109 = FALSE ;
  else {
  mu__boolexpr109 = ((mu_observe2_clock) <= (mu_observe2_durtime)) ; 
}
  if (!(mu__boolexpr109)) mu__boolexpr108 = FALSE ;
  else {
  mu__boolexpr108 = ((mu_prepareobs1_clock) <= (mu_prepareobs1_durtime)) ; 
}
  if (!(mu__boolexpr108)) mu__boolexpr107 = FALSE ;
  else {
  mu__boolexpr107 = ((mu_prepareobs2_clock) <= (mu_prepareobs2_durtime)) ; 
}
	      if (mu__boolexpr107) {
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
mu_fire_events (  );
mu_update_processes (  );
  };

  int Duration(RULE_INDEX_TYPE r)
  {
    return 1;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    return Duration(r);
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    return tsprintf("time_passing");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Clock;
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
Error.Notrace("Internal: NextStateGenerator -- querying PDDL class for nonexisting rule.");
}
};
const RULE_INDEX_TYPE numrules = 11;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 11


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("99");
  }
  void Code(unsigned short r)
  {
mu_all_event_true = mu_true;
mu_set_ready ( mu_true );
mu_observe2_clock_started = mu_false;
mu_observe2_clock = 0.000000e+00;
mu_observe1_clock_started = mu_false;
mu_observe1_clock = 0.000000e+00;
mu_prepareobs2_clock_started = mu_false;
mu_prepareobs2_clock = 0.000000e+00;
mu_prepareobs1_clock_started = mu_false;
mu_prepareobs1_clock = 0.000000e+00;
mu_fullprepare_clock_started = mu_false;
mu_fullprepare_clock = 0.000000e+00;
mu_observe_complete_value = 0;
mu_observe_complete_value = 0;
mu_gotobs2_value = mu_false;
mu_gotobs1_value = mu_false;
mu_readyforobs2_value = mu_false;
mu_readyforobs1_value = mu_false;
mu_commsopen_value = mu_false;
mu_daytime = 4.500000e+00;
mu_busy = mu_false;
mu_set_day ( mu_true );
mu_soc = 93;
mu_supply = 0;
mu_demand = 0;
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Goal records
 ********************/
int mu__goal_116() // Goal " enjoy "
{
bool mu__boolexpr117;
  if (!(mu_observe_complete(  ))) mu__boolexpr117 = FALSE ;
  else {
  mu__boolexpr117 = (mu_all_event_true) ; 
}
return mu__boolexpr117;
};

bool mu__condition_118() // Condition for Rule " enjoy "
{
  return mu__goal_116( );
}

/**** end rule declaration ****/

const rulerec goals[] = {
{" enjoy ", &mu__condition_118, NULL, },
};
const unsigned short numgoals = 1;

/********************
  Metric related stuff
 ********************/
const short metric = -1;

/********************
  Invariant records
 ********************/
int mu__invariant_119() // Invariant "everything going right"
{
return mu_all_event_true;
};

bool mu__condition_120() // Condition for Rule "everything going right"
{
  return mu__invariant_119( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"everything going right", &mu__condition_120, NULL, },
};
const unsigned short numinvariants = 1;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
all_event_true:NoScalarset
commsopen_value:NoScalarset
readyforobs2_value:NoScalarset
gotobs1_value:NoScalarset
observe_complete_value:NoScalarset
demand:NoScalarset
soc:NoScalarset
fullprepare_clock_started:NoScalarset
prepareobs1_clock_started:NoScalarset
prepareobs2_clock_started:NoScalarset
observe1_clock_started:NoScalarset
observe2_clock_started:NoScalarset
observe2_clock:NoScalarset
observe1_clock:NoScalarset
prepareobs2_clock:NoScalarset
prepareobs1_clock:NoScalarset
fullprepare_clock:NoScalarset
daytime:NoScalarset
supply:NoScalarset
gotobs2_value:NoScalarset
ready_value:NoScalarset
readyforobs1_value:NoScalarset
day_value:NoScalarset
busy:NoScalarset
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
        mu_all_event_true.MultisetSort();
        mu_commsopen_value.MultisetSort();
        mu_readyforobs2_value.MultisetSort();
        mu_gotobs1_value.MultisetSort();
        mu_observe_complete_value.MultisetSort();
        mu_demand.MultisetSort();
        mu_soc.MultisetSort();
        mu_fullprepare_clock_started.MultisetSort();
        mu_prepareobs1_clock_started.MultisetSort();
        mu_prepareobs2_clock_started.MultisetSort();
        mu_observe1_clock_started.MultisetSort();
        mu_observe2_clock_started.MultisetSort();
        mu_observe2_clock.MultisetSort();
        mu_observe1_clock.MultisetSort();
        mu_prepareobs2_clock.MultisetSort();
        mu_prepareobs1_clock.MultisetSort();
        mu_fullprepare_clock.MultisetSort();
        mu_daytime.MultisetSort();
        mu_supply.MultisetSort();
        mu_gotobs2_value.MultisetSort();
        mu_ready_value.MultisetSort();
        mu_readyforobs1_value.MultisetSort();
        mu_day_value.MultisetSort();
        mu_busy.MultisetSort();
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
void mu_1_int_type::Permute(PermSet& Perm, int i) {};
void mu_1_int_type::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_int_type::Canonicalize(PermSet& Perm) {};
void mu_1_int_type::SimpleLimit(PermSet& Perm) {};
void mu_1_int_type::ArrayLimit(PermSet& Perm) {};
void mu_1_int_type::Limit(PermSet& Perm) {};
void mu_1_int_type::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_real_type::Permute(PermSet& Perm, int i) {};
void mu_1_real_type::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_real_type::Canonicalize(PermSet& Perm) {};
void mu_1_real_type::SimpleLimit(PermSet& Perm) {};
void mu_1_real_type::ArrayLimit(PermSet& Perm) {};
void mu_1_real_type::Limit(PermSet& Perm) {};
void mu_1_real_type::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for real type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

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
              
              mu_all_event_true.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_all_event_true.MultisetSort();
              mu_commsopen_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_commsopen_value.MultisetSort();
              mu_readyforobs2_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_readyforobs2_value.MultisetSort();
              mu_gotobs1_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_gotobs1_value.MultisetSort();
              mu_observe_complete_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_observe_complete_value.MultisetSort();
              mu_demand.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_demand.MultisetSort();
              mu_soc.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_soc.MultisetSort();
              mu_fullprepare_clock_started.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_fullprepare_clock_started.MultisetSort();
              mu_prepareobs1_clock_started.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_prepareobs1_clock_started.MultisetSort();
              mu_prepareobs2_clock_started.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_prepareobs2_clock_started.MultisetSort();
              mu_observe1_clock_started.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_observe1_clock_started.MultisetSort();
              mu_observe2_clock_started.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_observe2_clock_started.MultisetSort();
              mu_observe2_clock.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_observe2_clock.MultisetSort();
              mu_observe1_clock.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_observe1_clock.MultisetSort();
              mu_prepareobs2_clock.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_prepareobs2_clock.MultisetSort();
              mu_prepareobs1_clock.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_prepareobs1_clock.MultisetSort();
              mu_fullprepare_clock.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_fullprepare_clock.MultisetSort();
              mu_daytime.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_daytime.MultisetSort();
              mu_supply.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_supply.MultisetSort();
              mu_gotobs2_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_gotobs2_value.MultisetSort();
              mu_ready_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ready_value.MultisetSort();
              mu_readyforobs1_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_readyforobs1_value.MultisetSort();
              mu_day_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_day_value.MultisetSort();
              mu_busy.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_busy.MultisetSort();
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

          mu_all_event_true.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_all_event_true.MultisetSort();
          mu_commsopen_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_commsopen_value.MultisetSort();
          mu_readyforobs2_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_readyforobs2_value.MultisetSort();
          mu_gotobs1_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_gotobs1_value.MultisetSort();
          mu_observe_complete_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_observe_complete_value.MultisetSort();
          mu_demand.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_demand.MultisetSort();
          mu_soc.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_soc.MultisetSort();
          mu_fullprepare_clock_started.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_fullprepare_clock_started.MultisetSort();
          mu_prepareobs1_clock_started.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_prepareobs1_clock_started.MultisetSort();
          mu_prepareobs2_clock_started.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_prepareobs2_clock_started.MultisetSort();
          mu_observe1_clock_started.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_observe1_clock_started.MultisetSort();
          mu_observe2_clock_started.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_observe2_clock_started.MultisetSort();
          mu_observe2_clock.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_observe2_clock.MultisetSort();
          mu_observe1_clock.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_observe1_clock.MultisetSort();
          mu_prepareobs2_clock.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_prepareobs2_clock.MultisetSort();
          mu_prepareobs1_clock.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_prepareobs1_clock.MultisetSort();
          mu_fullprepare_clock.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_fullprepare_clock.MultisetSort();
          mu_daytime.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_daytime.MultisetSort();
          mu_supply.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_supply.MultisetSort();
          mu_gotobs2_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_gotobs2_value.MultisetSort();
          mu_ready_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ready_value.MultisetSort();
          mu_readyforobs1_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_readyforobs1_value.MultisetSort();
          mu_day_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_day_value.MultisetSort();
          mu_busy.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_busy.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_all_event_true.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_all_event_true.MultisetSort();
              mu_commsopen_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_commsopen_value.MultisetSort();
              mu_readyforobs2_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_readyforobs2_value.MultisetSort();
              mu_gotobs1_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_gotobs1_value.MultisetSort();
              mu_observe_complete_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_observe_complete_value.MultisetSort();
              mu_demand.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_demand.MultisetSort();
              mu_soc.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_soc.MultisetSort();
              mu_fullprepare_clock_started.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_fullprepare_clock_started.MultisetSort();
              mu_prepareobs1_clock_started.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_prepareobs1_clock_started.MultisetSort();
              mu_prepareobs2_clock_started.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_prepareobs2_clock_started.MultisetSort();
              mu_observe1_clock_started.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_observe1_clock_started.MultisetSort();
              mu_observe2_clock_started.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_observe2_clock_started.MultisetSort();
              mu_observe2_clock.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_observe2_clock.MultisetSort();
              mu_observe1_clock.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_observe1_clock.MultisetSort();
              mu_prepareobs2_clock.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_prepareobs2_clock.MultisetSort();
              mu_prepareobs1_clock.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_prepareobs1_clock.MultisetSort();
              mu_fullprepare_clock.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_fullprepare_clock.MultisetSort();
              mu_daytime.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_daytime.MultisetSort();
              mu_supply.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_supply.MultisetSort();
              mu_gotobs2_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_gotobs2_value.MultisetSort();
              mu_ready_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ready_value.MultisetSort();
              mu_readyforobs1_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_readyforobs1_value.MultisetSort();
              mu_day_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_day_value.MultisetSort();
              mu_busy.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_busy.MultisetSort();
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
      mu_all_event_true.MultisetSort();
      mu_commsopen_value.MultisetSort();
      mu_readyforobs2_value.MultisetSort();
      mu_gotobs1_value.MultisetSort();
      mu_observe_complete_value.MultisetSort();
      mu_demand.MultisetSort();
      mu_soc.MultisetSort();
      mu_fullprepare_clock_started.MultisetSort();
      mu_prepareobs1_clock_started.MultisetSort();
      mu_prepareobs2_clock_started.MultisetSort();
      mu_observe1_clock_started.MultisetSort();
      mu_observe2_clock_started.MultisetSort();
      mu_observe2_clock.MultisetSort();
      mu_observe1_clock.MultisetSort();
      mu_prepareobs2_clock.MultisetSort();
      mu_prepareobs1_clock.MultisetSort();
      mu_fullprepare_clock.MultisetSort();
      mu_daytime.MultisetSort();
      mu_supply.MultisetSort();
      mu_gotobs2_value.MultisetSort();
      mu_ready_value.MultisetSort();
      mu_readyforobs1_value.MultisetSort();
      mu_day_value.MultisetSort();
      mu_busy.MultisetSort();
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
        mu_all_event_true.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_all_event_true.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_commsopen_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_commsopen_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_readyforobs2_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_readyforobs2_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_gotobs1_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_gotobs1_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_observe_complete_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_observe_complete_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_demand.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_demand.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_soc.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_soc.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_fullprepare_clock_started.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_fullprepare_clock_started.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_prepareobs1_clock_started.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_prepareobs1_clock_started.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_prepareobs2_clock_started.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_prepareobs2_clock_started.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_observe1_clock_started.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_observe1_clock_started.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_observe2_clock_started.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_observe2_clock_started.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_observe2_clock.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_observe2_clock.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_observe1_clock.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_observe1_clock.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_prepareobs2_clock.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_prepareobs2_clock.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_prepareobs1_clock.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_prepareobs1_clock.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_fullprepare_clock.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_fullprepare_clock.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_daytime.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_daytime.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_supply.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_supply.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_gotobs2_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_gotobs2_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ready_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ready_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_readyforobs1_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_readyforobs1_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_day_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_day_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_busy.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_busy.MultisetSort();
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
