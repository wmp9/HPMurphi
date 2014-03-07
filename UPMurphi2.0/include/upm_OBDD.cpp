/*
* Universal Planner CGMurphi Release 2.0.b1
* Copyright (C) 2007 - 2010: G. Della Penna, B. Intrigila, D. Magazzeni, F. Mercorio
*
* Read the file "license" distributed with these sources, or call
* UPMurphi with the -l switch for additional information.
* Current release developed by G. Della Penna (giuseppe.dellapenna@univaq.it)
*
*/

#include <math.h>

using namespace std;

unsigned int NUM_BYTES_STATE;
unsigned long NUM_TRANSITIONS;
unsigned int NUM_BITS_TRANSITION;

node* nodes;
short* permids;
BIT_BLOCK* else_type;

inline void swap(int* px, int* py) { 
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

inline void increment(int* index) {(*index)++;}
inline void decrement(int* index) {(*index)--;}
inline void interleaving(int* index){
    if ((*index) < NUM_BYTES_STATE * 8) {
        (*index) = (*index) + NUM_BYTES_RULE * 8;
    } else {
        (*index) = (*index) - NUM_BYTES_RULE * 8 - 1;
    }
}


/**Function********************************************************************

  Descrizione [Restituisce il valore del bit che occupa la posizione index in
  transition]

******************************************************************************/
int
getBit(
    unsigned char* transition,
    int index)
{
    return ((transition[index/8] & (1 << (index%8))) != 0);
}


/**Function********************************************************************

  Descrizione [Pone a 1 il bit che occupa la posizione index in bitset]

******************************************************************************/
void setBit(
    BIT_BLOCK* bitset,
    int index) 
{     
     bitset[index/8] = (bitset[index/8]) | (1 << (index%8));
}


/**Function********************************************************************

  Descrizione [Pone a 0 il bit che occupa la posizione index in bitset]

******************************************************************************/
void resetBit(
    BIT_BLOCK* bitset, 
    int index)
{     
     bitset[index/8] = (bitset[index/8]) & ~(1 << (index%8));
}


/**Function********************************************************************

  Descrizione [Costruisce l'OBDD corrispondente ad un controllore tabulare]

******************************************************************************/
void
WriteOBDD (
    FILE* file_ctrl, // nome del file del controllore tabulare
    Ordering_Type ordering_type,  // criterio di ordinamento iniziale
    Ordering_Mode first_mode, // ordine di elaborazione della prima componente
    Ordering_Mode last_mode, // ordine di elaborazione della seconda componente
    Cudd_ReorderingType reordering_type, // criterio di riordinamento dinamico
    int from, // numero di sequenza della prima transizione da elaborare
    int to, // numero di sequenza dell'ultima transizione da elaborare
    FILE* file_obdd, // nome del file dell'OBDD generato
    int format, // formato di salvataggio
    FILE* file_info, // nome del file delle statistiche
    int reporting) // abilita il reporting se = 1
{
    Order order;
    DdManager* manager;
    DdNode* root;
    DdNode* temp_root;
    DdNode* cube;
    DdNode* temp_cube;
    int i, j, k;
    void (*firstMode)(int*);
    void (*lastMode)(int*);
    void (*actualMode)(int*);
    FILE* fp;
    char* file_name = (char*)malloc(10 * sizeof(char));

	fseek(file_ctrl,0,SEEK_SET);
    
	/* accesso in lettura al controllore tabulare
    file_ctrl.open(file_ctrl_name, ios::binary);
    if (!file_ctrl.is_open()) {
        cout << "\n Errore nell'apertura del file" << flush;
        exit(-2);
    }
	*/
    
    /* lettura del numero di transizioni e della lunghezza dello stato */   
	fread((char*)&NUM_TRANSITIONS, sizeof(unsigned long),1,file_ctrl);
	fread((char*)&NUM_BYTES_STATE, sizeof(unsigned int),1,file_ctrl);	
    //file_ctrl.read((char*)&NUM_TRANSITIONS, sizeof(unsigned long));
    //file_ctrl.read((char*)&NUM_BYTES_STATE, sizeof(unsigned int));
    NUM_BITS_TRANSITION = (NUM_BYTES_STATE * 8) + (NUM_BYTES_RULE * 8);
    
    /* aggiornamento della struttura Order in funzione dei parametri 
       relativi all'ordinamento */
    if (ordering_type == TRANSITION) {
            order.first_from = 0;
            order.first_to = (NUM_BYTES_STATE * 8) - (NUM_BYTES_RULE * 8) - 1;
            order.last_from = NUM_BYTES_STATE * 8;
            order.last_to = (NUM_BYTES_STATE * 8) - 1;
            firstMode = decrement;
            lastMode = interleaving;
    } else {
        order.first_from = 0;
        order.first_to = (NUM_BYTES_STATE * 8) - 1;
        firstMode = decrement;
        order.last_from = NUM_BYTES_STATE * 8;
        order.last_to = NUM_BITS_TRANSITION - 1;
        lastMode = decrement;
    
        if (ordering_type == RULE_STATE) {
            swap(&order.first_from, &order.last_from);
            swap(&order.first_to, &order.last_to);
        }
        if (last_mode == MODE_REVERSED) {
            swap(&order.last_from, &order.last_to);
            lastMode = increment;
        }
    }
    
    if (first_mode == MODE_REVERSED) {
        swap(&order.first_from, &order.first_to);
        firstMode = increment;
    }

    BIT_BLOCK temp_transition[NUM_BYTES_STATE + NUM_BYTES_RULE];
    BIT_BLOCK empty_state[NUM_BYTES_STATE];
    
    memset((void*)temp_transition, 0, (size_t)NUM_BYTES_STATE + NUM_BYTES_RULE);
    
    for (i = 0; i < NUM_BYTES_STATE; i++) {
        empty_state[i] = 255;
    }
    
    /* inizializzazione della struttura manager ed eventuale abilitazione 
       del reporting */
    manager = Cudd_Init(NUM_BITS_TRANSITION, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
    
    if (reordering_type != CUDD_REORDER_NONE)
        Cudd_AutodynEnable(manager, reordering_type);
    if (reporting) Cudd_EnableReorderingReporting(manager);
    
    /* creazione delle variabili */
    for (i = 0; i < NUM_BITS_TRANSITION; i++) {
        Cudd_bddIthVar(manager, i);
    }
    
    /* assegnamento del nodo costante Zero alla radice dell'OBDD */
    root = Cudd_ReadLogicZero(manager);
    Cudd_Ref(root);
    
    if (to > NUM_TRANSITIONS + 1) to = NUM_TRANSITIONS + 1;
    
    /* costruzione diagramma */
    for (i = 0; i < to; i++) {
	
		fread((char*)&temp_transition, NUM_BYTES_STATE,1,file_ctrl);
        //file_ctrl.read((char*)&temp_transition, NUM_BYTES_STATE);
        
        if (memcmp(temp_transition, empty_state, NUM_BYTES_STATE) != 0) {           
			fread((char*)&temp_transition + NUM_BYTES_STATE, NUM_BYTES_RULE,1,file_ctrl);
            //file_ctrl.read((char*)&temp_transition + NUM_BYTES_STATE, NUM_BYTES_RULE);
            //file_ctrl.seekg(2,ios::cur); // si ignora il numero di passi

            if (i >= from) {
            
                cube = Cudd_ReadOne(manager);
                Cudd_Ref(cube);
            
                k = order.last_to;
                actualMode = lastMode;
            
                /* costruzione clausola */
                for (j = NUM_BITS_TRANSITION - 1; j >= 0; j--) {
                    if (getBit(temp_transition, k) == 0) {
                        temp_cube = Cudd_bddAnd(manager, cube, Cudd_Not(Cudd_bddIthVar(manager, j)));
                    } else {
                        temp_cube = Cudd_bddAnd(manager, cube, Cudd_bddIthVar(manager, j));
                    }
                    Cudd_Ref(temp_cube);
                    Cudd_IterDerefBdd(manager, cube);
                    cube = temp_cube;
                
                    if (k == order.last_from) { /* si prosegue con la prima componente */
                        k = order.first_to;
                        actualMode = firstMode;
                    } else {
                        (*actualMode)(&k);
                    }
                } /* fine costruzione clausola */
            
                temp_root = Cudd_bddOr(manager, root, cube);
                Cudd_Ref(temp_root);
                Cudd_IterDerefBdd(manager, root);
                Cudd_IterDerefBdd(manager, cube);
                root = temp_root;
            
            }
        }

    } /* fine costruzione diagramma */ 
    
    /* scrittura su disco dell'OBDD nel formato specificato */
	//fp = fopen(file_obdd_name, "w");
	char * nome = "BOH";
    Dddmp_cuddBddStore(manager, NULL, root, NULL, NULL, format, DDDMP_VARIDS, nome, file_obdd);
    //fclose(fp);
    
    /* scrittura su disco del file delle statistiche */
    //fp = fopen(file_info_name, "w");
    //Cudd_PrintInfo(manager,fp);
    //fclose(fp);
    
    /* restituzione delle risorse */
    Cudd_Quit(manager);
}

/*
for (i = 0; i < NUM_BITS_TRANSITION; i++) {
        Cudd_bddCompose(manager,root,Cudd_ReadOne(manager),i)
	cube = Cudd_ReadOne(manager);
          Cudd_Ref(cube);
		  for.... {
	Cudd_bddAnd(manager)
	Cudd_bddIthVar(manager, i)
	}
	Cudd_bddExistAbstract(manager)
	
	dobbiamo crearne una copia ogni volta?!?
  }







*/
