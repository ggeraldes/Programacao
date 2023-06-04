#include <stdio.h>
#include <malloc.h>
#include "ParagensLinhas.h"
#include "GlobalFunc.h"

#define MAX 100

int main() {


    pParagem paragens=NULL;
    pLinha linhas=NULL;
    int total=0, i, y;

    registarDados(&linhas, &paragens, &total);

    do {
        i = menu();
        switch(i){
            case 1: {
                y=menuParagens();
                switch(y){
                    case 1: paragens=adiciona_paragem(paragens,&total, NULL, NULL); break;
                    case 2: paragens=elimina_paragem(paragens,&total); break;
                    case 3: escreve_todos(paragens,total); break;
                }
                break;
            }
            case 2: {
                y=menuLinhas();
                switch(y){
                    case 1: linhas=adiciona_linha(linhas, NULL); break;
                    case 2: adicionar_paragemLinha(linhas, paragens, total, NULL, NULL); break;
                    case 3: eliminar_paragemLinha(linhas, paragens, total); break;
                    case 4: linhas=elimina_Linha(linhas, paragens, total); break;
                    case 5: escreve_linhas(linhas); break;
                    case 6: carregaFicheiro(&linhas, &paragens, &total); break;

                }
                break;
            }
            case 3: caminhoMaisRapido(linhas); break;
        }
    } while(i != 4);

    guardarDados(linhas, paragens, total);

    if (paragens != NULL)
        free(paragens);
    if(linhas != NULL)
        free(linhas);

    return 0;
}
