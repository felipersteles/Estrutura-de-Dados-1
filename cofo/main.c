
#include<stdio.h>
#include<stdlib.h>
#include"cofo.h"

int main() {

    int qtdC;
    printf("COMPETICAO DE CARROS REBAIXADOS\n\nInforme a quantidade de participantes: ");
    scanf("%i",&qtdC);

    cofo *cf = cCreate(qtdC);

    int aux; //auxiliares

    Carros *vet; //cria vetor de carros rebaixados

    //variaveis

    int loop=1;

    while(loop!=0) {
        printf("\n[1]Adicionar um carro\n[2]Buscar um carro\n[3]Remover carro\n[0]Sair\nInsira a opcao: ");

        int menu;

        scanf("%i",&menu);

        switch(menu) {

        case 1:

            vet = (Carros*)malloc(sizeof(Carros));
            if(vet!=NULL) {
                printf("\nInsira a marca do carro: ");
                scanf("%s",&(vet->modelo));
                setbuf(stdin, NULL);

                printf("Insira o modelo do carro: ");
                scanf("%s",&(vet->marca));
                setbuf(stdin, NULL);

                printf("Insira o ano do carro: ");
                scanf("%i",&(vet->ano));
                setbuf(stdin, NULL);

                printf("Insira o consumo do carro: ");
                scanf("%f",&(vet->consumo));
                setbuf(stdin, NULL);

                printf("Insira o aro do Pneu: ");
                scanf("%i",&(vet->aroPneu));
                setbuf(stdin, NULL);
            }

            cInsert(cf,(void*)vet);
            printf("%d",cf->nelms);

            break;
        case 0:

            loop=0;

            break;
        }
    }
    return 0;
}
