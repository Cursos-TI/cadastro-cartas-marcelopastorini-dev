#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Cidade
{
    char nome[30];
    int populacao;
    double pib;
    double densidade;
    int pontosTuristicos;
    double area;
    double pibPerCapta;
};

void mostrarCarta(struct Cidade c)
{
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidade);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB per Capta: %.2f R$\n", c.pibPerCapta);
}

int main()
{
    srand(time(NULL));

    struct Cidade cidades[8] = {
        {"São Paulo", 12300000, 700.0, 7500.0, 15, 1521.0, 57000.0},
        {"Rio de Janeiro", 6700000, 350.0, 5300.0, 20, 1182.0, 52000.0},
        {"Curitiba", 1900000, 90.0, 4300.0, 10, 435.0, 47000.0},
        {"Fortaleza", 2700000, 65.0, 7800.0, 12, 314.0, 24000.0},
        {"Belo Horizonte", 2500000, 85.0, 7200.0, 11, 330.0, 34000.0},
        {"Salvador", 2900000, 60.0, 8000.0, 18, 693.0, 21000.0},
        {"Recife", 1600000, 50.0, 7800.0, 14, 218.0, 31000.0},
        {"Porto Alegre", 1500000, 75.0, 2900.0, 13, 496.0, 50000.0}};

    int i1 = rand() % 8;
    int i2 = rand() % 8;
    while (i2 == i1)
    {
        i2 = rand() % 8;
    }

    struct Cidade jogador1 = cidades[i1];
    struct Cidade jogador2 = cidades[i2];

    printf("🧍 Carta do Jogador 1:\n");
    mostrarCarta(jogador1);

    int escolha;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - PIB\n");
    printf("3 - Densidade Demográfica\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Área\n");
    printf("6 - PIB per Capta\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &escolha);

    printf("\n🧍 Carta do Jogador 2:\n");
    mostrarCarta(jogador2);

    double valor1 = 0, valor2 = 0;

    if (escolha == 1)
    {
        valor1 = jogador1.populacao;
        valor2 = jogador2.populacao;
    }
    else if (escolha == 2)
    {
        valor1 = jogador1.pib;
        valor2 = jogador2.pib;
    }
    else if (escolha == 3)
    {
        valor1 = jogador1.densidade;
        valor2 = jogador2.densidade;
    }
    else if (escolha == 4)
    {
        valor1 = jogador1.pontosTuristicos;
        valor2 = jogador2.pontosTuristicos;
    }
    else if (escolha == 5)
    {
        valor1 = jogador1.area;
        valor2 = jogador2.area;
    }
    else if (escolha == 6)
    {
        valor1 = jogador1.pibPerCapta;
        valor2 = jogador2.pibPerCapta;
    }
    else
    {
        printf("Atributo inválido.\n");
        return 1;
    }

    printf("\n🔍 Comparando atributo escolhido:\n");
    printf("Jogador 1: %.2f\n", valor1);
    printf("Jogador 2: %.2f\n", valor2);

    if (valor1 > valor2)
    {
        printf("🏆 Jogador 1 venceu!\n");
    }
    else if (valor2 > valor1)
    {
        printf("🏆 Jogador 2 venceu!\n");
    }
    else
    {
        printf("🤝 Empate!\n");
    }

    return 0;
}