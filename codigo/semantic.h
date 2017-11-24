#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

extern char *temp_text;
extern int semantic_error_count;

void inicioPrograma();
void finPrograma();

void declararIdentificador(char *identificador);

void leerIdentificador(char *identificador);
void escribirIdentificador(char *identificador);

void generarVariableTemporal();

int validarIdentificadorDeclarado(char *identificador);

void invertir(char *identificador);
void multiplicar(char *factorUno, char *factorDos);
void dividir(char* dividendo, char* divisor);
void restar(char* minuendo, char* sustraendo);
void sumar(char* sumandoUno, char* sumandoDos);
void asignar(char* identificador, char* valor);

#endif
