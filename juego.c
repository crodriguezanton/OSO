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
int jugar_humano(t_mapa *mapa, int j) {
  /* COMPLETAR */
}

/*
 * Dado un mapa y numero de jugador; el programa decide una jugada.
 * Tiene que ser una jugada reglamentaria.
 * Y, estaria bien si la jugada fuera mas o menos inteligente.
 * Realiza la jugada seleccionada y duerme un rato.
 * Devuelve el numero de OSOs conseguidos con esa jugada.
 */
int jugar_maquina(t_mapa *mapa, int j) {
  /* COMPLETAR */
}

/*
 * Dado un mapa y jugadores,
 * si el contador de casillas en blanco esta a cero mira que jugador/es
 * ha/n conseguido mas OSOs y los imprime por pantalla.
 * Devuelve cierto si el juego se ha acabado. Y sino, falso.
 */
int se_acabo_el_juego(t_mapa mapa, t_jugadores js) {
  /* COMPLETAR */
}

/*
 * Imprime el mapa y los contadores de OSOs de cada jugador.
 */
void imprimir_estado_juego(t_mapa mapa, t_jugadores js) {
  /* COMPLETAR */
}

/*
 * Dado un mapa y jugadores,
 * - Se imprime el jugador que tiene el turno, se mira si es humano o maquina
 * y se le hace jugar. Se le añaden a su total de OSOs los obtenidos con la
 * jugada. Se imprime por pantalla los OSOs obtenidos con la jugada.
 * - Si no obtuvo ninguno pasa el turno.
 */
void realizar_jugada(t_mapa *mapa, t_jugadores *js) {
  /* COMPLETAR */
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
  /* COMPLETAR */
}

