#include "TadCola.h"
cola::cola()
{
elementos=new cadenasig[INCREMENTO];
if (elementos!=NULL) {
ne=fin=inicio=0;
Tama=INCREMENTO;
}
else {
ne=fin=inicio=-1;
Tama=-1;
}
}
cola& cola::operator=(cola &p){				//no estoy seguro de que se deba hacer 
	inicio=p.inicio;
	fin=p.fin;
	Tama=p.Tama;
	ne=p.ne;
	if (elementos!=NULL)	delete []elementos;
	elementos=new cadenasig[Tama];
	for(int i=0;i<ne;i++){
		strcpy(elementos[i],p.elementos[i]);
	}
}
cola::~cola()
{
if (elementos!=NULL)
delete [] elementos;
elementos=NULL;
ne=fin=inicio=-1;
Tama=0;
}
char *cola::primero(){		//como es una cadena habra que hacerlo con punteros no?
return elementos[inicio];
}
bool cola::esvacia(){
return (ne==0);
}
int cola::longitud()
{
return ne;
}
void cola::encolar(cadenasig e)
{
if (ne==Tama) {
	cadenasig *NuevaZona=new cadenasig[Tama+INCREMENTO];
	if (NuevaZona!=NULL) {
		for (int i=0;i<ne; i++) {
			strcpy(NuevaZona[i],elementos[inicio]);
			inicio++;
			if (inicio==Tama) // inicio=(inicio+1)%Tama
				inicio=0;
		}
		inicio=0;
		fin=ne;
		Tama+=INCREMENTO;
		delete elementos;
		elementos=NuevaZona;
	}
}
if (ne<Tama) {
	strcpy(elementos[fin],e);
	fin=(fin+1)%Tama;
	ne++;
}
}
void cola::desencolar()
{
inicio++; // inicio=(inicio+1)%Tama;
if (inicio==Tama)
inicio=0;
ne--;
if (Tama-ne>=INCREMENTO && Tama>INCREMENTO) {
cadenasig *NuevaZona=new cadenasig[Tama-INCREMENTO];
if (NuevaZona!=NULL) {
for (int i=0;i<ne; i++) {
strcpy(NuevaZona[i],elementos[inicio++]);
if (inicio==Tama)
inicio=0;
}
Tama-=INCREMENTO;
inicio=0;
fin=Tama;
delete [] elementos;
elementos=NuevaZona;
}
}
}
