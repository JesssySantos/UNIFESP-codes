#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct{
    int valor;
    int prox;
}Info;

typedef struct{
    int tamanho;
    int primeiro; //indice
    int ultimo; //indice
    int posLivre[N]; //0 ocupado e 1 livre
    Info elementos[N];
}ListaEE;

//funcoes TAD info
int ProxPosLivre(ListaEE *l);

//funções TAD ListaEE
void Inicializar(ListaEE *l);
void Inserir_antesPrimeiro(ListaEE *l,int p);
void Inserir_Meio(ListaEE *l,int p);
void Inserir_depoisUltimo(ListaEE *l,int p);
void Remover_inicio(ListaEE *l,int p);
void Remover_fim(ListaEE *l,int p);
void Remover_meio(ListaEE *l,int p);
void Imprimir(ListaEE l);
