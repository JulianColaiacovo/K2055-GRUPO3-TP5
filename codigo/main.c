#include <stdio.h>
#include "parser.h"
/*

TP4 - 2017

Grupo 03

Badía, Leonardo Javier
159.179-4

Colaiacovo, Julián Joaquín
152.048-9

De Luca, Iván
158.907-6

Espíndola Rodríguez, Iván Pablo
159.655-0

*/

int main(void){
	switch( yyparse() ){
	case 0:
		printf("Compilación terminada con éxito\n");
		printf("Errors sintácticos: 0 - Errores léxicos: 0\n");
		return 0;
	case 1:
		printf("Errores de compilación\n");
		printf("Errors sintácticos: %d - Errores léxicos: %d\n - Errores semánticos: %d\n", yynerrs, lexem_error_count, semantic_error_count);
		return 1;
	case 2:
		printf("Memoria insuficiente\n"); 
		return 2;
	}
}
