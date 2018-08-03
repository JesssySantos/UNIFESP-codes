#include <stdio.h>
#include "TADLDE.h"

void Inicializa(LDE *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanhoLista = 0;
}

void Insere_inicio(LDE *l,int y){
    tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));
    novo->info = y;

    if(l->tamanhoLista == 0){
        novo->prox = NULL;
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else{
       novo->prox = l->primeiro;
       l->primeiro = novo;
    }

    l->tamanhoLista++;
}

void Insere_final(LDE *l,int y){
    tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));
    novo->info = y;

    if(l->tamanhoLista == 0){
        novo->prox = NULL;
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else{
        novo->prox = NULL;
        l->ultimo->prox = novo;
        l->ultimo = novo;
    }
    l->tamanhoLista++;
}

void Insere_ordenadoCRES(LDE *l,int y){
    tipoElemento *i,*j;
    tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));
    novo->info = y;

    if(l->tamanhoLista == 0){
            novo->prox = NULL;
            l->primeiro = novo;
            l->ultimo = novo;
    }
    else{
        j=l->primeiro;
        for(i=l->primeiro; i!= NULL; i=i->prox){
            if(novo->info <= i->info)
                break;
            j=i; //antecessor
        }
        if (i == l->primeiro){  //antes do primeiro
            novo->prox = l->primeiro;
            l->primeiro = novo;
        }
        else if(i == l->ultimo){ //depois do ultimo
                i->prox = novo;
                novo->prox = NULL;
                l->ultimo=novo;
        }
        else{//meio
                j->prox = novo;
                novo->prox = i;
        }
    }
    l->tamanhoLista++;
}

void Remove_p(LDE *l,int v){
    tipoElemento *x,*aux,*anterior;
    if(l->primeiro != NULL){
        x = l->primeiro;
        while(x->info != v){
            anterior = x;
            x = x->prox;
        }
        aux = x->prox;
        free(x);
        anterior->prox = aux;
    }
}

void Imprime(LDE *l){
    if(l->primeiro == NULL)
        printf("\A lista esta vazia.");

    tipoElemento *x;
    for(x=l->primeiro; x!= NULL; x=x->prox)
        printf("\n%d",x->info);
}

void Busca(LDE *l,int z){
    tipoElemento *x;
    int cont=0;

    for(x=l->primeiro; x!= NULL; x=x->prox){
        cont++;
        if(x->info == z){
            printf("\nValor %d encontrado!.Esta na posicao %d da lista.",x->info,cont);
            break;
        }
    }

    if(cont == l->tamanhoLista)
        printf("\nValor nao esta na lista.");
}






