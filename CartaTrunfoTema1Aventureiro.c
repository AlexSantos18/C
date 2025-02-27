#include <stdio.h>

// Tema 1 Nivel Novato
// Finalizado
// criaçao de variaveis das cartas

char estado[3], estado2[3];
char cod_carta[5], cod_carta2[5];
char cidade[50], cidade2[50];
int populacao = 0, populacao2 = 0;
float dens_populacional = 0, dens_populacional2 = 0;
float area = 0, area2 = 0;
float pib = 0, pib2 = 0;
float pib_capita = 0, pib_capita2 = 0;
int n_turisticos = 0, n_turisticos2 = 0;

// funçao para imprimir o cabeçalho
void imprimir_cab(void){
    printf("=======================================\n");
    printf("= Cadastramento da Carta Super Trunfo =\n");
    printf("=======================================\n");

}
// funçao de titulos de Apresentação
void imprimir_dados(const char titulo[100]){
    printf("=======================================\n");
    printf("=  %s  =\n", titulo);
    printf("=======================================\n");
}

// função para entrada de dados desta forma fica mais organizado o codigo
void entrada_dados(void){
    imprimir_dados("Cadastrar Primeira Carta");
    printf("Digite a letra correspondente ao Estado: ");
    scanf(" %s", estado);
    printf("Digite o Codigo da Carta: ");
    scanf(" %s", cod_carta);
    printf("Digite a Cidade: ");
    scanf(" %[^\n]", cidade);
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
    getchar();

    imprimir_dados("Cadastrar Segunda Carta");

    printf("Digite a letra correspondente ao Estado: ");
    scanf(" %s", estado2);
    printf("Digite o Codigo da Carta: ");
    scanf(" %s", cod_carta2);
    printf("Digite a Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);
    printf("Digite a Area: ");
    scanf("%f", &area2);
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("Digite os Numeros de Pontos Turisticos: ");
    scanf("%d", &n_turisticos2);
    printf("Carta Cadastrada com Sucesso.\n");
    printf("\n");
    printf("\n");
    getchar();
    system("cls");
}

// função de saide de dados cadastrados 
void saida_dados(void){
    printf("Estado: %s\n", estado);
    printf("Codigo da Carta: %s\n", cod_carta);
    printf("Nome da Cidade: %s\n", cidade);
    printf("Populacao: %d\n", populacao);
    printf("Densidade Populacional: %.2f hab/km2\n", dens_populacional);
    printf("Area: %.2f km\n", area);
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("Pib Per Capita: %.2f reais\n ", pib_capita);
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos);
    printf("\n");
    printf("\n");

    printf("Estado: %s\n", estado2);
    printf("Codigo da Carta: %s\n", cod_carta2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Densidade Populacional: %.2f hab/km2\n", dens_populacional2);
    printf("Area: %.2f km\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pib Per Capita: %.2f reais\n", pib_capita2);
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos2);
    printf("\n");
    printf("\n");
}

void calculo_pop_pib(void){
dens_populacional = (float)(populacao / area);
pib_capita = ((pib * 1e9) / populacao); // 1e9 1 vezes 10 elevado à nona potência 1.000.000.000 um bilhao

dens_populacional2 = (float)(populacao2 / area2);
pib_capita2 = ((pib2 * 1e9) / populacao2); // 1e9 1 vezes 10 elevado à nona potência 1.000.000.000 um bilhao
}




int main() {
    
    // Inicio da solicitaçao de dados dos usuarios
    imprimir_cab();
    entrada_dados();
    calculo_pop_pib();
    
    // Impressao dos dados digitados pelo usuario
    imprimir_dados("Dados Cadastrados");
    saida_dados();

    return 0;
}