#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de cidade
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para calcular a densidade populacional
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta* carta) {
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);

    printf("Digite a populacao: ");
    scanf("%d", &carta->populacao);

    printf("Digite a area (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    printf("\n");
}

// Função para exibir uma carta
void exibirCarta(struct Carta carta) {
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", calcularDensidade(carta.populacao, carta.area));
    printf("------------------------------\n");
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("Cadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    // Exibir ambas as cartas
    printf("\n--- Cartas Cadastradas ---\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Comparação com base na menor densidade populacional
    float dens1 = calcularDensidade(carta1.populacao, carta1.area);
    float dens2 = calcularDensidade(carta2.populacao, carta2.area);

    printf("\nResultado da Comparação:\n");
    if (dens1 < dens2) {
        printf("A carta vencedora é: %s (menor densidade populacional)\n", carta1.nome);
    } else if (dens2 < dens1) {
        printf("A carta vencedora é: %s (menor densidade populacional)\n", carta2.nome);
    } else {
        printf("Empate! As duas cidades têm a mesma densidade populacional.\n");
    }

    return 0;
}
