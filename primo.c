#include<stdio.h>


int main(){

    int num,div,cont,soma=0;
    int n;

    scanf("%d",&n);

    for(num=1;num<=n;num++){

         cont = 0;

         for(div=2;div<=num/2;div++){
             if(num%div==0){
                 cont++;
                 break;
             }
        }

         if(cont==0 && num!= 1)
             soma = soma + num;
    }

    printf("%d",soma);

   return 0;
}
