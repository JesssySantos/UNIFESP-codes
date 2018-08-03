#include <stdio.h>
#include <string.h>

//tadLista.h
struct elemento{
    char letra;
    struct elemento *anterior;
    struct elemento *sucessor;
};

typedef struct elemento tipoElemento;

typedef struct{
  int ListaTamanho;
  tipoElemento *primeiro;
  tipoElemento *ultimo;
}LDDE;

void Inicializar_lista(LDDE *lista);
void Inserir(LDDE *lista);
void Imprimir(LDDE *lista);

//tadLista.c
void Inicializar_lista(LDDE *lista){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->ListaTamanho = 0;
}

void Inserir(LDDE *lista){
    tipoElemento *novo = (tipoElemento*)malloc(sizeof(tipoElemento));

    scanf("%c",&novo->letra);

    if(lista->ListaTamanho == 0){
        novo->sucessor = NULL;
        novo->anterior = NULL;
        lista->primeiro = novo;
        lista->ultimo = novo;
    }
    else{
        lista->ultimo->sucessor = novo;
        novo->anterior = lista->ultimo;
        novo->sucessor = NULL;
        lista->ultimo = novo;
    }
    lista->ListaTamanho++;
}

void Imprimir(LDDE *lista){
    tipoElemento *aux;

    for(aux=lista->ultimo;aux!=NULL;aux=aux->anterior)
        printf("%c",aux->letra);
}

int main(){
    LDDE lista;
    int i,L;
    scanf("%d",&L);
    L=L+1; // \n do ENTER

    Inicializar_lista(&lista);

    for(i=0;i<L;i++)
        Inserir(&lista);

    Imprimir(&lista);
}


