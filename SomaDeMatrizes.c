//MATRÍCULA: 20221045050036
//NOME: Ana Késia Araújo Gomes
//USUÁRIO: Sylph42

#include <stdio.h>
#include <stdlib.h>


//receber tam da matriz.
//receber conteúdo da matriz
//multiplicar por X, x variando 0,1, 11 vezes.
//imprimir o resultados

int main() {
int linha, coluna, X, tam, Tam;

printf("insira a quantidade de linhas:\n");
scanf ("%d", &tam);
printf("insira a quantidade de linhas:\n");
scanf ("%d", &Tam);

int m[tam][Tam];
int n[tam][Tam];
int matriz[tam][Tam];

for ( linha=0; linha<tam; linha++ )
  for ( coluna=0; coluna<Tam; coluna++ )
  {
     printf ("\nElemento[%d][%d] = ", linha, coluna);
     scanf ("%d", &m[ linha ][ coluna ]);
  }

for ( linha=0; linha<tam; linha++ )
  for ( coluna=0; coluna<Tam; coluna++ )
  {
      printf ("\nElemento[%d][%d] = ", linha, coluna);
     scanf ("%d", &n[ linha ][ coluna ]);
  }

for(X=0; X<=10;X++){
for ( linha=0; linha<tam; linha++){
    for( coluna = 0 ; coluna < Tam; coluna++){
           float  t = 0.1 * X;

        matriz[linha][coluna] = (1-t)*m[linha][coluna] + t*n[linha][coluna];
        printf("%i   ", matriz[linha][coluna]);

      }
printf("\n");
    }
  printf("\n");
  }
}
