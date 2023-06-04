//
// Created by goncalo on 29/05/2023.
//

#include <stdio.h>
#include <string.h>
#include "ParagensLinhas.h"

int nL=0;



void escreve_linhas(pLinha p){
    while(p != NULL)
    {
        printf("-----------------------\n");
        printf("Linha: %s, Cod:%s, nParagens:%d\n",p->nome, p->codigo, p->nParagens);
        if(p->nParagens!=0){
            printf("Paragens:\n");
            for(int i=0; i<p->nParagens; i++)
                printf("Nome da paragem: %s, Codigo: %s\n", p->paragens[i].nome, p->paragens[i].codigo);
        }
        else{
            printf("Nao ha paragens!\n");
        }
        printf("-----------------------\n");
        p = p->prox;
    }
}


pLinha adiciona_linha(pLinha p, char str[50]){

    pLinha nova, temp=p;
    nova = malloc(sizeof(linhas));
    if(nova == NULL) return p;

    if(str==NULL){
        printf("Nome da Linha: ");
        scanf(" %99[^\n]", nova->nome);
    }else{
        strcpy(nova->nome, str);
    }

    while(temp != NULL){
        if(strcmp(temp->nome, nova->nome)==0){
            printf("Linha %s ja existe!\n", temp->nome);
            return p;
        }

            temp = temp->prox;
    }
    //printf("nL = %d", nL);
    if(nL>99)
        sprintf(nova->codigo, "L%d", nL++);
    else if(nL>9)
        sprintf(nova->codigo, "L0%d", nL++);
    else
        sprintf(nova->codigo, "L00%d", nL++);

    nova->codigo[4]='\0';
    //printf("parei aqui");
    nova->nParagens=0;
    nova->paragens = NULL;
    printf("Linha Adicionada!\n");

    nova->prox = p;
    p = nova;

    return p;
}

void adicionar_paragemLinha(pLinha l, pParagem p, int n, char codeP[5], char codeL[5]){

    char code[50], code2[50];

    if(codeP==NULL){
        do{
            printf("\nDigite o codigo da Linha: ");
            scanf("%s", code);
            code[strlen(code)] = '\0';
        }while(strlen(code) > 4 || strlen(code) < 4 || code[0]!='L');

        do{
            printf("\nDIgite o codigo da Paragem a adicionar: ");
            scanf("%s", code2);
            code[strlen(code2)] = '\0';
        }while(strlen(code2) > 4 || strlen(code2) < 4|| code2[0]!='P');
    }else{
        strcpy(code, codeL);
        strcpy(code2, codeP);

    }



    while(l!=NULL && strcmp(l->codigo, code) !=0)
        l = l->prox;


    if(n!=0){

        if(l!=NULL){

           for(int i=0; i<l->nParagens;i++)
               if(strcmp(code2, l->paragens[i].codigo)==0){
                   printf("\nParagem ja registada nesta Linha\n");
                   return;
               }

            pParagem add;
            add = realloc(l->paragens, sizeof(paragem) * (l->nParagens+1));

            if(add != NULL){

                for(int i=0; i<n; i++){
                    if(strcmp(p[i].codigo, code2)==0){

                        l->paragens = add;
                        p[i].nLinhas++;
                        l->paragens[l->nParagens]=p[i];
                        l->nParagens++;

                        printf("\nParagem %s adicionada a Linha %s\n", l->paragens[l->nParagens-1].codigo, l->codigo);
                        return;
                    }
                }

            }
        }else
            printf("\nLinha nao encontrada!\n");
    }
    else{
        printf("\nNao ha paragens!\n");
    }
    //printf("\nParagem nao encontrada!\n");

}

void eliminar_paragemLinha(pLinha l, pParagem p, int n){

    char code[50], code2[50];
    int verifica=0;
    do{
        printf("\nDigite o codigo da Linha: ");
        scanf("%s", code);
        code[strlen(code)] = '\0';
    }while(strlen(code) > 4 || strlen(code) < 4 || code[0]!='L');

    do{
        printf("\nDIgite o codigo da Paragem a adicionar: ");
        scanf("%s", code2);
        code[strlen(code2)] = '\0';
    }while(strlen(code2) > 4 || strlen(code2) < 4|| code2[0]!='P');

    while(l!=NULL && strcmp(l->codigo, code) !=0)
        l = l->prox;

    if(n!=0){

        if(l!=NULL){

            int i;
            pParagem aux;
            paragem t;

            for(i=0; i<l->nParagens && strcmp(code2, l->paragens[i].codigo)!=0; i++);


            if(i==l->nParagens){
                printf("Paragem nao existe\n");
            }
            else if(l->nParagens==1){
                printf("Paragem eliminada!\n");
                l->nParagens=0;
                //free(l->paragens);

                for(int y=0;y<n;y++)
                    if(strcmp(p[y].codigo, l->paragens[i].codigo)==0)
                        p[y].nLinhas--;
            }
            else{
                t = l->paragens[i];
                l->paragens[i] = l->paragens[l->nParagens-1];
                aux = realloc(l->paragens, sizeof(paragem) * (l->nParagens-1));
                printf("Paragem eliminada!\n");
                if(aux!=NULL){
                    l->paragens = aux;
                    l->nParagens--;
                }
                else
                    l->paragens[i] = t;

                for(int y=0;y<n;y++)
                    if(strcmp(p[y].codigo, l->paragens[i].codigo)==0)
                        p[y].nLinhas--;
            }
        }else
            printf("\nLinha nao encontrada!\n");
    }
    else{
        printf("\nNao ha paragens!\n");
    }


}

pLinha elimina_Linha(pLinha l, pParagem p, int n){

    pLinha atual, anterior=NULL;
    atual=l;
    char code[50];

    do{
        printf("\nDigite o codigo da Linha: ");
        scanf("%s", code);
        code[strlen(code)] = '\0';
    }while(strlen(code) > 4 || strlen(code) < 4 || code[0]!='L');

    while(atual!=NULL && strcmp(atual->codigo, code) !=0){
        anterior=atual;
        atual = atual->prox;
    }

    if(atual ==NULL)return l;
    printf("Linha Eliminada!\n");
    for(int i=0; i<atual->nParagens; i++)
        for(int y=0;y<n;y++)
            if(strcmp(p[y].codigo, atual->paragens[i].codigo)==0)
                p[y].nLinhas--;

    if(anterior==NULL)
        l=atual->prox;
    else
        anterior->prox=atual->prox;

    free(atual);
    return l;

}

void carregaFicheiro(pLinha* l, pParagem* p, int* n) {
    char ficheiro[50];
    char linha[50];
    char paragem[50], codParagem[5];

    printf("\nNome do ficheiro: ");
    scanf("%s", ficheiro);
    ficheiro[strlen(ficheiro)] = '\0';

    FILE* arquivo = fopen(ficheiro, "r");  // Abra o arquivo para leitura

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        printf("Erro ao ler o nome da linha.\n");
        fclose(arquivo);
        return;
    }
    linha[strcspn(linha, "\n")] = '\0';  // Remove a quebra de linha

    *l = adiciona_linha(*l, linha);

    // Lê as paragens
    while (fscanf(arquivo, "%[^#]#%s", paragem, codParagem) == 2) {
        size_t len = strlen(paragem);
        if (paragem[0] == '\n'){
            memmove(paragem, paragem + 1, len);  // Remove a quebra de linha
            paragem[len - 2] = '\0';  // Atualiza o caractere nulo no final da string
        }else
            paragem[len - 1] = '\0';  // Atualiza o caractere nulo no final da string

        *p = adiciona_paragem(*p, n, paragem, codParagem);

        adicionar_paragemLinha(*l, *p, *n, codParagem, (*l)->codigo);
    }

    fclose(arquivo);  // Fecha o arquivo
}

void guardarDados(pLinha l, pParagem p, int n) {
    FILE* arquivo = fopen("data.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Gravar o número de paragens
    fwrite(&n, sizeof(int), 1, arquivo);

    // Gravar as paragens
    fwrite(p, sizeof(paragem), n, arquivo);

    // Contar o número de linhas
    int counter = 0;
    pLinha linhaAtual = l;
    while (linhaAtual != NULL) {
        counter++;
        linhaAtual = linhaAtual->prox;
    }
    fwrite(&counter, sizeof(int), 1, arquivo);

    // Gravar as linhas
    linhaAtual = l;
    while (linhaAtual != NULL) {
        fwrite(linhaAtual->nome, sizeof(char), 100, arquivo);
        fwrite(linhaAtual->codigo, sizeof(char), 5, arquivo);
        fwrite(&linhaAtual->nParagens, sizeof(int), 1, arquivo);
        fwrite(linhaAtual->paragens, sizeof(paragem), linhaAtual->nParagens, arquivo);
        linhaAtual = linhaAtual->prox;
    }

    fclose(arquivo);
}

void registarDados(pLinha* l, pParagem* p, int* n) {
    FILE* arquivo = fopen("data.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    // Ler o número de paragens
    fread(n, sizeof(int), 1, arquivo);

    // Alocar memória para as paragens
    *p = (pParagem)malloc(*n * sizeof(paragem));

    // Ler as paragens
    fread(*p, sizeof(paragem), *n, arquivo);

    // Ler o número de linhas
    int numLinhas;
    fread(&numLinhas, sizeof(int), 1, arquivo);
    nL=numLinhas;
    // Ler as linhas
    for (int i = 0; i < numLinhas; i++) {
        pLinha linha = (pLinha)malloc(sizeof(linhas));
        fread(linha->nome, sizeof(char), 100, arquivo);
        fread(linha->codigo, sizeof(char), 5, arquivo);
        fread(&linha->nParagens, sizeof(int), 1, arquivo);

        linha->paragens = (pParagem)malloc(linha->nParagens * sizeof(linhas));
        fread(linha->paragens, sizeof(paragem), linha->nParagens, arquivo);

        incrementNParagens(linha->paragens, linha->nParagens);

        linha->prox = *l;
        *l = linha;
    }

    fclose(arquivo);
}

void caminhoMaisRapido(pLinha l){


    int maisRapido=100000, verificado=0, inicial=0, final=0;
    char linha[50], partida[50], chegada[50];
    pLinha temp;

    printf("Partida: ");
    scanf(" %99[^\n]", partida);
    partida[strlen(partida)]='\0';
    printf("\nChegada: ");
    scanf(" %99[^\n]", chegada);
    chegada[strlen(chegada)]='\0';

    while(l != NULL)
    {

            for(int i=0; i<l->nParagens; i++){
                if(strcmp(partida, l->paragens[i].nome)==0){
                    for(int y=0; y<l->nParagens; y++) {
                        if(strcmp(chegada, l->paragens[y].nome)==0){
                            if(i<y){
                                if(y-i<maisRapido){
                                    maisRapido=y-i;
                                    strcpy(linha, l->nome);
                                    verificado=1;
                                    temp=l;
                                    inicial=i;
                                    final=y;
                                }
                            }else{
                                if(i-y<maisRapido){
                                    maisRapido=i-y;
                                    strcpy(linha, l->nome);
                                    verificado=2;
                                    temp=l;
                                    inicial=i;
                                    final=y;
                                }
                            }
                        }
                    }
                }
            }

        l = l->prox;
    }
    if(verificado==1){
        printf("Melhor percurso pela linha '%s'\n", linha);
                for (int i = inicial; i <= final; i++) {
                    printf("%s",  temp->paragens[i].nome);
                    if(i!=final)
                        printf(" -> ");
                }
                printf("\n");
    }
    else  if(verificado==2) {
        printf("Melhor percurso pela linha %s\n", linha);
            for (int i = inicial; i >= final; i--) {
                printf("%s", temp->paragens[i].nome);
                if (i != final)
                    printf(" -> ");
            }
            printf("\n");
    }
    else
        printf("\nNenhuma linha tem esses dois pontos!");

}