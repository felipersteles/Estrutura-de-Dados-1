
#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"
#include <string.h>

cofo *cCreate (int max)
{
    cofo *c;

    if(max>0)
    {
        c = (cofo*)malloc(sizeof(cofo));
        c->nelms = (void**) malloc(sizeof(void*)*max);
        c->maxelms = max;
        c->nelms = 0;
        return c;
    }
    return NULL;
}

int cDestroy(cofo* c) //SOMENTE SE O COFO ESTIVER VAZIO
{
    if(c != NULL)
    {
        if(c->nelms == 0)
        {
            if(c->elms != NULL)
            {
                free(c->elms);
                free (c);
            }

            return TRUE;
        }
    }
    return FALSE;

}

int cInsert(cofo* c,void *elm)
{
    if(c!=NULL)
    {
        if(c->elms != NULL && (c->nelms) < (c->maxelms))
        {
            c->elms[c->nelms] = elm;
            c->nelms++;

            return TRUE;
        }
    }
    return FALSE;


}

void *cQuery(cofo *c,void *key, int(*cmp)(void*,void*))
{
    int i=0;
    void *elm;

    if (c!=NULL && c->elms!=NULL)
    {
        if(c->nelms>0)
        {
            while(i<c->nelms && cmp(key, c->elms[i])!=TRUE)
            {
                i++;
            }
            if(cmp(key, c->elms[i])==TRUE)
            {

                elm = c->elms[i];

                return  (Carros*)elm;
            }
        }
    }
    return NULL;
}

/*int cSearch( cofo *c, int key )
{
	int i;
	if (( c == NULL ) ){	  return -1;	 }
	for(i=0;i<c->numItens;i++) {
		if (c->itens[i] == key){
			return c->items[i];
		}
	}
} //fim de colBuscar */

void * cRemove (cofo*c, void* key, int(*cmp)(void*, void*))
{
    int stat=FALSE, i=0;
    void *elm;

    if(c!=NULL && c->elms!=NULL)
    {
        if (c->nelms>0)
        {
            stat=cmp(key, c->elms[i]);
            while(i<c->nelms && stat!=TRUE)
            {
                i++;
                stat=cmp(key, c->elms[i]);
            }
        }
        if(stat==TRUE)
        {
            elm = c->elms[i];
            for( ; i<c->nelms-1; i++)
            {
                c->elms[i] = c->elms[i+1];
            }
            c->nelms--;
            return elm;
        }
    }

    return NULL;
}

int cmpChar(void* a, void* b)
{
    int *pa;
    Carros *pb;

    pa = (int*) a;
    pb = (Carros*) b;
    if(pb->modelo == *pa)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpInt(void* a, void* b)
{
    int *pa;
    Carros *pb;

    pa = (char*) a;
    pb = (Carros*) b;

    if(strcmp(pa, pb->aroPneu)==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
