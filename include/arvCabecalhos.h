
#include <string.h>
#define TRUE 1;
#define FALSE 0;

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

typedef struct
{
	PONTARV pilha;
	int cap;	//pilha vazia quando topo = 0
	int topo;	//pilha cheia quando topo = cap
} tPilhaNoArv; //last in first out - lifo
// topo = 0
int iniPilhaNoArv(tPilhaNoArv *pilha, int cap);
int incPilhaNoArv(PONTARV no, tPilhaNoArv *pilha);
int remPilhaNoArv(PONTARV no, tPilhaNoArv *pilha);


PONTARV novoNoDaArv(tAluno aluno);
PONTARV incNoNaArv(PONTARV raiz, PONTARV no);
void printArv(PONTARV raiz);
PONTARV buscaNaArv(PONTARV raiz, char chave[]);
PONTARV treeMin(PONTARV raiz);
PONTARV remNoNaArv(PONTARV raiz, PONTARV no);