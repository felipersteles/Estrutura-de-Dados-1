
#include <stdlib.h>
#include <stdio.h>
#include "SLL.h" //inclui biblioteca de listas

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
        if(l->first!=NULL) {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
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

void* SLLQuery(SLList* l,void* key,int (*cmp)(void*,void*)){
    SLNode* spec;
    int stat;

    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            stat = cmp(spec->data,key);
            while(stat!=TRUE && spec->next!=NULL){
                spec = l->first;
                stat = cmp(spec->data,key);
            }
            if(stat==TRUE){
                return spec->data;
            }
        }
    }
    return NULL;
}
