#include "symbol.h"

char *temp_text;
int semantic_error_count;
static int indice_variable_temporal = 0;

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

void declararConstante(char *constante) {
	if (!existeIdentificador(constante)) {
		registrarIdentificador(constante);
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
	temp_text = (char *)malloc(sizeof(char *));
	sprintf(temp_text, "Temp#%d", indice_variable_temporal);
	declararIdentificador(temp_text);
}

void realizarOperacion(char* instruccion, char* variableUno, char* variableDos){
	generarVariableTemporal();
	printf("%s %s,%s,%s\n", instruccion, variableUno, variableDos, temp_text);
}

int invertir(char *identificador) {
	if (existeIdentificador(identificador)) {
		realizarOperacion("INV", identificador, "");
		return 0;
	} else {
		semantic_error_count++;
		return 1;
	}
}

int multiplicar(char *factorUno, char *factorDos) {
	if (existenIdentificadores(factorUno,factorDos)) {
		realizarOperacion("MULT", factorUno, factorDos);
		return 0;
	} else {
		semantic_error_count++;
		return 1;
	}
}

int dividir(char* dividendo, char* divisor){
	if (existenIdentificadores(dividendo, divisor)) {
		realizarOperacion("DIV", dividendo, divisor);
		return 0;
	} else {
		semantic_error_count++;
		return 1;
	}
}

int restar(char* minuendo, char* sustraendo){
	if (existenIdentificadores(minuendo, sustraendo)) {
		realizarOperacion("SUBS",minuendo,sustraendo);	
		return 0;
	} else {
		semantic_error_count++;
		return 1;
	}
}

int sumar(char* sumandoUno, char* sumandoDos){
	if(existenIdentificadores(sumandoUno, sumandoDos)){
		realizarOperacion("ADD", sumandoUno, sumandoDos);
		return 0;
	}else{
		semantic_error_count++;
		return 1;
	}
}

int asignar(char* identificador, char* valor){
		printf("Store %s, %s\n", valor, identificador);
		return 0;
}