/******************************************************************************
//     usaFilaDinamica.c
// Este programa interage com o usuario para o gerenciamento de uma fila.
******************************************************************************/
#include "filaDinamica.c"
#include <stdio.h>

void inserir(FILA* f){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirNaFila(f,reg)) printf("Elemento %i inserido corretamente.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void buscar(FILA* f){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  PONT posicao = buscaSeq(f,ch);
  if (posicao != NULL) printf("Elemento %i encontrado no endereco %p (busca sequencial).\n",ch,posicao);
  else printf("Nao foi possivel encontrar elemento %i.\n",ch);
  posicao = buscaSeqSent1(f,ch);
  if (posicao != NULL) printf("Elemento %i encontrado no endereco %p (busca sequencial sentinela 1).\n",ch,posicao);
  else printf("Nao foi possivel encontrar elemento %i.\n",ch);
  posicao = buscaSeqSent2(f,ch);
  if (posicao != NULL) printf("Elemento %i encontrado no endereco %p (busca sequencial sentinela 2).\n",ch,posicao);
  else printf("Nao foi possivel encontrar elemento %i.\n",ch);
}

void exibirPrimeiro(FILA* f){
  TIPOCHAVE ch;
  PONT posicao = retornarPrimeiro(f,&ch);
  if (posicao != NULL) printf("Primeiro elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (fila vazia).\n");
}

void exibirUltimo(FILA* f){
  TIPOCHAVE ch;
  PONT posicao = retornarUltimo(f,&ch);
  if (posicao != NULL) printf("Ultimo elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o ultimo elemento (fila vazia).\n");
}

void excluir(FILA* f){
  TIPOCHAVE ch;
  REGISTRO excluido;
  if (excluirDaFila(f,&excluido)) printf("Elemento %i excluido corretamente.\n",excluido.chave);
  else printf("Nao foi possivel excluir elemento %i.\n",ch);
}

void exibir(FILA* f){
  exibirFila(f);
}

void meuLog(FILA* f){
  printf("Numero de elementos na fila: %i.\n",tamanho(f));
  printf("Tamanho da fila (em bytes): %i.\n",tamanhoEmBytes(f));
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1 no final da fila\n");
  printf("   e : exclui primeiro elemento da fila\n");
  printf("   p : imprimir fila\n");
  printf("   d : destruir (zerar) fila\n");
  printf("   l : exibir log de utilizacao da fila\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   b <chave1>: exibir posicao do elemento com chave=chave1\n");
  printf("   0 : exibir a chave e o endereco do primeiro elemento\n");
  printf("   u : exibir a chave e o endereco do ultimo elemento\n");
  printf("   q : sair (quit)\n");
}

void destruir(FILA* f){
     destruirFila(f);
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
      case 'b' : buscar(&fila); break;
      case '0' : exibirPrimeiro(&fila); break;
      case 'u' : exibirUltimo(&fila); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
