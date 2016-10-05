#include <iostream> 
#define INCREMENTO 4 
#include "clasepalabra.h"
#ifndef _LISTA
#define _LISTA
using namespace std; 
class lista { 
 Palabra *elementos; // elementos de la lista 
 int n; // nº de elementos que tiene la lista 
 int Tama; // tamaño de la tabla en cada momento 
 public: 
 lista(); // constructor de la clase 
 ~lista(); // destructor de la clase 
 lista(Palabra e); 
 bool esvacia(); 
 int longitud(); 
 void anadirIzq(Palabra& e); 
 void anadirDch(Palabra e); 
 void eliminarIzq(); 
 void eliminarDch(); 
 void insertarsigni(cadenasig signi,int i);
 Palabra& observarIzq(); 
 Palabra& observarDch(); 
 void concatenar(lista l); 
 bool pertenece(Palabra e); 
 void insertar(int i, Palabra& e); 
 void eliminar(int i); 
 void modificar(int i, Palabra& e); 
 Palabra& observar(int i); 
 int posicion(Palabra& e);
 lista& operator=(lista &p); 
}; 
#endif
