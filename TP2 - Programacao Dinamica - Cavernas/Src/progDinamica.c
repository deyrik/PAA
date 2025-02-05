/*
 * prog_dinamica.c
 *
 *  Created on: 4 de jan. de 2025
 *      Author: nalu
 */

#include "../Headers/progDinamica.h"

struct celulaProgD **fazMatrizProgDinamica(informacoes inf){
	struct celulaProgD **progD;
	progD = (struct celulaProgD **)malloc(inf.linhas * sizeof(struct celulaProgD *));
	for (int i = 0; i < inf.linhas; i++) {
	    progD[i] = (struct celulaProgD *)malloc(inf.colunas * sizeof(struct celulaProgD));
	    for (int j = 0; j < inf.colunas; j++) {
	    	progD[i][j].pv = 0;  // Inicializa o valor como o zero
	    	progD[i][j].letra = 'x';  // Inicializa a letra como valor padrão
	    	progD[i][j].posiX = i;
	    	progD[i][j].posiY = j;
	    }
	}
	return progD;
}

int maiorValor(int valor1, int valor2){
	int maior;
	if(valor1 > valor2){
		maior = valor1;
	}
	else if(valor1 <= valor2){
		maior = valor2;
	}
	return maior;
}


struct celulaProgD maiorCelula(struct celulaProgD valor1, struct celulaProgD valor2){
	struct celulaProgD maior;
	if(valor1.pv > valor2.pv){
		maior = valor1;
	}
	else if(valor1.pv <= valor2.pv){
		maior = valor2;
	}
	return maior;
}



void calcularSubproblemas(struct celulaProgD **progD, Mapa mapa, informacoes inf, int linhaF, int colunaF, int linhaI, int colunaI){
	//progD[linhaI][colunaI].pv = inf.HP; // posi de I
	//printf("I: %d\n\n", inf.HP);
	progD[linhaI][colunaI].letra = 'I';
	progD[linhaF][colunaF].pv = 0;
	progD[linhaF][colunaF].letra = 'F';
	int i, j;
	for(i = linhaI; i >= linhaF; i--){
		for(j = colunaI; j >= colunaF; j--){ //verificar colunaI ou inf.colunas
			if(i == linhaI){ //se for a ultima linha do labirinto!
				if(progD[i][j].letra == 'I'){
					progD[i][j].pv = inf.HP + progD[i][j].pv;
					//printf("pv: %d\n ", progD[i][j].pv );
				}
				else if(progD[i][j].letra == 'F'){
					progD[i][j].pv = 0 + progD[i][j+1].pv;
					break;
				}
				else{
					progD[i][j].pv = mapa[i][j] + progD[i][j+1].pv;
					//printf("pv: %d\n ", progD[i][j].pv );
				}
			}
			else if(j == inf.colunas - 1){ // se for a ultima coluna do labirinto
				if(progD[i][j].letra == 'F'){
					progD[i][j].pv = 0 + progD[i+1][j].pv;
					break;
				}
				else{
				progD[i][j].pv = mapa[i][j] + progD[i+1][j].pv;
				//printf("pv: %d\n ", progD[i][j].pv );	
				}
			}
			else{ // qualquer outra célula do labirinto
				if(progD[i][j].letra == 'F'){
					progD[i][j].pv = 0 + maiorValor(progD[i+1][j].pv, progD[i][j+1].pv);
					break;
				}
				progD[i][j].pv = mapa[i][j] + maiorValor(progD[i+1][j].pv, progD[i][j+1].pv);
				//printf("pv: %d\n ", progD[i][j].pv );
			}		
		}
		if(progD[i][j].letra == 'F') break;
	}
	//printf("PV:%d\n", progD[linhaF][colunaF].pv);
	//printf("cont: %d", cont);
}


int verificaPontosDeVidaFinal(struct celulaProgD **progD, int linhaF, int colunaF){
	//linhaF e colunaF são as coordenadas onde se enconta F
	//printf("PV:%d\n", progD[linhaF][colunaF].pv);
	if(progD[linhaF][colunaF].pv <= 0){
		//printf("Não eh possivel sair do labirinto! :(\n");
		
		return -1;
	}
	else{
		//printf("Parabéns! Voce saiu do labirinto com %d pontos!\n",progD[linhaF][colunaF].pv);
		return progD[linhaF][colunaF].pv;
	}
}

void constroiCaminho(struct celulaProgD **progD, informacoes inf, int linhaF, int colunaF, int linhaI, int colunaI){

	FILE* resultado;
	resultado = fopen("Out/resultado.txt", "w");
	if(resultado == NULL){
		printf("Arquivo inexistente!\n");
		exit(1);
	}
	else{
		struct celulaProgD maior;
		int i, j;
		for(i = linhaI; i >= linhaF; i--){
			for(j = colunaI; j >= colunaF; j--){
				
				if(i == linhaI && j == colunaI){ //se for a posição do I
					if(progD[i][j].pv > 0){
						//printf("%d %d\n", i, j);
						fprintf(resultado,"%d %d\n", i, j);
						maior = (maiorCelula(progD[i-1][j], progD[i][j-1]));
					}
					else{
						//printf("Vc já começou morto, meu querido!");
						freopen("Out/resultado.txt", "w", resultado); //reabre o arquivo limpando seu conteúdo
						fprintf(resultado, "impossível sair do labirinto!\n");
						break;
					}
				}
				else if(i == maior.posiX && j == maior.posiY){
					if(maior.pv > 0){ //verifica se há pontos de vida
						//printf("%d %d\n", i , j);
						fprintf(resultado,"%d %d\n", i, j);
					}
					else{
						//printf("Vish! vc morreu! :(");
						freopen("Out/resultado.txt", "w", resultado);
						fprintf(resultado, "impossível sair do labirinto!\n");
						break;
					}
					if((i == linhaF) && (maior.letra != 'F')){ //impede o acesso de um elemento fora da matriz que estamos analisando.
						maior = progD[i][j-1];
					}
					else if(j == colunaF && (maior.letra != 'F')){ //impede o acesso de um elemento fora da matriz que estamos analizando.
						maior = progD[i-1][j];
					}
					else if((i == linhaF) && (j == colunaF) && ((maior.letra = 'F'))){ // apenas para F, evita acesso fora da matriz
						maior = progD[i][j];
					}
					else{
						maior = (maiorCelula(progD[i-1][j], progD[i][j-1]));
					}
				}
			}
			if(maior.pv <= 0 || progD[linhaI][colunaI].pv <=0){
				break;
			}
		}

	}
	fclose(resultado);	
}

