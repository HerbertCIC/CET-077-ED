
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "include/ferramentas.h"


typedef struct
{
	char numMatricula[10]; //chave com 9 caracteres
	char nome[100];		   // nome com até 99 caracteres
	char email[100];	   // eMail com até 99 caracteres
} tAluno;

struct arvAluno
{
	tAluno aluno;
	struct arvAluno *dir;
	struct arvAluno *esq;
};

typedef struct arvAluno NOARV;
typedef NOARV *PONTARV;


PONTARV novoNoDaArv(tAluno aluno);
PONTARV incNoNaArv(PONTARV raiz, PONTARV no);
void printAlunosNaArv(PONTARV raiz, int ordem);
PONTARV buscaAlunoNaArv(PONTARV raiz, char chave[]);
PONTARV treeMin(PONTARV raiz);
PONTARV removeNoArv(PONTARV raiz, char chave[10]);

int main()
{
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
    
    printAlunosNaArv(raiz, 0);

    printf("\nRemovendo um aluno da lista\n");
    raiz = removeNoArv(raiz, "202410281");
    printAlunosNaArv(raiz, 0);
    //202010281 n confere
    //201910281 confere



    printf("\nBuscando por um aluno removido da lista\n");
    novo = buscaAlunoNaArv(raiz, "202410281");
    if(novo != NULL){
      printf("Número de Matricula: %s, ", novo->aluno.numMatricula);
      printf("Nome: %s, ", novo->aluno.nome);
      printf("Email: %s,\n", novo->aluno.email);
    }else{
      printf("Não achei aluno na Lista\n");
    }
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
    if (raiz == NULL)
        return no;
    int comp = strcmp(raiz->aluno.numMatricula, no->aluno.numMatricula);
    if (comp > 0)
      raiz->esq = incNoNaArv(raiz->esq, no);
    else
      raiz->dir = incNoNaArv(raiz->dir, no);
    return raiz;
}

void printAlunosNaArv(PONTARV raiz, int ordem)
{
    if (raiz == NULL)
    {
        printf("[]\n");
    }
    else
    {
        switch (ordem)
        {
        case 0: //pré-ordem
            printf("[ Numero de Matricula: %s, ", raiz->aluno.numMatricula);
            printf("Nome: %s, ", raiz->aluno.nome);
            printf("Email: %s],\n", raiz->aluno.email);
            printAlunosNaArv(raiz->esq, 0);
            printAlunosNaArv(raiz->dir, 0);
            break;
        case 1: //ordem
            printAlunosNaArv(raiz->esq, 1);
            printf("[ Numero de Matricula: %s, ", raiz->aluno.numMatricula);
            printf("Nome: %s, ", raiz->aluno.nome);
            printf("Email: %s],\n", raiz->aluno.email);
            printAlunosNaArv(raiz->dir, 1);
            break;
        case 2: //pós-ordem
            printAlunosNaArv(raiz->esq, 2);
            printf("[ Numero de Matricula: %s, ", raiz->aluno.numMatricula);
            printf("Nome: %s, ", raiz->aluno.nome);
            printf("Email: %s],\n", raiz->aluno.email);
            printAlunosNaArv(raiz->dir, 2);
            break;
        default:
            break;
        }
    }
}


PONTARV buscaAlunoNaArv(PONTARV raiz, char chave[]){
  if(raiz == NULL)
    return NULL;
  int cmp = strcmp(raiz->aluno.numMatricula, chave);
  if(cmp > 0)
    return buscaAlunoNaArv(raiz->esq, chave);
  else{
    if(cmp == 0)
        return raiz;
    else
        return buscaAlunoNaArv(raiz->dir, chave);
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


PONTARV removeNoArv(PONTARV raiz, char chave[10])
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else
    {
        int comp = strcmp(raiz->aluno.numMatricula, chave);
        if (comp > 0)
        {
            raiz->dir = removeNoArv(raiz->dir, chave);
        }
        else if (comp < 0)
        {
            raiz->esq = removeNoArv(raiz->esq, chave);
        }
        else //encontrou o elemento a ser removido
        {
            if (raiz->esq == NULL && raiz->dir == NULL)
            {
                free(raiz);
                return NULL;
            }
            else if (raiz->esq == NULL)
            {
                PONTARV aux = raiz->dir;
                free(raiz);
                return aux;
            }
            else if (raiz->dir == NULL)
            {
                PONTARV aux = raiz->esq;
                free(raiz);
                return aux;
            }
            else
            {
                // PONTARV aux1 = treeMin(raiz->dir);
                // PONTARV aux2 = raiz->dir;
                // PONTARV aux3 = raiz->esq;
                // free(raiz);
                // aux1->esq = aux3;
                // return aux2;

                PONTARV aux = treeMin(raiz->dir);//Encontra o elemento minimo subarvore direita
                tAluno alunoAux = aux->aluno;//copia a informação do nó retornado
                raiz = removeNoArv(raiz, alunoAux.numMatricula); //remove o nó retornado
                raiz->aluno = alunoAux;//substitui o valor de aluno raiz
                    
            }            
        }
        return raiz;   
    }
}