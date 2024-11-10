#include <stdio.h>

int main(){
    char nome[20];
    printf("Digite seu nome: ");

    scanf("%[^\n]s", &nome);

    printf("Nome informado: %s\n", nome);
}