#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


// CONSTANTES GLOBAIS

#define TAM_MOCHILA 20
#define MAX_STRING 30
#define MAX_TIPO 20



// ESTRUTURA DE DADOS

typedef struct 
{
    char nome[MAX_STRING];
    char tipo[MAX_TIPO];
    int prioridade;
} freefire;


void BuscaBinaria(freefire *Mochila, int contadorItem);
void BuscaSequencial(freefire *Mochila, int contadorItem);
void OrdenarSequencial(freefire *Mochila, int contadorItem); // ordenar pelo metodo Bubble Sort no campo nome
void OrdenarInsertionSort(freefire *Mochila, int contadorItem); //ordenar pelo metodo Insertion Sort no campo tipo
void OrdenarSelectionSort(freefire *Mochila, int contadorItem); // ordenar pelo metodo Selection Sort pelo campo prioridade
void MedirTempo(freefire *Mochila, int contadorItem);  // medir o tempo de cada ordenacao e mostrar ao usuario usando clock()
int InserirItem(freefire *Mochila, int contadorItem);
void RemoverItem(freefire *Mochila, int *contadorItem, int indice);
void ListarItens(freefire *Mochila, int contadorItem);
void BuscarItem(freefire *Mochila, int contadorItem);
void BuscaSequencialInsertion(freefire *Mochila, int contadorItem);
void BuscaBinariaInsertion(freefire *Mochila, int contadorItem);
void BuscaSequencialSelection(freefire *Mochila, int contadorItem); // Busca sequencial  por prioridade
void BuscaBinariaSelection(freefire *Mochila, int contadorItem); // Busca Binaria por prioridade
void Menu1();
void Menu2();
int LerUmaOpcao();
void LimpaBuffer();



int main(void){
    // variaveis locais
    int resp = 0;
    int contadorItem = 0;
    int listaOrdenada = 0; // controle para saber se a lista foi ordenada
      
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
        
        case 3:
        {
            printf("\n=== LISTA SEQUENCIAL ===\n");
            ListarItens(Mochila, contadorItem);
            break;
        }
        
        case 4:
        {
            printf("\nOrdenando listas...\n");
            if (contadorItem > 0) {
                OrdenarSequencial(Mochila, contadorItem);
                listaOrdenada = 1; // Marca que está ordenada
            } else {
                printf("Lista sequencial vazia!\n");
            }

            break;
        }

        case 5:
        {
            printf("\nOrdenando listas...\n");
            if (contadorItem > 0) {
                OrdenarInsertionSort(Mochila, contadorItem);
                listaOrdenada = 1; // Marca que está ordenada
            } else {
                printf("Lista sequencial vazia!\n");
            }

            break;
        }

        case 6:
        {
            printf("\nOrdenando listas...\n");
            if (contadorItem > 0) {
                OrdenarSelectionSort(Mochila, contadorItem);
                listaOrdenada = 1; // Marca que está ordenada
            } else {
                printf("Lista sequencial vazia!\n");
            }
            break;
        }
        
        case 7:
        {
            int respMenu2 = 0;
            do {
                Menu2();
                respMenu2 = LerUmaOpcao();

                switch(respMenu2){

                case 1:
                {
                    if (contadorItem == 0) {
                        printf("Nenhum item na mochila!\n");
                        break;
                    }

                    printf("\n--- BUSCA SEQUENCIAL POR NOME ---\n");
                    BuscaSequencial(Mochila, contadorItem);

                    printf("\n--- BUSCA BINARIA POR NOME ---\n");
                    // Ordena apenas se ainda não estiver ordenada utilizando o controle
                    if (!listaOrdenada) {
                        printf("Ordenando lista para busca binaria...\n");
                        OrdenarSequencial(Mochila, contadorItem);
                        listaOrdenada = 1;
                    }
                    BuscaBinaria(Mochila, contadorItem);
                    break;
                }

                case 2:
                {
                    if (contadorItem == 0) {
                        printf("Nenhum item na mochila!\n");
                        break;
                    }

                    printf("\n--- BUSCA SEQUENCIAL POR TIPO ---\n");
                    BuscaSequencialInsertion(Mochila, contadorItem);

                    printf("\n--- BUSCA BINARIA POR TIPO ---\n");
                    // Ordena apenas se ainda não estiver ordenada utilizando o controle
                    if (!listaOrdenada) {
                        printf("Ordenando lista para busca binaria...\n");
                        OrdenarInsertionSort(Mochila, contadorItem);
                        listaOrdenada = 1;
                    }
                    BuscaBinariaInsertion(Mochila, contadorItem);
                    break;
                }

                case 3:
                {
                    if (contadorItem == 0) {
                        printf("Nenhum item na mochila!\n");
                        break;
                    }

                    printf("\n--- BUSCA SEQUENCIAL POR PRIORIDADE ---\n");
                    BuscaSequencialSelection(Mochila, contadorItem);

                    printf("\n--- BUSCA BINARIA POR PRIORIDADE ---\n");
                    // Ordena apenas se ainda não estiver ordenada utilizando o controle
                    if (!listaOrdenada) {
                        printf("Ordenando lista para busca binaria...\n");
                        OrdenarSelectionSort(Mochila, contadorItem);
                        listaOrdenada = 1;
                    }
                    BuscaBinariaSelection(Mochila, contadorItem);
                    break;
                }

                case 0:
                {
                    printf("\nVoltando ao menu principal...\n");
                    break;
                }

                default:
                {
                    if (respMenu2 != -1) {
                        printf("\n[ERRO] Opcao invalida! Escolha entre 0 e 3.\n");
                    }
                    break;
                }

                } // fim switch interno
                
            } while (respMenu2 != 0);

            break;
        }
        
        case 8:
        {
            if (contadorItem == 0) {
                printf("Nenhum item na mochila para medir tempo!\n");
                break;
            }
            MedirTempo(Mochila, contadorItem);
            break;
        }
                
        case 0:
        {
            printf("\nEncerrando programa...\n");
            break;
        }
        
        default:
        {
            if (resp != -1) {
                printf("\n[ERRO] Opcao invalida! Escolha entre 0 e 8.\n");
            }
            break;
        }
        }

    } while (resp != 0);

    // Liberando Memoria alocada - 
    free(Mochila);
    printf("Memoria liberada com sucesso!\n");
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
    printf("=====FREE FIRE MOCHILA DE EQUIPAMENTOS=======\n");
    printf("\n");
    printf("1 - Inserir Item \n");
    printf("2 - Remover Item \n");
    printf("3 - Listar Itens \n");
    printf("4 - Ordenar por NOME (BUBBLE SORT)\n");
    printf("5 - Ordenar por TIPO (INSERTION SORT)\n");
    printf("6 - Ordenar por PRIORIDADE (SELECTION SORT)\n");
    printf("7 - Buscar Item (Sequencial e Binaria)\n");
    printf("8 - Medir Tempo das Ordenacoes\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao no Menu: ");
}


void Menu2(){
    printf("\n\n");
    printf("=====FREE FIRE PROCURA DE ITENS=======\n");
    printf("\n");
    printf("1 - Procura pelo Nome\n");
    printf("2 - Procura pelo Tipo\n");
    printf("3 - Procura pela Prioridade\n");
    printf("0 - Voltar ao Menu Anterior\n");
    printf("Escolha uma opcao: ");
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

    printf("Digite o Nome do Item (Ex: Chip Central, Placa, Viga, Parede etc): ");
    fgets(novoitem->nome, MAX_STRING, stdin);
    novoitem->nome[strcspn(novoitem->nome, "\n")] = '\0';

    printf("Digite a Categoria do Item (Ex: Suporte, Controle, Propulsao, Eletronico etc): ");
    fgets(novoitem->tipo, MAX_TIPO, stdin);
    novoitem->tipo[strcspn(novoitem->tipo, "\n")] = '\0';

    printf("Digite a Prioridade de [0 a 10] do Item: ");
    while (scanf("%d", &novoitem->prioridade) != 1 || (novoitem->prioridade < 0))
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
    printf("%-15s |%-30s | %-15s | %-10s\n","INDICE", "ITEM", "TIPO", "PRIORIDADE");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < contadorItem; i++) {
        freefire *NovaMochila = Mochila + i;

        printf("%-15d |%-30s | %-15s | %-10d\n",
               i,
               NovaMochila->nome,
               NovaMochila->tipo,
               NovaMochila->prioridade);
    }
    printf("------------------------------------------------------------------------------\n");
}

/// @brief função remover o item 
/// @param Mochila passa a struct
/// @param contadorItem  quantidade de itens na struct
/// @param indice passa o item para remoção
void RemoverItem(freefire *Mochila, int *contadorItem, int indice) {
    if (indice < 0 || indice >= *contadorItem) {
        printf("Indice invalido!\n");
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
            printf("%-15s |%-30s | %-15s | %-10s\n","INDICE", "ITEM", "TIPO", "PRIORIDADE");
            printf("------------------------------------------------------------------------------\n");
            printf("%-15d |%-30s | %-15s | %-10d\n",
               i,
               busca->nome,
               busca->tipo,
               busca->prioridade);
            printf("\n");

        }
    }
    printf("------------------------------------------------------------------------------\n");
    if (encontrado == 0) {
        printf("[AVISO] Item nao Encontrado\n");
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

    printf("Lista ordenada com sucesso por NOME (Bubble Sort)!\n");
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
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].prioridade);
    } else {
        printf("\n[AVISO] Item nao encontrado!\n");
    }

    printf("Numero de comparacoes (Sequencial): %d\n", comparacoes);
}

/// @brief Busca Sequencial pelo metodo Insertion sort
/// @param Mochila 
/// @param contadorItem 
void BuscaSequencialInsertion(freefire *Mochila, int contadorItem) {
    char tipoBusca[MAX_TIPO];
    int comparacoes = 0;
    int encontrado = -1;

    printf("\nDigite o tipo do item para busca SEQUENCIAL: ");
    fgets(tipoBusca, sizeof(tipoBusca), stdin);
    tipoBusca[strcspn(tipoBusca, "\n")] = '\0';

    for (int i = 0; i < contadorItem; i++) {
        comparacoes++;
        if (strcmp(Mochila[i].tipo, tipoBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("\nItem encontrado no indice %d.\n", encontrado);
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].prioridade);
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
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].prioridade);
    } else {
        printf("\n[AVISO] Item nao encontrado!\n");
    }

    printf("Numero de comparacoes (Binaria): %d\n", comparacoes);
}

/// @brief Busca Binaria pelo metodo Insertion sort
/// @param Mochila 
/// @param contadorItem 
void BuscaBinariaInsertion(freefire *Mochila, int contadorItem) {
    char tipoBusca[MAX_TIPO];
    int inicio = 0, fim = contadorItem - 1, meio;
    int comparacoes = 0;
    int encontrado = -1;

    printf("\nDigite o tipo do item para busca BINARIA: ");
    fgets(tipoBusca, sizeof(tipoBusca), stdin);
    tipoBusca[strcspn(tipoBusca, "\n")] = '\0';

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoes++;

        int cmp = strcmp(Mochila[meio].tipo, tipoBusca);

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
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].prioridade);
    } else {
        printf("\n[AVISO] Item nao encontrado!\n");
    }

    printf("Numero de comparacoes (Binaria): %d\n", comparacoes);
}


/// @brief Busca sequencial pelo metodo Selection sort
/// @param Mochila 
/// @param contadorItem 
void BuscaSequencialSelection(freefire *Mochila, int contadorItem) {
    int prioridadeBusca;
    int comparacoes = 0;
    int encontrado = -1;

    printf("\nDigite a prioridade do item para busca SEQUENCIAL: ");
    if (scanf("%d", &prioridadeBusca) != 1) {
        printf("[ERRO] Entrada invalida!\n");
        LimpaBuffer();
        return;
    }
    LimpaBuffer();

    for (int i = 0; i < contadorItem; i++) {
        comparacoes++;
        if (Mochila[i].prioridade == prioridadeBusca) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("\nItem encontrado no indice %d.\n", encontrado);
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].prioridade);
    } else {
        printf("\n[AVISO] Item nao encontrado!\n");
    }

    printf("Numero de comparacoes (Sequencial): %d\n", comparacoes);
}


/// @brief Busca binaria pelo metodo Selection sort
/// @param Mochila 
/// @param contadorItem 
void BuscaBinariaSelection(freefire *Mochila, int contadorItem) {
    int prioridadeBusca;
    int inicio = 0, fim = contadorItem - 1, meio;
    int comparacoes = 0;
    int encontrado = -1;

    printf("\nDigite a prioridade do item para busca BINARIA: ");
    if (scanf("%d", &prioridadeBusca) != 1) {
        printf("[ERRO] Entrada invalida!\n");
        LimpaBuffer();
        return;
    }
    LimpaBuffer();

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoes++;

        if (Mochila[meio].prioridade == prioridadeBusca) {
            encontrado = meio;
            break;
        } else if (Mochila[meio].prioridade < prioridadeBusca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado != -1) {
        printf("\nItem encontrado no Indice %d.\n", encontrado);
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               Mochila[encontrado].nome,
               Mochila[encontrado].tipo,
               Mochila[encontrado].prioridade);
    } else {
        printf("\n[AVISO] Item nao encontrado!\n");
    }

    printf("Numero de comparacoes (Binaria): %d\n", comparacoes);
}

/// @brief Ordena a Lista pelo metodo Insertion Sort
/// @param Mochila 
/// @param contadorItem 
void OrdenarInsertionSort(freefire *Mochila, int contadorItem) {
    if (contadorItem < 2) {
        printf("Poucos itens para ordenar!\n");
        return;
    }

    for (int i = 1; i < contadorItem; i++) {
        freefire chave = Mochila[i];
        int j = i - 1;

        while (j >= 0 && strcmp(Mochila[j].tipo, chave.tipo) > 0) {
            Mochila[j + 1] = Mochila[j];
            j--;
        }
        Mochila[j + 1] = chave;
    }

    printf("Lista ordenada com sucesso por TIPO (Insertion Sort)!\n");
}

/// @brief Ordena a lista pelo metodo Selection Sort
/// @param Mochila 
/// @param contadorItem 
void OrdenarSelectionSort(freefire *Mochila, int contadorItem) {
    if (contadorItem < 2) {
        printf("Poucos itens para ordenar!\n");
        return;
    }

    for (int i = 0; i < contadorItem - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < contadorItem; j++) {
            if (Mochila[j].prioridade < Mochila[minIndex].prioridade) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            freefire temp = Mochila[i];
            Mochila[i] = Mochila[minIndex];
            Mochila[minIndex] = temp;
        }
    }

    printf("Lista ordenada com sucesso por PRIORIDADE (Selection Sort)!\n");
}



/// @brief Medi o tempo de ordenaçao 
/// @param Mochila 
/// @param contadorItem 
void MedirTempo(freefire *Mochila, int contadorItem) {
    clock_t inicio, fim;
    double tempo;

    freefire *copia = (freefire *)calloc(contadorItem, sizeof(freefire));

    if (copia == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("\n=== MEDICAO DE TEMPO DAS ORDENACOES ===\n\n");

    // BUBBLE SORT
    memcpy(copia, Mochila, contadorItem * sizeof(freefire));
    inicio = clock();
    OrdenarSequencial(copia, contadorItem);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Bubble Sort (Nome): %.6f segundos\n", tempo);

    // INSERTION SORT
    memcpy(copia, Mochila, contadorItem * sizeof(freefire));
    inicio = clock();
    OrdenarInsertionSort(copia, contadorItem);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Insertion Sort (Tipo): %.6f segundos\n", tempo);

    // SELECTION SORT
    memcpy(copia, Mochila, contadorItem * sizeof(freefire));
    inicio = clock();
    OrdenarSelectionSort(copia, contadorItem);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Selection Sort (Prioridade): %.6f segundos\n", tempo);

    printf("\n");
    free(copia);
}