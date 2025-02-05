#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limparTerminalUnix();
void criaQuadro(char matriz[20][80]);
void mostraQuadro(char matriz[20][80]);
void limpaQuadro(char matriz[20][80]);
int numeroAleatorioLinha();
int numeroAleatorioColuna();
void asteriscoSimples (char matriz[20][80],int numeroDeAsteriscos);
void somaComAsteriscos(char matriz[20][80],int numeroDeAsterisocs);
void xComAsteriscos(char matri[20][80], int numeroDeAsteriscos);
void figurasAleatorias(char matriz[20][80], int numeroDeFiguras);

//----------TESTES----------------
void testeAsteriscoSimples (char matriz[20][80], int numeroDeAsteriscos);
void testeSomaAsteriscos(char matriz[20][80], int numeroDeAsteriscos);
void testeXComAsteriscos(char matriz[20][80], int numeroDeAsteriscos);
void testeFigurasAleatorias(char matriz[20][80], int numeroDeFiguras);

//----------Minhas Figuras----------------
void arvoreCheia (char matriz[20][80],int numeroDeAsteriscos);
void arvoreDeMaca(char matriz[20][80],int numeroDeAsteriscos);
void arvore2galhos(char matriz[20][80],int numeroDeAsteriscos);
void florestaSalva(char matriz[20][80],int numeroDeAsteriscos);
void florestaQueimada(char matriz[20][80],int numeroDeAsteriscos);
void mostraQuadroLorax(char matriz[20][80]);


