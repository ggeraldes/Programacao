//
// Created by glgge on 21/04/2023.
//

#ifndef TRABALHO_PARAGENS_H
#define TRABALHO_PARAGENS_H

#endif //TRABALHO_PARAGENS_H

typedef struct PARAGEM paragem;

struct PARAGEM{
    char nome[100];
    char codigo[4];
    int nLinhas;
};

paragem obtem_info();

void escreve_info(paragem p);

void escreve_todos(paragem *tab, int n);

/*
int adiciona_paragem(paragem tab[], int* n);

int elimina_paragem(paragem tab[], int *n);
*/

paragem* adiciona_paragem(paragem *tab, int* n);

paragem* elimina_paragem(paragem *tab, int *n);

int menu();