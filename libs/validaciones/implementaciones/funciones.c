#include "../headers/funciones.h"
bool palindromoRec(char *palabra, int inicio, int final){
    if(inicio>= final){
        return true;
    }
    if(palabra[inicio]!=palabra[final]){
        return false;
    }
    return palindromoRec(palabra, inicio+1, final-1);
}

void ejercicio1(){
    char *palabra;
    palabra = malloc(sizeof(char)*10);
    printf("Bienvenido al ejercicio del palindromo!\n Ingrese la palabra a verificar: ");
    scanf("%s", palabra);
    if(palindromo(palabra)){
        printf("La palabra '%s' si es un palindromo\n", palabra);
    }else{
        printf("La palabra '%s' no es un palindromo\n", palabra);
    }printf("\n");
    free(palabra);
}

void ejercicio2(){
    int m,n;
    printf("Bienvenido al ejercicio del producto por sumas sucesivas!\n Ingrese el multiplicando: ");
    scanf("%d", &m);
    printf("Ingrese el multiplicador: ");
    scanf("%d", &n);
    int resultado = producto(m,n);
    printf("El resultado de multiplicar %d por %d mediante sumas sucesivas es: %d\n\n",m,n,resultado);
}

void ejercicio3(){
    int m;
    printf("Bienvenido al ejercicio del termino de fibonacci!\n Ingrese el termino a saber: ");
    scanf("%d", &m);
    int resultado = terminoSeridFibonacci(m);
    printf("El %d-termino de la serie de fibonacci es %d\n\n", m,resultado);
}

void ejercicio4(){
    int m,n;
    printf("Bienvenido al ejercicio de division por restas sucesivas!\n Ingrese el primer factor: ");
    scanf("%d", &m);
    printf("Ingrese el segundo factor: ");
    scanf("%d", &n);
    float resultado = division(m, n);
    if (resultado == (int)resultado) {
        printf("El resultado de dividir %d por %d es: %d\n", m, n, (int)resultado);
    } else {
        printf("El resultado de dividir %d por %d es: %.5f\n", m, n, resultado);
    }
}


//ejercicio7
void ejercicio7(){
    char *palabra;
    palabra = malloc(100*10);
    printf("\nBienvenido al ejercicio de onda digital!\nIngrese la cadena (solo caracteres L y H): ");
    scanf("%99s", palabra);

    char *onda = ondaDigital(palabra);
    printf("La onda digital es: %s\n", onda);
}
char* ondaDigitalRec(char *palabra, int inicio, int final, char *senal){
    if(inicio>final){
        return senal;
    }
    if(palabra[inicio]=='L'){
        strcat(senal, "_");
        if(palabra[inicio+1]=='H'){
            strcat(senal, "|");
        }
    }else if(palabra[inicio]=='H'){
        strcat(senal, "-");
        if(palabra[inicio+1]=='L'){
            strcat(senal, "|");
        }
    }else{
        printf("Solo ingresar L y H en cadena y mayusculas.");
        ejercicio7();
    }
    return ondaDigitalRec(palabra,inicio+1, final, senal);
}
