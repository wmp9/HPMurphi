/******************************
  Program "sb2.m" compiled by "Universal Planner Murphi Release 2.0.R8"

  Murphi Last Compiled date: "Jul 28 2014"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Universal Planner Murphi Release 2.0.R8"
#define MURPHI_DATE "Jul 28 2014"
#define PROTOCOL_NAME "sb2"
#define BITS_IN_WORLD 273
#define HASHC

/********************
  Include
 ********************/
#include "upm_prolog.hpp"
#include <typeinfo>

/********************
  Decl declaration
 ********************/

class mu_1_real_type: public mu__real
{
 public:
  inline double operator=(double val) { return mu__real::operator=(val); };
  inline double operator=(const mu_1_real_type& val) { return mu__real::operator=((double) val); };
  mu_1_real_type (const char *name, int os): mu__real(13,13,72,name, os) {};
  mu_1_real_type (void): mu__real(13,13,72) {};
  mu_1_real_type (double val): mu__real(13,13,72,"Parameter or function result.", 0)
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

class mu_1_integer: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_integer& val) { return mu__long::operator=((int) val); };
  mu_1_integer (const char *name, int os): mu__long(-1000, 1000, 11, name, os) {};
  mu_1_integer (void): mu__long(-1000, 1000, 11) {};
  mu_1_integer (int val): mu__long(-1000, 1000, 11, "Parameter or function result.", 0)
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
mu_1_integer mu_1_integer_undefined_var;

const double mu_T = +1.000000e-02;
/*** Variable declaration ***/
mu_1_integer mu_h_n("h_n",0);

/*** Variable declaration ***/
mu_1_integer mu_g_n("g_n",11);

/*** Variable declaration ***/
mu_1_integer mu_f_n("f_n",22);

/*** Variable declaration ***/
mu_1_real_type mu_capacitance("capacitance",33);

/*** Variable declaration ***/
mu_1_real_type mu_resistance("resistance",105);

/*** Variable declaration ***/
mu_1_real_type mu_ringtime("ringtime",177);

/*** Variable declaration ***/
mu_0_boolean mu_windowclosed("windowclosed",249);

/*** Variable declaration ***/
mu_0_boolean mu_windowopen("windowopen",251);

/*** Variable declaration ***/
mu_0_boolean mu_magnetoperational("magnetoperational",253);

/*** Variable declaration ***/
mu_0_boolean mu_freshair("freshair",255);

/*** Variable declaration ***/
mu_0_boolean mu_circuit("circuit",257);

/*** Variable declaration ***/
mu_0_boolean mu_alarmdisabled("alarmdisabled",259);

/*** Variable declaration ***/
mu_0_boolean mu_alarmenabled("alarmenabled",261);

/*** Variable declaration ***/
mu_0_boolean mu_voltage("voltage",263);

/*** Variable declaration ***/
mu_0_boolean mu_ringing("ringing",265);

/*** Variable declaration ***/
mu_0_boolean mu_almostawake("almostawake",267);

/*** Variable declaration ***/
mu_0_boolean mu_deeplyasleep("deeplyasleep",269);

/*** Variable declaration ***/
mu_0_boolean mu_awake("awake",271);


#include "sb1.h"

void mu_set_windowclosed(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_windowclosed.undefine();
else
  mu_windowclosed = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_windowclosed()
{
return mu_windowclosed;
	Error.Error("The end of function get_windowclosed reached without returning values.");
};
/*** end function declaration ***/

void mu_set_windowopen(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_windowopen.undefine();
else
  mu_windowopen = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_windowopen()
{
return mu_windowopen;
	Error.Error("The end of function get_windowopen reached without returning values.");
};
/*** end function declaration ***/

void mu_set_magnetoperational(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_magnetoperational.undefine();
else
  mu_magnetoperational = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_magnetoperational()
{
return mu_magnetoperational;
	Error.Error("The end of function get_magnetoperational reached without returning values.");
};
/*** end function declaration ***/

void mu_set_freshair(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_freshair.undefine();
else
  mu_freshair = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_freshair()
{
return mu_freshair;
	Error.Error("The end of function get_freshair reached without returning values.");
};
/*** end function declaration ***/

void mu_set_circuit(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_circuit.undefine();
else
  mu_circuit = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_circuit()
{
return mu_circuit;
	Error.Error("The end of function get_circuit reached without returning values.");
};
/*** end function declaration ***/

void mu_set_alarmdisabled(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_alarmdisabled.undefine();
else
  mu_alarmdisabled = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_alarmdisabled()
{
return mu_alarmdisabled;
	Error.Error("The end of function get_alarmdisabled reached without returning values.");
};
/*** end function declaration ***/

void mu_set_alarmenabled(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_alarmenabled.undefine();
else
  mu_alarmenabled = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_alarmenabled()
{
return mu_alarmenabled;
	Error.Error("The end of function get_alarmenabled reached without returning values.");
};
/*** end function declaration ***/

void mu_set_voltage(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_voltage.undefine();
else
  mu_voltage = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_voltage()
{
return mu_voltage;
	Error.Error("The end of function get_voltage reached without returning values.");
};
/*** end function declaration ***/

void mu_set_ringing(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_ringing.undefine();
else
  mu_ringing = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_ringing()
{
return mu_ringing;
	Error.Error("The end of function get_ringing reached without returning values.");
};
/*** end function declaration ***/

void mu_set_almostawake(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_almostawake.undefine();
else
  mu_almostawake = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_almostawake()
{
return mu_almostawake;
	Error.Error("The end of function get_almostawake reached without returning values.");
};
/*** end function declaration ***/

void mu_set_deeplyasleep(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_deeplyasleep.undefine();
else
  mu_deeplyasleep = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_deeplyasleep()
{
return mu_deeplyasleep;
	Error.Error("The end of function get_deeplyasleep reached without returning values.");
};
/*** end function declaration ***/

void mu_set_awake(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_awake.undefine();
else
  mu_awake = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_awake()
{
return mu_awake;
	Error.Error("The end of function get_awake reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_makecircuit()
{
bool mu__boolexpr0;
  if (!(!(mu_magnetoperational))) mu__boolexpr0 = FALSE ;
  else {
  mu__boolexpr0 = (!(mu_circuit)) ; 
}
if ( mu__boolexpr0 )
{
mu_circuit = mu_true;
return mu_true;
}
else
{
return mu_false;
}
	Error.Error("The end of function makecircuit reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_alarmtriggered()
{
bool mu__boolexpr1;
bool mu__boolexpr2;
  if (!(mu_circuit)) mu__boolexpr2 = FALSE ;
  else {
  mu__boolexpr2 = (mu_alarmdisabled) ; 
}
  if (!(mu__boolexpr2)) mu__boolexpr1 = FALSE ;
  else {
  mu__boolexpr1 = (mu_voltage) ; 
}
if ( mu__boolexpr1 )
{
mu_alarmenabled = mu_true;
mu_ringing = mu_true;
mu_alarmdisabled = mu_false;
return mu_true;
}
else
{
return mu_false;
}
	Error.Error("The end of function alarmtriggered reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_voltageavailable()
{
if ( (mu_capacitance) >= (5.000000e+00) )
{
mu_voltage = mu_true;
return mu_true;
}
else
{
return mu_false;
}
	Error.Error("The end of function voltageavailable reached without returning values.");
};
/*** end function declaration ***/

void mu_ring()
{
if ( mu_ringing )
{
mu_ringtime = increase_ringtime_process_ring( mu_ringtime, (double)mu_T );
}
};
/*** end procedure declaration ***/

mu_0_boolean mu_rouseprincess()
{
bool mu__boolexpr3;
bool mu__boolexpr4;
  if (!(mu_ringing)) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = ((mu_ringtime) >= (1.000000e+01)) ; 
}
  if (!(mu__boolexpr4)) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = (mu_deeplyasleep) ; 
}
if ( mu__boolexpr3 )
{
mu_almostawake = mu_true;
mu_deeplyasleep = mu_false;
return mu_true;
}
else
{
return mu_false;
}
	Error.Error("The end of function rouseprincess reached without returning values.");
};
/*** end function declaration ***/

void mu_chargecapacitor()
{
bool mu__boolexpr5;
  if (!(mu_circuit)) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = (!(mu_voltage)) ; 
}
if ( mu__boolexpr5 )
{
mu_capacitance = increase_capacitance_process_chargecapacitor( mu_capacitance, (double)mu_T, mu_resistance );
}
};
/*** end procedure declaration ***/

void mu_event_check()
{
/*** Variable declaration ***/
mu_0_boolean mu_event_triggered("event_triggered",0);

/*** Variable declaration ***/
mu_0_boolean mu_makecircuit_triggered("makecircuit_triggered",2);

/*** Variable declaration ***/
mu_0_boolean mu_alarmtriggered_triggered("alarmtriggered_triggered",4);

/*** Variable declaration ***/
mu_0_boolean mu_voltageavailable_triggered("voltageavailable_triggered",6);

/*** Variable declaration ***/
mu_0_boolean mu_rouseprincess_triggered("rouseprincess_triggered",8);

mu_event_triggered = mu_true;
mu_makecircuit_triggered = mu_false;
mu_alarmtriggered_triggered = mu_false;
mu_voltageavailable_triggered = mu_false;
mu_rouseprincess_triggered = mu_false;
{
  bool mu__while_expr_7;  mu__while_expr_7 = mu_event_triggered;
int mu__counter_6 = 0;
while (mu__while_expr_7) {
if ( ++mu__counter_6 > args->loopmax.value )
  Error.Error("Too many iterations in while loop.");
{
mu_event_triggered = mu_false;
if ( !(mu_makecircuit_triggered) )
{
mu_makecircuit_triggered = mu_makecircuit(  );
bool mu__boolexpr8;
  if (mu_event_triggered) mu__boolexpr8 = TRUE ;
  else {
  mu__boolexpr8 = (mu_makecircuit_triggered) ; 
}
mu_event_triggered = mu__boolexpr8;
}
if ( !(mu_alarmtriggered_triggered) )
{
mu_alarmtriggered_triggered = mu_alarmtriggered(  );
bool mu__boolexpr9;
  if (mu_event_triggered) mu__boolexpr9 = TRUE ;
  else {
  mu__boolexpr9 = (mu_alarmtriggered_triggered) ; 
}
mu_event_triggered = mu__boolexpr9;
}
if ( !(mu_voltageavailable_triggered) )
{
mu_voltageavailable_triggered = mu_voltageavailable(  );
bool mu__boolexpr10;
  if (mu_event_triggered) mu__boolexpr10 = TRUE ;
  else {
  mu__boolexpr10 = (mu_voltageavailable_triggered) ; 
}
mu_event_triggered = mu__boolexpr10;
}
if ( !(mu_rouseprincess_triggered) )
{
mu_rouseprincess_triggered = mu_rouseprincess(  );
bool mu__boolexpr11;
  if (mu_event_triggered) mu__boolexpr11 = TRUE ;
  else {
  mu__boolexpr11 = (mu_rouseprincess_triggered) ; 
}
mu_event_triggered = mu__boolexpr11;
}
};
mu__while_expr_7 = mu_event_triggered;
}
};
};
/*** end procedure declaration ***/

void mu_apply_continuous_change()
{
/*** Variable declaration ***/
mu_0_boolean mu_process_updated("process_updated",0);

/*** Variable declaration ***/
mu_0_boolean mu_end_while("end_while",2);

/*** Variable declaration ***/
mu_0_boolean mu_ring_enabled("ring_enabled",4);

/*** Variable declaration ***/
mu_0_boolean mu_chargecapacitor_enabled("chargecapacitor_enabled",6);

mu_process_updated = mu_false;
mu_end_while = mu_false;
mu_ring_enabled = mu_false;
mu_chargecapacitor_enabled = mu_false;
{
  bool mu__while_expr_13;  mu__while_expr_13 = !(mu_end_while);
int mu__counter_12 = 0;
while (mu__while_expr_13) {
if ( ++mu__counter_12 > args->loopmax.value )
  Error.Error("Too many iterations in while loop.");
{
bool mu__boolexpr14;
  if (!(mu_ringing)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = (!(mu_ring_enabled)) ; 
}
if ( mu__boolexpr14 )
{
mu_process_updated = mu_true;
mu_ring (  );
mu_ring_enabled = mu_true;
}
bool mu__boolexpr15;
bool mu__boolexpr16;
  if (!(mu_circuit)) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = (!(mu_voltage)) ; 
}
  if (!(mu__boolexpr16)) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = (!(mu_chargecapacitor_enabled)) ; 
}
if ( mu__boolexpr15 )
{
mu_process_updated = mu_true;
mu_chargecapacitor (  );
mu_chargecapacitor_enabled = mu_true;
}
if ( !(mu_process_updated) )
{
mu_end_while = mu_true;
}
else
{
mu_process_updated = mu_false;
}
};
mu__while_expr_13 = !(mu_end_while);
}
};
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_h_n.clear();
  mu_g_n.clear();
  mu_f_n.clear();
  mu_capacitance.clear();
  mu_resistance.clear();
  mu_ringtime.clear();
  mu_windowclosed.clear();
  mu_windowopen.clear();
  mu_magnetoperational.clear();
  mu_freshair.clear();
  mu_circuit.clear();
  mu_alarmdisabled.clear();
  mu_alarmenabled.clear();
  mu_voltage.clear();
  mu_ringing.clear();
  mu_almostawake.clear();
  mu_deeplyasleep.clear();
  mu_awake.clear();
}
void world_class::undefine()
{
  mu_h_n.undefine();
  mu_g_n.undefine();
  mu_f_n.undefine();
  mu_capacitance.undefine();
  mu_resistance.undefine();
  mu_ringtime.undefine();
  mu_windowclosed.undefine();
  mu_windowopen.undefine();
  mu_magnetoperational.undefine();
  mu_freshair.undefine();
  mu_circuit.undefine();
  mu_alarmdisabled.undefine();
  mu_alarmenabled.undefine();
  mu_voltage.undefine();
  mu_ringing.undefine();
  mu_almostawake.undefine();
  mu_deeplyasleep.undefine();
  mu_awake.undefine();
}
void world_class::reset()
{
  mu_h_n.reset();
  mu_g_n.reset();
  mu_f_n.reset();
  mu_capacitance.reset();
  mu_resistance.reset();
  mu_ringtime.reset();
  mu_windowclosed.reset();
  mu_windowopen.reset();
  mu_magnetoperational.reset();
  mu_freshair.reset();
  mu_circuit.reset();
  mu_alarmdisabled.reset();
  mu_alarmenabled.reset();
  mu_voltage.reset();
  mu_ringing.reset();
  mu_almostawake.reset();
  mu_deeplyasleep.reset();
  mu_awake.reset();
}
std::vector<mu_0_boolean*> world_class::get_mu_bools()
{
	  std::vector<mu_0_boolean*> awesome;

      awesome.push_back(&(mu_windowclosed));
      awesome.push_back(&(mu_windowopen));
      awesome.push_back(&(mu_magnetoperational));
      awesome.push_back(&(mu_freshair));
      awesome.push_back(&(mu_circuit));
      awesome.push_back(&(mu_alarmdisabled));
      awesome.push_back(&(mu_alarmenabled));
      awesome.push_back(&(mu_voltage));
      awesome.push_back(&(mu_ringing));
      awesome.push_back(&(mu_almostawake));
      awesome.push_back(&(mu_deeplyasleep));
      awesome.push_back(&(mu_awake));
    return awesome; 
}
std::vector<mu_0_boolean*> world_class::get_mu_bool_arrays()
{
	  std::vector<mu_0_boolean*> var_arrays;
   std::vector<mu_0_boolean*> interm;

    return var_arrays; 
}
//WP
double world_class::get_f_val()
{
  double f_val = mu_f_n.value();
  return 0;
}
//WP
void world_class::set_f_val()
{
  double f_val = mu_g_n.value() + mu_h_n.value();
  mu_f_n.value(0);
}
//WP
double world_class::get_h_val()
{
  double h_val = mu_h_n.value();
  return 0;
}
//WP
void world_class::set_h_val()
{
  	double h_val = 0;
  //   double h_val = upm_rpg().get_rpg_value();
//  upm_rpg::getInstance().clear_all();
//  double h_val = upm_rpg::getInstance().get_rpg_value();
  mu_h_n.value(h_val);
}
//WP
double world_class::get_g_val()
{
  double g_val = mu_g_n.value();
  return 0;
}
//WP
void world_class::set_g_val(double g_val)
{
  mu_g_n.value(0);
}
void world_class::print(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_h_n.print(target, separator);
  mu_g_n.print(target, separator);
  mu_f_n.print(target, separator);
  mu_capacitance.print(target, separator);
  mu_resistance.print(target, separator);
  mu_ringtime.print(target, separator);
  mu_windowclosed.print(target, separator);
  mu_windowopen.print(target, separator);
  mu_magnetoperational.print(target, separator);
  mu_freshair.print(target, separator);
  mu_circuit.print(target, separator);
  mu_alarmdisabled.print(target, separator);
  mu_alarmenabled.print(target, separator);
  mu_voltage.print(target, separator);
  mu_ringing.print(target, separator);
  mu_almostawake.print(target, separator);
  mu_deeplyasleep.print(target, separator);
  mu_awake.print(target, separator);
    num_calls--;
}
}
void world_class::pddlprint(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_capacitance.print(target, separator);
  mu_resistance.print(target, separator);
  mu_ringtime.print(target, separator);
  mu_windowclosed.print(target, separator);
  mu_windowopen.print(target, separator);
  mu_magnetoperational.print(target, separator);
  mu_freshair.print(target, separator);
  mu_circuit.print(target, separator);
  mu_alarmdisabled.print(target, separator);
  mu_alarmenabled.print(target, separator);
  mu_voltage.print(target, separator);
  mu_ringing.print(target, separator);
  mu_almostawake.print(target, separator);
  mu_deeplyasleep.print(target, separator);
  mu_awake.print(target, separator);
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_h_n.print_statistic();
  mu_g_n.print_statistic();
  mu_f_n.print_statistic();
  mu_capacitance.print_statistic();
  mu_resistance.print_statistic();
  mu_ringtime.print_statistic();
  mu_windowclosed.print_statistic();
  mu_windowopen.print_statistic();
  mu_magnetoperational.print_statistic();
  mu_freshair.print_statistic();
  mu_circuit.print_statistic();
  mu_alarmdisabled.print_statistic();
  mu_alarmenabled.print_statistic();
  mu_voltage.print_statistic();
  mu_ringing.print_statistic();
  mu_almostawake.print_statistic();
  mu_deeplyasleep.print_statistic();
  mu_awake.print_statistic();
    num_calls--;
}
}
void world_class::print_diff(state *prevstate, FILE *target, const char *separator)
{
  if ( prevstate != NULL )
  {
    mu_h_n.print_diff(prevstate,target,separator);
    mu_g_n.print_diff(prevstate,target,separator);
    mu_f_n.print_diff(prevstate,target,separator);
    mu_capacitance.print_diff(prevstate,target,separator);
    mu_resistance.print_diff(prevstate,target,separator);
    mu_ringtime.print_diff(prevstate,target,separator);
    mu_windowclosed.print_diff(prevstate,target,separator);
    mu_windowopen.print_diff(prevstate,target,separator);
    mu_magnetoperational.print_diff(prevstate,target,separator);
    mu_freshair.print_diff(prevstate,target,separator);
    mu_circuit.print_diff(prevstate,target,separator);
    mu_alarmdisabled.print_diff(prevstate,target,separator);
    mu_alarmenabled.print_diff(prevstate,target,separator);
    mu_voltage.print_diff(prevstate,target,separator);
    mu_ringing.print_diff(prevstate,target,separator);
    mu_almostawake.print_diff(prevstate,target,separator);
    mu_deeplyasleep.print_diff(prevstate,target,separator);
    mu_awake.print_diff(prevstate,target,separator);
  }
  else
print(target,separator);
}
void world_class::to_state(state *newstate)
{
  mu_h_n.to_state( newstate );
  mu_g_n.to_state( newstate );
  mu_f_n.to_state( newstate );
  mu_capacitance.to_state( newstate );
  mu_resistance.to_state( newstate );
  mu_ringtime.to_state( newstate );
  mu_windowclosed.to_state( newstate );
  mu_windowopen.to_state( newstate );
  mu_magnetoperational.to_state( newstate );
  mu_freshair.to_state( newstate );
  mu_circuit.to_state( newstate );
  mu_alarmdisabled.to_state( newstate );
  mu_alarmenabled.to_state( newstate );
  mu_voltage.to_state( newstate );
  mu_ringing.to_state( newstate );
  mu_almostawake.to_state( newstate );
  mu_deeplyasleep.to_state( newstate );
  mu_awake.to_state( newstate );
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
    return tsprintf(" time passing ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return mu_true;
  }

  std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> preconds;


    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;



    return effs;
  }

  std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> aeffs;



    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
	      if (mu_true) {
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
mu_event_check (  );
mu_apply_continuous_change (  );
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {





  }

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
    return tsprintf(" time passing ");
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::Clock;
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
    return tsprintf(" kiss ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    return mu_almostawake;
  }

  std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> preconds;

		preconds.push_back(mu_almostawake.name); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;


    effs.push_back(&(mu_awake));  // mu_true 
    effs.push_back(&(mu_almostawake));  // mu_false 

    return effs;
  }

  std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> aeffs;


    aeffs.push_back(mu_awake.name); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 1;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
	      if (mu_almostawake) {
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
mu_awake = mu_true;
mu_almostawake = mu_false;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {



    mu_awake = mu_true; 


  }

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
    return tsprintf(" kiss");
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
    return tsprintf(" closewindow ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr17;
  if (!(mu_windowopen)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = (!(mu_magnetoperational)) ; 
}
    return mu__boolexpr17;
  }

  std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> preconds;

//		preconds.push_back(!(mu_magnetoperational).name);
		preconds.push_back(mu_windowopen.name); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;


    effs.push_back(&(mu_magnetoperational));  // mu_true 
    effs.push_back(&(mu_windowclosed));  // mu_true 
    effs.push_back(&(mu_windowopen));  // mu_false 

    return effs;
  }

  std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> aeffs;


    aeffs.push_back(mu_magnetoperational.name); //  mu_true 
    aeffs.push_back(mu_windowclosed.name); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 2;
    while (what_rule < 3 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr18;
  if (!(mu_windowopen)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = (!(mu_magnetoperational)) ; 
}
	      if (mu__boolexpr18) {
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
mu_magnetoperational = mu_true;
mu_windowclosed = mu_true;
mu_windowopen = mu_false;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {



    mu_magnetoperational = mu_true; 
    mu_windowclosed = mu_true; 


  }

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
    return tsprintf(" closewindow");
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
    return tsprintf(" openwindow ");
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
bool mu__boolexpr19;
  if (!(mu_windowclosed)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = (mu_magnetoperational) ; 
}
    return mu__boolexpr19;
  }

  std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> preconds;

		preconds.push_back(mu_magnetoperational.name); 
		preconds.push_back(mu_windowclosed.name); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;


    effs.push_back(&(mu_windowopen));  // mu_true 
    effs.push_back(&(mu_freshair));  // mu_true 
    effs.push_back(&(mu_magnetoperational));  // mu_false 
    effs.push_back(&(mu_windowclosed));  // mu_false 

    return effs;
  }

  std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> aeffs;


    aeffs.push_back(mu_windowopen.name); //  mu_true 
    aeffs.push_back(mu_freshair.name); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 3;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr20;
  if (!(mu_windowclosed)) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = (mu_magnetoperational) ; 
}
	      if (mu__boolexpr20) {
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
mu_windowopen = mu_true;
mu_freshair = mu_true;
mu_magnetoperational = mu_false;
mu_windowclosed = mu_false;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {



    mu_windowopen = mu_true; 
    mu_freshair = mu_true; 


  }

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
    return tsprintf(" openwindow");
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
}
bool Condition(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
  if (r>=2 && r<=2) return R2.Condition(r-2);
  if (r>=3 && r<=3) return R3.Condition(r-3);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.precond_array(r-0);
  if (r>=1 && r<=1) return R1.precond_array(r-1);
  if (r>=2 && r<=2) return R2.precond_array(r-2);
  if (r>=3 && r<=3) return R3.precond_array(r-3);
Error.Notrace("Internal: NextStateGenerator -- checking preconditions for nonexisting rule.");
}
std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.effects_array(r-0);
  if (r>=1 && r<=1) return R1.effects_array(r-1);
  if (r>=2 && r<=2) return R2.effects_array(r-2);
  if (r>=3 && r<=3) return R3.effects_array(r-3);
Error.Notrace("Internal: NextStateGenerator -- checking effects for nonexisting rule.");
}
std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.effects_add_array(r-0);
  if (r>=1 && r<=1) return R1.effects_add_array(r-1);
  if (r>=2 && r<=2) return R2.effects_add_array(r-2);
  if (r>=3 && r<=3) return R3.effects_add_array(r-3);
Error.Notrace("Internal: NextStateGenerator -- checking add effects for nonexisting rule.");
}
void Code(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code(r-2); return; } 
  if (r>=3 && r<=3) { R3.Code(r-3); return; } 
}
void Code_ff(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code_ff(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code_ff(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code_ff(r-2); return; } 
  if (r>=3 && r<=3) { R3.Code_ff(r-3); return; } 
}
int Priority(RULE_INDEX_TYPE r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
  if (r>=2 && r<=2) { return R2.Priority(); } 
  if (r>=3 && r<=3) { return R3.Priority(); } 
}
char * Name(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  if (r>=2 && r<=2) return R2.Name(r-2);
  if (r>=3 && r<=3) return R3.Name(r-3);
  return NULL;
}
int Duration(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Duration(r-0);
  if (r>=1 && r<=1) return R1.Duration(r-1);
  if (r>=2 && r<=2) return R2.Duration(r-2);
  if (r>=3 && r<=3) return R3.Duration(r-3);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
int Weight(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Weight(r-0);
  if (r>=1 && r<=1) return R1.Weight(r-1);
  if (r>=2 && r<=2) return R2.Weight(r-2);
  if (r>=3 && r<=3) return R3.Weight(r-3);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
char * PDDLName(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLName(r-0);
  if (r>=1 && r<=1) return R1.PDDLName(r-1);
  if (r>=2 && r<=2) return R2.PDDLName(r-2);
  if (r>=3 && r<=3) return R3.PDDLName(r-3);
  return NULL;
}
RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLClass(r-0);
  if (r>=1 && r<=1) return R1.PDDLClass(r-1);
  if (r>=2 && r<=2) return R2.PDDLClass(r-2);
  if (r>=3 && r<=3) return R3.PDDLClass(r-3);
Error.Notrace("Internal: NextStateGenerator -- querying PDDL class for nonexisting rule.");
}
};
const RULE_INDEX_TYPE numrules = 4;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 4


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
mu_set_windowclosed ( mu_false );
mu_set_windowopen ( mu_false );
mu_set_magnetoperational ( mu_false );
mu_set_freshair ( mu_false );
mu_set_circuit ( mu_false );
mu_set_alarmdisabled ( mu_false );
mu_set_alarmenabled ( mu_false );
mu_set_voltage ( mu_false );
mu_set_ringing ( mu_false );
mu_set_almostawake ( mu_false );
mu_set_deeplyasleep ( mu_false );
mu_set_awake ( mu_false );
mu_capacitance = 0.000000e+00;
mu_resistance = 0.000000e+00;
mu_ringtime = 0.000000e+00;
mu_windowclosed = mu_true;
mu_magnetoperational = mu_true;
mu_alarmdisabled = mu_true;
mu_deeplyasleep = mu_true;
mu_capacitance = 0.000000e+00;
mu_resistance = 2.000000e+00;
mu_ringtime = 0.000000e+00;
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
int mu__goal_21() // Goal "enjoy"
{
bool mu__boolexpr22;
  if (!(mu_freshair)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = (mu_deeplyasleep) ; 
}
return mu__boolexpr22;
};

bool mu__condition_23() // Condition for Rule "enjoy"
{
  return mu__goal_21( );
}

/**** end rule declaration ****/

const rulerec goals[] = {
{"enjoy", &mu__condition_23, NULL, },
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
deeplyasleep:NoScalarset
ringing:NoScalarset
alarmenabled:NoScalarset
circuit:NoScalarset
magnetoperational:NoScalarset
windowclosed:NoScalarset
resistance:NoScalarset
f_n:NoScalarset
h_n:NoScalarset
g_n:NoScalarset
capacitance:NoScalarset
ringtime:NoScalarset
windowopen:NoScalarset
freshair:NoScalarset
alarmdisabled:NoScalarset
voltage:NoScalarset
almostawake:NoScalarset
awake:NoScalarset
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
        mu_deeplyasleep.MultisetSort();
        mu_ringing.MultisetSort();
        mu_alarmenabled.MultisetSort();
        mu_circuit.MultisetSort();
        mu_magnetoperational.MultisetSort();
        mu_windowclosed.MultisetSort();
        mu_resistance.MultisetSort();
        mu_f_n.MultisetSort();
        mu_h_n.MultisetSort();
        mu_g_n.MultisetSort();
        mu_capacitance.MultisetSort();
        mu_ringtime.MultisetSort();
        mu_windowopen.MultisetSort();
        mu_freshair.MultisetSort();
        mu_alarmdisabled.MultisetSort();
        mu_voltage.MultisetSort();
        mu_almostawake.MultisetSort();
        mu_awake.MultisetSort();
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
void mu_1_integer::Permute(PermSet& Perm, int i) {};
void mu_1_integer::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_integer::Canonicalize(PermSet& Perm) {};
void mu_1_integer::SimpleLimit(PermSet& Perm) {};
void mu_1_integer::ArrayLimit(PermSet& Perm) {};
void mu_1_integer::Limit(PermSet& Perm) {};
void mu_1_integer::MultisetLimit(PermSet& Perm)
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
              
              mu_deeplyasleep.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_deeplyasleep.MultisetSort();
              mu_ringing.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ringing.MultisetSort();
              mu_alarmenabled.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_alarmenabled.MultisetSort();
              mu_circuit.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_circuit.MultisetSort();
              mu_magnetoperational.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_magnetoperational.MultisetSort();
              mu_windowclosed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_windowclosed.MultisetSort();
              mu_resistance.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_resistance.MultisetSort();
              mu_f_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
              mu_h_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_g_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_capacitance.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_capacitance.MultisetSort();
              mu_ringtime.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ringtime.MultisetSort();
              mu_windowopen.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_windowopen.MultisetSort();
              mu_freshair.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_freshair.MultisetSort();
              mu_alarmdisabled.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_alarmdisabled.MultisetSort();
              mu_voltage.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_voltage.MultisetSort();
              mu_almostawake.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_almostawake.MultisetSort();
              mu_awake.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_awake.MultisetSort();
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

          mu_deeplyasleep.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_deeplyasleep.MultisetSort();
          mu_ringing.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ringing.MultisetSort();
          mu_alarmenabled.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_alarmenabled.MultisetSort();
          mu_circuit.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_circuit.MultisetSort();
          mu_magnetoperational.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_magnetoperational.MultisetSort();
          mu_windowclosed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_windowclosed.MultisetSort();
          mu_resistance.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_resistance.MultisetSort();
          mu_f_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_f_n.MultisetSort();
          mu_h_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_h_n.MultisetSort();
          mu_g_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_g_n.MultisetSort();
          mu_capacitance.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_capacitance.MultisetSort();
          mu_ringtime.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ringtime.MultisetSort();
          mu_windowopen.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_windowopen.MultisetSort();
          mu_freshair.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_freshair.MultisetSort();
          mu_alarmdisabled.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_alarmdisabled.MultisetSort();
          mu_voltage.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_voltage.MultisetSort();
          mu_almostawake.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_almostawake.MultisetSort();
          mu_awake.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_awake.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_deeplyasleep.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_deeplyasleep.MultisetSort();
              mu_ringing.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ringing.MultisetSort();
              mu_alarmenabled.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_alarmenabled.MultisetSort();
              mu_circuit.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_circuit.MultisetSort();
              mu_magnetoperational.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_magnetoperational.MultisetSort();
              mu_windowclosed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_windowclosed.MultisetSort();
              mu_resistance.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_resistance.MultisetSort();
              mu_f_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
              mu_h_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_g_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_capacitance.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_capacitance.MultisetSort();
              mu_ringtime.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ringtime.MultisetSort();
              mu_windowopen.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_windowopen.MultisetSort();
              mu_freshair.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_freshair.MultisetSort();
              mu_alarmdisabled.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_alarmdisabled.MultisetSort();
              mu_voltage.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_voltage.MultisetSort();
              mu_almostawake.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_almostawake.MultisetSort();
              mu_awake.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_awake.MultisetSort();
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
      mu_deeplyasleep.MultisetSort();
      mu_ringing.MultisetSort();
      mu_alarmenabled.MultisetSort();
      mu_circuit.MultisetSort();
      mu_magnetoperational.MultisetSort();
      mu_windowclosed.MultisetSort();
      mu_resistance.MultisetSort();
      mu_f_n.MultisetSort();
      mu_h_n.MultisetSort();
      mu_g_n.MultisetSort();
      mu_capacitance.MultisetSort();
      mu_ringtime.MultisetSort();
      mu_windowopen.MultisetSort();
      mu_freshair.MultisetSort();
      mu_alarmdisabled.MultisetSort();
      mu_voltage.MultisetSort();
      mu_almostawake.MultisetSort();
      mu_awake.MultisetSort();
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
        mu_deeplyasleep.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_deeplyasleep.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ringing.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ringing.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_alarmenabled.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_alarmenabled.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_circuit.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_circuit.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_magnetoperational.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_magnetoperational.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_windowclosed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_windowclosed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_resistance.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_resistance.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_f_n.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_f_n.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_h_n.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_h_n.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_g_n.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_g_n.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_capacitance.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_capacitance.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ringtime.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ringtime.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_windowopen.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_windowopen.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_freshair.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_freshair.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_alarmdisabled.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_alarmdisabled.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_voltage.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_voltage.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_almostawake.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_almostawake.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_awake.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_awake.MultisetSort();
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
