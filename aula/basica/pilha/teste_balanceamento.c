#include <string.h>
#include "stack.h"

/*
 * Verifica se os parênteses, colchetes e chaves estão balanceados.
 * Retorna 1 se estiver tudo certo, 0 caso contrário.
 */
int verificar_balanceamento(const char* expressao) {
    Stack* pilha = create_stack();

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        // Símbolo de abertura → empilha
        if (c == '(' || c == '[' || c == '{') {
            push(pilha, c);
        }
        // Símbolo de fechamento → verifica topo
        else if (c == ')' || c == ']' || c == '}') {
            int topo;
            if (!pop(pilha, &topo)) {
                free_stack(pilha);
                return 0; // Fechamento sem abertura
            }

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                free_stack(pilha);
                return 0; // Par incorreto
            }
        }
    }

    // Se sobrar algo na pilha, há abertura sem fechamento
    int balanceado = is_empty(pilha);
    free_stack(pilha);
    return balanceado;
}

int main(void) {
    const char* testes[] = {
        "{[()()]}",      // correto
        "{[(])}",        // incorreto
        "((()))",        // correto
        "({[)]}",        // incorreto
        "([]{})",        // correto
        "(",             // incorreto
        "[]",            // correto
        "{[()]}}",       // incorreto
        NULL
    };

    printf("=== Teste de balanceamento de símbolos ===\n\n");
    for (int i = 0; testes[i] != NULL; i++) {
        const char* exp = testes[i];
        int ok = verificar_balanceamento(exp);
        printf("Expressão: %-10s → %s\n", exp, ok ? "CORRETA" : "INCORRETA");
    }

    return 0;
}

