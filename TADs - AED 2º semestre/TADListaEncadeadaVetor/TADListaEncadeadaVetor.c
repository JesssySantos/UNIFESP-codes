#include <stdio.h>
#include <stdlib.h>
#include "TADListaEncadeadaVetor.h"

//funcoes TAD info
int ProxPosLivre(ListaEE *l){
    int i;
    for(i=0;i<N;i++){
        if(l->posLivre[i] == 1)
            return i;
    }
    return -1;
}

//funções TAD ListaEE
void Inicializar(ListaEE *l){
    int i;
    l->tamanho = 0;
    l->primeiro = 0;
    l->ultimo = 0;
    for(i=0;i<N;i++){
        l->elementos[i].valor = 0;
        l->elementos[i].prox = -1;
        l->posLivre[i] = 1;
    }
}

void Inserir_antesPrimeiro(ListaEE *l,int p){
}



void Inserir_depoisUltimo(ListaEE *l,int p){
    if(p != -1)
        scanf("%d",&l->elementos[p].valor);

    if(l->tamanho == 0)
        l->primeiro = p;
    else{
        l->elementos[l->ultimo].prox = p;
        l->elementos[p].prox = -1;
        l->tamanho++;
        l->ultimo = p;
        l->posLivre[p] = 0;
    }
}

void Imprimir(ListaEE l){
  Info y;
  y.prox = l.elementos[l.primeiro].prox;
  printf("\n%d",y.prox);
}
