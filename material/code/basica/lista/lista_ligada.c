#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    char fone[9];
} Aluno;

typedef struct No {
    Aluno* aluno;
    struct No* proximo;
} No;

typedef struct {
    No* primeiro;
    int tamanho;
} Lista;

Lista* cria_lista(void);
No* cria_no(Aluno* aluno);
Aluno* cria_aluno(const char* nome, const char* fone);

void libera_lista(Lista* lista);
void libera_no(No* no);

// push front
void add(Lista* lista, Aluno* aluno);

// push back
void append(Lista* lista, Aluno* aluno);

// insert at position [0..tamanho]
int insert(Lista* lista, int pos, Aluno* aluno);

// search by name key
Aluno* search(Lista* lista, char* chave);

// is empty?
int is_empty(Lista* lista);

// remove at position [0..tamanho-1], return the removed Aluno*
Aluno* pop(Lista* lista, int pos);

// print list
void imprime_lista(Lista* lista);

/* -------------------- Main (demo) -------------------- */
int main(void) {
    Lista* lista = cria_lista();
    Aluno* pt_aluno;

    add(lista, cria_aluno("Marcos", "1"));
    add(lista, cria_aluno("Maria",  "2"));
    add(lista, cria_aluno("Paulo",  "3"));
    append(lista, cria_aluno("Beatriz", "6"));

    imprime_lista(lista);

    // search example
    pt_aluno = search(lista, "Paulo");
    if (pt_aluno) {
        printf("Found: %s - %s\n", pt_aluno->nome, pt_aluno->fone);
    } else {
        printf("Not found\n");
    }

    // insert example
    insert(lista, 2, cria_aluno("Ana", "7"));
    imprime_lista(lista);

    // pop example
    Aluno* removed = pop(lista, 1);
    if (removed) {
        printf("Popped: %s - %s\n", removed->nome, removed->fone);
        free(removed); // caller frees the removed Aluno
    }
    imprime_lista(lista);

    libera_lista(lista);
    return 0;
}

/* -------------------- Implementations -------------------- */

Lista* cria_lista(void) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (!lista) {
        fprintf(stderr, "Memória não alocada para Lista!\n");
        exit(EXIT_FAILURE);
    }
    lista->primeiro = NULL;
    lista->tamanho = 0;
    return lista;
}

Aluno* cria_aluno(const char* nome, const char* fone) {
    Aluno* pt_aluno = (Aluno*) malloc(sizeof(Aluno));
    if (!pt_aluno) {
        fprintf(stderr, "Não foi possível alocar memória para Aluno!\n");
        exit(EXIT_FAILURE);
    }
    // ensure null-termination
    strncpy(pt_aluno->nome, nome, sizeof(pt_aluno->nome)-1);
    pt_aluno->nome[sizeof(pt_aluno->nome)-1] = '\0';
    strncpy(pt_aluno->fone, fone, sizeof(pt_aluno->fone)-1);
    pt_aluno->fone[sizeof(pt_aluno->fone)-1] = '\0';
    return pt_aluno;
}

No* cria_no(Aluno* aluno) {
    No* no = (No*) malloc(sizeof(No));
    if (!no) {
        fprintf(stderr, "Não foi possível alocar memória para No!\n");
        exit(EXIT_FAILURE);
    }
    no->proximo = NULL;
    no->aluno = aluno;
    return no;
}

int is_empty(Lista* lista) {
    return (lista == NULL) || (lista->tamanho == 0);
}

// push front
void add(Lista* lista, Aluno* aluno) {
    No* pt_no = cria_no(aluno);
    pt_no->proximo = lista->primeiro;
    lista->primeiro = pt_no;
    lista->tamanho++;
}

// push back
void append(Lista* lista, Aluno* aluno) {
    No* pt_no = cria_no(aluno);

    if (!lista->primeiro) {
        lista->primeiro = pt_no;
    } else {
        No* pt_aux = lista->primeiro;
        while (pt_aux->proximo) {
            pt_aux = pt_aux->proximo;
        }
        pt_aux->proximo = pt_no;
    }
    lista->tamanho++;
}

// insert at position [0..tamanho]; returns 1 on success, 0 on error
int insert(Lista* lista, int pos, Aluno* aluno) {
    if (!lista || pos < 0 || pos > lista->tamanho) return 0;

    if (pos == 0) {
        add(lista, aluno);
        return 1;
    }
    if (pos == lista->tamanho) {
        append(lista, aluno);
        return 1;
    }

    No* novo = cria_no(aluno);
    No* atual = lista->primeiro;
    int i = 0;

    // stop at node before target position
    while (i < pos - 1 && atual) {
        atual = atual->proximo;
        i++;
    }
    if (!atual) { // safety
        free(novo);
        return 0;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
    lista->tamanho++;
    return 1;
}

// search by nome; returns Aluno* or NULL
Aluno* search(Lista* lista, char* chave) {
    if (!lista || !chave) return NULL;
    No* atual = lista->primeiro;
    while (atual) {
        if (strcmp(atual->aluno->nome, chave) == 0) {
            return atual->aluno;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// remove node at position [0..tamanho-1]; returns the Aluno* (caller must free it)
Aluno* pop(Lista* lista, int pos) {
    if (!lista || pos < 0 || pos >= lista->tamanho) return NULL;

    No* removido;
    Aluno* aluno;

    if (pos == 0) {
        removido = lista->primeiro;
        lista->primeiro = removido->proximo;
    } else {
        No* atual = lista->primeiro;
        int i = 0;
        while (i < pos - 1 && atual) {
            atual = atual->proximo;
            i++;
        }
        if (!atual || !atual->proximo) return NULL; // safety
        removido = atual->proximo;
        atual->proximo = removido->proximo;
    }

    aluno = removido->aluno; // hand ownership to caller
    free(removido);
    lista->tamanho--;
    return aluno;
}

void imprime_lista(Lista* lista) {
    if (!lista) {
        printf("(lista nula)\n");
        return;
    }
    printf("Lista (tamanho=%d):\n", lista->tamanho);
    No* atual = lista->primeiro;
    int idx = 0;
    while (atual) {
        printf("  [%d] %s - %s\n", idx, atual->aluno->nome, atual->aluno->fone);
        atual = atual->proximo;
        idx++;
    }
}

void libera_no(No* no) {
    if (!no) return;
    free(no->aluno);
    free(no);
}

void libera_lista(Lista* lista) {
    if (!lista) return;
    No* atual = lista->primeiro;
    while (atual) {
        No* prox = atual->proximo;
        libera_no(atual);
        atual = prox;
    }
    free(lista);
}

