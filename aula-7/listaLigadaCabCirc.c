/******************************************************************************
     listaLigadaCabCirc.c
  Este programa gerencia listas lineares ligadas circulares (implementacao 
dinamica) com nó cabeça no início da lista.
  As listas gerenciadas podem ter um numero arbitrario de elementos.
  O no cabeça acelera o algoritmo de busta sequencial por reduzir o numero
de comparacoes. Alem disso algumas operacoes ficam mais simples pois a lista
nunca esta "vazia" (sempre haverah o noh cabeca)
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;


typedef struct tempRegistro{
  REGISTRO reg;
  struct tempRegistro* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
  PONT cabeca;
} LISTA;

/* Inicialização da lista ligada (a lista jah esta criada e eh apontada 
pelo endereco em l) */
void inicializarLista(LISTA* l){
  l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
  l->cabeca->prox = l->cabeca;  // faz com que a lista seja circular
} /* inicializarLISTA* /

/* Exibição da lista sequencial */
void exibirLista(LISTA* l){
  PONT end = l->cabeca->prox;
  printf("Lista: \" ");
  while (end != l->cabeca){
    printf("%d ", end->reg.chave); // soh lembrando TIPOCHAVE = int
    end = end->prox;
  }
  printf("\"\n");
} /* exibirLISTA* / 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  PONT end = l->cabeca->prox;
  int tam = 0;
 while (end != l->cabeca){
    tam++;
    end = end->prox;
  }
  return tam;
} /* tamanho */

/* Retornar o tamanho em bytes da lista. Neste caso, isto depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytes(LISTA* l) {
  return((tamanho(l)+1)*sizeof(ELEMENTO))+sizeof(LISTA); // sizeof(LISTA) = sizeof(PONT) pois a "LISTA" eh um ponteiro para o 1o elemento
} /* tamanhoEmBytes */

/* Busca sequencial sentinela (lista ordenada ou nao) */
PONT buscaSentinela(LISTA* l, TIPOCHAVE ch){
  PONT pos = l->cabeca->prox;
  l->cabeca->reg.chave = ch;
  while (pos->reg.chave != ch) pos = pos->prox;
  if (pos != l->cabeca) return pos;
  return NULL;
} /* buscaSentinela */

/* Busca sequencial (lista ordenada) */
PONT buscaSentinelaOrd(LISTA* l, TIPOCHAVE ch){
  PONT pos = l->cabeca->prox;
  l->cabeca->reg.chave = ch;
  while (pos->reg.chave < ch) pos = pos->prox;
  if (pos != l->cabeca && pos->reg.chave==ch) return pos;
  return NULL;
} /* buscaSentinelaOrd */

/* Busca sequencial - funcao de exclusao (retorna no endereço *ant o indice do
   elemento anterior ao elemento que está sendo buscado [ant recebe o elemento
   anterior independente do elemento buscado ser ou não encontrado]) 
   O nó cabeca pode ser o anterior.   
*/
PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant){
  *ant = l->cabeca;
  PONT pos = l->cabeca->prox;
  l->cabeca->reg.chave = ch; // utiliza o cabeça como sentinela
  while (pos->reg.chave<ch){
    *ant = pos;
    pos = pos->prox;
  }
  if ((pos != l->cabeca) && (pos->reg.chave == ch)) return pos;
  return NULL;
} /* buscaSeqExc */

/* Exclusão do elemento de chave indicada */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
  PONT ant, i;
  i = buscaSeqExc(l,ch,&ant);
  if (i == NULL) return false;  // elemento a ser excluido nao existe
  ant->prox = i->prox;
  free(i);
  return true;
} /* excluirElemListaEnc */

/* Destruição da lista sequencial 
   libera a memoria de todos os elementos da lista*/
void reinicializarLista(LISTA* l) {
  PONT end = l->cabeca->prox;
  while (end != l->cabeca){
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->cabeca->prox = l->cabeca;
} /* destruirLISTA* /


/* Inserção em lista ordenada sem duplicação */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  PONT ant, i;
  i = buscaSeqExc(l,reg.chave,&ant);
  if (i != NULL) return false;
  i = (PONT) malloc(sizeof(ELEMENTO));
  i->reg = reg;
  i->prox = ant->prox;
  ant->prox = i;
  return true;
} /* inserirElemListaOrd */

/* retornarPrimeiro - retorna o endereco do primeiro elemento da lista e (caso
   a lista nao esteja vazia) retorna a chave desse elemento na memoria 
   apontada pelo ponteiro ch */
PONT retornarPrimeiro(LISTA* l, TIPOCHAVE* ch){
  if (l->cabeca->prox != l->cabeca) *ch = l->cabeca->prox->reg.chave;
  return l->cabeca->prox;
} /* retornarPrimeiro */

/* retornarUltimo - retorna o endereco do ultimo elemento da lista e (caso
   a lista nao esteja vazia) retorna a chave desse elemento na memoria 
   apontada pelo ponteiro ch */
PONT retornarUltimo(LISTA* l, TIPOCHAVE* ch){
  PONT ultimo = l->cabeca->prox;
  if (ultimo == l->cabeca) return NULL;
  while (ultimo->prox != l->cabeca) ultimo = ultimo->prox;
  *ch = ultimo->reg.chave;
  return ultimo;
} /* retornarUltimo */
