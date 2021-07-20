
#include <stdio.h>
#include <stdlib.h>
#include "teles.h"

int **mattransposta(int **matriz,int n, int m);

int **MultAxBT(int **matrizA,int linhasA,int colunasA,
               int **matrizB,int linhasB,int colunasB);

int *matElemDiagPrin(int *va, int n, int m);

int *matElemlinhaL(int *va,int n,int m,int l);

int *matElemColunaK(int *va,int n,int m,int k);

int *matmultAxBT(int*A,int n,int m,
                 int *B,int p,int q);

int main() {
    int n,m,p,q;
    printf("Digite n,m,p,q:\n");
    scanf("%d" "%d" "%d" "%d",&n,&m,&p,&q);

    int *A;
    A = (int*) malloc((n*m)*sizeof(int));
    printf("Digite A:\n");
    escreveMatVet(A,n,m);

    int *B;
    B = (int*) malloc((p*q)*sizeof(int));
    printf("Digite B:\n");
    escreveMatVet(B,p,q);

    int *diag;

    diag = matElemColunaK(B,p,q,2);

    printf("\n");

    printV(diag,p);

    printf("\n");

    int *C;
    C = matmultAxBT(A,n,m,B,p,q);

    printV(C,(n*p));

    return 0;
}

int **mattransposta(int **matriz,int n, int m) {

    int i,j;

    int trans[n][m];

    if(n==m) {
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                trans[i][j] = matriz[j][i];
            }
        }
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                matriz[i][j] = trans[i][j];
            }
        }

        return matriz;
    } else {
        printf("N diferente de M");
    }
}

int **MultAxBT(int **matrizA,int linhasA,int colunasA,
               int **matrizB,int linhasB,int colunasB) {

    int i,j,k;

    int**resposta;

    resposta = malloc(linhasA*sizeof(int*));
    for(i=0; i<linhasA; i++) {
        resposta[i] = malloc(linhasB*sizeof(int*));
    }

    if(colunasA==colunasB) {
        for(i=0; i<linhasA; i++) {
            for(j=0; j<linhasB; j++) {
                resposta[i][j]=0;
                for(k=0; k<(colunasA); k++) {
                    resposta[i][j]=(resposta[i][j])+(matrizA[i][k]*matrizB[j][k]);
                }
            }
        }

        return resposta;
    } else {
        printf("\nNao eh possivel multiplicar as matrizes\n");

        return NULL;
    }
}

int *matElemDiagPrin(int *va, int n, int m) {

    int i,j; //auxiliares

    int qtdD; //quantidade de termos na diagonal

    if(n<m) {
        qtdD = n;
    } else {
        qtdD = m;
    }

    int *diagonal;
    diagonal = (int*)malloc(qtdD*sizeof(int));

    int k = 0; //faz a contagem do vetor

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(i==j) {
                diagonal[k] = va[(i*m)+j];
                k++;
            }
        }
    }

    return diagonal;

}

int *matElemlinhaL(int *va,int n,int m,int l) {

    int i = l,j;

    int *linhaL = (int*)malloc(m*sizeof(int));

    for(j=0; j<m; j++) {
        linhaL[j] = va[(i*m)+j];
    }

    return linhaL;
}

int *matElemColunaK(int *va,int n,int m,int k) {

    int i,j = k;

    int *colunaK = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++) {
        colunaK[i] = va[(i*m)+j];
    }

    return colunaK;
}

int *matmultAxBT(int*A,int n,int m,
                 int *B,int p,int q) {
    int i,j,k;

    int *resposta = malloc((n*p)*sizeof(int*));

    if(m==q) {
        for(i=0; i<n; i++) {
            for(j=0; j<p; j++) {
                resposta[(i*p) + j]=0;
                for(k=0; k<m; k++) {
                    resposta[(i*p)+j]+=(A[(i*m)+k]*B[(j*q)+k]);
                }
            }
        }

        return resposta;
    } else {
        printf("\nNao eh possivel multiplicar as matrizes\n");

        return NULL;
    }
}

