#include <stdio.h>
#include <stdlib.h>
#include "TADgrafo_MatrizAdj.h"

int main(){
    TGrafo g;
    int i,N,M;
    TVertice v1,v2;
    TAresta e = 1;
    printf("Insira o numero de vertices do grafo: ");
    scanf("%d",&N);
    TGrafo_Inicia(&g,N);
    printf("\nInsira o numero de arestas do grafo: ");
    scanf("%d",&M);

    if(N <= MAXvertices){
        for(i=0;i<M;i++){
            printf("\nInsira o primeiro vertice: "); //considerar que 0 é o primeiro vértice do Grafo
            scanf("%d",&v1);
            printf("\nInsira o segundo vertice: ");
            scanf("%d",&v2);
            TGrafo_InsereAresta(&g,v1,v2,1);
            printf("\nAresta criada com sucesso!");
        }
    }

    printf("\n");
    Imprime_MatrizAdj(&g);

    return 0;
}

