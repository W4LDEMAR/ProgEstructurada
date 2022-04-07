#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char marca;
    char modelo;
    int ano;
    float motor;
    char placa;
    int n_puertas;
    int n_pasajeros;
    float precio;
} Automovil;

typedef struct{
    char id[7];
    int numAut;
    Automovil autos[5];
    float precio;
    int estado;
} Embarque;

int main(){
    Embarque E[5];
    int numE = 0, op, fin = 0;

    do{
        printf("Altas y bajas de embarques");
        printf("Seleccione la opcion deseada");
        printf("1.- Dar de alta un embarque. \n2.- Realizar cambios en un embarque. \n3.- Imprimir el resumen de un embarque. \n4.- Imprimir toda la informacion del embarque. \n5.- Eliminar un embarque. \n6.- Terminar programa");

        if(fin >= 1 && fin <= 6){
            switch(op){
                case 1:
                    nuevoEmbarque(&numE);
                    break;
                case 2:
                    modDatosE();
                    break;
                case 3:
            }
        }else{
            printf("EROOR: Introduce una opcion valida");
        }
    }while(fin != 6);

}

Automovil nuevoAuto(int n){

    Automovil nuevo;

    system("cls");
    printf("\t *** AUTOMOVIL NUMERO %d ***", n);
    printf("Introduce la marca del auto: \n");
    fflush(stdin);
    gets(nuevo.marca);
    printf("Introduce el modelo del auto: \n");
    fflush(stdin);
    gets(nuevo.modelo);
    printf("Introduce el ano del auto: \n");
    fflush(stdin);
    scanf("%d", &nuevo.ano);
    printf("Introduce la placa del auto: \n");
    fflush(stdin);
    gets(nuevo.placa);
    printf("Introduce la capacidad del motor: \n");
    fflush(stdin);
    scanf("%f", &nuevo.motor);
    printf("Indica el numero de puertas que tiene el auto: \n");
    fflush(stdin);
    scanf("%d", &nuevo.n_puertas);
    printf("Indica la cantidad de pasajeros maximos del auto: \n");
    fflush(stdin);
    scanf("%d", &nuevo.n_pasajeros);
    printf("Introduce el precio del auto: \n");
    fflush(stdin);
    scanf("%f", &nuevo.precio);

    return nuevo;
}

Embarque nuevoEmbarque(int *numE){

    Embarque nuevo;
    int i;

    system("cls");
    printf("Escribe el id del nuevo embarque:\n");
    fflush(stdin);
    gets(nuevo.id);

    do{
        printf("Indica el numero de autos que tendra el embarque:\n");
        fflush(stdin);
        scanf("d", &nuevo.numAut);
    }while(comp_nAutos(nuevo.numAut) =! 1);

    nuevo.precio = 0;

    for(i = 0; i > nuevo.numAut; i++){
        nuevo.autos[i] = nuevoAuto(i + 1);
        nuevo.precio = nuevo.autos[i].precio + nuevo.precio;
    }

    do{
        printf("Elige el estado del embarque:\n");
        printf(" 1.- Pendiente\n 2.- En transito\n 3.- Entregado\n 4.- Cancelado\n");
        fflush(stdin);
        scanf("%d", &nuevo.estado);
    }while(comp_estado(nuevo.estado) != 1);

    *numE++;

    return nuevo;
}

int comp_estado(int n){
    if(n > 4 || n < 1){
        printf("ERROR: Selecciona una opcion del menu\n")
        return 0;
    }else{
        return 1;
    }
}

int comp_nAutos(int n){
    if(n > 5 || n < 1){
        printf("ERROR: El embarque debe de tener entre 1 y 5 autos unicamente\n");
        return 0;
    }else{
        return 1;
    }
}

void impResumEmbarque(Embarque E){

    system("cls");
    printf("\n \t*** RESUMEN DEL EMBARQUE %s ***\n", E.id);
    printf("El precio total del embarque es de: %f \n", E.precio);
    printf("El embarque se encuentra ---> ");
    impEstado(E.estado);
    system("pause");

}

void impEmbarque(Embarque E){

    int i;

    system("cls");
    printf("\n\t*** DATOS DEL EMBARQUE %s ***\n", E.id);
    printf("El embarque cuenta con: %d autos \n", E.numAut);
    printf("Los autos son:\n");
    for(i = 0; i < E.numAut; i++){
        printf("\t %s %s \n",E.autos[i].marca, E.autos[i].modelo);
    }
    printf("El precio total del embarque es de: %f \n", E.precio);
    printf("El embarque se encuentra ---> ");
    impEstado(E.estado);
    system("pause");

}

void impEstado(int estado){

    switch(estado){
        case 1:
            printf("PENDIENTE");
            break;
        case 2:
            printf("EN TRANSITO");
            break;
        case 3:
            printf("ENTREGADO");
            break;
        case 4:
            printf("CANCELADO");
            break;
    }
}

void impAuto(Embarque E, int n){

    system("cls");
    printf("\t *** DATOS DEL AUTO %d DENTRO DEL EMBARQUE %s ***\n\n", n, E.id);
    printf("Marca del automovil: %s\n", E.autos[n].marca);
    printf("Modelo del automovil: %s\n", E.autos[n].modelo);
    printf("Ano del automovil: %s\n", E.autos[n].ano);
    printf("Motor del automovil: %f\n", E.autos[n].motor);
    printf("Placa del automovil: %s\n", E.autos[n].placa);
    printf("Numero de puertas del automovil: %d\n", E.autos[n].n_puertas);
    printf("Numero de pasajeros del automovil: %d\n", E.autos[n].n_pasajeros);
    printf("Precio del automovil: %f\n", E.autos[n].precio);
    system("pause");

}

void modDatosE(Embarque *E, int *numE){
    /// Recuerda hacer una comprobacion por si no esl embarque que desea modificar en el main
    int opcion, numero, x;

    system("cls");
    do{
        printf("\n\t Elige el campo que deseas modificar:\n");
        printf(" 1.- ID del embarque.\n 2.- Estado del embarque.\n 3.- Autos del embarque\n");
        printf("\t 4.- CANCELAR\n");
        fflush(stdin);
        scanf("%d", &opcion);
    }while(comp_OpMod(opcion) != 1);

    switch(opcion){
        case 1:
            printf("Introduce el nuevo id del embarque: \n");
            fflush(stdin);
            gets(*E.id);
            break;
        case 2:
            do{
                printf("Elige el nuevo estado del embarque:\n");
                printf(" 1.- Pendiente\n 2.- En transito\n 3.- Entregado\n 4.- Cancelado\n");
                fflush(stdin);
                scanf("%d", &numero);
                *E.estado = numero;
            }while(comp_estado(nuevo.estado) != 1);
            break;
        case 3:
            while(x != 1 || x != 2){
                printf("Elige la opcion deseada:\n");
                printf(" 1.- Modificar los datos de un auto del embarque. \n 2.- ELIMINAR un auto del embarque");
                fflush("stdin");
                scanf("%d", &x);
                if(x == 1){
                    ///llama a la funcion para modificar
                }else if(x == 2){
                    ///llama a la funcion para eliminar auto
                }else{
                    printf("Introduce una opcion valida\n");
                }
            }
            break;
        case 4:
            printf("Operacion cancelada");
            break;
    }
}

void modAutos(){

}

void elimAuto(Embarque E, int nAuto){

}

int comp_OpMod(int n){
    if(n >= 1 && n <= 5){
        return 1;
    }else{
        printf("Introduce una opcion valida.");
        return 0;
    }
}
