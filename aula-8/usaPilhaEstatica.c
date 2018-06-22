/******************************************************************************
//     usaPilhaEstatica.c
// Este programa interage com o usuario para o gerenciamento de uma pilha 
// (implementacao estatica).
******************************************************************************/
#include "pilhaEstatica.c"
#include <stdio.h>

void inserir(PILHA* p){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoPilha(p,reg)) printf("Elemento %i inserido corretamente.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void exibirPrimeiroPilha(PILHA* p){
  TIPOCHAVE ch;
  int posicao = retornarPrimeiroPilha(p,&ch);
  if (posicao != -1) printf("Primeiro elemento %i encontrado na posição %i.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (pilha vazia).\n");
}


void excluir(PILHA* p){
  REGISTRO reg;
  if (excluirElementoPilha(p,&reg)) printf("Elemento %i excluido corretamente.\n",reg.chave);
  else printf("Nao foi possivel excluir elemento - pilha vazia.\n");
}

void exibir(PILHA* p){
  exibirPilha(p);
}

void meuLog(PILHA* p){
  printf("Numero de elementos na pilha: %i.\n",tamanhoPilha(p));
  printf("Tamanho da pilha (em bytes): %i.\n",tamanhoEmBytesPilha(p));
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1 no topo da pilha\n");
  printf("   e : excluir o topo da pilha\n");
  printf("   p : imprimir pilha\n");
  printf("   d : destruir (zerar) pilha\n");
  printf("   l : exibir log de utilizacao da pilha\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   0 : exibir a chave e o endereco do topo da pilha\n");
}

void destruir(PILHA* p){
     reinicializarPilha(p);
     printf("Pilha zerada.\n");
}

int main(){
  PILHA pilha;
  inicializarPilha(&pilha);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir(&pilha); break;
      case 'e' : excluir(&pilha); break;
      case 'p' : exibir(&pilha); break;
      case 'd' : destruir(&pilha); break;
      case 'l' : meuLog(&pilha); break;
      case 'h' : help(); break;
      case '0' : exibirPrimeiroPilha(&pilha); break;
      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
