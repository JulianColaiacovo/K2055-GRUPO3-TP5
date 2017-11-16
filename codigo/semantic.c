#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
#include "parser.h"

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
	char * error = (char *)malloc(sizeof(char *));

	if (existeIdentificador(identificador)) {
		semantic_error_count++;
		sprintf(error, "Error semántico: identificador %s ya declarado", identificador);
		yyerror(error);
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

void validarIdentificadorDeclarado(char *identificador) {
	char *error = (char *)malloc(sizeof(char *));
	if (!existeIdentificador(identificador)) {
		semantic_error_count++;
		sprintf(error, "Error semántico: identificador %s NO declarado", identificador);
		yyerror(error);
	}
}

void realizarOperacion(char* instruccion, char* variableUno, char* variableDos){
	generarVariableTemporal();
	printf("%s %s,%s,%s\n", instruccion, variableUno, variableDos, temp_text);
}

void invertir(char *identificador) {
	realizarOperacion("INV", identificador, "");
}

void multiplicar(char *factorUno, char *factorDos) {
	realizarOperacion("MULT", factorUno, factorDos);
}

void dividir(char* dividendo, char* divisor){
	realizarOperacion("DIV", dividendo, divisor);
}

void restar(char* minuendo, char* sustraendo){
	realizarOperacion("SUBS",minuendo,sustraendo);
}

void sumar(char* sumandoUno, char* sumandoDos){
	realizarOperacion("ADD", sumandoUno, sumandoDos);
}

void asignar(char* identificador, char* valor){
	printf("Store %s,%s\n", valor, identificador);
}
