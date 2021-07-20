
#include<stdio.h>
#include<stdlib.h>
#include "pilhafila.h"

//------------------PILHA----------------------
Stack *stkCreate(int max) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s!=NULL) {
        s->elms = (void**)malloc(sizeof(void*)*max);
        if(s->elms != NULL) {
            s->maxElms = max;
            s->top = -1;
            return s;
        }
    }
    return NULL;
}
int stkDestroy(Stack *s) {
    if(s!=NULL) {
        if(s->top < 0) {
            free(s->elms);
            free(s);
            return TRUE;
        }
    }
    return FALSE;
}
int stkPush(Stack *s,void* elm) {
    if(s!=NULL) {
        if( s->top < s->maxElms - 1 ) {
            s->top++;
            s->elms[s->top] = elm;
            return TRUE;
        }
    }
    return FALSE;
}

void* stkPop(Stack *s) {
    void* aux;

    if(s!=NULL) {
        if(s->top >= 0) {
            aux = s->elms[s->top];
            s->top--;
            return aux;
        }
    }
    return NULL;
}

void* stkTop(Stack *s) {
    if(s!=NULL) {
        if(s->top >= 0) {
            return s->elms[s->top];
        }
    }
    return NULL;
}

int stkIsEmpty(Stack *s) {
    if(s!=NULL) {
        if(s->top>=0) {
            return FALSE;
        }
    }
    return TRUE;
}

//------------------FILA----------------------

Queue* qCreate(int max) {
    Queue* q;
    if(max>0) {
        q = (Queue*)malloc(sizeof(Queue));
        if(q!=NULL) {
            q->elms = (void**)malloc(sizeof(void*)*max);
            if(q->elms!=NULL){
                q->beg = -1;
                q->end = -1;
                q->maxElms = max;
                return q;
            }
            free(q);
        }
    }
    return NULL;
}

int qDestroy(Queue* q){
    if(q!=NULL){
        if(q->end<0){
            free(q->elms);
            free(q);
            return TRUE;
        }
    }
    return FALSE;
}

int qEnqueue(Queue* q,void* elm){
    if(q!=NULL){
        if(q->end < q->maxElms){
            q->end++;
            q->elms[q->end] = elm;
            return TRUE;
        }
    }
    return FALSE;
}

void* qDequeue(Queue* q){
    void* aux;
    if(q!=NULL){
        if(q->end >= 0){
            aux = q->elms[q->beg];
            for(int i = q->beg;i<q->end;i++){
                q->elms[i]=q->elms[i+1];
            }
            q->beg++;
            return aux;
        }
    }
    return NULL;
}

//-------------FILA CIRCULAR--------------
int qIncrementoCircular(int i,int max){
    if(i==max-1)
        return 0;
    else
        return i+1;
}

int qDecrementoCircular(int i,int max){
    if(i==0)
        return max - 1;
    else
        return i - 1;
}

Queue* qcCreate(int max){
    Queue* q;
    if(max>0){
        q = (Queue*)malloc(sizeof(Queue));
        if(q!=NULL){
            q->elms = (void**)malloc(sizeof(void*)*max);
            if(q->elms!=NULL){
                q->maxElms = max;
                q->beg = 0;
                q->end = -1;
                q->nElms = 0;
                return q;
            }
            free(q);
        }
    }
    return FALSE;
}
