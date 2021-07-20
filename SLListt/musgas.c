
#include <stdlib.h>
#include <stdio.h>
#include "musgas.h"
#include "SLL.h"

int cmpNome(void* a, void* b)
{
    int *pa;
    musicas *pb;

    pa = (char*) a;
    pb = (musicas*) b;

    if(strcmp(pa, pb->nome)==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int cmpAlbum(void* a, void* b)
{
    int *pa;
    musicas *pb;

    pa = (char*) a;
    pb = (musicas*) b;

    if(strcmp(pa, pb->album)==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
