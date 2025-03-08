#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {{0}}; // criação de uma matriz 10x10 com todos os elementos iguais a 0
    int barco[3] = {3, 3, 3}; // criação de um vetor com 3 elementos iguais a 3

    int i, j; // variaveis de controle de laço
    
    printf("BATALHA NAVAL!!!! \n\n");
    printf(" __  __  __  __  __  __  __  __  __  __\n");

    for (i  = 0; i < 3; i++) {
        tabuleiro[barco[0] + 4][barco[1] + i + 1] = 3; // Laço que percorre o vetor barco e atribui o valor 3 a matriz tabuleiro horizontal
    }                                                   // indice 0 tem valor 3 + 4 = 7 percore ate a linha 7, indice 1 tem valor 3 + 1 = 4 percore a coluna 4 e adiciona o valor 3 e assim por diante, aqui a linha é fixa e o que percorre é a coluna.

    for (i = 0; i < 3; i++) {
        tabuleiro[barco[2] + i][barco[1]] = 3; // Laço que percorre o vetor barco e atribui o valor 3 a matriz tabuleiro vertical
    }                                           // indice 2 tem valor 3 + 0 = 3 percorre ate a linha 3 e aqui a coluna é fixa o que percore é a linha e adiciona o valor 3 e assim por diante.

 
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) { // Laço que percorre a matriz tabuleiro e imprime os valores com a formatação de um tabuleiro

            printf("| %d ", tabuleiro[i][j]);
        }
        printf("|\n");
        printf(" __  __  __  __  __  __  __  __  __  __\n");
    }


    return 0;
}