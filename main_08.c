#include <stdio.h>
#include <stdlib.h>

#include "include/ferramentas.h"

int main(void)
{ 
	tListAlunos* lista;
  lista = malloc(1*sizeof(tListAlunos));
  iniListAlunos(lista, 10);
  // leitura de um arquivo
  FILE *fp;
  char path[20] = "dadosAlunos.txt";
  if((fp=fopen(path,"r"))==NULL){
    printf("Erro");
    exit(-1);
  }
  int i=0;
  for(i=0;!feof(fp) && i<lista->cap; i++){
    fscanf(fp,"%s\n", lista->lista[i].numMatricula);
    fgets(lista->lista[i].nome,99,fp);
    fscanf(fp,"%s\n", lista->lista[i].email);
  }
  lista->tam = i;
  printf("Arquivo:\n");
  printLisAluno(lista->lista, lista->tam);
  printf("tamanho = %d\n", lista->tam);
  printf("\n----------------------------------------\n");
  printf("Testando Listas Lineares Sequenciais Não Ordenadas");
  printf("\n----------------------------------------\n");
  
  //add um aluno ao arquivo
  tAluno aluno;
  char op=0;
  do{
    printf("\n----------------------------------------\n");
    printf("Incluindo um aluno no arquivo");
    printf("\n----------------------------------------\n");
    printf("Digite o numero de matricula: ");
    scanf("%s",aluno.numMatricula);
    getchar();
    printf("Digite o nome do aluno: "); 
    fgets(aluno.nome, 100, stdin);
    fflush(stdin);
    printf("Digite o email do aluno: ");
    scanf("%s",aluno.email);
    fflush(stdin);
    if(incNaoOrdenada(aluno, lista)){
      atualizar_arq(fp, lista, path);
      printf("Adicionado com sucesso!!\n");
      printf("\nArquivo atualizado:\n");
      printLisAluno(lista->lista, lista->tam);
    }else
      printf("\nNão foi possivel adicionar ao arquivo!\n");
  
    printf("tamanho = %d\n", lista->tam);
    printf("Deseja fazer outra inclusão (s/n)? ");
    scanf(" %c", &op);
  }while(op=='s' || op=='S');

  //remove um aluno do arquivo
  do{
    printf("\n----------------------------------------\n");
    printf("Removendo um aluno do arquivo");
    printf("\n----------------------------------------\n");
    printf("Digite o numero da matricula do aluno que deseja remover: ");
    scanf("%s", aluno.numMatricula);
    if(remNaoOrdenada(aluno,lista)){
      atualizar_arq(fp,lista,path);
      printf("Removido com sucesso!!\n");
      printf("\nArquivo atualizado:\n");
      printLisAluno(lista->lista, lista->tam);
    }else
      printf("\nNão foi possivel fazer a remoção\n");

    printf("Deseja fazer outra remoção (s/n)? ");
    scanf(" %c", &op);
  }while(op=='s' || op=='S');

  //Procurando um elemento que está na lista
  printf("\n----------------------------------------\n");
	printf("Testando o método de busca não ordenada"); 
  printf("\n----------------------------------------\n");
  do{
    printf("Digite o numero da matricula para pesquisar: ");
    scanf("%s", aluno.numMatricula);
    int index = buscaNaoOrdenada(lista, aluno.numMatricula);
    if(index < lista->tam){
      printf("Elemento achado com índice %d\n", index);
      printItemLisAluno(lista->lista, index);
    }else{
      printf("Elemento não se encontra na lista!!\n");
    }
    printf("Deseja fazer outra inclusão (s/n)? ");
    scanf(" %c", &op);
  }while(op=='s' || op=='S');
  
  free(lista);
	return 0;
}