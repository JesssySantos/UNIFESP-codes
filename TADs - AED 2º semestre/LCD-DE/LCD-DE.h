#include <stdio.h>
#include <stdlib.h>

//TadLCD-DE.h
struct elemento{
    int info;
    struct elemento *anterior;
    struct elemento *proximo;
};

typedef struct elemento tipoElemento;

typedef struct{
    int tamanhoLista;
    tipoElemento *primeiro;
    tipoElemento *ultimo;
}LCD_DE;

//funções
void Inicializar(LCD_DE *l);
void Inserir_inicio(LCD_DE *l);
void Inserir_final(LCD_DE *l);
void Imprimir(LCD_DE *l);

