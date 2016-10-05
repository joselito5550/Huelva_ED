#include <iostream>
#include "clasepalabra.h"
#include <string>
#include <stdio.h>
#include "windows.h"
using namespace std;
Palabra::Palabra() //constructor
{
     strcpy(palabra,"");
}
Palabra& Palabra::operator=(Palabra &p){		//podria hacerlo sin una sobrecarga del operador =?
	strcpy(palabra,p.palabra);
	significados=p.significados;		//aqui tambien habria que sobrecargar el operador "=" de cola? 
	}
char *Palabra::getPalabra(){
	return palabra;
}
char *Palabra::getSignificado(int i){		//revisarlo per
	char*  aux;
	for (int j=0;j<i;j++){
		cadenasig help;
		aux=significados.primero();
		strcpy(help,aux);
		significados.desencolar();
		significados.encolar(help);
	}
	aux=significados.primero();
	return aux;
}
void Palabra::setPalabra(cadena p)    
{
     strcpy(palabra,p);
}
    
int Palabra::getnumAcepciones()
{
    return significados.longitud();
}
/*void Palabra::setnumAcepciones(int i)		//no sirve  
{
     numAcepciones=i;
}*/

void Palabra::setSignificado(cadenasig c)//copia c en la posicion i
{
     significados.encolar(c);
}
