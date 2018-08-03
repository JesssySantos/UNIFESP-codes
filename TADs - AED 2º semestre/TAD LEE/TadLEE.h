#include <stdio.h>
#include <stdlib.h>
#define N 5

struct info{
    int valor;
    int prox;
};

typedef struct info tipoInfo;

struct listaEE{
    int tamanhoLista;
    int primeiro;
    int ultimo;
    int posLivre[N];
    tipoInfo elemento[N];
};

typedef struct listaEE tipoListaEE;

//funções
void Inicializar(tipoListaEE *l);
void Inserir_final(tipoListaEE *l,int posicao);
void Busca(tipoListaEE *l,int v); //retorna a posição da lista que está tal valor
void Imprimir(tipoListaEE *l);

//função tipoInfo
int proxPosLivre(tipoListaEE *l);


