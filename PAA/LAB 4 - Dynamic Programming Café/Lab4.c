#include <stdio.h>
#include <stdlib.h>

struct proposta{
    int tam_lote;
    int preco;
};

//N : numero de compradores, propostas = N
//Wi: tamanho do lote em sacas =ti
//V: valor a ser pago por cada saca
//W ou C: numero de sacas disponiveis para venda

int calcula_MaxLucro(int N,struct proposta v[],int P){
    int V[P];
    int i,j;

    V[0] = 0;
    for(j=1;j<=P;j++){
        V[j] = V[j-1];
        for(i=0;i<N;i++){
            if(v[i].tam_lote <= j && v[i].preco + V[j-v[i].tam_lote] > V[j]){
                printf("\n%d + %d = ",v[i].preco,V[j-v[i].tam_lote]);
                V[j] = v[i].preco + V[j-v[i].tam_lote];
                printf("%d",V[j]);
            }
        }
    }

    printf("\n");
    for(i=0;i<P;i++)
        printf("%d ",V[i]);

    return V[P];
}

int main(){
    int P; //sacas disponiveis
    int N; //ṕossiveis compradores
    int i;

    scanf("%d %d",&P,&N);

    struct proposta vendedores[N];

    for(i=0;i<N;i++)
        scanf("%d %d",&vendedores[i].tam_lote,&vendedores[i].preco);

    printf("%d",calcula_MaxLucro(N,vendedores,P));
    return 0;
}
