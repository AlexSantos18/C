#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {{0}}; // criação de uma matriz 10x10 com todos os elementos iguais a 0
    int cone[5][5] ={
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}}; // criação de uma matriz 5x5 com todos os elementos formando um cone

    int cruz[5][5] ={
        {0,0,2,0,0},
        {0,0,2,0,0},
        {2,2,2,2,2},
        {0,0,2,0,0},
        {0,0,2,0,0}}; // criação de uma matriz 5x5 com todos os elementos formando uma cruz

    int octagono[5][5] ={
        {0,0,3,0,0},
        {0,3,3,3,0},
        {3,3,3,3,3},
        {0,3,3,3,0},
        {0,0,3,0,0}}; // criação de uma matriz 5x5 com todos os elementos formando um octógono

       int i, j; // variaveis de controle de laço

    printf(" __  __  __  __  __  __  __  __  __  __\n");

    for (i = 0; i < 5; i++) {           // laço para percorrer as linhas da matriz
        for (j = 0; j < 5; j++) {       // laço para percorrer as colunas da matriz

            if (cone[i][j] == 1){       // se o elemento da matriz cone for igual a 1
                tabuleiro[i][j] = 1;    //  o elemento da matriz tabuleiro na mesma posição recebe 1
            }
            if (cruz[i][j] == 2){       // se o elemento da matriz cruz for igual a 2
                tabuleiro[i + 2][j +4] = 2; //  o elemento da matriz +2 linhas e +4 colunas da matriz tabuleiro na mesma posição recebe 2
            }
            if (octagono[i][j] == 3){ // se o elemento da matriz octagono for igual a 3
                tabuleiro[i + 5][j +1] = 3;   //   o elemento da matriz +5 linhas e +1 coluna da matriz tabuleiro na mesma posição recebe 3
            }
        }
    }
    
    for (i = 0; i < 10; i++) {  // laço para percorrer as linhas da matriz
        for(j = 0; j < 10; j++){       // laço para percorrer as colunas da matriz
            printf("| %d ", tabuleiro[i][j]); // imprime o elemento da matriz tabuleiro na posição i,j
        }
        printf("|\n");
        printf(" __  __  __  __  __  __  __  __  __  __\n");
    }



    return 0;
}