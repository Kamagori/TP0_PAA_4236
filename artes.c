#include "artes.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

void ImprimeMenu()
{
    printf("Digite qual figura: \n");
    printf("[1] para * \n");
    printf("[2] para + \n");
    printf("[3] para X \n");
    printf("[4] para figuras aleatorias \n");
    printf("[5] para Triforce\n");
    printf("[0] para sair\n");

    printf("Digite aqui: ");
}

void CriaTelaEmBranco(Tela *tela)
{
    tela->matriz= (char **) malloc(sizeof(char *) * tela->linha);
    for(int i = 0; i < tela->linha; i++)
    {
        tela->matriz[i] = (char *) malloc(sizeof(char) * tela->coluna+1);
    }
    for(int i = 0; i < tela->linha; i++)
    {
        for(int j = 0; j < tela->coluna; j++)
        {
            if(i == 0 || i == 19)
            {
                tela->matriz[i][j] = '-';
            }
            else if(j == 0 || j == 79)
            {
                tela->matriz[i][j] = '|';
            }
            else
            {
                tela->matriz[i][j] = ' ';
            }
        }
    }
}

void ImprimeTela(Tela *tela){
    for (int i = 0; i < tela->linha; i++){
        printf("%s\n", tela->matriz[i]);
    }
}

void CriaAsterisco(Tela *tela, int quantos){
    int horizontal, vertical, controle = 0;

    while (controle < quantos){
        vertical = rand() % tela->linha;
        horizontal = rand() % tela->coluna;

        if (tela->matriz[vertical][horizontal] == ' ' && vertical < 20 && horizontal < 80){
            tela->matriz[vertical][horizontal] = '*';
            controle += 1;
        }
    }
}

int EscolhaFigura(Tela *tela, int escolha)
{
    if(escolha == 0)
    {
        return 0;
    }
    int quantos = 0;
    printf("Digite a quantidade de figuras: ");
    scanf("%d", &quantos);

    switch (escolha)
    {
        case 1:
            CriaAsterisco(tela, quantos);
            break;
    }
    ImprimeTela(tela);
    CriaTelaEmBranco(tela);
    return 1;
}