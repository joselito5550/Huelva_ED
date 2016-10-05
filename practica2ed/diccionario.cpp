#include "clasediccionario.h"
#include <iostream>
#include "windows.h"
#include <fstream>
using namespace std;

Diccionario::Diccionario(){
	char a;
	a='a';
	for (int i=0;i<26;i++){
		tabla[i].setLetra(a);
		a++;
	}
}
Letra& Diccionario::getLetra(char letra){
	bool encontrado=false;
	int posic=0;
	while (!encontrado){
		if(letra==tabla[posic].getLetra())	encontrado=true;
		else posic++;
	}
	
	return tabla[posic];
}
void Diccionario::insertarPalabra(cadena palabra, cadenasig significado){
	bool encontrado=false;
	int i=0;
	while(!encontrado){
		if(palabra[0]==tabla[i].getLetra())
			encontrado=true;
		else	i++;
	}			
	if (encontrado){
		tabla[i].insertarPalabra(palabra,significado);
	}
}

/*void Diccionario::BorrarPalabra(cadena p){
	bool encontrado=false;
	bool algo=false;
	int numpalabras=0;
	Palabra aux;
	int i=0;
	int j=0;
	while((!encontrado)&&(!algo)){
		if(p[0]==tabla[i].getLetra())
			encontrado=true;
		else	i++;
		if (encontrado){
			numpalabras=tabla[i].getNumPalabras();
			if(strcmp(tabla[i].getPalabra(j).getPalabra(),p)==0)
				algo=true;
			else	j++;					//ya sabemos la posicion en la que se encuentra la palabra que queremos eliminar
			}	
	}
	if(!algo) cout<<"\n La palabra no se encuentra en el diccionario";
	else {
		for (int z=numpalabras-1;z>=j;z--){
			aux=tabla[i].getPalabra(z);
			tabla[i].setPalabra(z-1,aux);		//utilizo setpalabra porque sustituye la que estaba
		}										//intento copiar la tabla hacia atras para eliminar asi la palabra
		
	}
} */
void Diccionario::mostrarPalabra(cadena palabra){
	bool encontrado=false;
	bool algo=false;
	int numpalabras=0;
	int i=0;
	int j=0;
	while(!encontrado){			
		if(palabra[0]==tabla[i].getLetra())
			encontrado=true;
		else	i++;
	}
		if (encontrado){
			numpalabras=tabla[i].getNumPalabras();
			while (!algo){
			if(strcmp(tabla[i].getPalabra(j).getPalabra(),palabra)==0){
				algo=true;}
			else  j++;					//ya sabemos la posicion en la que se encuentra la palabra que queremos mostrar
			
			}
	if (algo){
	int numsigni=tabla[i].getPalabra(j).getnumAcepciones();
	cout<<tabla[i].getPalabra(j).getPalabra();
	for(int z=0;z<numsigni;z++){
		cout<<"\n"<<z<<".-"<<tabla[i].getPalabra(j).getSignificado(z);	//getSignifiado es un puntero... sera asi?
	}
}
}
}
void Diccionario::mostrarDiccionario(){
	int numpalabras,numsig;
	for (int i=0;i<NUMLETRAS;i++){
		numpalabras=tabla[i].getNumPalabras();
		for (int j=0;j<numpalabras;j++){
			numsig=tabla[i].getPalabra(j).getnumAcepciones();		//cuidado
			cout<<"\n"<<tabla[i].getPalabra(j).getPalabra();
			for (int z=0;z<numsig;z++){
				cout<<"\n\t"<<tabla[i].getPalabra(j).getSignificado(z);		
			}
		}
	}
}
void Diccionario::borrarDiccionario(){			//sigue existiendo porque cuando carguemos desde fichero tenemos que quitar lo que haya
	for(int i=0;i<NUMLETRAS;i++){
		tabla[i].eliminarPalabras();                                
	}
}
Diccionario::~Diccionario()
{
   borrarDiccionario();
}                               
void Diccionario::cargarDiccionario(char* fichero)   
{
     fstream f;
     fpalabra aux;
     cadenasig signi;
     int i=0;
     int j=0;
     bool encontrado=false;
     int numsig;
     f.open(fichero,ios::in|ios::binary);
	 f.clear();			//in u out?
     if (f.fail()) cout<<"\n\tError al abrir el fichero";
     do{
    	i=0;
     f.read((char*)&aux,sizeof(fpalabra));
     numsig=aux.numAcepciones;
     while (!encontrado){
     	if(aux.palabra[0]==tabla[i].getLetra())	encontrado=true;
     	else i++;															//revisarlo! 
     }
     for (int j=0;j<numsig;j++)
     f.read((char*)&signi,sizeof(cadenasig));
     tabla[i].insertarPalabra(aux.palabra,signi);
}while (!f.eof());
f.close();
f.clear();
}										//mientras no se llegue al final 

void Diccionario::volcarDiccionario(char* fichero){
	fstream f;
	f.open(fichero,ios::out|ios::binary);	//va entre comillas???
	fpalabra aux;
	cadenasig signi;
	int numdepalabras;
	int numsig;
	for (int i=0;i<NUMLETRAS;i++){
		numdepalabras=tabla[i].getNumPalabras();
		for (int z=0;z<numdepalabras;z++){
			strcpy(aux.palabra,tabla[i].getPalabra(z).getPalabra());						//puede ser que este bien... repasarlo un poco
			numsig=tabla[i].getPalabra(z).getnumAcepciones();
			aux.numAcepciones=numsig;
			f.write((char*)&aux,sizeof(fpalabra));
			for (int j=0;j<numsig;j++){
				strcpy(signi,tabla[i].getPalabra(z).getSignificado(j));
				f.write((char*)&signi,sizeof(cadenasig));
			}
		}																
	}
	f.close();
}  																	   
