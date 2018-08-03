#include <stdio.h>
#include <stdlib.h>

//TadLDDE.h
struct elemento{
    int info;
    struct elemento *prox; //sucessor
    struct elemento *ant; //antecessor
};

typedef struct elemento tipoElemento;

typedef struct{
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;
}LDDE;

//funções
void Inicializa(LDDE *l);
void Insere_inicio(LDDE *l);
void Insere_final(LDDE *l);
tipoElemento* Busca_recursiva(tipoElemento *x,int v);
void Imprimir(LDDE *l);

