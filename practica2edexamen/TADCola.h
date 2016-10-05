#include <iostream> 
#define INCREMENTO 4 
#include "windows.h"
#ifndef _COLA
#define _COLA

using namespace std; 
typedef char cadenasig[251];

 class cola{ 
 cadenasig *elementos; //elementos de la cola  
 int inicio;
 int fin;    //principio y fin de la cola  
 int Tama;           //Capacidad de la tabla  
 int ne;             //Nº de elementos  
public: 
cola();             // constructor de la clase 
~cola();            // destructor de la clase 
void encolar(cadenasig e);  
void desencolar(); 
bool esvacia();  
char *primero();  
int longitud(); 
cola& operator=(cola &p);
}; 
#endif
