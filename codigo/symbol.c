#include <string.h>

static char *diccionario[1000];
static int indice_diccionario = 0;

void registrarIdentificador(char *identificador) {
	diccionario[indice_diccionario] = identificador;
	indice_diccionario++;
}

int existeIdentificador(char *identificador) {
	for (int i = 0; i < indice_diccionario; i++) {
		if (strcmp(diccionario[i], identificador) == 0) {
			return 1;
		}
	}
	return 0;
}

int existenIdentificadores(char *identificadorUno, char *identificadorDos){
	return existeIdentificador(identificadorUno) && existeIdentificador(identificadorDos);
}