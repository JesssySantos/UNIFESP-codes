#include <stdio.h>
#include <stdlib.h>


/*

PARA O CODIGO DISPONIBILIZADO: ALTERACAO PERMITIDA APENAS NOS ESPACOS INDICADOS
ALTERACOES NAS ESTRUTURAS E QUALQUER OUTRA PARTE DO CODIGO RESULTARA NA ANULACAO DA QUESTAO

*/


struct arvoreBB {
    int info;
    struct arvoreBB* esq;
    struct arvoreBB* dir;
};
typedef struct arvoreBB tipoArvoreBB;

void inicializa (int c, tipoArvoreBB *arvoreAux){
 arvoreAux->info = c;
 arvoreAux->esq = NULL;
 arvoreAux->dir=NULL;
}

tipoArvoreBB* criaArvore(int c) {
    tipoArvoreBB* novo = (tipoArvoreBB*) malloc(sizeof(tipoArvoreBB));
    novo->info = c;
    novo->dir = NULL;
    novo->esq= NULL;
    return novo;
}

tipoArvoreBB* insereNo(int c) {
    tipoArvoreBB* novo = (tipoArvoreBB*) malloc(sizeof(tipoArvoreBB));
    novo->info = c;
    novo->dir = NULL;
    novo->esq= NULL;
    return novo;
}

void emOrdem(tipoArvoreBB *Aux){
    if (Aux!= NULL){
        emOrdem(Aux->esq);
        printf("%d ", Aux->info);
        emOrdem(Aux->dir);
    }
}


void insereABB (int info, tipoArvoreBB *Aux){
     if(info < Aux->info){
        if(Aux->esq == NULL)
            Aux->esq = insereNo (info);
        else
            insereABB (info,Aux->esq);
    }
    else if (info > Aux->info){
        if (Aux->dir == NULL)
            Aux->dir = insereNo(info);
        else insereABB (info,Aux->dir);
    }
}


tipoArvoreBB *maiorValor(tipoArvoreBB *aux){



/* ****************


 COMPLETAR AQUI


***************** */

}


tipoArvoreBB* removeABB (tipoArvoreBB *Aux, int info){
    if (Aux == NULL)
         return NULL;
	 else if (info > Aux->info)
         Aux->dir = removeABB(Aux->dir,info);
	 else if (info < Aux->info)
         Aux->esq = removeABB(Aux->esq,info);
	 else{
         if (Aux->esq == NULL)
             Aux = Aux->dir;
         else if (Aux->dir == NULL)
             Aux = Aux->esq;
         else{
             int i = 0;
             tipoArvoreBB* anterior = Aux;
             tipoArvoreBB* atual = anterior->esq;
             while(atual->dir != NULL){
                 anterior = atual;
                 atual = atual->dir;
                 i = 1;
             }
             if(i == 0)
                 anterior->esq = NULL;
             else
                 anterior->dir = NULL;
             Aux->info = atual->info;
             if (atual->esq != NULL){
                 if(atual->esq->info > anterior->info)
                     anterior->dir = atual->esq;
                 else
                     anterior->esq = atual->esq;
             }
         }
     }
	 return Aux;

}



int main(){

  tipoArvoreBB *minhaRaiz=NULL, *p=NULL;

  int n1, valor;
  char c;

  scanf("%d", &n1);


  while (n1 > 0)
    {

        /*
           SINTAXE DE ENTRADA
           N = NUMERO DE INSTRUCOES QUE SERAO LIDAS USANDO A SINTAXE (COMANDO <ESPACO> VALOR)

           COMANDOS:

           I = INSERIR
           R = REMOVER
           P = IMPRIMIR EM ORDEM

           EXEMPLO DE ENTRADA: 10 I 10 I 2 I 30 I 6 R 2 R 10 I 5 I 20 I 19 P 0
           EXEMPLO DE SAIDA: 5 6 19 20 30

           OBS: O CASO DE REMOCAO DE ELEMENTOS COM DOIS FILHOS SEGUE A REGRA DE SUBSTITUICAO PELO MAIOR ELEMENTO DA SUB-ARVORE DA ESQUERDA.

        */

        scanf(" %c", &c);
        scanf("%d", &valor);


        if (c=='I'){
            if (minhaRaiz == NULL) minhaRaiz = criaArvore(valor);
            else insereABB (valor, minhaRaiz);}
        if (c=='R') {minhaRaiz=removeABB(minhaRaiz,valor);}
        if (c=='P') {emOrdem(minhaRaiz);}
        n1--;
    }


    return 0;
}

