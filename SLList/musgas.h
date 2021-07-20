
#ifndef MUSGAS_H
#define MUSGAS_H

typedef struct _MUSICAS_{

    char nome[50];
    char artista[51];
    char album[52];
    int minutos;
    int segundos;
    float avaliacao;

}musicas;

int cmpNome(void* a,void* b);
int cmpArtista(void* a,void* b);

#endif // MUSGAS_H
