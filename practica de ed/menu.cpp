#include <iostream>
#include <fstream>
#include "clasediccionario.h"
using namespace std;
int main() {
	int opc;
	cadena ficherovolcado;
	Diccionario dicci;
	cout<<"\t -------Menu----------";
	cout<<"\n 1.-Cargar diccionario desde fichero";
	cout<<"\n 2.-Mostrar diccionario por pantalla";
	cout<<"\n 3.-Buscar Palabra";
	cout<<"\n 4.-Insertar Palabra";
	cout<<"\n 5.-Volcar diccionario a fichero";
	cout<<"\n 6.-Consultar palabra en el fichero";
	cout<<"\n 7.-Salir";
	cin>>opc;
	do{
		switch(opc){
			case 1:{
				cadena nombrefichero;
				system ("cls");
				cout<<"Introduzca el nombre del fichero que desea cargar\t";
				cin>>nombrefichero;
				dicci.cargarDiccionario(nombrefichero);
				system ("pause");
			}break;
			case 2:{
				dicci.mostrarDiccionario();
				system ("pause");
			}break;
			case 3:{
				system("cls");
				cadena palab;
				cout<<"Introduzca la palabra que desea buscar\t";
				cin>>palab;
				dicci.mostrarPalabra(palab);
				system ("pause");
			
			}	break;
			case 4:{
				system("cls");
				cadena palabr;
				char opc='s';
				cadenasig signi;
				do{
					cout<<"Introduzca la palabra que desea introducir\t";
					cin>>palabr;
					cout<<"\nIntroduzca el significado\t";
					cin>>signi;
					dicci.insertarPalabra(palabr,signi);
					cout<<"\nDesea seguir?S/N";
					cin>>opc;
				}while(opc!='N');
				system ("pause");
			}break;
			case 5:{
				system("cls");
				cout<<"Introduce el nombre del fichero donde desea volcar el diccionario\t";
				cin>>ficherovolcado;
				dicci.volcarDiccionario(ficherovolcado);
				
			}break;
			case 6:{
				char letrita;
				char letra;
				fpalabra aux;
				fstream f;
				cadenasig aux2;
				f.open(ficherovolcado,ios::in|ios::binary);
				int contadorpalabras=0;
				int contadorsignificados=0;
				int numpalabritas=0;
				letra='a';
				system("cls");
				cout<<"Introduzca la letra\t";
				cin>>letrita;
				while(dicci.getLetra(letra).getLetra()!=letrita){
					contadorpalabras+=dicci.getLetra(letra).getNumPalabras();
					numpalabritas=dicci.getLetra(letra).getNumPalabras();
					for (int j=0;j<numpalabritas;j++){
						contadorsignificados+=dicci.getLetra(letra).getPalabra(j).getnumAcepciones();
						}
				}
					f.seekg(contadorpalabras*sizeof(fpalabra)+contadorsignificados*sizeof(cadenasig),ios::beg); //abrir el flujo de fichero
					f.read((char*)&aux,sizeof(fpalabra));
					cout<<"\n"<<aux.palabra;
					for (int x=0;x<aux.numAcepciones;x++){
						f.read((char*)&aux2,sizeof(cadenasig));
						cout<<"\n\t"<<aux2;
					}
					system ("pause"); 
				}break;
			
		}while (opc!=7);
	return 0;

}
