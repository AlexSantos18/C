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

typedef struct freefireNo
{
    char nome[MAX_STRING];
    char tipo[MAX_TIPO];
    int quantidade;
    struct freefireNo *proximo;
} freefireNo;


freefireNo* CriaNo(const char *nome, const char *tipo, int quantidade);
freefireNo* LerDadosUsuario();
freefireNo* InserirInicio(freefireNo* inicio, freefireNo* novo);
void Listar(freefireNo* inicio);
freefireNo* RemoverNo(freefireNo* inicio, const char *nome);
void LiberarMemoriaLista(freefireNo* inicio);
void BuscaBinaria(freefire *Mochila, int contadorItem);
void BuscaSequencial(freefire *Mochila, int contadorItem);
void OrdenarEncadeada(freefireNo* inicio);
void OrdenarSequencial(freefire *Mochila, int contadorItem);
int InserirItem(freefire *Mochila, int contadorItem);
void RemoverItem(freefire *Mochila, int *contadorItem, int indice);
void ListarItens(freefire *Mochila, int contadorItem);
void BuscarItem(freefire *Mochila, int contadorItem);
void Menu1();
int LerUmaOpcao();
void LimpaBuffer();



int main(void){
    // variaveis locais
    int resp = 0;
    int contadorItem = 0;
    int listaOrdenada = 0; // controle para saber se a lista foi ordenada
    freefireNo* lista = NULL;
    char nome[MAX_STRING];
    
    freefire *Mochila = NULL;
    // Alocando Memoria com Calloc (iniciando com zeros) 
    Mochila = (freefire *) calloc(TAM_MOCHILA, sizeof(freefire));

    if (Mochila == NULL){
        fprintf(stderr, "ERRO: Falha ao alocar a memoria!!\n");
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
            listaOrdenada = 0; // Lista desorganizada após inserção
            break;
        }

        case 2:
        {
            freefireNo* novo = LerDadosUsuario();
            lista = InserirInicio(lista, novo);
            printf("Item adicionado com sucesso!\n");
            break;
        }
        
        case 3:
        {
            if (contadorItem == 0) {
                printf("Nenhum item na mochila para remover!\n");
                break;
            }
            ListarItens(Mochila, contadorItem);
            printf("Escolha um indice para remover o item: ");
            int indiceRemover = LerUmaOpcao();
            if (indiceRemover >= 0) {
                RemoverItem(Mochila, &contadorItem, indiceRemover);
                listaOrdenada = 0; // Lista pode estar desorganizada
            }
            break;
        }
        
        case 4:
        {
            printf("\nDigite o nome do item para remover: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            lista = RemoverNo(lista, nome);
            break;
        }
        
        case 5:
        {
            printf("\n=== LISTA SEQUENCIAL ===\n");
            ListarItens(Mochila, contadorItem);
            printf("\n=== LISTA ENCADEADA ===\n");
            Listar(lista);
            break;
        }
        
        case 6:
        {
            printf("\nOrdenando listas...\n");
            if (contadorItem > 0) {
                OrdenarSequencial(Mochila, contadorItem);
                listaOrdenada = 1; // Marca que está ordenada
            } else {
                printf("Lista sequencial vazia!\n");
            }
            OrdenarEncadeada(lista);
            break;
        }
        
        case 7:
        {
            if (contadorItem == 0) {
                printf("Nenhum item na mochila!\n");
                break;
            }

            printf("\n--- BUSCA SEQUENCIAL ---\n");
            BuscaSequencial(Mochila, contadorItem);

            printf("\n--- BUSCA BINÁRIA ---\n");
            // Ordena apenas se ainda não estiver ordenada utilizando o controle
            if (!listaOrdenada) {
                printf("Ordenando lista para busca binária...\n");
                OrdenarSequencial(Mochila, contadorItem);
                listaOrdenada = 1;
            }
            BuscaBinaria(Mochila, contadorItem);
            break;
        }

        case 8:
        {
            printf("\nEncerrando programa...\n");
            break;
        }
        
        default:
        {
            if (resp != -1) {
                printf("\n[ERRO] Opção inválida! Escolha entre 1 e 8.\n");
            }
            break;
        }
        }

    } while (resp != 8);

    // Liberando Memoria alocada - 
    LiberarMemoriaLista(lista);
    free(Mochila);
    
    printf("Memória liberada com sucesso!\n");

    return 0;
}



void LimpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        
    }
}

void Menu1(){
    printf("\n\n");
    printf("=====FREE FIRE MOCHILA DE LOOT INICIAL=======\n");
    printf("\n");
    printf("1 - Inserir Item SEQUENCIAL\n");
    printf("2 - Inserir Item ENCADEADA\n");
    printf("3 - Remover Item SEQUENCIAL\n");
    printf("4 - Remover Item ENCADEADA\n");
    printf("5 - Listar Itens (AMBAS)\n");
    printf("6 - Ordenar Listas\n");
    printf("7 - Buscar Item (Sequencial e Binaria)\n");
    printf("8 - Sair\n");
    printf("Escolha uma opcao no Menu: ");
}

int LerUmaOpcao(){
    int resp;

    if (scanf("%d", &resp) != 1){
        printf("[ERRO] Opcao invalida!! Digite um numero!\n");
        LimpaBuffer();
        return -1;
    }

    LimpaBuffer();
    return resp;
}


/// @brief Função para inserir item na struct por ponteiros
/// @param Mochila struct 
/// @param contadorItem quantidade de itens cadastrados 
/// @return retorna a quantidade de item
int InserirItem(freefire *Mochila, int contadorItem){
    
    if (contadorItem >= TAM_MOCHILA){
        printf("[AVISO] Mochila cheia de itens!!!\n");
        return contadorItem;
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


// Listagem dos itens com alinhamento
void ListarItens(freefire *Mochila, int contadorItem) {
    if (contadorItem == 0) {
        printf("\nNao existe itens para listagem, utilize a opcao 01 para inserir\n");
        return;
    }

    printf("\n==== LISTAGEM DOS ITENS ====\n");
    printf("%-15s |%-30s | %-15s | %-10s\n","INDICE", "ITEM", "TIPO", "QUANTIDADE");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < contadorItem; i++) {
        freefire *NovaMochila = Mochila + i;

        printf("%-15d |%-30s | %-15s | %-10d\n",
               i,
               NovaMochila->nome,
               NovaMochila->tipo,
               NovaMochila->quantidade);
    }
    printf("------------------------------------------------------------------------------\n");
}

/// @brief função remover o item 
/// @param Mochila passa a struct
/// @param contadorItem  quantidade de itens na struct
/// @param indice passa o item para remoção
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

void BuscarItem(freefire *Mochila, int contadorItem){

    char Item[MAX_STRING];
    int encontrado = 0;

    printf("==============BUSCA DE ITENS===============\n");
    printf("\n");

    if (contadorItem == 0){
        printf("\nNao existe itens para a busca, utilize a opcao 01 para inserir\n");
        return;
    }

    printf("Digite o nome do Item para a busca: ");
    fgets(Item, MAX_STRING, stdin);
    Item[strcspn(Item, "\n")] = '\0'; 

    for (int i = 0; i < contadorItem; i++){
        
        freefire *busca = Mochila + i;
        if (strcmp(busca->nome, Item) == 0){ 
            
            encontrado = 1;
            
            printf("Item Encontrado!!\n");
            printf("\n");
            printf("%-15s |%-30s | %-15s | %-10s\n","INDICE", "ITEM", "TIPO", "QUANTIDADE");
            printf("------------------------------------------------------------------------------\n");
            printf("%-15d |%-30s | %-15s | %-10d\n",
               i,
               busca->nome,
               busca->tipo,
               busca->quantidade);
            printf("\n");

        }
    }
    printf("------------------------------------------------------------------------------\n");
    if (encontrado == 0) {
        printf("[AVISO] Item nao Encontrado\n");
    }
}

/// @brief Função para criar um NovoNo (já com os dados prontos)
/// @param nome 
/// @param tipo 
/// @param quantidade 
/// @return retorna um novoNo
freefireNo* CriaNo(const char *nome, const char *tipo, int quantidade){
    freefireNo* NovoNo = (freefireNo*) malloc (sizeof(freefireNo));
    if (NovoNo == NULL){
        printf("Erro ao Alocar Memoria\n");
        exit(1);
    }

    strcpy(NovoNo->nome, nome);
    strcpy(NovoNo->tipo, tipo);
    NovoNo->quantidade = quantidade;
    NovoNo->proximo = NULL;

    return NovoNo;

}

/// @brief Le os dados do usuario 
/// @return retorna a função CriaNo
freefireNo* LerDadosUsuario(){
    char Nome[MAX_STRING];
    char Tipo[MAX_TIPO];
    int quantidade;

    printf("\n");
    printf("======CADASTRO DE ITEM=======");
    printf("\n\n");

    printf("Digite o Nome do Item (Ex: Kit Medico, AK47, Faca etc): ");
    fgets(Nome, sizeof(Nome), stdin);
    Nome[strcspn(Nome, "\n")] = '\0';

    printf("Digite a Categoria do Item (Ex: Cura, Arma, Municao etc): ");
    fgets(Tipo,sizeof(Tipo), stdin);
    Tipo[strcspn(Tipo, "\n")] = '\0';

    printf("Digite a Quantidade de Itens: ");
    while (scanf("%d", &quantidade) != 1 || (quantidade < 0))
    {
        printf("[AVISO] Digite um numero positivo: \n");
        LimpaBuffer();
    }
    LimpaBuffer();
    return CriaNo(Nome, Tipo, quantidade);

    
}

/// @brief Inserir no inicio da lista
/// @param inicio 
/// @param novo 
/// @return o Novo passa a ser o inicio
freefireNo* InserirInicio(freefireNo* inicio, freefireNo* novo){
    novo->proximo = inicio;
    return novo;

}

/// @brief Lista todos os Nos
/// @param inicio 
void Listar(freefireNo* inicio){
    freefireNo* atual = inicio;
    
    if (atual == NULL){
        printf("\nLista Vazia!\n");
        return;

    }

    printf("\n==== LISTAGEM DOS ITENS ====\n");
    printf("%-30s | %-15s | %-10s\n", "ITEM", "TIPO", "QUANTIDADE");
    printf("-------------------------------------------------------------\n");
    while (atual != NULL)
    {
        printf("%-30s | %-15s | %-10d\n", atual->nome, atual->tipo, atual->quantidade);
        atual = atual->proximo;     
        
    }
    printf("-------------------------------------------------------------\n");

}

/// @brief Remove um item pelo nome 
/// @param inicio 
/// @param nome 
/// @return 
freefireNo* RemoverNo(freefireNo* inicio, const char *nome) {
    freefireNo* atual = inicio;
    freefireNo* anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Item '%s' nao encontrado !!\n", nome);
        return inicio;
    }

    if (anterior == NULL) {
        // Removendo o primeiro nó
        inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Item '%s' removido com sucesso!\n", atual->nome);
    free(atual);

    return inicio;
}


void LiberarMemoriaLista(freefireNo* inicio){
    freefireNo* atual = inicio;
    while (atual != NULL)
    {
        freefireNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    
}

/// @brief Ordenar a lista sequencial (bubble sort)
/// @param Mochila 
/// @param contadorItem 
void OrdenarSequencial(freefire *Mochila, int contadorItem) {
    if (contadorItem < 2) {
        printf("Poucos itens para ordenar!\n");
        return;
    }

    for (int i = 0; i < contadorItem - 1; i++) {
        for (int j = 0; j < contadorItem - i - 1; j++) {
            if (strcmp(Mochila[j].nome, Mochila[j + 1].nome) > 0) {
                freefire temp = Mochila[j];
                Mochila[j] = Mochila[j + 1];
                Mochila[j + 1] = temp;
            }
        }
    }

    printf("Lista SEQUENCIAL ordenada com sucesso (Bubble Sort)!\n");
}

/// @brief ordenar a lista encadeada (bubble sort)
/// @param inicio 
void OrdenarEncadeada(freefireNo* inicio) {
    if (inicio == NULL || inicio->proximo == NULL) {
        printf("Poucos itens para ordenar!\n");
        return;
    }

    int trocou;
    freefireNo *ptr1;
    freefireNo *lptr = NULL;

    do {
        trocou = 0;
        ptr1 = inicio;

        while (ptr1->proximo != lptr) {
            if (strcmp(ptr1->nome, ptr1->proximo->nome) > 0) {
                // Troca os dados
                char tempNome[MAX_STRING];
                char tempTipo[MAX_TIPO];
                int tempQtd;

                strcpy(tempNome, ptr1->nome);
                strcpy(tempTipo, ptr1->tipo);
                tempQtd = ptr1->quantidade;

                strcpy(ptr1->nome, ptr1->proximo->nome);
                strcpy(ptr1->tipo, ptr1->proximo->tipo);
                ptr1->quantidade = ptr1->proximo->quantidade;

                strcpy(ptr1->proximo->nome, tempNome);
                strcpy(ptr1->proximo->tipo, tempTipo);
                ptr1->proximo->quantidade = tempQtd;

                trocou = 1;
            }
            ptr1 = ptr1->proximo;
        }
        lptr = ptr1;
    } while (trocou);

    printf("Lista ENCADEADA ordenada com sucesso (Bubble Sort)!\n");
}

/// @brief busca sequencial com contagem de comparações 
/// @param Mochila 
/// @param contadorItem 
void BuscaSequencial(freefire *Mochila, int contadorItem) {
    char nomeBusca[MAX_STRING];
    int comparacoes = 0;
    int encontrado = -1;

    printf("\nDigite o nome do item para busca SEQUENCIAL: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < contadorItem; i++) {
        comparacoes++;
        if (strcmp(Mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("\nItem encontrado no indice %d.\n", encontrado);
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].quantidade);
    } else {
        printf("\n[AVISO] Item nao encontrado!\n");
    }

    printf("Numero de comparacoes (Sequencial): %d\n", comparacoes);
}


/// @brief busca binaria com contagem de comparacoes
/// @param Mochila 
/// @param contadorItem 
void BuscaBinaria(freefire *Mochila, int contadorItem) {
    char nomeBusca[MAX_STRING];
    int inicio = 0, fim = contadorItem - 1, meio;
    int comparacoes = 0;
    int encontrado = -1;

    printf("\nDigite o nome do item para busca BINARIA: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoes++;

        int cmp = strcmp(Mochila[meio].nome, nomeBusca);

        if (cmp == 0) {
            encontrado = meio;
            break;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado != -1) {
        printf("\nItem encontrado no Indice %d.\n", encontrado);
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].quantidade);
    } else {
        printf("\n[AVISO] Item nao encontrado!\n");
    }

    printf("Numero de comparacoes (Binaria): %d\n", comparacoes);
}