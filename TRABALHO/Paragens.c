//
// Created by glgge on 21/04/2023.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include "ParagensLinhas.h"

#define MAX 100
int nP=0;

paragem obtem_info(){

    paragem t;
    printf("Nome da paragem: ");
    scanf(" %99[^\n]", t.nome);
    if(nP>99)
        sprintf(t.codigo, "P%d", nP++);
    else if(nP>9)
        sprintf(t.codigo, "P0%d", nP++);
    else
        sprintf(t.codigo, "P00%d", nP++);
    t.codigo[4]='\0';

    t.nLinhas=0;
    return t;


}
void escreve_info(paragem p){


    printf("Nome da paragem: %s, ", p.nome);
    printf("Codigo: %s, ", p.codigo);
    printf("Numero de Linhas: %d\n", p.nLinhas);

}
void escreve_todos(pParagem tab, int n){

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

pParagem adiciona_paragem(pParagem tab, int* n, char str_name[50], char str_cod[5]){

    char nome[50];


    paragem *aux;
    aux = realloc(tab, sizeof(paragem) * (*n+1));

    if(aux != NULL){
        tab = aux;
        if(str_cod==NULL){

            printf("Nome da paragem: ");
            scanf(" %99[^\n]", nome);

            for(int i=0; i<*n; i++)
                if(strcmp(nome, tab[i].nome)==0) {
                    printf("A Paragem %s ja existe", nome);
                    return tab;
                }
            strcpy(tab[*n].nome, nome);
            if(nP>99)
                sprintf(tab[*n].codigo, "P%d", nP++);
            else if(nP>9)
                sprintf(tab[*n].codigo, "P0%d", nP++);
            else
                sprintf(tab[*n].codigo, "P00%d", nP++);
            tab[*n].codigo[4]='\0';

            tab[*n].nLinhas=0;
        }
        else{
            if(*n!=0)
                for(int i=0; i<*n; i++){
                    if(strcmp(str_name, tab[i].nome)==0){
                        printf("A Paragem: %s ja existe", str_name);
                        return tab;
                    }else if(strcmp(str_cod, tab[i].codigo)==0){
                        printf("Codigo: %s ja existe", str_cod);
                        sprintf(str_cod, "P%d", nP++);
                    }
                }

            strcpy(tab[*n].codigo, str_cod);
            strcpy(tab[*n].nome, str_name);
            tab[*n].nLinhas=0;

            char lastThree[4];  // Additional space for the null terminator
            strncpy(lastThree, str_cod + strlen(str_cod) - 3, 3);
            lastThree[3] = '\0';

            nP= atoi(lastThree)+1;
        }
        (*n)++;
    }
    printf("Paragem Adicionada!");
    return tab;
}

pParagem elimina_paragem(pParagem tab, int *n){
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
        else if(*n==1 && tab[i].nLinhas==0){
            printf("Paragem eliminada!a\n");
            free(tab); *n=0; return NULL;
        }
        else if(tab[i].nLinhas==0){
            t = tab[i];
            tab[i] = tab[*n-1];
            aux = realloc(tab, sizeof(paragem) * (*n-1));
            printf("Paragem eliminada!b\n");
            if(aux!=NULL){
                tab = aux;
                (*n)--;
            }
            else
                tab[i] = t;
            return tab;
        }else
            printf("ERRO - PARAGEM REGISTADA EM LINHA!\n");

}


