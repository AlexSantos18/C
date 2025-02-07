#include <stdio.h>

int main(){
    // Declaraçao de variaveis 
    char nome[50];
    float n1, n2, n3, n4, media;
    media =  0;
    n1 = 0, n2 = 0, n3 = 0, n4 = 0;

    
    // Solicitando os dados do usuario
    printf("Nome do Aluno: ");
    scanf(" %s", nome);
    printf("Nota primeiro Bimestre: ");
    scanf("%f", &n1);
    printf("Nota segundo Bimestre: ");
    scanf("%f", &n2);
    printf("Nota terceiro Bimestre: ");
    scanf("%f", &n3);
    printf("Nota quarto Bimestre: ");
    scanf("%f", &n4);
    // calculo da media
    media = (n1 + n2 + n3 + n4)/ 4;
    // Se a media ficar igual ou superior a 7 será APROVADO caso contrario REPROVADO
    if (media >= 7)
    {
        printf("Parabens voce ficou com a media %.2f e foi APROVADO" , media);
    } else
    {
        printf("Sua media foi %.2f voce nao atingiu minimo de media, REPROVADO", media);
    }
    
    
}