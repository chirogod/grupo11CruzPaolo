#include <stdlib.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/funciones.h"
#include <ctype.h>
int main() {
    int ejercicio;
    while (1) {
        printf("----MENU----\n");
        printf("1) Palindromo\n");
        printf("2) Producto mediante sumas sucesivas\n");
        printf("3) Fibonacci\n");
        printf("4) Division mediante restas sucesivas\n");
        printf("5) Separador miles\n");
        printf("6) Mafia china\n");
        printf("7) Onda digital\n");
        printf("8) Subconjuntos que suman N\n");
        printf("9) Divisible por 7\n");
        printf("10) Numero explosivo\n");
        ejercicio = obtener_opcion_menu();
        printf("\n");
        switch (ejercicio) {
            case 0:
                printf("\nSaliendo del programa!!!\n");
                return 0;
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 4:
                ejercicio4();
                break;
            case 5:
                ejercicio5();
                break;
            case 6:
                ejercicio6();
                break;
            case 7:
                ejercicio7();
                break;
            case 8:
                ejercicio8();
                break;
            case 9:
                ejercicio9();
                break;
            case 10:
                ejercicio10();
                break;
            default:
                printf("Ese ejercicio no existe, solo del 0 al 10.\n\n");
        }
    }
}
