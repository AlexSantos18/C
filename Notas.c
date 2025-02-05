#include <stdio.h>

int main(){
  // Declaração das variaveis 
  char aluno[30];
  int idade = 0;
  int matricula = 0;
  float nota1 = 0;
  float nota2 = 0;
  float nota3 = 0;
  float media = 0;
  //Entrada de dados dos alunos 
  printf("Digite o Nome do Aluno: ");
  scanf("%s", &aluno);
  printf("Digite a idade do Aluno: ");
  scanf("%d", &idade);
  printf("Digite a matricula: ");
  scanf("%d", &matricula);
  printf("Primeira nota: ");
  scanf("%f", &nota1);
  printf("Segunda nota: ");
  scanf("%f", &nota2);
  printf("Terceira nota: ");
  scanf("%f", & nota3);
  media = (nota1 + nota2 + nota3) / 3; // media aritimetica
  printf("A matricula n. %d corresponde ao Aluno %s do qual teve uma media de %.2f\n",matricula, aluno, media); 
  system("pause");  
  return 0;
}