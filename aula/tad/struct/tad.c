#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[20];
	int idade;
	float media;
	char eu;
} Aluno;


typedef enum {
	DOMINGO,
	SEGUNDA,
	TERCA,
	QUARTA,
	QUINTA,
	SEXTA,
	SABADO
} DiaDaSemana;

//typedef enum DiadaSemana dia_da_semana;

int main(){

	Aluno aluno;

	//aluno.nome = "Jõao Pedro";

	strcpy(aluno.nome, "João Pedro");

	aluno.idade = 18;
	aluno.media = 5.0;


	printf("Nome: %s\n", aluno.nome);
	printf("Idade: %d\n", aluno.idade);
	printf("Media: %f\n", aluno.media);


	printf("tamnho é %ld\n", sizeof(aluno));

	printf("Endereço de Aluno: %p\n", &aluno);
	printf("Endereço Nome: %p\n", &aluno.nome);
	printf("Endereço Idade: %p\n", &aluno.idade);
	printf("Endereço Media: %p\n", &aluno.media);


/*	DiaDaSemana dia = SABADO;




	printf("O dia da semana é:");
	switch(dia){
	case SABADO:
		printf(" Sábado\n");
		break;
	case SEGUNDA:
		printf(" Segunda\n");
		break;

	}

	printf("O dia de hoje é: %d \n", dia);


	if(dia == SABADO){
		printf("Não temos aula\n");
	}*/


}
