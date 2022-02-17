#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>


#define maxr 7

int main()
{
    char a[7][9]; //Array2D de cadenas
    int i, x;
    char e = {"nombre", "segundo nombre", "apellido paterno", "apellido materno"};
    for(x = 0; x < strlen(e); x++){
        for(i = 0; i < maxr; i++){
            printf("\nEscribe la cadena %d:", x);
            fflush(stdin);
            gets(a[i]);
        }
    }
    if(a[4])
    for(i = 0; i < maxr; i++){
        printf("\n%s", a[i]);
    }
    return 0;
}
