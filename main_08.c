#include <stdio.h>
#include <stdlib.h>

#include "include/ferramentas.h"

int main(void)
{
	tListAlunos* lista;
  iniListAlunos(lista, 3);
  tAluno* lista_din;
  lista_din = (tAluno*)malloc(3*sizeof(tAluno));  
  // Colocar aqui a leitura de um arquivo
  FILE *fp;
  if((fp=fopen("dadosAlunos.txt","r"))==NULL){
    printf("Erro");
    exit(-1);
  }
  for(int i=0;i<4;i++){
    fscanf(fp,"%s\n", lista_din[i].numMatricula);
    fgets(lista_din[i].nome,99,fp);
    fscanf(fp,"%s\n", lista_din[i].email);
  }

  for(int i=0;i<4;i++){
        printf("%s\t", lista_din[i].numMatricula);
        printf("%s", lista_din[i].nome);
        printf("\t%s\n", lista_din[i].email);
     }

  printf("Testando Listas Lineares Sequenciais\n"); 

  /*
	strcpy(aluno.numMatricula, "201913425");
  strcpy(aluno.nome, "Regrano Guedes Maia");
  strcpy(aluno.email,"regguemai@uesc.br");
	incLisAluno(aluno, lista_stc, nLis);
  nLis++;

	strcpy(aluno.numMatricula, "201913245");
  strcpy(aluno.nome, "Mengano Martins Pereira");
  strcpy(aluno.email,"menmarper@uesc.br");
	incLisAluno(aluno, lista_stc, nLis);
	nLis++;

	strcpy(aluno.numMatricula, "201912345");
  strcpy(aluno.nome, "Fulano Silva Oliveira");
  strcpy(aluno.email,"fulsiloli@uesc.br");
	incLisAluno(aluno, lista_stc, nLis);
  nLis++;*/

	//Procurando um elemento que está na lista
	printLisAluno(lista_stc, nLis);
	printf("Testando o método de busca 2 de um\n"); 
	printf(" elemento que esta na lista: 201913425\n");
	index = buscaLisAluno2(lista_stc, nLis, "201913425");
	if(index < nLis){
    printf("Elemanto achado com índice %d\n", index);
		printItemLisAluno(lista_stc, index);
  }else{
    printf("Elemento não se encontra na lista!!\n");
  }

	//Procurando um elemento que não está na lista
	printf("Testando o método de busca 2 de um\n"); 
	printf(" elemento que não esta na lista: 201900000\n");
	index = buscaLisAluno2(lista_stc, nLis, "201900000");
	if(index < nLis){
    printf("Elemanto achado com índice %d\n", index);
		printItemLisAluno(lista_stc, index);
  }else{
    printf("Elemento não se encontra na lista!!\n");
  }


	free(lista_din);

	return 0;
}