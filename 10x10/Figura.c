#include "Figura.h"
#include <stdlib.h>

ALLEGRO_COLOR obtenerColor(int id) {
	switch (id){
	case 0:
		return al_map_rgb(89, 201, 131);
	case 1:
		return al_map_rgb(231, 105, 132);
	case 2:
		return al_map_rgb(89, 188, 228);
	case 3:
		return al_map_rgb(255, 199, 57);
	default:
		return al_map_rgb(222, 101, 82);
	}
}


Figura crearFigura() {
	Figura figura;
	figura.color = obtenerColor(rand() % 5);
	figura.id_figura = rand() % N_FIGURAS;
	figura.mouse_offset_x = 0;
	figura.mouse_offset_y = 0;
	figura.seleccion_x = -1;
	return figura;
}

Figura crearFiguraNula() {
	Figura figuraNula;
	figuraNula.id_figura = -1;
	return figuraNula;
}

int tieneCuadradoFigura(Figura* figura, int x, int y)
{
	if (figura->id_figura == -1) return 0;
	return formasFigura[figura->id_figura][x][y] == '#' ? 1 : 0;
}

void renderizarFigura(Figura* figura, int pos) {
	Cuadrado cuadrado;
	cuadrado.color = figura->color;
	if (figura->id_figura == -1) {
		cuadrado.color = al_map_rgb(0, 0, 0);
	}
	
	int i, j, pos_x, pos_y;
	int p0_x = MARGEN + (pos * 5 * TAMANIO);
	int p0_y = (MARGEN * 2) + (TAMANIO * 10);
	for (i = 0; i < 5; i++) {
		pos_x = p0_x + (i * TAMANIO);
		for (j = 0; j < 5; j++) {
			pos_y = p0_y + (j * TAMANIO);
			if (figura->id_figura == -1) {
				renderizarCuadrado(&cuadrado, pos_x, pos_y);
			}
			else if(tieneCuadradoFigura(figura, i , j)) {
				if (figura->seleccion_x != -1) {
					renderizarCuadrado(
						&cuadrado,
						(i * TAMANIO) + figura->pos_x - figura->mouse_offset_x,
						(j * TAMANIO) + figura->pos_y - figura->mouse_offset_y
					);
				}
				else {
					renderizarCuadrado(&cuadrado, pos_x, pos_y);
				}
			}
		}
	}
}


char formasFigura[N_FIGURAS][5][5] = {
	{
		"#    ",
		"     ",
		"     ",
		"     ",
		"     "
	},
	{
		"##   ",
		"     ",
		"     ",
		"     ",
		"     "
	},
	{
		"#    ",
		"#    ",
		"     ",
		"     ",
		"     "
	},
	{
		"##   ",
		"#    ",
		"     ",
		"     ",
		"     "
	},
	{
		" #   ",
		"##   ",
		"     ",
		"     ",
		"     "
	},
	{
		"##   ",
		"##   ",
		"     ",
		"     ",
		"     "
	},
	{
		"###  ",
		"#    ",
		"#    ",
		"     ",
		"     "
	},
	{
		"###  ",
		"     ",
		"     ",
		"     ",
		"     "
	},
	{
		"#    ",
		"#    ",
		"#    ",
		"     ",
		"     "
	},
	{
		"  #  ",
		"  #  ",
		"###  ",
		"     ",
		"     "
	},
	{
		"###  ",
		"###  ",
		"###  ",
		"     ",
		"     "
	},
	{
		"#### ",
		"#    ",
		"#    ",
		"#    ",
		"     "
	}
	,
	{
		"   # ",
		"   # ",
		"   # ",
		"#### ",
		"     "
	},
	{
		"#    ",
		"#    ",
		"#    ",
		"#    ",
		"     "
	},{
		"#### ",
		"     ",
		"     ",
		"     ",
		"     "
	},{
		"#### ",
		"#### ",
		"#### ",
		"#### ",
		"     "
	}
};
