#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int info;
    struct elemento *prox;
};

typedef struct elemento tipoElemento;

typedef struct{
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;
}LDE;

//funções
void Inicializa(LDE *l);
void Insere_inicio(LDE *l,int y);
void Insere_final(LDE *l,int y);
void Insere_ordenadoCRES(LDE *l,int y);
void Remove_p(LDE *l,int v);
void Imprime(LDE *l);
void Busca(LDE *l,int y);
