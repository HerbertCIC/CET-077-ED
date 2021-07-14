
#include <stdio.h>
#include <stdlib.h>
#include "include/arvCabecalhos.h"
//#include "arvfunc.c"

PONTARV novoNoDaArv(tAluno aluno);
PONTARV incNoNaArv(PONTARV raiz, PONTARV no);
void printArv(PONTARV raiz);
PONTARV buscaNaArv(PONTARV raiz, char chave[]);
PONTARV treeMin(PONTARV raiz);
PONTARV remNoNaArv(PONTARV raiz, PONTARV no);

int iniPilhaNoArv(tPilhaNoArv *pilha, int cap);
int incPilhaNoArv(PONTARV no, tPilhaNoArv *pilha);
int remPilhaNoArv(PONTARV no, tPilhaNoArv *pilha);



PONTARV buscaNaArv(PONTARV raiz, char chave[])
{
  PONTARV aux = raiz;
  if(chave != NULL){
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
  }   
  return NULL; //Não achou retorna NULL ou chave é null
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



PONTARV removeNoAtual(PONTARV atual){
  PONTARV no1, no2;
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
  printf("\n\n%s", no1->aluno.numMatricula);
  printf("\n\n%s", no2->aluno.numMatricula);

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
  //PONTARV aux = raiz;
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
          return raiz;
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








int main(){
    PONTARV raiz = NULL;
    tAluno aluno;
    PONTARV novo;

    strcpy(aluno.numMatricula, "201910281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno); 
    raiz = incNoNaArv(raiz, novo);

    strcpy(aluno.numMatricula, "202210281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno); 
    raiz = incNoNaArv(raiz, novo);

    strcpy(aluno.numMatricula, "201610281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno); 
    raiz = incNoNaArv(raiz, novo);

    strcpy(aluno.numMatricula, "201410281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno); 
    raiz = incNoNaArv(raiz, novo);

    strcpy(aluno.numMatricula, "201810281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno); 
    raiz = incNoNaArv(raiz, novo);

    strcpy(aluno.numMatricula, "202010281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno); 
    raiz = incNoNaArv(raiz, novo);

    strcpy(aluno.numMatricula, "202410281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno); 
    raiz = incNoNaArv(raiz, novo);


    /*strcpy(aluno.numMatricula, "202210281");
    strcpy(aluno.nome, "Fulano conceicao");
    strcpy(aluno.email, "fulano@uesc.br");
    novo = novoNoDaArv(aluno);
    incNoNaArv(raiz, novo);*/

    printf("\n%s\n", raiz->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->dir->aluno.numMatricula);

    char matricula[] = "201910281";
    // char matricula[] = "201610281";
    // char matricula[] = "201410281";
    // char matricul[] = "201910281";
    // char matricul[] = "202210281";
    // char matricula[] = "202010281";
    // char matricula[] = "202410281";
 
    printf("\nTESTANDO BUSCA NA ARVORE\n");
    printf("\n\nProcurando um aluno com numero de matricula: %s na arvore: ", matricula);
    PONTARV busca = buscaNaArv(raiz, matricula);

    printf("\nResultado da busca: %s", busca->aluno.numMatricula);

    printf("\n\nProcurando um aluno que não está na arvore:");
    PONTARV busca2 = buscaNaArv(raiz, "0000000000");

    printf("\nResultado da busca: %s", busca2->aluno.numMatricula);




    printf("\n\nTESTANDO REMOÇÃO NA ARVORE\n");

    raiz = removeNoDaArv(raiz, raiz->dir->dir);
    PONTARV busca3 = buscaNaArv(raiz, raiz->dir->dir->aluno.numMatricula);

    printf("\n\nNovo valor do nó: %s", busca3->aluno.numMatricula);

    printf("\nArvore - pre-ordem:");
    printf("\n%s\n", raiz->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->dir->aluno.numMatricula);


    //aqui entra no removeatual depois do if
    raiz = removeNoDaArv(raiz, raiz->esq);   
    PONTARV busca4 = buscaNaArv(raiz, raiz->esq->aluno.numMatricula);

    printf("\n\nNovo valor do nó: %s", busca4->aluno.numMatricula);

    printf("\nArvore - pre-ordem:");
    printf("\n%s\n", raiz->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->dir->aluno.numMatricula);


    raiz = removeNoDaArv(raiz, raiz);   
    PONTARV busca5 = buscaNaArv(raiz, raiz->aluno.numMatricula);

    printf("\n\nNovo valor do nó: %s", busca5->aluno.numMatricula);
    
    printf("\nArvore - pre-ordem:");
    printf("\n%s\n", raiz->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->esq->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->esq->aluno.numMatricula);
    printf("\n%s\n", raiz->dir->dir->aluno.numMatricula);

    //printArv(raiz);




  return 0;
}







