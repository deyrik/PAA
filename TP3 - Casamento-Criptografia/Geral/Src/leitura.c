#include "../Headers/leitura.h"

void arquivoParaString(char* arquivo, char** texto)
{
	FILE* textoArquivo = fopen(arquivo, "r");
	if(textoArquivo == NULL)
	{
		printf("%s não existe!\n", arquivo);
		return;
	}
	
	//Determina tamanho do arquivo e volta ponteiro de leitura para posição inicial
	fseek(textoArquivo, 0, SEEK_END);
	long tamArquivo = ftell(textoArquivo);
	fseek(textoArquivo, 0, SEEK_SET);
	int i = 0;
	char k;

	*texto = (char*)malloc((tamArquivo+1)*sizeof(char));

	while((k = fgetc(textoArquivo))!= EOF)
	{
		(*texto)[i] = k;
		i++;
	}
	//Coloca fim de string como garantia de que não haverá problema de segmentação
	(*texto)[i] = '\0';

	fclose(textoArquivo);
}
