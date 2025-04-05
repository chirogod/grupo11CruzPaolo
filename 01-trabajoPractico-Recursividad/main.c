#include <stdlib.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/funciones.h"
int main(){
    int ejercicio;
    while(1){
        printf("Ingrese el ejercicio al que ingresar: ");
        scanf("%d", &ejercicio);
        if(ejercicio == 1){
            ejercicio1();
        }else if(ejercicio==2){
            ejercicio2();
        }else if(ejercicio==3){
            ejercicio3();
        }else if(ejercicio==4){
            ejercicio4();
        }else if(ejercicio==7){
            ejercicio7();
        }
    }
}
