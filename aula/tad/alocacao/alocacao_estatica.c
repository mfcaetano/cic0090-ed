
#include <stdio.h>


typedef struct {
	char nome[20];
	float notas[3];
} Aluno;


void ler_do_teclado(Aluno * pt_aluno);


int main(){
	Aluno aluno;

	printf("conteúdo1 %p\n", &aluno);

	ler_do_teclado(&aluno);


	int a = 2;
	int *pt_a;

	pt_a = &a;

    printf("conteúdo1 %p\n", &a);
    printf("conteúdo1 %p\n", pt_a);

    printf("conteudo de a: %d \n", a);
    printf("conteudo do ponteiro de a: %d \n", *pt_a);


    *pt_a = 4;

	printf("novo conteudo de a: %d \n", a);





	printf("Nome: %s \n", aluno.nome);

	for(int i = 0; i < 3; i++){
		printf("n%d: %f \n", i+1, aluno.notas[i]);
	}







}//end main






void ler_do_teclado( Aluno * pt_aluno  ){

	printf("conteúdo2 %p\n", pt_aluno);

	/*printf("Informe seu nome: \n");
	scanf("%[^\n]s", pt_aluno.nome);


	for(int i = 0; i < 3; i++){
		printf("Informe n%d: \n", i+1);
		scanf("%f", &pt_aluno.notas[i]);
	}*/
}

