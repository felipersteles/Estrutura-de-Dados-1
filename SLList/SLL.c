
#include <stdlib.h>
#include <stdio.h>
#include "SLL.h" //inclui biblioteca de listas
#include "musgas.h" //inclui biblioteca de "QUALQUER TIPO"

SLList* SLCreate() {
    SLList* l;
    l = (SLList*)malloc(sizeof(SLList));
    if(l!=NULL) {
        l->first = NULL;
        l->current = NULL;
        return l;
    }
    return NULL;
}

int SLLDestroy(SLList* l) {
    if(l!=NULL) {
        if(l->first==NULL) {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

int SLLIsEmpty(SLList *l) {
    if(l!=NULL){
        if(l->first!=NULL) {
            return FALSE;
        }
    }
    return TRUE;
}

int SLLInsertFirst(SLList* l, void* data) {
    SLNode* newnode;
    if(l!=NULL) {
        newnode = (SLNode*)malloc(sizeof(SLNode));
        if(newnode!=NULL) {
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int SLLInsertLast(SLList* l,void* data) {
    SLNode *last; //ponteiros
    SLNode *newnode; //novo no
    if(l!=NULL) {
        newnode = (SLNode*)malloc(sizeof(SLNode));
        if(newnode != NULL) {
            newnode->data = data;
            newnode->next = NULL;
            if(l->first==NULL) {
                l->first = newnode;
            } else {
                last = l->first;
                while(last->next != NULL) {
                    last = last->next;
                }
                last->next = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

void* SLLQuery(SLList* l,void* key,int (*cmp)(void*,void*)) {
    SLNode* spec;
    int stat;

    if(l!=NULL) {
        if(l->first!=NULL) {
            spec = l->first;
            stat = cmp(spec->data,key);
            while(stat!=TRUE && spec->next!=NULL) {
                spec = spec->next;
                stat = cmp(spec->data,key);
            }
            if(stat==TRUE) {
                return spec->data;
            }
        }
    }
    return NULL;
}

void* SLLRemoveSpec(SLList *l,void* key, int (*cmp)(void*,void*)) {
    SLNode *spec, *prev;
    int stat;
    void* data;
    if(l!=NULL) {
        if(l->first!=NULL) {
            prev = NULL;
            spec = l->first;
            stat = cmp(spec->data,key);
            while(stat!=TRUE && spec->next!=NULL) {
                prev=spec;
                spec = spec->next;
                stat = cmp(spec->data,key);
            }
            if(stat==TRUE) {
                data = spec->data;
                if(prev!=NULL)
                    prev->next = spec->next;
                else
                    l->first = spec->next;
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

void* SLLRemoveFirst(SLList *l){
    SLNode *aux;void* data;
    if(l!=NULL){
        if(l->first!=NULL){
            aux = l->first;
            data = aux->data;
            l->first = aux->next;
            free(aux);
            return data;
        }
    }
    return NULL;
}
