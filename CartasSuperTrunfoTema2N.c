#include <stdio.h>
#include <string.h>

    //// Desafio Nivel Novato

    char estado[2], estado2[2];
    char cod_carta[5], cod_carta2[5];
    char cidade[50], cidade2[50];
    int populacao = 0, populacao2 = 0;
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
void imprimir_dados(void){
    printf("=======================\n");
    printf("=  Dados Cadastrados  =\n");
    printf("=======================\n");
    printf("\n");
}

void imprimir_disputa(void){
    printf("=======================\n");
    printf("=  Hora da Disputa  =\n");
    printf("=======================\n");
    printf("\n");
}


    // funçao entrada de dados do usuario CARTA 1
void entrada_dados(void){
    printf("Digite a letra correspondente ao Estado: ");
    scanf(" %s", estado);
    printf("\n"); // pula uma linha 
    getchar(); // limpa o buffer do teclado para cada entrada de dados.

    printf("Digite o Codigo da Carta: ");
    scanf(" %s", cod_carta);
    printf("\n");
    getchar();
    
    printf("Digite a Cidade: ");
    fgets(cidade, sizeof(cidade), stdin); // ultilizado fgets pois o scanf não funcionava para strings separadas pois finaliza no espaço
    cidade[strcspn(cidade, "\n")] = '\0';  // Remove o '\n' no final da string e troca por \0 do char
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
    getchar();

}

    // funçao entrada de dados do usuario CARTA 2
void entrada_dados2(void){
    printf("Digite a letra correspondente ao Estado: ");
    scanf(" %s", estado2);
    printf("\n");
    getchar(); // limpa o buffer do teclado.

    printf("Digite o Codigo da Carta: ");
    scanf(" %s", cod_carta2);
    printf("\n");
    getchar();
    
    printf("Digite a Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin); // ultilizado fgets pois o scanf não funcionava para strings separadas pois finaliza no espaço
    cidade2[strcspn(cidade2, "\n")] = '\0';  // Remove o '\n' no final da string
    getchar();
    
    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);
    printf("\n");
    getchar();
    
    printf("Digite a Area: ");
    scanf("%f", &area2);
    printf("\n");
    getchar();
    
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("\n");
    getchar();
    
    printf("Digite os Numeros de Pontos Turisticos: ");
    scanf("%d", &n_turisticos2);
    printf("\n");
    getchar();
    
    printf("Carta Cadastrada com Sucesso.\n");
    printf("\n");
    printf("\n");
    getchar();

}



    // funçao a saida de dados cadastrados 
void saida_dados(void){
    printf("Primera Carta Cadastrada \n");
    printf("\n");
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
    printf("super Poder : %.2lf\n", poder);
    getchar();
    system("cls");    // limpa a tela se a compilaçao for no linux trocar pelo clear

    // Segunda Carta
    imprimir_dados();
    printf("Segunda Carta Cadastrada \n");
    printf("\n");
    printf("Estado: %s\n", estado2);
    printf("\n");
    printf("Codigo da Carta: %s\n", cod_carta2);
    printf("\n");
    printf("Nome da Cidade: %s\n", cidade2);
    printf("\n");
    printf("Populacao: %d\n", populacao2);
    printf("\n");
    printf("Area: %.2f km\n", area2);
    printf("\n");
    printf("Densidade Populacional: %.2f pessoas/km2\n", dens_populacional2);
    printf("\n");
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("\n");
    printf("PIB per Capita: %.2f reais\n", pib_capita2);
    printf("\n");
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos2);
    printf("\n");
    printf("Super Poder: %.2lf\n", poder2);
    getchar();
    system("cls");

}

int main() {

    int resultado;
    
    
    // Inicio da solicitaçao de dados dos usuarios
    imprimir_cab();
    printf("Cadastre a Primeira Carta do Jogo SuperTrunfo \n");
    entrada_dados();
    system("cls"); // quando compilado no vscode windows do contrario no linux usar o clear
    imprimir_cab();
    printf("Cadastre a Segunda Carta do Jogo SuperTrunfo \n");
    entrada_dados2();
    system("cls");
    

    // Calculo da Densidade e Per Capita
    dens_populacional = (float)(populacao / area);
    pib_capita = ((pib * 1e9) / populacao); // 1e9 1 veze 10 elevado à nona potência 1.000.000.000 um bilhao

    dens_populacional2 = (float)(populacao2 / area2);
    pib_capita2 = ((pib2 * 1e9 ) / populacao2); // 1e9 1 veze 10 elevado à nona potência 1.000.000.000 um bilhao


    // Calculando o Poder da Carta

    poder = (populacao + area + pib + pib_capita + n_turisticos) - dens_populacional;
    poder2 = (populacao2 + area2 + pib2 + pib_capita2 + n_turisticos2) - dens_populacional2;


    // Impressao dos dados digitados pelo usuario
    imprimir_dados();
    saida_dados();

    // Comparação das cartas

    imprimir_disputa();
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem uma Populacao %d \nCarta 2 %s tem uma Populacao %d\n", cidade, populacao, cidade2, populacao2);

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