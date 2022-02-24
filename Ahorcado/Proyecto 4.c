#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxpal 20
#define maxlet 15

void impresionTurno(char);
int buscarLetra(char, char), i, x;
int turno(char);

struct Jugador{

    int vidas;
    char nombre[20];
    char palabra[20];
    char progreso[20];

};

int main(){

    char palabras[maxpal][maxlet] = {"programa", "dinosaurio", "telefono", "ingenuo", "refrigerador", "renacuajo", "mantenimiento",
    "resultados", "coronavirus", "alpinismo", "caballo", "hermano", "contaminar", "hormonas", "columpio", "ambulancia", "hormiguero",
    "imprimir", "nostalgia", "literatura"};
    int n_jug;

    printf("\t\t A H O R C A D O\n");
    n_jug = n_jugadores();

    return 0;
}

int n_jugadores(){

    int n_jug;

    printf("¿Cuantas personas jugaran?\n\t**De 1 a 5 jugadores**\n");
    fflush(stdin);
    scanf("%d", &n_jug);

    if(n_jug < 0 || n_jug > 5){
        printf("introduce un numero de jugadores valido");
        n_jug = n_jugadores();
    }

    return n_jug;
}

struct Jugador crea_jug(char palabras[][maxlet]){

    struct Jugador jug1;
    int x = rand()%maxpal, n_letras, i;

    printf("Insterte el nombre del nuevo jugador:\n");
    fflush(stdin);
    gets(&jug1.nombre);

    n_letras = strlen(palabras[x]);
    jug1.palabra = palabras[x];

    for(i = 0; i < n_letras; i++){
        jug1.progreso[i] = "_ ";
    }

    return jug1;
}
