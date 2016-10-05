# include "TADLista.h" 
lista::lista() 
{ 
 elementos=new Palabra[INCREMENTO]; 
 if (elementos!=NULL) 
    { 
     Tama=INCREMENTO; 
      n=0; 
 } 
  else 
 { 
  Tama=n=-1; 
 } 
} 
lista::~lista() 
{ 
 if (elementos!=NULL) 
  delete [] elementos; 
 elementos=NULL; 
 Tama=n=0; 
} 
void lista::insertarsigni(cadenasig signi,int i){
	elementos[i].setSignificado(signi);
}
 
void lista::insertar(int i, Palabra& e) 
{
int pos;
if (n==Tama)
{
Palabra *NuevaZona=new Palabra[Tama+INCREMENTO];
if (NuevaZona!=NULL)
{
for (int i=0;i<n; i++)
NuevaZona[i]=elementos[i];
Tama+=INCREMENTO;
delete [] elementos;
elementos=NuevaZona;
}
};
if (n<Tama)
{
for (pos=n-1; pos>=i-1; pos--)
elementos[pos+1]=elementos[pos]; // Desplazamiento
elementos[i-1]=e;
n++;
}
}
 
void lista::modificar(int i, Palabra& e) { 	//hago lo mismo que en la de arriba //meto los significados
elementos[i-1]=e;
} 
 
Palabra& lista::observar(int i) {		 
 return(elementos[i-1]); 
} 
 
bool lista::esvacia() { 
 return (n == 0); 
} 
 
void lista::eliminar(int i) //es segun el usuario
//no lo podemos macharcar  
{ 
 Palabra* aux;
 aux= new Palabra[Tama];
 for (int j=0;j<i-1;j++)
     aux[j]=elementos[j];
 for (int z=n-1;z>=i;z--)            
     aux[z-1]=elementos[z];
  delete []elementos;
  elementos=aux; 
 n--; 
 if (Tama-n>=INCREMENTO && Tama>INCREMENTO) 
 { 
 Palabra *NuevaZona=new Palabra[Tama-INCREMENTO]; 
 if (NuevaZona!=NULL) 
 { 
  Tama-=INCREMENTO; 
   for (int i=0;i<Tama; i++) 	
       NuevaZona[i]=elementos[i]; 
    delete [] elementos; 
    elementos=NuevaZona; 
 } 
 } 
} 
 
int lista::posicion(Palabra &e) //devuelve la posicion 
{ 
 int i=0; 
 while (strcmp(elementos[i].getPalabra(),e.getPalabra())==0 && i < n) 
       i++; 
 return (i == n ? -1 : i+1); 
} 
 
inline int lista::longitud() 
{ 
 return n; 
} 
 
lista::lista(Palabra e) 
{ 
 elementos=new Palabra[INCREMENTO]; 
 if (elementos!=NULL) { 
  Tama=INCREMENTO; 
   n=1; 
   elementos[0]=e; 		//asi no?
 } 
 else { 
 Tama=n=-1; 
 } 
} 
void lista::anadirIzq(Palabra& e) 
{ 
 insertar(1, e); 
} 
 
void lista::anadirDch(Palabra e) 
{ 
 insertar(n+1, e); 
} 
 
void lista::eliminarIzq() 
{ 
 eliminar(1); 
} 
 
void lista::eliminarDch() 
{ 
 eliminar(n); 
} 
 
Palabra& lista::observarIzq() 
{ 
 return(observar(1)); 
} 
 
Palabra& lista::observarDch() 
{ 
 return(observar(n)); 
} 
lista& lista::operator=(lista &p){
	n=p.n;
	Tama=p.Tama;
	elementos=new Palabra[Tama];
	for (int i=0;i<Tama;i++){
		elementos[i]=p.elementos[i];
	}
}
 
void lista::concatenar(lista l) 
{ 
 int lon = l.longitud(); 
 for (int i=1; i<=lon; i++) 
 insertar(n+1, l.observar(i)); 
} 
 
bool lista::pertenece(Palabra e) 
{ 
 return (posicion(e) != -1); 
} 
