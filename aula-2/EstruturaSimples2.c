#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225

typedef struct
{
  int peso;   // peso em quilogramas
  int altura; // altura em centimetros
} PesoAltura;

int main() {
  int x;
  PesoAltura* pessoa1;
  printf("Valor inicial do endereco: %p\n", pessoa1);
  pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
  printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura);
  pessoa1->peso = 80;
  pessoa1->altura = 185;

  printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura);
  if (pessoa1->altura>alturaMaxima) {
    printf("Altura acima da maxima.\n");
  }
  else printf("Altura abaixo da maxima.\n");

  printf("Enderecos: %p %p %p\n", &x, &pessoa1, pessoa1);
 
  return 0;
}

/*
Valor inicial do endereço: (nil)
Peso: 0, Altura 0. Peso: 80, Altura 185. Altura abaixo da maxima.
Endereços: 0x7ffde9c33f74 0x7ffde9c33f78 0x1f50010
*/
