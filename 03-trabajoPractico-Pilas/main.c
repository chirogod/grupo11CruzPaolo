#include <stdlib.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_3_pilas.h"
#include "../libs/validaciones/headers/funciones.h"
#include <ctype.h>
int main() {
    int ejercicio;
    while (1) {
        printf("----MENU----\n");
        printf("2) Dada una pila:\n \t-buscar clave\n \t-insertar elemento\n \t-eliminar elemento\n \t-intercambiar 2 valores\n \t-duplicar pila\n \t-contar pila.\n");
        printf("3) Ver si dos pilas son exactamente iguales.\n");
        printf("4) Convertir numero decimal en otra base.\n");
        printf("5) Invertir una pila.\n");
        printf("6) Eliminar todas las ocurrencias de una pila.\n");
        printf("7) Elementos en comun entre dos pilas.\n");
        printf("8) Ver cuantas veces se repiten elementos en una pila.\n");

        ejercicio = obtener_opcion_menu();
        printf("\n");
        switch (ejercicio) {
            case 0:
                printf("\nSaliendo del programa!!!\n");
                return 0;
            case 2:
                pilasEjercicio2();
                break;
            case 3:
                pilasEjercicio3();
                break;
            case 4:
                pilasEjercicio4();
                break;
            case 5:
                pilasEjercicio5();
                break;
            case 6:
                pilasEjercicio6();
                break;
            case 7:
                pilasEjercicio7();
                break;
            case 8:
                pilasEjercicio8();
                break;
            default:
                printf("Ese ejercicio no existe, solo del 2 al 8.\n\n");
        }
    }
}
