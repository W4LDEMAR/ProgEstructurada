/*
    Practica 2

Limon Escamilla Carlos Alberto
Sanchez Ortiz Karla Gabriela
Sosa Hernandez Saul Waldemar
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define maxp 2
#define maxr 4
#define maxc 5

void resultados();

int main(){

    int a[maxp][maxr][maxc], b;
    int p, r, c, x, e1, e2;

    printf("Multiplo de la primera cara: \n");
    scanf("%i", &e1);
    printf("Multiplo de la segunda cara: \n");
    fflush(stdin);
    scanf("%i", &e2);

    for(p = 0; p < maxp; p++){
        for(r = 0; r < maxr; r++){
            for(c = 0; c < maxc; c++){
                if(p == 0){
                    do{
                        x = 1 + rand()%998;
                    }while(x % e1 != 0);
                    a[p][r][c] = x;
                }else{
                    do{
                        x = 1 + rand() % 998;
                    }while(x % e2 != 0);
                    a[p][r][c] = x;
                }
            }
        }
    }
    printf("\tLas matrices son:\n");
    resultados(a);

    int cont = 0;
    while(cont != 20){
        for(p = 0; p < maxp; p++){
            for(r = 0; r < maxr; r++){
                for(c = 0; c < maxc; c++){
                    if(p == 0){
                        if(a[p][r][c] < a[p][r][c+1]){
                            b = a[p][r][c+1];
                            a[p][r][c+1] = a[p][r][c];
                            a[p][r][c] = b;
                        }
                    }else{
                        if(a[p][r][c] > a[p][r][c+1]){
                            b = a[p][r][c+1];
                            a[p][r][c+1] = a[p][r][c];
                            a[p][r][c] = b;
                        }
                    }
                }
            }
        }
        cont++;
    }

    printf("\n\tLas matrices en orden son: \n");
    resultados(a);

    return 0;
}

void resultados(int a[maxp][maxr][maxc]){

    int p, r, c;

    for(p = 0; p < maxp; p++){
        for(r = 0; r < maxr; r++){
            for(c = 0; c < maxc; c++){
                printf("[%3d]", a[p][r][c]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}
