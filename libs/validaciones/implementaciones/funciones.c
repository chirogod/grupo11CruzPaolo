#include "../headers/funciones.h"
#include <ctype.h>
#include "../headers/validaciones.h"
#include "../../../02-trabajoPractico-Listas/tp_2_listas.h"

//Ejercicio 1
bool palindromoRec(char *palabra, int inicio, int final) {
    if (inicio >= final) {
        return true;
    }
    if (palabra[inicio] != palabra[final]) {
        return false;
    }
    return palindromoRec(palabra, inicio + 1, final - 1);
}

void ejercicio1() {
    char *palabra = malloc(sizeof(char) * 100);
    if (palabra == NULL) {
        printf("Error al asignar memoria\n");
        return;
    }

    printf("Bienvenido al ejercicio del palindromo!\nIngrese la palabra a verificar: ");
    scanf("%99s", palabra);

    for (int i = 0; palabra[i]; i++) {
        palabra[i] = tolower(palabra[i]);
    }

    if (palindromo(palabra)) {
        printf("La palabra '%s' si es un palindromo\n\n", palabra);
    } else {
        printf("La palabra '%s' no es un palindromo\n\n", palabra);
    }

    printf("\n");
    free(palabra);
}

//ejercicio 2
void ejercicio2() {
    int m, n;
    printf("Bienvenido al ejercicio del producto por sumas sucesivas!\n Ingrese el multiplicando: ");
    scanf("%d", &m);
    printf("Ingrese el multiplicador: ");
    scanf("%d", &n);
    while (getchar() != '\n');  // limpiar buffer

    int original_m = m;
    int original_n = n;

    int signo = 1;
    if ((m < 0 && n > 0) || (m > 0 && n < 0)) {
        signo = -1;
    }

    if (m < 0) m = -m;
    if (n < 0) n = -n;

    int resultado = producto(m, n);
    resultado *= signo;

    printf("El resultado de multiplicar %d por %d mediante sumas sucesivas es: %d\n\n", original_m, original_n, resultado);
}

//Ejercicio 3
void ejercicio3(){
    printf("Bienvenido al ejercicio de saber el k-esimo termino de fibonacci!\n\n");
    int m = pedirEnteroEnRango(0, 30);
    int resultado = terminoSeridFibonacci(m);
    printf("El %d-termino de la serie de fibonacci es %d\n\n", m,resultado);
}
//Ejercicio 4
float divisionRec(int m, int n, int profundidad) {
    if (m < n) {
        if (profundidad == 5 || m == 0) return 0;
        return 0.1 * divisionRec(m * 10, n, profundidad + 1);
    }
    return 1 + divisionRec(m - n, n, profundidad);
}

void ejercicio4(){
    int m,n;
    printf("Bienvenido al ejercicio de division por restas sucesivas!\n");
    m = pedirEntero("Ingrese el primer factor: ");
    n = pedirNumeroNoCero("Ingrese el segundo factor(distinto de 0): ");
    float resultado = division(m, n);
    if (resultado == (int)resultado) {
        printf("El resultado de dividir %d por %d es: %d\n\n", m, n, (int)resultado);
    } else {
        printf("El resultado de dividir %d por %d es: %.5f\n\n", m, n, resultado);
    }
}

//ejercicio 5
void ejercicio5(){
    printf("No esta listo.\n\n");
}

//ejercicio6
void ejercicio6(){
    printf("Bienvenido al ejercicio de la mafia china para saber como se veria la mafia segun su nivel.\n");
    int nivel;
    nivel = pedirEnteroEnRango(1,100);
    char *vista = reunionMafia(nivel);
    printf("Nivel %d: %s\n\n", nivel, vista);
    free(vista);
}


//ejercicio7
void ejercicio7() {
    char palabra[100];
    int valida = 0;

    printf("\nBienvenido al ejercicio de onda digital!\n");


    while (!valida) {
        printf("Ingrese la cadena (solo caracteres L y H): ");
        scanf("%99s", palabra);
        valida = 1;
        for (int i = 0; palabra[i] != '\0'; i++) {
            if (palabra[i] != 'L' && palabra[i] != 'H') {
                printf("Error: Solo se permiten caracteres 'L' y 'H' en mayusculas.\n");
                valida = 0;
                break;
            }
        }
    }

    char *onda = ondaDigital(palabra);
    if (onda == NULL) {
        printf("Error generando la onda digital.\n");
        return;
    }

    printf("La onda digital es: %s\n\n", onda);
    free(onda);
}

char *ondaDigitalRec(char *palabra, int inicio, int final, char *senal) {
    if (inicio > final) {
        return senal;
    }

    if (palabra[inicio] == 'L') {
        strcat(senal, "_");
        if (palabra[inicio + 1] == 'H') {
            strcat(senal, "|");
        }
    } else if (palabra[inicio] == 'H') {
        strcat(senal, "-");
        if (palabra[inicio + 1] == 'L') {
            strcat(senal, "|");
        }
    } else {
        return NULL;
    }

    return ondaDigitalRec(palabra, inicio + 1, final, senal);
}

//ejercicio 8
void encontrarSubconjuntos(int conjunto[], int tamano, int indiceActual, int sumaActual, int objetivo, int subconjuntoTemp[], int tamSub, char **output, int *contador) {
    if (sumaActual == objetivo) {
        char *resultado = (char *)malloc(100 * sizeof(char));
        resultado[0] = '\0';
        strcat(resultado, "{");
        for (int i = 0; i < tamSub; i++) {
            char buffer[10];
            sprintf(buffer, "%d", subconjuntoTemp[i]);
            strcat(resultado, buffer);
            if (i < tamSub - 1)
                strcat(resultado, ", ");
        }
        strcat(resultado, "}");
        output[(*contador)++] = resultado;
        return;
    }

    if (indiceActual == tamano || sumaActual > objetivo)
        return;

    subconjuntoTemp[tamSub] = conjunto[indiceActual];
    encontrarSubconjuntos(conjunto, tamano, indiceActual + 1, sumaActual + conjunto[indiceActual], objetivo, subconjuntoTemp, tamSub + 1, output, contador);
    encontrarSubconjuntos(conjunto, tamano, indiceActual + 1, sumaActual, objetivo, subconjuntoTemp, tamSub, output, contador);
}
void ejercicio8(){
    int conjunto[100];
    int tamano;
    int n;
    char *resultados[101];

    pedirConjunto(conjunto, &tamano);

    n = pedirNumeroNatural("Ingrese el valor objetivo(n): ");

    subconjuntosQueSumanN(conjunto, tamano, n, resultados);

    printf("Subconjuntos que suman %d:\n\n", n);
    for (int i = 0; resultados[i] != NULL; i++) {
        printf("%s\n", resultados[i]);
        free(resultados[i]);
    }
}

//Ejercicio 9
void ejercicio9(){
    int n;
    printf("Bienvenido al ejercicio de divisible por 7!\n");
    n = pedirEntero("Ingrese el numero a saber si es multiplo de 7: ");
    if(divisiblePor7(n)){
        printf("'%d' SI es divisible por 7\n\n", n);
    }else{
        printf("'%d' NO es divisible por 7\n\n", n);
    }
}

//Ejercicio 10
void ejercicio10(){
    int n, b;
    printf("Bienvenido al ejercicio del numero explosivo!\n");
    n = pedirNumeroNatural("Ingrese el numero: ");
    b = pedirEnteroEnRango(0,n-1);

    int *resultado = explosion(n, b);
    printf("[");
    for (int i = 0; i < 100 && resultado[i] != 0; i++) {
        printf(" %d ", resultado[i]);
    }
    printf("]\n\n");
}
void explosionRec(int n, int b, int *resultado, int *pos) {
    if (n <= b) {
        resultado[(*pos)++] = n;
    } else {
        int n1 = n / b;
        int n2 = n - n1;
        explosionRec(n1, b, resultado, pos);
        explosionRec(n2, b, resultado, pos);
    }
}



///////////////////// TP2 LISTAS
void listasEjercicio2(){
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    llenarDosListas(l1,l2);

    printf("Elementos de L2 que no estan en L1: \n");
    Lista listaNoEstan = verElementosQueNoSeRepiten(l1, l2);
    l_mostrar(listaNoEstan);

    printf("\nElementos de L1 que no estan en L2: \n");
    listaNoEstan = verElementosQueNoSeRepiten(l2, l1);
    l_mostrar(listaNoEstan);

    printf("\nElementos repetidos en ambas listas: \n");
    Lista listaComunes = verElementosRepetidos(l1,l2);
    l_mostrar(listaComunes);

    float prom = promedio(l1);
    printf("\nPromedio primer lista: %f\n", prom);

    prom = promedio(l2);
    printf("\nPromedio segunda lista: %f\n", prom);

    ResultadoValorMinimo resultado = valorMinimo(l1,l2);
    printf("\nEl valor minimo de la primer lista es: %d y su posicion es la: %d\n", resultado.valor, resultado.pos);
    printf("\nEl valor minimo de la segunda lista es: %d y su posicion es la: %d\n", resultado.valor_2, resultado.pos_2);

    printf("\n\n");


}

void listasEjercicio3(){
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    llenarDosListas(l1,l2);

    ResultadosMul resultado = multiplo(l1,l2);

    if(resultado.esMultiplo){
        printf("L2 es multiplo de L1");
        if(resultado.escalar){
            printf(" y por un escalar: %d\n\n", resultado.numEscalar);
        }else{
            printf(" pero no por un escalar.\n\n");
        }
    }else{
        printf("L2 NO es multiplo de L1\n\n");
    }
}

void listasEjercicio4(){
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    llenarDosListas(l1,l2);

    int resultado = CompararListas(l1,l2);
    if(resultado == 1){
        printf("L1 es mayor que L2!!");
    }else if(resultado == 2){
        printf("L2 es mayor que L1!!");
    }else{
        printf("L1 y L2 son iguales!!");
    }
    //FALTA DETERMINAR COMPLEJIDAD----------------------------------------------IMPORTANTE
    printf("\n\n");
}

void listasEjercicio5(){
    printf("No esta listo!!");
}

void listasEjercicio6(){
    Lista l1 = l_crear();
    Lista l2 = l_crear();
    llenarDosListas(l1,l2);

    bool resultado = esSublista(l1,l2);
    if(resultado){
        printf("L2 es sublista de L1");
    }else{
        printf("L2 NO es sublista de L1");
    }
    //FALTA DETERMINAR COMPLEJIDAD----------------------------------------------IMPORTANTE
    printf("\n\n");
}
