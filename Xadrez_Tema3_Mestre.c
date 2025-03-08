#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.


// Funçao Recursiva 
void Torre(int casa){
    if (casa > 0)
    {
        printf("Direita\n");
        Torre(casa -1);
    
    }
}

void Bispo(int casa){
    if (casa > 0){
        printf("Cima\n");
        printf("Direita\n");
        Bispo(casa - 1);
    }
}
void Rainha(int casa){
    if (casa > 0){
        printf("Esquerda\n");
        Rainha(casa - 1);
    }
}

int main() {
    int i = 1, n = 1;
    int j, m, k;

    printf("Jogador sua Torre sera movimentada 5 casas a direita \n");
    Torre(5); // Chama a funçao recorsiva e faz o loop 5 vezes 
    printf("\n");
    printf("\n");
    printf("\n");

    printf("Jogador seu Bispo sera movimentado 5 casas na diagonal para acima e direita \n");
    
    Bispo(5);   // chama a segunda funçao
    printf("\n");
    printf("\n");
    printf("\n");

    printf("Jogador sua Rainha sera movimentada 8 casas para esquerda \n");

    Rainha(8);  // chama a utima funçao 
    printf("\n");
    printf("\n");
    printf("\n");

    i = 1;

    // Loop encadeado ultilizando o do while externo e o form interno
    printf("Jogador seu Cavalo sera movimentado 2 casas para Cima para Direita \n");

    do
    {
        for (j = 0; j < 2; j++)
        {
            printf("Cima\n");
        }

        printf("Direita\n");
        
    } while (i < 1);
    printf("\n");
    printf("\n");
    printf("\n");
    //Loop for alinhados 
    printf("Jogador seu Bispo sera movimentado 5 casas na diagonal para acima e Direita \n");
    
    for(k = 0; k < 5; k++)
    {
        printf("Cima\n");
        for (m = 0; m < 1; m++)
        {
            printf("Direita\n");
        }

    }
    
    return 0;
}