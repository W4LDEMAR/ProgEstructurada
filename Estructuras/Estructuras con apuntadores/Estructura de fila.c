#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* push(int [], int *, int);
int* pop(int *, int *);
void imp(int *, int *);

int main(){

    int fila[10], *start, *end, op, n;
    start = end = &fila[0];

    do{
        system("cls");
        printf("\n1.-Push.\n2.-Pop.\n\n");
        printf("\tFILA:\n");
        imp(start, end);
        printf("\nOpcion:\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                system("cls");
                printf("Escribre el numero que deseas agregar:\n");
                scanf("%d", &n);
                end = push(fila, end, n);
                break;
            case 2:
                aux=pila;
                end = pop(start, end);
                break;
            case 3:
                system("cls");
                printf("\n***PROGRAMA TERMINADO***\n\t ADIOS");
                break;
            default:
                printf("\nERROR: Opcion no valida.");
                system("pause");
                break;
        }
    }while(op != 3);

    return 0;
}

int* push(int fila[], int *end, int n){

    if(&fila[10] == end){
        printf("\nERROR: La fila ya esta llena.");
        system("pause");
    }else{
        *end = n;
        end++;
    }

    return end;
}

int* pop(int aux[], int *start, int *end){

    int *aux, *i;

    if(start == end){
        printf("ERROR: La pila esta vacia.");
        system("pause");
    }else{
        for(i = start; i = end; i++){

        }
        end--;
    }

    return end;
}

void imp(int *start, int *end){

    int *aux;

    for(aux = start; aux < end; aux++){
        printf("[%d]", *aux);
    }
    return end;
}
