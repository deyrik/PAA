/**************************************************************
 * Nome do arquivo: arquivo.c
 * Projeto: Caverna-PAA
 * Descrição: prototipos e declarações de funções para lidar com arquivos 
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 04/01/2025
 *
 * Histórico de versões:
 *    - v1.0 (gabriel)- 04/01/2025: criado cabeçalho de função lerArquivo e estrutura de informaçoes 
 *    - v1.0 (matheus)- 06/01/2025: criada cabeçalho gerarArquivo
 * Dependências:
 *    - stdio.h
 *    - stdlib.h
 *    - string.h
 *    - mapa.h
 *     
 * 
 * Observações:
 *    - 
 **************************************************************/
#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/mapa.h"

//------------------------Estruturas---------------------------
typedef char* string;

typedef struct informacoes
{
    int linhas;
    int colunas;
    int HP;
    int linhaF;
    int colunaF;
    int linhaI;
    int colunaI;

}informacoes;

typedef informacoes *ponteiroInformçaoes;

typedef struct informacoesArquivo
{
    int linhas;
    int colunas;
    int HP;

}informacoesArquivo;

//------------------------Funções---------------------------
void lerArquivo(const char* nomeArquivo, ponteiroInformçaoes informacoes, ApontadorMapa mapa);
void gerarArquivo(const string nomeArquivo,int linhas, int colunas, int vidaInicial);
int valorDaMatriz(int valorAleatorio);
void gerarAquivosComArmadilhas(const string nomeArquivo,int linhas, int colunas, int vidaInicial);


#endif