#ifndef NOVA_HEURISTICA_H
#define NOVA_HEURISTICA_H

#include "mapa.h"
#include "arquivo.h"
#include "time.h"
#include "listaDuplamenteEncadeada.h"

//---------------------------------Estruturas---------------------------------
typedef struct caminhando{
    posicao pos;

}caminhando;

typedef struct resultado{
    int valor;
    posicao pos;

}resultado;

//---------------------------------Funções---------------------------------

resultado melhorPosicao(Mapa mapa,posicao atual,int linhaFinal,int colunaFinal);

ponteiroLista progamaçaoD(Mapa mapa,informacoes info,caminhando aluno);

void guardarInformacoes(ponteiroLista lista);

#endif
