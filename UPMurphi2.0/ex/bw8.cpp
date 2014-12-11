/******************************
  Program "bw8.m" compiled by "Universal Planner Murphi Release 2.0.R8"

  Murphi Last Compiled date: "Dec  8 2014"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Universal Planner Murphi Release 2.0.R8"
#define MURPHI_DATE "Dec  8 2014"
#define PROTOCOL_NAME "bw8"
#define BITS_IN_WORLD 235
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
  mu_1_real_type (const char *name, int os): mu__real(3,3,24,name, os) {};
  mu_1_real_type (void): mu__real(3,3,24) {};
  mu_1_real_type (double val): mu__real(3,3,24,"Parameter or function result.", 0)
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

class mu_1_block: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_block& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_block& val)
  {
    if (val.defined())
      return ( s << mu_1_block::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_block (const char *name, int os): mu__byte(1, 8, 4, name, os) {};
  mu_1_block (void): mu__byte(1, 8, 4) {};
  mu_1_block (int val): mu__byte(1, 8, 4, "Parameter or function result.", 0)
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

const char *mu_1_block::values[] = {"b1","b2","b3","b4","b5","b6","b7","b8",NULL };

/*** end of enum declaration ***/
mu_1_block mu_1_block_undefined_var;

class mu_1__type_0:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 8 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_0 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_0 (const char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 8 ) )
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
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 8; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<8; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<8; i++) {
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
    for (int i=0; i<8; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<8; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 8; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 8; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 8; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
      array[i].to_state(thestate);
  };

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
		for (int ix = 0; ix < 8; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 8; ix++){
			for (int ix2 = 0; ix2 < 8; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
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

if (n) array[i].set_self_ar(n,"b1", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b2", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b3", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b4", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b5", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b6", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b7", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b8", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1:public mu_1__type_super
{
 public:
  mu_1__type_0 array[ 8 ]; 
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
    if ( ( index >= 1 ) && ( index <= 8 ) )
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
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 8; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<8; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<8; i++) {
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
    for (int i=0; i<8; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<8; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 8; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 8; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 8; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
      array[i].to_state(thestate);
  };

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
		for (int ix = 0; ix < 8; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 8; ix++){
			for (int ix2 = 0; ix2 < 8; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
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

if (n) array[i].set_self_ar(n,"b1", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b2", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b3", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b4", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b5", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b6", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b7", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b8", i * 16 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 8 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_2 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os) { set_self(n, os); };
  mu_1__type_2 ( void ) {};
  virtual ~mu_1__type_2 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 8 ) )
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
    for (int i = 0; i < 8; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<8; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<8; i++) {
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
    for (int i=0; i<8; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<8; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 8; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 8; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 8; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
      array[i].to_state(thestate);
  };

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
		for (int ix = 0; ix < 8; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 8; ix++){
			for (int ix2 = 0; ix2 < 8; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
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

if (n) array[i].set_self_ar(n,"b1", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b2", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b3", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b4", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b5", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b6", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b7", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b8", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_2::~mu_1__type_2()
{
}
/*** end array declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 8 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_3 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_3 (const char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 8 ) )
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
    for (int i = 0; i < 8; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<8; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<8; i++) {
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
    for (int i=0; i<8; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<8; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 8; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 8; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 8; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
      array[i].to_state(thestate);
  };

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
		for (int ix = 0; ix < 8; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 8; ix++){
			for (int ix2 = 0; ix2 < 8; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
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

if (n) array[i].set_self_ar(n,"b1", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b2", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b3", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b4", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b5", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b6", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b7", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b8", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4:public mu_1__type_super
{
 public:
  mu_0_boolean array[ 8 ]; 
#define awesome_mu_00_mu_0_boolean_mu_1__type_4 1 
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_4 (const char *n, int os) { set_self(n, os); };
  mu_1__type_4 ( void ) {};
  virtual ~mu_1__type_4 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 8 ) )
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
    for (int i = 0; i < 8; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<8; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<8; i++) {
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
    for (int i=0; i<8; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<8; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 8; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 8; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 8; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 8; i++)
      array[i].to_state(thestate);
  };

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
		for (int ix = 0; ix < 8; ix++){ barr.push_back(&(array[ix])); }
		return barr;
	#else 
		for (int ix = 0; ix < 8; ix++){
			for (int ix2 = 0; ix2 < 8; ix2++){ barr.push_back(&(array[ix][ix2+1])); }
		}
		return barr;
	   

	#endif 
}
  void print(FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
      array[i].print(target,separator); };

  void print_diff(state *prevstate, FILE *target, const char *separator)
  {
    for (int i = 0; i < 8; i++)
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

if (n) array[i].set_self_ar(n,"b1", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b2", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b3", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b4", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b5", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b6", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b7", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"b8", i * 2 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

const int mu_b1 = 1;
const int mu_b2 = 2;
const int mu_b3 = 3;
const int mu_b4 = 4;
const int mu_b5 = 5;
const int mu_b6 = 6;
const int mu_b7 = 7;
const int mu_b8 = 8;
const int mu_T = 1;
/*** Variable declaration ***/
mu_1_real_type mu_fun("fun",0);

/*** Variable declaration ***/
mu_1_integer mu_h_n("h_n",24);

/*** Variable declaration ***/
mu_1_integer mu_g_n("g_n",35);

/*** Variable declaration ***/
mu_1_integer mu_f_n("f_n",46);

/*** Variable declaration ***/
mu_1__type_1 mu_on("on",57);

/*** Variable declaration ***/
mu_1__type_2 mu_ontable("ontable",185);

/*** Variable declaration ***/
mu_1__type_3 mu_isclear("isclear",201);

/*** Variable declaration ***/
mu_0_boolean mu_handempty("handempty",217);

/*** Variable declaration ***/
mu_1__type_4 mu_holding("holding",219);

void mu_set_on(const mu_1_block& mu_x, const mu_1_block& mu_y, const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_on[mu_x][mu_y].undefine();
else
  mu_on[mu_x][mu_y] = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_on(const mu_1_block& mu_x,const mu_1_block& mu_y)
{
return mu_on[mu_x][mu_y];
	Error.Error("The end of function get_on reached without returning values.");
};
/*** end function declaration ***/

void mu_set_ontable(const mu_1_block& mu_x, const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_ontable[mu_x].undefine();
else
  mu_ontable[mu_x] = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_ontable(const mu_1_block& mu_x)
{
return mu_ontable[mu_x];
	Error.Error("The end of function get_ontable reached without returning values.");
};
/*** end function declaration ***/

void mu_set_isclear(const mu_1_block& mu_x, const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_isclear[mu_x].undefine();
else
  mu_isclear[mu_x] = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_isclear(const mu_1_block& mu_x)
{
return mu_isclear[mu_x];
	Error.Error("The end of function get_isclear reached without returning values.");
};
/*** end function declaration ***/

void mu_set_handempty(const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_handempty.undefine();
else
  mu_handempty = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_handempty()
{
return mu_handempty;
	Error.Error("The end of function get_handempty reached without returning values.");
};
/*** end function declaration ***/

void mu_set_holding(const mu_1_block& mu_x, const mu_0_boolean& mu_value)
{
if (mu_value.isundefined())
  mu_holding[mu_x].undefine();
else
  mu_holding[mu_x] = mu_value;
};
/*** end procedure declaration ***/

mu_0_boolean mu_get_holding(const mu_1_block& mu_x)
{
return mu_holding[mu_x];
	Error.Error("The end of function get_holding reached without returning values.");
};
/*** end function declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_fun.clear();
  mu_h_n.clear();
  mu_g_n.clear();
  mu_f_n.clear();
  mu_on.clear();
  mu_ontable.clear();
  mu_isclear.clear();
  mu_handempty.clear();
  mu_holding.clear();
}
void world_class::undefine()
{
  mu_fun.undefine();
  mu_h_n.undefine();
  mu_g_n.undefine();
  mu_f_n.undefine();
  mu_on.undefine();
  mu_ontable.undefine();
  mu_isclear.undefine();
  mu_handempty.undefine();
  mu_holding.undefine();
}
void world_class::reset()
{
  mu_fun.reset();
  mu_h_n.reset();
  mu_g_n.reset();
  mu_f_n.reset();
  mu_on.reset();
  mu_ontable.reset();
  mu_isclear.reset();
  mu_handempty.reset();
  mu_holding.reset();
}
std::vector<mu_0_boolean*> world_class::get_mu_bools()
{
	  std::vector<mu_0_boolean*> awesome;

      awesome.push_back(&(mu_handempty));
    return awesome; 
}
std::vector<mu_0_boolean*> world_class::get_mu_bool_arrays()
{
	  std::vector<mu_0_boolean*> var_arrays;
   std::vector<mu_0_boolean*> interm;

      interm = mu_on.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_ontable.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_isclear.bool_array();
		var_arrays.insert(var_arrays.end(), interm.begin(), interm.end());
      interm = mu_holding.bool_array();
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
  //   double h_val = upm_rpg().compute_rpg();
  upm_rpg::getInstance().clear_all();
  double h_val = upm_rpg::getInstance().compute_rpg();
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
  mu_fun.print(target, separator);
  mu_h_n.print(target, separator);
  mu_g_n.print(target, separator);
  mu_f_n.print(target, separator);
  mu_on.print(target, separator);
  mu_ontable.print(target, separator);
  mu_isclear.print(target, separator);
  mu_handempty.print(target, separator);
  mu_holding.print(target, separator);
    num_calls--;
}
}
void world_class::pddlprint(FILE *target, const char *separator)
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_fun.print(target, separator);
  mu_on.print(target, separator);
  mu_ontable.print(target, separator);
  mu_isclear.print(target, separator);
  mu_handempty.print(target, separator);
  mu_holding.print(target, separator);
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_fun.print_statistic();
  mu_h_n.print_statistic();
  mu_g_n.print_statistic();
  mu_f_n.print_statistic();
  mu_on.print_statistic();
  mu_ontable.print_statistic();
  mu_isclear.print_statistic();
  mu_handempty.print_statistic();
  mu_holding.print_statistic();
    num_calls--;
}
}
void world_class::print_diff(state *prevstate, FILE *target, const char *separator)
{
  if ( prevstate != NULL )
  {
    mu_fun.print_diff(prevstate,target,separator);
    mu_h_n.print_diff(prevstate,target,separator);
    mu_g_n.print_diff(prevstate,target,separator);
    mu_f_n.print_diff(prevstate,target,separator);
    mu_on.print_diff(prevstate,target,separator);
    mu_ontable.print_diff(prevstate,target,separator);
    mu_isclear.print_diff(prevstate,target,separator);
    mu_handempty.print_diff(prevstate,target,separator);
    mu_holding.print_diff(prevstate,target,separator);
  }
  else
print(target,separator);
}
void world_class::to_state(state *newstate)
{
  mu_fun.to_state( newstate );
  mu_h_n.to_state( newstate );
  mu_g_n.to_state( newstate );
  mu_f_n.to_state( newstate );
  mu_on.to_state( newstate );
  mu_ontable.to_state( newstate );
  mu_isclear.to_state( newstate );
  mu_handempty.to_state( newstate );
  mu_holding.to_state( newstate );
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

  std::vector<mu_0_boolean*> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> preconds;



    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;



    return effs;
  }

  std::vector<mu_0_boolean*> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> aeffs;



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
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" unstack , y:%s, x:%s", mu_y.Name(), mu_x.Name());
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
bool mu__boolexpr5;
bool mu__boolexpr6;
  if (!(mu_on[mu_x][mu_y])) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = (mu_isclear[mu_x]) ; 
}
  if (!(mu__boolexpr6)) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = (mu_handempty) ; 
}
    return mu__boolexpr5;
  }

  std::vector<mu_0_boolean*> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> preconds;
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;


		preconds.push_back(&(mu_handempty)); 
		preconds.push_back(&(mu_isclear[mu_x])); 
		preconds.push_back(&(mu_on[mu_x][mu_y])); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;

    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    effs.push_back(&(mu_holding[mu_x]));  // mu_true 
    effs.push_back(&(mu_isclear[mu_y]));  // mu_true 
    effs.push_back(&(mu_isclear[mu_x]));  // mu_false 
    effs.push_back(&(mu_handempty));  // mu_false 
    effs.push_back(&(mu_on[mu_x][mu_y]));  // mu_false 

    return effs;
  }

  std::vector<mu_0_boolean*> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> aeffs;

    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    aeffs.push_back(&(mu_holding[mu_x])); //  mu_true 
    aeffs.push_back(&(mu_isclear[mu_y])); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 1;
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    while (what_rule < 65 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr7;
bool mu__boolexpr8;
  if (!(mu_on[mu_x][mu_y])) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = (mu_isclear[mu_x]) ; 
}
  if (!(mu__boolexpr8)) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = (mu_handempty) ; 
}
	      if (mu__boolexpr7) {
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
    mu_y.value((r % 8) + 1);
    r = r / 8;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
mu_holding[mu_x] = mu_true;
mu_isclear[mu_y] = mu_true;
mu_isclear[mu_x] = mu_false;
mu_handempty = mu_false;
mu_on[mu_x][mu_y] = mu_false;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {


    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    mu_holding[mu_x] = mu_true; 
    mu_isclear[mu_y] = mu_true; 


  }

  int Duration(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" unstack(%s,%s)", mu_y.Name(), mu_x.Name());
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
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" stack , y:%s, x:%s", mu_y.Name(), mu_x.Name());
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
bool mu__boolexpr9;
  if (!(mu_holding[mu_x])) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = (mu_isclear[mu_y]) ; 
}
    return mu__boolexpr9;
  }

  std::vector<mu_0_boolean*> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> preconds;
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;


		preconds.push_back(&(mu_holding[mu_x])); 
		preconds.push_back(&(mu_isclear[mu_y])); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;

    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    effs.push_back(&(mu_isclear[mu_x]));  // mu_true 
    effs.push_back(&(mu_handempty));  // mu_true 
    effs.push_back(&(mu_on[mu_x][mu_y]));  // mu_true 
    effs.push_back(&(mu_holding[mu_x]));  // mu_false 
    effs.push_back(&(mu_isclear[mu_y]));  // mu_false 

    return effs;
  }

  std::vector<mu_0_boolean*> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> aeffs;

    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    aeffs.push_back(&(mu_isclear[mu_x])); //  mu_true 
    aeffs.push_back(&(mu_handempty)); //  mu_true 
    aeffs.push_back(&(mu_on[mu_x][mu_y])); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 65;
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    while (what_rule < 129 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr10;
  if (!(mu_holding[mu_x])) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = (mu_isclear[mu_y]) ; 
}
	      if (mu__boolexpr10) {
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
    r = what_rule - 65;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
mu_isclear[mu_x] = mu_true;
mu_handempty = mu_true;
mu_on[mu_x][mu_y] = mu_true;
mu_holding[mu_x] = mu_false;
mu_isclear[mu_y] = mu_false;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {


    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    mu_isclear[mu_x] = mu_true; 
    mu_handempty = mu_true; 
    mu_on[mu_x][mu_y] = mu_true; 


  }

  int Duration(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_y;
    mu_y.value((r % 8) + 1);
    r = r / 8;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" stack(%s,%s)", mu_y.Name(), mu_x.Name());
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
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" put-down , x:%s", mu_x.Name());
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return mu_holding[mu_x];
  }

  std::vector<mu_0_boolean*> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> preconds;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;


		preconds.push_back(&(mu_holding[mu_x])); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;

    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    effs.push_back(&(mu_isclear[mu_x]));  // mu_true 
    effs.push_back(&(mu_handempty));  // mu_true 
    effs.push_back(&(mu_ontable[mu_x]));  // mu_true 
    effs.push_back(&(mu_holding[mu_x]));  // mu_false 

    return effs;
  }

  std::vector<mu_0_boolean*> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> aeffs;

    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    aeffs.push_back(&(mu_isclear[mu_x])); //  mu_true 
    aeffs.push_back(&(mu_handempty)); //  mu_true 
    aeffs.push_back(&(mu_ontable[mu_x])); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 129;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    while (what_rule < 137 )
      {
	if ( ( TRUE  ) ) {
	      if (mu_holding[mu_x]) {
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
    r = what_rule - 129;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
mu_isclear[mu_x] = mu_true;
mu_handempty = mu_true;
mu_ontable[mu_x] = mu_true;
mu_holding[mu_x] = mu_false;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {


    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    mu_isclear[mu_x] = mu_true; 
    mu_handempty = mu_true; 
    mu_ontable[mu_x] = mu_true; 


  }

  int Duration(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" put-down(%s)", mu_x.Name());
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
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" pick-up , x:%s", mu_x.Name());
  }
  bool Condition(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
bool mu__boolexpr11;
bool mu__boolexpr12;
  if (!(mu_isclear[mu_x])) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = (mu_ontable[mu_x]) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = (mu_handempty) ; 
}
    return mu__boolexpr11;
  }

  std::vector<mu_0_boolean*> precond_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> preconds;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;


		preconds.push_back(&(mu_handempty)); 
		preconds.push_back(&(mu_isclear[mu_x])); 
		preconds.push_back(&(mu_ontable[mu_x])); 

    return preconds;
  }

  std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> effs;

    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    effs.push_back(&(mu_holding[mu_x]));  // mu_true 
    effs.push_back(&(mu_ontable[mu_x]));  // mu_false 
    effs.push_back(&(mu_isclear[mu_x]));  // mu_false 
    effs.push_back(&(mu_handempty));  // mu_false 

    return effs;
  }

  std::vector<mu_0_boolean*> effects_add_array(RULE_INDEX_TYPE r)
  {
    std::vector<mu_0_boolean*> aeffs;

    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    aeffs.push_back(&(mu_holding[mu_x])); //  mu_true 

    return aeffs;
  }

  void NextRule(RULE_INDEX_TYPE & what_rule)
  {
    RULE_INDEX_TYPE r = what_rule - 137;
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    while (what_rule < 145 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr13;
bool mu__boolexpr14;
  if (!(mu_isclear[mu_x])) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = (mu_ontable[mu_x]) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = (mu_handempty) ; 
}
	      if (mu__boolexpr13) {
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
    r = what_rule - 137;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    }
  }

  void Code(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
mu_holding[mu_x] = mu_true;
mu_ontable[mu_x] = mu_false;
mu_isclear[mu_x] = mu_false;
mu_handempty = mu_false;
  };

  void Code_ff(RULE_INDEX_TYPE r)
  {


    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;

    mu_holding[mu_x] = mu_true; 


  }

  int Duration(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  int Weight(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return 0;
  }

  char * PDDLName(RULE_INDEX_TYPE r)
  {
    static mu_1_block mu_x;
    mu_x.value((r % 8) + 1);
    r = r / 8;
    return tsprintf(" pick-up(%s)", mu_x.Name());
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
  if (what_rule>=1 && what_rule<65)
    { R1.NextRule(what_rule);
      if (what_rule<65) return; }
  if (what_rule>=65 && what_rule<129)
    { R2.NextRule(what_rule);
      if (what_rule<129) return; }
  if (what_rule>=129 && what_rule<137)
    { R3.NextRule(what_rule);
      if (what_rule<137) return; }
  if (what_rule>=137 && what_rule<145)
    { R4.NextRule(what_rule);
      if (what_rule<145) return; }
}
bool Condition(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=64) return R1.Condition(r-1);
  if (r>=65 && r<=128) return R2.Condition(r-65);
  if (r>=129 && r<=136) return R3.Condition(r-129);
  if (r>=137 && r<=144) return R4.Condition(r-137);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
std::vector<mu_0_boolean*> precond_array(RULE_INDEX_TYPE r)
{
  category = CONDITION;
  if (r<=0) return R0.precond_array(r-0);
  if (r>=1 && r<=64) return R1.precond_array(r-1);
  if (r>=65 && r<=128) return R2.precond_array(r-65);
  if (r>=129 && r<=136) return R3.precond_array(r-129);
  if (r>=137 && r<=144) return R4.precond_array(r-137);
Error.Notrace("Internal: NextStateGenerator -- checking preconditions for nonexisting rule.");
}
std::vector<mu_0_boolean*> effects_array(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.effects_array(r-0);
  if (r>=1 && r<=64) return R1.effects_array(r-1);
  if (r>=65 && r<=128) return R2.effects_array(r-65);
  if (r>=129 && r<=136) return R3.effects_array(r-129);
  if (r>=137 && r<=144) return R4.effects_array(r-137);
Error.Notrace("Internal: NextStateGenerator -- checking effects for nonexisting rule.");
}
std::vector<mu_0_boolean*> effects_add_array(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.effects_add_array(r-0);
  if (r>=1 && r<=64) return R1.effects_add_array(r-1);
  if (r>=65 && r<=128) return R2.effects_add_array(r-65);
  if (r>=129 && r<=136) return R3.effects_add_array(r-129);
  if (r>=137 && r<=144) return R4.effects_add_array(r-137);
Error.Notrace("Internal: NextStateGenerator -- checking add effects for nonexisting rule.");
}
void Code(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=64) { R1.Code(r-1); return; } 
  if (r>=65 && r<=128) { R2.Code(r-65); return; } 
  if (r>=129 && r<=136) { R3.Code(r-129); return; } 
  if (r>=137 && r<=144) { R4.Code(r-137); return; } 
}
void Code_ff(RULE_INDEX_TYPE r)
{
  if (r<=0) { R0.Code_ff(r-0); return; } 
  if (r>=1 && r<=64) { R1.Code_ff(r-1); return; } 
  if (r>=65 && r<=128) { R2.Code_ff(r-65); return; } 
  if (r>=129 && r<=136) { R3.Code_ff(r-129); return; } 
  if (r>=137 && r<=144) { R4.Code_ff(r-137); return; } 
}
int Priority(RULE_INDEX_TYPE r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=64) { return R1.Priority(); } 
  if (r>=65 && r<=128) { return R2.Priority(); } 
  if (r>=129 && r<=136) { return R3.Priority(); } 
  if (r>=137 && r<=144) { return R4.Priority(); } 
}
char * Name(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=64) return R1.Name(r-1);
  if (r>=65 && r<=128) return R2.Name(r-65);
  if (r>=129 && r<=136) return R3.Name(r-129);
  if (r>=137 && r<=144) return R4.Name(r-137);
  return NULL;
}
int Duration(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Duration(r-0);
  if (r>=1 && r<=64) return R1.Duration(r-1);
  if (r>=65 && r<=128) return R2.Duration(r-65);
  if (r>=129 && r<=136) return R3.Duration(r-129);
  if (r>=137 && r<=144) return R4.Duration(r-137);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
int Weight(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.Weight(r-0);
  if (r>=1 && r<=64) return R1.Weight(r-1);
  if (r>=65 && r<=128) return R2.Weight(r-65);
  if (r>=129 && r<=136) return R3.Weight(r-129);
  if (r>=137 && r<=144) return R4.Weight(r-137);
Error.Notrace("Internal: NextStateGenerator -- querying duration for nonexisting rule.");
}
char * PDDLName(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLName(r-0);
  if (r>=1 && r<=64) return R1.PDDLName(r-1);
  if (r>=65 && r<=128) return R2.PDDLName(r-65);
  if (r>=129 && r<=136) return R3.PDDLName(r-129);
  if (r>=137 && r<=144) return R4.PDDLName(r-137);
  return NULL;
}
RuleManager::rule_pddlclass PDDLClass(RULE_INDEX_TYPE r)
{
  if (r<=0) return R0.PDDLClass(r-0);
  if (r>=1 && r<=64) return R1.PDDLClass(r-1);
  if (r>=65 && r<=128) return R2.PDDLClass(r-65);
  if (r>=129 && r<=136) return R3.PDDLClass(r-129);
  if (r>=137 && r<=144) return R4.PDDLClass(r-137);
Error.Notrace("Internal: NextStateGenerator -- querying PDDL class for nonexisting rule.");
}
};
const RULE_INDEX_TYPE numrules = 145;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 145


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
for(int mu_x = 1; mu_x <= 8; mu_x++) {
{
for(int mu_y = 1; mu_y <= 8; mu_y++) {
mu_set_on ( mu_x, mu_y, mu_false );
};
};
};
};
{
for(int mu_x = 1; mu_x <= 8; mu_x++) {
mu_set_ontable ( mu_x, mu_false );
};
};
{
for(int mu_x = 1; mu_x <= 8; mu_x++) {
mu_set_isclear ( mu_x, mu_false );
};
};
mu_set_handempty ( mu_false );
{
for(int mu_x = 1; mu_x <= 8; mu_x++) {
mu_set_holding ( mu_x, mu_false );
};
};
mu_fun = 0.000000e+00;
mu_isclear[mu_b1] = mu_true;
mu_isclear[mu_b7] = mu_true;
mu_ontable[mu_b4] = mu_true;
mu_ontable[mu_b8] = mu_true;
mu_on[mu_b1][mu_b6] = mu_true;
mu_on[mu_b2][mu_b5] = mu_true;
mu_on[mu_b3][mu_b2] = mu_true;
mu_on[mu_b5][mu_b4] = mu_true;
mu_on[mu_b6][mu_b3] = mu_true;
mu_on[mu_b7][mu_b8] = mu_true;
mu_handempty = mu_true;
mu_h_n = 0;
mu_g_n = 0;
mu_f_n = (mu_h_n) + (mu_g_n);
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

// WPGOAL
int mu__goal_15() // Goal "enjoy"
{
bool mu__boolexpr16;
bool mu__boolexpr17;
bool mu__boolexpr18;
bool mu__boolexpr19;
bool mu__boolexpr20;
  if (!(mu_on[mu_b1][mu_b6])) mu__boolexpr20 = FALSE ;
  else {
  mu__boolexpr20 = (mu_on[mu_b3][mu_b1]) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = (mu_on[mu_b4][mu_b3]) ; 
}
  if (!(mu__boolexpr19)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = (mu_on[mu_b5][mu_b8]) ; 
}
  if (!(mu__boolexpr18)) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = (mu_on[mu_b6][mu_b7]) ; 
}
  if (!(mu__boolexpr17)) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = (mu_on[mu_b7][mu_b5]) ; 
}
return mu__boolexpr16;
};

  std::set<mu_0_boolean*> get_goal_conditions()
  {
    std::set<mu_0_boolean*> goal_conds;

		goal_conds.insert(&(mu_on[mu_b1][mu_b6])); 
		goal_conds.insert(&(mu_on[mu_b3][mu_b1])); 
		goal_conds.insert(&(mu_on[mu_b4][mu_b3])); 
		goal_conds.insert(&(mu_on[mu_b5][mu_b8])); 
		goal_conds.insert(&(mu_on[mu_b6][mu_b7])); 
		goal_conds.insert(&(mu_on[mu_b7][mu_b5])); 

    return goal_conds;
  }

bool mu__condition_21() // Condition for Rule "enjoy"
{
  return mu__goal_15( );
}

bool mu__goal__00(){ return mu__condition_21(); } /* WP WP WP GOAL CONDITION CHECK */ /**** end rule declaration ****/


// WPGOAL
const rulerec goals[] = {
{"enjoy", &mu__condition_21, NULL, },
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
isclear:NoScalarset
ontable:NoScalarset
on:NoScalarset
g_n:NoScalarset
fun:NoScalarset
h_n:NoScalarset
f_n:NoScalarset
handempty:NoScalarset
holding:NoScalarset
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
        mu_isclear.MultisetSort();
        mu_ontable.MultisetSort();
        mu_on.MultisetSort();
        mu_g_n.MultisetSort();
        mu_fun.MultisetSort();
        mu_h_n.MultisetSort();
        mu_f_n.MultisetSort();
        mu_handempty.MultisetSort();
        mu_holding.MultisetSort();
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
void mu_1_block::Permute(PermSet& Perm, int i) {};
void mu_1_block::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_block::Canonicalize(PermSet& Perm) {};
void mu_1_block::SimpleLimit(PermSet& Perm) {};
void mu_1_block::ArrayLimit(PermSet& Perm) {};
void mu_1_block::Limit(PermSet& Perm) {};
void mu_1_block::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<8; j++)
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
  for (j=0; j<8; j++)
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
  for (j=0; j<8; j++)
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
  for (j=0; j<8; j++)
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
  for (j=0; j<8; j++)
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
              
              mu_isclear.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_isclear.MultisetSort();
              mu_ontable.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ontable.MultisetSort();
              mu_on.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_on.MultisetSort();
              mu_g_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_fun.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_fun.MultisetSort();
              mu_h_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_f_n.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
              mu_handempty.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_handempty.MultisetSort();
              mu_holding.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_holding.MultisetSort();
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

          mu_isclear.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_isclear.MultisetSort();
          mu_ontable.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ontable.MultisetSort();
          mu_on.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_on.MultisetSort();
          mu_g_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_g_n.MultisetSort();
          mu_fun.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_fun.MultisetSort();
          mu_h_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_h_n.MultisetSort();
          mu_f_n.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_f_n.MultisetSort();
          mu_handempty.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_handempty.MultisetSort();
          mu_holding.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_holding.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_isclear.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_isclear.MultisetSort();
              mu_ontable.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ontable.MultisetSort();
              mu_on.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_on.MultisetSort();
              mu_g_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_g_n.MultisetSort();
              mu_fun.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_fun.MultisetSort();
              mu_h_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_h_n.MultisetSort();
              mu_f_n.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_f_n.MultisetSort();
              mu_handempty.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_handempty.MultisetSort();
              mu_holding.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_holding.MultisetSort();
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
      mu_isclear.MultisetSort();
      mu_ontable.MultisetSort();
      mu_on.MultisetSort();
      mu_g_n.MultisetSort();
      mu_fun.MultisetSort();
      mu_h_n.MultisetSort();
      mu_f_n.MultisetSort();
      mu_handempty.MultisetSort();
      mu_holding.MultisetSort();
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
        mu_isclear.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_isclear.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ontable.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ontable.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_on.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_on.MultisetSort();
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
        mu_fun.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_fun.MultisetSort();
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
        mu_handempty.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_handempty.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_holding.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_holding.MultisetSort();
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
