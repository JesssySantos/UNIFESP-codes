#include <stdio.h>
#include "TadLDDE.h"

void Inicializa(LDDE *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanhoLista = 0;
}

void Insere_inicio(LDDE *l){
    tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));

    scanf("%d",&novo->info);

    if(l->tamanhoLista == 0){
        novo->prox = NULL;
        novo->ant = NULL;
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else{
        l->primeiro->ant = novo;
        novo->prox = l->primeiro;
        l->primeiro = novo;
    }
    l->tamanhoLista++;
}

void Insere_final(LDDE *l){
    tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));

    scanf("%d",&novo->info);

    if(l->tamanhoLista == 0){
        novo->prox = NULL;
        novo->ant = NULL;
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else{
        l->ultimo->prox = novo;
        novo->ant = l->ultimo;
        novo->prox = NULL;
        l->ultimo = novo;
    }
    l->tamanhoLista++;
}

void Imprimir(LDDE *l){
    tipoElemento *x;

    for(x=l->primeiro;x != NULL;x=x->prox)
        printf("\n%d",x->info);
}

tipoElemento* Busca_recursiva(tipoElemento *x,int v){
    if(x->info == v)
        return x;
    else
        return(Busca_recursiva(x->prox,v));
}



