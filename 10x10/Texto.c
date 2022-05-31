#include "Texto.h"
#pragma once

Texto crearTexto(char* texto, int x, int y, ALLEGRO_COLOR color, ALLEGRO_FONT* fuente) {
	Texto t;
	strcpy_s(&t.texto, sizeof(char) * TAM_TEXTO, texto);
	t.pos_x = x;
	t.pos_y = y;
	t.color = color;
	t.fuente = fuente;
	return t;
}

void setTexto(Texto* texto, char* valor) {
	strcpy_s(&texto->texto, sizeof(char) * TAM_TEXTO, valor);
}


void renderizarTexto(Texto* texto){
	al_get_text_dimensions(texto->fuente, texto->texto, &texto->old_x, &texto->old_y, &texto->w, &texto->h);
	int pos_x = texto->pos_x + texto->old_x;
	int pos_y = texto->pos_y + texto->old_y;
	al_draw_filled_rectangle(pos_x, pos_y, pos_x + texto->w, pos_y + texto->h, al_map_rgb(0, 0, 0));
	al_draw_text(texto->fuente, texto->color, texto->pos_x, texto->pos_y, 0, texto->texto);
}

char* concatenarTextoEntero(char* texto, int num){
	char salida[TAM_TEXTO] = "";
	char textoNum[6] = "";
	_itoa_s(num, textoNum, sizeof(char) * 6, 10);

	strcpy_s(&salida, sizeof(char) * TAM_TEXTO, texto);
	strcat_s(&salida, sizeof(char) * TAM_TEXTO, textoNum);
	return salida;
}
