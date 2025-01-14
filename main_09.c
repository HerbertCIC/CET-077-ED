#include <stdio.h>
#include <stdlib.h>

#include "include/ferramentas.h"

void menu();
void incluirAluno_arq(tAluno, tListAlunos*, FILE*, char*);
void removerAluno_arq(tAluno, tListAlunos*, FILE*, char*);
void buscarAluno(tAluno, tListAlunos*);
void listarAlunos(tListAlunos*);

int main(void)
{ 
  //declaração
	tListAlunos* lista;
  lista = malloc(1*sizeof(tListAlunos));
  tAluno aluno; 
  FILE *fp; 
  char path[20] = "dadosAlunos.txt";
  char op=0;  
  int i=0;  
  
  iniListAlunos(lista, 6);  
  // leitura de um arquivo  
  if((fp=fopen(path,"r"))==NULL){
    printf("Erro");
    exit(-1);
  }  
  for(i=0;!feof(fp) && i<lista->cap; i++){
    fscanf(fp,"%s\n", lista->lista[i].numMatricula);
    fgets(lista->lista[i].nome,99,fp);
    fscanf(fp,"%s\n", lista->lista[i].email);
  }
  lista->tam = i;
  
  printf("Arquivo Original:\n");
  printLisAluno(lista->lista, lista->tam);
  //ordena arquivo
  mergeSort(lista->lista, 0, lista->tam-1);
  atualizar_arq(fp, lista, path);
  printf("Arquivo Ordenado:\n");
  printLisAluno(lista->lista, lista->tam);
  
  menu();
  while((op=getchar())!='5'){
    switch(op){
      case '1': incluirAluno_arq(aluno, lista, fp, path);
        break;
      case '2': removerAluno_arq(aluno, lista, fp, path);
        break;
      case '3': buscarAluno(aluno, lista);
        break;
      case '4': listarAlunos(lista);
        break;
      case '\n':
      case ' ':
        break;
      default:
          printf("Opcão inválida");
          system("PAUSE");
          break;
      }
      getchar();
      menu();
  } 

  free(lista);
	return 0;
}

void menu(){
    printf("\n------------------------------------------------\n");
    printf("Testando Listas Lineares Sequenciais Ordenadas");
    printf("\n------------------------------------------------\n");
    printf("Digite uma opção:\n");
    printf("(1) Incluir aluno\n(2) Remover aluno\n(3) Pesquisar aluno\n(4) Listar todos os alunos\n(5) Sair\n");
}

void incluirAluno_arq(tAluno aluno, tListAlunos* lista, FILE* fp, char* path){
    printf("Incluindo um aluno no arquivo:");
    printf("\n------------------------------\n");
    printf("Digite o numero de matricula: ");
    scanf("%s",aluno.numMatricula);
    getchar();
    printf("Digite o nome do aluno: "); 
    fgets(aluno.nome, 100, stdin);
    printf("Digite o email do aluno: ");
    scanf("%s",aluno.email);
    if(incOrdenada(aluno, lista)){
      atualizar_arq(fp, lista, path);
      printf("\nAdicionado com sucesso!!\n");
    }else
      printf("\nNão foi possivel adicionar ao arquivo!\n"); 
}

void removerAluno_arq(tAluno aluno, tListAlunos* lista, FILE* fp, char* path){
    printf("Removendo um aluno do arquivo:");
    printf("\n------------------------------\n");
    printf("Digite o numero da matricula do aluno que deseja remover: ");
    scanf("%s", aluno.numMatricula);
    if(remOrdenada(aluno,lista)){
      atualizar_arq(fp, lista, path);
      printf("\nRemovido com sucesso!!\n");
    }else
      printf("\nNão foi possivel fazer a remoção\n");
}

void buscarAluno(tAluno aluno, tListAlunos* lista){
	printf("Procurando um aluno no arquivo:"); 
  printf("\n------------------------------\n");
  printf("Digite o numero da matricula para pesquisar: ");
  scanf("%s", aluno.numMatricula);
  int achou;
  int index = buscaOrdenada(lista, aluno.numMatricula, &achou);
  if(achou){
    printf("\nElemento encontrado com índice %d\n", index);
  }else
      printf("\nElemento não se encontra na lista!!\n");
}

void listarAlunos(tListAlunos* lista){
  if(strlen(lista->lista[0].numMatricula) =='\0')
    printf("Lista vazia!\n");
  else{
    printf("Arquivo:\n");
    printLisAluno(lista->lista, lista->tam);
    printf("Tamanho = %d\n", lista->tam);
  }
}