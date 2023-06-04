//
// Created by glgge on 21/04/2023.
//

#ifndef TRABALHO_PARAGENS_H
#define TRABALHO_PARAGENS_H

#include <stdlib.h>

typedef struct PARAGEM paragem, *pParagem;
typedef struct LINHAS linhas, *pLinha;

struct PARAGEM{
    char nome[100];
    char codigo[5];
    int nLinhas;
};

struct LINHAS{
    char nome[100];
    char codigo[5];
    int nParagens;
    pParagem paragens;      //lista de paragens
    pLinha prox;            //proxima Linha
};

//--------------------------PARAGENS-------------------------

void escreve_todos(pParagem tab, int n);

pParagem adiciona_paragem(pParagem tab, int* n, char str_name[50], char str_cod[5]);

pParagem elimina_paragem(pParagem tab, int *n);

//--------------------------LINHAS---------------------------

void escreve_linhas(pLinha lista);

pLinha adiciona_linha(pLinha lista, char nomeLinha[50]);

void adicionar_paragemLinha(pLinha linhas, pParagem paragens, int n, char str_codeP[5], char str_codeL[5]);

void eliminar_paragemLinha(pLinha linhas, pParagem paragens, int n);

pLinha elimina_Linha(pLinha p, pParagem paragens, int n);

void carregaFicheiro(pLinha* l, pParagem* p, int* n);

//---------------------carregarDados------------------------

void registarDados(pLinha* l, pParagem* p, int* n);

void guardarDados(pLinha linhas, pParagem paragens, int total);

void caminhoMaisRapido(pLinha linhas);

#endif //TRABALHO_PARAGENS_H

