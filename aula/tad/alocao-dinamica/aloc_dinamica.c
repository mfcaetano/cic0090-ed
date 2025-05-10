
#include <stdlib.h>
#include <stdio.h>


typedef struct {
	char* nome;
	float* notas;
} Aluno;


Aluno * aloca_aluno(int tam_nome, int qt_notas);
void libera_aluno(Aluno* pt_aluno);
void ler_dados(Aluno *pt_aluno, int indice_aluno);



int main(){
	Aluno* pt_aluno = aloca_aluno(1000, 5);



	char nome[1000];




	ler_dados(pt_aluno, 1);

	printf("Nome do aluno %d: %s\n", 1, pt_aluno->nome);

    for(int j = 0; j < 5; j++){
    	printf("Nota %d do aluno %d: %f\n", j+1, 1, pt_aluno->notas[j]);
    }


    //free(pt_aluno);


    libera_aluno(pt_aluno);


}



Aluno * aloca_aluno(int tam_nome, int qt_notas){
	Aluno* pt_aluno = (Aluno *) malloc(sizeof(Aluno));

	//teste

	pt_aluno->nome = (char *) malloc(tam_nome*sizeof(char));

	//testo o retorno de malloc

	(*pt_aluno).notas = (float *) malloc(qt_notas*sizeof(float));

	//testo o retorno de malloc

	return pt_aluno;
}//end aloca_aluno()


void libera_aluno(Aluno* pt_aluno){
	free(pt_aluno->nome);
	free(pt_aluno->notas);
	free(pt_aluno);
}//end libera_aluno;



void ler_dados(Aluno * pt_aluno, int indice_aluno){

    printf("Informe o nome do aluno %d: \n", indice_aluno);
    //scanf("%[^\n]s", (*pt_aluno).nome);
    scanf("%[^\n]s", pt_aluno->nome); //outra forma de fazer
    fflush(stdin);

    for(int i = 0; i < 5; i++){
        printf("Informe a nota %d do aluno %d:\n", i+1, indice_aluno);
        scanf("%f", &pt_aluno->notas[i]);
        getchar();
    }

} //end ler_dados()


