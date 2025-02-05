#include "../Headers/cifra.h"
#include "../../Geral/Headers/leitura.h"

char* criptografar(int x, char* texto, char* nomeArquivoCriptografado)
{
	alfabeto letras;
	strcpy(letras.simbolos,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	int tamTexto = strlen(texto);
	int tamAlfabeto = strlen(letras.simbolos);
	int cifra = 0;

	//Confere se e letra maiúscula ou minúscula, se for aplica o deslocamento
	//Se a cifra for menor que o tamanho do alfabeto, usa o módulo do valor da cifra % tamanho do alfabeto
	for(int i = 0; i < tamTexto; i++)
	{
		if((texto[i] >= 65 && texto[i] <= 90) || (texto[i] >= 97 && texto[i] <= 122))
		{
			for(int j = 0; j < tamAlfabeto; j++)
			{
				if(texto[i] == letras.simbolos[j])
				{
					cifra = j + x;
					if(cifra < tamAlfabeto) texto[i] = letras.simbolos[abs(cifra%tamAlfabeto)];
       					else texto[i] = letras.simbolos[cifra%tamAlfabeto];
					break;
				}
			}
		}
	}
	
	//Geração de arquivo de saída com base na entrada do usuário
	char* pasta = "Out/";
	char* txt = ".txt";
	size_t tamArquivo = strlen(pasta) + strlen(nomeArquivoCriptografado) + strlen(txt);
	char* arquivoSaidaTxt = (char*)malloc(tamArquivo*sizeof(char));
	strcpy(arquivoSaidaTxt, pasta);
	strcat(arquivoSaidaTxt, nomeArquivoCriptografado);
	strcat(arquivoSaidaTxt, txt);

	FILE* saida = fopen(arquivoSaidaTxt,"w");
	if(saida == NULL)
	{
		printf("Erro!\n");
		exit(1);
	}
	for(int i = 0; i < tamTexto; i++) fprintf(saida,"%c",texto[i]);
	fclose(saida);

	return arquivoSaidaTxt;
}

char* descriptografar(int x, char* texto, char* nomeArquivoDescriptografado)
{
	alfabeto letras;
	strcpy(letras.simbolos,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	int tamTexto = strlen(texto);
	int tamAlfabeto = strlen(letras.simbolos);
	int cifra = 0;
	
	//Confere se é letra maiúsucula ou minúscula
	//Se sim, desfaz o deslocamento feito sobre o texto usando o struct de alfabeto e fórmula (posição - chave) % tamanhoAlfabeto
	//A operação % é usada para lidar com chaves muito grandes, maiores que o tamanho do alfabeto
	for(int i = 0; i < tamTexto; i++)
	{
		if((texto[i] >= 65 && texto[i] <= 90) || (texto[i] >= 97 && texto[i] <= 122))
		{
			for(int j = 0; j < tamAlfabeto; j++)
			{
				if(texto[i] == letras.simbolos[j])
				{
					cifra = (j - x)%tamAlfabeto;
					if(cifra < 0) cifra += tamAlfabeto;
					texto[i] = letras.simbolos[cifra];
					break;
				}
			}
		}

	}
	
	//Geração arquivo de saída baseado na entrada do usuário
	char* pasta = "Out/";
	char* txt = ".txt";
	size_t tamArquivo = strlen(pasta) + strlen(nomeArquivoDescriptografado) + strlen(txt);
	char* arquivoSaidaTxt = (char*)malloc(tamArquivo*sizeof(char));
	strcpy(arquivoSaidaTxt, pasta);
	strcat(arquivoSaidaTxt, nomeArquivoDescriptografado);  
	strcat(arquivoSaidaTxt, txt);

	FILE* saida = fopen(arquivoSaidaTxt,"w");
	if(saida == NULL)
	{
		printf("Erro!\n");
		exit(1);
	}
	for(int i = 0; i < tamTexto; i++) fprintf(saida,"%c",texto[i]);
	fclose(saida);

	return arquivoSaidaTxt;
}

void adivinhaChave(int chaveAleatoria, char* texto, char* nomeArquivoCriptografado)
{
	//Coleta do texto criptografado e suas informações
	char* textoCriptografado = criptografar(chaveAleatoria,texto,nomeArquivoCriptografado);
	char* analisaFrequencias;
	arquivoParaString(textoCriptografado, &analisaFrequencias);
	int tamTexto = strlen(analisaFrequencias);

	//Novo texto criptografado aleatoriamente
	printf("\nTexto criptografado com chave aleatória:\n");
	printf("=======================================================\n");
	for(int i = 0; i < tamTexto; i++)printf("%c",analisaFrequencias[i]);
	printf("=======================================================\n");

	//Alfabeto de letras minúsculas
	alfabeto letrasMinusculas;
	strcpy(letrasMinusculas.simbolos,"abcdefghijklmnopqrstuvwxyz");
	int tamAlfabeto = strlen(letrasMinusculas.simbolos);
	
	//Preparação para verificação do valor da chave aleatória
	contagemOcorrencias ocorrenciaLetrasMinusculas[tamAlfabeto];
	contagemOcorrencias total[tamTexto]; 

	int encontrou = 0;
	int k = 0;
	int tamUsado = 0;
	
	//Inicialização das structs
	for(int i = 0; i < tamAlfabeto; i++)
	{
		ocorrenciaLetrasMinusculas[i].caractere = letrasMinusculas.simbolos[i];
		ocorrenciaLetrasMinusculas[i].ocorrencias = 0;
		ocorrenciaLetrasMinusculas[i].porcentagem = 0;
	}

	for(int i = 0; i < tamTexto; i++)
	{
		total[i].caractere = '|';
		total[i].ocorrencias = 0;
		total[i].porcentagem = 0;
	}
	
	//Contabiliza frequência de cada caractere no texto
	for(int i = 0; i < tamTexto; i++)
	{
		encontrou = 0;
		for(int j = 0; j < k; j++)
		{
			if(analisaFrequencias[i] == total[j].caractere)
			{
				total[j].ocorrencias++;
				encontrou = 1;
				break;
			}
		}

		if(encontrou == 0)
		{
			total[k].caractere = analisaFrequencias[i];
			total[k].ocorrencias++;
			k++;
		}
		tamUsado = k;
	}
	encontrou = 0;
	k = 0;

	int totalOcorrencias = 0;
	int retiraCaracteresInuteis = 0;

	//Limpa caracteres que não serão usados
	for(int i = 0; i < tamUsado; i++)
	{
		//if(isprint(total[i].caractere)) totalOcorrencias += total[i].ocorrencias;
		if((total[i].caractere >= 65 && total[i].caractere <= 90) || (total[i].caractere >= 97 && total[i].caractere <= 122))
		{
			if(total[i].caractere >= 65 && total[i].caractere <= 90) totalOcorrencias += total[i].ocorrencias;

			else if(total[i].caractere >= 97 && total[i].caractere <= 122)
			{
				char c;
				c = tolower(total[i].caractere);
				for(int j = 0; j < tamUsado; j++)
				{
					if(total[j].caractere == c)
					{
						totalOcorrencias += total[i].ocorrencias;
					}
				}
			}
		}
		else retiraCaracteresInuteis++;
	}

	//Delimita vetor só de letras e frequência
	int tamVerdadeiro = tamUsado - retiraCaracteresInuteis;
	contagemOcorrencias letras[tamVerdadeiro+1];
	
	//Calcula frequência absoluta das letras
	for(int i = 0; i < tamUsado; i++)
	{
		if(isalpha(total[i].caractere))
		{
			char c = tolower(total[i].caractere);
			encontrou = 0;
			for(int j = 0; j < k; j++)
			{
				if(letras[j].caractere == c)
				{
					letras[j].ocorrencias += total[i].ocorrencias;
					encontrou = 1;
					break;
				}
			}

			if(encontrou == 0)
			{
				letras[k].caractere = c;
				letras[k].ocorrencias = total[i].ocorrencias;
				k++;
			}
		}
	}
	//Delimita ainda mais a busca do vetor de caracteres
	tamVerdadeiro = k;
	
	printf("\n");
	for(int i = 0; i < tamVerdadeiro; i++) printf("letra: %c freq: %d\n", letras[i].caractere,letras[i].ocorrencias);


	for(int i = 0; i < tamVerdadeiro; i++)
	{
		letras[i].porcentagem = ((float)letras[i].ocorrencias / totalOcorrencias) * 100;
	}
	
	printf("\n");
	for(int i = 0; i < tamVerdadeiro; i++)
	{
	    printf("Caractere: %c Ocorrência: %d Porcentagem: %.2f %%\n", letras[i].caractere, letras[i].ocorrencias, letras[i].porcentagem);
	}

	//Descobrindo chave aleatória
	float freqs[] = {14.63,1.04,3.88,4.99,12.57,1.02,1.30,1.28,6.18,0.40,0.02,2.78,4.74,5.05,10.73,2.52,1.20,6.53,7.81,4.34,4.63,1.67,0.01,0.21,0.01,0.47};
	
	for(int i = 0; i < tamAlfabeto; i++) ocorrenciaLetrasMinusculas[i].porcentagem = freqs[i];

	contagemOcorrencias maxFreqL = letras[0];
	contagemOcorrencias maxFreqA = ocorrenciaLetrasMinusculas[0];

	for(int i = 1; i < tamVerdadeiro; i++)
	{
		if(letras[i].porcentagem > maxFreqL.porcentagem)
		{
			maxFreqL.porcentagem = letras[i].porcentagem;
			maxFreqL.caractere = letras[i].caractere;
		}
	}

	for(int i = 1; i < tamAlfabeto; i++)
	{
		if(ocorrenciaLetrasMinusculas[i].porcentagem > maxFreqA.porcentagem)
		{
			maxFreqA.porcentagem = ocorrenciaLetrasMinusculas[i].porcentagem;
			maxFreqA.caractere = ocorrenciaLetrasMinusculas[i].caractere;
		}
	}
	
	int chaveUsada = chaveAleatoria % tamAlfabeto;
	int chute = (maxFreqL.caractere - maxFreqA.caractere + tamAlfabeto) % tamAlfabeto;

	printf("\nChute = %d\n",chute);
	printf("Módulo de chave usada = %d\nChave Real = %d\n",chaveUsada,chaveAleatoria);
	printf("Diferença entre chute e módulo de chave usada: %d\n", abs(chute-chaveUsada));
}
