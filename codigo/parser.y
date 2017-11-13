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

programa : PROGRAMA { inicioPrograma(); } cuerpoPrograma FIN { finPrograma(); if (yynerrs > 0 || lexem_error_count > 0 || semantic_error_count > 0) YYABORT; }
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
          | LEER '(' listaIdentificadores ')'  ';'
          | ESCRIBIR '(' listaExpresiones ')'  ';' { escribirIdentificador($3); } 
          | error ';'
          ;

listaIdentificadores : listaIdentificadores ',' IDENTIFICADOR { leerIdentificador($3); }
                     | IDENTIFICADOR { leerIdentificador($1); }
                     ;

listaExpresiones : listaExpresiones ',' expresion
                 | expresion
                 ;

expresion :	expresion '+' expresion { sumar($1, $3); $$ = temp_text; }
		      | expresion '-' expresion { restar($1, $3); $$ = temp_text; }
		      | expresion '/' expresion { dividir($1, $3); $$ = temp_text; }
		      | expresion '*' expresion { multiplicar($1, $3); $$ = temp_text; }
		      | '-' expresion           { invertir($2); $$ = temp_text; } %prec NEG
		      | '(' expresion ')'       { $$ = $2; }
		      | IDENTIFICADOR
		      | CONSTANTE               { declararConstante($1); }
		      ;

%%
int lexem_error_count = 0;
int semantic_error_count = 0;
void yyerror(const char *msg) {
	printf("línea #%d: %s\n", yylineno, msg);
}
