#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2

double **initialArray()
{ 
  int i,j;
  double **res;
  res = new double * N ;
  for(i = 0; i<2*N; i++)
	  res[i] = new double N;

  for(i = 0; i<2*N; i++)
  for(j = 0; j<2*N; j++)
  res[i][j] = 0.1*(rand()%50);

  return res;
}

double **tearOff(double **a, int row, int col)
{ 
  int i,j;
  double **res = (double **)malloc(N*sizeof(double*));
  for(i = 0; i<N; i++)
  res[i] = (double*) malloc(N*sizeof(double));

  for(i =0; i<N; i++)
  for(j = 0; j<N; j++)
  res[i][j] = a[i+row][j+col];

  return res;
}

void putTogether(double **a, double **piece, int row, int col)
{ 
  int i,j;

  for(i = 0; i<N; i++)
  for(j = 0; j<N; j++)
  a[i+row][j+col] = piece[i][j];
}

void showResult(double **a)
{ 
  int i,j;

  for(i = 0; i<2*N; i++)
  { 
    for(j = 0; j<2*N; j++)
    printf("%5.1lf", a[i][j]);
    printf("\n");
  }
}


int main()
{ 
  double **arr, **ul, **ur, **dl, **dr;
  srand((unsigned int) time (NULL));

  arr = initialArray();
  printf("inicializaciya:\n");
  showResult(arr);

//óêàçàòåëè íà êàæäóþ èç ÷åòâåðòåé
ul = tearOff(arr, 0, 0); //âåðõíÿÿ ëåâàÿ ÷åòâåðòü
ur = tearOff(arr, 0, N); //âåðõíÿÿ ïðàâàÿ
dl = tearOff(arr, N, 0); //íèæíÿÿ ëåâàÿ
dr = tearOff(arr, N, N); //íèæíÿÿ ïðàâàÿ

//ïåðåñîáèðàåì ìàòðèöó
putTogether(arr, dl, 0, 0); //íèæíÿÿ ïðàâàÿ -> âåðõíÿÿ ëåâàÿ
putTogether(arr, ul, 0, N); //íèæíÿÿ ëåâàÿ -> âåðõíÿÿ ïðàâàÿ
putTogether(arr, dr, N, 0); //âåðõíÿÿ ïðàâàÿ -> íèæíÿÿ ëåâàÿ
putTogether(arr, ur, N, N); //âåðõíÿÿ ëåâàÿ -> íèæíÿÿ ïðàâàÿ

printf("\n\nmasiv posle peremesheniya\n");
showResult(arr);

free(arr);
free(ul); free(ur); free(dl); free(dr);

getchar();
return 0;
}
