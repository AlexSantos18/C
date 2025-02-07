#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Declaração das variaveis para utilizaçao no sistema
    char estado[2];
    char cod_carta[5];
    char cidade[50];
    int populacao = 0;
    float area = 0;
    float pib = 0;
    int n_turisticos = 0;
    
    // Inicio da solicitaçao de dados dos usuarios
    printf("Cadastramento da Carta Super Trunfo\n");
    printf("==================================\n");
    printf("Digite a letra correspondente ao Estado: ");
    scanf(" %s", estado);
    printf("Digite o Codigo da Carta: ");
    scanf(" %s", cod_carta);
    printf("Digite a Cidade: ");
    scanf(" %s", cidade);
    printf("Digite a Populacao: ");
    scanf("%d", &populacao);
    printf("Digite a Area: ");
    scanf("%f", &area);
    printf("Digite o PIB: ");
    scanf("%f", &pib);
    printf("Digite os Numeros de Pontos Turisticos: ");
    scanf("%d", &n_turisticos);
    printf("Carta Cadastrada com Sucesso.\n");
    printf("\n");
    printf("\n");
   

    // Impressao dos dados digitados pelo usuario

    printf("Dados da Carta Cadastrada\n");
    printf("===========================\n");
    printf("Estado: %s\n", estado);
    printf("Codigo da Carta: %s\n", cod_carta);
    printf("Nome da Cidade: %s\n", cidade);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km\n", area);
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos);
    printf("===========================\n");

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
