#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char op;
    int ID;
}Movs;

//TAD Lista.h
typedef struct{
    int Tamanho;
    int Primeiro;
    int Ultimo;
    int posicao;
    int lista[10];
}ListaEE;

void Inicializar(ListaEE *x);
void Inserir(ListaEE *x,char y);
void Remover(ListaEE *x,char y);
void Imprimir(ListaEE x);

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

void Inserir(ListaEE *x,char y){
    int i;
    x->posicao++;
    i = x->posicao;
    x->lista[i] = y;
}

void Remover(ListaEE *x,char y){
    int i;
    x->posicao--;
    for(i=0;i < x->posicao+1;i++){
        if(y == x->lista[i])
            x->lista[i] = NULL;
    }
}

void Imprimir(ListaEE x){
    int i,j,aux=0;
    for(i=0;i < x.posicao;i++){
        for(j=i+1;j < x.posicao;j++){
            if(x.lista[i] > x.lista[j]){
                aux = x.lista[i];
                x.lista[i] = x.lista[j];
                x.lista[j] = aux;
            }
        }
    }
    for(i=x.posicao;i>0;i--){
        if(x.lista[i] != NULL)
            printf("%d ",x.lista[i]);
    }
    printf("\n");
}

int main(){
    int L,i;
    ListaEE Funcionario;
    Inicializar(&Funcionario);

    scanf("%d",&L);
    Movs dia[L];

    for(i=0;i<L;i++){
        scanf("\n%c",&dia[i].op);
        scanf("%d",&dia[i].ID);
    }

    printf("\n");
    for(i=0;i<L;i++){
        if(dia[i].op == 'E'){
            Inserir(&Funcionario,dia[i].ID);
            Imprimir(Funcionario);
        }
        else if(dia[i].op == 'S'){
            Remover(&Funcionario,dia[i].ID);
            Imprimir(Funcionario);
        }
    }

    return 0;
}

