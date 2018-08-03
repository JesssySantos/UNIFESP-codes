#include <stdio.h>
#include <stdlib.h>
#define LMAX 100

//TAD Lista.h
typedef struct{
    int Tamanho;
    int Primeiro;
    int Ultimo;
    int posicao;
    int lista[10];
}ListaEE;

void Inicializar(ListaEE *x);
void Inserir(ListaEE *x);
void Remover(ListaEE *x);
void Imprimir(ListaEE *x);

//TAD Lista.c
void Inicializar(ListaEE *x){
    int i;
    x->Tamanho = 0;
    x->Primeiro = -1;
    x->Ultimo = -1;
    x->posicao = 0;
    for(i=0;i<10;i++)
        x->lista[i] = 0;
}

void Inserir(ListaEE *x){
    int i,ID;
    x->posicao++;
    i = x->posicao;
    scanf("%d",&ID);
    x->lista[i] = ID;
}

void Remover(ListaEE *x){
    int i,ID;
    scanf("%d",&ID);
    for(i=0;i <= x->posicao;i++){
        if(ID == x->lista[i])
            x->lista[i] = 0;
    }
}

void Imprimir(ListaEE *x){
   int i,j,aux=0;
   for(i=0;i<x->posicao;i++){
       for(j=0;j<x->posicao;j++){
            if(x->lista[j] < x->lista[j+1]){
                aux = x->lista[j];
                x->lista[j] = x->lista[j+1];
                x->lista[j+1] = aux;
            }
       }
    }
    for(i=x->posicao;i>=0;i--){
        if(x->lista[i] != 0)
            printf("%d ",x->lista[i]);
   }
   printf("\n");
}

int main(){
    int L,i;
    char op;
    ListaEE Funcionario;
    Inicializar(&Funcionario);

    scanf("%d",&L);

    if(L <= LMAX){
        for(i=0;i<L;i++){
            scanf("\n%c",&op);
            if(op == 'E'){
                Inserir(&Funcionario);
                Imprimir(&Funcionario);
            }
            else if(op == 'S'){
                Remover(&Funcionario);
                Imprimir(&Funcionario);
            }
        }
    }

    else
        exit(1);

    return 0;
}






