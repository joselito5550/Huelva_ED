#include "claseletra.h"
#include <iostream>
#include "windows.h"

using namespace std;
typedef char cadena[51];
typedef char cadenasig[251]; // para un significado
Letra::Letra()
{      
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
    return palabras.longitud();
}
Letra& Letra::operator=(Letra &p){
	letra=p.letra;
	palabras=p.palabras;
}
void Letra::insertarPalabra(cadena p, cadenasig significado)		
{
     int i=0;
     bool encontrado;
     bool vacia=palabras.esvacia();
     encontrado=false;
     int longitud=palabras.longitud();
     if(vacia){
     	Palabra aux;
     	aux.setPalabra(p);
     	aux.setSignificado(significado);
     	palabras.anadirIzq(aux);
     }
  
     else {
       while ((i < longitud )&&(!encontrado)&&(strcmp(palabras.observar(i+1).getPalabra(),p)<=0))	//deberia de dar error pero es al contrario
       {                  //buscarlo si es mayor la palabra ya que si es mayor
                                                                    //al estar ordenada alfb. no va a estar COÑO!
          if (strcmp(palabras.observar(i+1).getPalabra(),p)==0) 
		  encontrado=true; 
          else i++;
       }
         if (encontrado) 	//si la he encontrado añado el nuevo significado?
         {	palabras.insertarsigni(significado,i);
		 	//Palabra aux=palabras.observar(i+1);			//por aqui DA FALLO 
			 //aux.setSignificado(significado);			//probar creando un nuevo metodo en clase lista a ver que tal 
		 	//palabras.modificar(i+1,aux);				
         }
         
          else
         { if(i==longitud)
           {
        	Palabra aux;
		   	aux.setPalabra(p);
		   	aux.setSignificado(significado);			
           	palabras.insertar(i+1,aux);
           }
		   else {
		   	Palabra aux;
		   	aux.setPalabra(p);
		   	aux.setSignificado(significado);			
           	palabras.insertar(i+1,aux);
       		}
        }                                                    
    }
}
void Letra::setPalabra(int i,Palabra p)
{
	palabras.insertar(i,p);
} 
Palabra Letra::getPalabra(int i)
{
        Palabra aux;
        aux=palabras.observar(i+1);               
        return aux;
}
void Letra::eliminarPalabras(){	//revisar el destructor de clase palabra
	for(int i=0;i<palabras.longitud();i++){
	
		palabras.eliminarIzq();
	}
}        
