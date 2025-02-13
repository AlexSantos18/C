#include <stdio.h>

char estado[2];
char cod_carta[5];
char cidade[50];
int populacao = 0;
float area = 0;
float pib = 0;
int n_turisticos = 0;
float dens_populacional = 0;
float pib_capita = 0;

void imprimir_cab(void){
    printf("=======================================\n");
    printf("= Cadastramento da Carta Super Trunfo =\n");
    printf("=======================================\n");

}

void imprimir_dados(void){
    printf("=======================\n");
    printf("=  Dados Cadastrados  =\n");
    printf("=======================\n");
}


void entrada_dados(void){
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
    getch();

}

void saida_dados(void){
    printf("Estado: %s\n", estado);
    printf("Codigo da Carta: %s\n", cod_carta);
    printf("Nome da Cidade: %s\n", cidade);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km\n", area);
    printf("Densidade Populacional: %.2f pessoas/km2\n", dens_populacional);
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("PIB per Capita: %.2f reais\n", pib_capita);
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos);
    printf("\n");
    printf("\n");
    getch();

}

int main() {
    
    // Inicio da solicitaçao de dados dos usuarios
    imprimir_cab();
    entrada_dados();

    // Calculo da Densidade e Per Capita
    dens_populacional = (float)(populacao / area);
    pib_capita = (float)(pib/populacao);
    
    // Impressao dos dados digitados pelo usuario
    imprimir_dados();
    saida_dados();

    return 0;
}
