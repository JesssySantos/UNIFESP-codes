#include <stdio.h>
#include <stdlib.h>
#include "TGrafo_porMatrizIncd.h"

int TGrafo_Inicia(TGrafo *pGrafo,int NVertices){
    TVertice u,v;

    if(NVertices > MAXvertices) //numero de vertices maior que o permitido
        return 0;

    pGrafo->NVertices = NVertices;
    pGrafo->NArestas = 0;

    return 1;
}

int TGrafo_ExisteAresta(TGrafo *pGrafo,TVertice u,TVertice v){
    TAresta e;

    for(e=0;e < pGrafo->NArestas;e++){
        if((pGrafo->Adj[u][e].IncideAresta > 0) && (pGrafo->Adj[v][e].IncideAresta < 0))
            return 1;
    }

    return 0;
}

int TGrafo_InsereAresta(TGrafo *pGrafo,TVertice u,TVertice v,TAresta e){
    TAresta i;

    if(pGrafo->NArestas >= MAXarestas)//capacidade limite de arestas excedida
        return 0;

    for(i=0;i < pGrafo->NVertices;i++)
        pGrafo->Adj[i][pGrafo->NArestas].IncideAresta = 0; //zera a matriz de incidência

    pGrafo->Adj[u][pGrafo->NArestas].IncideAresta = 1; //Vertice de saída da Aresta(PARA GRAFOS ORIENTADOS)
    pGrafo->Adj[v][pGrafo->NArestas].IncideAresta = -1; //Vertice de entrada da Aresta(PARA GRAFOS ORIENTADOS)
    pGrafo->Adj[u][pGrafo->NArestas].Aresta = 1;
    pGrafo->Adj[v][pGrafo->NArestas].Aresta = 1;
    pGrafo->NArestas++; //aumenta o numero de arestas no grafo

    return 1;
}

int TGrafo_RetiraAresta(TGrafo *pGrafo,TVertice u,TVertice v,TAresta *pE){
    TVertice i;
    TAresta e;

    if(! TGrafo_ExisteAresta(pGrafo,u,v)) //verifica a existência da aresta
        return 0;

    for(e=0;e <pGrafo->NArestas;e++){
        if((pGrafo->Adj[u][e].IncideAresta > 0) && (pGrafo->Adj[v][e].IncideAresta < 0))
            break;
    }

    *pE = pGrafo->Adj[u][e].Aresta;
    for(i=0;i < pGrafo->NVertices;i++)
        pGrafo->Adj[i][e] = pGrafo->Adj[i][pGrafo->NArestas-1];
    pGrafo->NArestas--;

    return 1;
}

int TGrafo_NVertices(TGrafo *pGrafo){
    return(pGrafo->NVertices);
}

int TGrafo_NArestas(TGrafo *pGrafo){
    return(pGrafo->NArestas);
}

void Imprime_MatrizINCD(TGrafo *pGrafo){
    int i,j;
    for(i=0;i < pGrafo->NVertices;i++){
        for(j=0;j < pGrafo->NArestas ;j++)
            printf("\t%d",pGrafo->Adj[i][j]);
        printf("\n");
    }
}

