
#include "../Headers/arquivo.h"

int main(int argc, char const *argv[])
{

    if (argc == 5){
        string nomeArquivo = (string) malloc(strlen(argv[1]) + 1);
        int linha, coluna, vida;


        strcpy(nomeArquivo, argv[1]);
        linha = atoi(argv[2]);
        coluna = atoi(argv[3]);
        vida = atoi(argv[4]);

        gerarArquivo(nomeArquivo,linha,coluna,vida);
        return 0;
    }

    if (argc == 6)
    {
        string nomeArquivo = (string) malloc(strlen(argv[1]) + 1);
        int linha, coluna, vida;


        strcpy(nomeArquivo, argv[1]);
        linha = atoi(argv[2]);
        coluna = atoi(argv[3]);
        vida = atoi(argv[4]);

        gerarAquivosComArmadilhas(nomeArquivo,linha,coluna,vida);
        return 0;
    }
    
    if (argc != 5 || argc != 6){

        fprintf(stderr, "Use para criar arquivos normais: %s NOME=<string-nome> LINHA=<int-linha> COLUNA=<int-coluna> VIDA=<int-vida>\n", argv[0]);
        fprintf(stderr, "Use para criar arquivos com baú: %s NOME=<string-nome> LINHA=<int-linha> COLUNA=<int-coluna> VIDA=<int-vida> <int-qualquer_num>\n", argv[0]);

        
        return 1;
    }
    

}
