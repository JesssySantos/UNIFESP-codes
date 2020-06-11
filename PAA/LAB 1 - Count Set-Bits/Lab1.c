#include <stdio.h>
#include <math.h>

long long int Count_Set(long long int n){
    long long int x = floor(log2(n));
    long long int a = pow(2,x);
    long long int aux1,aux2,aux3;

    if(n == 0 || n == -1)
        return 0;
    else{
        aux1 = x * pow(2,x-1);
        aux2 = Count_Set(n - pow(2,x));
        aux3 = n - pow(2,x) + 1;

        return aux1+ aux2 + aux3;
    }

}

int main(){
    unsigned long long int X,Y;
    scanf("%lld %lld",&X,&Y);

    printf("%lld",Count_Set(Y) - Count_Set(X-1));
}
