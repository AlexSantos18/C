#include <stdio.h>

    // Tema 2 Desafio Nivel Aventureiro
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

// Funçao menu2 a ser chamada no programa
void menu2(void)
{
    printf("[1] Populacao\n");
    printf("[2] Area\n");
    printf("[3] Densidade Populacional\n");
    printf("[4] PIB\n");
    printf("[5] PIB Per Capita\n");
    printf("[6] Pontos Turisticos\n");
    printf("[7] Super Poder\n");
    printf("[8] Sair do Jogo\n");
    printf("Escolha uma opcao: ");
}


void menu_populacao(void)
{
    printf("ESCOLHA UM SEGUNDO ATRIBUDO DA CARTA\n");
    printf("\n");
    printf("[1] Area\n");
    printf("[2] Densidade Populacional\n");
    printf("[3] PIB\n");
    printf("[4] PIB Per Capita\n");
    printf("[5] Pontos Turisticos\n");
    printf("[6] Super Poder\n");
    printf("[7] Sair do Jogo\n");
    printf("Escolha uma 2 opcao: ");
}

void menu_area(void)
{
    printf("ESCOLHA UM SEGUNDO ATRIBUDO DA CARTA\n");
    printf("\n");
    printf("[1] Populacao\n");
    printf("[2] Densidade Populacional\n");
    printf("[3] PIB\n");
    printf("[4] PIB Per Capita\n");
    printf("[5] Pontos Turisticos\n");
    printf("[6] Super Poder\n");
    printf("[7] Sair do Jogo\n");
    printf("Escolha uma 2 opcao: ");
}

void menu_densidade(void)
{
    printf("ESCOLHA UM SEGUNDO ATRIBUDO DA CARTA\n");
    printf("\n");
    printf("[1] Populacao\n");
    printf("[2] Area\n");
    printf("[3] PIB\n");
    printf("[4] PIB Per Capita\n");
    printf("[5] Pontos Turisticos\n");
    printf("[6] Super Poder\n");
    printf("[7] Sair do Jogo\n");
    printf("Escolha uma 2 opcao: ");
}
void menu_pib(void)
{
    printf("ESCOLHA UM SEGUNDO ATRIBUDO DA CARTA\n");
    printf("\n");
    printf("[1] Populacao\n");
    printf("[2] Area\n");
    printf("[3] Densidade Populacional\n");
    printf("[4] PIB Per Capita\n");
    printf("[5] Pontos Turisticos\n");
    printf("[6] Super Poder\n");
    printf("[7] Sair do Jogo\n");
    printf("Escolha uma 2 opcao: ");
}
void menu_per_capita(void)
{
    printf("ESCOLHA UM SEGUNDO ATRIBUDO DA CARTA\n");
    printf("\n");
    printf("[1] Populacao\n");
    printf("[2] Area\n");
    printf("[3] Densidade Populacional\n");
    printf("[4] PIB\n");
    printf("[5] Pontos Turisticos\n");
    printf("[6] Super Poder\n");
    printf("[7] Sair do Jogo\n");
    printf("Escolha uma 2 opcao: ");
}

void menu_turisticos(void)
{
    printf("ESCOLHA UM SEGUNDO ATRIBUDO DA CARTA\n");
    printf("\n");
    printf("[1] Populacao\n");
    printf("[2] Area\n");
    printf("[3] Densidade Populacional\n");
    printf("[4] PIB\n");
    printf("[5] PIB Per Capita\n");
    printf("[6] Super Poder\n");
    printf("[7] Sair do Jogo\n");
    printf("Escolha uma 2 opcao: ");
}

void menu_poder(void)
{
    printf("ESCOLHA UM SEGUNDO ATRIBUDO DA CARTA\n");
    printf("\n");
    printf("[1] Populacao\n");
    printf("[2] Area\n");
    printf("[3] Densidade Populacional\n");
    printf("[4] PIB\n");
    printf("[5] PIB Per Capita\n");
    printf("[6] Pontos Turisticos\n");
    printf("[7] Sair do Jogo\n");
    printf("Escolha uma 2 opcao: ");
}

void disputa_populacao(void){
    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem uma Populacao %lu \nCarta 2 %s tem uma Populacao %lu\n", cidade, populacao, cidade2, populacao2);
    if (populacao == populacao2){
        printf("Houve empate!!!\n");
    } else if (populacao > populacao2){
        printf("A Carta 1 %s foi a Vencedora\n", cidade);
    } else {
        printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
}

void disputa_area(void){
    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem uma Area %.2f\nCarta 2 %s tem uma Area %.2f\n", cidade, area, cidade2, area2);
    if (area == area2){
        printf("Houve empate!!!\n");
    } else if (area > area2){
        printf("A Carta 1 %s foi a Vencedora\n", cidade);
    } else{
        printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
}

void disputa_dens(void){
    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem uma Densidade Populacional %.2f\nCarta %s tem uma Densidade Populacional %.2f\n", cidade, dens_populacional, cidade2, dens_populacional2);
    // densidade a menor vence
    if (dens_populacional == dens_populacional2){
        printf("Houve empate!!!\n");
    } else if (dens_populacional < dens_populacional2){
        printf("A Carta 1 %s foi a Vencedora\n", cidade);
    } else{
        printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
}

void disputa_pib(void){
    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem um PIB %.2f\nCarta 2 %s tem um PIB %.2f\n", cidade, pib, cidade2, pib2);
    if (pib == pib2){
        printf("Houve empate!!!\n");
    } else if (pib > pib2)        {
        printf("A Carta 1 %s foi a Vencedora\n", cidade);
    } else{
        printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
}

void disputa_pib_capita(void){
    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem um PIB per Capita %.2f\nCarta 2 %s tem um PIB per Capita %.2f\n", cidade, pib_capita, cidade2, pib_capita2);

    if (pib_capita == pib_capita2){
        printf("Houve empate!!!\n");
    } else if (pib_capita > pib_capita2){
        printf("A Carta 1 %s foi a Vencedora\n", cidade);
    } else {
        printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
}

void disputa_turismo(void){
    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");
    printf("Carta 1 %s tem Pontos Turisticos %d\nCarta 2 %s tem Pontos Turisticos %d\n", cidade, n_turisticos, cidade2, n_turisticos2);
    if (n_turisticos == n_turisticos2){
        printf("Houve empate!!!\n");
    } else if (n_turisticos > n_turisticos2){
        printf("A Carta 1 %s foi a Vencedora\n", cidade);
    } else {
        printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
}

void disputa_poder(void){
    imprimir_dados("Hora da Disputa!!!");
    printf("REGRA DO JOGO (TODOS OS ATRIBUTOS A MAIOR VENCE EXCETO A DENSIDADE POPULACIONAL DO QUAL A MENOR VENCE)\n");
    printf("\n");   
    printf("Carta 1 %s tem um Super Poder %.2lf\nCarta 2 %s tem um Super Poder %.2lf\n", cidade, poder, cidade2, poder2);
    if (poder == poder2){
        printf("Houve empate!!!\n");
    } else if (poder > poder2){
        printf("A Carta 1 %s foi a Vencedora\n", cidade);
    } else {
        printf("A Carta 2 %s foi a Vencedora\n", cidade2);
    }
    printf("\n");
}
// funçao soma os dois atributos de cada carta
void disputa_final(double c1_atrib1, double c1_atirb2, double c2_atrib1, double c2_atrib2){
    long double total_atributo1, total_atributo2; 
    total_atributo1 = (long double)c1_atrib1 + (long double)c1_atirb2;
    total_atributo2 = (long double)c2_atrib1 + (long double)c2_atrib2;
    imprimir_dados("HORA DA BATALHA FINAL!!!");
    if (total_atributo1 > total_atributo2){
        printf("A Carta 1 tem um total de %.2Lf de Atributo\n", total_atributo1);
        printf("A Carta 2 tem um total de %.2Lf de Atributo\n", total_atributo2);
        printf("A Carta 1 Venceu a Batalha!!!");
    } else {
        printf("A Carta 1 tem um total de %.2Lf de Atributo\n", total_atributo1);
        printf("A Carta 2 tem um total de %.2Lf de Atributo\n", total_atributo2);
        printf("A Carta 2 Venceu a Batalha!!!");
    }
}


int main(){

  
    // Entrada de Dados das Cartas

    int opcao;

    // Inicio da solicitaçao de dados dos usuarios
    imprimir_cab();
    entrada_dados();
    system("cls"); // quando compilado no vscode windows do contrario no linux usar o clear
    calculo_pop_pib();
    super_poder();

       // Impressao dos dados digitados pelo usuario

    imprimir_dados("Cartas Cadastradas");
    saida_dados();
    system("cls");
 
    // Menu da Disputa
    imprimir_dados("Escolha um Atributo para Jogar");
    menu2(); // impresao do Menu
    scanf("%d", &opcao);

    switch (opcao) // menu escolha de propriedades
    {
    case 1: // menu escolha populaçao 
        system("cls");
        menu_populacao();
        scanf("%d", &opcao);
        switch (opcao) 
        {
        case 1:     // escolha area
            disputa_populacao(); // chama a funçao de disputa
            disputa_area();
            disputa_final(populacao, area, populacao2, area2); // chama a funçao de soma de atributo
            break;
            
        case 2: // escolha densidade 
            disputa_populacao();
            disputa_dens();
            disputa_final(populacao, populacao2, dens_populacional, dens_populacional2);
            break;
        case 3: // escolha pib
            disputa_populacao();
            disputa_pib();
            disputa_final(populacao, populacao2, pib, pib2);
            break;

        case 4: // escolha pib per capita
            disputa_populacao();
            disputa_pib_capita();
            disputa_final(populacao, populacao2, pib_capita, pib_capita2);
            break;

        case 5: // escolha pontos turisticos
            disputa_populacao();
            disputa_turismo();
            disputa_final(populacao, populacao2, n_turisticos, n_turisticos2);
            break;
        case 6: // escolha super poder
            disputa_populacao();
            disputa_poder();
            disputa_final(populacao, populacao2, poder, poder2);
            break;

        default:
            break;
        }

        break;
    case 2: // menu area 
        system("cls");
        menu_area();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // escolha populaçao 
            disputa_area();
            disputa_populacao();
            disputa_final(area, area2, populacao, populacao2);
            break;
        case 2: // escolha densidade 
            disputa_area();
            disputa_dens();
            disputa_final(area, area2, dens_populacional, dens_populacional2);
            break;
        case 3: // escolha pib
            disputa_area();
            disputa_pib();
            disputa_final(area, area2, pib, pib2);
            break;
        case 4: // escolha pib per capita
            disputa_area();
            disputa_pib_capita();
            disputa_final(area, area2, pib_capita, pib_capita2);
            break;
        case 5: // escolha pontos turisticos
            disputa_area();
            disputa_turismo();
            disputa_final(area, area2, n_turisticos, n_turisticos2);
            break;
        case 6: // escolha super poder
            disputa_area();
            disputa_poder();
            disputa_final(area, area2, poder, poder2);
            break;

        default:
            break;
        }
        break;
        

    case 3: // escolha densidade 
        system("cls");
        menu_densidade();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // escolha populaçao
            disputa_dens();
            disputa_populacao();
            disputa_final(dens_populacional, dens_populacional2, populacao, populacao2);
            break;
        case 2: // escolha area 
            disputa_dens();
            disputa_area();
            disputa_final(dens_populacional, dens_populacional2, area, area2);
            break;
        case 3: // escolha pib
            disputa_dens();
            disputa_pib();
            disputa_final(dens_populacional, dens_populacional2, pib, pib2);
            break;
        case 4: // escolha pib per capita
            disputa_dens();
            disputa_pib_capita();
            disputa_final(dens_populacional, dens_populacional2, pib_capita, pib_capita2);
            break;
        case 5: // escolha pontos turisticos 
            disputa_dens();
            disputa_turismo();
            disputa_final(dens_populacional, dens_populacional2, n_turisticos, n_turisticos2);
            break;
        case 6: // escolha super poder
            disputa_dens();
            disputa_poder();
            disputa_final(dens_populacional, dens_populacional2, poder, poder2);
            break;

        default:
            break;
        }
        break;
    case 4: // escolha menu pib
        system("cls");
        menu_pib();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // escolha populaçao 
            disputa_pib();
            disputa_populacao();
            disputa_final(pib, pib2, populacao, populacao2);
            break;
        case 2: // escolha area
            disputa_pib();
            disputa_area();
            disputa_final(pib, pib2, area, area2);
            break;
        case 3: // escolha densidade
            disputa_pib();
            disputa_dens();
            disputa_final(pib, pib2, dens_populacional, dens_populacional2);
            break;
        case 4: // escolha pib per capita
            disputa_pib();
            disputa_pib_capita();
            disputa_final(pib, pib2, pib_capita, pib_capita2);
            break;
        case 5: // escolha pontos turisticos
            disputa_pib();
            disputa_turismo();
            disputa_final(pib, pib2, n_turisticos, n_turisticos2);
            break;
        case 6: // escolha super poder 
            disputa_pib();
            disputa_poder();
            disputa_final(pib, pib2, poder, poder2);
            break;
            
        default:
            break;
        }
        break;
    case 5: // escolha menu per capita 
        system("cls");
        menu_per_capita();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:  // escolha populaçao 
            disputa_pib_capita();
            disputa_populacao();
            disputa_final(pib_capita, pib_capita2, populacao, populacao2);
            break;
           
        case 2: // escolha area 
            disputa_pib_capita();
            disputa_area();
            disputa_final(pib_capita, pib_capita2, area, area2);
            break;
        case 3: // escolha densidade 
            disputa_pib_capita();
            disputa_dens();
            disputa_final(pib_capita, pib_capita2, dens_populacional, dens_populacional2);
            break;
        case 4: // escolha pib
            disputa_pib_capita();
            disputa_pib();
            disputa_final(pib_capita, pib_capita2, pib, pib2);
            break;
        case 5: // escolha pontos turisticos 
            disputa_pib_capita();
            disputa_turismo();
            disputa_final(pib_capita, pib_capita2, n_turisticos, n_turisticos2);
            break;
        case 6: // escolha super poder 
            disputa_pib_capita();
            disputa_poder();
            disputa_final(pib_capita, pib_capita2, poder, poder2);
            break;

        default:
            break;
        }

        break;

    case 6: // escolha pontos turisticos 
        system("cls");
        menu_turisticos();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: //escolha populaçao
            disputa_turismo();
            disputa_populacao();
            disputa_final(n_turisticos, n_turisticos2, populacao, populacao2);
            break;
        case 2: // escolha area 
            disputa_turismo();
            disputa_area();
            disputa_final(n_turisticos, n_turisticos2, area, area2);
            break;
        case 3: // escolha densidade
            disputa_turismo();
            disputa_dens();
            disputa_final(n_turisticos, n_turisticos2, dens_populacional, dens_populacional2);
            break;
        case 4: // escolha pib
            disputa_turismo();
            disputa_pib();
            disputa_final(n_turisticos, n_turisticos2, pib, pib2);
            break;
        case 5: // escolha pib per capita
            disputa_turismo();
            disputa_pib_capita();
            disputa_final(n_turisticos, n_turisticos2, pib_capita, pib_capita2);
            break;
        case 6: // escolha super poder 
            disputa_turismo();
            disputa_poder();
            disputa_final(n_turisticos, n_turisticos2, poder, poder2);
            break;

        default:
            break;
        }

        break;
    case 7: // escolha super poder
        system("cls");
        menu_poder();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // escolha populaçao
            disputa_poder();
            disputa_populacao();
            disputa_final(poder, poder2, populacao, populacao2);
            break;
        case 2: // escolha area 
            disputa_poder();
            disputa_area();
            disputa_final(poder, poder2, area, area2);
            break;
        case 3: // escolha  densidade 
            disputa_poder();
            disputa_dens();
            disputa_final(poder, poder2, dens_populacional, dens_populacional2);
            break;
        case 4: // escolha pib 
            disputa_poder();
            disputa_pib();
            disputa_final(poder, poder2, pib, pib2);
            break;
        case 5: // escolha pib per capita
            disputa_poder();
            disputa_pib_capita();
            disputa_final(poder, poder2, pib_capita, pib_capita2);
            break;
        case 6:  // escolha pontos turisticos 
            disputa_poder();
            disputa_turismo();
            disputa_final(poder, poder2, n_turisticos, n_turisticos2);
            break;

        default:
            break;
        }

        break;
    case 8:
        printf("Saindo .....");
        break;

    default:
        break;
    }

    getchar();

    return 0;
    }
