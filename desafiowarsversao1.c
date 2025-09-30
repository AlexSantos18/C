#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes Globais

#define MAX_TERRITORIO 5
#define TAM_STRING_NOME 30
#define TAM_STRING_COR 10

// criacao da strutura de dados 
typedef struct{
    char nome[30];
    char cor[10];
    int tropas;   
}Territorio;

// Funcao limpa buffer teclado

void LimpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// programa principal

int main(){
    Territorio *continente;
    int totalcontinente = 0;
    int opcao;
    int i = 0;

    //Alocando memoria para os cincos continentes
    
    continente = (Territorio *) calloc(MAX_TERRITORIO, sizeof(Territorio));
    if (continente == NULL) {
        printf("Erro ao alocar memoria para continente!\n");
        return 1;
    }
    
    // Menu de Cadastro

    do
    {
        printf("Cadastro de Territorios\n");
        printf("=========================\n");
        printf("1 - Cadastrar um novo Territorio\n");
        printf("2 - Listagem de Territorio\n");
        printf("3 - Sair\n");
        printf("_________________________\n");
        printf("Escolha uma opcao: ");

        // ler a opcao do usuario

        scanf("%d", &opcao);
        LimpaBuffer();
        

        // opcoes no switch

        switch (opcao)
        {
        case 1:
            printf("\n");
            printf("########################\n");
            printf("Cadastro Novo Territorio\n");
            printf("########################\n");
            printf("\n");
            

            // Não é necessário alocar memória para nome e cor, pois agora são arrays fixos

            if (totalcontinente < MAX_TERRITORIO) { // Verifica se já esta cadastrado os 5 territorio e retorna 
                                                    // limite maximo 

                for (int i = 0; i < 5; i++){      // for para cadastrar todos os territorios
                    printf("Digite o Territorio %d : ", totalcontinente + 1);
                    fgets((continente + totalcontinente)->nome , TAM_STRING_NOME, stdin);

                    printf("Digite a cor das tropas. (Ex: Verde, Vermelho ...) : ");
                    fgets((continente + totalcontinente)->cor, TAM_STRING_COR, stdin);

                    (continente + totalcontinente)->nome[strcspn((continente + totalcontinente)->nome, "\n")] = '\0';
                    (continente + totalcontinente)->cor[strcspn((continente + totalcontinente)->cor, "\n")] = '\0'; 


                    printf("Digite a quantidade de tropas: ");
                    scanf("%d", &((continente + totalcontinente)->tropas));
                    LimpaBuffer();
                    
                    totalcontinente++;
                    printf("\n");
                    printf("Territorio cadastrado com sucesso!\n");
                    printf("__________________________________\n");
                    printf("\n");
                    
                }
            break;

            } else { 
                printf("**** Limite maximo de territorios atingido! ****\n");
                printf("\n");
                break;
            }
        case 2:    // Listagem dos territorios 
            printf("\n");
            printf("########################\n");
            printf("Listagem dos Territorios\n");
            printf("########################\n");
            printf("\n");

            if (totalcontinente < MAX_TERRITORIO){
                printf("**** Nao existe Territorio Cadastrado! ****\n");
                printf("\n");
                break;
            } else { 
                for (int i = 0; i < 5; i++){
                    printf("Nome do Territorio: %s\n", (continente + i)->nome);
                    printf("Cor da Tropas: %s\n", (continente + i)->cor);
                    printf("Quantidade de Tropas: %d\n\n", (continente + i)->tropas);
                    printf("______________________________________\n");
                    printf("\n");
                }
            break;

            }
            
        default:
            break;
        }


    }while (opcao != 3);
    free(continente);
}