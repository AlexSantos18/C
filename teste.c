#include <stdio.h>


typedef struct {
    char entrada[3];
    int id, valor;
    
}Teste;

void entrada_dados(Teste *teste){
    printf("digite o entrada: ");
    scanf("%s", teste->entrada);
    printf("Digite o id: ");
    scanf("%d", &teste->id);
    printf("digite o valor: ");
    scanf("%d", &teste->valor);
}

void saida_dados(Teste teste){
    printf("Entrada %s \n", teste.entrada);
    printf("id %d \n", teste.id);
    printf("Valor %d \n", teste.valor);
    getchar();
   
}

void menu(void){
   
    printf("[1] Cadastro\n");
    printf("[2] Visualizacao\n");
    printf("[3] Numeros Pares ou impares\n");
    printf("[4] tabuada\n");
    printf("Escolha a Opcao: ");
    
}

int main(){ 
    int resultado, opcao, i, numero;
    Teste teste, teste2;
    i = 0;

    do
    {
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            entrada_dados(&teste);
            entrada_dados(&teste2);
           // system("cls"); 
            break;
        case 2:
            saida_dados(teste);
            saida_dados(teste2);
           // system("cls");
            break;
        case 3:
            while (i <= 10)
            {
                if (i % 2 == 0){
                    printf("O numero %d e par! \n", i);
                } else {
                    printf("O numero %d e impar! \n", i);
                }

                i++;
            }
            break;
        case 4:
            printf("Digite um numero para calcularmos a tabuada: ");
            scanf("%d", &numero);

            for ( i = 0; i <= 10; i++)
            {
                printf("%d x %d = %d \n", i, numero, i * numero);

            }
            getchar();
            break;

        default:
            break;
        }

    } while (opcao < 5);
    resultado = teste.valor + teste2.valor;
    printf("a soma e %d", resultado);

    return 0;
}

