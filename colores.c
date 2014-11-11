// Este fichero se le da al alumno
#include <stdio.h>
#include "colores.h"

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// http://ascii-table.com/ansi-escape-sequences.php

/*
 * Dado un color -1Default 0Red 1Green 2Yellow 3Blue 4Magenta 5Cyan
 * Hace que el terminal a partir de ahora escriba en ese color
 */
void printf_color(int color) {
	switch (color) {
		case -1: printf(ANSI_COLOR_RESET ); break;
		case  0: printf(ANSI_COLOR_RED    ); break;
		case  1: printf(ANSI_COLOR_GREEN  ); break;
		case  2: printf(ANSI_COLOR_YELLOW ); break;
		case  3: printf(ANSI_COLOR_BLUE   ); break;
		case  4: printf(ANSI_COLOR_MAGENTA); break;
		case  5: printf(ANSI_COLOR_CYAN   ); break;
	}
}

/*
 * Hace que el terminal a partir de ahora escriba en el color por defecto
 */
void printf_reset_color() {
	printf_color(-1);
}

