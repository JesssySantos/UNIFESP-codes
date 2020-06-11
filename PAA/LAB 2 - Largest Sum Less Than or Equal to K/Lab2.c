#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define MAX 100000

void Merge(int A[],int ini,int mid,int fim){
    int i, mi, k, p, aux[MAX];

    p = ini;
    i = ini;
    mi = mid + 1;

    while ((p <= mid) && (mi <= fim)){
        if (A[p] <= A[mi]){
            aux[i] = A[p];
            p++;
        }
        else{
            aux[i] = A[mi];
            mi++;
        }
        i++;
    }

    if (p > mid){
        for (k = mi; k <= fim; k++){
            aux[i] = A[k];
            i++;
        }
    }
    else{
        for (k = p; k <= mid; k++){
             aux[i] = A[k];
             i++;
        }
    }

    for (k = ini; k <= fim; k++)
        A[k] = aux[k];
}

void MergeSort(int A[],int ini,int fim){
    int mid;

    if(ini < fim){
        mid = (ini + fim) / 2;
        MergeSort(A, ini, mid);
        MergeSort(A, mid + 1, fim);
        Merge(A, ini, mid, fim);
    }
}

int Existe_Soma(int A[],int n,int K){
    int i = 0;
    int j = n - 1;
    int ctrl = -1;

    while(i < j){
        if(A[i] + A[j] > K)
            j--;
        else{
            ctrl = max(ctrl,A[i] + A[j]);
            i++;
        }
    }
    return ctrl;
}



int main(){
    int i,N,C;
    scanf("%d %d",&N,&C);
    int Music[N];
    int resp;

    for(i=0;i<N;i++)
        scanf("%d",&Music[i]);

    MergeSort(Music,0,N-1);
    resp = Existe_Soma(Music,N,C);

    if(resp > 0)
        printf("%d",resp);
    else
        printf("NONE");
    return 0;
}
