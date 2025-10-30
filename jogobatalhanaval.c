#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void inicializarTabuleiro(char tab[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = '~'; // água
}

void posicionarNavio(char tab[TAM][TAM], int *linha, int *coluna, int *horizontal)
{
    *linha = rand() % TAM;
    *coluna = rand() % (TAM - 1);
    *horizontal = rand() % 2;

    if (*horizontal)
    {
        tab[*linha][*coluna] = 'N';
        tab[*linha][*coluna + 1] = 'N';
    }
    else
    {
        tab[*linha][*coluna] = 'N';
        tab[*linha + 1][*coluna] = 'N';
    }
}

void mostrarTabuleiro(char tab[TAM][TAM], int revelar)
{
    printf("\n  A B C D E\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < TAM; j++)
        {
            if (revelar)
                printf("%c ", tab[i][j]);
            else if (tab[i][j] == 'X' || tab[i][j] == 'O')
                printf("%c ", tab[i][j]);
            else
                printf("~ ");
        }
        printf("\n");
    }
}

int letraParaColuna(char letra)
{
    return letra - 'A';
}

int main()
{
    srand(time(NULL));

    char tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    int linhaNavio, colunaNavio, horizontal;
    posicionarNavio(tabuleiro, &linhaNavio, &colunaNavio, &horizontal);

    int acertos = 0;
    int tentativas = 0;

    while (acertos < 2)
    {
        mostrarTabuleiro(tabuleiro, 0);
        printf("\nTentativa %d - Digite coordenada (ex: B3): ", tentativas + 1);

        char entrada[3];
        scanf("%s", entrada);

        int col = letraParaColuna(entrada[0]);
        int lin = entrada[1] - '1';

        if (lin < 0 || lin >= TAM || col < 0 || col >= TAM)
        {
            printf("Coordenada inválida!\n");
            continue;
        }

        if (tabuleiro[lin][col] == 'N')
        {
            tabuleiro[lin][col] = 'X';
            acertos++;
            printf("💥 Acertou!\n");
        }
        else if (tabuleiro[lin][col] == '~')
        {
            tabuleiro[lin][col] = 'O';
            printf("🌊 Água!\n");
        }
        else
        {
            printf("Você já tentou essa posição.\n");
        }

        tentativas++;
    }

    printf("\n🎉 Você venceu em %d tentativas!\n", tentativas);
    mostrarTabuleiro(tabuleiro, 1);

    return 0;
}