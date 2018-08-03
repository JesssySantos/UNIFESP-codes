#include <stdio.h>
#include <stdlib.h>
#include "TADgrafo_MatrizAdj.h"

int TGrafo_Inicia(TGrafo *pGrafo, int NVertices){
    TVertice u,v;

    if(NVertices > MAXvertices) //tamanho maior que o suportado
        return 0;

    pGrafo->NVertices = NVertices; //atribui o numero de vertices digitado pelo usuário ao grafo a ser criado
    pGrafo->NArestas = 0; //arestas serão criadas na inserção
    for(u=0;u < pGrafo->NVertices;u++){
        for(v=0;v < pGrafo->NVertices;v++)
            pGrafo->Adj[u][v].Incide_aresta = 0; //inicializa matriz de adjacência zerada
    }

    return 1;
}

int TGrafo_ExisteAresta(TGrafo *pGrafo, TVertice u, TVertice v){
    return pGrafo->Adj[u][v].Incide_aresta; // se 1 = existe aresta; se 0 = não existe
}

int TGrafo_InsereAresta(TGrafo *pGrafo, TVertice u, TVertice v, TAresta e){
    pGrafo->Adj[u][v].Incide_aresta = 1; //cria relação de incidência na matriz
    pGrafo->Adj[u][v].aresta = e;
    pGrafo->NArestas++;
    return 1;
}

int TGrafo_RetiraAresta(TGrafo *pGrafo, TVertice u, TVertice v, TAresta *pE){
    if(! TGrafo_ExisteAresta(pGrafo,u,v)) //se tal aresta não existir
        return 0;

    *pE = pGrafo->Adj[u][v].aresta; //ponteiro recebe aresta
    pGrafo->Adj[u][v].Incide_aresta = 0; //relação de incidência é zerada na matriz
    pGrafo->NArestas--; //diminui-se o número de arestas no Garfo
    return 1;
}

int TGrafo_NVertices(TGrafo *pGrafo){
    return (pGrafo->NVertices);
}

int TGrafo_NArestas(TGrafo *pGrafo){
    return (pGrafo->NArestas);
}

void Imprime_MatrizAdj(TGrafo *pGrafo){
    int i,j;
    for(i=0;i < pGrafo->NVertices;i++){
        for(j=0;j < pGrafo->NVertices;j++)
            printf("\t%d",pGrafo->Adj[i][j]);
        printf("\n");
    }
}


