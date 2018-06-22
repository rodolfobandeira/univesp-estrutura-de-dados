#include <stdio.h>

int main() {
  int matriz1[2][3];
  int matriz2[2][3];

  matriz1[0][0] = 1;
  matriz1[0][1] = 2;
  matriz1[0][2] = 3;
  matriz1[1][0] = 4;
  matriz1[1][1] = 5;
  matriz1[1][2] = 6;

  matriz2[0][0] = 11;
  matriz2[0][1] = 12;
  matriz2[0][2] = 13;
  matriz2[1][0] = 14;
  matriz2[1][1] = 15;
  matriz2[1][2] = 16;

  int matriz3[2][3];

  int i, j;
  for (i=0;i<2;i++)
    for (j=0;j<3;j++) matriz3[i][j] = matriz1[i][j] + matriz2[i][j];

  for (i=0;i<2;i++){
    for (j=0;j<3;j++){
      printf("%i ",matriz3[i][j]);
    }
    printf("\n");
  }

  return 0;
}

/* SAIDA:
12 14 16 
18 20 22 
*/
