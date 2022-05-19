#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inciso2(char [], int *);

int main(){

    int op, e[10], r[10], b[3][5], t[3][3][3], k[2][10];
    char c[20], *ptrc;
    float f[10], *ptrf;
    int *ptr, **ptrd;

    inciso2(c, ptrc);
    do{
        system("cls");
        printf("\tSELECCIONA LA OPCION DESEADA:\n");
        printf("1.- Imprimir la direccion de casillas de un arreglo de 10 enteros.\n");
        printf("2.- Imprimir la direccion de casillas de un arreglo de 20 caracteres.\n");
        printf("3.- Imprimir la direccion de casillas de un arreglo de 10 flotantes.\n");
        printf("4.- Imprimir el contenido de un arreglo de 10 enteros aleatorios.\n");
        printf("5.- Llenar por entrada de usuario un arreglo de 10 flotantes (iniciando por detras).\n");
        printf("6.- Llenar por entrada de usuario un arreglo de 20 caracteres.\n");
        printf("7.- Imprimir la direccion de casillas de un arreglo de enteros bidimensional de 3 renglones y 5 columnas.\n");
        printf("8.- Imprimir la direccion de casillas de un arreglo de enteros tridimensional de 3x3x3.\n");
        printf("9.- Llenar un arreglo de enteros de 2 renglones y 10 columnas de forma lineal.\n");
        printf("10.- Llenar un arreglo de enteros de 2 renglones y 10 columnas de forma salteada.\n");
        printf("11.- Llenar un arreglo de enteros de 2 renglones y 10 columnas de par en par con saltos.\n");
        printf("0.- Terminar el programa.\n");

        switch(op){
            case 1:
                system("cls");
                inciso1(e, ptr);
                break;
            case 2:
                system("cls");
                inciso2(c, ptrc);
                break;
            case 3:
                system("cls");
                inciso3(f, ptrf);
                break;
            case 4:
                system("cls");
                inciso4(r, ptr);
                break;
            case 5:
                system("cls");
                inciso5(f, ptrf);
                break;
            case 6:
                system("cls");
                inciso6(c, ptrc);
                break;
            case 7:
                system("cls");
                inciso7(b, ptr);
                break;
            case 8:
                system("cls");
                inciso8(t, ptr);
                break;
            case 9:
                system("cls");
                inciso9(k, ptrd);
                break;
            case 10:
                system("cls");
                inciso10(k, ptr);
                break;
            casse 11:
                system("cls");
                inciso11(k, ptr);
                break;
        }

    }while(op != 0);


    return 0;
}

void inciso1(int e[], int *ptr){
    printf("\n\tEn un arreglo de 10 enteros, se imprime la direccion de cada una de las casillas del arreglo\n");
    for(ptr = e; ptr < (e + 10); ptr++){
        printf("[ %p ]\n", ptr);
    }
}

void inciso2(char c[], char *ptrc){
    printf("\n\tEn un arreglo de 20 caracteres, se imprime la direccion de cada una de las casillas del arreglo:\n");
    for(ptrc = c; ptrc < (c + 20); ptrc++){
        printf("[ %p ]\n", ptrc);
    }
}

void inciso3(float f[], float *ptrf){
    printf("\n\tEn un arreglo de 10 floats, se imprime la direccion de cada una de las casillas del arreglo\n");
    for(ptrf = f; ptrf < (f + 10); ptrf++){
        printf("[ %p ]\n", ptrf);
    }
}

void inciso4(int r[], int *ptr){

    int i, x;

    for(i = 0; i < 10; i++){
        x = rand() % 999;
        r[i] = x;
    }

    printf("\n\tEn un arreglo de 10 enteros aleatorios, se imprime el contenido del arreglo\n");
    for(ptr = r; ptr < (r + 10); ptr++){
        printf("[ %d ]\n", *ptr);
    }
}

void inciso5(float f[], float *ptrf){

    int n;

    for(ptrf = (f + 9); ptrf = f; f--){
        printf("Ingresa un numero flotante:\n");
        fflush(stdin);
        scanf("%f", &n);
        *ptr = n;
    }

    printf("Tu arreglo de numeros flotantes es:\n");
    for(ptrf = f; ptrf < (f + 10); ptrf++){
        printf("[ %f ]\n", *ptrf);
    }
}

void inciso6(char c[], char *ptrc){

    char *izq = (c), *der = (c + 19);
    int i;

    for(i = 0; i < 20; i++){
        printf("Ingresa la letra que deseas agregar:\n");
        fflush(stdin);
        if(i % 2 = 0){for(ptr = b; ptr <= &(b[2][4]); ptr++){
        if(ptr == &b[1][0] || ptr == &b[2][0]){
            printf("\n");
        }
        printf("[ %p ]\n", ptr);
    }
            scanf("%c", izq);
            izq++;
        }else{
            scanf("%c", der);
            der--;
        }
    }

    printf("El arreglo quedo de la siguiente manera:\n");
    for(i = 0; i < 20; i++){
        printf("[%c] ", c[i]);
    }
}

void inciso7(int b[][5], int *ptr){
    printf("\n\tEn un arreglo bidimensional de enteros de 3 renglones y 5 columnas, se imprime la direccion de cada una de las casillas del arreglo\n");
    for(ptr = b; ptr <= &(b[2][4]); ptr++){
        if(ptr == &b[1][0] || ptr == &b[2][0]){
            printf("\n");
        }
        printf("[ %p ]\n", ptr);
    }
}

void inciso8(int t[][3][3], int *ptr){
    printf("\n\tEn un arreglo tridimensional de enteros de 3x3x3, se imprime la direccion de cada una de las casillas del arreglo\n");
    for(ptr = t; ptr <= &(t[2][2][2]); ptr++){
        if(ptr == &t[1][0][0] || ptr == &t[2][0][0]){
            printf("\n");
        }
        printf("[ %p ]\n", ptr);
    }
}

void inciso9(int k[][10], int **ptrd){

    int x, i, n = 0;

    ptr = k;

    for(x = 0; x < 2; x++){
        for(i = 0; i < 10; i++){
            *(*(ptr + x) + i) = n;
            n++;
        }
    }
}

void inciso99(int k[][10], int *ptr){

    int n = 0;

    for(ptr = k; ptr <= &(k[1][9]); ptr++){
        *ptr = n;
        n++;
    }

    printf("\tARREGLO:\n");
    for(ptr = k; ptr <= &k[1][9]; ptr++){
        if(ptr == &k[1][0]){
            printf("\n");
        }
        printf("[ %d ]\n", *ptr);
    }
}

void inciso10(int k[][10], int *ptr){

    int n = 0;

    for(ptr = k; ptr <= &(k[1][9]); ptr++){
    }

    printf("\tARREGLO:\n");
    for(ptr = k; ptr <= &(k[1][9]); ptr++){
        if(ptr == &k[1][0]){
            printf("\n");
        }
        printf("[ %d ]\n", *ptr);
    }
}

void inciso11(int k[][10], int *ptr){

    int x, i;

    for(x = 0; x < 2; x++){
        for(i = 0; i < 10; i++){
            if(x == 0){
                *(*(ptr + x) + i) =
            }
        }
    }
}
