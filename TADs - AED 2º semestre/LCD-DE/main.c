#include <stdio.h>
#include <stdlib.h>
#include "LCD-DE.h"

int main(){
    LCD_DE lista;
    int i;

    Inicializar(&lista);

    for(i=0;i<5;i++)
        Inserir_final(&lista);

    Imprimir(&lista);
}
