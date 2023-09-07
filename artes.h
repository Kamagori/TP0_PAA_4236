#include <stddef.h>
#ifndef TP0_PAA_Artes_h
#define TP0_PAA_Artes_h

typedef struct tela{

    int linha, coluna;
    char **matriz;

}Tela;

void CriaTelaEmBranco(Tela *tela);
void ImprimeTela(Tela *tela);
void CriaAtesrisco(Tela *tela, int quantos);
void CriaMais(Tela *tela, int quantos);
void CriaXis(Tela *tela, int quantos);
void PintaFiguraAleatoria(Tela *tela, int quantos);
void CriaTriforce(Tela *tela, int quantos);
int EscolhaFigura(Tela *tela, int escolha);
void ImprimeMenu();

#endif //TP0_PAA_Artes_h