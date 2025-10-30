#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 8

void inicializarTabuleiro(char tab[TAM][TAM])
{
    // Limpa tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = ' ';

    // Pretas
    tab[0][0] = tab[0][7] = 't';
    tab[0][1] = tab[0][6] = 'c';
    tab[0][2] = tab[0][5] = 'b';
    tab[0][3] = 'q';
    tab[0][4] = 'k';
    for (int j = 0; j < TAM; j++)
        tab[1][j] = 'p';

    // Brancas
    tab[7][0] = tab[7][7] = 'T';
    tab[7][1] = tab[7][6] = 'C';
    tab[7][2] = tab[7][5] = 'B';
    tab[7][3] = 'Q';
    tab[7][4] = 'K';
    for (int j = 0; j < TAM; j++)
        tab[6][j] = 'P';
}

void mostrarTabuleiro(char tab[TAM][TAM])
{
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", TAM - i);
        for (int j = 0; j < TAM; j++)
        {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int letraParaColuna(char letra)
{
    return toupper(letra) - 'A';
}

int validarMovimento(char peca, int li, int ci, int lf, int cf, char tab[TAM][TAM])
{
    int dr = lf - li;
    int dc = cf - ci;

    switch (tolower(peca))
    {
    case 'p': // peão
        if (isupper(peca))
            return (dr == -1 && dc == 0 && tab[lf][cf] == ' ');
        else
            return (dr == 1 && dc == 0 && tab[lf][cf] == ' ');
    case 't':
        return (li == lf || ci == cf);
    case 'c':
        return ((abs(dr) == 2 && abs(dc) == 1) || (abs(dr) == 1 && abs(dc) == 2));
    case 'b':
        return (abs(dr) == abs(dc));
    case 'q':
        return (li == lf || ci == cf || abs(dr) == abs(dc));
    case 'k':
        return (abs(dr) <= 1 && abs(dc) <= 1);
    default:
        return 0;
    }
}

int main()
{
    char tab[TAM][TAM];
    inicializarTabuleiro(tab);

    int rodada = 1;
    while (1)
    {
        mostrarTabuleiro(tab);
        printf("\nRodada %d - Jogador %s\n", rodada, rodada % 2 == 1 ? "Branco" : "Preto");

        char origem[3], destino[3];
        printf("Origem (ex: E2): ");
        scanf("%s", origem);
        printf("Destino (ex: E4): ");
        scanf("%s", destino);

        int li = TAM - (origem[1] - '0');
        int ci = letraParaColuna(origem[0]);
        int lf = TAM - (destino[1] - '0');
        int cf = letraParaColuna(destino[0]);

        char peca = tab[li][ci];
        if (peca == ' ')
        {
            printf("Não há peça na origem!\n");
            continue;
        }

        if ((rodada % 2 == 1 && islower(peca)) || (rodada % 2 == 0 && isupper(peca)))
        {
            printf("Essa peça não pertence ao jogador da vez!\n");
            continue;
        }

        if (validarMovimento(peca, li, ci, lf, cf, tab))
        {
            tab[lf][cf] = peca;
            tab[li][ci] = ' ';
            rodada++;
        }
        else
        {
            printf("Movimento inválido!\n");
        }
    }
    return 0;
}
