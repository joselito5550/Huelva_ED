#include <iostream>

#include "claseclasificador.h"
#include "windows.h"
using namespace std;
Clasificador::Clasificador(Diccionario& d){
	if(inicio!=NULL)	delete inicio;		//ya se han de debido borrar con el borrar clasificador 
	inicio=new nodoNum;
	nodoNum *aux;
	if(inicio!=NULL){
		int asig=1;
		aux=inicio;
		for (int i=0;i<12;i++){
			aux->num=asig;
			//if(aux->sig!=NULL)	delete aux->sig;
			aux->sig=NULL;
			aux->sig=new nodoNum;
			aux->pnp=NULL;				//lo ponemos a NULL porque aun no sabemos si hay palabras que tengan ese num de vocales
			if(aux->sig==NULL)	
				cout<<"\n\n\n\nNo hay memoria para mas nodos";
			else 
				aux=aux->sig;
			asig++;
		}
		aux->num=asig;
		aux->sig=NULL;	//lo ponemos a NULL
		aux->pnp=NULL;
		//se supone que aqui hemos creado suficientes nodoNum
		char a='a';
		int z,contador,numpalabras,longitudpal,p;
		bool nodoencontrado;
		cadena algo;
		nodoPal *ayuda;
		nodoPal *ayuda1;
		nodoPal *ayuda2;
		Letra help;
		for(int j=0;j<NUMLETRAS;j++){			//voy letra por letra 
			help=d.getLetra(a);					//cuento el num de palabras de cada letra
			z=0;
			numpalabras=help.getNumPalabras();
			do {
				contador=0;
				longitudpal=strlen(help.getPalabra(z).getPalabra());		//reviso cada palabra y cuento cuantas vocales tiene 
				strcpy(algo,help.getPalabra(z).getPalabra());
				for(int y=0;y<longitudpal;y++){
					if(algo[y]=='a'||algo[y]=='e'||algo[y]=='i'||algo[y]=='o'||algo[y]=='u')
						contador++;
				}
				//una vez tenemos la longitud tenemos que insertarla en su nodo correspondiente 
				if(contador<12&&contador>0){	//nos aseguramos que tenga vocales 
					p=0;
					aux=inicio;
					nodoencontrado=false;
					while((nodoencontrado==false)&&(p<asig)){
						if(aux->num==contador)	nodoencontrado=true;		//buscamos el nodo con el num de vocales
						else {
							p++;
							aux=aux->sig;
						}
					}
					if(nodoencontrado){			//cuando lo encontremos tenemos que ver donde lo ponemos 
						if(aux->pnp==NULL){
							aux->pnp=new nodoPal;
							strcpy(aux->pnp->pal,algo);
							aux->pnp->sig=NULL;
						}
						else{
							ayuda=aux->pnp;
							ayuda1=new nodoPal;				
							if(ayuda1!=NULL){				
								strcpy(ayuda1->pal,algo);
								ayuda2=ayuda->sig;
								if(ayuda2==NULL){
								ayuda->sig=ayuda1;
								}
								else {
									ayuda->sig=ayuda1;
									ayuda1->sig=ayuda2;
								}
								ayuda=NULL;
									
							}
							else cout<<"no hay espacio";
							ayuda1=NULL;
						}
					}
				}
				z++;
			} while(z<numpalabras);
			a++;
			//
		}
	}
	
}
void Clasificador::mostrar(){
	nodoNum *aux;
	nodoPal *aux1;
	aux=inicio;
	for (int i=0;i<12;i++){
		cout<<"\n"<<aux->num<<"\tVocal\n";
		aux1=aux->pnp;
		if(aux1!=NULL){
			while(aux1->sig!=NULL){
				cout<<"\t"<<aux1->pal;
				aux1=aux1->sig;
			}
			cout<<"\t"<<aux1->pal;
		}
		aux=aux->sig;
	}
}
void Clasificador::borrarClasificador(){
	nodoNum *aux;
	nodoNum *aux1;
	nodoPal *help;
	nodoPal *help1;
	aux=inicio;
	while(aux->sig!=NULL){
		if(aux->pnp!=NULL){		//si tiene algo
			help=aux->pnp;
			while(help->sig!=NULL){
				help1=help->sig;
				delete help;
				help=help1;
			}
			delete help;		//borramos el ultimo
	
		}
		aux1=aux->sig;
		delete aux;
		aux=aux1;
		}
		delete aux;
		inicio=NULL;
		aux=NULL;
		aux1=NULL;
		help=NULL;
		help1=NULL;
}
















