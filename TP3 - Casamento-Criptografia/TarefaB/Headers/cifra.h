#ifndef CIFRA_H
#define CIFRA_H

#include "../../Geral/Headers/includes.h"

#define TAM_ALFABETO 53

typedef struct Alfabeto
{
	char simbolos[TAM_ALFABETO];
}
alfabeto;

typedef struct ContagemOcorrencias
{
	int ocorrencias;
	char caractere;
	float porcentagem;
}
contagemOcorrencias;

// --------------- Cabeçalho das funções: -----------------------
char* criptografar(int x, char* texto, char* nomeArquivoCriptografado);
char* descriptografar(int x, char* texto, char* nomeArquivoDescriptografado);
void adivinhaChave(int chaveAleatoria, char* texto, char* nomeArquivoCriptografado);
// --------------------------------------------------------------

#endif 
