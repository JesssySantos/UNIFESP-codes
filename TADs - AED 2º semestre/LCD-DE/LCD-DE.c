#include <stdio.h>
#include "LCD-DE.h"

void Inicializar(LCD_DE *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanhoLista = 0;
}

void Inserir_inicio(LCD_DE *l){
    tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));

    scanf("%d",&novo->info);

    if(l->tamanhoLista == 0){
        l->primeiro = novo;
        l->ultimo = novo;
        novo->anterior = novo;
        novo->proximo =  novo;
    }
    else{
        l->primeiro->anterior = novo;
        l->ultimo->proximo = novo;
        novo->anterior = l->ultimo;
        novo->proximo = l->primeiro;
        l->primeiro = novo;
    }
    l->tamanhoLista++;
}

void Inserir_final(LCD_DE *l){
      tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));

    scanf("%d",&novo->info);

    if(l->tamanhoLista == 0){
        l->primeiro = novo;
        l->ultimo = novo;
        novo->anterior = novo;
        novo->proximo =  novo;
    }
    else{
            l->ultimo->proximo = novo;
            l->primeiro->anterior = novo;
            novo->anterior = l->ultimo;
            novo->proximo = l->primeiro;
            l->ultimo = novo;
    }
    l->tamanhoLista++;
}

void Imprimir(LCD_DE *l){
    if(l->tamanhoLista == 0)
        printf("\nLista vazia!");
    else{
        tipoElemento *aux = l->primeiro;
        printf("\n%d",aux->info);
        aux = aux->proximo;
        while(aux != l->primeiro){
            printf("\n%d",aux->info);
            aux = aux->proximo;
        }
    }
}





