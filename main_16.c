
#include <stdio.h>
#include <stdlib.h>
#include "include/arvCabecalhos.h"

PONTARV novoNoDaArv(tAluno aluno);
PONTARV incNoNaArv(PONTARV raiz, PONTARV no);
void printArv(PONTARV raiz);
PONTARV buscaNaArv(PONTARV raiz, char chave[]);
PONTARV treeMin(PONTARV raiz);
PONTARV remNoNaArv(PONTARV raiz, PONTARV no);

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
        return aux; //retorna nó original
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

    printf("\n%s\n", raiz->aluno.numMatricula);


  return 0;
}



