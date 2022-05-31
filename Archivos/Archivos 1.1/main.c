#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *apf;
    int i, n;

    apf = fopen("10_enteros.txt");

    for(i = 0; i < 10; i++){
        printf("Introduce un numero:\n");
        fflush(stdin);
        scanf("%d", &n);
        strcpy()
    }
    fclose(apf);
    return 0;
}
