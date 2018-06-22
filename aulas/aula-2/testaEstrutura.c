#include <stdio.h>
#include <malloc.h>

typedef struct{
  int c1;
  int c2;
} TESTE, *PONT;

PONT copiar(TESTE t1){
	PONT x = (PONT) malloc(sizeof(TESTE));
	*x = t1;
	return x;
}

int main(){
	TESTE y;
	y.c1 = 10;
	y.c2 = 22;
	PONT w = copiar(y);
	printf("c1: %i, c2: %i\n", w->c1, w->c2);
	return 0;
}

/*
c1: 10, c2: 22
*/
