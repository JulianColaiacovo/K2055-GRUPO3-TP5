#include "symbol.c"

extern char temp_text[10];
extern int semantic_error_count;
int indice_variable_temporal = 0;
char temp_text[10];

void inicioPrograma() {
	printf("Load rtlib,\n");
}

void finPrograma() {
	printf("Stop ,\n");
}

int declararIdentificador(char *identificador) {
	if (existeIdentificador(identificador)) {
		semantic_error_count++;
		return 1;
	} else {
		registrarIdentificador(identificador);
		printf("Declare %s,Integer\n", identificador);
		return 0;
	}
}

int leerIdentificador(char *identificador) {
	if (existeIdentificador(identificador)) {
		printf("Read %s,Integer\n", identificador);
	} else {
		return 0;
	}
}

int escribirIdentificador(char *identificador) {
	if (existeIdentificador(identificador)) {
		printf("Write %s,Integer\n", identificador);
	} else {
		return 0;
	}
}

void generarVariableTemporal() {
	indice_variable_temporal++;
	sprintf(temp_text, "Temp#%d", indice_variable_temporal);
	declararIdentificador(temp_text);
}

int invertir(char *identificador) {
	if (existeIdentificador(identificador)) {
		generarVariableTemporal();

		printf("INV %s,,%s\n", identificador, temp_text);
		return 0;
	} else {
		return 1;
	}
}

int multiplicar(char *factorUno, char *factorDos) {
	printf("generado%s,%s\n", factorUno, factorDos);
	printf("generado\n");
	if (existeIdentificador(factorUno) && existeIdentificador(factorDos)) {
		generarVariableTemporal();
		printf("MULT %s,%s,%s\n", factorUno, factorDos, temp_text);
		return 0;
	} else {
		return 1;
	}
}