#include <iostream>
#include "clasediccionario.h"
#ifndef _clasificador
#define _clasificador
using namespace std;
struct nodoPal {
cadena pal;
nodoPal* sig;
};
struct nodoNum {
int num;
nodoPal* pnp;
nodoNum* sig;
};
class Clasificador {
nodoNum* inicio;
public:
Clasificador(Diccionario& d);
void borrarClasificador();
void mostrar();
};
#endif
