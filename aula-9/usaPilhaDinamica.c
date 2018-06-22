/******************************************************************************
//     usaPilhaDinamica.c
// Este programa interage com o usuario para o gerenciamento de uma pilha.
******************************************************************************/
#include "pilhaDinamica.c"
#include <stdio.h>

void inserir(PILHA *l){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElemPilha(l,reg)) printf("Elemento %i inserido corretamente.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void exibirTopo(PILHA *l){
  TIPOCHAVE ch;
  PONT posicao = retornarTopo(l,&ch);
  if (posicao != NULL) printf("Elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar nenhum elemento (pilha vazia).\n");
}


void excluir(PILHA *l){
  REGISTRO temp;
  if (excluirElemPilha(l, &temp)) printf("Elemento %i excluido corretamente.\n",temp.chave);
  else printf("Nao foi possivel excluir elemento (pilha vazia).\n");
}

void exibir(PILHA *l){
  exibirPilha(l);
}

void meuLog(PILHA *l){
  printf("Numero de elementos na pilha: %i.\n",tamanho(l));
  printf("Tamanho da pilha (em bytes): %i.\n",tamanhoEmBytes(l));
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1\n");
  printf("   e : excluir topo da pilha\n");
  printf("   p : imprimir pilha\n");
  printf("   d : destruir (zerar) pilha\n");
  printf("   l : exibir log de utilizacao da pilha\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   0 : exibir a chave e o endereco do primeiro elemento\n");
  printf("   q : sair\n");
}

void destruir(PILHA *l){
     reinicializarPilha(l);
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
      case '0' : exibirTopo(&pilha); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
