/*
* Universal Planner CGMurphi Release 2.0.b1
* Copyright (C) 2007 - 2010: G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio
*
* Read the file "license" distributed with these sources, or call
* UPMurphi with the -l switch for additional information.
* Current release developed by G. Della Penna (giuseppe.dellapenna@univaq.it)
*
*/

/*---------------------------------------------------------------------------*/
/* Nested includes                                                           */
/*---------------------------------------------------------------------------*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include "cudd.h"
#include "cuddInt.h"
#include "util.h"
#include "dddmp.h"

/*---------------------------------------------------------------------------*/
/* Constant declarations                                                     */
/*---------------------------------------------------------------------------*/

#define NUM_BYTES_RULE sizeof(RULE_INDEX_TYPE)

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/

/**Enum************************************************************************

  Descrizione [Criteri di ordinamento]

******************************************************************************/
typedef enum {
    STATE_RULE, // la prima componente è lo stato
    RULE_STATE, // la prima componente è la regola
    TRANSITION // modalità interleaving
} Ordering_Type;


/**Enum************************************************************************

  Descrizione [Ordini di elaborazione della singola componente]

******************************************************************************/
typedef enum {
    MODE_SAME,
    MODE_REVERSED,
    MODE_INTERLEAVED
} Ordering_Mode;


/**Enum************************************************************************

  Descrizione [Struttura contenente l'indicazione degli estremi da elaborare 
  nello stato e nella regola]

******************************************************************************/
typedef struct {
    int first_from; // primo indice della prima componente
    int first_to; // ultimo indice della prima componente
    int last_from; // primo indice della seconda componente
    int last_to; // ultimo indice della seconda componente
} Order;


/**Enum************************************************************************

  Descrizione []

******************************************************************************/
typedef struct node* ptree;

typedef struct node {
    ptree then_child;
    ptree else_child;
} node;


/*---------------------------------------------------------------------------*/
/* Global variables                                                          */
/*---------------------------------------------------------------------------*/
/* numero di transizioni */
extern unsigned long NUM_TRANSITIONS;
/* numero di bytes per ogni stato */
extern unsigned int NUM_BYTES_STATE;
/* lunghezza della transizione espressa in bit */
extern unsigned int NUM_BITS_TRANSITION;
/* lista dei nodi */
extern node* nodes;
/* permutazione dell'indice delle variabili */
extern short* permids;
/* tipologia di puntatore Else*/
extern BIT_BLOCK* else_type;

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

inline void swap(int*, int*);
inline void increment(int*);
inline void decrement(int*);
inline void interleaving(int*);

int getBit(char*, int);
void setBit(BIT_BLOCK*, int);
void resetBit(BIT_BLOCK*, int);

void WriteOBDD(FILE*, Ordering_Type, Ordering_Mode, Ordering_Mode, 
               Cudd_ReorderingType, int, int, FILE*, int, FILE*, int);
