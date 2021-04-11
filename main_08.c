#include <stdio.h>
#include <stdlib.h>

#include "include/ferramentas.h"

int main(void)
{ 
	tListAlunos* lista;
  lista = malloc(1*sizeof(tListAlunos));
  iniListAlunos(lista, 10);
  // Colocar aqui a leitura de um arquivo
  FILE *fp;
  char nome[20] = "dadosAlunos.txt";
  if((fp=fopen(nome,"r"))==NULL){
    printf("Erro");
    exit(-1);
  }
  int i=0;
  for(i=0;!feof(fp); i++){
    fscanf(fp,"%s\n", lista->lista[i].numMatricula);
    fgets(lista->lista[i].nome,99,fp);
    fscanf(fp,"%s\n", lista->lista[i].email);
  }
  lista->tam = i;
  printf("Lista do arquivo\n");
  printLisAluno(lista->lista, lista->tam);
  printf("tamanho = %d\n", lista->tam);
  
  printf("Testando Listas Lineares Sequenciais Não Ordenadas\n");
  printf("--------------------------------------------------\n");
  //add um aluno ao arquivo
  tAluno aluno;
  printf("Incluindo um aluno no arquivo\n");
  printf("--------------------------------------------------\n");
  printf("Digite o numero de matricula: ");
  scanf("%s",aluno.numMatricula);
  getchar();
  printf("Digite o nome do aluno: "); 
  fgets(aluno.nome, 100, stdin);
  fflush(stdin);
  printf("Digite o email do aluno: ");
  scanf("%s",aluno.email);
  if(incNaoOrdenada(aluno, lista)){
     atualizar_arq(fp,lista,nome);
     printf("------------Adicionado com sucesso!!------------\n");
     printf("\nArquivo atualizado:\n");
     printLisAluno(lista->lista, lista->tam);
  }else
    printf("\nNão foi possivel adicionar ao arquivo!");
 
  printf("tamanho = %d\n", lista->tam);
 
  /*for(int j=0; j<i; j++){
    printf("%s\n",lista->lista[j].numMatricula);
    printf("%s",lista->lista[j].nome);
    printf("%s\n",lista->lista[j].email);
  }*/


   //printLisAluno(lista->lista, lista->tam);




  free(lista);
	return 0;
}