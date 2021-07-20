
#ifndef MUSGAS_H
#define MUSGAS_H

typedef struct _MUSICAS_{

    char nome[50];
    char artista[50];
    char album[50];
    int minutos;
    int segundos;
    float avaliacao;

}musicas;

int cmpNome(void* a,void* b);
int cmpAlbum(void* a,void* b);

#endif // MUSGAS_H
