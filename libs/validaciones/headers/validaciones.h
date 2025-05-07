#include "../../listas/headers/listas.h"
#include "../../pilas/headers/pilas.h"
#include "../../colas/headers/colas.h"
#include "../../tipoElemento/headers/tipo_elemento.h"
int obtener_opcion_menu();
int pedirEnteroEnRango(int min, int max);
int pedirEntero(char *mensaje);
int pedirNumeroNatural(char *mensaje);
int pedirNumeroNaturalNoCero(char *mensaje);
int pedirNumeroNaturalConjunto(char *mensaje);
void pedirConjunto(int conjunto[], int *tamano);
int pedirNumeroNoCero(char *mensaje);

Lista llenarLista(Lista lista);
Lista llenarListaLong(Lista lista, int longi);
void llenarDosListas(Lista l1, Lista l2);
void llenarDosListasIguales(Lista l1, Lista l2);

void llenarPila(Pila pila);
int contadorElemPila(Pila pila);
Pila copiarPila(Pila pila);
TipoElemento pedirTE(char *mensaje);


void llenarCola(Cola cola);
int longitudCola(Cola cola);

void mostrar_lista_posiciones(Lista l);
