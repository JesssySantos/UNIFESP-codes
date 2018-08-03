#include <stdio.h>
#include <stdlib.h>
#include "TADLDE.h"

int main(){
    LDE lista;
    int info,i,p;

    Inicializa(&lista);

    for(i=0;i<5;i++){
        scanf("%d",&info);
        Insere_final(&lista,info);
        info = 0;
    }

    printf("\nDigite o valor que deseja remover:");
    scanf("%d",&info);
    Remove_p(&lista,info);

    Imprime(&lista);

    return 0;
}
