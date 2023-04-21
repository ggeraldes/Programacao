#include <stdio.h>
#include <malloc.h>
#include "Paragens.h"

#define MAX 100

int main() {

    /*paragem banco[MAX];
    int i, total=0;
    do {
        i = menu();
        printf("\n|%d|\n", i);
        switch(i){
            case 1: adiciona_paragem(banco,&total); break;
            case 2: elimina_paragem(banco,&total); break;
            case 3: escreve_todos(banco,total); break;
        }
    } while(i != 4);
    return 0;
     */

    paragem *banco=NULL;
    int total=0, i;


    do {
        i = menu();
        switch(i){
            case 1: banco=adiciona_paragem(banco,&total); break;
            case 2: banco=elimina_paragem(banco,&total); break;
            case 3: escreve_todos(banco,total); break;
        }
    } while(i != 4);

    if (banco != NULL)
        free(banco);

    return 0;
}
