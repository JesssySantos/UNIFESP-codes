#include <stdio.h>
#include <stdlib.h>
#include "TadLDDE.h"

int main(){
    tipoElemento *x,*j;
   LDDE lista;
   int i,v;

   Inicializa(&lista);

   for(i=0;i<5;i++)
        Insere_final(&lista);

    printf("\nQue valor pretende buscar na lista?");
    scanf("%d",&v);
    for(i=0;i < lista.tamanhoLista;i++)
        j = Busca_recursiva(x,v);

    printf("\n%d",j->info);

    //Imprimir(&lista);

   return 0;
}
