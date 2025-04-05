#include <stdlib.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/funciones.h"
int main(){
    int ejercicio;
    while(1){
        printf("----MENU----\n");
        printf("1)Palindromo\n");
        printf("2)Producto mediante sumas sucesivas\n");
        printf("3)Fibonacci\n");
        printf("4)Division mediante restas sucesivas\n");
        printf("7)Onda digital\n");
        printf("Ingrese el ejercicio al que ingresar('0' PARA SALIR): ");
        scanf("%d", &ejercicio);
        switch(ejercicio){
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
            case 7:
                ejercicio7();
                break;
            default:
                printf("Ese ejercicio no existe, solo del 1 al 10.");

        }

    }
}
