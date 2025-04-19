#include <stdbool.h>
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

#ifndef TP_2_Listas
#define TP_2_Listas

// P2
typedef struct
{
    float resultado1;
    float resultado2;
} Resultados;

typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;

// Punto 2 a y b
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2);
// Punto 2 C
Lista verElementosRepetidos(Lista l1, Lista l2);
// Punto 2 D
float promedio(Lista l1);
// Punto 2 E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2);

// P3
typedef struct
{
    bool esMultiplo;
    bool escalar;
    int numEscalar;
} ResultadosMul;
ResultadosMul multiplo(Lista l1, Lista l2);

// P4 Retorna 1 si L1 > L2, 2 si L2 > 1, 0 si son iguales
int CompararListas(Lista l1, Lista L2);

// P5
void hacerPolinomio(Lista list);
float evaluarPolinomio(Lista list, float x);
Lista calcularRango(Lista list, double x, double y, double sumando);

// P6
bool esSublista(Lista l1, Lista l2);

// Utilidades
Lista rellenarLista(int elementos);

#endif // TP_2_Listas
