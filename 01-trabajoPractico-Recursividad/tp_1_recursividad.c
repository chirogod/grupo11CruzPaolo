#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/funciones.h"
//ejercicio 1 palindromo
bool palindromo(char *cadena){
    int longitud = strlen(cadena);
    return palindromoRec(cadena,0,longitud-1);
}


// Ejercicio 2
/*2.	Dados dos números enteros m y n, construir una función recursiva que devuelva
el producto de ambos, calculando el mismo como sumas sucesivas. Esto es: m*n=m+m+...+m, n veces. */

int producto (int m, int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return m;
    }
    return m+producto(m,n-1);
}

//Ejercicio 3
/*3.	Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.*/

int terminoSeridFibonacci(int k){
    if(k<3){
        return k;
    }
    return terminoSeridFibonacci(k-2)+terminoSeridFibonacci(k-1);
}

//Ejercicio 4
/*4.	Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener en cuenta que en el caso
de que la división no sea exacta, se devolverán hasta 4 cifras decimales (si es necesario). */

float division(int m, int n) {
    if (m < n) {
        static int profundidad = 0;

        if (profundidad == 5 || m == 0) {
            profundidad = 0;
            return 0;
        }

        profundidad++;
        return 0.1 * division(m * 10, n);
    }
    return 1 + division(m - n, n);
}

//ejercicio 7
/*8.	Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se pide mostrar
la onda que representa utilizando “_” y “|”.

Ejemplo: Si se tiene la cadena HHHHLLLLHHHHHLLHHLL, su onda digital se puede ver algo así:
_ _ _ _            _ _ _ _ _      _ _
        | _ _ _ _ |         |_ _ |   | _ _

*/
//char seniales[] == char * seniales;
char * ondaDigital(char seniales[]){
    int longitud = strlen(seniales);
    char *senal;
    senal = malloc(1000);
    senal[0]= '\0';
    return ondaDigitalRec(seniales, 0, longitud-1, senal);
}
