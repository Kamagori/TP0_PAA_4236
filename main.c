#include "artes.h"
#include <stdio.h>

Tela tela;
int main(){
    tela.linha = 20;
    tela.coluna = 80;

    CriaTelaEmBranco(&tela);
    int escolha = 0;

    do{
        ImprimeMenu();

        scanf("%d", &escolha);
    }

    while(EscolhaFigura(&tela, escolha));

    return 0;

}