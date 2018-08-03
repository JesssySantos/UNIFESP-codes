#include <stdio.h>
#include <stdlib.h>
#include "TadLEE.h"

int main(){
    tipoListaEE lista;
    int i,p,v;

    Inicializar(&lista);

    for(i=0;i<N;i++){
        p = proxPosLivre(&lista);
        Inserir_final(&lista,p);
    }

    Busca(&lista,v);

    return 0;
}
