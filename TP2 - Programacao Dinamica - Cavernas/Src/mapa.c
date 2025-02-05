/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Labirinto-PAA
 * Descrição: definições de funcionalidades para manipulação do tipo Mapa
 * 
 * Autor(es): Gabriel de Pádua, Matheus Kauan
 * Data de criação: 15/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- 15/11/2024: criada funçoes criar mapa e apagar mapa
 *    - v1.1 (gabriel)- 16/11/2024: criada funções mostrar mapa e preencher mapa
 *    - v2.0 (gabriel)- 04/01/2025: alterado tipo de dados da matriz em (CriaMapa) e modo como se trata
 * a matriz em (MostrarMapa) e (PreencherMapa) 
 * Dependências:
 *    - mapa.h
 * 
 * Observações:
 *    - 
 **************************************************************/


/*
       int***       --> int**                --> int*     --> int
ponteiro pra matriz     ponteiro pra linha       vetor de inteiros 

*/


// typedef int*** ApontadorMapa _____________________ apontador de matriz de inteiros
// typedef int** Mapa __________________ matriz de inteiros 

#include "../Headers/mapa.h"


void CriaMapa(ApontadorMapa mapa, int linhas, int colunas)
{   
    *mapa = (char**)malloc(linhas * sizeof(char*)); // Aloca memória para as linhas
    if (*mapa == NULL)
    {
        printf("Erro ao alocar memória para as linhas do mapa\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++)
    {
        (*mapa)[i] = (char*)malloc(colunas * sizeof(char)); // Aloca memória para as colunas
        if ((*mapa)[i] == NULL)
        {
            printf("Erro ao alocar memória para as colunas do mapa\n");

            for (int j = 0; j < i; j++) // Libera linhas já alocadas
            {
                free((*mapa)[j]);
            }
            free(*mapa);
            exit(1);
        }
    }
}

void ApagaMapa(ApontadorMapa mapa, int linhas)
{
    if (*mapa == NULL)
        return;

    // Libera cada linha do mapa
    for (int i = 0; i < linhas; i++)
    {
        free((*mapa)[i]);
    }

    // Libera a matriz de ponteiros
    free(*mapa);

    // Define o ponteiro principal como NULL para evitar dangling pointers
    *mapa = NULL;
}

void MostrarMapa(Mapa mapa, int linhas, int colunas) {
    if (mapa == NULL) {
        printf("Mapa não existe\n");
        return;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 'F' || mapa[i][j] == 'I'|| mapa[i][j] == 'B') {
                printf("%c ", mapa[i][j]); // Exibir caracteres
            } else {
                printf("%d ", mapa[i][j]); // Exibir números
            }
        }
        printf("\n");
    }
}


void PreencherMapa(ApontadorMapa mapa, int posicacaoLinha, char valores[],int qtdColunas){

    for (int i = 0; i < qtdColunas; i++)
    {
        (*mapa)[posicacaoLinha][i] = valores[i];
    }
    
}
