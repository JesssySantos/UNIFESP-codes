#include <stdio.h>
#include <stdlib.h>
#include "TADPilha.h"

int main(){
    Pilha p;
    int i,valor;

    Inicializar(&p);

    for(i=0;i<tamanhoMAX;i++){
        scanf("%d",&valor);
        Empilhar(&p,valor);
        valor = 0;
    }

    printf("\nTopo da pilha: %d",Consulta_topo(&p));

    printf("\nElementos da pilha:");
    Imprimir_pilha(&p);

    printf("\nDesempilhando o topo %d da pilha:%d",Consulta_topo(&p)+1,Desempilhar(&p));

    printf("\nElementos da pilha:");
    Imprimir_pilha(&p);

    return 0;
}
