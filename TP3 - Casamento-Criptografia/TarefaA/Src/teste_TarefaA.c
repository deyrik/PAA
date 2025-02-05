#include "../../Geral/Headers/leitura.h"
#include "../../TarefaA/Headers/Algoritmos.h"

int main(){

    char nome[TAM_CAMINHO] = "Geral/Lib/teste3.txt";
	char* texto;
    char padrao[100];
    int resultado_forcaBruta, resultado_shiftAnd;

    clock_t inicio, fim;

    arquivoParaString(nome, &texto);
    

    //printf(texto);
    //printf("\n\n\n");

    printf("Digite o padrao: ");
    scanf("%s", padrao);


    inicio = clock();
    resultado_forcaBruta = forcaBruta(texto, padrao);
    fim = clock();
    printf("Tempo de execucao do forcaBruta: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    resultado_shiftAnd = shiftAnd(texto, padrao);
    fim = clock();
    printf("Tempo de execucao do shiftAnd: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("-----Forca Bruta:-----\n");
    if(resultado_forcaBruta){
        printf("Padrao encontrado!\n");
    }else{
        printf("Padrao nao encontrado!\n");
    }
    printf("-----Shift And:-----\n");
    if(resultado_shiftAnd){
        printf("Padrao encontrado!\n");
    }else{
        printf("Padrao nao encontrado!\n");
    }
    
}