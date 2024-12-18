#include <stdio.h>
#include <stdlib.h>

struct lista_compras{
    char nome_produto[20];
    float valor;
};

void imprime_lista(struct lista_compras* lista, int n){
    for(int i = 0; i < n; i++){
        printf("%s %.2f\n", lista[i].nome_produto, lista[i].valor);
    }
}


int main() {
    struct lista_compras minha_lista[5];

    for(int i = 0; i < 3; i++){
        printf("Informe o nome do produto: \n");
        scanf("%[^\n]s", minha_lista[i].nome_produto);
        getchar();

        printf("Informe o valor:\n");
        scanf("%f", &minha_lista[i].valor);
        getchar();
    }

    imprime_lista(minha_lista, 3);




    printf("Hello world!\n");
    return 0;




}
