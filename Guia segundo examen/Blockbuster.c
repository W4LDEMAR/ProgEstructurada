/*
Guia para segundo examen.
Ejercicio 1: Utilizar estructuras para llevar el control de estantes de peliculas dentro de una tienda.
Sosa Hernandez Saul Waldemar
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char titulo[50];
    int ano;
    float precio;
} Pelicula;

typedef struct{
    Pelicula arrP[10];
    char genero[20];
    int n_peliculas;
} Estante;

Pelicula nuevaPeli();
Estante nuevoEstante();
int elimEstante(int);
void impEstante(Estante, int);
void impPeli(Estante, int);

int main(){

    Estante E[5];
    int op = 1, cont = 0, i, n, x;

    while(op != 0){
        system("cls");
        printf("\t\t*** BLOCKBUSTER ***\n");
        printf("1.- Dar de alta un estante.\n2.- Dar de baja un estante.\n3.- Imprimir la informacion de un estante.\n4.- Acciones con peliculas.\n0.- Terminar el programa.\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                if(cont >= 5){
                    printf("¡¡ Has llegado al maximo de estantes desponibles !!");
                }else{
                    E[cont] = nuevoEstante();
                    cont++;
                }
                break;
            case 2:

                n = elimEstante(cont);
                E[n] = E[cont];
                cont--;
                printf("Se elimino el estante de manera exitosa!");
                break;

            case 3:

                system("cls");
                printf("Selecciona el estante que deseas:\n");
                fflush(stdin);

                for(i = 0; i < cont; i++){
                    printf("%d.- %s \n", i + 1, E[i].genero);
                }
                scanf("%d", &n);

                if((n-1) > cont || (n-1) <= 0){
                    printf("ERROR: Seleccion invalida.");
                    system("pause");
                }else{
                    impEstante(E[n-1], n);
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                printf("1.- Eliminar pelicula de un estante.\n2.- Agregar pelicula a un estante");
                fflush(stdin);
                scanf("%d", &x);

                if(x == 1 || x == 2){
                    if(x == 1){
                        //funcion para eliminar
                    }else{
                        //funcion para agregar
                    }
                }else{
                    printf("ERROR: Seleccion invalida.");
                }
                break;

        }
    }

    return 0;
}

Pelicula nuevaPeli(){

    Pelicula peli;

    system("cls");
    printf("Introduce el titulo de la pelicula: \n");
    fflush(stdin);
    gets(peli.titulo);
    printf("Introduce el anio de la pelicula: \n");
    fflush(stdin);
    scanf("%d", &peli.ano);
    printf("Introduce el precio de la pelicula: \n");
    fflush(stdin);
    scanf("%f", &peli.precio);

    return peli;
}

Estante nuevoEstante(){

    Estante nuevo;

    int i;

    system("cls");
    printf("Introduce el genero de las peliculas:\n");
    fflush(stdin);
    gets(nuevo.genero);
    printf("¿Cuantas peliculas tendra el estante?\n");
    fflush(stdin);
    scanf("%d", &nuevo.n_peliculas);

    for(i = 0; i < nuevo.n_peliculas; i++){
        nuevo.arrP[i] = nuevaPeli();
    }

    return nuevo;
}

int elimEstante(int c){

    int n;

    system("cls");
    printf("Elige el esatnte que deseas eliminar: \n");
    fflush(stdin);
    scanf("%d", &n);

    if(n > c || n < 0){
        printf("\nERROR: Elige una opcion valida");
        n = elimEstante(c);
    }

    return n;
}

void impEstante(Estante E, int n){

    int i;

    system("cls");
    printf("\tINFORMACION DEL ESTANTE %d \n", n);
    printf("Genero: %s \n", E.genero);
    printf("Numero de peliculas: %d", E.n_peliculas);
    printf("Las peliculas son: \n");

    for(i = 0; i < E.n_peliculas; i ++){
        printf("%d.- %s \n", i, E.arrP[i].titulo);
    }
}

void impPeli(Estante E, int n){

    system("cls");
    printf("\tINFORMACION DE LA PELICULA %d \n", n);
    printf("Titulo: %s \n", E.arrP[n].titulo);
    printf("Ano: %d", E.arrP[n].ano);
    printf("Precio: %f", E.arrP[n].precio);

}


