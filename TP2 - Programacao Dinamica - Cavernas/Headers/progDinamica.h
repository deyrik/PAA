/*
 * prog_dinamica.h
 *
 *  Created on: 4 de jan. de 2025
 *      Author: nalu
 */

#ifndef PROG_DINAMICA_H_
#define PROG_DINAMICA_H_

#include "mapa.h"
#include "arquivo.h"


struct celulaProgD{
	int pv; //pontos de vida
	char letra; // final (F), inicial (I), outro (x)
	int posiX; //posição x
	int posiY; //posição y
};

struct celulaProgD **fazMatrizProgDinamica(informacoes inf);
int maiorValor(int valor1, int valor2);
struct celulaProgD maiorCelula(struct celulaProgD valor1, struct celulaProgD valor2);
int verificaPontosDeVidaFinal(struct celulaProgD **progD, int linhaF, int colunaF);
void calcularSubproblemas(struct celulaProgD **progD, Mapa mapa, informacoes inf, int linhaF, int colunaF, int linhaI, int colunaI);
void constroiCaminho(struct celulaProgD **progD, informacoes inf, int linhaF, int colunaF, int linhaI, int colunaI);
#endif /* PROG_DINAMICA_H_ */