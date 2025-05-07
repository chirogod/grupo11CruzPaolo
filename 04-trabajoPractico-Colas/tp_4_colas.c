#include "tp_4_colas.h"
#include "../libs/colas/headers/colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libs/validaciones/headers/validaciones.h"

/*
    2.	Resolver los siguientes puntos:
 */

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave){
    Cola colaux = c_crear();
    TipoElemento x;
    bool encontrado = false;
    while(!c_es_vacia(c) && encontrado == false){
        x = c_desencolar(c);
        if(x->clave == clave){
            encontrado = true;
        }
        c_encolar(colaux,x);
    }
    while(!c_es_vacia(colaux)){
        x = c_desencolar(colaux);
        c_encolar(c,x);
    }
    return encontrado;
}

//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    Cola colaux = c_crear();
    Cola colares = c_crear();
    int contador = 1;
    TipoElemento y;
    while(!c_es_vacia(c)){
        y = c_desencolar(c);
        c_encolar(colaux,y);
    }
    while(!c_es_vacia(colaux)){
        y = c_desencolar(colaux);
        c_encolar(c,y);
        if(contador==posicionordinal){
            c_encolar(colares,X);
        }
        c_encolar(colares,y);
        contador++;
    }
    if (contador == posicionordinal) {
        c_encolar(colares, X);
    }

    return colares;
}

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave){
    TipoElemento x;
    Cola colaux = c_crear();
    Cola sinClave = c_crear();
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(colaux,x);
    }
    while(!c_es_vacia(colaux)){
        x = c_desencolar(colaux);
        c_encolar(c,x);
        if(x->clave != clave){
            c_encolar(sinClave,x);
        }
    }
    return sinClave;
}

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c){
    int contador = 0;
    TipoElemento x;
    Cola caux = c_crear();
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux,x);
        contador++;
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
        contador++;
    }
    return contador;
}

//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c){
    TipoElemento x;
    Cola caux = c_crear();
    Cola res = c_crear();
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux,x);
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
        c_encolar(res,x);
    }
    return res;
}

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.
Cola c_ej2_invertir(Cola c){
    return c;
}

/**
3.	Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave),
	sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar.
 */
// retorna true si son exactamente iguales, caso contrario retorna false.
bool c_ej3_iguales(Cola c1, Cola c2)
{
    TipoElemento aux1, aux2;
    Cola c_aux = c_crear();
    bool iguales = true;

    while(!c_es_vacia(c1) || !c_es_vacia(c2))
    {
        if(c_es_vacia(c1) || c_es_vacia(c2)){
            iguales = false;
            break;
        }

        aux1 = c_desencolar(c1);
        aux2 = c_desencolar(c2);

        if(aux1->clave != aux2->clave){
            iguales = false;
            break;
        }
        c_encolar(c_aux, aux1);
    }

    while(!c_es_vacia(c_aux))
    {
        aux1 = c_desencolar(c_aux);
        c_encolar(c1, aux1);
        c_encolar(c2, aux1);
    }

    return iguales;
}

/**
4.	Dada una cola de números enteros, no ordenada,
	construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera,
	sin destruir el contenido de la cola original y dejándola en su estado inicial.
 */
// Retorna la cola con las claves que no tienen repeticiones, caso contrario si todas se repiten retorna cola vacia.
Cola c_ej4_colanorepetidos(Cola c) {
    int repetido = 0;
    Cola caux = c_crear();
    Cola caux2 = c_crear();
    Cola resultado = c_crear();
    TipoElemento x, y,z;
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux,x);
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
        c_encolar(caux2,x);
    }
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        while(!c_es_vacia(caux2)){
            y = c_desencolar(caux2);
            if(x->clave == y->clave){
                repetido++;
            }
            c_encolar(caux, y);
        }
        if(repetido<=1){
            c_encolar(resultado,x);
        }
        while(!c_es_vacia(caux)){
            z = c_desencolar(caux);
            c_encolar(caux2, z);
        }
        repetido = 0;
    }
    while(!c_es_vacia(caux2)){
        z = c_desencolar(caux2);
        c_encolar(c, z);
    }
    return resultado;
}

/**
5.	Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
	obtener todos los valores que son Divisores Totales o parciales.
	Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta.
	Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola (es decir a la mitad de los elementos).
 */
// retorna una cola con el/los divisor/es total/es o parcial/es.   Si no hay ni divisor total ni parcial retornar cola vacia.
// Usar el atributo valor para indicar cuando el divisor es total(true) o parcial.  Indicar con true cuando es total, caso contrario false.
Cola c_ej5_divisortotal(Cola c) {
    Cola resultado = c_crear();
    Cola cola_analisis = c_crear();
    Cola cola_restauracion = c_crear();  // Para restaurar 'c'
    TipoElemento actual, comparado;
    int total = 0;

    // Copiar 'c' a cola_analisis y contar los elementos
    while (!c_es_vacia(c)) {
        actual = c_desencolar(c);
        c_encolar(cola_analisis, actual);
        c_encolar(cola_restauracion, actual); // para restaurar 'c'
        total++;
    }

    // Restaurar 'c' con los elementos originales
    while (!c_es_vacia(cola_restauracion)) {
        actual = c_desencolar(cola_restauracion);
        c_encolar(c, actual);
    }

    // Analizar cada valor como posible divisor
    while (!c_es_vacia(cola_analisis)) {
        actual = c_desencolar(cola_analisis);
        int divisor = actual->clave;
        int contador = 0;

        // Evaluar cuántos valores de 'c' son divisibles por 'divisor'
        while (!c_es_vacia(c)) {
            comparado = c_desencolar(c);

            if (comparado->clave % divisor == 0) {
                contador++;
            }

            c_encolar(cola_restauracion, comparado);  // restaurar luego
        }

        // Restaurar 'c'
        while (!c_es_vacia(cola_restauracion)) {
            comparado = c_desencolar(cola_restauracion);
            c_encolar(c, comparado);
        }

        // Evaluar si es divisor total o parcial
        if (contador == total) {
            TipoElemento nuevo = te_crear(divisor);
            nuevo->valor = (void*) true;  // divisor total
            c_encolar(resultado, nuevo);
        } else if (contador >= (total + 1) / 2) {
            TipoElemento nuevo = te_crear(divisor);
            nuevo->valor = (void*) false; // divisor parcial
            c_encolar(resultado, nuevo);
        }
    }

    return resultado;
}

/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
	y en qué posición ordinal se encontró cada uno en su estructura.  Si existe mas de una vez la primer posicion encontrada.
	No se deben destruir las estructuras originales.
 */
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia.
// Usar el atributo valor para enviar las 2 posiciones como un *char.
// Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:5). 2 y 4 deben venir en el valor.
// "2:4" indicara que el "5" esta en la segunda posicion de "P" y en la cuarta de "C".
Lista c_ej6_comunesapilaycola(Pila p, Cola c) {
    Pila p_copia = p_crear();
    Pila paux2 = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(paux2,x);
    }
    while(!p_es_vacia(paux2)){
        x = p_desapilar(paux2);
        p_apilar(p_copia,x);
        p_apilar(p,x);
    }
    Lista respuesta = l_crear();
    TipoElemento aux_p, aux_c;
    int pos_pila = 0;

    while (!p_es_vacia(p_copia))
    {
        aux_p = p_desapilar(p_copia);
        pos_pila++;

        Cola c_temp = c_crear();
        int pos_cola = 0;

        while (!c_es_vacia(c)) {
            aux_c = c_desencolar(c);
            pos_cola++;

            if (aux_c->clave == aux_p->clave) {
                char buffer[20];
                snprintf(buffer, sizeof(buffer), "%d:%d", pos_pila, pos_cola);
                char* valor_dinamico = malloc(strlen(buffer) + 1);
                if (valor_dinamico != NULL) {
                    strcpy(valor_dinamico, buffer);
                    l_agregar(respuesta, te_crear_con_valor(aux_c->clave, valor_dinamico));
                }
            }

            c_encolar(c_temp, aux_c);
        }

        while (!c_es_vacia(c_temp)) {
            c_encolar(c, c_desencolar(c_temp));
        }
    }

    return respuesta;
}

/**
7.	Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en cada ventanilla.
	Un día, dos de los tres empleados que atienden las ventanillas no pueden asistir al trabajo,
	quedando uno solo para atender a las tres colas. Este empleado decide que, a medida que lleguen los clientes,
	atenderá por cierta cantidad de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas equitativamente.
	Se pide que implemente un algoritmo que modele esta situación y dé como resultado el orden en que fueron atendidos los clientes.
 */
// retornar la cola con los resultados de la atenciones de los clientes.  Ver el ejemplo en el PDF del TP.
// retornar en la clave el nro de cola que lo atendio y en el void* de cada elemento los textos "Cliente 1 Cola 3", Cliente 1 Cola 2, etc.
// Segun el ejemplo el primer item de la cola seria clave: 3, void* "Cliente 1 Cola 3".
// Si las colas estan vacias, retornar cola vacia.
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int q) {
    Cola resultado = c_crear();  // Cola de resultados

    int tiempo1 = 0, tiempo2 = 0, tiempo3 = 0;
    int cliente1 = 1, cliente2 = 1, cliente3 = 1;

    TipoElemento actual1 = c_desencolar(c1);
    TipoElemento actual2 = c_desencolar(c2);
    TipoElemento actual3 = c_desencolar(c3);

    while (actual1 != NULL || actual2 != NULL || actual3 != NULL) {
        // Cola 1
        if (actual1 != NULL) {
            if (actual1->clave > q) {
                actual1->clave -= q;
            } else {
                char* texto = malloc(50);
                sprintf(texto, "Cliente %d Cola 1", cliente1);
                TipoElemento res = te_crear_con_valor(1, texto);
                c_encolar(resultado, res);

                cliente1++;
                actual1 = c_desencolar(c1);
            }
        }

        // Cola 2
        if (actual2 != NULL) {
            if (actual2->clave > q) {
                actual2->clave -= q;
            } else {
                char* texto = malloc(50);
                sprintf(texto, "Cliente %d Cola 2", cliente2);
                TipoElemento res = te_crear_con_valor(2, texto);
                c_encolar(resultado, res);

                cliente2++;
                actual2 = c_desencolar(c2);
            }
        }

        // Cola 3
        if (actual3 != NULL) {
            if (actual3->clave > q) {
                actual3->clave -= q;
            } else {
                char* texto = malloc(50);
                sprintf(texto, "Cliente %d Cola 3", cliente3);
                TipoElemento res = te_crear_con_valor(3, texto);
                c_encolar(resultado, res);

                cliente3++;
                actual3 = c_desencolar(c3);
            }
        }
    }

    return resultado;
}




