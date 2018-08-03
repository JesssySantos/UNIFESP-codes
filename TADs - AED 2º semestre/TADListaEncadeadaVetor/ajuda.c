#include <stdio.h>
#include <stdlib.h>

    struct listaEE
    {
        int pos;
        int elemento[10];
    };
    typedef struct listaEE listafunc;

    void entrada (listafunc *funcionario)
    {
        int num,x;
        x = funcionario->pos;
        scanf("%d", &num);
        funcionario->elemento[x]=num;
    }

    void saida (listafunc *funcionario)
    {
        int num, i;
        scanf("%d", &num);
        for(i=0; i <= funcionario->pos; i++) //*
        {
            if(num == funcionario->elemento[i])
                funcionario->elemento[i]=NULL; //*
        }
    }

    void printar(listafunc *funcionario)
    {
        int temp, i, j;
        for(j=0; j<funcionario->pos; j++)
            for(i=0; i<funcionario->pos; i++)
            {
                if(funcionario->elemento[i]<funcionario->elemento[i+1])
                {
                    temp = funcionario->elemento[i];
                    funcionario->elemento[i] = funcionario->elemento[i+1];
                    funcionario->elemento[i+1] = temp;
                }
            }
        for(i=funcionario->pos; i>0; i--)
        {
            if(funcionario->elemento[i]!= NULL)
            printf("%d ", funcionario->elemento[i]);
        }

    printf("\n");
    }


    int main()
    {
        int mov, i;
        char com;
        listafunc funcionario;
        funcionario.pos = 0;
        scanf("%d", &mov);
        for(i=0; i<mov; i++)
        {
            scanf("\n%c", &com);
            if (com == 'E')
            {
                    funcionario.pos++;
                    entrada(&funcionario);
                    printar(&funcionario);

            }

            //-------------------------------------------
            if (com == 'S')
            {
                saida(&funcionario);
                printar (&funcionario);
                funcionario.pos--;
            }

        }
        return 0;
    }
