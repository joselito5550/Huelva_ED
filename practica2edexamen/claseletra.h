#include <iostream>
#include "clasepalabra.h"
#include "TADLista.h"
#ifndef _LEETRA
#define _LETRA

using namespace std;

class Letra {
char letra; 
lista palabras; // tabla dinámica de objetos de tipo Palabra de esa letra
public:
       
Letra();
char getLetra();                        
// devuelve la letra                               SI
void setLetra(char let);
// asigna la letra                                 SI
int getNumPalabras();
// devuelve el número de palabras                  SI
void setNumPalabras(int p);
// asigna el número de palabras                     SI
void insertarPalabra(cadena p, cadenasig significado);
// inserta una palabra y su significado
// si la palabra existía, se añade su significado (se supone que no se repiten)
// si no existía, se introduce respetando un orden alfabético ascendente                SI
Palabra getPalabra(int i);
// devuelve palabra de la posición iésima                                               SI
void setPalabra(int i,Palabra p);
// asigna la palabra de la posición iésima                                              PUEDE
void eliminarPalabras();
// elimina la tabla dinámica de palabras, junto con sus significados     
Letra& operator=(Letra &p);
};
#endif
