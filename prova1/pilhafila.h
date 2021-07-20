
#ifndef PILHAEFILA_H
#define PILHAEFILA_H

#define TRUE 1
#define FALSE 0


typedef struct _stack_{
    int maxElms;
    int top;
    void** elms;

}Stack;

Stack *stkCreate(int max);

int stkDestroy(Stack *s);

int stkPush(Stack *s,void *elm);

void* stkPop(Stack *s);

void* stkTop(Stack *s);

int stkIsEmpty(Stack *s);

//-----------FILA------------

typedef struct _queue_{

    int beg;
    int end;
    int maxElms;
    void* *elms;

    int nElms; //para fila circular

}Queue;

Queue* qCreate(int max);

int qDestroy(Queue* q);

int qEnqueue(Queue* q,void* elm);

void* qDequeue(Queue* q);

//-------------FILA CIRCULAR--------------

int qIncrementoCircular(int i,int max);

int qDecrementoCircular(int i,int max);

Queue* qcCreate(int max);

int qcDestroy(Queue* q);

int qcEnqueue(Queue* q, void* elm);

void* qcDequeue(Queue* q);

#endif // _pilhafila_

