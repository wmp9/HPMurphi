/******************************
  Program "icas.m" compiled by "Universal Planner Murphi Release 2.0.R8"

  Murphi Last Compiled date: "Nov 26 2013"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Universal Planner Murphi Release 2.0.R8"
#define MURPHI_DATE "Nov 26 2013"
#define PROTOCOL_NAME "icas"
#define BITS_IN_WORLD 125
#define HASHC

/********************
  Include
 ********************/
#include "upm_prolog.hpp"

/********************
  Decl declaration
 ********************/

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

class mu_1_real_fuel: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_real_fuel& val) { return mu__long::operator=((int) val); };
  mu_1_real_fuel (const char *name, int os): mu__long(0, 18000, 15, name, os) {};
  mu_1_real_fuel (void): mu__long(0, 18000, 15) {};
  mu_1_real_fuel (int val): mu__long(0, 18000, 15, "Parameter or function result.", 0)
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
mu_1_real_fuel mu_1_real_fuel_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (const char *name, int os): mu__byte(0, 10, 4, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 10, 4) {};
  mu_1__type_0 (int val): mu__byte(0, 10, 4, "Parameter or function result.", 0)
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

class mu_1__type_1: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_1& val) { return mu__byte::operator=((int) val); };
  mu_1__type_1 (const char *name, int os): mu__byte(0, 10, 4, name, os) {};
  mu_1__type_1 (void): mu__byte(0, 10, 4) {};
  mu_1__type_1 (int val): mu__byte(0, 10, 4, "Parameter or function result.", 0)
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
mu_1__type_1 mu_1__type_1_undefined_var;

const double mu_T = +1.000000e+00;
const double mu_rho = +1.000000e-01;
const double mu_m = +7.173000e+01;
const double mu_g = +3.800000e+02;
const int mu_h = 0;
const double mu_A = +2.500000e+00;
const int mu_Crr = 50;
const int mu_Cd = 25;
const double mu_mu = +8.000000e-01;
const double mu_Voltage = +1.000000e+01;
const int mu_restart_energy_cost = 40;
const int mu_cooling_total_time = 5;
const int mu_g_c = 25;
const int mu_g_s = 10;
const int mu_distance_to_reach = 200;
const int mu_min_distance_to_cool = 120;
const int mu_v_max = 10;
/*** Variable declaration ***/
mu_0_boolean mu_engineblown_value("engineblown_value",0);

/*** Variable declaration ***/
mu_0_boolean mu_running_value("running_value",2);

/*** Variable declaration ***/
mu_0_boolean mu_cooling_value("cooling_value",4);

/*** Variable declaration ***/
mu_0_boolean mu_cooling_prepare("cooling_prepare",6);

/*** Variable declaration ***/
mu_0_boolean mu_restarting("restarting",8);

/*** Variable declaration ***/
mu_1__type_0 mu_cooling_time("cooling_time",10);

/*** Variable declaration ***/
mu_1_real_type mu_a("a",14);

/*** Variable declaration ***/
mu_1_real_type mu_d("d",46);

/*** Variable declaration ***/
mu_1_real_fuel mu_f("f",78);

/*** Variable declaration ***/
mu_1_real_type mu_v("v",93);


#include "icas_lib.h"

mu_0_boolean mu_inRange()
{
bool mu__boolexpr2;
bool mu__boolexpr3;
bool mu__boolexpr4;
  if (!((mu_a) >= (-6))) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = ((mu_a) <= (5)) ; 
}
  if (!(mu__boolexpr4)) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = ((mu_v) >= (0.000000e+00)) ; 
}
  if (!(mu__boolexpr3)) mu__boolexpr2 = FALSE ;
  else {
  mu__boolexpr2 = ((mu_d) >= (0.000000e+00)) ; 
}
return mu__boolexpr2;
	Error.Error("The end of function inRange reached without returning values.");
};
/*** end function declaration ***/

void mu_dynamic_check()
{
/*** Variable declaration ***/
mu_1_real_type mu_a_old("a_old",0);

/*** Variable declaration ***/
mu_1_real_type mu_v_old("v_old",32);

/*** Variable declaration ***/
mu_1_real_type mu_d_old("d_old",64);

/*** Variable declaration ***/
mu_1_real_fuel mu_f_old("f_old",96);

/*** Variable declaration ***/
mu_0_boolean mu_cooling_value_old("cooling_value_old",111);

/*** Variable declaration ***/
mu_0_boolean mu_cooling_prepare_old("cooling_prepare_old",113);

/*** Variable declaration ***/
mu_0_boolean mu_restarting_old("restarting_old",115);

/*** Variable declaration ***/
mu_1__type_1 mu_cooling_time_old("cooling_time_old",117);

if (mu_a.isundefined())
  mu_a_old.undefine();
else
  mu_a_old = mu_a;
if (mu_v.isundefined())
  mu_v_old.undefine();
else
  mu_v_old = mu_v;
if (mu_d.isundefined())
  mu_d_old.undefine();
else
  mu_d_old = mu_d;
if (mu_f.isundefined())
  mu_f_old.undefine();
else
  mu_f_old = mu_f;
if (mu_cooling_value.isundefined())
  mu_cooling_value_old.undefine();
else
  mu_cooling_value_old = mu_cooling_value;
if (mu_cooling_prepare.isundefined())
  mu_cooling_prepare_old.undefine();
else
  mu_cooling_prepare_old = mu_cooling_prepare;
if (mu_restarting_old.isundefined())
  mu_restarting_old.undefine();
else
  mu_restarting_old = mu_restarting_old;
if (mu_cooling_time.isundefined())
  mu_cooling_time_old.undefine();
else
  mu_cooling_time_old = mu_cooling_time;
bool mu__boolexpr5;
bool mu__boolexpr6;
  if (!(mu_running_value)) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = ((mu_d_old) >= (mu_min_distance_to_cool)) ; 
}
  if (!(mu__boolexpr6)) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = ((mu_cooling_time_old) == (0)) ; 
}
if ( mu__boolexpr5 )
{
mu_cooling_prepare = mu_true;
}
bool mu__boolexpr7;
  if (!(mu_cooling_value_old)) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_cooling_time_old) <= (mu_cooling_total_time)) ; 
}
if ( mu__boolexpr7 )
{
mu_f = update_cooling( mu_f_old, (double)mu_g, mu_v_old, (double)mu_m );
}
if ( mu_running_value )
{
mu_d = update_d( mu_d_old, mu_v_old, mu_a );
mu_v = update1_v( mu_v_old, mu_a );
if ( !(mu_cooling_value_old) )
{
mu_f = update_f( (double)mu_rho, mu_v_old, (double)mu_m, (double)mu_g, mu_a, mu_h, mu_f_old );
}
}
bool mu__boolexpr8;
  if (!(mu_cooling_value_old)) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_cooling_time_old) == (mu_cooling_total_time)) ; 
}
if ( mu__boolexpr8 )
{
mu_running_value = mu_true;
mu_cooling_value = mu_false;
mu_restarting = mu_true;
}
bool mu__boolexpr9;
  if (!(mu_running_value)) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_v_old) > (mu_v_max)) ; 
}
if ( mu__boolexpr9 )
{
mu_engineblown_value = mu_true;
mu_running_value = mu_false;
mu_a = 0.000000e+00;
}
bool mu__boolexpr10;
bool mu__boolexpr11;
  if (!((mu_v) >= (0.000000e+00))) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_v) <= (1.000000e+00)) ; 
}
  if (!(mu__boolexpr11)) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = (mu_cooling_prepare) ; 
}
if ( mu__boolexpr10 )
{
mu_a = 0.000000e+00;
mu_v = 0.000000e+00;
mu_cooling_prepare = mu_false;
mu_cooling_value = mu_true;
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_engineblown_value.clear();
  mu_running_value.clear();
  mu_cooling_value.clear();
  mu_cooling_prepare.clear();
  mu_restarting.clear();
  mu_cooling_time.clear();
  mu_a.clear();
  mu_d.clear();
  mu_f.clear();
  mu_v.clear();
}
void world_class::undefine()
{
  mu_engineblown_value.undefine();
  mu_running_value.undefine();
  mu_cooling_value.undefine();
  mu_cooling_prepare.undefine();
  mu_restarting.undefine();
  mu_cooling_time.undefine();
  mu_a.undefine();
  mu_d.undefine();
  mu_f.undefine();
  mu_v.undefine();
}
void world_class::reset()
{
  mu_engineblown_value.reset();
  mu_running_value.reset();
  mu_cooling_value.reset();
  mu_cooling_prepare.reset();
  mu_restarting.reset();
  mu_cooling_time.reset();
  mu_a.reset();
  mu_d.reset();
  mu_f.reset();
  mu_v.reset();
}
void world_class::print(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_engineblown_value.print(target, separator);
  mu_running_value.print(target, separator);
  mu_cooling_value.print(target, separator);
  mu_cooling_prepare.print(target, separator);
  mu_restarting.print(target, separator);
  mu_cooling_time.print(target, separator);
  mu_a.print(target, separator);
  mu_d.print(target, separator);
  mu_f.print(target, separator);
  mu_v.print(target, separator);
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
  mu_engineblown_value.print_statistic();
  mu_running_value.print_statistic();
  mu_cooling_value.print_statistic();
  mu_cooling_prepare.print_statistic();
  mu_restarting.print_statistic();
  mu_cooling_time.print_statistic();
  mu_a.print_statistic();
  mu_d.print_statistic();
  mu_f.print_statistic();
  mu_v.print_statistic();
    num_calls--;
}
}
void world_class::print_diff(state *prevstate, FILE *target, const char *separator)
{
  if ( prevstate != NULL )
  {
    mu_engineblown_value.print_diff(prevstate,target,separator);
    mu_running_value.print_diff(prevstate,target,separator);
    mu_cooling_value.print_diff(prevstate,target,separator);
    mu_cooling_prepare.print_diff(prevstate,target,separator);
    mu_restarting.print_diff(prevstate,target,separator);
    mu_cooling_time.print_diff(prevstate,target,separator);
    mu_a.print_diff(prevstate,target,separator);
    mu_d.print_diff(prevstate,target,separator);
    mu_f.print_diff(prevstate,target,separator);
    mu_v.print_diff(prevstate,target,separator);
  }
  else
print(target,separator);
}
void world_class::to_state(state *newstate)
{
  mu_engineblown_value.to_state( newstate );
  mu_running_value.to_state( newstate );
  mu_cooling_value.to_state( newstate );
  mu_cooling_prepare.to_state( newstate );
  mu_restarting.to_state( newstate );
  mu_cooling_time.to_state( newstate );
  mu_a.to_state( newstate );
  mu_d.to_state( newstate );
  mu_f.to_state( newstate );
  mu_v.to_state( newstate );
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
    return tsprintf(" restart after cooling ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr12;
bool mu__boolexpr13;
bool mu__boolexpr14;
  if (!(mu_running_value)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_cooling_time) == (mu_cooling_total_time)) ; 
}
  if (!(mu__boolexpr13)) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = (mu_restarting) ; 
}
    return mu__boolexpr12;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr15;
bool mu__boolexpr16;
bool mu__boolexpr17;
  if (!(mu_running_value)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr17)) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_cooling_time) == (mu_cooling_total_time)) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = (mu_restarting) ; 
}
	      if (mu__boolexpr15) {
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
mu_f = update_cooling( mu_f, (double)mu_g, mu_v, (double)mu_m );
mu_a = 0;
mu_v = 0.000000e+00;
mu_restarting = mu_false;
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
    return tsprintf(" restart after cooling ");
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
    return tsprintf(" cooling ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr18;
bool mu__boolexpr19;
bool mu__boolexpr20;
  if (!(mu_running_value)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = (mu_cooling_value) ; 
}
  if (!(mu__boolexpr19)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = (!(mu_cooling_prepare)) ; 
}
    return mu__boolexpr18;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 1;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr21;
bool mu__boolexpr22;
bool mu__boolexpr23;
  if (!(mu_running_value)) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = (mu_cooling_value) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = (!(mu_cooling_prepare)) ; 
}
	      if (mu__boolexpr21) {
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
bool mu__boolexpr24;
  if (!((mu_v) == (0.000000e+00))) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = ((mu_a) == (0.000000e+00)) ; 
}
if ( mu__boolexpr24 )
{
mu_cooling_time = (mu_cooling_time) + (1);
}
mu_dynamic_check (  );
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
    return tsprintf(" cooling ");
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
    return tsprintf(" costant ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr25;
bool mu__boolexpr26;
bool mu__boolexpr27;
bool mu__boolexpr28;
  if (!(mu_running_value)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = (!(mu_cooling_value)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = (!(mu_cooling_prepare)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = (!(mu_restarting)) ; 
}
    return mu__boolexpr25;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 2;
    while (what_rule < 3 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr29;
bool mu__boolexpr30;
bool mu__boolexpr31;
bool mu__boolexpr32;
  if (!(mu_running_value)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = (!(mu_cooling_value)) ; 
}
  if (!(mu__boolexpr31)) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = (!(mu_cooling_prepare)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = (!(mu_restarting)) ; 
}
	      if (mu__boolexpr29) {
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
    return tsprintf(" costant ");
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
    return tsprintf(" decelerate ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr33;
bool mu__boolexpr34;
bool mu__boolexpr35;
  if (!(mu_running_value)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr35)) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = (!(mu_cooling_value)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = (!(mu_restarting)) ; 
}
    return mu__boolexpr33;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 3;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr36;
bool mu__boolexpr37;
bool mu__boolexpr38;
  if (!(mu_running_value)) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = (!(mu_cooling_value)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = (!(mu_restarting)) ; 
}
	      if (mu__boolexpr36) {
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
mu_running_value = mu_true;
mu_a = (mu_a) - (1.500000e+00);
mu_dynamic_check (  );
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
    return tsprintf(" decelerate ");
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
    return tsprintf(" accelerate ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr39;
bool mu__boolexpr40;
bool mu__boolexpr41;
bool mu__boolexpr42;
  if (!(mu_running_value)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = (!(mu_cooling_value)) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = (!(mu_cooling_prepare)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = (!(mu_restarting)) ; 
}
    return mu__boolexpr39;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 4;
    while (what_rule < 5 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr43;
bool mu__boolexpr44;
bool mu__boolexpr45;
bool mu__boolexpr46;
  if (!(mu_running_value)) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = (mu_inRange(  )) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = (!(mu_cooling_value)) ; 
}
  if (!(mu__boolexpr45)) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = (!(mu_cooling_prepare)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = (!(mu_restarting)) ; 
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
    r = what_rule - 4;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
mu_running_value = mu_true;
mu_a = (mu_a) + (1.500000e+00);
mu_dynamic_check (  );
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
    return tsprintf(" accelerate ");
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
}
bool Condition(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
  if (r>=2 && r<=2) return R2.Condition(r-2);
  if (r>=3 && r<=3) return R3.Condition(r-3);
  if (r>=4 && r<=4) return R4.Condition(r-4);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code(r-2); return; } 
  if (r>=3 && r<=3) { R3.Code(r-3); return; } 
  if (r>=4 && r<=4) { R4.Code(r-4); return; } 
}
int Priority(RULE_INDEX_TYPE r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
  if (r>=2 && r<=2) { return R2.Priority(); } 
  if (r>=3 && r<=3) { return R3.Priority(); } 
  if (r>=4 && r<=4) { return R4.Priority(); } 
}
char * Name(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  if (r>=2 && r<=2) return R2.Name(r-2);
  if (r>=3 && r<=3) return R3.Name(r-3);
  if (r>=4 && r<=4) return R4.Name(r-4);
  return NULL;
}
int Duration(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Duration(r-0);
  if (r>=1 && r<=1) return R1.Duration(r-1);
  if (r>=2 && r<=2) return R2.Duration(r-2);
  if (r>=3 && r<=3) return R3.Duration(r-3);
  if (r>=4 && r<=4) return R4.Duration(r-4);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
int Weight(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Weight(r-0);
  if (r>=1 && r<=1) return R1.Weight(r-1);
  if (r>=2 && r<=2) return R2.Weight(r-2);
  if (r>=3 && r<=3) return R3.Weight(r-3);
  if (r>=4 && r<=4) return R4.Weight(r-4);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
char * PDDLName(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLName(r-0);
  if (r>=1 && r<=1) return R1.PDDLName(r-1);
  if (r>=2 && r<=2) return R2.PDDLName(r-2);
  if (r>=3 && r<=3) return R3.PDDLName(r-3);
  if (r>=4 && r<=4) return R4.PDDLName(r-4);
  return NULL;
}
RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLClass(r-0);
  if (r>=1 && r<=1) return R1.PDDLClass(r-1);
  if (r>=2 && r<=2) return R2.PDDLClass(r-2);
  if (r>=3 && r<=3) return R3.PDDLClass(r-3);
  if (r>=4 && r<=4) return R4.PDDLClass(r-4);
Error.Notrace("Internal: NextStateGenerator -- querying PDDL class for nonexisting rule.");
}
};
const RULE_INDEX_TYPE numrules = 5;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 5


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("start");
  }
  void Code(unsigned short r)
  {
mu_running_value = mu_true;
mu_cooling_value = mu_false;
mu_engineblown_value = mu_false;
mu_d = 0.000000e+00;
mu_a = 0.000000e+00;
mu_v = 0.000000e+00;
mu_f = 18000;
mu_cooling_prepare = mu_false;
mu_cooling_time = 0;
mu_restarting = mu_false;
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
int mu__goal_47() // Goal "enjoy"
{
bool mu__boolexpr48;
bool mu__boolexpr49;
bool mu__boolexpr50;
bool mu__boolexpr51;
bool mu__boolexpr52;
  if (!((mu_d) >= (mu_distance_to_reach))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = (!(mu_engineblown_value)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_f) >= (17926)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_v) >= (0.000000e+00)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_v) <= (1.000000e-01)) ; 
}
  if (!(mu__boolexpr49)) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_cooling_time) == (mu_cooling_total_time)) ; 
}
return mu__boolexpr48;
};

bool mu__condition_53() // Condition for Rule "enjoy"
{
  return mu__goal_47( );
}

/**** end rule declaration ****/

const rulerec goals[] = {
{"enjoy", &mu__condition_53, NULL, },
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
f:NoScalarset
a:NoScalarset
cooling_prepare:NoScalarset
running_value:NoScalarset
engineblown_value:NoScalarset
cooling_value:NoScalarset
restarting:NoScalarset
cooling_time:NoScalarset
d:NoScalarset
v:NoScalarset
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
        mu_f.MultisetSort();
        mu_a.MultisetSort();
        mu_cooling_prepare.MultisetSort();
        mu_running_value.MultisetSort();
        mu_engineblown_value.MultisetSort();
        mu_cooling_value.MultisetSort();
        mu_restarting.MultisetSort();
        mu_cooling_time.MultisetSort();
        mu_d.MultisetSort();
        mu_v.MultisetSort();
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
void mu_1_real_type::Permute(PermSet& Perm, int i) {};
void mu_1_real_type::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_real_type::Canonicalize(PermSet& Perm) {};
void mu_1_real_type::SimpleLimit(PermSet& Perm) {};
void mu_1_real_type::ArrayLimit(PermSet& Perm) {};
void mu_1_real_type::Limit(PermSet& Perm) {};
void mu_1_real_type::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for real type.\n"); };
void mu_1_real_fuel::Permute(PermSet& Perm, int i) {};
void mu_1_real_fuel::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_real_fuel::Canonicalize(PermSet& Perm) {};
void mu_1_real_fuel::SimpleLimit(PermSet& Perm) {};
void mu_1_real_fuel::ArrayLimit(PermSet& Perm) {};
void mu_1_real_fuel::Limit(PermSet& Perm) {};
void mu_1_real_fuel::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
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
              
              mu_f.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_f.MultisetSort();
              mu_a.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_a.MultisetSort();
              mu_cooling_prepare.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cooling_prepare.MultisetSort();
              mu_running_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_running_value.MultisetSort();
              mu_engineblown_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_engineblown_value.MultisetSort();
              mu_cooling_value.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cooling_value.MultisetSort();
              mu_restarting.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_restarting.MultisetSort();
              mu_cooling_time.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cooling_time.MultisetSort();
              mu_d.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_d.MultisetSort();
              mu_v.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_v.MultisetSort();
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

          mu_f.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_f.MultisetSort();
          mu_a.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_a.MultisetSort();
          mu_cooling_prepare.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cooling_prepare.MultisetSort();
          mu_running_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_running_value.MultisetSort();
          mu_engineblown_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_engineblown_value.MultisetSort();
          mu_cooling_value.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cooling_value.MultisetSort();
          mu_restarting.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_restarting.MultisetSort();
          mu_cooling_time.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cooling_time.MultisetSort();
          mu_d.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_d.MultisetSort();
          mu_v.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_v.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_f.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_f.MultisetSort();
              mu_a.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_a.MultisetSort();
              mu_cooling_prepare.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cooling_prepare.MultisetSort();
              mu_running_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_running_value.MultisetSort();
              mu_engineblown_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_engineblown_value.MultisetSort();
              mu_cooling_value.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cooling_value.MultisetSort();
              mu_restarting.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_restarting.MultisetSort();
              mu_cooling_time.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cooling_time.MultisetSort();
              mu_d.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_d.MultisetSort();
              mu_v.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_v.MultisetSort();
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
      mu_f.MultisetSort();
      mu_a.MultisetSort();
      mu_cooling_prepare.MultisetSort();
      mu_running_value.MultisetSort();
      mu_engineblown_value.MultisetSort();
      mu_cooling_value.MultisetSort();
      mu_restarting.MultisetSort();
      mu_cooling_time.MultisetSort();
      mu_d.MultisetSort();
      mu_v.MultisetSort();
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
        mu_f.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_f.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_a.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_a.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cooling_prepare.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cooling_prepare.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_running_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_running_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_engineblown_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_engineblown_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cooling_value.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cooling_value.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_restarting.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_restarting.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cooling_time.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cooling_time.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_d.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_d.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_v.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_v.MultisetSort();
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
