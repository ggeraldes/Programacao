//
// Created by goncalo on 29/05/2023.
//

#include "GlobalFunc.h"

int menu(){
    int i;
    do{
    puts("\n1 - Tratar Paragens");
    puts("2 - Tratar Linhas");
    puts("3 - Onde quer ir?");
    puts("4 - Terminar");
    printf("\nEscolha uma opcao: ");

        if(scanf(" %d", &i)!=1){
            puts("Erro: voce nao digitou um numero inteiro.");
            fflush(stdin);
        }

    }while(i<1 || i>4);
    return i;
}

int menuParagens(){
    int i;
    do{
    puts("\n1 - Registar Paragem");
    puts("2 - Eliminar Paragem");
    puts("3 - Visualizar Paragens");
    puts("4 - Voltar");
    printf("\nEscolha uma opcao: ");

        if(scanf(" %d", &i)!=1){
            puts("Erro: voce nao digitou um numero inteiro.");
            fflush(stdin);
        }
    }while(i<1 || i>4);
    return i;
}

int menuLinhas(){
    int i;
    do{
        puts("\n1 - Registar Linha");
        puts("2 - Adicionar Paragem a Linha");
        puts("3 - Eliminar Paragem da Linha");
        puts("4 - Eliminar Linha");
        puts("5 - Visualizar Linhas");
        puts("6 - Carregar linha .txt");
        puts("7 - Voltar");
        printf("\nEscolha uma opcao: ");

        if(scanf(" %d", &i)!=1){
            puts("Erro: voce nao digitou um numero inteiro.");
            fflush(stdin);
        }
    }while(i<1 || i>7);
    return i;
}
