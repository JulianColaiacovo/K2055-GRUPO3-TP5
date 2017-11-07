#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

void inicioPrograma();
void finPrograma();

int declararIdentificador(char *identificador);

int leerIdentificador(char *identificador);
int escribirIdentificador(char *identificador);

void generarVariableTemporal();


void realizarOperacion(char* instruccion, char* variableUno, char* VariableDos);

int invertir(char *identificador);
int multiplicar(char *factorUno, char *factorDos);
int dividir(char* dividendo, char* divisor);
int restar(char* minuendo, char* sustraendo);
int sumar(char* sumandoUno, char* sumandoDos);
int asignar(char* identificador, char* valor);

#endif