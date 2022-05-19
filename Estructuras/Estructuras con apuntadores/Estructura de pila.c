#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* push(int [], int *, int);
int* pop(int *, int *);
void imp(int *, int *);

int main(){

    int pila[10], *start, *end, op, n;
    start = end = &pila[0];

    do{
        system("cls");
        printf("\n1.-Push.\n2.-Pop.\n\n");
        printf("\tPILA:\n");
        imp(start, end);
        printf("\nOpcion:\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                system("cls");
                printf("Escribre el numero que deseas agregar:\n");
                scanf("%d", &n);
                end = push(pila, end, n);
                break;
            case 2:
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

int* push(int pila[], int *end, int n){

    if(&pila[10] == end){
        printf("\nERROR: La pila ya esta llena.");
        system("pause");
    }else{
        *end = n;
        end++;
    }

    return end;
}

int* pop(int *start, int *end){
    if(start == end){
        printf("ERROR: La pila esta vacia.");
        system("pause");
    }else{
        end--;
    }

    return end;
}

void imp(int *start, int *end){

    int *aux;

    for(aux = start; aux < end; aux++){
        printf("[%d]\n", *aux);
    }

}
