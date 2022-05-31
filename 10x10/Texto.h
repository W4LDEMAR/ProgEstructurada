#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define TAM_TEXTO 50

typedef struct {
	char texto[TAM_TEXTO];
	int pos_x, pos_y;
	int old_x, old_y, w, h;
	ALLEGRO_COLOR color;
	ALLEGRO_FONT* fuente;
} Texto;

Texto crearTexto(char* texto, int x, int y, ALLEGRO_COLOR color, ALLEGRO_FONT* fuente);

char* concatenarTextoEntero(char* texto, int num);

void setTexto(Texto* texto, char* valor);

void renderizarTexto(Texto* texto);

