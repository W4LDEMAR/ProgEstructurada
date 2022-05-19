#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char modelo;
    char color;
    char placa;
} Auto;

typedef struct{
    Auto automovil;
    int hora;
    int folio;
} Boleto;

typedef struct{
    Boleto coche;
} Estacionamiento; //Pila

typedef struct{
    Boleto coche;
} Calle; //Fila

Auto ingresarAuto();
Boleto creaBoleto(int n_folio);
Estacionamiento* push(Estacionamiento [], Estacionamiento *, int);
Estacionamiento* pop(Estacionamiento *, Estacionamiento *);
void impE(Estacionamiento *, Estacionamiento *);
int compCalle(Calle [], Calle *);
Calle* pushc(Calle [], Calle *, Estacionamiento [], Estacionamiento *);
Calle* popc(Calle *, Calle *);
void impC(Calle *, Calle *);



int main(){
    Estacionamiento E[7], *start, *end;
    Calle C[7], *startf, *endf;
    int n_folio = 1, op, n;

    do{
        system("cls");
        printf("\t*** VALET PARKING ***\n");
        printf("Elige la opcion deseada:\n");
        printf("1.- Ingresar automovil.");
        printf("2.- Sacar automovil.\n");
        printf("3.- Imprimir estado.");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                end = push(E, end, n_folio);
                if(end == NULL){
                    end--;
                }else{
                    impE(start, end);
                    impC(startf, endf);
                }

                break;

            case 2:

                break;

            case 3:
                impE(start, end);
                impC(startf, endf);
                break;
            default:
                printf("ERROR: Ingrese una opcion valida.");
                system("pause");
        }
    }while(op != 0);


    return 0;
}

Auto ingresarAuto(){

    Auto nuevo;

    printf("Ingrese el modelo del coche:\n");
    fflush(stdin);
    gets(nuevo.modelo);
    printf("Ingrese el color del coche:\n");
    fflush(stdin);
    gets(nuevo.color);
    printf("Ingrese la placa del coche:");
    fflush(stdin);
    gets(nuevo.placa);

    return nuevo;
}

Boleto creaBoleto(int n_folio){

    Boleto nuevo;

    nuevo.automovil = ingresarAuto();
    printf("Ingrese la hora de llegada");
    fflush(stdin);
    scanf("%d", &nuevo.hora);
    nuevo.folio = n_folio;

    return nuevo;
}

Estacionamiento* push(Estacionamiento E[], Estacionamiento *end, int n_folio){

    if(&E[7] == end){
        printf("\nERROR: El estacionamiento ya esta lleno.");
        system("pause");
        return NULL;
    }else{
        end -> coche = creaBoleto(n_folio);
        end++;
    }

    return end;
}

Estacionamiento* pop(Estacionamiento *start, Estacionamiento *end){
    if(start == end){
        printf("ERROR: El estacionamiento esta vacio.\n");
        system("pause");
    }else{
        end--;
    }

    return end;
}

void impE(Estacionamiento *start, Estacionamiento *end){

    Estacionamiento *aux;
    printf("\n");

    if(start = end){
        printf("El estacionamiento esta vacio.");
    }else{
        printf("\tEstado del estacionamiento:\n");
        for(aux = start; aux < end; aux++){
            printf("[%d] ", aux->coche.folio);
        }
        printf("\tEstado de la calle:\n");
    }
}

int compCalle(Calle C[], Calle *endf){
    if(&C[7] == endf){
        printf("\nERROR: La calle ya esta llena.");
        system("pause");
        return 1;
    }else{
        return 0;
    }
}

Calle* pushc(Calle C[], Calle *endf, Estacionamiento E[], Estacionamiento *end){

    int comp;
    comp = compCalle(C, endf);

    if(comp == 0){
        endf -> coche = end -> coche;
        endf++;

    return endf;
}

Calle* popc(Calle *start, Calle *end){

    Calle *aux;

    if(start == end){
        printf("ERROR: La fila esta vacia.\n");
        system("pause");
    }else{
        end--;
        for(aux = start; aux < end; aux++){
            *aux = *(aux+1);
        }
    }

    return end;
}

void impC(Calle *startf, Calle *endf){ //Fila

    Calle *aux;

    if(startf = endf){
        printf("La calle esta vacia.\n");
    }else{
        for(aux = startf; aux < endf; aux++){
            printf("[%d] ", aux->coche.folio);
        }
    }

}

void eliminarAuto(){

}
