


#define maxr 4
#define maxc 4

int main()
{
    int a[maxr][maxc] = {0};
    int r, c, x = 1;
    for(r = 0; r <maxr; r++){
        for(c = 0; c < maxc; c++){
            a[r][c] = r + c + 1;
        }
    }
    for(r = 0; r < maxr; r++){
        printf("\n");
        for(c = 0; c < maxc; c++){
            printf("[%3d]", a[r][c]);
        }
    }
    return 0;
}
