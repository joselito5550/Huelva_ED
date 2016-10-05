#include <iostream>
#include "clasepalabra.h"
#include <string>
#include <stdio.h>
#include "windows.h"
using namespace std;
Palabra::Palabra() //constructor
{
     strcpy(palabra,"");
     numAcepciones=0;
     significados=NULL;
}
char *Palabra::getPalabra(){
	return palabra;
}
char *Palabra::getSignificado(int i){
	return significados[i];
}
void Palabra::setPalabra(cadena p)    //permite asiganar la palabra
{
     strcpy(palabra,p);
}
    
int Palabra::getnumAcepciones()
{
    return numAcepciones;
}
void Palabra::setnumAcepciones(int i) 
{
     numAcepciones=i;
}
void Palabra::eliminarSignificados()   
{
     delete []significados;
     significados=NULL;
     numAcepciones=0;
}
void Palabra::setSignificado(int i,cadenasig c)//copia c en la posicion i
{
     if (i<numAcepciones)                        //tiene que ser una posicion válida 
         strcpy(significados[i-1],c);
     numAcepciones++;
}
void Palabra::redimensionarSignificados(int d) //crear nueva tabla y copiar los elementos de la tabla anterior a esta y luego cargartela
{
     if (significados==NULL)
     {
      significados=new cadenasig [d];
     }
else 
{
     cadenasig *aux=new cadenasig [d];
     for(int i=0;i<numAcepciones;i++)
     strcpy(aux[i],significados[i]);    
     delete []significados;
     significados=aux;
}     
}
