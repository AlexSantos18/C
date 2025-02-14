#include <stdio.h>
#include <string.h>

    char estado[2];
    char cod_carta[5];
    char cidade[50];
    int populacao = 0;
    float area = 0;
    float pib = 0;
    int n_turisticos = 0;
    float dens_populacional = 0;
    float pib_capita = 0;


    // função imprimir o cabeçalho
void imprimir_cab(void){
    printf("=======================================\n");
    printf("= Cadastramento da Carta Super Trunfo =\n");
    printf("=======================================\n");

}
    // funçao imprimir o dados cadastrados
void imprimir_dados(void){
    printf("=======================\n");
    printf("=  Dados Cadastrados  =\n");
    printf("=======================\n");
}

    // funçao entrada de dados do usuario
void entrada_dados(void){
    printf("Digite a letra correspondente ao Estado: ");
    scanf(" %s", estado);
    printf("\n");
    getchar(); // limpa o buffer do teclado.

    printf("Digite o Codigo da Carta: ");
    scanf(" %s", cod_carta);
    printf("\n");
    getchar();
    
    printf("Digite a Cidade: ");
    fgets(cidade, sizeof(cidade), stdin); // ultilizado fgets pois o scanf não funcionava para strings separadas pois finaliza no espaço
    cidade[strcspn(cidade, "\n")] = '\0';  // Remove o '\n' no final da string
    getchar();
    
    printf("Digite a Populacao: ");
    scanf("%d", &populacao);
    printf("\n");
    getchar();
    
    printf("Digite a Area: ");
    scanf("%f", &area);
    printf("\n");
    getchar();
    
    printf("Digite o PIB: ");
    scanf("%f", &pib);
    printf("\n");
    getchar();
    
    printf("Digite os Numeros de Pontos Turisticos: ");
    scanf("%d", &n_turisticos);
    printf("\n");
    getchar();
    
    printf("Carta Cadastrada com Sucesso.\n");
    printf("\n");
    printf("\n");
    getch();

}
    // funçao a saida de dados cadastrados 
void saida_dados(void){
    printf("Estado: %s\n", estado);
    printf("\n");
    printf("Codigo da Carta: %s\n", cod_carta);
    printf("\n");
    printf("Nome da Cidade: %s\n", cidade);
    printf("\n");
    printf("Populacao: %d\n", populacao);
    printf("\n");
    printf("Area: %.2f km\n", area);
    printf("\n");
    printf("Densidade Populacional: %.2f pessoas/km2\n", dens_populacional);
    printf("\n");
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("\n");
    printf("PIB per Capita: %.2f reais\n", pib_capita);
    printf("\n");
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos);
    printf("\n");
    getch();

}

int main() {
    
    // Inicio da solicitaçao de dados dos usuarios
    imprimir_cab();
    entrada_dados();

    // Calculo da Densidade e Per Capita
    dens_populacional = (float)(populacao / area);
    pib_capita = (pib * 1e9 / populacao); // 1e9 1 veze 10 elevado à nona potência 1.000.000.000 um bilhao
    
    // Impressao dos dados digitados pelo usuario
    imprimir_dados();
    saida_dados();

    return 0;
}
