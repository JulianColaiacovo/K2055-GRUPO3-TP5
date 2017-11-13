#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

#include "symbol.c"

void registrarIdentificador(char *identificador);
int existeIdentificador(char *identificador);
int existenIdentificadores(char *identificadorUno, char *identificadorDos);

#endif