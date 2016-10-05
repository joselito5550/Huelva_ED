#include <iostream>
using namespace std;

typedef char cadena[51];
typedef char cadenasig[251]; // para un significado


class Palabra {
cadena palabra; // palabra
int numAcepciones; // n�mero de significados
cadenasig *significados; // tabla din�mica de significados
public:
       
Palabra(); // constructor que inicializa el objeto
char *getPalabra(); // permite obtener la palabra ------------------------------------------------------
void setPalabra(cadena p); // permite asignar la palabra
int getnumAcepciones(); // permite obtener el numero de significados
void setnumAcepciones(int i); // permite establecer el n�mero
void redimensionarSignificados(int d); // redimensiona la tabla din�mica--------------------------------
void setSignificado(int i, cadenasig c); // establece el significado i�simo------------------------------
char *getSignificado(int i); // devuelve el i�simo significado-------------------------------------------
void eliminarSignificados(); // elimina la tabla din�mica de significados
};

