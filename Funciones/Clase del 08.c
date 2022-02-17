#include <stdio.h>
#include <stdlib.h>
//calcular division por medio de restas sucesivas

int division();
void preguntaPalabra();

int main(){

    int x, y, n;
    char z[100];

    printf("Ingresa el primer dato:");
    scanf("%d", &x);
    printf("\nIngresa el primer dato:");
    fflush(stdin);
    scanf("%d", &y);

    printf("\n\tEl cociente da como resultado: %d", division(x, y, &n));
    printf("\n\tY el residuo es: %d", n);

    preguntaPalabra(z);
    printf("%s", z); // cadenas
    return 0;
}

int division(int x, int y, int *residuo){
    int r;
    while(x >= y){
        x = x-y;
        r++;
    }
    *residuo = x;
    return r;
}

void preguntaPalabra(char pal[]){
    printf("\nEscribe una cadena:");
    fflush(stdin);
    gets(pal);
}
