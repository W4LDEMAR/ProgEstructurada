#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[50];
    float calif;
    int clave;
} Alumno;

Alumno* push(Alumno [], Alumno *, int, float, char []);
Alumno* pop(Alumno *, Alumno *);
void imp(Alumno *, Alumno *);

int main(){

    Alumno pila[10], *start, *end;
    int op, clave, n;
    float calif;
    char nom[50];
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
                printf("Escribre la clave del alumno:\n");
                fflush(stdin);
                scanf("%d", &clave);
                printf("Escribre la calificacion del alumno:\n");
                fflush(stdin);
                scanf("%f", &calif);
                printf("Escribre el nombre del alumno:\n");
                fflush(stdin);
                gets(nom);
                end = push(pila, end, clave, calif, nom);

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

Alumno* push(Alumno pila[], Alumno *end, int clave, float calif, char nom[]){

    if(&pila[10] == end){
        printf("\nERROR: La pila ya esta llena.");
        system("pause");
    }else{
        end -> clave = clave;
        end -> calif = calif;
        strcpy(end -> nombre, nom);
        end++;
    }

    return end;
}

Alumno* pop(Alumno *start, Alumno *end){
    if(start == end){
        printf("ERROR: La pila esta vacia.\n");
        system("pause");
    }else{
        end--;
    }

    return end;
}

void imp(Alumno *start, Alumno *end){

    Alumno *aux;
    printf("\n");

    for(aux = start; aux < end; aux++){
        printf("[%d]\n", aux -> clave);
    }

}
