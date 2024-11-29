#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Função: bubble_sort_decrescente
// Descrição: Ordena os elementos da fila em ordem decrescente (do maior para o menor valor)
//            utilizando o algoritmo de bubble sort. A ordenação é feita trocando os valores
//            dos nós diretamente, sem alterar os ponteiros.
// Parâmetros:
//   - fila: Ponteiro para a estrutura `tipoFila` que será ordenada.
// Retorno: Nenhum.
void bubble_sort_decrescente(tipoFila* fila) 
{
    if (fila->prim == NULL || fila->prim->prox == NULL)
        return;

    int trocou;
    tipoNo *atual, *proximo;

    do {
        trocou = 0;
        atual = fila->prim;

        while (atual->prox != NULL) {
            proximo = atual->prox;

            if (atual->dado < proximo->dado) {
                int temp = atual->dado;
                atual->dado = proximo->dado;
                proximo->dado = temp;

                trocou = 1;
            }
            atual = atual->prox;
        }
    } while (trocou);
}


// Função: atender_clientes
// Descrição: Remove todos os elementos da fila, simulando o atendimento de clientes. 
//            Após atender cada cliente, imprime a idade do cliente atendido. 
//            Quando a fila fica vazia, exibe uma mensagem indicando que todos os clientes foram atendidos.
// Parâmetros:
//   - fila: Ponteiro para a estrutura `tipoFila` que será esvaziada.
// Retorno: Nenhum.
void atender_clientes(tipoFila* fila)
{
    while (fila->prim != NULL)
    {
        int cliente_atendido = remover_elemento(fila);
        printf("idade do ultimo cliente atendido: %d\n", cliente_atendido);
    }
    if (fila->prim == NULL)
        printf("todos os clientes foram atendidos!\n\n");
}

int main() 
{
    tipoFila *fila;
    fila = criar_fila();
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) 
    {
        printf("erro ao abrir o arquivo.\n");
        return 1;
    }

    int idade;
    while (fscanf(arquivo, "%d", &idade) != EOF)
    {
        printf("Lido: %d\n", idade); 
        inserir_elemento(fila, idade);
    }
    fclose(arquivo);

    printf("\nfila original:\n");
    imprimir_fila(fila);

    bubble_sort_decrescente(fila);

    printf("\nfila priorizando os mais velhos:\n");
    imprimir_fila(fila);

    atender_clientes(fila);

    liberar_fila(fila);

    return 0;
}