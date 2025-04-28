#include "tp_3_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//2.	Dada una pila cargada con valores al azar realizar los siguientes ejercicios:

//  a.	Buscar una clave y determinar si existe en la Pila (sin perder la pila). Si la encuentra retorna true, caso contrario false
bool p_ej2_existeclave(Pila p, int clave){
    Pila pAux = p_crear();
    bool encontro = false;
    TipoElemento x;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(pAux,x);
        if(x->clave == clave){
            encontro = true;
        }
    }

    while(!p_es_vacia(pAux)){
        x = p_desapilar(pAux);
        p_apilar(p,x);
    }
    return encontro;
}
//  b.Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).
// Retorna la nueva pila con el nuevo elemento, caso contrario la pila original recibida.
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    Pila paux = p_crear();
    Pila p2 = p_crear();
    int contador = 1;
    TipoElemento y;
    while(!p_es_vacia(p)){
        y = p_desapilar(p);
        p_apilar(paux,y);
    }
    while(!p_es_vacia(paux)){
        y = p_desapilar(paux);
        p_apilar(p,y);
        p_apilar(p2,y);
    }
    while(contador != posicionordinal){
        contador++;
        y = p_desapilar(p2);
        p_apilar(paux,y);
    }
    p_apilar(p2,x);
    while(!p_es_vacia(paux)){
        y = p_desapilar(paux);
        p_apilar(p2,y);
    }
    return p2;
}

//  c.	Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave).
// retorna la nueva pila sin la clave, si la encuentra, sino retorna la misma pila que recibio.
Pila p_ej2_eliminarclave(Pila p, int clave) {
    Pila pAux = p_crear();
    Pila pCopia = p_crear();
    Pila resultado = p_crear();
    TipoElemento x;
    bool eliminado = false;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);
        p_apilar(pAux, x);
        p_apilar(pCopia, x);
    }

    while (!p_es_vacia(pAux)) {
        x = p_desapilar(pAux);
        if (!eliminado && x->clave == clave) {
            eliminado = true;
        } else {
            p_apilar(resultado, x);
        }
    }

    while (!p_es_vacia(pCopia)) {
        x = p_desapilar(pCopia);
        p_apilar(p, x);
    }

    return resultado;
}

//  e.	Duplicar el contenido de una pila.
// retorna la nueva pila. Si esta vacia retorna otra vacia.
Pila p_ej2_duplicar(Pila p){
    Pila paux = p_crear();
    Pila copia = p_crear();
    TipoElemento x;
    if(!p_es_vacia(p)){
       while(!p_es_vacia(p)){
            x = p_desapilar(p);
            p_apilar(paux,x);
        }
    }
    if(!p_es_vacia(paux)){
       while(!p_es_vacia(paux)){
            x = p_desapilar(paux);
            p_apilar(copia,x);
            p_apilar(p,x);
        }
    }

    return copia;
}

//  f.	Contar los elementos de la pila.
// retorna la cantidad de elementos de la pila. Si esta vacia retorna 0 (cero).
int p_ej2_cantidadelementos(Pila p){
    int contador = 0;
    Pila paux = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        contador++;
        x = p_desapilar(p);
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return contador;
}



/**
 3.	Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas.
	Utilizar para la resolución del problema una única pila auxiliar.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna true si son exactamente iguales, caso contrario retorna false
bool p_ej3_iguales(Pila p1, Pila p2){
    Pila paux = p_crear();
    TipoElemento x,y;
    bool iguales = true;
    while(iguales && !p_es_vacia(p1)){
        x = p_desapilar(p1);
        y = p_desapilar(p2);
        p_apilar(paux,x);
        if(x->clave != y->clave){
            p_apilar(p2,y);
            iguales = false;
        }
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p1,x);
        p_apilar(p2,x);

    }
    return iguales;
}

/**
 4.	Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como parámetro,
	a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
char* p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase)
{
    char* resultado = (char*)malloc(100 * sizeof(char)); // Reservo espacio suficiente

    // Caso especial: Si el número es 0, devolvemos "0"
    if (nrobasedecimal == 0)
    {
        strcpy(resultado, "0");
        return resultado;
    }

    // Si el número es negativo, lo hacemos positivo para trabajar con su valor absoluto
    int negativo = 0;
    if (nrobasedecimal < 0) {
        negativo = 1;
        nrobasedecimal = -nrobasedecimal;  // Hacemos el número positivo para la conversión
    }

    Pila restos = p_crear();
    while(nrobasedecimal > 0)
    {
        int residuo = nrobasedecimal % nrootrabase;
        p_apilar(restos, te_crear(residuo));
        nrobasedecimal /= nrootrabase;
    }

    int i = 0;
    // Si el número era negativo, añadimos el signo menos al principio
    if (negativo) {
        resultado[i++] = '-';
    }

    // Extraemos los elementos de la pila y los convertimos a caracteres
    while (!p_es_vacia(restos)) {
        TipoElemento elemento = p_desapilar(restos);
        int digito = elemento->clave;
        if (digito < 10) {
            resultado[i++] = '0' + digito;
        } else {
            resultado[i++] = 'A' + (digito - 10);
        }
    }

    resultado[i] = '\0'; // Terminamos la cadena
    return resultado;
}

/**
 5.	Invertir el contenido de una pila sin destruir la pila original.
	Se debe retornar la nueva pila invertida y la original no se debe perder.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
Pila  p_ej5_invertir(Pila p){
    Pila paux = p_crear();
    Pila paux2 = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(paux,x);
        p_apilar(paux2,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return paux2;
}

/**
6.	Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado ítem sin perder la pila original.
	Deberá retornar una nueva pila sin el ítem en consideración.
	Resolver iterativamente y recursivamente.
	Determinar la complejidad algorítmica de ambas soluciones.
 */
// retornar la nueva pila sin la clave que se debe sacar (eliminar). Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones
Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila paux = p_crear();
    Pila sinClave = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
        if(x->clave != clave){
            p_apilar(sinClave,x);
        }
    }
    return sinClave;
}

/**
7.	Dada dos pilas realizar una función que permita determinar los elementos que tienen en común.
	Debe retornar una nueva pila con esos elementos (que están en ambas pilas) sin perder las pilas originales.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves en comun de ambas Pilas recibidas por parametro.  Si no hay claves en comun retornar una pila vacia.
Pila p_ej7_elementoscomunes(Pila p1, Pila p2) {
    Pila resultado = p_crear();
    Pila paux = p_crear();
    Pila temp_p2 = p_crear();
    Pila elementosEncontrados = p_crear();
    TipoElemento x, y;

    while (!p_es_vacia(p1)) {
        x = p_desapilar(p1);
        p_apilar(paux, x);

        while (!p_es_vacia(p2)) {
            y = p_desapilar(p2);
            p_apilar(temp_p2, y);

            if (x->clave == y->clave) {
                bool encontrado = false;

                Pila aux_check = p_crear();
                while (!p_es_vacia(elementosEncontrados)) {
                    TipoElemento z = p_desapilar(elementosEncontrados);
                    p_apilar(aux_check, z);
                    if (z->clave == x->clave) {
                        encontrado = true;
                    }
                }

                while (!p_es_vacia(aux_check)) {
                    p_apilar(elementosEncontrados, p_desapilar(aux_check));
                }

                if (!encontrado) {
                    p_apilar(resultado, x);
                    p_apilar(elementosEncontrados, x);
                }
            }
        }

        while (!p_es_vacia(temp_p2)) {
            y = p_desapilar(temp_p2);
            p_apilar(p2, y);
        }
    }

    while (!p_es_vacia(paux)) {
        x = p_desapilar(paux);
        p_apilar(p1, x);
    }

    return resultado;
}

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
// Si la pila estavacia retorna pila vacia.

Pila p_ej8_sacarrepetidos(Pila p) {
    return p;
}

