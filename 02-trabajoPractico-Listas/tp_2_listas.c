#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include <stdlib.h>
#include <stdio.h>

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista listaNoRepetidos = l_crear();
    int esta;
    int longitudl1 = l_longitud(l1);
    TipoElemento x,y;
    Iterador it2 = iterador(l2);
    while(hay_siguiente(it2)){
        x = siguiente(it2);
        esta = 0;
        for(int i = 1; i<=longitudl1; i++){
            y = l_recuperar(l1,i);
            if(x->clave == y->clave){
                esta = 1;
            }
        }
        if(!esta){
            l_agregar(listaNoRepetidos,x);
        }
    }

    return listaNoRepetidos;
}


Lista verElementosRepetidos(Lista l1, Lista l2){
    Lista repetidos = l_crear();
    int longitudl2 = l_longitud(l2);
    TipoElemento x,y;
    bool esta;
    Iterador it = iterador(l1);
    while(hay_siguiente(it)){
        x = siguiente(it);
        esta = 0;
        for(int i = 1; i<=longitudl2; i++){
            y = l_recuperar(l2,i);
            if(x->clave == y->clave){
                esta = 1;
            }
        }
        if(esta){
            l_agregar(repetidos,x);
        }

    }
    return repetidos;
}

float promedio(Lista l1){
    float promedio = 0;
    int longitud = l_longitud(l1);
    if (longitud == 0){return 0;}
    TipoElemento x;
    Iterador it = iterador(l1);
    while(hay_siguiente(it)){
        x = siguiente(it);
        promedio += x->clave;
    }
    return promedio/longitud;
}

/*
typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;
*/

ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    int longitud1 = l_longitud(l1);
    int longitud2 = l_longitud(l2);

    ResultadoValorMinimo resultado;
    int pos1 = 0, pos2 = 0;
    TipoElemento primeroL1;
    TipoElemento x;

    Iterador it1 = iterador(l1);
    if(longitud1>0){
        primeroL1 = l_recuperar(l1,1);
        resultado.valor = primeroL1->clave;
        resultado.pos = 1;
        while(hay_siguiente(it1)){
            pos1++;
            x = siguiente(it1);
            if(x->clave < resultado.valor){
                resultado.valor = x->clave;
                resultado.pos = pos1;
            }
        }
    }else{
        resultado.valor = 0;
        resultado.pos = -1;
        printf("\nLa primer lista no tiene elementos, por ende no tiene valor minimo.\n");
    }


    TipoElemento primeroL2;
    if(longitud2>0){
        primeroL2 = l_recuperar(l2,1);
        resultado.valor_2 = primeroL2->clave;
        resultado.pos_2 = 1;

        Iterador it2 = iterador(l2);

        while(hay_siguiente(it2)){
            pos2++;
            x = siguiente(it2);
            if(x->clave < resultado.valor_2){
                resultado.valor_2 = x->clave;
                resultado.pos_2 = pos2;
            }
        }
    }else{
        resultado.valor_2 = 0;
        resultado.pos_2 = -1;
        printf("\nLa segunda lista no tiene elementos, por ende no tiene valor minimo.\n");
    }

    return resultado;
}


/* P3
typedef struct
{
    bool esMultiplo;
    bool escalar;
    int numEscalar;
} ResultadosMul;
ResultadosMul multiplo(Lista l1, Lista l2);    */

ResultadosMul multiplo(Lista l1, Lista l2) {
    ResultadosMul res;
    res.esMultiplo = true;
    res.escalar = true;
    res.numEscalar = 0;

    int len1 = l_longitud(l1);
    int len2 = l_longitud(l2);

    if (len1 != len2 || len1 == 0) {
        res.esMultiplo = false;
        res.escalar = false;
        return res;
    }

    int escalarTemp = -1;
    for (int i = 1; i <= len1; i++) {
        TipoElemento e1 = l_recuperar(l1, i);
        TipoElemento e2 = l_recuperar(l2, i);

        if (e1->clave == 0 || e2->clave % e1->clave != 0) {
            res.esMultiplo = false;
            res.escalar = false;
            return res;
        }

        int division = e2->clave / e1->clave;

        if (i == 1) {
            escalarTemp = division;
        } else if (division != escalarTemp) {
            res.escalar = false;
        }
    }

    if (res.escalar) {
        res.numEscalar = escalarTemp;
    }

    return res;
}


/* P4 Retorna 1 si L1 > L2, 2 si L2 > 1, 0 si son iguales
int CompararListas(Lista l1, Lista L2);  */

int CompararListas(Lista l1, Lista l2){
    int contador1 = 0, contador2 = 0, resultado = 0;
    Iterador it1 = iterador(l1);
    Iterador it2 = iterador(l2);
    TipoElemento x;
    while(hay_siguiente(it1)){
        x = siguiente(it1);
        contador1 += x->clave;
    }
    while(hay_siguiente(it2)){
        x = siguiente(it2);
        contador2 += x->clave;
    }
    if(contador1 > contador2){
        resultado = 1;
    }else if(contador1<contador2){
        resultado = 2;
    }else{
        resultado = 0;
    }
    return resultado;
}


// P6
bool esSublista(Lista l1, Lista l2){
    bool resultado = false;
    int long2 = l_longitud(l2);
    int estan = 0;
    Iterador it2 = iterador(l2);
    TipoElemento x,y;
    while(hay_siguiente(it2)){
        x = siguiente(it2);
        y = l_buscar(l1, x->clave);
        if( y != NULL && x->clave == y->clave){
            estan++;
        }
    }

    if(estan == long2){
        resultado = true;
    }
    return resultado;
}
