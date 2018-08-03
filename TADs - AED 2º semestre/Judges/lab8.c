#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AutoresMAX 100
#define Infinito 10000

struct autor{
    char Nome[20];
    int n_Erdos;
} Autores[AutoresMAX];

int num_Autores;

int Ind_Autor(char *nome_autor);
void leitura(char Grafo[AutoresMAX][AutoresMAX]);
void calcula_Erdos(char Grafo[AutoresMAX][AutoresMAX]);
int compara(const void *p1,const void *p2);
void imprime();

int Ind_Autor(char *nome_autor){
    int i;
    for(i=0;i<num_Autores;i++){
        if(strcmp(nome_autor,Autores[i].Nome) == 0)
            return i;
    }
    strcpy(Autores[num_Autores].Nome,nome_autor);
    Autores[num_Autores].n_Erdos = Infinito;
    return num_Autores++;
}

void leitura(char Grafo[AutoresMAX][AutoresMAX]){
    char nome_Autor[20];
	int s, i_autores[10], i, j;
	int N=0;
	do{
		scanf("%s %s", nome_Autor, nome_Autor);
		s = nome_Autor[strlen(nome_Autor) - 1] == '.';
		nome_Autor[strlen(nome_Autor) - 1] = '\0';
		i_autores[N++] = Ind_Autor(nome_Autor);
	} while (!s);
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++)
			Grafo[i_autores[i]][i_autores[j]] = Grafo[i_autores[j]][i_autores[i]] = 1;
    }
}

void calcula_Erdos(char Grafo[AutoresMAX][AutoresMAX]){
    int vetor[AutoresMAX], ini_vetor = 0, fim_vetor = 1;
    int i,j;
	vetor[0] = Ind_Autor("Erdos");
	Autores[vetor[0]].n_Erdos = 0;
	while (ini_vetor < fim_vetor){
		i = vetor[ini_vetor++];
		for (j=0;j<num_Autores;j++){
			if (Grafo[i][j] && Autores[j].n_Erdos == Infinito){
				Autores[j].n_Erdos = Autores[i].n_Erdos + 1;
				vetor[fim_vetor++] = j;
			}
		}
	}
}

int compara(const void *p1, const void *p2){
    int aux;
	struct autor *fulano1 = (struct autor*) p1;
	struct autor *fulano2 = (struct autor*) p2;
	if ((aux = strcmp(&(fulano1->Nome), &(fulano2->Nome))) != 0)
		return aux;
	return fulano1->Nome[0] - fulano2->Nome[0];
}

void imprime(){
	int i;
	qsort(Autores,num_Autores,sizeof(struct autor),compara);
	for (i=0;i<num_Autores;i++){
		if (strcmp(Autores[i].Nome, "Erdos") != 0){
			if (Autores[i].n_Erdos == Infinito)
				printf("%s: infinito\n", Autores[i].Nome);
			else
				printf("%s: %d\n", Autores[i].Nome, Autores[i].n_Erdos);
		}
	}
}

int main(){
    char Grafo[AutoresMAX][AutoresMAX];
    int A; //numero de artigos

    scanf("%d",&A);

    while(A > 0){
        num_Autores = 0;
        memset(Grafo,0,sizeof(Grafo));

        while (A--)
            leitura(Grafo);
        scanf("%d",&A);
        calcula_Erdos(Grafo);
        imprime();
    }

    return 0;
}

