#include <stdlib.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_2_listas.h"
#include "../libs/validaciones/headers/funciones.h"
#include <ctype.h>
int main() {
    int ejercicio;
    while (1) {
        printf("----MENU----\n");
        printf("2) Dadas 2 listas (L1 y L2) generar los informes pedidos.\n");
        printf("3) Dadas 2 listas (L1 y L2) determinar si L2 es múltiplo de L1.\n");
        printf("4) Dadas dos listas (L1 y L2),  compararlas.\n");
        printf("5) Ejercicio 5.\n");
        printf("6) Dadas 2listas (L1 y L2), determinar si L2 es sublista de L1.\n");

        ejercicio = obtener_opcion_menu();
        printf("\n");
        switch (ejercicio) {
            case 0:
                printf("\nSaliendo del programa!!!\n");
                return 0;
            case 2:
                listasEjercicio2();
                break;
            case 3:
                listasEjercicio3();
                break;

            case 4:
                listasEjercicio4();
                break;
            case 5:
                listasEjercicio5();
                break;
            case 6:
                listasEjercicio6();
                break;
            default:
                printf("Ese ejercicio no existe, solo del 2 al 3.\n\n");
        }
    }
}
