#include <stdio.h>

int main(){
    // Declaraçoes de variaveis para a calculadora
    int vr1 = 0, vr2 = 0;
    float resultado =0;
    int escolha = 0;

    printf("Digite o Primeiro numero: ");
    scanf("%d", &vr1);  // recebe o primeiro numero
    printf("Digite o Segundo numero: ");
    scanf("%d", &vr2);   // recebe o segundo numero
    printf("O que voce gostaria de fazer?\n");
    printf("1: somar\n");
    printf("2: subtrair\n");
    printf("3: multiplicar\n");
    printf("4: dividir\n");
    printf("Opcao: ");
    scanf("%d", &escolha);
    if (escolha == 1)  // escolhas do usuario 
    {
        resultado = vr1 + vr2;
        printf("Seu resultado foi %.0f\n", resultado);
        system("pause");
    }else if (escolha == 2)
    {
        resultado = vr1 - vr2;
        printf("Seu resultado foi %.0f\n", resultado);
        system("pause");
    }else if (escolha == 3)
    {
        resultado = vr1 * vr2;
        printf("Seu resultado foi %.0f\n", resultado);
        system("pause");
    }else if (escolha == 4)
    {
        resultado = (float)vr1 / vr2;
        printf("Seu resultado foi %.2f\n", resultado);
        system("pause");
    }else if (escolha > 4)
    {
        printf("Opcao errada.\n");
        system("pause");
    }
    
    
    
    

        


    
}