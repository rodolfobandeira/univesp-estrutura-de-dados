/******************************************************************************
     esparsasArranjoDeListas.c
  Este programa gerencia matrizes esparsas (implementacao na forma de arranjo
  de listas lineares).
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int bool;

typedef struct tempNo{
  int coluna;
  float valor;
  struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct {
  int linhas;
  int colunas;
  PONT* A;
} MATRIZ;

/* Inicialização da matriz esparsa (cria o arranjo que contera o inicio das
   listas ligadas correspondentes a cada linha e coloca NULL em cada posicao
   indicando que as listas comecam vazias)                                */
void inicializarMatriz(MATRIZ* m, int lin, int col){
   int i;
   m->linhas = lin;
   m->colunas = col;
   m->A = (PONT*) malloc(lin*sizeof(PONT));
   for (i=0;i<lin;i++) m->A[i] = NULL;
} /* inicializarMatriz */

/* Exibicao da matriz na forma de uma conjunto de listas */
void exibirMatrizLinhas(MATRIZ* m){
  int i;
  printf("Matriz: %i por %i\n", m->linhas, m->colunas);
  for (i=0;i<m->linhas;i++){
    PONT atual = m->A[i];
    printf("[Linha %i]:",i);
    while (atual != NULL){
      printf(" (%i;%f)",atual->coluna,atual->valor);
      atual = atual->prox;
    }
    printf("\n");
  }
} /* exibirMatriz */ 

/* Retornar o tamanho da matriz (numero de elementos validos) */
int tamanho(MATRIZ* m) {
  int i;
  int tam=0;
  for (i=0;i<m->linhas;i++){
    PONT atual = m->A[i];
    while (atual != NULL){
      tam++;
      atual = atual->prox;
    }
  }
  return tam;
} /* tamanho */

/* Retornar o numero total de nos da matriz */
int NumeroNos(MATRIZ* m) {
  return tamanho(m);
} /* NumeroNos */

/* Retornar o tamanho em bytes da matriz. Neste caso, isto depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytes(MATRIZ* m) {
  return (tamanho(m)*sizeof(NO)) + sizeof(MATRIZ) + sizeof(PONT)*(m->linhas);
} /* tamanhoEmBytes */

/* Busca sequencial - retorna o endereco do elemento com o indice buscado
   se ele existir; caso contrario retorna NULL  */
PONT buscaSequencial(MATRIZ* m, int lin, int col){
  if (lin<0 || lin>=m->linhas || col<0 || col >= m->colunas) return NULL;
  PONT atual = m->A[lin];
  while (atual != NULL && atual->coluna<col) atual = atual->prox;
  if (atual !=NULL && atual->coluna == col) return atual;
  return NULL;
} /* buscaSequencial */

/* Exclusao do elemento da posicao (linha e coluna) indicada */
bool excluirElemMatriz(MATRIZ* m, int lin, int col){
  if (lin<0 || lin>=m->linhas || col<0 || col >= m->colunas) return false;
  PONT ant = NULL;
  PONT atual = m->A[lin];
  while (atual != NULL && atual->coluna<col) {
    ant = atual;
    atual = atual->prox;
  }
  if (atual == NULL || atual->coluna != col) return false;
  if (ant==NULL) m->A[lin] = atual->prox;
  else ant->prox = atual->prox;
  free(atual);
  return true;
} /* excluirElemMatriz */

/* Reinicializacao da matriz: libera a memoria de todos os elementos da matriz
   deixando-a como se tivesse terminado de ser inicializada */
void reinicializarMatriz(MATRIZ* m) {
  int i;
  for (i=0;i<m->linhas;i++){
    PONT atual = m->A[i];
    while (atual != NULL){
      PONT apagar = atual;
      atual = atual->prox;
      free(atual);
    }
    m->A[i] = NULL;
  }
} /* destruirMatriz */

/* LiberaMatriz = destruirMatriz */
void LiberaMatriz(MATRIZ* m){
     reinicializarMatriz(m);
} /* LiberaMatriz */

/* Atribuicao de valor na matriz: ha quatro casos principais:
   1o) se o elemento ja existe e o valor a ser inserido for maior que zero
       ira substituir o valor existente;
   2o) se o elemnto ja existe e o valor a ser inserido for zero ira excluir
       o elemento existente;
   3o) se o elemento nao existe e o valor a ser inserido for maior que zero
       ira inserir um novo elemento;
   4o) se o elemento nao existe e o valor for igual a zero nao fara nada.  */
bool AtribuiMatriz(MATRIZ* m,int lin, int col, float val) {
  if (lin<0 || lin >= m->linhas || col<0 || col >= m->colunas) return false;
  PONT ant = NULL;
  PONT atual = m->A[lin];
  while (atual != NULL && atual->coluna<col) {
    ant = atual;
    atual = atual->prox;
  }
  if (atual != NULL && atual->coluna == col) {
    if (val == 0) {
		if (ant==NULL) m->A[lin] = atual->prox;
		else ant->prox = atual->prox;
		free(atual);
	}
    else atual->valor = val;
  }else if (val != 0){
    PONT novo = (PONT) malloc(sizeof(NO));
    novo->coluna = col;
    novo->valor = val;
    novo->prox = atual;
    if (ant == NULL) m->A[lin] = novo;
    else ant->prox = novo;
  }
  return true;
} /* AtribuiMatriz */

/* ValorMatriz - retorna o valor do elemento de posicao lin, col 
   e 0 caso elemento nao exista   */
float ValorMatriz(MATRIZ* m, int lin, int col){
  if (lin<0 || lin>=m->linhas || col<0 || col >= m->colunas) return 0;
  PONT atual = m->A[lin];
  while (atual != NULL && atual->coluna<col) atual = atual->prox;
  if (atual !=NULL && atual->coluna == col) return atual->valor;
  return 0;
} /* ValorMatriz */


/* OrdemMatriz - coloca nos enderecos m e n a ordem da matriz */
void OrdemMatriz(MATRIZ* mat, int* m, int* n){
     *m = mat->linhas;
     *n = mat->colunas;
} /* OrdemMatriz */

/* SOMA INEFICIENTE DE MATRIZES */
MATRIZ* SomaMatriz(MATRIZ* mat1, MATRIZ* mat2) {
  int lin = mat1->linhas;
  int col = mat1->colunas;
  if ((mat2->linhas != lin) || (mat2->colunas != col)) return NULL;      
  MATRIZ* c = (MATRIZ*) malloc(sizeof(MATRIZ));
  inicializarMatriz(c,lin,col);
  int x;
  int y;
  for (x=0;x<lin;x++)
    for (y=0;y<col;y++) AtribuiMatriz(c,x,y,ValorMatriz(mat1,x,y)+ValorMatriz(mat2,x,y));
  return c;

}
