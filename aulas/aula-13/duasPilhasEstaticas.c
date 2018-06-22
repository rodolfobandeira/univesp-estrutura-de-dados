/******************************************************************************
//     duasPilhasEstaticas.c
// Este programa gerencia duas pilhas implementadas em um arranjo
   (implementacao estatica).
// As pilhas gerenciadas podem ter um numero de no maximo MAX elementos (juntas).
// Não usaremos sentinela nesta estrutura.
******************************************************************************/
#include <stdio.h>
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
  int topo1;
  int topo2;
} PILHADUPLA;


/* Inicialização da PILHADUPLA (a PILHADUPLA jah esta criada e eh apontada 
pelo endereco em p) */
void inicializarPilhaDupla(PILHADUPLA* p){
  p->topo1 = -1;
  p->topo2 = MAX;
} /* inicializarPILHADUPLA* /


/* Retornar o tamanho da PILHADUPLA (numero de elementos das duas somadas) */
int tamanhoPilhaDupla(PILHADUPLA* p) {
  return p->topo1+1 + MAX-p->topo2;
} /* tamanhoPILHADUPLA* /

/* Retornar o tamanho de uma das pilhas */
int tamanhoUmaPilha(PILHADUPLA* p, int pilha) {
  if (pilha < 1 || pilha > 2) return -1;
  if (pilha == 1) return p->topo1+1;
  else return MAX-p->topo2;
} /* tamanhoUmaPilha */

/* Exibição de uma das pilhas */
void exibirUmaPilha(PILHADUPLA* p, int pilha){
  if (pilha < 1 || pilha > 2) return;
  printf("Pilha %i: \" ", pilha);
  int i;
  if (pilha == 1) for (i=p->topo1;i>=0;i--) printf("%i ", p->A[i].chave);
  else for (i=p->topo2;i<MAX;i++) printf("%i ", p->A[i].chave);
  printf("\"\n");
} /* exibirPilha */ 

/* Retornar o tamanho em bytes da pilha. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytesPilha(PILHADUPLA* p) {
  return sizeof(PILHADUPLA);
} /* tamanhoEmBytes */

void reinicializarPilha(PILHADUPLA* p) {
  p->topo1 = -1;
  p->topo2 = MAX;
}

/* Destruição da pilha */
void reinicializarPilha2(PILHADUPLA* p) {
     inicializarPilhaDupla(p);
} /* destruirPilha */

/* inserirElementoPilha - insere elemento no fim da pilha   */
bool inserirElementoPilha(PILHADUPLA* p, REGISTRO reg, int pilha){
     if (pilha < 1 || pilha > 2) return false;
     if (p->topo1 + 1 == p->topo2) return false;
     if (pilha == 1) {
       p->topo1 = p->topo1+1;
       p->A[p->topo1] = reg;
     }else{
       p->topo2 = p->topo2-1;
       p->A[p->topo2] = reg;        
     }
     return true;
} /* inserirElementoPilha */

/* excluirElementoPilha - retorna e exclui topo da pilha 
retorna false se nao houver elemento a ser retirado */
bool excluirElementoPilha(PILHADUPLA* p, REGISTRO* reg, int pilha){
   if (pilha < 1 || pilha > 2) return false;
   if (pilha == 1){
     if (p->topo1 == -1) return false;
       *reg = p->A[p->topo1];
       p->topo1 = p->topo1-1;
   }else{
     if (p->topo2 == MAX) return false;
       *reg = p->A[p->topo2];
       p->topo2 = p->topo2+1;      
   }
   return true;
} /* excluirElementoPilha */

/* retornarPrimeiroPilha
retorna a posicao do primeiro (topo) elemento da pilha e o valor de sua chave no 
conteudo do endereco ch. Retorna -1 caso a lista esteja vazia */
int retornarPrimeiroPilha(PILHADUPLA* p, TIPOCHAVE* ch, int pilha){
  if (pilha < 1 || pilha > 2) return -1;
  if (pilha == 1){
    if (p->topo1==-1)return -1;
    *ch = p->A[p->topo1].chave;
    return p->topo1;
  }
  if (p->topo2==MAX)return -1;
  *ch = p->A[p->topo2].chave;          
  return p->topo2;
}
