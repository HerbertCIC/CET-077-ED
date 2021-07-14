#include <stdio.h>
#include <stdlib.h>
#include "include/arvCabecalhos.h"

PONTARV buscaNaArv(PONTARV raiz, char chave[])
{
  PONTARV aux = raiz;
    while (aux != NULL)
    {
        int comp = strcmp(aux->aluno.numMatricula, chave);
        if (comp == 0)
            return aux;
        else
        {
            if (comp > 0)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
    }
    return NULL; //Não achou retorna NULL
}

PONTARV novoNoDaArv(tAluno aluno)
{
    PONTARV novo = (PONTARV)malloc(sizeof(NOARV)); //Criando um novo no
    strcpy(novo->aluno.numMatricula, aluno.numMatricula);
    strcpy(novo->aluno.nome, aluno.nome); //copia aluno para o novo no
    strcpy(novo->aluno.email, aluno.email);
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

/*PONTARV incNoNaArv(PONTARV raiz, PONTARV no)
{
    if (raiz == NULL)
        return no;
    else
    {
        PONTARV aux = raiz; //guarda a raiz original
        while (aux != NULL)
        { //busca a posicão que deve-se inserir
            int comp = strcmp(aux->aluno.numMatricula, no->aluno.numMatricula);
            if (comp < 0)
                aux = aux->dir;
            else
                aux = aux->esq;
        }
        aux = no;  //atribui o nó a posição encontrada
        return raiz; //retorna nó original
    }
}*/

PONTARV incNoNaArv(PONTARV raiz, PONTARV no)
{
  PONTARV aux = raiz;
    if (raiz == NULL){
      //printf("\nEntrei");
         return no;
    }       
    else
    {
      //printf("\nEntrei 2");
      PONTARV atual = raiz;
      PONTARV ant = NULL;
        while (atual != NULL)
        { //busca a posicão que deve-se inserir
            //printf("\natual != null");
            ant = atual;
            int comp = strcmp(atual->aluno.numMatricula, no->aluno.numMatricula);
            if (comp < 0){
                //printf("\nentrei no ramo da direita");
                atual = atual->dir;         
            }
            else if(comp > 0){
              //printf("\nentrei no ramo da esquerda"); 
              atual = atual->esq;
            }
            else
              return 0;                
        }
        int comp = strcmp(ant->aluno.numMatricula, no->aluno.numMatricula);
        if(comp < 0)
          ant->dir = no;
        else
          ant->esq = no;
    }
    return aux;
}

//printa a arvore em ordem
//precisa implementar as funções de pilha para PONTARV
void printArv(PONTARV raiz)
{
    tPilhaNoArv *pilha;
    iniPilhaNoArv(pilha, 100);

    PONTARV aux = raiz;

    while (aux != NULL || pilha->topo != 0)
    {
        if (aux != NULL)
        {
            incPilhaNoArv(aux, pilha);
            aux = aux->esq;
        }
        else
        {
            PONTARV auxPrint;
            remPilhaNoArv(auxPrint, pilha);
            printf("[ Numero de Matricula: %s, ", auxPrint->aluno.numMatricula);
            printf("Nome: %s, ", aux->aluno.nome);
            printf("Email: %s],\n", aux->aluno.email);
            aux = aux->dir;
        }
    }
}

PONTARV treeMin(PONTARV raiz)
{
    if (raiz != NULL)
    {
        PONTARV aux = raiz;
        while (aux->esq != NULL)
        {
            aux = aux->esq;
        }
        return aux;
    }
    return NULL;
}

/*
PONTARV remNoNaArv(PONTARV raiz, PONTARV no)
{
    int comp = strcmp(raiz->aluno.numMatricula, no->aluno.numMatricula);
    if (raiz == NULL)
    {
        return NULL;
    }
    else if (comp == 0)
    {
        free(raiz);
        return NULL;
    }
    else
    {
        //Inicia pilha para guardar valores da arvore
        tPilhaNoArv pilha;
        iniPilhaNoArv(&pilha, 100);

        PONTARV aux = raiz;   //variavel para manipular valores da raiz
        PONTARV retornoPilha; //varivavel para guardar o no removido do topo da pilha
        retornoPilha = (PONTARV) malloc(sizeof(PONTARV)*1);

      while (aux != NULL)
      {

        if(incPilhaNoArv(aux, &pilha)){
                  int comp = strcmp(raiz->aluno.numMatricula, no->aluno.numMatricula);
                  if (comp == 0)
                  {
                      //Caso folha
                      if (aux->esq == NULL && aux->dir == NULL)
                      {
                          if(remPilhaNoArv(retornoPilha, &pilha)){
                            if(remPilhaNoArv(retornoPilha, &pilha)){
                              free(aux);                          //libera o nó folha
                              retornoPilha->dir = NULL;
                              retornoPilha->esq = NULL;
                              return raiz;
                            }else
                              printf("Erro remoção na pilha");
                          }else
                            printf("Erro remoção na pilha");
                          //remove topo
                          //remove topo2 Obs. retornoPilha agr guarda o nó antecessor ao nó aux
                          
                      }
                      //Caso 1 ramo a direita
                      else if (aux->esq == NULL)
                      {
                          if(remPilhaNoArv(retornoPilha, &pilha)){
                            if(remPilhaNoArv(retornoPilha, &pilha)){
                              PONTARV guardaNodir = aux->dir;
                              free(aux);
                              retornoPilha = guardaNodir;
                              return raiz;
                            }else
                              printf("Erro remocao na pilha");                          
                          }else
                              printf("Erro remocao na pilha"); 
                      }
                      //Caso 1 ramo a esquerda
                      else if (aux->dir == NULL)
                      {
                          if(remPilhaNoArv(retornoPilha, &pilha)){
                            if(remPilhaNoArv(retornoPilha, &pilha)){
                              PONTARV guardaNoesq = aux->esq;
                              free(aux);
                              retornoPilha = guardaNoesq;
                              return raiz;
                            }
                            else
                              printf("Erro remocao pilha");
                          }else
                            printf("Erro remocao pilha");                        
                      }
                      else
                      {
                          PONTARV noMin = treeMin(aux->dir); //guarda menor nó mais a esqueda da sub-arvore a direita
                          PONTARV guardaNodir = aux->dir;
                          PONTARV guardaNoesq = aux->esq;
                          if( remPilhaNoArv(retornoPilha, &pilha)){
                            if(remPilhaNoArv(retornoPilha, &pilha)){                            
                              free(aux);
                              retornoPilha = noMin;
                              retornoPilha->dir = guardaNodir;
                              retornoPilha->esq = guardaNoesq;
                              return raiz;
                            }else
                              printf("Erro remocao na pilha");
                          }else
                              printf("Erro remocao na pilha");
                        
                      }
                  }
                  else if (comp > 0)
                  {
                      raiz = raiz->esq;
                  }
                  else
                      aux = aux->dir;

          }else
            printf("Erro de inclusao na pilha");
        }
      return raiz;
    }
}*/

PONTARV removeNoAtual(PONTARV atual){
  PONTARV no1,no2;
  /*Este caso serve tanto para um nós com apenas 1 ramo ou folhas*/
  if(atual->esq == NULL){//sem ramo a esquerda
    no2 = atual->dir;//aponta para a subarvore da direita
    free(atual);//libera no atual
    return no2;//retorna no da direita
  }
  //procura o no mais a direita na subarvore esquerda 
  no1 = atual;
  no2 = atual->esq;
  while(no2->dir != NULL){
    no1 = no2;
    no2 = no2->dir;
  }

  //copia o ramo mais a direita na sub-arvore esquerda para o lugar do no removido
  if(no1 != atual){
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }
  no2->dir= atual->dir;
  free(atual);
  return no2;
}

PONTARV removeNoDaArv(PONTARV raiz, PONTARV no){
  PONTARV aux = raiz;
  if(raiz==NULL)
    return NULL;  
  else{
    PONTARV atual = raiz;
    PONTARV ant = NULL;    
    while(atual != NULL){
       int comp = strcmp(atual->aluno.numMatricula, no->aluno.numMatricula);
       //achou o nó a ser removido
       if(comp==0){
         if(atual == raiz)
            raiz = removeNoAtual(atual);
          else{//retorna o novo nó onde o ant vai apontar
            if(ant->dir == atual)
              ant->dir = removeNoAtual(atual);
            else
              ant->esq = removeNoAtual(atual);
          }
          return aux;
       }
       //percorrendo a arvore procurando o nó que será removido
       ant = atual;
       comp = strcmp(atual->aluno.numMatricula, no->aluno.numMatricula);
       if(comp < 0)
        atual = atual->dir;
       else
        atual = atual->esq;
    }
  }
}

int iniPilhaNoArv(tPilhaNoArv *pilha, int cap)
{
    pilha->cap = cap;
    pilha->topo = 0;
    pilha->pilha = (PONTARV)malloc(sizeof(PONTARV) * cap);
    return 0;
}

int incPilhaNoArv(PONTARV no, tPilhaNoArv *pilha)
{
    if (pilha->topo < pilha->cap)
    {
        // strcpy(pilha->pilha[pilha->topo].aluno.numMatricula, no->aluno.numMatricula);
        // strcpy(pilha->pilha[pilha->topo].aluno.nome, no->aluno.nome);
        // strcpy(pilha->pilha[pilha->topo].aluno.email, no->aluno.email);
        pilha->pilha = no;
        pilha->topo++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int remPilhaNoArv(PONTARV no, tPilhaNoArv *pilha)
{
    if (pilha->topo > 0)
    {
        pilha->topo--;
        no = pilha->pilha;
        // strcpy(no->aluno.numMatricula, pilha->pilha[pilha->topo].aluno.numMatricula);
        // strcpy(no->aluno.nome, pilha->pilha[pilha->topo].aluno.nome);
        // strcpy(no->aluno.email, pilha->pilha[pilha->topo].aluno.email);
        return 1;
    }
    else
    {
        return 0;
    }
}



