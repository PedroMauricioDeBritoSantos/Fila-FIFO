#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo tipoNo;
struct tipoNo {
    int dado;
    tipoNo *prox;
    tipoNo *ant;
};

typedef struct tipoFila tipoFila;
struct tipoFila {
    tipoNo *prim;
    tipoNo *fim;
};

// Função: criar_fila
// Descrição: Aloca dinamicamente uma nova fila do tipo `tipoFila`, inicializando seus ponteiros
//            para NULL (indicando que a fila está vazia) e retornando o ponteiro para a fila criada.
// Parâmetros: Nenhum.
// Retorno: Ponteiro para a nova fila criada.
tipoFila* criar_fila();

// Função: inserir_elemento
// Descrição: Insere um novo elemento no final da fila, criando um novo nó com o dado fornecido.
//            Atualiza os ponteiros para manter a estrutura da fila duplamente encadeada.
// Parâmetros:
//   - fila: Ponteiro para a estrutura `tipoFila` onde o elemento será inserido.
//   - dado: Valor inteiro a ser armazenado no novo nó.
// Retorno: Nenhum.
void inserir_elemento(tipoFila* fila, int dado);

// Função: remover_elemento
// Descrição: Remove o primeiro elemento da fila e retorna seu valor. 
//            Atualiza os ponteiros da fila para refletir a remoção.
// Parâmetros:
//   - fila: Ponteiro para a estrutura `tipoFila` de onde o elemento será removido.
// Retorno: Valor inteiro armazenado no nó removido.
int remover_elemento(tipoFila* fila);

// Função: imprimir_fila
// Descrição: Imprime os valores armazenados na fila, começando do primeiro até o último elemento.
//            Caso a fila esteja vazia, imprime uma mensagem informando isso.
// Parâmetros:
//   - fila: Ponteiro para a estrutura `tipoFila` cuja fila será impressa.
// Retorno: Nenhum.
void imprimir_fila(tipoFila* fila);

// Função: liberar_fila
// Descrição: Libera toda a memória alocada para a fila, incluindo os nós que contêm os elementos 
//            e a estrutura principal da fila. Após a execução desta função, a memória ocupada
//            pela fila é devolvida ao sistema, evitando vazamentos de memória.
// Parâmetros:
//   - fila: Ponteiro para a estrutura `Fila` que será completamente liberada.
// Retorno: Nenhum.
void liberar_fila(tipoFila* fila);