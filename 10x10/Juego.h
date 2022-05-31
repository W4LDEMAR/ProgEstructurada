#pragma once
#include <stdio.h>
#include "Cuadrado.h"
#include "Figura.h"



typedef struct {
	int puntuacion;
	Cuadrado cuadricula[10][10];
	Figura figuras[3];
	int figuraSeleccionada;
} Juego;


Juego crearJuego();

void crearOpciones(Juego* juego);

void renderizarJuego(Juego* juego);

void seleccionarFigura(Juego* juego, int pos_x, int pos_y);

void deseleccionarFiguras(Juego* juego);

int _sePuedeAniadirFigura(Juego* juego, Figura* figura, int x, int y);

int _sePuedeAniadirFiguraSeleccionada(Juego* juego, int x, int y);

int colocarFigura(Juego* juego, int pos_x, int pos_y);

void _buscarLineasH(Juego* juego, char* res);

void _buscarLineasV(Juego* juego, char* res);

void _limpiarLineas(Juego* juego);

int finDelJuego(Juego* juego);