void mostra_arvore(struct ab_int * raiz){
    if(!raiz){
        printf("()");
        return;
    }
    
    printf("(");
    printf("%d ", raiz->dado);
    mostra_arvore(raiz->esq);
    printf(" ");
    mostra_arvore(raiz->dir);
    printf(")");
}
