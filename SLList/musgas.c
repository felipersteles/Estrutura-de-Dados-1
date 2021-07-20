
#include <stdlib.h>
#include <stdio.h>
#include "musgas.h"
#include "SLL.h"

int cmpNome(void* a, void* b)
{
    char *pa;
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

int cmpArtista(void* a, void* b)
{
    musicas *pa;
    char *pb;

    pa = (musicas*) a;
    pb = (char*) b;

    if(strcmp(pa->artista,pb)==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
