#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "include/ferramentas.h"

#define LSIZE 20
#define PSIZE 20
#define FSIZE 20

int main(void){
  tPilhaAlunos pilha;
  iniPilhaAlunos(&pilha, PSIZE);
  tFilaAlunos fila;
  iniFilaAlunos(&fila, FSIZE);
  tListAlunos lista;
	iniListAlunos(&lista, LSIZE);
	geraAlunos(&lista);
  printLisAluno(lista.lista, lista.tam);

  printf("\n-----Teste PILHAS-----\n");
  for(int i=0; i<= LSIZE; i++){
    if(incPilhaAlunos(lista.lista[i], &pilha))
      printf("Elemento incluido no indice [%d]\n", pilha.topo-1);
    else{
      printf("Pilha cheia!\n"); 
      break;
    }   
  }
  printf("\n");

  for(int i=0; i<= LSIZE; i++){
    tAluno aluno;
    if(remPilhaAlunos(&aluno, &pilha))
      printf("Elemento removido no indice [%d]\n", pilha.topo);
    else{
      printf("Pilha vazia!\n"); 
      break;
    }
    //printAluno(aluno);   
  }

  printf("\n-----Teste FILAS-----\n");
  for(int i=0; i<= LSIZE; i++){
    if(incFilaAlunos(lista.lista[i], &fila)){
      if(fila.fim < fila.cap)
        printf("Elemento incluido no indice [%d]\n", fila.fim-1);
      else
        printf("Elemento incluido no indice [%d]\n", (fila.fim-1)%fila.cap);      
    }else{
        printf("Lista cheia!\n");
        break;
    }       
  }
  printf("\n");

  for(int i=0; i< LSIZE/2; i++){
    tAluno aluno;
    if(remFilaAlunos(&aluno, &fila)){
      if(fila.ini < fila.cap)
        printf("Elemento removido no indice [%d]\n", fila.ini-1);
      else
        printf("Elemento removido no indice [%d]\n", (fila.ini-1)%fila.cap);      
    }else{
        printf("Lista vazia!\n");
        break;
    }       
    //printAluno(aluno);   
  }
  printf("\n");

  for(int i=0; i< LSIZE; i++){
    if(incFilaAlunos(lista.lista[i], &fila)){
      if(fila.fim < fila.cap)
        printf("Elemento incluido no indice [%d]\n", fila.fim-1);
      else
        printf("Elemento incluido no indice [%d]\n", (fila.fim-1)%fila.cap);      
    }else{
        printf("Lista cheia!\n");
        break;
    }       
  }
  printf("\n");

  return 0;
}