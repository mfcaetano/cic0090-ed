
#ifndef __LISTA_H__
#define __LISTA_H__

#define RETORNO_OK 1
#define RETORNO_ERRO 0

typedef struct No{
    int dado;
    struct No* proximo;
} No;

typedef struct Lista{
    No* inicio;
    int tamanho;
} Lista;

Lista* cria_lista(void);
No* cria_no(int numero);

// Adiciona elemento no inicio da lista
void add(Lista* lista, int item);

// Adiciona elemento no final da lista
void append(Lista* lista, int item);

// Adiciona elemento em uma posição específica da lista
int insert(Lista* lista, int pos, int item);

// Remove um elemento da lista se existir
int remove_item(lista* lista, int item);

// Procura e retorna um elemento da lista
int search(Lista* lista, int item);

// Verifica se a lista está vazia
int is_empty(Lista* lista);

// retorna posição de um item da lista
int index(Lista* lista, int item);

// remove e retorna o último item da lista
int pop(Lista* lista);

// remove e retorna um item de uma posição específica
int pop_posicao(Lista* lista, int pos);





// Imprime todos os elementos da lista
void imprime_lista(Lista* l);

#endif
