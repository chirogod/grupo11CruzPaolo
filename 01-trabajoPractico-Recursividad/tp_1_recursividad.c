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
    // Manejo de signos
    int signo = 1;
    if (m < 0 && n > 0) signo = -1;
    else if (m > 0 && n < 0) signo = -1;

    // Convertir ambos a positivos
    m = m < 0 ? -m : m;
    n = n < 0 ? -n : n;

    float resultado = divisionRec(m, n, 0);
    return signo * resultado;
}

//Ejercicio 6
/*6.	Se conoce que la mafia china es muy organizada y protege mucho a sus miembros, cuando deciden asistir
a una reuni�n se dispone de una cantidad de chinos que asisten, y ellos se ubican de forma que al mirarlos
frontalmente generan cierto respeto y temor. A continuaci�n, se tiene una serie de posibles reuniones y su
nivel y la apariencia que se tiene del grupo que va a la reuni�n vistos frontalmente:

Nivel reuni�n	Vista frontal de la delegaci�n
		1 	        (-.-)
		2 		 (-.(-.-).-)
		3 	  (-.(-.(-.-).-).-)
		4  (-.(-.(-.(-.-).-).-).-)

*/

char* reunionMafia(int nivel) {
    if (nivel == 1) {
        char* base = (char*)malloc(6);
        strcpy(base, "(-.-)");
        return base;
    } else {
        char* inner = reunionMafia(nivel - 1);
        int len = strlen(inner) + 6;
        char* result = (char*)malloc(len);

        strcpy(result, "(-.");
        strcat(result, inner);
        strcat(result, ".-)");

        free(inner);

        return result;
    }
}

//ejercicio 7
/*7.	Se tiene una cadena que representa una onda digital de se�ales L (Low) y H (High). Se pide mostrar
la onda que representa utilizando �_� y �|�.

Ejemplo: Si se tiene la cadena HHHHLLLLHHHHHLLHHLL, su onda digital se puede ver algo as�:
_ _ _ _            _ _ _ _ _      _ _
        | _ _ _ _ |         |_ _ |   | _ _

*/
//char seniales[] == char * seniales;
char* ondaDigital(char seniales[]) {
    int longitud = strlen(seniales);
    char *senal = malloc(1000);
    if (!senal) return NULL;
    senal[0] = '\0';

    return ondaDigitalRec(seniales, 0, longitud - 1, senal);
}

//Ejercicio 8
/*8.	Definir una funci�n recursiva que dado un conjunto devuelva una lista con los subconjuntos del mismo
tales que la suma de los elementos de cada subconjunto sumen una cantidad dada.
Por ejemplo:   Dado el conjunto A = {10, 3, 1, 7, 4, 2}. La lista de los conjuntos que sumen 7 ser�a:
R = [{3, 4}, {1, 4, 2}, {7}]*/
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output) {
    static int contadorInterno;
    contadorInterno = 0;
    int temp[100];

    encontrarSubconjuntos(conjunto, tamano, 0, 0, n, temp, 0, output, &contadorInterno);

    output[contadorInterno] = NULL;
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
    return divisiblePor7(reducido);
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
    int *resultado = calloc(100, sizeof(int));
    int *pos = malloc(sizeof(int));
    *pos = 0;

    explosionRec(n, b, resultado, pos);

    free(pos);
    return resultado;
}
