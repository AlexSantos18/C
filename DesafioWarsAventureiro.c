#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes Globais
#define MAX_TERRITORIO 5
#define TAM_STRING_NOME 30
#define TAM_STRING_COR 10

// Estrutura de dados
typedef struct {
    char nome[TAM_STRING_NOME];
    char cor[TAM_STRING_COR];
    int tropas;   
} Territorio;

// Função limpa buffter do teclado
void LimpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar um território
int CadastrarTerritorio(Territorio *continente, int totalcontinente) {
    if (totalcontinente >= MAX_TERRITORIO) {
        printf("\n**** Limite maximo de territorios atingido! ****\n\n");
        return totalcontinente;
    }
    
    printf("\n########################\n");
    printf("Cadastro Novo Territorio\n");
    printf("########################\n\n");
    
    //  equivalente a (continente + totalcontinente) utilizado no desafio novato
    Territorio *novoTerritorio = &continente[totalcontinente];
    
    printf("Digite o nome do Territorio %d: ", totalcontinente + 1);
    fgets(novoTerritorio->nome, TAM_STRING_NOME, stdin);
    novoTerritorio->nome[strcspn(novoTerritorio->nome, "\n")] = '\0';
    
    printf("Digite a cor das tropas (Ex: Verde, Vermelho...): ");
    fgets(novoTerritorio->cor, TAM_STRING_COR, stdin);
    novoTerritorio->cor[strcspn(novoTerritorio->cor, "\n")] = '\0';
    
    printf("Digite a quantidade de tropas: ");
    while (scanf("%d", &novoTerritorio->tropas) != 1 || novoTerritorio->tropas < 0) {
        printf("Valor invalido! Digite um numero positivo: ");
        LimpaBuffer();
    }
    LimpaBuffer();
    
    printf("\nTerritorio cadastrado com sucesso!\n");
    printf("__________________________________\n\n");
    
    return totalcontinente + 1;
}

// Função para listar territórios
void ListarTerritorios(Territorio *continente, int totalcontinente) {
    printf("\n########################\n");
    printf("Listagem dos Territorios\n");
    printf("########################\n\n");
    
    if (totalcontinente == 0) {
        printf("**** Nao existe Territorio Cadastrado! ****\n\n");
        return;
    }
    
    // Usando ponteiros
    for (int i = 0; i < totalcontinente; i++) {
        Territorio *atual = continente + i;  // Equivalente a &continente[i]
        printf("Territorio %d:\n", i + 1);
        printf("  Nome: %s\n", atual->nome);
        printf("  Cor das Tropas: %s\n", atual->cor);
        printf("  Quantidade de Tropas: %d\n", atual->tropas);
        printf("______________________________________\n\n");
    }
}

// Função para atacar territórios









// Programa principal
int main() {
    Territorio *continente = NULL;
    int totalcontinente = 0;
    int opcao;
    
    // Alocando memória com calloc (inicializa com zeros)
    continente = (Territorio *) calloc(MAX_TERRITORIO, sizeof(Territorio));
    
    if (continente == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memoria para continente!\n");
        return EXIT_FAILURE;
    }
    
    // Menu de Cadastro
    do {
        printf("===========================\n");
        printf("Cadastro de Territorios\n");
        printf("===========================\n");
        printf("1 - Cadastrar um novo Territorio\n");
        printf("2 - Listagem de Territorios\n");
        printf("3 - Sair\n");
        printf("___________________________\n");
        printf("Escolha uma opcao: ");
        
        // Ler a opção do usuário com validação
        if (scanf("%d", &opcao) != 1) {
            printf("\nOpcao invalida! Digite um numero.\n\n");
            LimpaBuffer();
            continue;
        }
        LimpaBuffer();
        
        // Opções no switch
        switch (opcao) {
            case 1:
                totalcontinente = CadastrarTerritorio(continente, totalcontinente);
                break;
                
            case 2:
                ListarTerritorios(continente, totalcontinente);
                break;
                
            case 3:
                printf("\nEncerrando o programa...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Escolha entre 1 e 3.\n\n");
                break;
        }
        
    } while (opcao != 3);
    
    // Liberando memória alocada
    free(continente);
    continente = NULL;  
    
    return EXIT_SUCCESS;
}






