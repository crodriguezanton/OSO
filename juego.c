#include <stdio.h>
#include "azar.h"	// para el azar de los jugadores maquina
#include "duerme.h"	// para que haya pausa entre jugadas de la maquina
#include "mapa.h"
#include "jugadores.h"

/*
 * Dado un mapa, un numero de jugador;
 * pide fila, columna y un caracter 'O' o 'S' a un jugador humano,
 * verifica fila,col,car y realiza la jugada.
 * Devuelve el numero de OSOs conseguidos con esa jugada.
 */
int jugar_humano(t_mapa *mapa, int jug) {
	
	int carryon = TRUE;
	int f, c;
	char car;

		while (carryon){

			printf(" Fila,Columna: ");
			scanf("%d, %d", &f, &c);

			if (mapa->c[f][c].letra == CASILLA_VACIA){
				carryon = FALSE;
			}

			scanf("%*c");

		}
		
		carryon = TRUE;
		while (carryon){

			printf("O/S: ");
			scanf("%c", &car);

			if (car == 'S' || car == 's' || car == 'O' || car == 'o'){
				carryon = FALSE;
			}

		}



		escribir_jugada(mapa, jug, f, c, car);
		return calcular_osos(mapa, f, c, car);

}

/*
 * Dado un mapa y numero de jugador; el programa decide una jugada.
 * Tiene que ser una jugada reglamentaria.
 * Y, estaria bien si la jugada fuera mas o menos inteligente.
 * Realiza la jugada seleccionada y duerme un rato.
 * Devuelve el numero de OSOs conseguidos con esa jugada.
 */
int jugar_maquina(t_mapa *mapa, int j) {

	int f = 0, c = 0, nf, nc, po, pomax = 0, goon = TRUE, n = 0, rand;
	char car = 'O', pocar, pomaxcar = 'O';



	for (nf = 0; nf < mapa->num_filas; nf++){

		for (nc = 0; nc < mapa->num_cols; nc++){

			if (mapa->c[nf][nc].letra == CASILLA_VACIA){

				pocar = 'O';

				po = calcular_osos(mapa, nf, nc, pocar);

				if (po == pomax){
					if (numero_al_azar(100) > 50){

						pomaxcar = pocar;
						f = nf;
						c = nc;

					}
				}
				else if (po > pomax){

					pomaxcar = pocar;
					f = nf;
					c = nc;

				}

				pocar = 'S';

				po = calcular_osos(mapa, nf, nc, pocar);

				if (po == pomax){
					if (numero_al_azar(100) > 50){

						pomaxcar = pocar;
						f = nf;
						c = nc;

					}
				}
				else if (po > pomax){

					pomaxcar = pocar;
					f = nf;
					c = nc;

				}

			}

		}

	}

	if(pomax == 0){

		rand = numero_al_azar(mapa->num_casillas_en_blanco) - 1;

		for(nf = 0; nf < mapa->num_filas && n <= rand; nf++){
			for(nc = 0; nc < mapa->num_cols; nc++){

				if(mapa->c[nf][nc].letra == CASILLA_VACIA){
					
					if(n == rand){
						f = nf;
						c = nc;
						if (numero_al_azar(100) > 50){
							pomaxcar = 'S';
						} else {
							pomaxcar = 'O';
						}
					}

					n++;

				}
				
			}

		}		

		
	}

	escribir_jugada(mapa, j, f, c, pomaxcar);
	duerme_un_rato();
	return calcular_osos(mapa, f, c, pomaxcar);

}

/*
 * Dado un mapa y jugadores,
 * si el contador de casillas en blanco esta a cero mira que jugador/es
 * ha/n conseguido mas OSOs y los imprime por pantalla.
 * Devuelve cierto si el juego se ha acabado. Y sino, falso.
 */
int se_acabo_el_juego(t_mapa mapa, t_jugadores js) {

	int i, max = 0;
  
	if (mapa.num_casillas_en_blanco != 0){
		return FALSE;
	}
	else {
		printf("JUGADOR/ES GANADOR/ES: ");

		for (i = 0; i < js.num_jugadores; i++){

			if (js.j[i].num_osos > max)
				max = js.j[i].num_osos;

		}

		for (i = 0; i < js.num_jugadores; i++){

			if (js.j[i].num_osos == max){
				imprimir_jugador(i);
				printf(" ");
			}

		}

		return TRUE;
	}

}

/*
 * Imprime el mapa y los contadores de OSOs de cada jugador.
 */
void imprimir_estado_juego(t_mapa mapa, t_jugadores js) {

	imprimir_mapa(mapa);
	imprimir_contadores(js);
	printf("\n");

}

/*
 * Dado un mapa y jugadores,
 * - Se imprime el jugador que tiene el turno, se mira si es humano o maquina
 * y se le hace jugar. Se le añaden a su total de OSOs los obtenidos con la
 * jugada. Se imprime por pantalla los OSOs obtenidos con la jugada.
 * - Si no obtuvo ninguno pasa el turno.
 */
void realizar_jugada(t_mapa *mapa, t_jugadores *js) {

	int j = js->turno, carryon = TRUE, osos;

	printf("Jugador ");
	imprimir_jugador(j);
	printf("\n");

	if (js->j[j].tipo == JUGADOR_HUMANO){

		osos = jugar_humano(mapa, j);
		

	}
	else {

		osos = jugar_maquina(mapa, j);

	}

	if (osos == 0){
		pasar_turno(js);
	}
	else {
		js->j[j].num_osos += osos;
	}

}

/*
 * Inicializa la generación de números aleatorios, jugadores y mapa.
 * Imprime el estado del juego.
 * Mientras no se haya acabado el juego:
 * - Llama a realizar_jugada() que es la función que hace que el humano
 *   o la maquina que tiene el turno realize una jugada.
 * - Imprime el estado del juego.
 */

main() {
  
	t_jugadores js;
	t_mapa mapa;

	inicializar_azar();

	inicializar_jugadores(&js);

	inicializar_mapa(&mapa);

	imprimir_estado_juego(mapa, js);

	while (!se_acabo_el_juego(mapa, js)){

			

		realizar_jugada(&mapa, &js);

		imprimir_estado_juego(mapa, js);

	}

	printf("\n");

}

