
#ifndef COFO_H
#define COFO_H

#define TRUE 1
#define FALSE 0

typedef struct _cofo_{
    int maxelms;
    int nelms;
    void* *elms;
}cofo;

typedef struct _carros_{
    char marca[50];
    char modelo[50];
    int aroPneu;
    float consumo;
    int ano;
}Carros;

cofo *cCreate (int max);

int cDestroy (cofo *c);

int cInsert(cofo *c,void *elm);

void* cRemove(cofo* c, void* key, int(*cmp)(void*, void*));

void* cQuery(cofo* c, void* key, int(*cmp)(void*, void*));

int cmp(void* a, void* b);

int cmpChar(void* a, void* b); //função de Char

int cmpInt(void* a, void* b); //função de Int

#endif
