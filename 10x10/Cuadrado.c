#include "Cuadrado.h"

Cuadrado crearCuadrado(char valor, ALLEGRO_COLOR color) {
	Cuadrado cuadrado;
	cuadrado.color = color;
	cuadrado.valor = valor;
	return cuadrado;
}

Cuadrado crearCuadradoRGB(char valor, char r, char g, char b) {
	return crearCuadrado(valor, al_map_rgb(r, g, b));
}

void renderizarCuadrado(Cuadrado* cuadrado, int pos_x, int pos_y) {
	ALLEGRO_COLOR negro = al_map_rgb(0, 0, 0);
	al_draw_filled_rectangle(
		pos_x,
		pos_y,
		pos_x + TAMANIO,
		pos_y + TAMANIO,
		cuadrado->color
	);
	al_draw_rectangle(pos_x,
		pos_y,
		pos_x + TAMANIO,  
		pos_y + TAMANIO,
		negro,
		PADDING
	);
}