#include <stdio.h>
#include <stdlib.h>

int **MultiplicaMatriz(int **matrizA,int linhasA,int colunasA,
                       int **matrizB,int linhasB,int colunasB) {

    int i,j,k;

    int**resposta;

    resposta = malloc(linhasA*sizeof(int*));
    for(i=0; i<linhasA; i++) {
        resposta[i] = malloc(colunasB*sizeof(int*));
    }

    if(colunasA==linhasB) {
        for(i=0; i<linhasA; i++) {
            for(j=0; j<colunasB; j++) {
                resposta[i][j]=0;
                for(k=0; k<(colunasA); k++) {
                    resposta[i][j]=(resposta[i][j])+(matrizA[i][k]*matrizB[k][j]);
                }
            }
        }

        return resposta;
    } else {
        printf("\nNao eh possivel multiplicar as matrizes\n");

        return NULL;
    }
}

void printM(int **matriz, int linha, int coluna) {
    int i,j;

    for(i=0; i<linha; i++) {
        printf("%c",'\n');
        for(j=0; j<coluna; j++) {
            printf("%d%c",matriz[i][j],' ');
        }
    }
}

void printV(int *vetor,int n)
{
    int i;

    printf("\nVetor V: ");

    for(i=0; i<n; i++)
    {
        printf("%d%c",vetor[i],' ');
    }
}

void escreveM(int**matriz,int linha, int coluna){

    int i,j;

    for(i=0; i<linha; i++) {
        for(j=0; j<coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void escreveMatVet(int *matvet,int linha, int coluna){

    int i,j;

    for(i=0; i<linha; i++) {
        for(j=0; j<coluna; j++) {
            scanf("%d", &matvet[(i*coluna) + j]);
        }
    }
}
