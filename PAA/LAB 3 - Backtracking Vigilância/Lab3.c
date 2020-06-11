#include <stdio.h>
#include <stdlib.h>

typedef int TColuna;

typedef struct{
    TColuna idx;
    int visitado;
    int usr_input; //caso seja umas das M guaritas fixas dadas pelo usuário
}TGuarita;

typedef struct{
    int x;
    int y;
}TCoordenada;

int Verifica_Solucao(int ini, int fim){
    if(ini != fim-1)
        return(0);
    else
        return(1);
}

void Mover(TGuarita problem[],int cand[],int pos){
    problem[cand[pos]].visitado = 1;
}

void Desfaz_Movimento(TGuarita problem[],int cand[],int pos){
    problem[cand[pos]].visitado = 0;
}

void Imprime_Solucao(TGuarita problem[],int cont){
    int i;

    if(cont > 0){
        for(i=1;i<cont;i++){
            if(i < cont-1)
                printf("%d ",problem[i].idx);
            else
                printf("%d",problem[i].idx);
        }
        printf("\n");
    }

}

void Constroi_Candidatos(TGuarita problem[],int ini,int fim,int cand[],int *n_cand){
    int i;
    *n_cand = 1;

    for(i=1;i<fim;i++){
        if(problem[i].visitado == 0){
            cand[*n_cand] = i;
            *n_cand = *n_cand + 1;
        }
    }
}

void Processa_Solucao(TGuarita problem[],int ini,int fim){
    int i, ctrl = 1;

    for(i=1;i<fim;i++){
        if(problem[i].usr_input != 0){
            if(problem[i].usr_input != problem[i].idx){
                ctrl = 0;
                break;
            }
        }
    }

    if(ctrl == 1)
        Imprime_Solucao(problem,fim);
}

void Backtracking(TGuarita problem[],int ini,int fim){
    int current_candidates[fim];
    int i;
    int num_candidatos;

    if(Verifica_Solucao(ini,fim) == 1)
        Processa_Solucao(problem,ini,fim);
    else{
        ini++;
        Constroi_Candidatos(problem,ini,fim,current_candidates,&num_candidatos);

        for(i=1;i<num_candidatos;i++){
            problem[ini].idx = current_candidates[i];
            Mover(problem,current_candidates,i);
            Backtracking(problem,ini,fim);
            Desfaz_Movimento(problem,current_candidates,i);
        }
    }
}

int main(){
    int i,n,N,M;
    scanf("%d %d",&N,&M);
    TCoordenada guaritas_fixas[M];
    n = N+1;

    if(N > 0){
        n = N+1;
        TGuarita all_candidatos[n];

        for(i=0;i<n;i++){
            all_candidatos[i].visitado = 0;
            all_candidatos[i].usr_input = 0;
        }

        for(i=0;i<M;i++){
            scanf("%d %d",&guaritas_fixas[i].x,&guaritas_fixas[i].y);
            all_candidatos[guaritas_fixas[i].y].usr_input = guaritas_fixas[i].x;
        }

        Backtracking(all_candidatos,0,n);
    }

    return 0;
}
