#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxp 3
#define maxr 5
#define maxc 100

int main(){

    char a[maxp][maxr][maxc];
    int p, r, c, x;

    for(p = 0; p < maxp; p++){
        for(r = 0; r < maxr; r++){
            for(c = 0; c < maxc; c++){
                do{
                    x = 1 + rand()%998;
                }while(x % (p + 1) != 0);
                a[p][r][c] = x;
            }
        }
    }
    for(p = 0; p < maxp; p++){
        for(r = 0; r < maxr; r++){
            for(c = 0; c < maxc; c++){
                printf("[%3d]", a[p][r][c]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return 0;
}
