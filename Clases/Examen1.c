#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    char arr[3][10], pal[20], let[1];
    int i, cont = 0, c;

    for(i = 0; i < 3; i++){
        printf("Inserte\n");
        fflush(stdin);
        gets(pal);
        arr[i] = pal;
        printf("%c", arr[i]);
    }


    printf("Que letra\n");
    fflush(stdin);
    gets(let);

    for(i = 0; i < 3; i++){
        for(c = 0; c < 20; c++){

            if(arr[i] == let[0]){
                cont++;
            }
        }
    }

    printf("El arreglo tiene %d veces esa letra", cont);
    return 0;
}
