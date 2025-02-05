#include "../Headers/Algoritmos.h"

int forcaBruta(char *texto, char *padrao){
    int tamanho_txt = strlen(texto);
    int tamanho_pdr = strlen(padrao);
    int padrao_encontrado = 0;

    for(int i = 0; i <= tamanho_txt - tamanho_pdr; i++){
        int j;
        for(j = 0; j < tamanho_pdr; j++){
            if(texto[i + j] != padrao[j]){
                break;
            }
        }
        if(j == tamanho_pdr){
            padrao_encontrado = 1;
        }
    }

    return padrao_encontrado;

}

int shiftAnd(char *texto, char *padrao) {
    int tamanho_txt = strlen(texto);
    int tamanho_padrao = strlen(padrao);
    unsigned int mascaras[MAX_CHAR] = {0};
    unsigned int estado = 0;
    unsigned int mascaraFinal = 1 << (tamanho_padrao - 1);
    int padrao_encontrado = 0;

    // Construção das máscaras de bits
    for (int i = 0; i < tamanho_padrao; i++) {
        mascaras[(unsigned char)padrao[i]] |= (1 << i);
    }

    for (int i = 0; i < tamanho_txt; i++) {
        estado = ((estado << 1) | 1) & mascaras[(unsigned char)texto[i]];
        if (estado & mascaraFinal) {
            padrao_encontrado = 1;
        }
    }
    
    return padrao_encontrado;
}