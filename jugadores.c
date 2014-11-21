#include <stdio.h>
#include "colores.h"
#include "jugadores.h"

/*
 * void inicializar_jugadores(t_jugadores *js);
 * Dado un puntero a jugadores los inicializa pidiendo al usuario el numero
 * de jugadores y el de jugadores humanos, assegurandose que ambos estan
 * entre el numero de jugadores minimo y maximo permitidos.
 * E inicializa el turno al primer jugador.
 */
void inicializar_jugadores(t_jugadores *js) {
	int error = TRUE, i;
	
	while (error){
		printf("Numero de jugadores (%d-%d): ",  MIN_JUGADORES, MAX_JUGADORES);
		scanf("%d", &js->num_jugadores);
		
		if (!( js->num_jugadores >= MIN_JUGADORES &&  js->num_jugadores <= MAX_JUGADORES)){
			printf("Error: Numero de jugadores tiene que estar entre %d y %d\n", MIN_JUGADORES, MAX_JUGADORES);
			error = TRUE;
		} else {
			error = FALSE;
		}
	}
	error = TRUE;
	while (error){
		printf("Numero de jugadores humanos (%d-%d): ", MIN_HUMANOS, js->num_jugadores);
		scanf("%d", &js->num_humanos);
		
		if (!( js->num_humanos >= MIN_HUMANOS &&  js->num_humanos <= js->num_jugadores)){
			printf("Error: Numero de jugadores humanos tiene que estar entre %d y %d\n", MIN_HUMANOS, js->num_jugadores);

			

			error = TRUE;
		} else {
			for(i = 0; i < js->num_jugadores; i++){
				if(i < js->num_humanos){
					js->j[i].tipo = JUGADOR_HUMANO;
					js->j[i].num_osos = 0;
				} else {
					js->j[i].tipo = JUGADOR_MAQUINA;
					js->j[i].num_osos = 0;
				}
			}			
			error = FALSE;
		}
		
	}
	js->turno = 0;
}
	
	/*
	 * void pasar_turno(t_jugadores *js);
	 * Dado un puntero a jugadores pasa el turno al siguiente jugador
	 */
	void pasar_turno(t_jugadores *js) {
	  
		if (js->turno < js->num_jugadores - 1){
			js->turno++;
		}
		else {
			js->turno = 0;
		}

	}
	
	/*
	 * Dado un entero 'j' (correspondiente al jugador numero 'j',
	 * imprime en el color 'j' la cadena de caracteres "[#j]"
	 * y resetea el color. (Si j=3 -> imprime "[#3]" en color (3)"BLUE")
	 */
	void imprimir_jugador(int j) {
		printf_color(j);
		printf("[#%d]", j);
		printf_reset_color();
	}
	
	/*
	 * void imprimir_contadores(t_jugadores js);
	 * Se escribe el numero de OSOs que ha conseguido cada jugador.
	 */
	void imprimir_contadores(t_jugadores js) {

		int i;
	  
		printf("\nOSOs: ");
	
		for (i = 0; i < js.num_jugadores; i++){
			imprimir_jugador(i);
			printf(": %d | ", js.j[i].num_osos);
		}
		printf("\n");
	
	}

