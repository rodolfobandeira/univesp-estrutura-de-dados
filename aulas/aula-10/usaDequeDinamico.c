/******************************************************************************
//     usaDeque.c
// Este programa interage com o usuario para o gerenciamento de um deque.
******************************************************************************/
#include "dequeDinamico.c"
#include <stdio.h>

void inserir1(DEQUE* d){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirDequeInicio(d,reg)) printf("Elemento %i inserido corretamente na entrada 1.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void inserir2(DEQUE* d){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirDequeFim(d,reg)) printf("Elemento %i inserido corretamente na entrada 2.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}

void buscar(DEQUE* d){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  PONT posicao = buscaSeq(d,ch);
  if (posicao != NULL) printf("Elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar elemento %i.\n",ch);
}

void exibirPrimeiro1(DEQUE* d){
  TIPOCHAVE ch;
  PONT posicao = retornarPrimeiro1(d,&ch);
  if (posicao != NULL) printf("Primeiro elemento entrada 1: %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (deque vazio).\n");
}

void exibirPrimeiro2(DEQUE* d){
  TIPOCHAVE ch;
  PONT posicao = retornarPrimeiro2(d,&ch);
  if (posicao != NULL) printf("Primeiro elemento entrada 2: %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (deque vazio).\n");
}

void excluir1(DEQUE* d){
  REGISTRO ch;
  if (excluirElemDequeInicio(d,&ch)) printf("Elemento %i excluido corretamente da entrada 1.\n",ch.chave);
  else printf("Nao foi possivel excluir elemento entrada 1 - deque vazio.\n");
}

void excluir2(DEQUE* d){
  REGISTRO ch;
  if (excluirElemDequeFim(d, &ch)) printf("Elemento %i excluido corretamente da entrada 2.\n",ch.chave);
  else printf("Nao foi possivel excluir elemento entrada 2 - deque vazio.\n");
}


void exibir1(DEQUE* d){
  exibirDequeInicio(d);
}

void exibir2(DEQUE* d){
  exibirDequeFim(d);
}

void meuLog(DEQUE* d){
  printf("Numero de elementos no deque: %i.\n",tamanho(d));
  printf("Tamanho do deque (em bytes): %i.\n",tamanhoEmBytes(d));
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1, na entrada 1\n");
  printf("   j <chave1>: inserir elemento com chave=chave1, na entrada 2\n");
  printf("   e : excluir elemento com chave=chave1, na entrada 1\n");
  printf("   f : excluir elemento com chave=chave1, na entrada 2\n");
  printf("   o : imprimir deque a partir da entrada 1\n");
  printf("   p : imprimir deque a partir da entrada 2\n");
  printf("   d : destruir (zerar) lista\n");
  printf("   l : exibir log de utilizacao do deque\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   1 : exibir a chave e o endereco do primeiro elemento, entrada 1\n");
  printf("   2 : exibir a chave e o endereco do primeiro elemento, entrada 2\n");
  printf("   q : sair\n");
}

void destruir(DEQUE* d){
     reinicializarDeque(d);
     printf("Deque zerado.\n");
}

int main(){
  DEQUE deque;
  inicializarDeque(&deque);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir1(&deque); break;
      case 'j' : inserir2(&deque); break;
      case 'e' : excluir1(&deque); break;
      case 'f' : excluir2(&deque); break;
      case 'o' : exibir1(&deque); break;
      case 'p' : exibir2(&deque); break;
      case 'd' : destruir(&deque); break;
      case 'l' : meuLog(&deque); break;
      case 'h' : help(); break;
      case '1' : exibirPrimeiro1(&deque); break;
      case '2' : exibirPrimeiro2(&deque); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
