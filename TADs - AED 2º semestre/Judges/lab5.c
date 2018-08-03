#include <stdio.h>
#include <stdlib.h>
#define maxN 100

typedef struct{
    int ID; //identificação do funcionario
    int tempo; //tempo de ligação
    int num_ligacoes;
}Funcionario;

typedef struct{
    int primeiro; //indice do primeiro elemento
    int ultimo; //indice do ultimo elemento
    Funcionario vendas[maxN];
}FilaC;

void Inicializar(FilaC *f);
int Fila_vazia(FilaC *f);
int Fila_cheia(FilaC *f);
void Inserir(FilaC *f,int N);
void Imprimir(FilaC *f,int N);

void Inicializar(FilaC *f){
    int i;
    f->primeiro = -1;
    f->ultimo = -1;
    for(i=0;i<maxN;i++){
        f->vendas[i].ID = i+1;
        f->vendas[i].tempo = 0;
        f->vendas[i].num_ligacoes = 0;
    }
}

int Fila_vazia(FilaC *f){
    if((f->primeiro == f->ultimo)&&(f->ultimo == -1))
        return 1; //fila vazia
    else
        return 0;
}

int Fila_cheia(FilaC *f){
    if(((f->ultimo + 1)% maxN) == f->primeiro)
        return 1; //fila cheia
    else
        return 0;
}

void Inserir(FilaC *f,int N){
    int time,i,j;
    int p_menor = 0;
    if (f->ultimo + 1 != N){
            scanf("%d",&time);
            if(Fila_vazia(f)==1){
                f->primeiro++;
                f->ultimo++;
                f->vendas[f->ultimo].tempo = time;
                f->vendas[f->ultimo].num_ligacoes++;
            }
            else{
                f->ultimo++;
                f->vendas[f->ultimo].tempo = time;
                f->vendas[f->ultimo].num_ligacoes++;
            }
    }
    else{
        int menor=f->vendas[f->primeiro].tempo;
        for(i=0;i<f->ultimo;i++){
            if(f->vendas[i].tempo < menor){
                p_menor = i;
                scanf("%d",&time);
                f->vendas[p_menor].tempo = f->vendas[p_menor].tempo+time;
                f->vendas[p_menor].num_ligacoes++;
            }
        }
    }
}


void Imprimir(FilaC *f,int N){
    int i;
    for(i=0;i<N;i++){
        printf("\n%d %d",f->vendas[i].ID,f->vendas[i].num_ligacoes);
    }
}

int main(){
    int N,T,i;
    FilaC vendas;

    scanf("%d %d",&N,&T);

    Inicializar(&vendas);

    for(i=0;i<T;i++)
        Inserir(&vendas,N);

    Imprimir(&vendas,N);

    return 0;
}

