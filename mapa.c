#include <stdio.h>
#include "colores.h"
#include "mapa.h"



/*
 * void inicializar_casillas(t_mapa *mapa);
 * Dado un puntero a mapa con los campos filas y columnas inicializados,
 * se inicializa todas sus casillas a CASILLA_VACIA y NINGUN_JUGADOR.
 * Tambien se inicializan num_casillas y num_casillas_en_blanco.
 */
void inicializar_casillas(t_mapa *mapa) {

	int i, j;

	mapa->num_casillas = mapa->num_filas * mapa->num_cols;
	mapa->num_casillas_en_blanco = mapa->num_casillas;
  
	for (i = 0; i < MAX_FILAS; i++){
		for (j = 0; j < MAX_COLS; j++){

			mapa->c[i][j].letra = CASILLA_VACIA;
			mapa->c[i][j].jugador = NINGUN_JUGADOR;

		}
	}

}

/*
 * void inicializar_mapa(t_mapa *mapa);
 * Dado un puntero a mapa, se preguntan filas y columnas, se verifica que esten
 * entre sus minimos y maximos correspondientes.
 * Se asignan a mapa y se llama a inicializar casillas.
 */
void inicializar_mapa(t_mapa *mapa) {
  
	int error = TRUE;

	while (error){
		printf("Mapa:\n\tFilas (%d-%d): ", MIN_FILAS, MAX_FILAS);
		scanf("%d", &mapa->num_filas);
		if (!(mapa->num_filas >= MIN_FILAS && mapa->num_filas <= MAX_FILAS)){
			printf("Error: Numero de filas tiene que estar entre %d y %d", MIN_FILAS, MAX_FILAS);
			error = TRUE;
		}
		else{
			error = FALSE;
		}
	}

	error = TRUE;

	while (error){
		printf("\tColumnas (%d-%d): ", MIN_COLS, MAX_COLS);
		scanf("%d", &mapa->num_cols);
		if (!(mapa->num_filas >= MIN_FILAS && mapa->num_filas <= MAX_FILAS)){
			printf("Error: Numero de columnas tiene que estar entre %d y %d", MIN_COLS, MAX_COLS);
			error = TRUE;
		}
		else{
			error = FALSE;
		}
	}

	inicializar_casillas(&mapa);

}

/*
 * void imprimir_mapa(t_mapa mapa);
 * Dado un mapa imprime el mapa de tal forma que las 'O's y 'S's
 * se imprimen con el color del jugador que las hizo.
 */
void imprimir_mapa(t_mapa mapa) {
  


}

/*
 * Dado un mapa, un numero de jugador, fila, columna y un caracter 'O' o 'S';
 * escribe el car en fila,col del mapa para el jugador en turno
 * y decrementa el contador de casillas en blanco del mapa.
 */
void escribir_jugada(t_mapa *mapa, int j, int f, int c, char car) {
  mapa->c[f][c].jugador = j;
  mapa->c[f][c].letra = car;
  mapa->num_casillas_en_blanco--;
}

/*
 * int calcular_osos(t_mapa *mapa, int f, int c, char car);
 * Dado un mapa, fila "f", columna "c" y un caracter "car" = 'O' o 'S';
 * devuelve cuantos OSOs se crearian al escribir el car en fila,columna.
 */
int calcular_osos(t_mapa *mapa, int f, int c, char car){
  /* COMPLETAR */
  
}

