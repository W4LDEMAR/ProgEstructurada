#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdlib.h>
#include "Juego.h"
#include "Texto.h"

#define WIDTH 800
#define HEIGHT 800
#define FPS 60

int main()
{

	srand(time(NULL));

	al_init();
	al_install_mouse();
	ALLEGRO_DISPLAY* ventana = al_create_display(WIDTH, HEIGHT);

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(ventana));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_set_window_title(ventana, "10x10");
	

	
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT* fuente_1 = al_load_font("./game_over.ttf", 80, 0);


	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	
	Juego juego = crearJuego();
	renderizarJuego(&juego);
	int highscore = 0;
	int cuenta = 0;

	Texto textoHighscore = crearTexto("Highscore: ", TAMANIO * 10 + MARGEN * 2, 40, white, fuente_1);
	Texto textoPuntuacion = crearTexto("Puntuacion: ", TAMANIO * 10 + MARGEN * 2, 80, white, fuente_1);

	renderizarJuego(&juego);
	al_flip_display();
	while (true) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			return 0;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES && juego.figuraSeleccionada != -1) {
			juego.figuras[juego.figuraSeleccionada].pos_x = ev.mouse.x;
			juego.figuras[juego.figuraSeleccionada].pos_y = ev.mouse.y;
			al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, black);
			renderizarJuego(&juego);
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			seleccionarFigura(&juego, ev.mouse.x, ev.mouse.y);
			renderizarJuego(&juego);
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, black);
			if (colocarFigura(&juego, ev.mouse.x, ev.mouse.y)) {
				cuenta += 1;
			}
			deseleccionarFiguras(&juego);
			renderizarJuego(&juego);
			if (cuenta == 3) {
				cuenta = 0;
				crearOpciones(&juego);
				renderizarJuego(&juego);
			}
			if (finDelJuego(&juego)) {
				if (juego.puntuacion > highscore) {
					highscore = juego.puntuacion;
				}
				juego = crearJuego();
				al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, black);
				
				renderizarJuego(&juego);
				cuenta = 0;
			}
		}
		setTexto(&textoHighscore, concatenarTextoEntero("HighScore: ", highscore));
		renderizarTexto(&textoHighscore);
		setTexto(&textoPuntuacion, concatenarTextoEntero("Puntuacion: ", juego.puntuacion));
		renderizarTexto(&textoPuntuacion);
		al_flip_display();
		
	}
}