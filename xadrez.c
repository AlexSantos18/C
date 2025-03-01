#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    int i = 1, n = 1;
    

    // Primeiro loop ultilizado foi do while
    // criado uma variavel i para a repetiçao

    printf("Jogador sua Torre sera movimentada 5 casas a direita \n");
    do
    {
        printf("Direita\n");
        i++;

    } while (i <=5);

    printf("\n");
    printf("\n");
    printf("\n");

    // Segundo loop ultilizado foi o for
    // a variavel i do for nao interfere na variavel global


    printf("Jogador seu Bispo sera movimentado 5 casas na diagonal para direita e acima \n");
    
    for (i = 1; i <= 5; i++)
    {
        printf("Cima\n");
        printf("Direita\n");
    }

    printf("\n");
    printf("\n");
    printf("\n");

    // Terceiro loop ultilizado foi o while
    // criando uma nova variavel para o loop

    printf("Jogador sua Rainha sera movimentada 8 casas para esquerda \n");

    while (n <= 8)
    {
        printf("Esquerda\n");
        n++;
    }
    
    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}