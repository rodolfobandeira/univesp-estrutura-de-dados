/******************************************************************************
     usaDuasPilhasEstaticas.c
  Este programa interage com o usuario para o gerenciamento de duas pilhas
  alocadas num mesmo arranjo.
******************************************************************************/
#include "duasPilhasEstaticas.c"
#include <stdio.h>

void inserir1(PILHADUPLA* p){
  TIPOCHAVE ch;
  scanf("%d",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoPilha(p,reg,1)) printf("Elemento %d inserido corretamente na pilha 1.\n",ch);
  else printf("Nao foi possivel inserir elemento %d.\n",ch);
}

void inserir2(PILHADUPLA* p){
  TIPOCHAVE ch;
  scanf("%d",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoPilha(p,reg,2)) printf("Elemento %d inserido corretamente na pilha 2.\n",ch);
  else printf("Nao foi possivel inserir elemento %d.\n",ch);
}

void exibirPrimeiro1(PILHADUPLA* p){
  TIPOCHAVE ch;
  int posicao = retornarPrimeiroPilha(p,&ch,1);
  if (posicao != -1) printf("Primeiro elemento pilha 1: %d encontrado no endereco %d.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (pilha vazia).\n");
}

void exibirPrimeiro2(PILHADUPLA* p){
  TIPOCHAVE ch;
  int posicao = retornarPrimeiroPilha(p,&ch,2);
  if (posicao != -1) printf("Primeiro elemento pilha 2: %d encontrado no endereco %d.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (pilha vazia).\n");
}

void excluir1(PILHADUPLA* p){
  REGISTRO reg;
  if (excluirElementoPilha(p,&reg,1)) printf("Elemento %d excluido corretamente da pilha 1.\n",reg.chave);
  else printf("Nao foi possivel excluir elemento pilha 1 - pilha vazio.\n");
}

void excluir2(PILHADUPLA* p){
  REGISTRO reg;
  if (excluirElementoPilha(p, &reg,2)) printf("Elemento %d excluido corretamente da pilha 2.\n",reg.chave);
  else printf("Nao foi possivel excluir elemento pilha 2 - pilha vazio.\n");
}


void exibir1(PILHADUPLA* p){
  exibirUmaPilha(p,1);
}

void exibir2(PILHADUPLA* p){
  exibirUmaPilha(p,2);
}

void meuLog(PILHADUPLA* p){
  printf("Numero de elementos na pilha 1: %d.\n",tamanhoUmaPilha(p,1));
  printf("Numero de elementos na pilha 2: %d.\n",tamanhoUmaPilha(p,2));
  printf("Tamanho do pilha (em bytes): %d.\n",tamanhoEmBytesPilha(p));
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1, na pilha 1\n");
  printf("   j <chave1>: inserir elemento com chave=chave1, na pilha 2\n");
  printf("   e : excluir elemento com chave=chave1, na pilha 1\n");
  printf("   f : excluir elemento com chave=chave1, na pilha 2\n");
  printf("   o : imprimir pilha 1\n");
  printf("   p : imprimir pilha 2\n");
  printf("   d : destruir (zerar) pilhas\n");
  printf("   l : exibir log de utilizacao do pilha\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   1 : exibir a chave e o endereco do topo, pilha 1\n");
  printf("   2 : exibir a chave e o endereco do topo, pilha 2\n");
  printf("   q : sair (quit)\n");
}

void destruir(PILHADUPLA* p){
     reinicializarPilha(p);
     printf("Pilhas zeradas.\n");
}

int main(){
  PILHADUPLA pilha;
  inicializarPilhaDupla(&pilha);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir1(&pilha); break;
      case 'j' : inserir2(&pilha); break;
      case 'e' : excluir1(&pilha); break;
      case 'f' : excluir2(&pilha); break;
      case 'o' : exibir1(&pilha); break;
      case 'p' : exibir2(&pilha); break;
      case 'd' : destruir(&pilha); break;
      case 'l' : meuLog(&pilha); break;
      case 'h' : help(); break;
      case '1' : exibirPrimeiro1(&pilha); break;
      case '2' : exibirPrimeiro2(&pilha); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
