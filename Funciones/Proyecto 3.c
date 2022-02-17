/*
    Practica 3

Limon Escamilla Carlos Alberto
Sanchez Ortiz Karla Gabriela
Sosa Hernandez Saul Waldemar
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define maxent 10
#define maxch 50

void inicio();
long int factorial();
int primo();
long int potencia();
void arreglo_ran();
int buscador();

int main(){

    int enteros[maxent], correr = 1, opc, n, p;
    char arr_c[maxch];

    while(correr != 0){
        inicio();
        scanf("%d", &opc);
        if(opc == 1){
            printf("\n\nIngresa el numero del que quieres conocer su factorial:\n");
            fflush(stdin);
            scanf("%d", &n);
            printf("El factorial de %d es %d.", n, factorial(n));
        }else if(opc == 2){
            printf("\n\nIngresa un numero para saber si es primo o no: \n");
            fflush(stdin);
            scanf("%d", &n);
            if(primo(n) == 0){
                printf("El numero ingresado no es primo.");
            }else{
                printf("El numero ingresado es primo.");
            }
        }else if(opc == 3){
            printf("\n\nIngresa el numero que quieres elevar:\n");
            fflush(stdin);
            scanf("%d", &n);
            printf("Ingresa la potencia a la que lo quieres elevar:\n");
            fflush(stdin);
            scanf("%d", &p);
            printf("El numero %d elevado a la %d potencia es %d.", n, p,  potencia(n, p));
        }else if(opc == 4){
            printf("El arreglo de numeros aleatorio es:\n ");
            arreglo_ran_ent(enteros);
            arreglo_ran_ent_imp(enteros);
            printf("\n\nIngresa el numero que deseas buscar: \n");
            fflush(stdin);
            scanf("%d", &n);
            if(buscador(n, enteros) < 0){
                printf("El numero %d no esta dentro del arreglo de numeros aleatorios.", n);
            }else{
                printf("El numero %d se encuentra dentro el arreglo en la posicion %d", n, buscador(n, enteros) + 1);
            }
        }
        printf("\n\n\t\tDeseas realizar otra operacion?");
        printf("\n\t\tSI = 1      NO = 0\n");
        fflush(stdin);
        scanf("%d", &correr);
    }


    return 0;
}

void inicio(){
    printf("\t***Seleccione la opcion deseada***\n");
    printf("1. Factorial de un numero\n");
    printf("2. Saber si un numero es primo\n");
    printf("3. Calcular un numero elevado a otro (potencia)\n");
    printf("4. Buscar un numero dentro de un arreglo aleatorio\n");
    printf("\t *Inserta el numero de la opcion seleccioanda: \n");
}

long int factorial(int n){

    if(n == 0){
        return 1;
    }else{
        return(n * factorial(n-1));
    }
}

int primo(int n){

    if(n % 2 == 0){
        return 0;
    }else{
        return 1;
    }
}

long int potencia(int n, int p){

    int n1 = n;

    while(p != 1){
        n = n * n1;
        p--;
    }
    return n;

}

void arreglo_ran_ent(int enteros[]){

    int cont;

    for(cont = 0; cont < maxent; cont++){
        enteros[cont] = rand() % 26;
    }
}

void arreglo_ran_ent_imp(int enteros[]){
    int cont;

    for(cont = 0; cont < maxent; cont++){
        printf("[%d]", enteros[cont]);
    }
}

int buscador(int valor, int enteros[]){

    int cont = 0;

    while(cont < maxent){
        if(enteros[cont] == valor){
            return cont;
        }else{
            cont++;
        }
    }
    return -1;
}

