#include <stdio.h>
#include <stdlib.h>
#include "TadLEE.h"

void Inicializar(tipoListaEE *l){
    int i;
    l->tamanhoLista = 0;
    l->primeiro = -1;
    l->ultimo = -1;
    for(i=0;i<N;i++){
        l->posLivre[i] = 1; //todas livres
        l->elemento[i].valor = 0;
        l->elemento[i].prox = -1;
    }
}

int proxPosLivre(tipoListaEE *l){
    int i;
    for(i=0;i<N;i++){
        if(l->posLivre[i] == 1)
            return i;
    }
    return -1;
}

void Inserir_final(tipoListaEE *l,int posicao){
    if(posicao != -1){
        scanf("%d",&l->elemento[posicao].valor);

        if(l->tamanhoLista == 0){
            l->primeiro = posicao;
            l->ultimo = posicao;
            l->elemento[posicao].prox = -1;
            l->tamanhoLista++;
            l->posLivre[posicao] = 0;
        }
        else{
            l->elemento[l->ultimo].prox = posicao;
            l->elemento[posicao].prox = -1;
            l->tamanhoLista++;
            l->ultimo = posicao;
            l->posLivre[posicao] = 0;
        }
    }
}

void Busca(tipoListaEE *l,int v){
    int i;
    printf("\nQual elemento quer buscar na lista:");
    scanf("%d",&v);

    for(i=0;i<N;i++){
        if(l->elemento[i].valor == v)
                printf("\nValor encontrado. Ele esta na posicao %d da lista.",i+1);
    }
}

void Imprimir(tipoListaEE *l){
    int i;
    i = l->primeiro;
    do{
        printf("\n%d",l->elemento[i].valor);
        i = l->elemento[i].prox;
    }while(i != -1);
}
