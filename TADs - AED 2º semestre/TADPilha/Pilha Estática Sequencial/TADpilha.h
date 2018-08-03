#include <stdio.h>
#include <stdlib.h>
#define tamanhoMAX 5

typedef struct{
    int topo;
    int elementos[tamanhoMAX];
}Pilha;

void Inicializar(Pilha *p);
int Pilha_vazia(Pilha *p);
int Pilha_cheia(Pilha *p);
int Empilhar(Pilha *p,int valor);
int Desempilhar(Pilha *p);
int Consulta_topo(Pilha *p);
void Imprimir_pilha(Pilha *p);
