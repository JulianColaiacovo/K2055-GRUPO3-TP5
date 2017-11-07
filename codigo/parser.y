%{
#include <stdio.h>
#include "scanner.h"
#include "semantic.h"
%}

%defines "parser.h"
%output "parser.c"
%define parse.error verbose


%code provides {
	extern int yynerrs;
	extern int lexem_error_count;
	extern int semantic_error_count;
	void yyerror(const char *);
}
%define api.value.type {char *}

%token PROGRAMA VARIABLES DEFINIR CODIGO LEER ESCRIBIR FIN IDENTIFICADOR CONSTANTE ASIGNACION

%left '-' '+'
%left '*' '/'
%precedence NEG

%%

programa : {inicioPrograma()} programa cuerpoPrograma fin { finPrograma(); if (yynerrs > 0 || lexem_error_count > 0 || semantic_error_count > 0) YYABORT; }
         ;

cuerpoPrograma : VARIABLES listaDeclaraciones CODIGO listaSentencias
               ;

listaDeclaraciones : listaDeclaraciones declaracion
                   | declaracion
                   ;

declaracion : DEFINIR IDENTIFICADOR ';' { declararIdentificador($2); }
            | error ';'
            ;

listaSentencias : listaSentencias sentencia
                | sentencia
                ;

sentencia : IDENTIFICADOR ASIGNACION expresion ';' { asignar($1, $3); }
          | LEER '(' listaIdentificadores ')'  ';' { leerIdentificador($3); }
          | ESCRIBIR '(' listaExpresiones ')'  ';' { escribirIdentificador($3); } 
          | error ';'
          ;

listaIdentificadores : listaIdentificadores ',' IDENTIFICADOR
                     | IDENTIFICADOR
                     ;

listaExpresiones : listaExpresiones ',' expresion
                 | expresion
                 ;

expresion :	expresion '+' expresion { sumar($1, $3); }
		  | expresion '-' expresion { restar($1, $3); }
		  | expresion '/' expresion { dividir($1, $3); }
		  | expresion '*' expresion { multiplicar($1, $3); }
		  | '-' expresion           { invertir($2); $$ = temp_text; } %prec NEG
		  | '(' expresion ')'       { printf("paréntesis\n"); }
		  | IDENTIFICADOR
		  | CONSTANTE
		  ;

programa : PROGRAMA { inicioPrograma(); }
         ;

fin : FIN { finPrograma(); }
    ;

%%
int lexem_error_count = 0;
int semantic_error_count = 0;
void yyerror(const char *msg) {
	printf("línea #%d: %s\n", yylineno, msg);
}
