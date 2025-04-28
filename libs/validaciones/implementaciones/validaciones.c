#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../listas/headers/listas.h"
#include "../../pilas/headers/pilas.h"
int obtener_opcion_menu() {
    char entrada[100];
    int numero;

    while (1) {
        printf("Ingrese el ejercicio al que ingresar ('0' PARA SALIR): ");
        fgets(entrada, sizeof(entrada), stdin);

        entrada[strcspn(entrada, "\n")] = '\0';

        int valido = 1;
        for (int i = 0; entrada[i]; i++) {
            if (!isdigit(entrada[i])) {
                valido = 0;
                break;
            }
        }

        if (valido) {
            numero = 0;
            for (int i = 0; entrada[i]; i++) {
                numero = numero * 10 + (entrada[i] - '0');
            }

            if (numero >= 0 && numero <= 10) {
                return numero;
            }
        }

        printf("Entrada invalida. Ingrese un numero entre 0 y 10 unicamente (0 para salir).\n");
    }
}

//VALIDAR QUE UN ENTERO ESTE ENTRE DOS LIMITES
int pedirEnteroEnRango(int min, int max) {
    int numero;
    int resultado;

    do {
        printf("Ingrese un numero entre %d y %d: ", min, max);
        resultado = scanf("%d", &numero);

        // limpiar el buffer si hubo error
        while (getchar() != '\n');

        if (resultado != 1 || numero < min || numero > max) {
            printf("Entrada invalida. Intente de nuevo.\n");
        }
    } while (resultado != 1 || numero < min || numero > max);

    return numero;
}

//VALIDAR QUE UN ENTERO NO SEA 0
int pedirNumeroNoCero(char *mensaje) {
    char buffer[100];
    int numero;

    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &numero) == 1) {
                if (numero != 0) {
                    return numero;
                } else {
                    printf("El numero no puede ser 0.\n");
                }
            } else {
                printf("Entrada invalida. Ingrese un numero entero valido.\n");
            }
        }
    }
}

//validar entero
int pedirEntero(char *mensaje) {
    int numero;
    char linea[100];
    while (1) {
        printf("%s", mensaje);
        if (fgets(linea, sizeof(linea), stdin) != NULL) {
            if (sscanf(linea, "%d", &numero) == 1) {
                return numero;
            } else {
                printf("Entrada invalida. Ingrese un numero entero valido.\n");
            }
        }
    }
}

int pedirNumeroNatural(char *mensaje) {
    char linea[100];
    int num;
    char extra;

    while (1) {
        printf("%s", mensaje);

        if (fgets(linea, sizeof(linea), stdin) == NULL) {
            printf("Error al leer entrada. Intente de nuevo.\n");
            continue;
        }

        linea[strcspn(linea, "\n")] = '\0';

        if (sscanf(linea, "%d %c", &num, &extra) != 1) {
            printf("Error: Ingrese solo numeros naturales (0 o mayor).\n");
            continue;
        }

        if (num < 0) {
            printf("Error: No se permiten numeros negativos.\n");
            continue;
        }

        return num;
    }
}

int pedirNumeroNaturalNoCero(char *mensaje) {
    char linea[100];
    int num;
    char extra;

    while (1) {
        printf("%s", mensaje);

        if (fgets(linea, sizeof(linea), stdin) == NULL) {
            printf("Error al leer entrada. Intente de nuevo.\n");
            continue;
        }

        linea[strcspn(linea, "\n")] = '\0';

        if (sscanf(linea, "%d %c", &num, &extra) != 1) {
            printf("Error: Ingrese solo numeros naturales (0 o mayor).\n");
            continue;
        }

        if (num <= 0) {
            printf("Error: No se permiten numeros negativos.\n");
            continue;
        }

        return num;
    }
}

void pedirConjunto(int conjunto[], int *tamano) {
    *tamano = pedirNumeroNatural("Ingrese la cantidad de elementos del conjunto: ");

    printf("Ingrese los %d elementos separados por espacios:\n", *tamano);
    for (int i = 0; i < *tamano; i++) {
        char mensaje[50];
        sprintf(mensaje, "Elemento %d: ", i + 1);
        conjunto[i] = pedirNumeroNatural(mensaje);
    }
}

Lista llenarLista(Lista lista){
    char mensaje[100];
    int valor;
    int longitud = pedirNumeroNatural("Ingrese cuantos elementos tendra la lista: ");
    for(int i = 1; i<=longitud;i++){
        sprintf(mensaje, "Elemento[%d]: ", i);
        valor = pedirEntero(mensaje);
        TipoElemento te = te_crear(valor);
        l_agregar(lista,te);
    }
    return lista;
}

void llenarDosListas(Lista l1, Lista l2){
    printf("Ingrese dos listas para comenzar!\n");
    printf("\n----Primer lista----\n");
    llenarLista(l1);
    printf("\n----Segunda lista----\n");
    llenarLista(l2);
    printf("\n\n");
}

Lista llenarListaLong(Lista lista, int longi){
    char mensaje[100];
    int valor;
    for(int i = 1; i<=longi;i++){
        sprintf(mensaje, "Elemento[%d]: ", i);
        valor = pedirEntero(mensaje);
        TipoElemento te = te_crear(valor);
        l_agregar(lista,te);
    }
    return lista;
}

void llenarDosListasIguales(Lista l1, Lista l2){
    int longi = pedirNumeroNaturalNoCero("Para este ejercicio las listas deben tener la misma cantidad de elementos!\n Indique cuantos elementos tendran las listas: ");
    printf("\n\n");
    printf("\n----Primer lista----\n");
    llenarListaLong(l1,longi);
    printf("\n----Segunda lista----\n");
    llenarListaLong(l2,longi);
    printf("\n\n");
}

void llenarPila(Pila pila) {
    char entrada[20];
    bool continuar = true;

    while (continuar) {
        printf("Ingrese un entero o '/' para terminar: ");
        scanf("%s", entrada);
        while (getchar() != '\n');
        if (strcmp(entrada, "/") == 0) {
            continuar = false;
        } else {
            int numero;
            if (sscanf(entrada, "%d", &numero) == 1) {
                TipoElemento te = te_crear(numero);
                if (!p_apilar(pila, te)) {
                    printf("La pila esta llena. No se puede apilar mas.\n");
                    continuar = false;
                }
            } else {
                printf("Entrada invalida. Intente de nuevo.\n");
            }
        }
    }
}

int contadorElemPila(Pila pila){
    Pila paux = p_crear();
    int contador = 0;
    TipoElemento x;
    while(!p_es_vacia(pila)){
        x = p_desapilar(pila);
        contador++;
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(pila,x);
    }
    return contador;
}

Pila copiarPila(Pila pila){
    Pila pila2 = p_crear();
    Pila paux = p_crear();
    TipoElemento x;
    while(!p_es_vacia(pila)){
        x = p_desapilar(pila);
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(pila,x);
        p_apilar(pila2,x);
    }

    return pila2;
}

TipoElemento pedirTE(char *mensaje){
    int numero;
    char linea[100];
    while (1) {
        printf("%s", mensaje);
        if (fgets(linea, sizeof(linea), stdin) != NULL) {
            if (sscanf(linea, "%d", &numero) == 1) {
                TipoElemento x = te_crear(numero);
                return x;
            } else {
                printf("Entrada invalida. Ingrese un numero entero valido.\n");
            }
        }
    }

}
