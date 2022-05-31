#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define TAMANIO 50
#define PADDING 5

typedef struct {
	char valor;
	ALLEGRO_COLOR color;
} Cuadrado;


Cuadrado crearCuadrado(char valor, ALLEGRO_COLOR color);

Cuadrado crearCuadradoRGB(char valor, char r, char g, char b);

void renderizarCuadrado(Cuadrado* cuadrado, int pos_x, int pos_y);