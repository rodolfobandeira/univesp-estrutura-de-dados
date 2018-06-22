/******************************************************************************
//     usaFilaEstatica.c
// Este programa interage com o usuario para o gerenciamento de uma fila 
// (implementacao estatica).
******************************************************************************/
#include "filaEstatica.c"
#include <stdio.h>

void inserir(FILA* f){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElementoFila(f,reg)) printf("Elemento %i inserido corretamente.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void exibirPrimeiroFila(FILA* f){
  TIPOCHAVE ch;
  int posicao = retornarPrimeiroFila(f,&ch);
  if (posicao != -1) printf("Primeiro elemento %i encontrado na posição %i.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (fila vazia).\n");
}


void excluir(FILA* f){
  REGISTRO reg;
  if (excluirElementoFila(f,&reg)) printf("Elemento %i excluido corretamente.\n",reg.chave);
  else printf("Nao foi possivel excluir elemento - fila vazia.\n");
}

void exibir(FILA* f){
  exibirFila(f);
}

void meuLog(FILA* f){
  printf("Numero de elementos na fila: %i.\n",tamanhoFila(f));
  printf("Tamanho da fila (em bytes): %i.\n",tamanhoEmBytesFila(f));
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1 no final da fila\n");
  printf("   e : excluir o 1o elemento da fila\n");
  printf("   p : imprimir fila\n");
  printf("   d : destruir (zerar) fila\n");
  printf("   l : exibir log de utilizacao da fila\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   0 : exibir a chave e o endereco do primeiro elemento\n");
  printf("   q : sair\n");
}

void destruir(FILA* f){
     reinicializarFila(f);
     printf("Fila zerada.\n");
}

int main(){
  FILA fila;
  inicializarFila(&fila);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir(&fila); break;
      case 'e' : excluir(&fila); break;
      case 'p' : exibir(&fila); break;
      case 'd' : destruir(&fila); break;
      case 'l' : meuLog(&fila); break;
      case 'h' : help(); break;
      case '0' : exibirPrimeiroFila(&fila); break;
      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
