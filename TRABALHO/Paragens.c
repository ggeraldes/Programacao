//
// Created by glgge on 21/04/2023.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include "Paragens.h"

#define MAX 100
char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool verifica_codigo(paragem tab[], int n, paragem p){
    for(int i=0; i<n; i++){
        if(tab[i].codigo==p.codigo)
            return false;
    }
    return true;
}
void novo_codigo(paragem *p){
    srand(time(NULL));
    for (int i = 0; i < 4; ++i) {
        p->codigo[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
}

paragem obtem_info(){

    paragem t;
    printf("Nome da paragem: ");
    scanf(" %99[^\n]", t.nome);


    t.nLinhas=0;
    return t;


}
void escreve_info(paragem p){


    printf("Nome da paragem: %s, ", p.nome);
    printf("Codigo: %s, ", p.codigo);
    printf("Numero de Linhas: %d\n", p.nLinhas);

}
void escreve_todos(paragem *tab, int n){

    int i;
    if(n!=0){
        printf("-----------------------\n");
        for(i=0; i<n; i++){
            escreve_info(tab[i]);
        }
        printf("-----------------------\n");
    }
    else{
        printf("Nao ha paragens!\n");
    }

}

/*
int adiciona_paragem(paragem tab[], int* n){
    if(*n >= MAX){
        printf("Tabela completa\n");
        return 0;
    }
    else
    {
        tab[*n] = obtem_info();
        (*n)++;
        return 1;
    }
}

int elimina_paragem(paragem tab[], int *n){
    char st[15];
    int i;
    printf("Codigo da Paragem: ");
    scanf("%14s", st);
    for(i=0; i<*n && strcmp(st, tab[i].codigo)!=0; i++)
        ;
    if(i==*n){
        printf("Paragem nao existe\n");
        return 0;
    }
    else
    {
        tab[i] = tab[*n-1];
        (*n)--;
        printf("Paragem Eliminada\n");
        return 1;
    }
}

 */

paragem* adiciona_paragem(paragem *tab, int* n){
    paragem *aux;
    aux = realloc(tab, sizeof(paragem) * (*n+1));
    if(aux != NULL){
        tab = aux;
        tab[*n] = obtem_info();
        do{
            novo_codigo(&tab[*n]);
        }while(verifica_codigo(tab, *n, tab[*n])==false);
        (*n)++;
    }
    printf("Adicionado");
    return tab;
}

paragem* elimina_paragem(paragem *tab, int *n){
    char st[100];
    int i;
    paragem *aux, t;
    printf("Codigo da paragem a eliminar: ");
    scanf(" %s", st);
    for(i=0; i<*n && strcmp(st, tab[i].codigo)!=0; i++)
        ;
        if(i==*n){
            printf("Paragem nao existe\n"); return tab;
        }
        else if(*n==1){
            printf("Paragem eliminada!\n");
            free(tab); *n=0; return NULL;
        }
        else{
            t = tab[i];
            tab[i] = tab[*n-1];
            aux = realloc(tab, sizeof(paragem) * (*n-1));
            printf("Paragem eliminada!\n");
            if(aux!=NULL){
                tab = aux;
                (*n)--;
            }
            else
                tab[i] = t;
            return tab;
        }

}


int menu(){
    int i;
    puts("\n1 - Registar Paragem");
    puts("2 - Eliminar Paragem");
    puts("3 - Visualizar Paragems");
    puts("4 - Terminar");
    printf("\nEscolha uma opcao: ");
    do{
        scanf(" %d", &i);
    }while(i<1 || i>5);
    return i;
}