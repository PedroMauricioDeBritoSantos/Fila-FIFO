#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

tipoFila* criar_fila() 
{
    tipoFila *fila_temp = (tipoFila*) malloc(sizeof(tipoFila));
    if (fila_temp == NULL) {
        printf("erro ao alocar a fila.\n");
        exit(1);
    }
    fila_temp->prim = NULL;
    fila_temp->fim = NULL;
    return fila_temp;
}

void inserir_elemento(tipoFila* fila, int dado) 
{
    tipoNo *no = (tipoNo*) malloc(sizeof(tipoNo));
    if (no == NULL) {
        printf("erro ao alocar o nó.\n");
        exit(1);
    }
    no->dado = dado;
    no->prox = NULL;
    no->ant = fila->fim;
    fila->fim = no;

    if (fila->prim == NULL)
        fila->prim = no;
    else
        fila->fim->ant->prox = no;
}

int remover_elemento(tipoFila* fila)
{
    tipoNo* aux;
    int retorno;
    aux = fila->prim;
    fila->prim = fila->prim->prox;
    if (fila->prim == NULL)
        fila->fim = NULL;
    retorno = aux->dado;
    free(aux);
    return retorno; 
}

void imprimir_fila(tipoFila* fila) {
    if (fila->prim == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    tipoNo *aux = fila->prim;
    while (aux) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void liberar_fila(tipoFila* fila)
{
    tipoNo *atual, *prox;
    atual = fila->prim;

    while (atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(fila);
}