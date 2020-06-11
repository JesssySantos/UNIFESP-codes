#include <stdio.h>
#include <stdlib.h>

int calcula_Descansos(int N,int km[]){
    int i;
    int distancia_percorrida = km[1];
    int descansos = 0;

    if(km[N] <= 200 || km[N] >= 25000)
        return 0;
    for(i=1;i<=N-1;i++){
        if(distancia_percorrida + (km[i+1] - km[i]) > 200){
            distancia_percorrida = km[i+1] - km[i];
            descansos++;
        }
        else
            distancia_percorrida = distancia_percorrida + (km[i+1] - km[i]);
    }

    return descansos;
}

int main(){
    int c,i;
    int N; //num de ilhas
    scanf("%d",&N);

    int quilometragens[N];

    for(i=1;i<=N;i++)
        scanf("%d",&quilometragens[i]);

    c = calcula_Descansos(N,quilometragens);
    printf("%d",c);

    return 0;
}
