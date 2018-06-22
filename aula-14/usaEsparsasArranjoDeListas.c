/* Arquivo usaEsparsasArranjoDeListas.c */
#include <malloc.h>
#include <stdio.h>
#include "esparsasArranjoDeListas.c"

void LeMatriz(MATRIZ *a) {
/* Inicializa e lê os elementos de 'a' */
  int m,n,i,j;
  float x;
  scanf("%d %d\n",&m,&n);
  inicializarMatriz(a,m,n);
  printf("Matriz %i x %i inicializada\n", m, n);
  do {
   scanf("%d %d %f\n",&i,&j,&x);
   if (i>=0)
     AtribuiMatriz(a,i,j,x);
     printf("Valor inserido (%i,%i,%f)\n",i,j,x);
     //exibirMatrizLinhas(a);
  } while (i>=0);
}

void EscreveMatriz(MATRIZ* a) {
  int m,n,i,j;
  float x;
  OrdemMatriz(a,&m,&n);
  printf("%3d %3d\n",m,n);
  for (i=0;i<m;i++)
    for (j=0;j<n;j++) {
      x = ValorMatriz(a,i,j);
      if (x!=0.0) printf("%3d %3d %6.1f\n",i,j,x);
    }
      
}

float Eficiencia(MATRIZ* a) {
/* Calcula a eficiência da representação esparsa em
   comparação com a usual, em percentagem */
  int m,n;
  OrdemMatriz(a,&m,&n);
  if (m*n!=0)
    return 100.0*tamanhoEmBytes(a)
                  /(m*n*sizeof(float));
  else
    return 0;
}

int main() {
  MATRIZ a,b;
  printf("Lendo a primeira matriz\n");
  LeMatriz(&a);
  printf("Escrevendo a primeira matriz\n");
  EscreveMatriz(&a);
  printf("Eficiencia: %6.1f%%\n",Eficiencia(&a));
  printf("Lendo a segunda matriz\n");
  LeMatriz(&b);
  printf("Escrevendo a segunda matriz\n");
  EscreveMatriz(&b);
  printf("Gasto de memoria: %6.1f%%\n",Eficiencia(&b));

  MATRIZ* c = SomaMatriz(&a,&b);
  if (c==NULL) 
    printf("Soma de matrizes incompativeis\n");
  else {
    printf("Exibindo listas ligadas\n");
    exibirMatrizLinhas(c);
    printf("Escrevendo matriz soma\n");
    EscreveMatriz(c);
    printf("Gasto de memoria: %6.1f%%\n",Eficiencia(c));
    LiberaMatriz(c);
    LiberaMatriz(c);
    free(c);
  }
  LiberaMatriz(&a);
  LiberaMatriz(&b);
  return 0;
}
