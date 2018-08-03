#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    int Matricula;
    char nome[30];
    char curso[30];
    char cidade[20];
    struct aluno *prox;
};

typedef struct aluno itemAluno;

typedef struct{
    itemAluno *primeiro;
    itemAluno *ultimo;
    int tamanhoLista;
}LDE;

void Inicializa(LDE *l);
void Insere_ordenadoCRES(LDE *l,int Mat,char name[30],char course[30],char city[20]);
void Remove_p(LDE *l,int Mat);
void Imprime(LDE *l);
void Busca_porNome(LDE *l,char name[30]);
void Busca_porMat(LDE *l,int Mat);

void Inicializa(LDE *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanhoLista = 0;
}

void Insere_ordenadoCRES(LDE *l,int Mat,char name[30],char course[30],char city[20]){
    itemAluno *i,*j;
    itemAluno *novo = (itemAluno*)malloc(sizeof(itemAluno));
    novo->Matricula = Mat ;
    strcpy(novo->nome,name);
    strcpy(novo->curso,course);
    strcpy(novo->cidade,city);

    if(l->tamanhoLista == 0){
            novo->prox = NULL;
            l->primeiro = novo;
            l->ultimo = novo;
    }
    else{
        j=l->primeiro;
        for(i=l->primeiro; i!= NULL; i=i->prox){
            if(novo->Matricula <= i->Matricula)
                break;
            j=i; //antecessor
        }
        if (i == l->primeiro){  //antes do primeiro
            novo->prox = l->primeiro;
            l->primeiro = novo;
        }
        else if(i == l->ultimo){ //depois do ultimo
                i->prox = novo;
                novo->prox = NULL;
                l->ultimo=novo;
        }
        else{//meio
                j->prox = novo;
                novo->prox = i;
        }
    }
    l->tamanhoLista++;
}

void Remove_p(LDE *l,int Mat){
    itemAluno *x,*anterior,*aux;

     if(l->primeiro != NULL){
        x = l->primeiro;
        while(x->Matricula != Mat){
            anterior = x;
            x = x->prox;
        }
        aux = x->prox;
        free(x);
        anterior->prox = aux;
    }
}

void Imprime(LDE *l){
    if(l->primeiro == NULL)
        printf("\A lista esta vazia.");

    itemAluno *x;
    for(x=l->primeiro; x!= NULL; x=x->prox)
        printf("\nMatricula:%d Nome do aluno:%s Curso:%s Cidade:%s",x->Matricula,x->nome,x->curso,x->cidade);
}

void Busca_porMat(LDE *l,int Mat){
    itemAluno *x;

     for(x=l->primeiro; x!= NULL; x=x->prox){
        if(x->Matricula == Mat){
           printf("\nMatricula:%d Nome do aluno:%s Curso:%s Cidade:%s",x->Matricula,x->nome,x->curso,x->cidade);
           break;
        }
        else
            printf("\nAluno nao encontrado!");
     }
}

void Busca_porNome(LDE *l,char name[30]){
    itemAluno *x;

    for(x=l->primeiro; x!= NULL; x=x->prox){
        if(strcmp(x->nome,name)==0){
           printf("\nMatricula:%d Nome do aluno:%s Curso:%s Cidade:%s",x->Matricula,x->nome,x->curso,x->cidade);
           break;
        }
        else
            printf("\nAluno nao encontrado!");
    }
}

int main(){
    LDE alunos;
    int i,matricula;
    char NOME[30];
    char Curso[30];
    char City[30];

    Inicializa(&alunos);

    for(i=0;i<4;i++){
        printf("\nDigite a matricula do aluno:");
        scanf("%d",&matricula);
        printf("\nDigite o nome do aluno:");
        scanf("%s",NOME);
        printf("\nDigite o curso:");
        scanf("%s",Curso);
        printf("\nDigite a cidade de origem do aluno:");
        scanf("%s",City);
        Insere_ordenadoCRES(&alunos,matricula,NOME,Curso,City);
        printf("\nTamanho da lista:%d",alunos.tamanhoLista);
    }

    printf("\nDigite a matricula do Aluno que deseja pesquisar:");
    scanf("%d",&matricula);
    Busca_porMat(&alunos,matricula);

    Imprime(&alunos);

    return 0;
}






