#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// CONSTANTES GLOBAIS

#define TAM_MOCHILA 10
#define MAX_STRING 30
#define MAX_TIPO 20



// ESTRUTURA DE DADOS

typedef struct 
{
    char nome[MAX_STRING];
    char tipo[MAX_TIPO];
    int quantidade;
} freefire;


int InserirItem(freefire *Mochila, int contadorItem);
void RemoverItem(freefire *Mochila, int *contadorItem, int indice);
void ListarItens(freefire *Mochila, int contadorItem);
void BuscarItem();
void Menu1();
void Menu2();
int LerUmaOpcao();
void LimpaBuffer();
void LimparTela();
void LiberandoMemoria(freefire *mochila);



int main(void){
    // variaveis locais
    int resp = 0;
    int contadorItem = 0;
    
    freefire *Mochila = NULL;
    // Alocando Memoria com Calloc (iniciando com zeros)

    Mochila = (freefire *) calloc(TAM_MOCHILA, sizeof(Mochila));

    if (Mochila == NULL){
        fprintf(stderr, "ERRO: Falha ao alocar a memoria!!");
        return EXIT_FAILURE;
    }
    do
    {
    Menu1();
    resp = LerUmaOpcao();

    switch (resp)
    {
    case 1:
    {
        contadorItem = InserirItem(Mochila, contadorItem);

        break;
    }

    case 2:
    {
        ListarItens(Mochila, contadorItem);
        resp = 0;
        printf("Escolha um indice para remover o item: ");
        resp = LerUmaOpcao();
        RemoverItem(Mochila, &contadorItem, resp);
        break;
    }
    case 3:
    {
        ListarItens(Mochila, contadorItem);
        break;
    }
    case 4:
    {
        break;
    }
    case 5:
    {
        break;
    }
    
    default:
        break;
    }



    } while (resp != 5);

    //Liberando Memoria alocada

    free(Mochila);


return 0;
}



void LimpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ;
    }
}

void Menu1(){
    printf("\n\n");
    printf("=====FREE FIRE MOCHILA DE LOOT INICIAL=======\n");
    printf("\n");
    printf("1 - Inserir Item\n");
    printf("2 - Remover Item\n");
    printf("3 - Listar Itens\n");
    printf("4 - Buscar Item\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao no Menu: ");
}

int LerUmaOpcao(){
    int resp;

    if (scanf("%d", &resp) != 1){
        printf("[ERRO] Opcao invalida!! Digite um numero!");
        LimpaBuffer();
        return -1;
    }

    LimpaBuffer();
    return resp;
}


/// @brief Funçao para inserir item na struct por ponteiros
/// @param Mochila struct 
/// @param contadorItem quantidade de itens cadastrados 
/// @return retorna a quantidade de item
int InserirItem(freefire *Mochila, int contadorItem){
    
    if (contadorItem >= MAX_STRING){
        printf("[AVISO] Mochila cheia de itens!!!");
        return;
    }

    freefire *novoitem = &Mochila[contadorItem]; 

    printf("\n");
    printf("======CADASTRO DE ITEM=======");
    printf("\n\n");

    printf("Digite o Nome do Item (Ex: Kit Medico, AK47, Faca etc): ");
    fgets(novoitem->nome, MAX_STRING, stdin);
    novoitem->nome[strcspn(novoitem->nome, "\n")] = '\0';

    printf("Digite a Categoria do Item (Ex: Cura, Arma, Municao etc): ");
    fgets(novoitem->tipo, MAX_TIPO, stdin);
    novoitem->tipo[strcspn(novoitem->tipo, "\n")] = '\0';

    printf("Digite a Quantidade de Itens: ");
    while (scanf("%d", &novoitem->quantidade) != 1 || (novoitem->quantidade < 0))
    {
        printf("[AVISO] Digite um numero positivo: \n");
        LimpaBuffer();
    }
    LimpaBuffer();

    printf("\nItem Cadastrado com sucesso!!!\n");
    return contadorItem + 1;
}
/*
void LiberandoMemoria(freefire *mochila){
    
    if (mochila |= NULL){
        free(*mochila);
        *mochila = NULL;
        printf("\n[INFO] Memoria de Mochila liberada com sucesso.\n");
    }

}*/


// Listagem dos itens com alinhamento
void ListarItens(freefire *Mochila, int contadorItem) {
    if (contadorItem == 0) {
        printf("\nNao existe itens para listagem, utilize a opcao 01 para inserir\n");
        return;
    }

    printf("\n==== LISTAGEM DOS ITENS ====\n");
    printf("%-15s |%-15s | %-15s | %-10s\n","INDICE", "ITEM", "TIPO", "QUANTIDADE");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < contadorItem; i++) {
        freefire *NovaMochila = Mochila + i;

        // %-15s → string alinhada à esquerda com 15 espaços
        // %-10d → número alinhado à esquerda com largura 10
        printf("%-15d |%-15s | %-15s | %-10d\n",
               i,
               NovaMochila->nome,
               NovaMochila->tipo,
               NovaMochila->quantidade);
    }
}
/// @brief funçao remover o item 
/// @param Mochila passa a struct
/// @param contadorItem  quantidade de itens na struct
/// @param indice passa o item para remoçao
void RemoverItem(freefire *Mochila, int *contadorItem, int indice) {
    if (indice < 0 || indice >= *contadorItem) {
        printf("Índice inválido!\n");
        return;
    }

    // desloca todos os elementos uma posição para trás
    for (int i = indice; i < (*contadorItem) - 1; i++) {
        Mochila[i] = Mochila[i + 1];
    }

    (*contadorItem)--; // diminui o total de itens
    printf("Item removido com sucesso!\n");
}

