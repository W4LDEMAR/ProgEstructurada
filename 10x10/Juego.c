#include "Juego.h"

Juego crearJuego() {
	Juego juego;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			juego.cuadricula[i][j] = crearCuadradoRGB(0, 216, 216, 216);
		}
	}
	juego.puntuacion = 0;
	juego.figuraSeleccionada = -1;
	crearOpciones(&juego);
	return juego;
}

void crearOpciones(Juego* juego) {
	for (int i = 0; i < 3; i++) {
		juego->figuras[i] = crearFigura();
	}
}

void renderizarJuego(Juego* juego) {
	ALLEGRO_COLOR negro = al_map_rgb(0, 0, 0);
	int pos_x, pos_y, i, j;
	for (i = 0; i < 10; i++) {
		pos_x = MARGEN + (i * TAMANIO);
		for (j = 0; j < 10; j++) {
			pos_y = MARGEN + (j * TAMANIO);
			renderizarCuadrado(&juego->cuadricula[i][j], pos_x, pos_y);
		}
	}
	for (i = 0; i < 3; i++) {
		renderizarFigura(&juego->figuras[i], i);
	}
}

void deseleccionarFiguras(Juego* juego){
	juego->figuraSeleccionada = -1;
	for (int i = 0; i < 3; i++) {
		juego->figuras[i].seleccion_x = -1;
		juego->figuras[i].seleccion_y = -1;
		juego->figuras[i].mouse_offset_x = -1;
		juego->figuras[i].mouse_offset_y = -1;
	}
}

void seleccionarFigura(Juego* juego, int pos_x, int pos_y){
	int p0_x = MARGEN;
	int p0_y = (MARGEN * 2) + (TAMANIO * 10);
	deseleccionarFiguras(juego);

	if (pos_y < p0_y || pos_y > p0_y + (TAMANIO*5)) return;
	if (pos_x < MARGEN || pos_x > p0_x + (TAMANIO * 5 * 3)) return;


	int x = (pos_x - p0_x) / TAMANIO;
	int y = (pos_y - p0_y) / TAMANIO;
	int figura = x / 5;
	x -= figura * 5;

	if (!tieneCuadradoFigura(&juego->figuras[figura], x, y)) return;

	int offset_x = pos_x - ((figura * TAMANIO*5) + p0_x);
	int offset_y = pos_y - p0_y;
	printf("x: %d\ty: %d\tid_fig: %d\n", x, y, figura);
	juego->figuraSeleccionada = figura;
	juego->figuras[figura].seleccion_x = x;
	juego->figuras[figura].seleccion_y = y;
	juego->figuras[figura].mouse_offset_x = offset_x;
	juego->figuras[figura].mouse_offset_y = offset_y;
}

int _sePuedeAniadirFigura(Juego* juego, Figura* figura, int x, int y) {
	int i, j, curr_pos_x, curr_pos_y;
	for (i = 0; i < 5; i++) {
		curr_pos_x = x + i;
		for (j = 0; j < 5; j++) {
			curr_pos_y = y + j;
			if (tieneCuadradoFigura(figura, i, j)) {
				if (curr_pos_x >= 10 || curr_pos_y >= 10) return 0;
				if (juego->cuadricula[curr_pos_x][curr_pos_y].valor == 1) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int _sePuedeAniadirFiguraSeleccionada(Juego* juego, int x, int y) {
	if (juego->figuraSeleccionada == -1) return 0;
	return _sePuedeAniadirFigura(
		juego, juego->figuras + juego->figuraSeleccionada, x, y
	);
}

int colocarFigura(Juego* juego, int pos_x, int pos_y){
	int i, j, curr_pos_x, curr_pos_y;
	if (juego->figuraSeleccionada == -1) return 0;
	if (pos_y < MARGEN || pos_y > MARGEN + (TAMANIO * 10)) return 0;
	if (pos_x < MARGEN || pos_x > MARGEN + (TAMANIO * 10)) return 0;

	int x = (pos_x - MARGEN) / TAMANIO;
	int y = (pos_y - MARGEN) / TAMANIO;

	Figura* figuraSeleccionada = juego->figuras + juego->figuraSeleccionada;

	x -= figuraSeleccionada->seleccion_x;
	y -= figuraSeleccionada->seleccion_y;

	printf("x: %d\t", x);
	printf("y: %d\n", y);

	if (x < 0 || y < 0) return;
	if (!_sePuedeAniadirFiguraSeleccionada(juego, x, y)) return 0;

	for (i = 0; i < 5; i++) {
		curr_pos_x = x + i;
		for (j = 0; j < 5; j++) {
			curr_pos_y = y + j;
			if (tieneCuadradoFigura(figuraSeleccionada, i, j)) {
				juego->puntuacion += 1;
				juego->cuadricula[curr_pos_x][curr_pos_y] = crearCuadrado(1, figuraSeleccionada->color);
			}
		}
	}
	juego->figuras[juego->figuraSeleccionada] = crearFiguraNula();
	_limpiarLineas(juego);
	return 1;
}


void _buscarLineasV(Juego* juego, char* res) {
	int i, j, cuenta;
	for (i = 0; i < 10; i++) {
		cuenta = 0;
		for (j = 0; j < 10; j++) {
			if (juego->cuadricula[i][j].valor == 1) {
				cuenta += 1;
			}
		}
		res[i] = cuenta == 10 ? 1 : 0;
	}
}

void _buscarLineasH(Juego* juego, char* res) {
	int i, j, cuenta;
	for (i = 0; i < 10; i++) {
		cuenta = 0;
		for (j = 0; j < 10; j++) {
			if (juego->cuadricula[j][i].valor == 1) {
				cuenta += 1;
			}
		}
		res[i] = cuenta == 10 ? 1 : 0;
	}
}

void _limpiarLineas(Juego* juego) {
	int i, j;
	char res[10];
	_buscarLineasV(juego, &res);
	for (i = 0; i < 10; i++) {
		if (res[i] == 1) {
			juego->puntuacion += 10;
			for (j = 0; j < 10; j++) {
				juego->cuadricula[i][j] = crearCuadradoRGB(0, 216, 216, 216);
			}
		}
	}
	_buscarLineasH(juego, &res);
	for (i = 0; i < 10; i++) {
		if (res[i] == 1) {
			juego->puntuacion += 10;
			for (j = 0; j < 10; j++) {
				juego->cuadricula[j][i] = crearCuadradoRGB(0, 216, 216, 216);
			}
		}
	}
}


int finDelJuego(Juego* juego) {
	int i, j, k;
	for (i = 0; i < 3; i++) {
		if (juego->figuras[i].id_figura == -1) {
			continue;
		}
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				if (_sePuedeAniadirFigura(juego, &juego->figuras[i], j, k)) {
					return 0;
				}
				
			}
		}
	}
	return 1;
}