#include <stdio.h>
#include <stdlib.h>
#include "TADPilha.h"

void Inicializar(Pilha *p){
    int i;
    for(i=0;i<tamanhoMAX;i++)
        p->elementos[i] = 0;
    p->topo = -1;
}

int Pilha_vazia(Pilha *p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

int Pilha_cheia(Pilha *p){
    if(p->topo + 1 == tamanhoMAX)
        return 1;
    else
        return 0;
}

int Empilhar(Pilha *p,int valor){
    if(Pilha_cheia(p)==1)
        return -1; //aborta a função
    else{
        p->topo++;
        p->elementos[p->topo] = valor;
        return 0; //sucesso
    }
}

int Desempilhar(Pilha *p){
    if(Pilha_vazia(p) == 1)
        return -1; //aborta a função
    else{
        int aux = p->elementos[p->topo];
        p->topo--;

        return aux;
    }
}

int Consulta_topo(Pilha *p){
    if(Pilha_vazia(p) == 1)
        return -1; //aborta a função
    else
        return p->elementos[p->topo];
}

void Imprimir_pilha(Pilha *p){
    int i;
    i = p->topo;
    while(i!=-1){
        printf("\n%d",p->elementos[i]);
        i--;
    }
}

