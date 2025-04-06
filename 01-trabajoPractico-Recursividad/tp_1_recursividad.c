#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/funciones.h"
//ejercicio 1 palindromo
bool palindromo(char *cadena){
    int longitud = strlen(cadena);
    return palindromoRec(cadena,0,longitud-1);
}

// Ejercicio 2
/*2.	Dados dos n�meros enteros m y n, construir una funci�n recursiva que devuelva
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
/*3.	Generar un algoritmo recursivo que calcule el k-�simo n�mero de la serie de Fibonacci.*/
int terminoSeridFibonacci(int k){
    if(k<3){
        return k;
    }
    return terminoSeridFibonacci(k-2)+terminoSeridFibonacci(k-1);
}

//Ejercicio 4
/*4.	Dados los n�meros enteros m y n, construir una funci�n recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deber� tener en cuenta que en el caso
de que la divisi�n no sea exacta, se devolver�n hasta 4 cifras decimales (si es necesario). */
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
/*8.	Se tiene una cadena que representa una onda digital de se�ales L (Low) y H (High). Se pide mostrar
la onda que representa utilizando �_� y �|�.

Ejemplo: Si se tiene la cadena HHHHLLLLHHHHHLLHHLL, su onda digital se puede ver algo as�:
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

//Ejercicio 9
/*9. Escribir una funci�n recursiva que implemente el m�todo que se describe para saber si
un n�mero es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y as� sucesivamente,
hasta que el resultado obtenido sea un n�mero menor a 70. El n�mero original ser�
m�ltiplo de 7 si el resultado da cero o m�ltiplo de 7.
Ejemplos:
32291 -> 1x2=2.
3229 - 2 =
3227 -> 7x2=14.
322 - 14 =
308 -> 8x2=16
30 - 16 =
14 -> M�ltiplo de 7
divisiblePor7 (32291) => verdadero

110 -> 0 x 2 = 0
11 � 0 =
11 -> No m�ltiplo de 7
divisiblePor7 (110) => falso
*/
bool divisiblePor7(int n){
    if(n<70){
        return (n%7==0);
    }
    int ultimo = n%10;
    int resto = n/10;
    int reducido = resto - (ultimo*2);
    divisiblePor7(reducido);
}

//Ejercicio 10
/*
10.  Se dice que N es un n�mero explosivo cuando �ste explota en varios fragmentos m�s
chicos que �l, dada una bomba B. Si se tiene que N es el n�mero y B la bomba, tales
que N es mayor que B, se puede hacer que N explote en dos n�meros N1 = N / B
(divisi�n entera) y N2 = N - (N / B).
Pero B es una bomba que produce una reacci�n en cadena, si N1 o N2 son mayores que
B, estos tambi�n explotan con la regla anterior, hasta que se encuentre que el n�mero
no es mayor que B; entonces se dice que ya no se puede explotar el n�mero.
Escribe una funci�n recursiva que retorne una lista con los pedazos del n�mero N,
dado que se tiene la bomba B.

Ejemplos:
N�mero: 10
Bomba: 3
explosion(10, 3) => [3 2 1 1 3]
N�mero: 20
Bomba: 5
explosion(20, 5) => [4 3 2 2 1 1 1 1 5]
*/
int* explosion(int n, int b) {
    int *resultado = malloc(sizeof(int) * 100);
    int *pos = malloc(sizeof(int));
    *pos = 0;

    explosionRec(n, b, resultado, pos);

    free(pos);
    return resultado;
}
