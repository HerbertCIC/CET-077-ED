
#include <stdio.h>
#include <stdlib.h>
#include "include/ferramentas.h"

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo tAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1; 
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
saída:
- A função retorna o índice da lista que possui a chave procurada.
	Caso a chave não pertença a nenhum dos elementos da lista a 
	função retorna n;
*/
int buscaLisAluno(tAluno lista[], int n, char chave[10])
{
  int i = 0;
  while(i < n){
    if(strcmp(lista[i].numMatricula, chave) == 0)
      return i;
    i++;
  }
  return n; //não achou, retorna n 
}

/* 
Implementação ecursiva da função:

int buscaLisAluno(tAluno lista[], int n, char chave[10])
*/
int buscaLisAlunoRec(tAluno lista[], int n, char chave[])
{
	if (n == 0){
		return 0;
	}else{
		if (!strcmp(lista[0].numMatricula, chave)){
			return 0;
		}else{
			return 1 + buscaLisAlunoRec(&lista[1], n - 1, chave);
		}
	}
}

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo tAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1. Para melhorar o algoritmo se adiciona a 
	chave procurada ao elemento da posição n, que não pertence
	à lista. Se pressupõe que a lista tem capacidade para
	armazenar informação na posição de índice n;
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
saída:
- A função retorna o índice da lista que possui a chave procurada.
	Caso a chave não pertença a nenhum dos elementos da lista a 
	função retorna n;
*/
int buscaLisAluno2(tAluno lista[], int n, char chave[])
{
  int i = 0;
	strcpy(lista[n].numMatricula, chave); // adicionando cave no final
  while(strcmp(lista[i].numMatricula, chave) != 0){
    i++;
  }
  return i;
} //O(n)

/* 
Implementação ecursiva da função:

int buscaLisAluno2(tAluno lista[], int n, char chave[10])
Para o funcionamento correto desta implementação, a inserção
da chave procurada na posição de índice n deve ser feita
antes da chamada à função;
*/
int buscaLisAlunoRec2(tAluno lista[], int n, char chave[])
{
	if (!strcmp(lista[0].numMatricula, chave)){
		return 0;
	}else{
		return 1 + buscaLisAlunoRec(&lista[1], n - 1, chave);
	}
}

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo tAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática, na qual elementos
foram inseridos de forma ordenada, em ordem crescente, de 
acordo com o campo chave numMatricula). 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1. Para melhorar o algoritmo se adiciona a 
	chave procurada ao elemento da posição n, que não pertence
	à lista. Se pressupõe que a lista tem capacidade para
	armazenar informação na posição de índice n; 
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
- achou: Referência para retornar um boolean que relata o 
	sucesso da busca;
saída:
- A função retorna um índice da lista e um resultado boolean
	que significa:
	* se achou for TRUE o índice retornado indica o posição da 
	lista onde se encontra o elemento que possui a chave procurada.
	* se achou for FALSE o índice retornado indica o posição da 
	lista onde um elemento com essa chave deveria ser inserido na
	lista, de acordo com a ordem crescente estabelecida;
*/
int buscaLisAlunoOrd(tAluno lista[], int n, char chave[], int* achou)
{
  int i = 0;
	*achou = FALSE;
	strcpy(lista[n].numMatricula, chave); // adicionando cave no final
  while(strcmp(lista[i].numMatricula, chave) < 0){
    i++;
  }
	if((strcmp(lista[i].numMatricula, chave) == 0) && (i < n))
		*achou = TRUE;
  return i;
} // O(n)

/* 
Implementação ecursiva da função:

int buscaLisAlunoOrd(tAluno lista[], int n, char chave[], int* achou)
Para o funcionamento correto desta implementação, a inserção
da chave procurada na posição de índice n deve ser feita
antes da chamada à função e a varável referenciada por achou deve 
ser inicializada com valor FALSE;
*/
int buscaLisAlunoOrdRec(tAluno lista[], int n, char chave[], int* achou)
{
	if((!strcmp(lista[0].numMatricula, chave)) && (n > 0))
		*achou = TRUE;
	if (strcmp(lista[0].numMatricula, chave) < 0){
    return 1 + buscaLisAlunoOrdRec(&lista[1], n - 1, chave, achou);
	}
	else
		return 0;
}

/*
Implementa a busca binaria numa lista linear de alocação
sequencial do tipo tAluno. Nesta função se trabalha com uma 
lista definida como um array de forma estática, na qual elementos
foram inseridos de forma ordenada, em ordem crescente, de 
acordo com o campo chave numMatricula). 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
- n: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até n-1.
- chave: Número de matrícula do aluno que está sendo procurado. 
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
- achou: Referência para retornar um boolean que relata o 
	sucesso da busca;
saída:
- A função retorna um índice da lista e um resultado boolean
	que significa:
	* se achou for TRUE o índice retornado indica o posição da 
	lista onde se encontra o elemento que possui a chave procurada.
	* se achou for FALSE o índice retornado indica o posição da 
	lista onde um elemento com essa chave deveria ser inserido na
	lista, de acordo com a ordem crescente estabelecida;
*/
int buscaLisAlunoBin(tAluno lista[], int n, char chave[], int* achou)
{
	int min = 0;			
	int max = n;			
	int i;
	*achou = FALSE;
	while (min != max){
		i = (max + min)/2; 
		int com = strcmp(lista[i].numMatricula, chave); 
		if ( com < 0){
			min = ++i; 
		}else{ 
			if (com > 0){
				max = i; 
			}else{
				if (i < n) 
					*achou = TRUE;
				return i;
			}
		} 
	}
	return i;
} //O(log_2(n))

/* 
Implementação ecursiva da função:

int buscaLisAlunoBin(tAluno lista[], int n, char chave[], int* achou)
*/
int buscaLisAlunoBinRec(tAluno lista[], int n, char chave[], int* achou)
{
	if (n == 0){
		*achou = FALSE;
		return 0;
	}else{
		int i = n/2;
		int com = strcmp(lista[i].numMatricula, chave);
		if ( com < 0){
			return i + buscaLisAlunoBinRec(&lista[i], n-(n/2), chave, achou);
		}else{
			if (com > 0){
				return buscaLisAlunoBinRec(lista, n/2, chave, achou);
			}else{
				*achou = TRUE;
				return i;
			}
		}
	}
}

void incLisAluno(tAluno aluno, tAluno lista[], int n)
{
	if(buscaLisAluno2(lista, n, aluno.numMatricula) == n){//lista[0], 0, aluno.numMatricula
		strcpy(lista[n].numMatricula, aluno.numMatricula);
		strcpy(lista[n].nome, aluno.nome);
		strcpy(lista[n].email,aluno.email);
	}
}

int incLisAlunoOrd(tAluno aluno, tAluno lista[], int n)
{
	int achou;
	//int i = buscaLisAlunoOrd(lista, n, aluno.numMatricula, &achou);
	//achou = FALSE;
	//strcpy(lista[n].numMatricula, aluno.numMatricula);
	//int i = buscaLisAlunoOrdRec(lista, n, aluno.numMatricula, &achou);
  
	int i = buscaLisAlunoBin(lista, n, aluno.numMatricula, &achou);
	if (i == n){
		strcpy(lista[n].numMatricula, aluno.numMatricula);
		strcpy(lista[n].nome, aluno.nome);
		strcpy(lista[n].email,aluno.email);
		return 0;
	}else if (!achou){
		tAluno troca;
		for(int j = i; j < n; j++){
			strcpy(troca.numMatricula, lista[j].numMatricula);
			strcpy(troca.nome, lista[j].nome);
			strcpy(troca.email, lista[j].email);
			
			strcpy(lista[j].numMatricula, aluno.numMatricula);
			strcpy(lista[j].nome, aluno.nome);
			strcpy(lista[j].email, aluno.email);

			strcpy(aluno.numMatricula, troca.numMatricula);
			strcpy(aluno.nome, troca.nome);
			strcpy(aluno.email, troca.email);
		}
		strcpy(lista[n].numMatricula, aluno.numMatricula);
		strcpy(lista[n].nome, aluno.nome);
		strcpy(lista[n].email, aluno.email);
		return 0;
	}
	return 1; // Já tem um elemento com essa chave na lista;
}

void printLisAluno(tAluno lista[], int n)
{
	printf("[ \n ");
	for(int i = 0; i < n; i++){
		printf("%s, ", lista[i].numMatricula);
		printf("%s, ", lista[i].nome);
		printf("%s;\n ", lista[i].email);
	}
	printf(" ]\n");
}

void printItemLisAluno(tAluno lista[], int n)
{
	printf("[ \n");
	printf("%s, ", lista[n].numMatricula);
	printf("%s, ", lista[n].nome);
	printf("%s;\n ", lista[n].email);
	printf(" ]\n");
}   

void iniListAlunos(tListAlunos* list, int cap)
{
	list->cap = cap;
	list->tam = 0;
	list->lista = (tAluno*) malloc((cap+1)*sizeof(tAluno));
}
// ---------------------------------MINHAS MODIFICAÇÕES------------------------------

int buscaNaoOrdenada(tListAlunos* list, char chave[]){
  int i = 0;
  int n = list->tam;
	strcpy(list->lista[n].numMatricula, chave); // adicionando chave no final
  while(strcmp(list->lista[i].numMatricula, chave) != 0){
    i++;
  }
  return i; //retorna o indice onde achou
}


int incNaoOrdenada(tAluno aluno, tListAlunos* list){	
	// Retorna TRUE ou FALSE
	// FALSE: Se o aluno já estiver na lista ou se a 
	// lista já estiver cheia
    int n = list->tam;
  	if(buscaNaoOrdenada(list, aluno.numMatricula) == n && n < list->cap){
      strcpy(list->lista[n].numMatricula, aluno.numMatricula);
		  strcpy(list->lista[n].nome, aluno.nome);
		  strcpy(list->lista[n].email, aluno.email);
      list->tam ++;
      return TRUE;
	  }else
      return FALSE;
}

int remNaoOrdenada(tAluno aluno, tListAlunos* list){
	// Retorna TRUE ou FALSE
	// FALSE: Se o aluno não estiver na lista ou se a 
	// lista já estiver vazia
  int n = list->tam;
  if(buscaNaoOrdenada(list, aluno.numMatricula) == n || n == 0){
    return FALSE;
  }else{
    int i = buscaNaoOrdenada(list, aluno.numMatricula);
		for(int j = i; j < n; j++){
			strcpy(list->lista[j].numMatricula, list->lista[j+1].numMatricula);
			strcpy(list->lista[j].nome, list->lista[j+1].nome);
			strcpy(list->lista[j].email, list->lista[j+1].email);
    }
    list->tam--;
    return TRUE;
  }
}

int buscaOrdenada(tListAlunos* list, char chave[], int* achou){
	//retorna o indice onde achou 
  int i = 0;
  int n = list->tam;
	*achou = FALSE;  
	strcpy(list->lista[n].numMatricula, chave); // adicionando chave no final
  while(strcmp(list->lista[i].numMatricula, chave) < 0){
    i++;
  }
	if((strcmp(list->lista[i].numMatricula, chave) == 0) && (i < n))
		*achou = TRUE;
  return i;
}

int incOrdenada(tAluno aluno, tListAlunos* list){
	
	// Retorna TRUE ou FALSE
	// FALSE: Se o aluno já estiver na lista ou se a 
	// lista já estiver cheia
  int achou;
  int n = list->tam;
	int i = buscaOrdenada(list, aluno.numMatricula, &achou);
  printf("\ni = %d\n", i);
  printf("\nn = %d\n", n);
	if (i == n && n <= list->cap){
		strcpy(list->lista[n].numMatricula, aluno.numMatricula);
		strcpy(list->lista[n].nome, aluno.nome);
		strcpy(list->lista[n].email,aluno.email);
    list->tam ++;
		return TRUE;
	}else if (!achou && n+1 <= list->cap){
		tAluno troca;   
		for(int j = i; j < n; j++){
			strcpy(troca.numMatricula, list->lista[j].numMatricula);
			strcpy(troca.nome, list->lista[j].nome);
			strcpy(troca.email, list->lista[j].email);
			
			strcpy(list->lista[j].numMatricula, aluno.numMatricula);
			strcpy(list->lista[j].nome, aluno.nome);
			strcpy(list->lista[j].email, aluno.email);

			strcpy(aluno.numMatricula, troca.numMatricula);
			strcpy(aluno.nome, troca.nome);
			strcpy(aluno.email, troca.email);
		}
		strcpy(list->lista[n].numMatricula, aluno.numMatricula);
		strcpy(list->lista[n].nome, aluno.nome);
		strcpy(list->lista[n].email, aluno.email);
    list->tam ++;      
		return TRUE;
	}
	return FALSE; // Já tem um elemento com essa chave na lista ou a lista está cheia;
}

int remOrdenada(tAluno aluno, tListAlunos* list){

	// Retorna TRUE ou FALSE
	// FALSE: Se o aluno não estiver na lista ou se a 
	// lista já estiver vazia
  int achou;
  int n = list->tam;
  int i = buscaOrdenada(list, aluno.numMatricula, &achou);
  if(!achou || list->tam == 0){
    return FALSE;
  }else{
		for(int j = i; j < n; j++){
			strcpy(list->lista[j].numMatricula, list->lista[j+1].numMatricula);
			strcpy(list->lista[j].nome, list->lista[j+1].nome);
			strcpy(list->lista[j].email, list->lista[j+1].email);
    }
    list->tam--;
    return TRUE;
  }
}

void atualizar_arq(FILE* fp, tListAlunos* lista, char* nome){
  if((fp=fopen(nome,"w"))==NULL){
    printf("Erro de abertura de arquivo!");
    exit(-1);
  }
  int i=0;
  for(; i < lista->tam; i++){
    fprintf(fp,"%s\n", lista->lista[i].numMatricula);
    fprintf(fp,"%s", lista->lista[i].nome);
    fprintf(fp,"%s\n", lista->lista[i].email);
  }
  fclose(fp);
}
 
void mergeSort(tAluno* alunos, int inicio, int fim){
  int meio;
  if(inicio<fim){
    meio = (inicio+fim)/2;
    mergeSort(alunos, inicio, meio);
    mergeSort(alunos, meio+1, fim);
    merge(alunos, inicio, meio, fim);
  }
}

void merge(tAluno* alunos, int inicio, int meio, int fim){
    tAluno *temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (tAluno *) malloc(tamanho*sizeof(tAluno));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(strcmp(alunos[p1].numMatricula, alunos[p2].numMatricula) < 0)
                    temp[i]=alunos[p1++];
                else
                    temp[i]=alunos[p2++];
                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=alunos[p1++];
                else
                    temp[i]=alunos[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            alunos[k] = temp[j];
    }
    free(temp);
}