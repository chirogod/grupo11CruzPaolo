#include <stdlib.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_4_colas.h"
#include "../libs/validaciones/headers/funciones.h"
#include <ctype.h>
int main() {
    int ejercicio;
    while (1) {
        printf("----MENU----\n");
        printf("2) Dada una cola:\n \t-buscar elemeno\n \t-Agregar elemento en una posicion\n \t-Eliminar elemento todas las veces que aparezca\n \t-Contar elementos de la cola\n \t-Duplicar cola\n \t-Invertir cola.\n");
        printf("3) Dadas dos colas, determinar si son iguales.\n");
        printf("4) Dada una cola, recuperar los elementos no repetidos.\n");
        printf("5) Dada una cola, determinar divisores parciales y/o totales de los elementos.\n");
        printf("6) Dada un pila y una cola, retornar lista con valores comunes entre ellas y en que posicion estan.\n");
        printf("7) Dadas tres colas, determinar en que orden fueron atendidos los clientes de cada una.\n");

        ejercicio = obtener_opcion_menu();
        printf("\n");
        switch (ejercicio) {
            case 0:
                printf("\nSaliendo del programa!!!\n");
                return 0;
            case 2:
                colasEjercicio2();
                break;
            case 3:
                colasEjercicio3();
                break;
            case 4:
                colasEjercicio4();
                break;
            case 5:
                colasEjercicio5();
                break;
            case 6:
                colasEjercicio6();
                break;
            case 7:
                colasEjercicio7();
                break;

            default:
                printf("Ese ejercicio no existe, solo del 2 al 2.\n\n");
        }
    }
}
