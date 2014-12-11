/******************************
  Program "drivedomain.m" compiled by "Universal Planner Murphi Release 2.0.R8"

  Murphi Last Compiled date: "Jul 28 2014"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Universal Planner Murphi Release 2.0.R8"
#define MURPHI_DATE "Jul 28 2014"
#define PROTOCOL_NAME "drivedomain"
#define BITS_IN_WORLD 553
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
  mu_1_real_type (const char *name, int os): mu__real(12,12,64,name, os) {};
  mu_1_real_type (void): mu__real(12,12,64) {};
  mu_1_real_type (double val): mu__real(12,12,64,"Parameter or function result.", 0)
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

class mu_1_vehicle: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_vehicle& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_vehicle& val)
  {
    if (val.defined())
      return ( s << mu_1_vehicle::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_vehicle (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu_1_vehicle (void): mu__byte(1, 1, 1) {};
  mu_1_vehicle (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -1]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print(FILE *target, const char *separator)
  {
    if (defined())
    fprintf(target,"%s: %s%s",name,values[ value() -1],separator); 
    else
    fprintf(target,"%s: Undefined%s",name,separator); 
  };
};

const char *mu_1_vehicle::values[] = {"car",NULL };

/*** end of enum declaration ***/
mu_1_vehicle mu_1_vehicle_undefined_var;

class mu_1_location: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_location& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_location& val)
  {
    if (val.defined())
      return ( s << mu_1_location::values[ int(val) - 2] );
    else return ( s << "Undefined" );
  };

  mu_1_location (const char *name, int os): mu__byte(2, 3, 2, name, os) {};
  mu_1_location (void): mu__byte(2, 3, 2) {};
  mu_1_location (int val): mu__byte(2, 3, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -2]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print(FILE *target, const char *separator)
  {
    if (defined())
    fprintf(target,"%s: %s%s",name,values[ value() -2],separator); 
    else
    fprintf(target,"%s: Undefined%s",name,separator); 
  };
};

const char *mu_1_location::values[] = {"tstart","tend",NULL };

/*** end of enum declaration ***/
mu_1_location mu_1_location_undefined_var;

class mu_1__type_0:public mu_1__type_super
{
 public:
  mu_1_real_type array[ 2 ]; 
#define awesome_mu_00_mu_1_real_type_mu_1__type_0 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_0 (const char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_real_type& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 2 ) && ( index <= 3 ) )
      return array[ index - 2 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 2 ];
#endif
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_0
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_0
		for (int ix = 0; ix < 2; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 2; ix++){
			for (int ix2 = 0; ix2 < 2; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 2; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_0::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_0::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"tstart", i * 64 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"tend", i * 64 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1:public mu_1__type_super
{
 public:
  mu_1__type_0 array[ 2 ]; 
#define awesome_mu_00_mu_1__type_0_mu_1__type_1 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_1 (const char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1__type_0& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 2 ) && ( index <= 3 ) )
      return array[ index - 2 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 2 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_1
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_1
		for (int ix = 0; ix < 2; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 2; ix++){
			for (int ix2 = 0; ix2 < 2; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 2; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_1::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"tstart", i * 128 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"tend", i * 128 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2:public mu_1__type_super
{
 public:
  mu_1_real_type array[ 1 ]; 
#define awesome_mu_00_mu_1_real_type_mu_1__type_2 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os) { set_self(n, os); };
  mu_1__type_2 ( void ) {};
  virtual ~mu_1__type_2 ();
  mu_1_real_type& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_2
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_2
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_2::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_2::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 64 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_2::~mu_1__type_2()
{
}
/*** end array declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3:public mu_1__type_super
{
 public:
  mu_1_real_type array[ 1 ]; 
#define awesome_mu_00_mu_1_real_type_mu_1__type_3 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_3 (const char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_real_type& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_3
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_3
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_3::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_3::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 64 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4:public mu_1__type_super
{
 public:
  mu_1_real_type array[ 1 ]; 
#define awesome_mu_00_mu_1_real_type_mu_1__type_4 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_4 (const char *n, int os) { set_self(n, os); };
  mu_1__type_4 ( void ) {};
  virtual ~mu_1__type_4 ();
  mu_1_real_type& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_4
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_4
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_4::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_4::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 64 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 1 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_5 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_5 (const char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_5
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_5
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_5::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_5::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6:public mu_1__type_super
{
 public:
  mu_1_real_type array[ 1 ]; 
#define awesome_mu_00_mu_1_real_type_mu_1__type_6 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_6 (const char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1_real_type& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_6
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_6
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_6::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_6::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 64 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 2 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_7 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_7 (const char *n, int os) { set_self(n, os); };
  mu_1__type_7 ( void ) {};
  virtual ~mu_1__type_7 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 2 ) && ( index <= 3 ) )
      return array[ index - 2 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 2 ];
#endif
  };
  mu_1__type_7& operator= (const mu_1__type_7& from)
  {
    for (int i = 0; i < 2; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_7
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_7
		for (int ix = 0; ix < 2; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 2; ix++){
			for (int ix2 = 0; ix2 < 2; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 2; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_7::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_7::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"tstart", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"tend", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_7::~mu_1__type_7()
{
}
/*** end array declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8:public mu_1__type_super
{
 public:
  mu_1__type_7 array[ 1 ]; 
#define awesome_mu_00_mu_1__type_7_mu_1__type_8 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_8 (const char *n, int os) { set_self(n, os); };
  mu_1__type_8 ( void ) {};
  virtual ~mu_1__type_8 ();
  mu_1__type_7& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_8& operator= (const mu_1__type_8& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_8
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_8
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_8::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_8::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_8::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 4 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_8::~mu_1__type_8()
{
}
/*** end array declaration ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 1 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_9 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_9 (const char *n, int os) { set_self(n, os); };
  mu_1__type_9 ( void ) {};
  virtual ~mu_1__type_9 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_9& operator= (const mu_1__type_9& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_9& a, mu_1__type_9& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_9& a, mu_1__type_9& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_9
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_9
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_9::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_9::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_9::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_9::~mu_1__type_9()
{
}
/*** end array declaration ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 1 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_10 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_10 (const char *n, int os) { set_self(n, os); };
  mu_1__type_10 ( void ) {};
  virtual ~mu_1__type_10 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_10& operator= (const mu_1__type_10& from)
  {
      array[0].value(from.array[0].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_10& a, mu_1__type_10& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_10& a, mu_1__type_10& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  int array_dim() {

  const char* mb = "mu_0_boolean";
  const char* mt = "mu_1__type";

	int dim = 1;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_10
		return 1;
	#else 
	if (strstr(typeid(array).name(), mt) != NULL){
			dim += array[0].array_dim();
  			return dim;
	}
   else { return (-1); }
   

	#endif 
}
  std::vector<mu_0_boolean*> bool_array() {

	std::vector<mu_0_boolean*> barr;
	#ifdef awesome_mu_00_mu_0_boolean_mu_1__type_10
		for (int ix = 0; ix < 1; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 1; ix++){
			for (int ix2 = 0; ix2 < 1; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate,target,separator);
  };
};

  void mu_1__type_10::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_10::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1__type_10::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"car", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_10::~mu_1__type_10()
{
}
/*** end array declaration ***/
mu_1__type_10 mu_1__type_10_undefined_var;

const int mu_car = 1;
const int mu_tstart = 2;
const int mu_tend = 3;
const int mu_T = 1;
/*** Variable declaration ***/
mu_1_integer mu_h_n("h_n",0);

/*** Variable declaration ***/
mu_1_integer mu_g_n("g_n",11);

/*** Variable declaration ***/
mu_1_integer mu_f_n("f_n",22);

/*** Variable declaration ***/
mu_0_boolean mu_all_event_true("all_event_true",33);

/*** Variable declaration ***/
mu_1__type_1 mu_distance("distance",35);

/*** Variable declaration ***/
mu_1__type_2 mu_maxspeed("maxspeed",291);

/*** Variable declaration ***/
mu_1__type_3 mu_speed("speed",355);

/*** Variable declaration ***/
mu_1__type_4 mu_traveltime("traveltime",419);

/*** Variable declaration ***/
mu_1__type_5 mu_accelerate_clock_started("accelerate_clock_started",483);

/*** Variable declaration ***/
mu_1__type_6 mu_accelerate_clock("accelerate_clock",485);

/*** Variable declaration ***/
mu_1__type_8 mu_at("at",549);


#include "drivedomain.h"

void mu_set_at(const mu_1_vehicle& mu_v, const mu_1_location& mu_l, const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_at[mu_v][mu_l].undefine();
else
  mu_at[mu_v][mu_l] = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_at(const mu_1_vehicle& mu_v,const mu_1_location& mu_l)
{
return mu_at[mu_v][mu_l];
	Error.Error("The end of function get_at reached without returning values.");
};
/*** end function declaration ***/

void mu_process_accelerate(const mu_1_vehicle& mu_v)
{
if ( mu_accelerate_clock_started[mu_v] )
{
mu_accelerate_clock[mu_v] = (mu_accelerate_clock[mu_v]) + (mu_T);
}
};
/*** end procedure declaration ***/

mu_0_boolean mu_event_accelerate_failure(const mu_1_vehicle& mu_v)
{
if ( mu_accelerate_clock_started[mu_v] )
{
mu_accelerate_clock[mu_v] = (mu_accelerate_clock[mu_v]) + (mu_T);
mu_all_event_true = mu_false;
return mu_true;
}
else
{
return mu_false;
}
	Error.Error("The end of function event_accelerate_failure reached without returning values.");
};
/*** end function declaration ***/

void mu_event_check()
{
/*** Variable declaration ***/
mu_0_boolean mu_event_triggered("event_triggered",0);

/*** Variable declaration ***/
mu_1__type_9 mu_event_accelerate_failure_triggered("event_accelerate_failure_triggered",2);

mu_event_triggered = mu_true;
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
mu_event_accelerate_failure_triggered[mu_v] = mu_false;
};
};
{
  bool mu__while_expr_12;  mu__while_expr_12 = mu_event_triggered;
int mu__counter_11 = 0;
while (mu__while_expr_12) {
if ( ++mu__counter_11 > args->loopmax.value )
  Error.Error("Too many iterations in while loop.");
{
mu_event_triggered = mu_false;
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
if ( !(mu_event_accelerate_failure_triggered[mu_v]) )
{
mu_event_accelerate_failure_triggered[mu_v] = mu_event_accelerate_failure( mu_v );
bool mu__boolexpr13;
  if (mu_event_triggered) mu__boolexpr13 = TRUE ;
  else {
  mu__boolexpr13 = (mu_event_accelerate_failure_triggered[mu_v]) ; 
}
mu_event_triggered = mu__boolexpr13;
}
};
};
};
mu__while_expr_12 = mu_event_triggered;
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
mu_1__type_10 mu_process_accelerate_enabled("process_accelerate_enabled",4);

mu_process_updated = mu_false;
mu_end_while = mu_false;
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
mu_process_accelerate_enabled[mu_v] = mu_false;
};
};
{
  bool mu__while_expr_15;  mu__while_expr_15 = !(mu_end_while);
int mu__counter_14 = 0;
while (mu__while_expr_15) {
if ( ++mu__counter_14 > args->loopmax.value )
  Error.Error("Too many iterations in while loop.");
{
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
bool mu__boolexpr16;
  if (!(mu_accelerate_clock_started[mu_v])) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = (!(mu_process_accelerate_enabled[mu_v])) ; 
}
if ( mu__boolexpr16 )
{
mu_process_updated = mu_true;
mu_process_accelerate ( mu_v );
mu_process_accelerate_enabled[mu_v] = mu_true;
}
};
};
if ( !(mu_process_updated) )
{
mu_end_while = mu_true;
}
else
{
mu_process_updated = mu_false;
}
};
mu__while_expr_15 = !(mu_end_while);
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
  mu_all_event_true.clear();
  mu_distance.clear();
  mu_maxspeed.clear();
  mu_speed.clear();
  mu_traveltime.clear();
  mu_accelerate_clock_started.clear();
  mu_accelerate_clock.clear();
  mu_at.clear();
}
void world_class::undefine()
{
  mu_h_n.undefine();
  mu_g_n.undefine();
  mu_f_n.undefine();
  mu_all_event_true.undefine();
  mu_distance.undefine();
  mu_maxspeed.undefine();
  mu_speed.undefine();
  mu_traveltime.undefine();
  mu_accelerate_clock_started.undefine();
  mu_accelerate_clock.undefine();
  mu_at.undefine();
}
void world_class::reset()
{
  mu_h_n.reset();
  mu_g_n.reset();
  mu_f_n.reset();
  mu_all_event_true.reset();
  mu_distance.reset();
  mu_maxspeed.reset();
  mu_speed.reset();
  mu_traveltime.reset();
  mu_accelerate_clock_started.reset();
  mu_accelerate_clock.reset();
  mu_at.reset();
}
std::vector<mu_0_boolean*> world_class::get_mu_bools()
{
	  std::vector<mu_0_boolean*> awesome;

      awesome.push_back(&(mu_all_event_true));
    return awesome; 
}
std::vector<mu_0_boolean*> world_class::get_mu_bool_arrays()
{
	  std::vector<mu_0_boolean*> var_arrays;
   std::vector<mu_0_boolean*> interm;

      interm = mu_distance.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_maxspeed.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_speed.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_traveltime.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_accelerate_clock_started.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_accelerate_clock.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_at.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
    return var_arrays; 
}
//WP
double world_class::get_f_val()
{
  double f_val = mu_f_n.value();
  return f_val;
}
//WP
void world_class::set_f_val()
{
  double f_val = mu_g_n.value() + mu_h_n.value();
  mu_f_n.value(f_val);
}
//WP
double world_class::get_h_val()
{
  double h_val = mu_h_n.value();
  return h_val;
}
//WP
void world_class::set_h_val()
{
  //	double h_val = 0; 
  //   double h_val = upm_rpg().get_rpg_value();
  upm_rpg::getInstance().clear_all();
  double h_val = upm_rpg::getInstance().get_rpg_value();
  mu_h_n.value(h_val);
}
//WP
double world_class::get_g_val()
{
  double g_val = mu_g_n.value();
  return g_val;
}
//WP
void world_class::set_g_val(double g_val)
{
  mu_g_n.value(g_val);
}
void world_class::print(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_h_n.print(target, separator);
  mu_g_n.print(target, separator);
  mu_f_n.print(target, separator);
  mu_all_event_true.print(target, separator);
  mu_distance.print(target, separator);
  mu_maxspeed.print(target, separator);
  mu_speed.print(target, separator);
  mu_traveltime.print(target, separator);
  mu_accelerate_clock_started.print(target, separator);
  mu_accelerate_clock.print(target, separator);
  mu_at.print(target, separator);
    num_calls--;
}
}
void world_class::pddlprint(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_distance.print(target, separator);
  mu_maxspeed.print(target, separator);
  mu_speed.print(target, separator);
  mu_traveltime.print(target, separator);
  mu_at.print(target, separator);
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
  mu_all_event_true.print_statistic();
  mu_distance.print_statistic();
  mu_maxspeed.print_statistic();
  mu_speed.print_statistic();
  mu_traveltime.print_statistic();
  mu_accelerate_clock_started.print_statistic();
  mu_accelerate_clock.print_statistic();
  mu_at.print_statistic();
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
    mu_all_event_true.print_diff(prevstate,target,separator);
    mu_distance.print_diff(prevstate,target,separator);
    mu_maxspeed.print_diff(prevstate,target,separator);
    mu_speed.print_diff(prevstate,target,separator);
    mu_traveltime.print_diff(prevstate,target,separator);
    mu_accelerate_clock_started.print_diff(prevstate,target,separator);
    mu_accelerate_clock.print_diff(prevstate,target,separator);
    mu_at.print_diff(prevstate,target,separator);
  }
  else
print(target,separator);
}
void world_class::to_state(state *newstate)
{
  mu_h_n.to_state( newstate );
  mu_g_n.to_state( newstate );
  mu_f_n.to_state( newstate );
  mu_all_event_true.to_state( newstate );
  mu_distance.to_state( newstate );
  mu_maxspeed.to_state( newstate );
  mu_speed.to_state( newstate );
  mu_traveltime.to_state( newstate );
  mu_accelerate_clock_started.to_state( newstate );
  mu_accelerate_clock.to_state( newstate );
  mu_at.to_state( newstate );
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
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return tsprintf(" drive , l:%s, p:%s, v:%s", mu_l.Name(), mu_p.Name(), mu_v.Name());
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
bool mu__boolexpr17;
  if (!(mu_at[mu_v][mu_p])) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_speed[mu_v]) > (0.000000e+00)) ; 
}
    return mu__boolexpr17;
  }

  std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> preconds;
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

		preconds.push_back((mu_speed[mu_v]) > (0.000000e+00).name); 
		preconds.push_back(0.000000e+00.name); 
		preconds.push_back(mu_at[mu_v][mu_p].name); 
		preconds.push_back(mu_speed[mu_v].name); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;

    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    effs.push_back(&(mu_at[mu_v][mu_l]));  // mu_true 
    effs.push_back(&(mu_at[mu_v][mu_p]));  // mu_false 
    effs.push_back(&(mu_traveltime[mu_v]));  // increase_traveltime_action_drive( mu_traveltime[mu_v], mu_distance[mu_p][mu_l], mu_speed[mu_v] ) 

    return effs;
  }

  std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> aeffs;

    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    aeffs.push_back(mu_at[mu_v][mu_l].name); //  mu_true 
    aeffs.push_back(mu_traveltime[mu_v].name); //  increase_traveltime_action_drive( mu_traveltime[mu_v], mu_distance[mu_p][mu_l], mu_speed[mu_v] ) 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 1;
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 5 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr18;
  if (!(mu_at[mu_v][mu_p])) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_speed[mu_v]) > (0.000000e+00)) ; 
}
	      if (mu__boolexpr18) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 1;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
mu_at[mu_v][mu_l] = mu_true;
mu_at[mu_v][mu_p] = mu_false;
mu_traveltime[mu_v] = increase_traveltime_action_drive( mu_traveltime[mu_v], mu_distance[mu_p][mu_l], mu_speed[mu_v] );
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {


    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    mu_at[mu_v][mu_l] = mu_true; 
    mu_traveltime[mu_v] = increase_traveltime_action_drive( mu_traveltime[mu_v], mu_distance[mu_p][mu_l], mu_speed[mu_v] ); 


  }

  int Duration(RULE_INDEX_TYPE r)
  {
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    static mu_1_location mu_l;
    mu_l.value((r % 2) + 2);
    r = r / 2;
    static mu_1_location mu_p;
    mu_p.value((r % 2) + 2);
    r = r / 2;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return tsprintf(" drive(%s,%s,%s)", mu_l.Name(), mu_p.Name(), mu_v.Name());
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
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return tsprintf(" accelerate_end , v:%s", mu_v.Name());
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
bool mu__boolexpr19;
bool mu__boolexpr20;
  if (!(mu_accelerate_clock_started[mu_v])) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = ((mu_accelerate_clock[mu_v]) <= ((mu_maxspeed[mu_v]) - (mu_speed[mu_v]))) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = (mu_all_event_true) ; 
}
    return mu__boolexpr19;
  }

  std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> preconds;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

bool mu__boolexpr21;
  if (!(mu_accelerate_clock_started[mu_v])) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_accelerate_clock[mu_v]) <= ((mu_maxspeed[mu_v]) - (mu_speed[mu_v]))) ; 
}
		preconds.push_back((mu_accelerate_clock[mu_v]) <= ((mu_maxspeed[mu_v]) - (mu_speed[mu_v])).name); 
		preconds.push_back((mu_maxspeed[mu_v]) - (mu_speed[mu_v]).name); 
		preconds.push_back(mu_accelerate_clock[mu_v].name); 
		preconds.push_back(mu_accelerate_clock_started[mu_v].name); 
		preconds.push_back(mu_all_event_true.name); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;

    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    effs.push_back(&(mu_accelerate_clock_started[mu_v]));  // mu_false 
    effs.push_back(&(mu_accelerate_clock[mu_v]));  // 0.000000e+00 
    effs.push_back(&(mu_speed[mu_v]));  // increase_speed_duraction_end_accelerate( mu_speed[mu_v], mu_accelerate_clock[mu_v] ) 

    return effs;
  }

  std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> aeffs;

    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    aeffs.push_back(mu_accelerate_clock[mu_v].name); //  0.000000e+00 
    aeffs.push_back(mu_speed[mu_v].name); //  increase_speed_duraction_end_accelerate( mu_speed[mu_v], mu_accelerate_clock[mu_v] ) 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 5;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 6 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr22;
bool mu__boolexpr23;
  if (!(mu_accelerate_clock_started[mu_v])) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_accelerate_clock[mu_v]) <= ((mu_maxspeed[mu_v]) - (mu_speed[mu_v]))) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = (mu_all_event_true) ; 
}
	      if (mu__boolexpr22) {
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
    mu_v.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
mu_accelerate_clock_started[mu_v] = mu_false;
mu_accelerate_clock[mu_v] = 0.000000e+00;
mu_speed[mu_v] = increase_speed_duraction_end_accelerate( mu_speed[mu_v], mu_accelerate_clock[mu_v] );
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {


    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    mu_accelerate_clock[mu_v] = 0.000000e+00; 
    mu_speed[mu_v] = increase_speed_duraction_end_accelerate( mu_speed[mu_v], mu_accelerate_clock[mu_v] ); 


  }

  int Duration(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return tsprintf(" accelerate(%s)", mu_v.Name());
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeEnd;
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
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return tsprintf(" accelerate_start , v:%s", mu_v.Name());
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
bool mu__boolexpr24;
  if (!(!(mu_accelerate_clock_started[mu_v]))) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = (mu_all_event_true) ; 
}
    return mu__boolexpr24;
  }

  std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> preconds;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

		preconds.push_back(!(mu_accelerate_clock_started[mu_v]).name); 
		preconds.push_back(mu_all_event_true.name); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;

    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    effs.push_back(&(mu_accelerate_clock_started[mu_v]));  // mu_true 

    return effs;
  }

  std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<std::string> aeffs;

    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    aeffs.push_back(mu_accelerate_clock_started[mu_v].name); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 6;
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 7 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr25;
  if (!(!(mu_accelerate_clock_started[mu_v]))) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = (mu_all_event_true) ; 
}
	      if (mu__boolexpr25) {
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
    mu_v.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
mu_accelerate_clock_started[mu_v] = mu_true;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {


    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;

    mu_accelerate_clock_started[mu_v] = mu_true; 


  }

  int Duration(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    static mu_1_vehicle mu_v;
    mu_v.value((r % 1) + 1);
    r = r / 1;
    return tsprintf(" accelerate(%s)", mu_v.Name());
  }
   RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
  {
    return RuleManager::DurativeStart;
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
  if (what_rule>=1 && what_rule<5)
    { R1.NextRule(what_rule);
      if (what_rule<5) return; }
  if (what_rule>=5 && what_rule<6)
    { R2.NextRule(what_rule);
      if (what_rule<6) return; }
  if (what_rule>=6 && what_rule<7)
    { R3.NextRule(what_rule);
      if (what_rule<7) return; }
}
bool Condition(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=4) return R1.Condition(r-1);
  if (r>=5 && r<=5) return R2.Condition(r-5);
  if (r>=6 && r<=6) return R3.Condition(r-6);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
std::vector<std::string> precond_array(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.precond_array(r-0);
  if (r>=1 && r<=4) return R1.precond_array(r-1);
  if (r>=5 && r<=5) return R2.precond_array(r-5);
  if (r>=6 && r<=6) return R3.precond_array(r-6);
Error.Notrace("Internal: NextStateGenerator -- checking preconditions for nonexisting rule.");
}
std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.effects_array(r-0);
  if (r>=1 && r<=4) return R1.effects_array(r-1);
  if (r>=5 && r<=5) return R2.effects_array(r-5);
  if (r>=6 && r<=6) return R3.effects_array(r-6);
Error.Notrace("Internal: NextStateGenerator -- checking effects for nonexisting rule.");
}
std::vector<std::string> effects_add_array(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.effects_add_array(r-0);
  if (r>=1 && r<=4) return R1.effects_add_array(r-1);
  if (r>=5 && r<=5) return R2.effects_add_array(r-5);
  if (r>=6 && r<=6) return R3.effects_add_array(r-6);
Error.Notrace("Internal: NextStateGenerator -- checking add effects for nonexisting rule.");
}
void Code(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=4) { R1.Code(r-1); return; } 
  if (r>=5 && r<=5) { R2.Code(r-5); return; } 
  if (r>=6 && r<=6) { R3.Code(r-6); return; } 
}
void Code_ff(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code_ff(r-0); return; } 
  if (r>=1 && r<=4) { R1.Code_ff(r-1); return; } 
  if (r>=5 && r<=5) { R2.Code_ff(r-5); return; } 
  if (r>=6 && r<=6) { R3.Code_ff(r-6); return; } 
}
int Priority(RULE_INDEX_TYPE r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=4) { return R1.Priority(); } 
  if (r>=5 && r<=5) { return R2.Priority(); } 
  if (r>=6 && r<=6) { return R3.Priority(); } 
}
char * Name(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=4) return R1.Name(r-1);
  if (r>=5 && r<=5) return R2.Name(r-5);
  if (r>=6 && r<=6) return R3.Name(r-6);
  return NULL;
}
int Duration(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Duration(r-0);
  if (r>=1 && r<=4) return R1.Duration(r-1);
  if (r>=5 && r<=5) return R2.Duration(r-5);
  if (r>=6 && r<=6) return R3.Duration(r-6);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
int Weight(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Weight(r-0);
  if (r>=1 && r<=4) return R1.Weight(r-1);
  if (r>=5 && r<=5) return R2.Weight(r-5);
  if (r>=6 && r<=6) return R3.Weight(r-6);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
char * PDDLName(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLName(r-0);
  if (r>=1 && r<=4) return R1.PDDLName(r-1);
  if (r>=5 && r<=5) return R2.PDDLName(r-5);
  if (r>=6 && r<=6) return R3.PDDLName(r-6);
  return NULL;
}
RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLClass(r-0);
  if (r>=1 && r<=4) return R1.PDDLClass(r-1);
  if (r>=5 && r<=5) return R2.PDDLClass(r-5);
  if (r>=6 && r<=6) return R3.PDDLClass(r-6);
Error.Notrace("Internal: NextStateGenerator -- querying PDDL class for nonexisting rule.");
}
};
const RULE_INDEX_TYPE numrules = 7;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 7


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
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
{
for(int mu_l = 2; mu_l <= 3; mu_l++) {
mu_set_at ( mu_v, mu_l, mu_false );
};
};
};
};
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
mu_maxspeed[mu_v] = 0.000000e+00;
};
};
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
mu_speed[mu_v] = 0.000000e+00;
};
};
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
mu_traveltime[mu_v] = 0.000000e+00;
};
};
{
for(int mu_p = 2; mu_p <= 3; mu_p++) {
{
for(int mu_l = 2; mu_l <= 3; mu_l++) {
mu_distance[mu_p][mu_l] = 0.000000e+00;
};
};
};
};
mu_h_n = 0;
mu_g_n = 0;
mu_f_n = 0;
mu_at[mu_car][mu_tstart] = mu_true;
mu_speed[mu_car] = 0.000000e+00;
mu_maxspeed[mu_car] = 1.000000e+01;
mu_traveltime[mu_car] = 0.000000e+00;
mu_distance[mu_tstart][mu_tend] = 1.000000e+02;
{
for(int mu_v = 1; mu_v <= 1; mu_v++) {
mu_accelerate_clock_started[mu_v] = mu_false;
mu_accelerate_clock[mu_v] = 0.000000e+00;
};
};
mu_all_event_true = mu_true;
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
int mu__goal_26() // Goal "enjoy"
{
bool mu__boolexpr27;
  if (!(mu_at[mu_car][mu_tend])) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_traveltime[mu_car]) >= (2.000000e+01)) ; 
}
return mu__boolexpr27;
};

bool mu__condition_28() // Condition for Rule "enjoy"
{
  return mu__goal_26( );
}

/**** end rule declaration ****/

const rulerec goals[] = {
{"enjoy", &mu__condition_28, NULL, },
};
const unsigned short numgoals = 1;

/********************
  Metric related stuff
 ********************/
const short metric = -1;

/********************
  Invariant records
 ********************/
int mu__invariant_29() // Invariant "todo bien"
{
return mu_all_event_true;
};

bool mu__condition_30() // Condition for Rule "todo bien"
{
  return mu__invariant_29( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"todo bien", &mu__condition_30, NULL, },
};
const unsigned short numinvariants = 1;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
accelerate_clock:NoScalarset
accelerate_clock_started:NoScalarset
traveltime:NoScalarset
speed:NoScalarset
maxspeed:NoScalarset
distance:NoScalarset
f_n:NoScalarset
h_n:NoScalarset
g_n:NoScalarset
all_event_true:NoScalarset
at:NoScalarset
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
        mu_accelerate_clock.MultisetSort();
        mu_accelerate_clock_started.MultisetSort();
        mu_traveltime.MultisetSort();
        mu_speed.MultisetSort();
        mu_maxspeed.MultisetSort();
        mu_distance.MultisetSort();
        mu_f_n.MultisetSort();
        mu_h_n.MultisetSort();
        mu_g_n.MultisetSort();
        mu_all_event_true.MultisetSort();
        mu_at.MultisetSort();
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
void mu_1_vehicle::Permute(PermSet& Perm, int i) {};
void mu_1_vehicle::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_vehicle::Canonicalize(PermSet& Perm) {};
void mu_1_vehicle::SimpleLimit(PermSet& Perm) {};
void mu_1_vehicle::ArrayLimit(PermSet& Perm) {};
void mu_1_vehicle::Limit(PermSet& Perm) {};
void mu_1_vehicle::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_location::Permute(PermSet& Perm, int i) {};
void mu_1_location::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_location::Canonicalize(PermSet& Perm) {};
void mu_1_location::SimpleLimit(PermSet& Perm) {};
void mu_1_location::ArrayLimit(PermSet& Perm) {};
void mu_1_location::Limit(PermSet& Perm) {};
void mu_1_location::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm){};
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm) {}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm) {}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm){};
void mu_1__type_2::SimpleLimit(PermSet& Perm){}
void mu_1__type_2::ArrayLimit(PermSet& Perm) {}
void mu_1__type_2::Limit(PermSet& Perm){}
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm) {}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm){};
void mu_1__type_4::SimpleLimit(PermSet& Perm){}
void mu_1__type_4::ArrayLimit(PermSet& Perm) {}
void mu_1__type_4::Limit(PermSet& Perm){}
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm) {}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_6::Canonicalize(PermSet& Perm){};
void mu_1__type_6::SimpleLimit(PermSet& Perm){}
void mu_1__type_6::ArrayLimit(PermSet& Perm) {}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  static mu_1__type_7 temp("Permute_mu_1__type_7",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_7::Canonicalize(PermSet& Perm){};
void mu_1__type_7::SimpleLimit(PermSet& Perm){}
void mu_1__type_7::ArrayLimit(PermSet& Perm) {}
void mu_1__type_7::Limit(PermSet& Perm){}
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  static mu_1__type_8 temp("Permute_mu_1__type_8",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_8::Canonicalize(PermSet& Perm){};
void mu_1__type_8::SimpleLimit(PermSet& Perm){}
void mu_1__type_8::ArrayLimit(PermSet& Perm) {}
void mu_1__type_8::Limit(PermSet& Perm){}
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_9::Permute(PermSet& Perm, int i)
{
  static mu_1__type_9 temp("Permute_mu_1__type_9",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_9::Canonicalize(PermSet& Perm){};
void mu_1__type_9::SimpleLimit(PermSet& Perm){}
void mu_1__type_9::ArrayLimit(PermSet& Perm) {}
void mu_1__type_9::Limit(PermSet& Perm){}
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i)
{
  static mu_1__type_10 temp("Permute_mu_1__type_10",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_10::Canonicalize(PermSet& Perm){};
void mu_1__type_10::SimpleLimit(PermSet& Perm){}
void mu_1__type_10::ArrayLimit(PermSet& Perm) {}
void mu_1__type_10::Limit(PermSet& Perm){}
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

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
              
              mu_accelerate_clock.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_accelerate_clock.MultisetSort();
              mu_accelerate_clock_started.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_accelerate_clock_started.MultisetSort();
              mu_traveltime.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_traveltime.MultisetSort();
              mu_speed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_speed.MultisetSort();
              mu_maxspeed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_maxspeed.MultisetSort();
              mu_distance.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_distance.MultisetSort();
              mu_f_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
              mu_h_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_g_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_all_event_true.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_all_event_true.MultisetSort();
              mu_at.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_at.MultisetSort();
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

          mu_accelerate_clock.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_accelerate_clock.MultisetSort();
          mu_accelerate_clock_started.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_accelerate_clock_started.MultisetSort();
          mu_traveltime.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_traveltime.MultisetSort();
          mu_speed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_speed.MultisetSort();
          mu_maxspeed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_maxspeed.MultisetSort();
          mu_distance.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_distance.MultisetSort();
          mu_f_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_f_n.MultisetSort();
          mu_h_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_h_n.MultisetSort();
          mu_g_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_g_n.MultisetSort();
          mu_all_event_true.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_all_event_true.MultisetSort();
          mu_at.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_at.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_accelerate_clock.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_accelerate_clock.MultisetSort();
              mu_accelerate_clock_started.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_accelerate_clock_started.MultisetSort();
              mu_traveltime.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_traveltime.MultisetSort();
              mu_speed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_speed.MultisetSort();
              mu_maxspeed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_maxspeed.MultisetSort();
              mu_distance.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_distance.MultisetSort();
              mu_f_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
              mu_h_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_g_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_all_event_true.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_all_event_true.MultisetSort();
              mu_at.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_at.MultisetSort();
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
      mu_accelerate_clock.MultisetSort();
      mu_accelerate_clock_started.MultisetSort();
      mu_traveltime.MultisetSort();
      mu_speed.MultisetSort();
      mu_maxspeed.MultisetSort();
      mu_distance.MultisetSort();
      mu_f_n.MultisetSort();
      mu_h_n.MultisetSort();
      mu_g_n.MultisetSort();
      mu_all_event_true.MultisetSort();
      mu_at.MultisetSort();
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
        mu_accelerate_clock.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_accelerate_clock.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_accelerate_clock_started.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_accelerate_clock_started.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_traveltime.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_traveltime.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_speed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_speed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_maxspeed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_maxspeed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_distance.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_distance.MultisetSort();
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
        mu_at.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_at.MultisetSort();
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
