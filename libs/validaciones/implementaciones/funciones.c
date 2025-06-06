#include "../headers/funciones.h"
#include <ctype.h>
#include "../headers/validaciones.h"
#include "../../../02-trabajoPractico-Listas/tp_2_listas.h"
#include "../../../03-trabajoPractico-Pilas/tp_3_pilas.h"
#include "../../../04-trabajoPractico-Colas/tp_4_colas.h"

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
    if(resultado.pos != -1){
        printf("\nEl valor minimo de la primer lista es: %d y su posicion es la: %d\n", resultado.valor, resultado.pos);
    }
    if(resultado.pos_2 != -1){
        printf("\nEl valor minimo de la segunda lista es: %d y su posicion es la: %d\n", resultado.valor_2, resultado.pos_2);
    }

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
    llenarDosListasIguales(l1,l2);

    int resultado = CompararListas(l1,l2);
    if(resultado == 1){
        printf("L1 es mayor que L2!!");
    }else if(resultado == 2){
        printf("L2 es mayor que L1!!");
    }else{
        printf("L1 y L2 son iguales!!");
    }
    printf("\nCOMPLEJIDAD ALGORITMICA: Al recorrer dos listas que tienen la misma cantidad de elementos 'n' y se recorre una unica vez cada lista, esta funcion tiene una complejidad lineal 'O(n)'. ");
    printf("\n\n");
}

void listasEjercicio5(){
    printf("No esta listo!!\n\n");
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
    printf("\nCOMPLEJIDAD ALGORITMICA: Esta funcion tiene una complejidad de O(m*n) ya que se recorre todos los elementos de L2 y por cada vez hace una busqueda en L1. ");
    printf("\n\n");
}

///////////////////////////////////////TP3 PILAS
void pilasEjercicio2(){
    Pila p = p_crear();
    printf("Cargar pila:\n");
    llenarPila(p);
    int longitud = contadorElemPila(p);
    int clave2a = pedirEntero("\nIngrese la clave a buscar: ");
    if(p_ej2_existeclave(p,clave2a)){
        printf("\nLa clave '%d' SI existe en la pila!\n\n",clave2a);
    }else{
        printf("\nLa clave '%d' NO existe en la pila!\n\n",clave2a);
    }

    printf("Ahora para el ejercicio 2b, se colocara en una posicion ordinal dada, un elemento dado: \n");
    int posicionordinal = pedirEnteroEnRango(1,longitud);
    TipoElemento elem2b = pedirTE("Ingrese el elemento a agregar: ");
    Pila pila2b = p_ej2_colocarelemento(p,posicionordinal,elem2b);
    printf("La pila con el nuevo elemento: ");
    p_mostrar(pila2b);
    printf("La pila original sin perderse: ");
    p_mostrar(p);
    printf("\n\n");

    printf("Ahora para el ejercicio 2c, se eliminar la primer ocurrencia de una clave dada: \n");
    int clave2c = pedirEntero("Clave a eliminar: ");
    Pila p2c = p_ej2_eliminarclave(p,clave2c);
    printf("La pila con la clave eliminada: ");
    p_mostrar(p2c);
    printf("La pila original sin perderse: ");
    p_mostrar(p);
    printf("\n\n");

    printf("Ahora para el ejercicio 2e, se duplicara la pila: \n");
    Pila p2e = p_ej2_duplicar(p);
    printf("La copia de la pila: ");
    p_mostrar(p2e);
    printf("La pila original sin perderse: ");
    p_mostrar(p);
    printf("\n\n");

    printf("Ahora para el ejercicio 2f, se contaran los elementos de la pila: \n");
    int elementosPila1 = p_ej2_cantidadelementos(p);
    printf("Elementos: %d\n", elementosPila1);
    p_mostrar(p2e);
    printf("La pila original sin perderse: ");
    p_mostrar(p);
    printf("\n\n");
}

void pilasEjercicio3(){
    printf("Ejercicio de comparar pilas por su clave!\n\n");
    Pila p1 = p_crear();
    printf("Cargar primer pila:\n");
    llenarPila(p1);
    Pila p2 = p_crear();
    printf("Cargar segunda pila:\n");
    llenarPila(p2);
    printf("\n\npilas originales\n");
    p_mostrar(p1);
    p_mostrar(p2);
    int longp1 = contadorElemPila(p1);
    int longp2 = contadorElemPila(p2);
    bool resultado = false;
    if(longp1==longp2){
        resultado = p_ej3_iguales(p1,p2);
    }
    if(resultado){
        printf("Las pilas son exactamente iguales!");
    }else{
        printf("Las pilas son diferentes!");
    }
    printf("\n\npilas originales sin perderse\n");
    p_mostrar(p1);
    p_mostrar(p2);
    printf("\n\nComplejidad Algoritmica: O(n) , n es el numero de elementos de las pilas, teniendo ambas la misma cantidad.\n");
    printf("\n\n");
}

void pilasEjercicio4(){
    printf("Ejercicio 4: Convertir numero entero en base decimal en la base deseada.\n\n");
    char* res;
    int decimal, base;
    decimal = pedirEntero("Ingrese numero a convertir: ");
    printf("\nIngrese base: ");
    base = pedirEnteroEnRango(2,16);
    res = p_ej4_cambiarbase(decimal, base);
    printf("\n'%d' en base '%d' es: %s\n",decimal,base,res);
    printf("\nComplejidad algoritmica: O(log(n))\n\n");
}

void pilasEjercicio5(){
    printf("En este ejercicio vamos a invertir una pila!\nIngresar la pila: \n\n");
    Pila p = p_crear();
    llenarPila(p);
    printf("\n");
    p_mostrar(p);
    printf("\n");
    Pila resultado = p_ej5_invertir(p);
    printf("Pila invertida: \n");
    p_mostrar(resultado);
    printf("\nPila original: \n");
    p_mostrar(p);
    printf("\nComplejidad Algoritmica: O(n) , n es el numero de elementos de la pila.\n");
    printf("\n\n");
}

void pilasEjercicio6(){
    printf("En este ejercicio vamos a eliminar todas las ocurrencias de una clave en una pila!\nIngresar la pila: \n\n");
    Pila p = p_crear();
    llenarPila(p);
    printf("\n");
    p_mostrar(p);
    printf("\n");
    int clave = pedirEntero("Ingresa la clave a eliminar todas las ocurrencias: ");
    printf("\n");
    Pila resultado = p_ej6_eliminarclave(p,clave);
    printf("Pila sin las claves: \n");
    p_mostrar(resultado);
    printf("\nPila original: \n");
    p_mostrar(p);
    printf("\nComplejidad Algoritmica: O(n) .\n");
    printf("\n\n");

}

void pilasEjercicio7(){
    printf("Ejercicio de ver elementos en comun de dos pilas!\n\n");
    Pila p1 = p_crear();
    printf("Cargar primer pila:\n");
    llenarPila(p1);
    Pila p2 = p_crear();
    printf("\nCargar segunda pila:\n");
    llenarPila(p2);
    printf("\n\npilas origins\n");
    p_mostrar(p1);
    p_mostrar(p2);
    Pila resultado = p_ej7_elementoscomunes(p1,p2);
    printf("\n\nElementos en comun: \n");
    p_mostrar(resultado);
    printf("\n\nComplejidad algoritmica: O(n*m) donde n es el numero de elementos de la primer pila, y m es el numero de elementos de la segunda pila.\n");
    printf("\n\npilas origins\n");
    p_mostrar(p1);
    p_mostrar(p2);
    printf("\n\n");
}

void pilasEjercicio8(){
    printf("Ejercicio de contar elementos repetidos!\n\n");
    Pila p1 = p_crear();
    printf("Cargar pila:\n");
    llenarPila(p1);
    p_mostrar(p1);
    Pila resultado = p_ej8_sacarrepetidos(p1);
    printf("\n\nElementos repetidos: \n");
    p_mostrar(resultado);
    printf("\n\nComplejidad algoritmica: .\n");
    printf("\n\nPila original\n");
    p_mostrar(p1);
    printf("\n\n");
}

/*--------------------COLAS-------------------*/
void colasEjercicio2(){
    printf("Bienvenido al ejercicio 2! Primero ingrese la cola: \n");
    Cola cola = c_crear();
    llenarCola(cola);
    c_mostrar(cola);
    int longitud = longitudCola(cola);
    printf("\na)Ingresar un elemento para ver si se encuentra en la cola!\n");
    int elemento = pedirEntero("Ingresar la clave a buscar: ");
    bool encontrado = c_ej2_existeclave(cola,elemento);
    if(encontrado){
        printf("La clave '%d' SI existe en la cola!!",elemento);
    }else{
        printf("La clave '%d' NO existe en la cola!!",elemento);
    }
    printf("\n\n");
    printf("\nb)Ahora agregar un elemento en una posicion!");
    if(!c_es_llena(cola)){
        TipoElemento elementoAgregar = pedirTE("\nElemento a agregar: ");
        int posicion = pedirEnteroEnRango(1,longitud+1);
        Cola agregar = c_ej2_colarelemento(cola,posicion,elementoAgregar);
        printf("\nCola con el elemento agregado: \n");
        c_mostrar(agregar);
        printf("\nCola original: \n");
        c_mostrar(cola);
    }else{
        printf(" Pero la cola esta llena no se podra encolar otro elemento.\n\n");
    }

    printf("c) Dado un elemento sacarlo todas las veces que aparezca en la cola!\n");
    int claveEliminar = pedirEntero("Clave a eliminar: ");
    Cola sinClave = c_ej2_sacarelemento(cola,claveEliminar);
    printf("Cola sin la clave dada:\n");
    c_mostrar(sinClave);
    printf("\nCola original:\n");
    c_mostrar(cola);

    printf("d) Contar los elementos de la cola!\n");
    int elementosCola = c_ej2_contarelementos(cola);
    printf("La cola tiene %d elementos.\n", elementosCola);
    printf("\nCola original:\n");
    c_mostrar(cola);

}

void colasEjercicio3(){
    printf("Para este ejercicio, dada dos colas, determinaremos si son iguales!\nIngrese la primer cola:\n");
    Cola c1 = c_crear();
    llenarCola(c1);
    c_mostrar(c1);
    printf("\nLlene la segunda cola:\n");
    Cola c2 = c_crear();
    llenarCola(c2);
    c_mostrar(c2);
    bool resultado = c_ej3_iguales(c1,c2);
    if(resultado){
        printf("Las colas son iguales!!\n");
    }else{
        printf("Las colas NO son iguales!!\n");
    }
    printf("\nColas originales:\n");
    c_mostrar(c1);
    c_mostrar(c2);
    printf("\nLa funcion tiene una complejidad algoritmica de O(n).\n\n");
}

void colasEjercicio4(){
    printf("Para este ejercicio, dada una cola, generaremos otra con los elementos no repetidos!\nIngrese la cola:\n");
    Cola cola = c_crear();
    llenarCola(cola);
    c_mostrar(cola);
    Cola res = c_ej4_colanorepetidos(cola);
    printf("Cola de los no repetidos: \n");
    c_mostrar(res);
    printf("\nCola original: \n");
    c_mostrar(cola);
    printf("\nLa funcion tiene una complejidad algoritmica de O(n^2)\n\n");
}

void colasEjercicio5(){
    printf("Para este ejercicio, dada una cola(de elementos mayores a 2 y no repetidos!!!)\nobtendremos los divisores totales o parciales que haya.\nLlenar la cola: \n");
    Cola cola = c_crear();
    llenarCola(cola);
    c_mostrar(cola);
    Cola res = c_ej5_divisortotal(cola);
    printf("Divisores parciales y/o totales: \n");
    c_mostrar(res);
    printf("\nCola original: \n");
    c_mostrar(cola);
    printf("\nLa funcion tiene una complejidad algoritmica de O(n^2)\n\n");
}

void colasEjercicio6(){
    printf("Para este ejercicio, dada una pila y una cola determinar elementos en comun y en que posiciones se encontraron .\nLlenar la pila: \n");
    Pila pila = p_crear();
    llenarPila(pila);
    p_mostrar(pila);
    Cola cola = c_crear();
    llenarCola(cola);
    c_mostrar(cola);

    Lista res = c_ej6_comunesapilaycola(pila,cola);
    mostrar_lista_posiciones(res);
    printf("\nCola original: \n");
    c_mostrar(cola);
    printf("\nPila original: \n");
    p_mostrar(pila);
    printf("\nLa funcion tiene una complejidad algoritmica de O(n*m)\n\n");
}

void colasEjercicio7(){
    printf("Para este ejercicio, dada tres colas y `q` cantidad de minutos,\ninformar el orden en que fueron atendidos los clientes\n\n");
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();
    printf("Primer cola:\n");
    llenarCola(c1);
    printf("Segunda cola:\n");
    llenarCola(c2);
    printf("Tercer cola:\n");
    llenarCola(c3);
    int tiempo = pedirNumeroNatural("Ingresar tiempo(>0): ");
    Cola res = c_ej7_atenderclientes(c1,c1,c3,tiempo);
    c_mostrar(res);
}
