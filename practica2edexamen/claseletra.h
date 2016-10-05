#include <iostream>
#include "clasepalabra.h"
#include "TADLista.h"
#ifndef _LEETRA
#define _LETRA

using namespace std;

class Letra {
char letra; 
lista palabras; // tabla din�mica de objetos de tipo Palabra de esa letra
public:
       
Letra();
char getLetra();                        
// devuelve la letra                               SI
void setLetra(char let);
// asigna la letra                                 SI
int getNumPalabras();
// devuelve el n�mero de palabras                  SI
void setNumPalabras(int p);
// asigna el n�mero de palabras                     SI
void insertarPalabra(cadena p, cadenasig significado);
// inserta una palabra y su significado
// si la palabra exist�a, se a�ade su significado (se supone que no se repiten)
// si no exist�a, se introduce respetando un orden alfab�tico ascendente                SI
Palabra getPalabra(int i);
// devuelve palabra de la posici�n i�sima                                               SI
void setPalabra(int i,Palabra p);
// asigna la palabra de la posici�n i�sima                                              PUEDE
void eliminarPalabras();
// elimina la tabla din�mica de palabras, junto con sus significados     
Letra& operator=(Letra &p);
};
#endif
