#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char palabras [2][50];
    int intentos;
    char nombre[50];
    int ranking;
} Jugador;


void impresiondeturno (Jugador);
Jugador crearjugador ();
int buscarletra(char[],char);
Jugador turno(Jugador,int *);
int destaparLetras(char [][50],char);

int main()
{
    Jugador j[5];
    srand(time(NULL));
    int ganador=0,numJ,i;
    int fin=0,maxR,minR,cont;
    ///PREGUNTAMOS CUANTOS JUGADORES
    do{
        printf("\nEscibe numero de jugadores");
        scanf("%d",&numJ);
        if(numJ<2||numJ>5){
            printf("\nSolamente pueden ser entre 2 y 5 jugador");
        }
    }while(numJ<2||numJ>5);
    minR=numJ;
    maxR=1;
    ///CREAMOS JUGADORES
    for(i=0;i<numJ;i++){
        j[i]=crearjugador();
    }
    while(fin==0){
        for(i=0;i<numJ;i++){
            if(j[i].ranking==0){
                j[i]=turno(j[i],&ganador);
                if(ganador==1){
                    j[i].ranking=maxR;
                    maxR++;
                }
                else{
                    if(ganador==-1){
                        j[i].ranking=minR;
                        minR--;
                    }
                }
            }
        }
        cont=0;
        for(i=0;i<numJ;i++){
            if(j[i].ranking==0){
                cont++;
            }
        }
        if(cont<=1){
            fin=1;
        }
    }
    printf("\nTermino el juego");
    for(i=0;i<numJ;i++){
        impresiondeturno(j[i]);
    }
    return 0;
}
Jugador turno(Jugador j,int* ganador){
    char letra;
    *ganador=0;///ganador=1 tenemos ganador,
    ///ganador=0 sigue jugando
    ///ganador=-1 perdio
    ///Imprimir tablero
    impresiondeturno(j);
    ///Preguntar letra
    printf("\nEscribe una letra:");
    fflush(stdin);
    scanf("%c",&letra);
    ///Validar letra
    if(buscarletra(j.palabras[0],letra)==1){
        ///Se encontro la letra
        ///Modiciaciones
           ///Cambiar los guiones para que aparezcan letras
           ///Validar ganador
           if(destaparLetras(j.palabras,letra)==0){
                ///Tenemos un ganador
                *ganador=1;
           }
           /*else{
                ///Se pasa al siguiente turno
           }*/
    }
    else{
        ///No se encontro la letra
        ///Modificaciones
           ///Reducir intentos
        j.intentos--;
           ///Validar perdedor
        if(j.intentos<=0){
            *ganador=-1;
        }
    }
    impresiondeturno(j);
    printf("\n");
    system("pause");
    return j;
}

int destaparLetras(char a[][50],char l){
    ///regresa 0 si no hay guiones
    ///regresa !=0 si hay guiones
    int i,c=0;
    for(i=0;i<strlen(a[0]);i++){
        if(l==a[0][i]){
            a[1][i]=l;
        }
    }
    for(i=0;i<strlen(a[1]);i++){
        if(a[1][i]=='_'){
            c++;
        }
    }
    return c;
}

void impresiondeturno(Jugador j){
    system("cls");
    printf("\nAsignada:%s",j.palabras[0]);
    printf("\nPalabra:%s",j.palabras[1]);
    printf("\nIntentos:%d",j.intentos);
    printf("\nNombre:%s",j.nombre);
    if (j.ranking==0){
        printf("\nRanking:????");
    }
    else {
        printf("\nRanking:%d",j.ranking);
    }
}

 Jugador crearjugador(){
    Jugador nuevo;
    char pals[5][50];
    int x=0;
    nuevo.ranking=0;
    nuevo.intentos=3;
    printf("\nEscribe tu id:");
    fflush(stdin);
    gets(nuevo.nombre);
    strcpy(pals[x++],"CAYDE");
    strcpy(pals[x++],"ZAVALA");
    strcpy(pals[x++],"IKORA");
    strcpy(pals[x++],"ERIS");
    strcpy(pals[x++],"ORYX");
    x=rand()%5;
    strcpy(nuevo.palabras[0],pals[x]);
    for (x=0;x<strlen(nuevo.palabras[0]);x++){
       nuevo.palabras[1][x]='_';
    }
    nuevo.palabras[1][x]=NULL;
    return nuevo;
}

int buscarletra(char a[],char l){
    int i,r=0;
    for (i=0;i<strlen(a) && r==0;i++){
        if (l==a[i]){
            r=1;
        }
    }
    return r;
}
