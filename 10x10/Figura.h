#pragma once
#include <allegro5/allegro.h>
#include "Cuadrado.h"

#define MARGEN 20
#define N_FIGURAS 16

char formasFigura[N_FIGURAS][5][5];

typedef struct {
	int id_figura;
	ALLEGRO_COLOR color;
	int seleccion_x, seleccion_y;
	int mouse_offset_x, mouse_offset_y;
	int pos_x, pos_y;
} Figura;

Figura crearFigura();

Figura crearFiguraNula();

int tieneCuadradoFigura(Figura* figura, int x, int y);

void renderizarFigura(Figura* figura, int pos);
