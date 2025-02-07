#include <stdio.h>

char estado[2];
char cod_carta[5];
char cidade[50];
int populacao = 0;
float area = 0;
float pib = 0;
int n_turisticos = 0;

void imprimir_cab(void){

    printf("=======================================\n");
    printf("= Cadastramento da Carta Super Trunfo =\n");
    printf("=======================================\n");

}

void imprimir_dados(void){
    
    printf("========================================\n");
    printf("=  Cadastrados das Carta Super Trunfo  =\n");
    printf("========================================\n");
}

void cadastro(void){

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
}

void Lista_cad(void){
    
    printf("Estado: %s\n", estado);
    printf("Codigo da Carta: %s\n", cod_carta);
    printf("Nome da Cidade: %s\n", cidade);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km\n", area);
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("Numero de Pontos Turisticos: %d\n", n_turisticos);

}


int main() {
 

    // Inicio da solicitaçao de dados dos usuarios
    imprimir_cab();
    cadastro();
    printf("\n");
    printf("\n");
    getch();
 
    // Impressao dos dados digitados pelo usuario

    imprimir_dados();
    Lista_cad();
    printf("\n");
    printf("\n");
    getch();

    return 0;
}