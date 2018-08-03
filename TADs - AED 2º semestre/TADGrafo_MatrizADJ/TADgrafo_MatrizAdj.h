#include <stdio.h>
#include <stdlib.h>
#define MAXvertices 5

typedef int TVertice;

typedef int TAresta;

typedef struct{
    int Incide_aresta;
    TAresta aresta;
}TAdjacencia;

typedef struct{
    TAdjacencia Adj[MAXvertices][MAXvertices];
    int NVertices;
    int NArestas;
}TGrafo;

//funções
int TGrafo_Inicia(TGrafo *pGrafo, int NVertices);
int TGrafo_ExisteAresta(TGrafo *pGrafo, TVertice u, TVertice v);
int TGrafo_InsereAresta(TGrafo *pGrafo, TVertice u, TVertice v, TAresta e);
int TGrafo_RetiraAresta(TGrafo *pGrafo, TVertice u, TVertice v, TAresta *pE);
int TGrafo_NVertices(TGrafo *pGrafo);
int TGrafo_NArestas(TGrafo *pGrafo);
void Imprime_MatrizAdj(TGrafo *pGrafo);
