#include "artes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ImprimeMenu()
{
    printf("Lista de opções para pintar na tela: \n");
    printf("[1] para * \n");
    printf("[2] para + \n");
    printf("[3] para X \n");
    printf("[4] para figuras aleatorias \n");
    printf("[5] para Triforce\n");
    printf("[0] para sair\n");

    printf("Escolha qual figura deseja pintar: ");
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

void CriaMais(Tela *tela, int quantos){
    int horizontal, vertical, controle = 0;

    while(controle < quantos){
        vertical = rand() % tela->linha;
        horizontal = rand() % tela->coluna;

        if (tela->matriz[vertical][horizontal] == ' ' && tela->matriz[vertical-1][horizontal] == ' ' && 
        tela->matriz[vertical][horizontal+1] == ' ' && tela->matriz[vertical+1][horizontal] == ' ' && 
        tela->matriz[vertical][horizontal-1] == ' ' && vertical < 20 && horizontal < 80){

            tela->matriz[vertical][horizontal] = '*';
            tela->matriz[vertical-1][horizontal] = '*';
            tela->matriz[vertical][horizontal+1] = '*';
            tela->matriz[vertical+1][horizontal] = '*';
            tela->matriz[vertical][horizontal-1] = '*';
            controle ++;
            
        }
    }
}

void CriaXis(Tela *tela, int quantos){
    int horizontal, vertical, controle = 0;

    while(controle < quantos){
        vertical = rand() % tela->linha;
        horizontal = rand() % tela->coluna;

        if (tela->matriz[vertical][horizontal] == ' ' && tela->matriz[vertical-1][horizontal+1] == ' ' && 
        tela->matriz[vertical+1][horizontal+1] == ' ' && tela->matriz[vertical+1][horizontal-1] == ' ' && 
        tela->matriz[vertical-1][horizontal-1] == ' ' && vertical < 20 && horizontal < 80){

            tela->matriz[vertical][horizontal] = '*';
            tela->matriz[vertical-1][horizontal+1] = '*';
            tela->matriz[vertical+1][horizontal+1] = '*';
            tela->matriz[vertical+1][horizontal-1] = '*';
            tela->matriz[vertical-1][horizontal-1] = '*';
            controle ++;
            
        }
    }
}

void PintaFiguraAleatoria(Tela *tela, int quantos){
    for (int i = 0; i < quantos; i++){
        int figura = 1 + (rand() % 3);
        if(figura == 1)
        {
            CriaAsterisco(tela, 1);
        }
        else if(figura == 2)
        {
            CriaMais(tela, 1);
        }
        else if(figura == 3)
        {
            CriaXis(tela, 1);
        }
    }
}

void CriaTriforce(Tela *tela, int quantos){
    int horizontal, vertical, controle = 0;

    while (controle < quantos){
        vertical = rand() % tela->linha;
        horizontal = rand() % tela->coluna;
        if (tela->matriz[vertical][horizontal] == ' ' && tela->matriz[vertical][horizontal+1] == ' ' && 
        tela->matriz[vertical+1][horizontal] == ' ' && tela->matriz[vertical+1][horizontal-1] == ' ' && 
        tela->matriz[vertical+1][horizontal+1] == ' ' && tela->matriz[vertical+1][horizontal+2] == ' ' && 
        vertical < 20 && horizontal < 80){
            tela->matriz[vertical][horizontal] = '/';
            tela->matriz[vertical][horizontal+1] = '\\';
            tela->matriz[vertical+1][horizontal-1] = '/';
            tela->matriz[vertical+1][horizontal] = '\\';
            tela->matriz[vertical+1][horizontal+1] = '/';
            tela->matriz[vertical+1][horizontal+2] = '\\';
            controle ++;
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
    if (quantos > 100){
        quantos = 100;
    }
    if (quantos <= 0){
        quantos = rand() % 100 + 1;
    }
    switch (escolha)
    {
        case 1:
            CriaAsterisco(tela, quantos);
            break;
        case 2:
            CriaMais(tela, quantos );
            break;
        case 3:
            CriaXis(tela, quantos  );
            break;
        case 4:
            PintaFiguraAleatoria(tela, quantos  );
            break;
        case 5:
            CriaTriforce(tela, quantos);
            break;
    }
    ImprimeTela(tela);
    return 1;
}