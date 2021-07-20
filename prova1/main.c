
#include<stdio.h>
#include<stdlib.h>
#include "pilhafila.h"

int MaiorElemLinha(int *v,int N, int M,int k);

int EPalindromo(Stack* s);

void main(void) {

    Stack* s;
    s = stkCreate(200);
    if(s!=NULL) {

        stkPush(s,(void*)"o");
        stkPush(s,(void*)"g");
        stkPush(s,(void*)"a");
        stkPush(s,(void*)"l");
        stkPush(s,(void*)"o");
        stkPush(s,(void*)"a");
        stkPush(s,(void*)"m");
        stkPush(s,(void*)"a");
        stkPush(s,(void*)"o");
        stkPush(s,(void*)"l");
        stkPush(s,(void*)"a");
        stkPush(s,(void*)"g");
        stkPush(s,(void*)"o");

        if(EPalindromo(s)==TRUE)
            printf("foi");
        else
            printf("nao foi");

    }
}

int EPalindromo(Stack* s) {
    int i,tam=0,cont=0;
    void* c;
    Stack* aux;
    Stack* aux2;
    if(s!=NULL) {
        while(s->elms[tam]!='\0') {
            tam++;
        }
        aux = stkCreate(s->maxElms);
        if(aux!=NULL) {
            for(i=0; i<tam; i++) {
                stkPush(aux,s->elms[i]);
            }
            i=0;
            aux2=stkCreate(s->maxElms);
            if(aux2!=NULL) {
                while(stkIsEmpty(aux)!=TRUE) {
                    c = stkPop(aux);
                    stkPush(aux2,c);
                    i++;
                }
                for(i=0; i<tam; i++) {
                    if(aux2->elms[i] == s->elms[i])
                        cont++;
                }
            }
        }
        if(cont==tam)
            return TRUE;
    }
    return FALSE;
}

int MaiorElemLinha(int *v,int N, int M,int k) {
    int j,maior = v[k*M];
    if(v!=NULL) {
        for(j=0; j<M; j++) {
            if(v[ (k*M)+ j ]>maior)
                maior = v[ (k*M)+ j ];
        }
        return maior;
    }
    return NULL;
}
