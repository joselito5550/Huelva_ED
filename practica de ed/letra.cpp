#include "claseletra.h"
#include <iostream>
#include "windows.h"
using namespace std;
typedef char cadena[51];
typedef char cadenasig[251]; // para un significado
Letra::Letra()
{      numPalabras=0;
       palabras=NULL;
}
char Letra::getLetra()
{
     return letra;
}
void Letra::setLetra(char let)
{
     letra=let;
}
int Letra::getNumPalabras()     
{
    return numPalabras;
}
void Letra::setNumPalabras(int p)
{
     numPalabras=p;
}
void Letra::insertarPalabra(cadena p, cadenasig significado)
{
     int i=0;
     bool encontrado;
     encontrado=false;
       while ((i < numPalabras) && (!encontrado) && (strcmp(palabras[i].getPalabra(),p)<0))
       {                  //buscarlo si es mayor la palabra ya que si es mayor
                                                                    //al estar ordenada alfb. no va a estar COÑO!
          if (strcmp(palabras[i].getPalabra(),p)==0) encontrado=true; 
          else i++;
       }
         if (encontrado) 
         {
           int numsig=palabras[i].getnumAcepciones();
           palabras[i].setnumAcepciones(numsig+1);
           palabras[i].redimensionarSignificados(numsig+1);
           palabras[i].setSignificado(numsig+1,significado);
         }
         
          else
         { if(i=numPalabras)
           {
                 i=0;  //se introduce respetando su orden
          
                 while(strcmp(palabras[i].getPalabra(),p)<0)
                 {
                      i++; 
                 }
           }                         //j es la posicion donde tiene que ir la palabra
           Palabra *aux=new Palabra[numPalabras+1];
           for (int z=numPalabras;z>i;z--)
              aux[z]=palabras[z-1];                   //creo que esta bien pero hay que pensarlo mas y hay que añadirle el significado
           for (int x=0;x<i;x++)
              aux[x]=palabras[x];
           aux[i].setPalabra(p);
           numPalabras++;
           aux[i].redimensionarSignificados(1);
           aux[i].setSignificado(1,significado);                    //hay que hacerlo sobre aux que esta redimensionada 
           delete []palabras;
           palabras=aux;   
            }                                                    //se pone en la posicion 1 ya que la palabra es nueva
               }                                                    //hay que copiar aux a la "palabras"
void Letra::eliminarPalabras()
{    for(int i=0;i<numPalabras;i++)
     {
        palabras[i].eliminarSignificados();
     }
     delete []palabras;
}     
void Letra::setPalabra(int i,Palabra p)
{
     palabras[i]=p;                     //BORRANDO LA QUE ESTABA?
}     
Palabra Letra:: getPalabra(int i)
{
        Palabra aux;
        aux=palabras[i];               // I-1 porque el usuario empieza desde el 1?
        return aux;
}        
        
