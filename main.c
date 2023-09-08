#include "artes.h"
#include <stdio.h>

Tela tela;
int main(){
    tela.linha = 20;
    tela.coluna = 80;

    printf("\n \nTela em Branco: \n \n");

    CriaTelaEmBranco(&tela);
    ImprimeTela(&tela);
    int escolha = 0;

    do{
        ImprimeMenu();

        scanf("%d", &escolha);
    }

    while(EscolhaFigura(&tela, escolha));

    return 0;

}