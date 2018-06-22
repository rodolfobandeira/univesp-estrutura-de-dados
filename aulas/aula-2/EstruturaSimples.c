#include <stdio.h>
#define alturaMaxima 225

typedef struct
{
  int peso;   // peso em quilogramas
  int altura; // altura em centimetros
} PesoAltura;

int main() {
  int x;
  PesoAltura pessoa1;
  pessoa1.peso = 80;
  pessoa1.altura = 185;

  printf("Peso: %i, Altura %i. ", pessoa1.peso, pessoa1.altura);
  if (pessoa1.altura>alturaMaxima) {
    printf("Altura acima da maxima.\n");
  }
  else printf("Altura abaixo da maxima.\n");

  printf("%p %p %p\n", &x, &pessoa1, &(pessoa1.altura));
 
  return 0;
}

/*
Peso: 80, Altura 185. Altura abaixo da maxima.
0x7ffc84b3daec 0x7ffc84b3daf0 0x7ffc84b3daf4
*/
