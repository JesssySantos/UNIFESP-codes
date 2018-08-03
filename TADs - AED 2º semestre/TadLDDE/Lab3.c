#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TadLDDE.h
struct elemento{
    char caracter;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Item;

typedef struct{
    int tamanhoLista;
    Item *primeiro;
    Item *ultimo;
}LDDE;

void Inicializa(LDDE *l);
void Insere_inicio(LDDE *l);
void Imprimir(LDDE *l);

//TadLDDE.c
void Inicializa(LDDE *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanhoLista = 0;
}

void Insere_inicio(LDDE *l){
    Item *novo = (Item*)malloc(sizeof(Item));

    scanf("%c",&novo->caracter);

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

void Imprimir(LDDE *l){
    Item *x;

    for(x=l->primeiro;x != NULL;x=x->prox)
        printf("%c",x->caracter);
}

int main(){
    LDDE bilhete;
    int L,i;
    scanf("%d",&L);

    Inicializa(&bilhete);

    for(i=0;i<L+1;i++) //L+1 frase mais \n do enter
        Insere_inicio(&bilhete);

    Imprimir(&bilhete);

    return 0;
}

