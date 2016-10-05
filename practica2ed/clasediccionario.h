#include "claseletra.h"
#include "windows.h"
#ifndef _DICCIONARIO
#define _DICCIONARIO

#define NUMLETRAS 26
using namespace std;
typedef char cadena[51];
typedef char cadenasig[251]; // para un significado
struct fpalabra {
cadena palabra;
int numAcepciones; // n�mero de significados
};

class Diccionario { 
 Letra tabla[NUMLETRAS]; 
 public: 
 Diccionario(); 													
 // constructor que inicializa la tabla con las letras 				HECHO
 Letra& getLetra(char letra); 										
 // devuelve el objecto Letra asociado con la letra dada 			HECHO
 void insertarPalabra(cadena palabra, cadenasig significado); 
 // permite insertar una palabra en el diccionario 
 // con el término “palabra” y con el significado “significado” 	HECHO
 void mostrarPalabra(cadena palabra); 
 // muestra los significados de una palabra por pantalla 			HECHO
 void mostrarDiccionario(); 
 // permite mostrar el diccionario completo por pantalla 			HECHO
 void cargarDiccionario(char* fichero); 
 // lee un fichero y lo carga en el diccionario 					NO
 void volcarDiccionario(char* fichero); 
 // vuelca a un fichero el diccionario 								NO
 void BorrarPalabra(cadena p);
 void borrarDiccionario(); 
 // elimina todas las palabras del diccionario 						HECHO
 ~Diccionario(); 
 // destructor, para liberar la memoria dinámica 					HECHO
};
#endif 
