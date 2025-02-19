#include <stdio.h>


typedef struct {
    char entrada[3];
    int id, valor;
    
}Teste;

void entrada_dados(Teste *teste){
    printf("digite o entrada: \n");
    scanf("%s", teste->entrada);
    printf("Digite o id: \n");
    scanf("%d", &teste->id);
    printf("digite o valor: \n");
    scanf("%d", &teste->valor);
}

void saida_dados(Teste teste){
    printf("Entrada %s \n", teste.entrada);
    printf("id %d \n", teste.id);
    printf("Valor %d \n", teste.valor);
   
}

int main(){ 
    int resultado;
    Teste teste, teste2;
    
    entrada_dados(&teste);
    entrada_dados(&teste2);   
    saida_dados(teste);
    saida_dados(teste2);
    resultado = teste.valor + teste2.valor;
    printf("a soma e %d", resultado);

    return 0;
}

