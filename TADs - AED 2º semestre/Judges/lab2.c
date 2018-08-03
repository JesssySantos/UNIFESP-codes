#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TADLista.h
struct elemento
{
    char nome[15];
    int RA;
    float mediaArr;
    struct elemento *prox;
};

typedef struct elemento Item;

typedef struct
{
    Item *primeiro;
    Item *ultimo;
    int tamanhoLista;
} LDE;

//funções
void Inicializa(LDE *l);
void Insere_ordenando(LDE *l,char name[15],int matricula,float media);
void Imprime(LDE *l);

//função adicional
float arredonda(float media)
{
    int media1;
    float aux=0;

    media1 = media;//Parte inteira da media

    aux = media - (float)media1;//ṕarte decimal

    if(aux >= 0.0 && aux < 0.5)
        return (media-aux);
    else if(aux >= 0.5)
        return media1+1;
}

//TADLista.c
void Inicializa(LDE *l)
{
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanhoLista = 0;
}

void Insere_ordenando(LDE *l,char name[15],int matricula,float media){
    Item *novo;
    novo = (Item*)malloc(sizeof(Item));

    strcpy(novo->nome,name);
    novo->RA = matricula;
    novo->mediaArr = media;

    if(novo->mediaArr >= 5){
        if(l->tamanhoLista == 0){
            novo->prox = NULL;
            l->primeiro = novo;
            l->ultimo = novo;
            l->tamanhoLista++;
        }
        else{
            Item *i,*j;
            j=l->primeiro;
                for(i=l->primeiro; i!= NULL; i=i->prox){
                    if(novo->mediaArr >= i->mediaArr)
                       break;
                    j=i; //antecessor
                }
                if (i == l->primeiro){  //antes do primeiro
                    novo->prox = l->primeiro;
                    l->primeiro = novo;
                    l->tamanhoLista++;
                }
                else if(i == l->ultimo){ //depois do ultimo
                    i->prox = novo;
                    novo->prox = NULL;
                    l->tamanhoLista++;
                    l->ultimo=novo;
                }
                else{//meio
                    j->prox = novo;
                    novo->prox = i;
                    l->tamanhoLista++;
                }
           }
    }
}

//}

void Imprime(LDE *l){
    float m;
    if(l->primeiro == NULL)
        exit(1);

    Item *x;
    for(x=l->primeiro; x!= NULL; x=x->prox){
        m = x->mediaArr;
        printf("\n%s %d %.1f",x->nome,x->RA,arredonda(m));
    }
}


int main()
{
    char aluno[15];
    int matricula,L,i;
    float P1,P2,P3,media=0;
    LDE classe;

    scanf("%d",&L); //numero de alunos inseridos
    Inicializa(&classe);

    for(i=0; i<L; i++)
    {

        scanf("%s",aluno);
        scanf("%d",&matricula);
        scanf("%f",&P1);
        scanf("%f",&P2);
        scanf("%f",&P3);

        media = (P1+P2+P3)/3;

        Insere_ordenando(&classe,aluno,matricula,media);
        //fflush(stdin);
    }

    Imprime(&classe);

    return 0;
}




