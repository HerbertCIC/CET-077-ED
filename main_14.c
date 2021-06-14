#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#include "include/ferramentas.h"

#define LSIZE 10
//#define LSIZE 1000
//#define LSIZE 10000
//#define LSIZE 100000

/*
    Testando inc e rem
*/

int main(void){
        double start, stop; // variaveis para medir tempo
	/*
        Criamos uma lista Linear de Alocação sequencial para
        utilizar como referência e fonte de dados para testar
        as outras listas. Como esta lista vai ser utilizada
        apenas como fonte de dados, os alunos vão ser
        acessados diretamente no arrey pelo seu índice.
        Podemos utilizar uma lista não ordenada
    */
    tListAlunos lista; // declarando a variável
	iniListAlunos(&lista, LSIZE); // inicializando a lista
	geraAlunos(&lista); // Prenche a lista
    if (lista.cap <= 10){
        printf("Lista de referencia inicial\n");
        printLisAluno(lista.lista, lista.tam);
    }
    tListDuplaEncAlunos listaDuplaEncOrd;
    ini_tListDuplaEncAlunos(&listaDuplaEncOrd);

    printf(listaDuplaEncOrd.tail->numMatricula);printf("\n");
    printf(listaDuplaEncOrd.head->prox->numMatricula);printf("\n");

    printf(lista.lista[0].numMatricula);printf("\n");

    int achou;

    printf("Teste algoritmo de busca 1");
    printListaDuplaEncAluno(buscaOrd_tListDuplaEncAlunos(listaDuplaEncOrd, lista.lista[0].numMatricula, &achou));

    printf("\nACHOU = %d\n", achou);

    printf("Teste algoritmo de busca binária");
    printListaDuplaEncAluno(buscaBin_tListDuplaEncAlunos(listaDuplaEncOrd, lista.lista[0].numMatricula, &achou));

    printf("\nACHOU = %d\n", achou);

    if(incOrd_tListDuplaEncAlunos(lista.lista[0], &listaDuplaEncOrd)){
        printf("Conseguiu incluir na Lista duplamente encadeada");
        printListaDuplaEncAluno2(listaDuplaEncOrd);
        //printListaDuplaEncAluno(listaDuplaEncOrd);
    }
    else
        printf("Nao conseguiu incluir na lista encadeada ");







    /*

    printf(" Testando uma Lista Linear duplamente encadeada\n");
    printf("LSIZE = %d\n", LSIZE);

    printf("Testando inclusão de elementos\n");
    //lista.lista[index];
    //buscaOrd_tListDuplaEncAlunos(listaDuplaEncOrd, char chave[10], int* achou);

     /*
        2. Preencher a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível
        avaliar o desempenho considerando os casos em que se
        tenta incluir um elemento que já esxiste na lista.
        Para comparar esta etrutura definir uma semente que
        garanta a mesma sequencia de números aleatórios em
        todos os testes
    *//*
    unsigned int seed = time(NULL); //gerando uma semente para os testes
    srand(seed); // definindo a semente do sequencia rand
	  start = omp_get_wtime(); // Iniciando o cronometro
    int index;
    // equanto a lista não estiver cheia
    int i = 0;
	  while(i<1){
		// gera um índece aleatório nos limites da lista de referencia
      index = rand()%LSIZE;
        // incluindo o elemento index, pode já ter sido incluido
		  if(incOrd_tListDuplaEncAlunos(lista.lista[index], &listaDuplaEncOrd))
          i++;
	}

	stop = omp_get_wtime(); // Para o cronometro
	printf("t_inc = %f\n", stop - start);
    if (lista.cap <= 10){
        printf("Lista duplamente encadeada\n");
        printListaDuplaEncAluno2(listaDuplaEncOrd);
    }
/*

        unsigned int seed = time(NULL); //gerando uma semente para os testes
    srand(seed); // definindo a semente do sequencia rand
    int index;
    int achou = 0;
	int qIn, qOut; // Variáveis para testar se a busca funcionou
	qIn = qOut = 0; // quantos elementos estão ou não na lista
	PONTD aluno;  //Ponteiro para elemento achado
	start = omp_get_wtime(); // Iniciando o cronometro
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
		aluno = buscaOrd_tListDuplaEncAlunos(listaDuplaEncOrd, lista.lista[index].numMatricula, &achou);
		if(aluno->prox != NULL){ // se esta na lista
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que não achou
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);







    tListDuplaEncAlunos listaDuplaEncOrd2;
    ini_tListDuplaEncAlunos(&listaDuplaEncOrd2);

    printf("Testando inclusão de elementos\n");
    /*
        2. Preencher a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível
        avaliar o desempenho considerando os casos em que se
        tenta incluir um elemento que já esxiste na lista.
        Para comparar esta etrutura definir uma semente que
        garanta a mesma sequencia de números aleatórios em
        todos os testes
    *//*
    unsigned int seed = time(NULL); //gerando uma semente para os testes
    srand(seed);
    int index;
    int i;
    srand(seed); // definindo a semente do sequencia rand
	  start = omp_get_wtime(); // Iniciando o cronometro
    // equanto a lista não estiver cheia
    i = 0;
    while(i < LSIZE/2){
      // gera um índece aleatório nos limites da lista de referencia
          index = rand()%LSIZE;
          // incluindo o elemento index, pode já ter sido incluido
      if(incOrd_tListDuplaEncAlunos(lista.lista[index], &listaDuplaEncOrd2))
              i++;
      }
      stop = omp_get_wtime(); // Para o cronometro
      printf("t_inc = %f\n", stop - start);
        if (lista.cap <= 10){
            printf("Lista encadeada\n");
            printListaDuplaEncAluno2(listaDuplaEncOrd2);
        }







/*


    printf("Testando busca de elementos\n");
    /*
        3. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se
        de teste de busca considerando elementos que estão e que não
        estão na lista.
    *//*
    PONTD aluno;  //Ponteiro para elemento achado
    int qIn, qOut; // Variáveis para testar se a busca funcionou
	qIn = qOut = 0; // quantos elementos estão ou não na lista
	qIn = qOut = 0; // quantos elementos estão ou não na lista
  int index;
	start = omp_get_wtime(); // Iniciando o cronometro
    int achou;
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
        aluno = buscaBin_tListDuplaEncAlunos(listaDuplaEncOrd, lista.lista[index]
        .numMatricula, &achou);
		if(achou){ // se esta na lista
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que não achou
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);





     printf(" Testando uma Lista Linear duplamente encadeada\n");





    tListDuplaEncAlunos listaDuplaEncOrd;
    ini_tListEncAlunos(&listaEncNaoOrd);

    printf("LSIZE = %d\n", LSIZE);

    printf("Testando inclusão de elementos\n");
    /*
        2. Preencher a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível
        avaliar o desempenho considerando os casos em que se
        tenta incluir um elemento que já esxiste na lista.
        Para comparar esta etrutura definir uma semente que
        garanta a mesma sequencia de números aleatórios em
        todos os testes
    *//*
    unsigned int seed = time(NULL); //gerando uma semente para os testes
    srand(seed); // definindo a semente do sequencia rand
	start = omp_get_wtime(); // Iniciando o cronometro
    int index;
    // equanto a lista não estiver cheia
    int i = 0;
	while(i < LSIZE/2){
		// gera um índece aleatório nos limites da lista de referencia
        index = rand()%LSIZE;
        // incluindo o elemento index, pode já ter sido incluido
		if(inc_tListDuplaEncAlunos(lista.lista[index], &listaDuplaDuplaOrd))
            i++;
	}

	stop = omp_get_wtime(); // Para o cronometro
	printf("t_inc = %f\n", stop - start);
    if (lista.cap <= 10){
        printf("Lista encadeada\n");
        printListaEncAluno2(listaEncNaoOrd);
    }

    printf("Testando busca de elementos\n");
    /*
        3. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se
        de teste de busca considerando elementos que estão e que não
        estão na lista.
    *//*
    PONT aluno;  //Ponteiro para elemento achado
    int qIn, qOut; // Variáveis para testar se a busca funcionou
	qIn = qOut = 0; // quantos elementos estão ou não na lista
	start = omp_get_wtime(); // Iniciando o cronometro
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
        aluno = busca_tListEncAlunos(listaEncNaoOrd, lista.lista[index].numMatricula);
		if(aluno->prox != listaEncNaoOrd.tail){ // se esta na lista
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que não achou
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

    printf("Testando remoção de elementos\n");
    /*
        4. Esvaziar a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível
        avaliar o desempenho considerando os casos em que se
        tenta escluit um elemento que não esxiste na lista.
    *//*
	start = omp_get_wtime();// Iniciando o cronometro
    // equanto a lista não estiver vazia
	while(listaEncNaoOrd.head->prox != listaEncNaoOrd.tail){
        // gera um índece aleatório nos limites da lista de referencia
		index = random()%LSIZE;
        // removendo o elemento index, pode não estar na lista
        rem_tListEncAlunos(lista.lista[index], &listaEncNaoOrd);
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_rem = %f\n", stop - start);
	if (lista.cap <= 10){
        printf("Lista encadeada\n");
        printListaEncAluno2(listaEncNaoOrd);
    }


    printf("=================================================\n");

    tListEncAlunos listaEncOrd;
    ini_tListEncAlunos(&listaEncOrd);


    printf(" Testando uma Lista Linear de Simplesmente\n");
    printf("Encadeada Ordenada.\n");
    printf("LSIZE = %d\n", LSIZE);

    printf("Testando inclusão de elementos\n");
    /*
        2. Preencher a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível
        avaliar o desempenho considerando os casos em que se
        tenta incluir um elemento que já esxiste na lista.
        Para comparar esta etrutura definir uma semente que
        garanta a mesma sequencia de números aleatórios em
        todos os testes
    *//*
    srand(seed); // definindo a semente do sequencia rand
	start = omp_get_wtime(); // Iniciando o cronometro
    // equanto a lista não estiver cheia
    i = 0;
	while(i < LSIZE/2){
		// gera um índece aleatório nos limites da lista de referencia
        index = random()%LSIZE;
        // incluindo o elemento index, pode já ter sido incluido
		if(incOrd_tListEncAlunos(lista.lista[index], &listaEncOrd))
            i++;

	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_inc = %f\n", stop - start);
    if (lista.cap <= 10){
        printf("Lista encadeada\n");
        printListaEncAluno2(listaEncOrd);
    }

    printf("Testando busca de elementos\n");
    /*
        3. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se
        de teste de busca considerando elementos que estão e que não
        estão na lista.
    *//*
	qIn = qOut = 0; // quantos elementos estão ou não na lista
	start = omp_get_wtime(); // Iniciando o cronometro
    int achou;
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
        aluno = buscaBin_tListEncAlunos(listaEncOrd, lista.lista[index].numMatricula, &achou);
		if(achou){ // se esta na lista
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que não achou
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

    printf("Testando remoção de elementos\n");*/
    /*
        4. Esvaziar a lista pegando elementos, de formaa
        aleatória da lista de referência. Desta forma é possível
        avaliar o desempenho considerando os casos em que se
        tenta escluit um elemento que não esxiste na lista.
    *//*
	start = omp_get_wtime();// Iniciando o cronometro
    // equanto a lista não estiver vazia
	while(listaEncOrd.head->prox != listaEncOrd.tail){
        // gera um índece aleatório nos limites da lista de referencia
		index = random()%LSIZE;
        // removendo o elemento index, pode não estar na lista
        remOrd_tListEncAlunos(lista.lista[index], &listaEncOrd);
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_rem = %f\n", stop - start);
	if (lista.cap <= 10){
        printf("Lista encadeada\n");
        printListaEncAluno2(listaEncOrd);
    }*/

    return 0;
}
