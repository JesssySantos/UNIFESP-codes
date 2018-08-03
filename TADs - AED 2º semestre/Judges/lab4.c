#include <stdio.h>
#include <stdlib.h>

//TadLCD-DE.h
struct elemento{
    int altura;
    struct elemento *anterior;
    struct elemento *proximo;
};

typedef struct elemento Item;

typedef struct{
    int tamanhoLista;
    Item *primeiro;
    Item *ultimo;
}LCD_DE;

//funcoes
void Inicializar(LCD_DE *l);
void Inserir_decrescente(LCD_DE *l);
void Remover_primeiro(LCD_DE *l);
void Remover_ultimo(LCD_DE *l);
void Imprimir(LCD_DE *l);

//TadLCD-DE.c
void Inicializar(LCD_DE *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanhoLista = 0;
}

void Inserir_decrescente(LCD_DE *l){
    Item *novo = (Item*)malloc(sizeof(Item));

    scanf("%d",&novo->altura);

    if(l->tamanhoLista == 0){
        l->primeiro = novo;
        l->ultimo = novo;
        novo->anterior = novo;
        novo->proximo = novo;
        l->tamanhoLista = 1;
        return;
    }
    if(novo->altura > l->primeiro->altura){//inserção antes do primeiro
        l->primeiro->anterior = novo;
        l->ultimo->proximo = novo;
        novo->anterior = l->ultimo;
        novo->proximo = l->primeiro;
        l->primeiro = novo;
        l->tamanhoLista++;
        return;
    }
    if(novo->altura < l->ultimo->altura){//inserção depois do ultimo
        l->ultimo->proximo = novo;
        l->primeiro->anterior = novo;
        novo->anterior = l->ultimo;
        novo->proximo = l->primeiro;
        l->ultimo = novo;
        l->tamanhoLista++;
        return;
    }
    //inserção no meio
    Item *x = l->primeiro;
    int i;
    for(i=0;i<l->tamanhoLista;i++){
        if(x->altura < novo->altura)
            break;
        x = x->proximo;
    }
    x->anterior->proximo = novo;
    novo->anterior = x->anterior;
    novo->proximo = x;
    x->anterior = novo;
    l->tamanhoLista++;
}

void Remover_primeiro(LCD_DE *l){
    if(l->tamanhoLista == 1){
        free(l->primeiro);
        l->primeiro = NULL;
        l->ultimo = NULL;
        l->tamanhoLista = 0;
    }
    Item *aux = l->primeiro->proximo;
    aux->anterior = l->ultimo;
    l->ultimo->proximo = aux;
    free(l->primeiro);
    l->primeiro = aux;
    l->tamanhoLista--;
}

void Remover_ultimo(LCD_DE *l){
    if (l->tamanhoLista == 1){
        Remover_primeiro(l);
        return;
    }
    Item *aux = l->ultimo;
    l->ultimo = aux->anterior;
    l->ultimo->proximo = l->primeiro;
    l->primeiro->anterior = l->ultimo;
    free(aux);
    l->tamanhoLista--;
}

void Imprimir(LCD_DE *l){
    if(l->primeiro == l->ultimo)
        printf("%d",l->primeiro->altura);
    else
        printf("%d %d ",l->primeiro->altura,l->ultimo->altura);
}

int main(){
    LCD_DE alunos;
    int i,L;
    scanf("%d",&L);

    Inicializar(&alunos);

    for(i=0;i<L;i++)
        Inserir_decrescente(&alunos);

    Imprimir(&alunos);

    if(L % 2 == 0){ //L par
        for(i=0;i<(L/2)-1;i++){
            Remover_primeiro(&alunos);
            Remover_ultimo(&alunos);
            Imprimir(&alunos);
        }
    }
    else{ //L impar
        for(i=0;i<L/2;i++){
            Remover_primeiro(&alunos);
            Remover_ultimo(&alunos);
            Imprimir(&alunos);
        }
    }

    return 0;
}



