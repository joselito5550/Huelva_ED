#include <iostream>
using namespace std;

typedef char cadena[51];
typedef char cadenasig[251]; // para un significado


class Palabra {
cadena palabra; // palabra
int numAcepciones; // número de significados
cadenasig *significados; // tabla dinámica de significados
public:
       
Palabra(); // constructor que inicializa el objeto
char *getPalabra(); // permite obtener la palabra ------------------------------------------------------
void setPalabra(cadena p); // permite asignar la palabra
int getnumAcepciones(); // permite obtener el numero de significados
void setnumAcepciones(int i); // permite establecer el número
void redimensionarSignificados(int d); // redimensiona la tabla dinámica--------------------------------
void setSignificado(int i, cadenasig c); // establece el significado iésimo------------------------------
char *getSignificado(int i); // devuelve el iésimo significado-------------------------------------------
void eliminarSignificados(); // elimina la tabla dinámica de significados
};

