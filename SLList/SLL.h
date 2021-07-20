
#ifndef SLLIST_H
#define SLLIST_H

#define TRUE 1
#define FALSE 0

typedef struct _SLLNODE_{ //Lista simplesmente encadeada
    void* data;
    struct _SLLNode_* next;

}SLNode;

typedef struct _SLLIST_{ //Cria o pai da lista
    SLNode* first;
    SLNode* current;
}SLList;

//---------funcoesdalista---------

SLList* SLCreate();

int SLLDestroy(SLList *l);

int SLLInsertFirst(SLList *l,void* data);

int SLLInsertLast(SLList *l,void* data);

void* SLLQuery(SLList *l,void* key,int (*cmp)(void*,void*));

void* SLLRemoveSpec(SLList *l,void* key, int (*cmp)(void*,void*));

int SLLIsEmpty(SLList *l);

void* SLLRemoveFirst(SLList *l); //auxilia na limpeza da lista



#endif // SLLIST_H
