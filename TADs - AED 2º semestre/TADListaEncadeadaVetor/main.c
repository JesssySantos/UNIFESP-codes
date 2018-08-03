#include <stdio.h>
#include <stdlib.h>
#include "TADListaEncadeadaVetor.h"

int main(){
    ListaEE x;
    int i,aux=0;

    Inicializar(&x);

    for(i=0;i<N;i++){
        aux = ProxPosLivre(&x);
        Inserir_depoisUltimo(&x,aux);
        aux=0;
    }

    Imprimir(x);

    return 0;
}
