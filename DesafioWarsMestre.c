#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ============================================================================
// CONSTANTES GLOBAIS
// ============================================================================
#define MAX_TERRITORIO 5
#define TAM_STRING_NOME 30
#define TAM_STRING_COR 10
#define MIN_TROPAS 1
#define MAX_TROPAS 5
#define QT_MISSOES 5
#define TAM_MISSAO 100

// ============================================================================
// ESTRUTURAS DE DADOS
// ============================================================================
typedef struct
{
    char nome[TAM_STRING_NOME];
    char cor[TAM_STRING_COR];
    int tropas;
} Territorio;

typedef struct
{
    char descricao[TAM_MISSAO];
    int ativa;           // 1 = missão ativa, 0 = não ativa
    int completada;      // 1 = completada, 0 = não completada
} MissaoJogador;

// ============================================================================
// FUNÇÕES AUXILIARES
// ============================================================================

/**
 * Limpa o buffer de entrada para evitar problemas com scanf
 */
void LimparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/**
 * Imprime um único território formatado
 * @param t Ponteiro para o território
 * @param indice Número do território para exibição (indice do vetor)
 */
void ImprimirTerritorio(Territorio *t, int indice)
{
    printf("Territorio %d:\n", indice);
    printf("  Nome: %s\n", t->nome);
    printf("  Cor das Tropas: %s\n", t->cor);
    printf("  Quantidade de Tropas: %d\n", t->tropas);
    printf("______________________________________\n\n");
}

/**
 * Imprime um território em formato resumido 
 * @param t Ponteiro para o território
 * @param indice Número do território para exibição (indice do vetor)
 */
void ImprimirTerritorioResumido(Territorio *t, int indice)
{
    printf("Territorio %d: Nome: %s, Cor: %s, Tropas: %d\n",
           indice, t->nome, t->cor, t->tropas);
    printf("________________________________________________________________________\n");
}

/**
 * Valida se um número está dentro do intervalo permitido
 * @param valor Valor a ser validado
 * @param min Valor mínimo permitido
 * @param max Valor máximo permitido
 * @return 1 se válido, 0 se inválido
 */
int ValidarIntervalo(int valor, int min, int max)
{
    return (valor >= min && valor <= max);
}

/**
 * Simula o lançamento de um dado 
 * @return Valor entre 1 e 6
 */
int LancarDado()
{
    return 1 + rand() % 6;
}

// ============================================================================
// FUNÇÕES DE GERENCIAMENTO DE TERRITÓRIOS
// ============================================================================

/**
 * Inicializa os territórios ja com os dados preenchidos 
 * Usa calloc para alocar memória 
 * @return Ponteiro para vetor de territórios alocado dinamicamente
 */
Territorio *InicializarTerritorio()
{
    // Alocando memória com calloc 
    Territorio *territorios = (Territorio *)calloc(MAX_TERRITORIO, sizeof(Territorio));

    if (territorios == NULL)
    {
        printf("\n[ERRO] Falha ao alocar memoria para territorios!\n");
        exit(1);
    }

    // Inicializando cada território
    strcpy((territorios + 0)->nome, "Europa");
    strcpy((territorios + 0)->cor, "Verde");
    (territorios + 0)->tropas = 3;

    strcpy((territorios + 1)->nome, "Asia");
    strcpy((territorios + 1)->cor, "Vermelho");
    (territorios + 1)->tropas = 2;

    strcpy((territorios + 2)->nome, "America");
    strcpy((territorios + 2)->cor, "Azul");
    (territorios + 2)->tropas = 4;

    strcpy((territorios + 3)->nome, "Oceania");
    strcpy((territorios + 3)->cor, "Amarelo");
    (territorios + 3)->tropas = 2;

    strcpy((territorios + 4)->nome, "Africa");
    strcpy((territorios + 4)->cor, "Branco");
    (territorios + 4)->tropas = 1;

    printf("\n[SUCESSO] %d territorios inicializados com sucesso!\n\n", MAX_TERRITORIO);
    return territorios;
}

/**
 * Lista todos os territórios cadastrados
 * @param territorios Ponteiro para vetor de territórios
 * @param total Quantidade de territórios no vetor
 */
void ListarTerritorios(Territorio *territorios, int total)
{
    if (territorios == NULL || total == 0)
    {
        printf("\n[AVISO] Nenhum territorio cadastrado ainda!\n");
        printf("Escolha a opcao 1 no menu para inicializar os territorios.\n\n");
        return;
    }

    printf("\n########################\n");
    printf("Listagem dos Territorios\n");
    printf("########################\n\n");

    // Usando aritmética de ponteiros para percorrer o array
    for (int i = 0; i < total; i++)
    {
        Territorio *atual = territorios + i;
        ImprimirTerritorio(atual, i + 1);
    }
}

/**
 * Libera a memória alocada para os territórios
 * @param territorios Ponteiro duplo para poder setar NULL após free
 */
void LiberarTerritorios(Territorio **territorios)
{
    if (*territorios != NULL)
    {
        free(*territorios);
        *territorios = NULL;
        printf("\n[INFO] Memoria de territorios liberada com sucesso.\n");
    }
}

// ============================================================================
// FUNÇÕES DE SISTEMA DE MISSÕES
// ============================================================================

/**
 * Cria e retorna um vetor de strings com todas as missões disponíveis
 * Usa calloc para alocar memória dinamicamente
 * @return Ponteiro para array de ponteiros de strings (char**)
 */
char **Missoes()
{
    // Alocando array de ponteiros para strings
    char **missoes = (char **)calloc(QT_MISSOES, sizeof(char *));
    
    if (missoes == NULL)
    {
        printf("\n[ERRO] Falha ao alocar memoria para missoes!\n");
        exit(1);
    }

    // Alocando memória para cada string individual
    for (int i = 0; i < QT_MISSOES; i++)
    {
        *(missoes + i) = (char *)calloc(TAM_MISSAO, sizeof(char));
        
        if (*(missoes + i) == NULL)
        {
            printf("\n[ERRO] Falha ao alocar memoria para missao %d!\n", i);
            exit(1);
        }
    }

    // Inicializando as missões 
    strcpy(*(missoes + 0), "Venca o Territorio Vermelho");
    strcpy(*(missoes + 1), "Venca o Territorio Azul");
    strcpy(*(missoes + 2), "Conquiste um Territorio");
    strcpy(*(missoes + 3), "Venca o Territorio Verde");
    strcpy(*(missoes + 4), "Venca o Territorio Amarelo");

    return missoes;
}

/**
 * Sorteia uma missão aleatória e atribui ao jogador
 * @param missaoJogador Ponteiro para estrutura da missão do jogador
 * @param missoes vetor de strings com todas as missões 
 */
void AtribuirMissao(MissaoJogador *missaoJogador, char **missoes)
{
    if (missaoJogador == NULL || missoes == NULL)
    {
        printf("\n[ERRO] Ponteiros invalidos para atribuir missao!\n");
        return;
    }

    // Sorteia um número entre 0 e 4 (índices do vetor de missões)
    int sorteio = rand() % QT_MISSOES;
    
    // Copia a missão sorteada para a estrutura do jogador
    strcpy(missaoJogador->descricao, *(missoes + sorteio));
    missaoJogador->ativa = 1;
    missaoJogador->completada = 0;

    printf("\n==============================================\n");
    printf("  MISSAO ATRIBUIDA!\n");
    printf("==============================================\n");
    printf("Sua missao: %s\n", missaoJogador->descricao);
    printf("==============================================\n\n");
}

/**
 * Exibe a missão atual do jogador
 * @param missaoJogador Ponteiro para estrutura da missão do jogador
 */
void MissaoAtual(MissaoJogador *missaoJogador)
{
    if (missaoJogador == NULL)
    {
        printf("\n[ERRO] Missao nao inicializada!\n");
        return;
    }

    printf("\n########################\n");
    printf("    MISSAO ATUAL\n");
    printf("########################\n\n");

    if (!missaoJogador->ativa)
    {
        printf("Nenhuma missao ativa no momento.\n");
        printf("Inicialize os territorios para receber uma missao!\n\n");
        return;
    }

    printf("Missao: %s\n", missaoJogador->descricao);
    
    if (missaoJogador->completada)
    {
        printf("Status: [COMPLETADA] \n");
        printf("\n*** PARABENS! Voce completou sua missao! ***\n");
    }
    else
    {
        printf("Status: [EM ANDAMENTO]\n");
    }
    
    printf("\n");
}

/**
 * Verifica se a missão foi completada após uma batalha
 * @param missaoJogador Ponteiro para estrutura da missão do jogador
 * @param territorios Ponteiro para vetor de territórios
 * @param total Quantidade total de territórios
 * @return 1 se missão foi completada, 0 caso contrário
 */
int VerificarMissao(MissaoJogador *missaoJogador, Territorio *territorios, int total)
{
    if (missaoJogador == NULL || territorios == NULL || !missaoJogador->ativa)
    {
        return 0;
    }

    // Se já foi completada, retorna imediatamente
    if (missaoJogador->completada)
    {
        return 1;
    }

    // Verificar cada tipo de missão usando strstr para buscar palavras-chave
    
    // Missão: "Venca o Territorio Vermelho"
    if (strstr(missaoJogador->descricao, "Vermelho") != NULL)
    {
        // Procura o território Vermelho
        for (int i = 0; i < total; i++)
        {
            Territorio *t = territorios + i;
            if (strcmp(t->cor, "Vermelho") != 0 && strcmp(t->nome, "Asia") == 0)
            {
                // Asia foi conquistada (mudou de cor)
                missaoJogador->completada = 1;
                printf("\n*** MISSAO COMPLETADA! ***\n");
                printf("Voce venceu o territorio Vermelho!\n\n");
                return 1;
            }
        }
    }
    
    // Missão: "Venca o Territorio Azul"
    else if (strstr(missaoJogador->descricao, "Azul") != NULL)
    {
        for (int i = 0; i < total; i++)
        {
            Territorio *t = territorios + i;
            if (strcmp(t->cor, "Azul") != 0 && strcmp(t->nome, "America") == 0)
            {
                missaoJogador->completada = 1;
                printf("\n*** MISSAO COMPLETADA! ***\n");
                printf("Voce venceu o territorio Azul!\n\n");
                return 1;
            }
        }
    }
    
    // Missão: "Venca o Territorio Verde"
    else if (strstr(missaoJogador->descricao, "Verde") != NULL)
    {
        for (int i = 0; i < total; i++)
        {
            Territorio *t = territorios + i;
            if (strcmp(t->cor, "Verde") != 0 && strcmp(t->nome, "Europa") == 0)
            {
                missaoJogador->completada = 1;
                printf("\n*** MISSAO COMPLETADA! ***\n");
                printf("Voce venceu o territorio Verde!\n\n");
                return 1;
            }
        }
    }
    
    // Missão: "Venca o Territorio Amarelo"
     else if (strstr(missaoJogador->descricao, "Amarelo") != NULL)
    {
        for (int i = 0; i < total; i++)
        {
            Territorio *t = territorios + i;
            if (strcmp(t->cor, "Amarelo") != 0 && strcmp(t->nome, "Oceania") == 0)
            {
                missaoJogador->completada = 1;
                printf("\n*** MISSAO COMPLETADA! ***\n");
                printf("Voce venceu o territorio Amarelo!\n\n");
                return 1;
            }
        }
    }
    // Missão: "Conquiste um Territorio"
    else if (strstr(missaoJogador->descricao, "Conquiste") != NULL)
    {
        // Esta missão é verificada diretamente na função de batalha
        // quando há dominação total
        return 0;
    }

    return 0;
}

/**
 * Libera a memória alocada para as missões
 * @param missoes Ponteiro duplo para o vetor de strings
 */
void LiberarMissoes(char ***missoes)
{
    if (*missoes != NULL)
    {
        // Liberar cada string individual
        for (int i = 0; i < QT_MISSOES; i++)
        {
            if (*(*missoes + i) != NULL)
            {
                free(*(*missoes + i));
            }
        }
        
        // Liberar o array de ponteiros
        free(*missoes);
        *missoes = NULL;
        printf("[INFO] Memoria de missoes liberada com sucesso.\n");
    }
}

// ============================================================================
// FUNÇÕES DE BATALHA
// ============================================================================

/**
 * Lê e valida a escolha de um território
 * @param mensagem Mensagem a ser exibida ao usuário
 * @param min Índice mínimo permitido
 * @param max Índice máximo permitido
 * @return Índice escolhido ou -1 em caso de erro
 */
int LerEscolhaTerritorio(const char *mensagem, int min, int max)
{
    int escolha;
    printf("%s", mensagem);

    if (scanf("%d", &escolha) != 1)
    {
        printf("\n[ERRO] Entrada invalida! Digite um numero.\n");
        LimparBuffer();
        return -1;
    }

    LimparBuffer();

    if (!ValidarIntervalo(escolha, min, max))
    {
        printf("\n[ERRO] Numero fora do intervalo! Digite um valor entre %d e %d.\n", min, max);
        return -1;
    }

    return escolha;
}

/**
 * Processa a vitória do atacante
 * @param atacante Ponteiro para território atacante
 * @param defensor Ponteiro para território defensor
 * @param indiceDefesa Índice do defensor (para exibição)
 * @param missaoJogador Ponteiro para missão do jogador
 * @return 1 se houve conquista total, 0 caso contrário
 */
int ProcessarVitoriaAtaque(Territorio *atacante, Territorio *defensor, int indiceDefesa, MissaoJogador *missaoJogador)
{
    printf("\n>>> O Territorio de Ataque VENCEU! <<<\n");
    defensor->tropas--;

    if (defensor->tropas == 0)
    {
        printf("\n*** DOMINIO TOTAL! ***\n");
        printf("O territorio %d foi conquistado!\n", indiceDefesa);
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = MIN_TROPAS;
        
        // Verificar se completou a missão "Conquiste um Territorio"
        if (missaoJogador != NULL && strstr(missaoJogador->descricao, "Conquiste") != NULL)
        {
            missaoJogador->completada = 1;
            printf("\n*** MISSAO COMPLETADA! ***\n");
            printf("Voce conquistou um territorio!\n\n");
        }
        
        return 1; // Houve conquista
    }
    else
    {
        printf("O territorio defensor perdeu 1 tropa.\n");
        return 0; // Não houve conquista
    }
}

/**
 * Processa a vitória do defensor
 * @param atacante Ponteiro para território atacante
 * @param defensor Ponteiro para território defensor
 * @param indiceAtaque Índice do atacante (para exibição)
 */
void ProcessarVitoriaDefesa(Territorio *atacante, Territorio *defensor, int indiceAtaque)
{
    printf("\n>>> O Territorio de Defesa RESISTIU! <<<\n");
    atacante->tropas--;

    if (atacante->tropas == 0)
    {
        printf("\n*** CONTRA-ATAQUE VITORIOSO! ***\n");
        printf("O territorio %d foi conquistado pelo defensor!\n", indiceAtaque);
        strcpy(atacante->cor, defensor->cor);
        atacante->tropas = MIN_TROPAS;
    }
    else
    {
        printf("O territorio atacante perdeu 1 tropa.\n");
    }
}

/**
 * Executa uma batalha entre dois territórios
 * @param territorios Ponteiro para array de territórios
 * @param total Quantidade total de territórios
 * @param missaoJogador Ponteiro para missão do jogador
 */
void Batalha(Territorio *territorios, int total, MissaoJogador *missaoJogador)
{
    printf("\n########################\n");
    printf("    MODO BATALHA\n");
    printf("########################\n\n");

    // Validação inicial
    if (territorios == NULL || total < 2)
    {
        printf("[ERRO] Nao existem territorios suficientes para batalha!\n");
        printf("Cadastre os territorios primeiro (opcao 1).\n\n");
        return;
    }

    // Exibir territórios disponíveis
    printf("Territorios disponiveis para batalha:\n\n");
    for (int i = 0; i < total; i++)
    {
        ImprimirTerritorioResumido(territorios + i, i + 1);
    }

    // Ler escolhas do usuário
    printf("\n");
    int indiceAtaque = LerEscolhaTerritorio(
        "Escolha o numero do Territorio de ATAQUE: ", 1, total);

    if (indiceAtaque == -1)
        return;

    int indiceDefesa = LerEscolhaTerritorio(
        "Escolha o numero do Territorio de DEFESA: ", 1, total);

    if (indiceDefesa == -1)
        return;

    // Validar que os territórios são diferentes
    if (indiceAtaque == indiceDefesa)
    {
        printf("\n[ERRO] O territorio de ataque nao pode ser o mesmo da defesa!\n");
        printf("A batalha foi cancelada.\n\n");
        return;
    }

    // Ponteiros para os territórios envolvidos (convertendo de 1-based para 0-based)
    Territorio *atacante = territorios + (indiceAtaque - 1);
    Territorio *defensor = territorios + (indiceDefesa - 1);

    // Simular lançamento dos dados
    printf("\n=== Rolando os dados ===\n\n");
    int dadoAtaque = LancarDado();
    int dadoDefesa = LancarDado();

    printf("Territorio %d (%s) tirou: %d\n", indiceAtaque, atacante->nome, dadoAtaque);
    printf("Territorio %d (%s) tirou: %d\n", indiceDefesa, defensor->nome, dadoDefesa);
    printf("________________________\n");

    // Determinar resultado
    if (dadoAtaque == dadoDefesa)
    {
        printf("\n=== EMPATE! ===\n");
        printf("Nenhum territorio perdeu tropas. A batalha terminou em empate.\n");
    }
    else if (dadoAtaque > dadoDefesa)
    {
        ProcessarVitoriaAtaque(atacante, defensor, indiceDefesa, missaoJogador);
    }
    else
    {
        ProcessarVitoriaDefesa(atacante, defensor, indiceAtaque);
    }

    // Exibir estado final dos territórios
    printf("\n=== Estado Apos a Batalha ===\n\n");
    for (int i = 0; i < total; i++)
    {
        ImprimirTerritorioResumido(territorios + i, i + 1);
    }
    
    // Verificar se a missão foi completada após a batalha
    if (missaoJogador != NULL && missaoJogador->ativa)
    {
        VerificarMissao(missaoJogador, territorios, total);
    }
    
    printf("\n");
}

// ============================================================================
// FUNÇÕES DE INTERFACE
// ============================================================================

/**
 * Exibe o menu principal
 */
void ExibirMenu()
{
    printf("===========================\n");
    printf("         JOGO WAR \n");
    printf("===========================\n");
    printf("1 - Inicializar Territorios\n");
    printf("2 - Listar Territorios\n");
    printf("3 - Missao Atual\n");
    printf("4 - Iniciar Batalha\n");
    printf("5 - Sair\n");
    printf("___________________________\n");
    printf("Escolha uma opcao: ");
}

/**
 * Lê e valida a opção do menu
 * @return Opção escolhida ou -1 em caso de erro
 */
int LerOpcaoMenu()
{
    int opcao;

    if (scanf("%d", &opcao) != 1)
    {
        printf("\n[ERRO] Opcao invalida! Digite um numero.\n\n");
        LimparBuffer();
        return -1;
    }

    LimparBuffer();
    return opcao;
}

// ============================================================================
// PROGRAMA PRINCIPAL
// ============================================================================

int main()
{
    // Inicializar gerador de números aleatórios
    srand(time(NULL));

    // Variáveis de controle
    Territorio *territorios = NULL;
    char **listaMissoes = NULL;
    MissaoJogador *missaoJogador = NULL;
    int totalTerritorios = 0;
    int opcao;
    int jaInicializado = 0;

    // Alocar estrutura da missão do jogador
    missaoJogador = (MissaoJogador *)calloc(1, sizeof(MissaoJogador));
    if (missaoJogador == NULL)
    {
        printf("\n[ERRO] Falha ao alocar memoria para missao do jogador!\n");
        return 1;
    }

    printf("\n==============================================\n");
    printf("              BEM-VINDO AO WARS\n");
    printf("==============================================\n\n");

    // Loop principal do menu
    do
    {
        ExibirMenu();
        opcao = LerOpcaoMenu();

        if (opcao == -1)
        {
            continue; // Erro na leitura, mostrar menu novamente
        }

        switch (opcao)
        {
        case 1:
            if (jaInicializado)
            {
                printf("\n[AVISO] Territorios ja foram inicializados!\n");
                printf("Os territorios existentes serao substituidos.\n");
                LiberarTerritorios(&territorios);
                LiberarMissoes(&listaMissoes);
            }

            territorios = InicializarTerritorio();
            totalTerritorios = MAX_TERRITORIO;
            
            // Criar lista de missões e atribuir uma ao jogador
            listaMissoes = Missoes();
            AtribuirMissao(missaoJogador, listaMissoes);
            
            jaInicializado = 1;
            break;

        case 2:
            ListarTerritorios(territorios, totalTerritorios);
            break;

        case 3:
            MissaoAtual(missaoJogador);
            break;

        case 4:
            Batalha(territorios, totalTerritorios, missaoJogador);
            break;

        case 5:
            printf("\n==============================================\n");
            printf("  Encerrando o programa...\n");
            printf("  Obrigado por jogar!\n");
            printf("==============================================\n\n");
            break;

        default:
            printf("\n[ERRO] Opcao invalida! Escolha entre 1 e 5.\n\n");
            break;
        }

    } while (opcao != 5);

    // Liberação de memória antes de encerrar
    LiberarTerritorios(&territorios);
    LiberarMissoes(&listaMissoes);
    
    if (missaoJogador != NULL)
    {
        free(missaoJogador);
        printf("[INFO] Memoria de missao do jogador liberada.\n");
    }

    return 0;
}