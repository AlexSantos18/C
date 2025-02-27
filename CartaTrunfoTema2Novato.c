#include <stdio.h>

    // Tema 2 Desafio Nivel Novato
    // Finalizado

    // Declaração de variaveis

    char estado[2], estado2[2];
    char cod_carta[5], cod_carta2[5];
    char cidade[50], cidade2[50];
    unsigned long int populacao = 0, populacao2 = 0;
    float area = 0, area2 = 0;
    float pib = 0, pib2 = 0;
    int n_turisticos = 0, n_turisticos2 = 0;
    float dens_populacional = 0, dens_populacional2 = 0;
    float pib_capita = 0, pib_capita2 = 0;
    double poder = 0, poder2 = 0;


    // função imprimir o cabeçalho
void imprimir_cab(void){
    printf("=======================================\n");
    printf("= Cadastramento da Carta Super Trunfo =\n");
    printf("=======================================\n");
    printf("\n");
}
    // funçao imprimir o dados cadastrados
// funçao de titulos de Apresentação
void imprimir_dados(const char titulo[100]){
    printf("=======================================\n");
    printf("=  %s  =\n", titulo);
    printf("=======================================\n");
}


    // funçao entrada de dados do usuario CARTA 1
void entrada_dados(void){
    imprimir_dados("Cadastrar Primeira Carta");
    printf("Digite a letra correspondente ao Estado: ");
    scanf(" %s", estado);
    printf("Digite o Codigo da Carta: ");
    scanf(" %s", cod_carta);
    printf("Digite a Cidade: ");
    scanf(" %[^\n]", cidade);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao);
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
    scanf("%lu", &populacao2);
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

     // funçao a saida de dados cadastrados 
void saida_dados(void){
    printf("Estado: %s\n", estado);
    printf("Codigo da Carta: %s\n", cod_carta);
    printf("Nome da Cidade: %s\n", cidade);
    printf("Populacao: %lu\n", populacao);
    printf("Densidade Populacional: %.2f hab/km2\n", dens_populacional);
    printf("Area: %.2f km\n", area);
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("Pib Per Capita: %.2f reais\n ", pib_capita);
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos);
    printf("Super Poder: %.2lf\n", poder);
    printf("\n");
    printf("\n");

    printf("Estado: %s\n", estado2);
    printf("Codigo da Carta: %s\n", cod_carta2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Densidade Populacional: %.2f hab/km2\n", dens_populacional2);
    printf("Area: %.2f km\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pib Per Capita: %.2f reais\n", pib_capita2);
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos2);
    printf("Super Poder: %.2lf\n", poder2);
    printf("\n");
    printf("\n");
    getchar();

}
    // Calculo da Densidade Populacional e o Pib Per Capita
void calculo_pop_pib(void){
    dens_populacional = (float)(populacao / area);
    pib_capita = ((pib * 1e9) / populacao); // 1e9 1 vezes 10 elevado à nona potência 1.000.000.000 um bilhao
    
    dens_populacional2 = (float)(populacao2 / area2);
    pib_capita2 = ((pib2 * 1e9) / populacao2); // 1e9 1 vezes 10 elevado à nona potência 1.000.000.000 um bilhao
}
    // Calculo do Super poder
void super_poder(void){ 
    float inverso_densidade = 0, inverso_densidade2 = 0;
    inverso_densidade = 1.0 / dens_populacional;
    inverso_densidade2 = 1.0 / dens_populacional2;
    poder = (populacao + area + pib + pib_capita + n_turisticos + inverso_densidade);
    poder2 = (populacao2 + area2 + pib2 + pib_capita2 + n_turisticos2 + inverso_densidade2); 
}
int main() {

    // Inicio da solicitaçao de dados dos usuarios
    imprimir_cab();
    entrada_dados();
    system("cls"); // quando compilado no vscode windows do contrario no linux usar o clear
    calculo_pop_pib();
    super_poder();

       // Impressao dos dados digitados pelo usuario

    imprimir_dados("Cartas Cadastradas");
    system("cls");
    

    // Comparação das cartas

    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem uma Populacao %lu \nCarta 2 %s tem uma Populacao %lu\n", cidade, populacao, cidade2, populacao2);
    if (populacao > populacao2){
            printf("A Carta 1 %s foi a Vencedora\n", cidade); 
        } else{
            printf("A Carta 2 %s foi a Vencedora\n", cidade2);
        } 
    printf("\n");

    printf("Carta 1 %s tem uma Area %.2f\nCarta 2 %s tem uma Area %.2f\n", cidade, area, cidade2, area2);
    if (area > area2){
            printf("A Carta 1 %s foi a Vencedora\n", cidade); 
        }else {
            printf("A Carta 2 %s foi a Vencedora\n", cidade2);
        }
    printf("\n");
    
    printf("Carta 1 %s tem um PIB %.2f\nCarta 2 %s tem um PIB %.2f\n", cidade, pib, cidade2, pib2);
    if (pib > pib2){
            printf("A Carta 1 %s foi a Vencedora\n", cidade); 
        }else {
            printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
    
    printf("Carta 1 %s tem Pontos Turisticos %d\nCarta 2 %s tem Pontos Turisticos %d\n", cidade, n_turisticos, cidade2, n_turisticos2);
    if (n_turisticos > n_turisticos2){
            printf("A Carta 1 %s foi a Vencedora\n", cidade); 
        }else {
            printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");

    printf("Carta 1 %s tem uma Densidade Populacional %.2f\nCarta %s tem uma Densidade Populacional %.2f\n", cidade, dens_populacional, cidade2, dens_populacional2);
    // densidade a menor vence
    if (dens_populacional < dens_populacional2){
            printf("A Carta 1 %s foi a Vencedora\n", cidade); 
        }else{
            printf("A Carta 2 %s foi a Vencedora\n", cidade2);
        }
    printf("\n");

    printf("Carta 1 %s tem um PIB per Capita %.2f\nCarta 2 %s tem um PIB per Capita %.2f\n", cidade, pib_capita, cidade2, pib_capita2);
    if (pib_capita > pib_capita2){
            printf("A Carta 1 %s foi a Vencedora\n", cidade); 
        }else {
            printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");

    printf("Carta 1 %s tem um Super Poder %.2lf\nCarta 2 %s tem um Super Poder %.2lf\n", cidade, poder, cidade2, poder2);
    if (poder > poder2){
            printf("A Carta 1 %s foi a Vencedora\n", cidade); 
        }else {
            printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
    getchar();
   

    return 0;
}