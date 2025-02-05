#include "../Headers/listaDuplamenteEncadeada.h"

ponteiroLista criaLista (posicao posicaoAtual){
    
    ponteiroLista lista = (ponteiroLista) malloc(sizeof(lista));  
    lista->posicao.x = posicaoAtual.x;
    lista->posicao.y = posicaoAtual.y;
    lista->prox = NULL;
    lista->ant = NULL;

    return lista;
}

void insereLista(ponteiroLista lista, posicao posicaoAtual) {
    ponteiroLista novo = (ponteiroLista) malloc(sizeof(lista)); // Alocando espaço para o novo nó
    novo->posicao = posicaoAtual; // Atribuindo a estrutura diretamente
    novo->prox = NULL;

    // Se a lista estiver vazia
    if (lista == NULL) {
        novo->ant = NULL;
        lista = novo; // A lista agora é o novo nó
    } else {
        // Caso contrário, insira o novo nó no final da lista
        ponteiroLista aux = lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux; // O nó anterior do novo nó é o último nó da lista
    }
}

void imprimeLista (ponteiroLista lista){
    ponteiroLista aux = lista;
    while (aux != NULL){
        printf("X: %d Y: %d\n",aux->posicao.x,aux->posicao.y);
        aux = aux->prox;
    }
}

void imprimeListaInversa (ponteiroLista lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    // Ir para o último nó
    ponteiroLista aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    // Imprimir de trás para frente
    while (aux != NULL) {
        printf("X: %d Y: %d\n", aux->posicao.x, aux->posicao.y);
        aux = aux->ant;
    }
}
