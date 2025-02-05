#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct posicao{
    int x;
    int y;
}posicao;

typedef struct listaDuplamenteEncadeada{
    
    posicao posicao;
    struct listaDuplamenteEncadeada *prox;
    struct listaDuplamenteEncadeada *ant;
}lista;

typedef struct listaDuplamenteEncadeada* ponteiroLista; 


ponteiroLista criaLista (posicao posicaoAtual);
void insereLista (ponteiroLista lista,posicao posicaoAtual);
void imprimeLista (ponteiroLista lista);
void imprimeListaInversa (ponteiroLista lista);

#endif