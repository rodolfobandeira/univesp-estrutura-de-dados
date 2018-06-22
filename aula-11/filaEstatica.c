/******************************************************************************
//     filaEstatica.c
// Este programa gerencia filas implementadas em arranjos 
   (implementacao estatica).
// As filas gerenciadas podem ter no maximo MAX elementos.
// Não usaremos sentinela nesta estrutura.
******************************************************************************/
#include <stdio.h>
#define ERRO -1
#define true 1
#define false 0
#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX];
  int inicio;
  int nroElem;
} FILA;

/* Inicialização da fila (a fila jah esta criada e eh apontada 
pelo endereco em f) */
void inicializarFila(FILA* f){
  f->inicio=0;
  f->nroElem=0;
} /* inicializarFila */


/* Retornar o tamanho da fila (numero de elementos) */
int tamanhoFila(FILA* f) {
  return f->nroElem;
} /* tamanho */

/* Exibição da fila seqüencial */
void exibirFila(FILA* f){
   printf("Fila: \" ");
   int i = f->inicio;
   int temp;
   for (temp = 0; temp < f->nroElem; temp++){
      printf("%i ", f->A[i].chave); // soh lembrando TIPOCHAVE = int
      i = (i + 1) % MAX;
    }
   printf("\"\n");
} /* exibirLista */ 


/* Retornar o tamanho em bytes da fila. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytesFila(FILA* f) {
  return sizeof(FILA);
} /* tamanhoEmBytes */

/* Busca Fila - retorna a posicao do primeiro elemento da fila */
int buscaFila(FILA* f){
  if (f->nroElem > 0) return f->inicio;
  return ERRO;
} /* buscaFila */
/* Busca Sequencia Fila - retorna a posicao do primeiro elemento da fila
   que possui a chave buscada */
int buscaSequencial(FILA* f, TIPOCHAVE ch){
   int i = f->inicio;
   int temp;
   for (temp = 0; temp < f->nroElem; temp++){
      if (f->A[i].chave == ch) return i;
      i = (i + 1) % MAX;
    }
  return ERRO;
} /* buscaFila */


/* Destruição da fila */
void reinicializarFila(FILA* f) {
     inicializarFila(f);
} /* destruirFila */

/* inserirElementoFila - insere elemento no fim da fila   */
bool inserirElementoFila(FILA* f,REGISTRO reg){
     if (f->nroElem >= MAX) return false;
     f->A[(f->inicio + f->nroElem)%MAX] = reg;
     f->nroElem++;
     return true;
} /* inserirElementoFila */

/* excluirElementoFila - retorna e exclui 1o elemento da fila 
retorna false se nao houver elemento a ser retirado */
bool excluirElementoFila(FILA* f,REGISTRO* reg){
   if (f->nroElem==0) return false;
   *reg = f->A[f->inicio];
   f->inicio = (f->inicio+1)%MAX;
   f->nroElem--;
   return true;
} /* excluirElementoFila */

/* retornarPrimeiroFila
retorna a posicao do primeiro elemento da fial e o valor de sua chave no 
conteudo do endereco ch. Retorna -1 caso a lista esteja vazia */
int retornarPrimeiroFila(FILA* f, TIPOCHAVE* ch){
    if (f->nroElem==0)return -1;
    *ch = f->A[f->inicio].chave;
    return f->inicio;
}

