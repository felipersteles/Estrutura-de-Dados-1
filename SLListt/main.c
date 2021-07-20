
#include<stdlib.h>
#include<stdio.h>
#include "SLL.h"
#include "musgas.h"

void preenchemusica(musicas* musica);
void preenchemusica(musicas* musica);

int main(){
    SLList* l;
    l = SLCreate();

    musicas *inserir, *buscar, *remover;
    int stat; //verifica as funcoes
    char busca[50]; //auxiliar de busca

    int menu,case1,case2,loop = -1;
    while(loop!=0) {

        printf("[1]Inserir na lista\n[2]Buscar na lista\n[3]Remover da lista\n[0]Sair\nEscolha a opcao: ");
        scanf("%d",&menu);
        setbuf(stdin, NULL);

        switch(menu) {
        case 0:
            loop = 0;
            break;

        case 1:
            inserir = (musicas*)malloc(sizeof(musicas));
            preenchemusica(inserir);

            printf("\n[1]Inserir no inicio\n[2]Inserir no final\nEscolha a opcao: ");
            scanf("%d",&case1);
            setbuf(stdin, NULL);

            if(case1 == 1) {
                stat = SLLInsertFirst(l,(void*)inserir);
                if(stat==TRUE)
                    printf("\nMusica inserida!\n");
                else
                    printf("\nERRO! Musica nao inserida!\n");
            } else {
                stat = SLLInsertLast(l,(void*)inserir);
                if(stat==TRUE)
                    printf("\nMusica inserida!\n");
                else
                    printf("\nERRO! Musica nao inserida!\n");
            }
            break;

        case 2:
            printf("\n[1]Buscar por nome\n[2]Buscar por album\nEscolha a opcao: ");
            scanf("%d",&case2);
            setbuf(stdin, NULL);

            if(case2==1){
                printf("\nDigite o nome da musica: ");
                gets(busca);
                setbuf(stdin, NULL);

                buscar = SLLQuery(l,busca,cmpNome);
                if(buscar!=NULL){
                    printf("\n\nMusica encontrada:\n");
                    preenchemusica(buscar);
                }else
                    printf("\n\nERRO!Musica nao encontrada.");
            }else{
            }

            break;
        }
    }
}

void preenchemusica(musicas* musica) {
    printf("\nNome da musica: ");
    gets(musica->nome);
    setbuf(stdin, NULL);

    printf("\nNome da artista: ");
    gets(musica->artista);
    setbuf(stdin, NULL);

    printf("Nome do album: ");
    gets(musica->album);
    setbuf(stdin, NULL);

    printf("Duracao em minutos: ");
    scanf("%d",&musica->minutos);
    setbuf(stdin, NULL);

    printf("segundos: ");
    scanf("%d",&musica->segundos);
    setbuf(stdin, NULL);

    printf("Avaliacao(0 a 1): ");
    scanf("%f",&musica->avaliacao);
    setbuf(stdin, NULL);
}

void printamusica(musicas* musica){
    printf("Nome da musica: %s\nArtista: %s\nNome do album: %s\nDuracao: %d:%d\nAvaliacao: %f",
           musica->nome,musica->artista,musica->album,musica->minutos,musica->segundos,musica->avaliacao);
}
