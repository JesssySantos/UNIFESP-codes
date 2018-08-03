#include <stdio.h>
#include <stdlib.h>
#define LMax 100

typedef struct{
    char op; //E ou S
    int placa;
}Movimentacoes;

//TADLista.h
typedef struct{
    int ultimo;
    int tamanho;
    int lista[10];
}Lista;

void Inicializa_Lista(Lista *x);
void Inserir(Lista *x,int y);
void retirar(Lista *x,int p);

//TADLista.c
void Inicializa_Lista(Lista *x){
    int i;
    x->tamanho = 0;
    x->ultimo = -1;
}

void Inserir(Lista *x,int y){
    x->tamanho++;
    x->ultimo++;
    x->lista[x->ultimo] = y;
}

void retirar(Lista *x,int p){
    int i,cont;
    for(i=p;i < x->ultimo;i++){
        x->lista[i] = x->lista[i+1];
    }
    x->ultimo--;
    x->tamanho--;
}

int main(){
    Lista estacionamento;
    Inicializa_Lista(&estacionamento);

    int i,j,L,aux=0,cont=0;

    scanf("%d",&L);
    Movimentacoes dia[L];

    if(L <= LMax){
        for(i=0;i<L;i++){
            scanf("\n%c",&dia[i].op);
            scanf("%d",&dia[i].placa);
        }
    }
    else
        exit(1);

    for(i=0;i<L;i++){
        if(dia[i].op == 'E' && estacionamento.tamanho<10){
            Inserir(&estacionamento,dia[i].placa);
            printf("\nO carro %d foi estacionado",estacionamento.lista[estacionamento.ultimo]);
        }
        else if(dia[i].op == 'S'){
            for(j=0;j<estacionamento.tamanho;j++){
                if(estacionamento.lista[j] == dia[i].placa){
                    aux = dia[j].placa;
                    cont = j;
                }
            }
            if(j==0)
                printf("\nO carro %d foi retirado com %d manobras",estacionamento.lista[0],estacionamento.tamanho - (cont+1));
            else if(dia[i].placa == estacionamento.lista[estacionamento.ultimo])
                printf("\nO carro %d foi retirado com %d manobras",dia[i].placa,0);
            else
                printf("\nO carro %d foi retirado com %d manobras",dia[i].placa,estacionamento.tamanho - (cont+1));
        retirar(&estacionamento,i);
        }
        else if(estacionamento.tamanho == 10)
            printf("\nEstacionamento lotado");
    }

    return 0;
}

