
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include "SLL.h"
#include "musgas.h"

void preenchemusica(musicas* musica);
void printamusica(musicas* musica);
void endl();

int main() {
    SLList* l = SLCreate();

    musicas *inserir, *buscar, *remover; //auxiliares dos menus

    int stat; //verifica as funcoes

    char busca1[50],busca2[50],remove1[50],remove2[50],limpar[3]; //auxiliar de busca na lista

    int menu,case1,case2,case3,loop = -1; //auxiliares
    while(loop!=0) {

        printf("[1]Inserir na lista\n[2]Buscar na lista\n[3]Remover da lista\n[4]Destroir a lista\n[0]Sair\nEscolha a opcao: ");
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
                    printf("\nMusica inserida!\n\n");
                else
                    printf("\nERRO! Musica nao inserida!\n\n");
            } else {
                stat = SLLInsertLast(l,(void*)inserir);
                if(stat==TRUE)
                    printf("\nMusica inserida!\n\n");
                else
                    printf("\nERRO! Musica nao inserida!\n\n");
            }
            break;

        case 2:
            if(l->first!=NULL) {
                printf("\nDeseja buscar por:\n[1]Nome da musica\n[2]Artista\n[0]Voltar\nEscolha a opcao: ");
                scanf("%d",&case2);
                setbuf(stdin, NULL);

                if(case2==1) {
                    printf("\nDigite o nome da musica: ");
                    gets(busca1);
                    setbuf(stdin, NULL);

                    buscar = SLLQuery(l,busca1,cmpNome);
                    if(buscar!=NULL) {
                        printf("\n\nMusica encontrada:\n");
                        printamusica(buscar);
                    } else {
                        printf("\n\nERRO! Musica nao encontrada.\n\n");
                    }

                } else if(case2 == 2) {
                    printf("\nDigite a(o) artista da musica: ");
                    gets(busca2);
                    setbuf(stdin, NULL);

                    buscar = SLLQuery(l,busca2,cmpArtista);
                    if(buscar!=NULL) {
                        printf("\n\nMusica encontrada:\n\n");
                        printamusica(buscar);
                    } else {
                        printf("\nERRO! Musica nao encontrada.\n\n");
                    }
                }  else if(case2 == 0) {
                    endl();
                    break;

                } else {
                    printf("\nOpcao invalida!\n\n");
                }
            } else {
                printf("\nERRO! Lista vazia.\n\n");
            }
            break;

        case 3:
            if(l->first!=NULL && l!=NULL) {
                printf("\nDeseja remover por:\n[1]Nome da musica\n[2]Nome do artista\nEscolha a opcao: ");
                scanf("%d",&case3);
                setbuf(stdin,NULL);

                if(case3 == 1) {
                    printf("\nDigite o nome da musica: ");
                    gets(remove1);
                    setbuf(stdin,NULL);

                    remover = SLLRemoveSpec(l,remove1,cmpNome);
                    if(remover!=NULL) {
                        printf("\nMusica removida:\n");
                        printamusica(remover);
                    } else {
                        printf("\nERRO! Musica nao removida.\n\n");
                    }
                } else if(case3 == 2) {
                    printf("\nDigite o(a) artista da musica: ");
                    gets(remove2);
                    setbuf(stdin, NULL);

                    remover = SLLRemoveSpec(l,remove2,cmpArtista);
                    if(remover!=NULL) {
                        printf("\nMusica removida:\n\n");
                        printamusica(remover);
                    } else {
                        printf("\nERRO! Musica nao removida.\n\n");
                    }
                } else if(case3 == 0) {
                    endl();
                    break;
                } else {
                    printf("\nOpcao invalida!\n\n");
                }
            } else {
                printf("\nERRO! Lista vazia.\n\n");
            }
            break;

        case 4:
            if(l->first != NULL) {
                printf("\nATENCAO! A lista nao esta vazia. Deseja esvazia-la?[S/N] ");
                scanf("%s",limpar);
                setbuf(stdin,NULL);

                if(strcmp(limpar,"s")==0) {
                    while(l->first != NULL) {
                        remover = SLLRemoveFirst(l);
                    }
                    remover = NULL;
                } else {
                    endl();
                    break;
                }
            }
            stat = SLLDestroy(l);
            if(stat==TRUE) {
                printf("\nLista destruida com sucesso! Deseja voltar ao inicio?[S/N] ");
                scanf("%s",limpar);
                setbuf(stdin,NULL);

                if(strcmp(limpar,"s")==0) {
                    l = SLCreate();
                    endl();
                    break;
                } else {
                    loop = 0;
                }
            } else
                printf("\nERRO! Lista nao destruida.\n\n");
            break;
        }
        if(l->first == NULL)
            printf("OBS: Lista vazia!\n");
    }
}

void preenchemusica(musicas* musica) {
    printf("\nNome da musica: ");
    gets(musica->nome);
    setbuf(stdin, NULL);

    printf("Nome da artista: ");
    gets(musica->artista);
    setbuf(stdin, NULL);

    printf("Nome do album: ");
    gets(musica->album);
    setbuf(stdin, NULL);

    printf("Duracao minutos e segundos: ");
    scanf("%d",&musica->minutos);
    setbuf(stdin, NULL);
    scanf("%d",&musica->segundos);
    setbuf(stdin, NULL);

    printf("Avaliacao(0 a 1): ");
    scanf("%f",&musica->avaliacao);
    setbuf(stdin, NULL);
}

void endl() {
    printf("\n");
}

void printamusica(musicas* musica) {
    printf("\nNome da musica: %s\nArtista: %s\nDuracao: %d:%d\nAvaliacao: %f\n\n",
           musica->nome,musica->artista,musica->minutos,musica->segundos,musica->avaliacao);
}
