
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[20];
	char fone[9];
} Aluno;


typedef struct No{
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
void libera_no(No * no);

//adiciona no início na lista
void add(Lista* lista, Aluno* aluno);

//adiciona no final da lista
void append(Lista* lista, Aluno* aluno);


//adiciona em uma posição específica da lista
int insert(Lista* lista, int pos, Aluno* aluno);


Aluno* search(Lista* lista, char* chave);

int is_empty(Lista* lista);

//int index(Lista* lista, char* chave);

Aluno* pop(Lista* lista, int pos);

void imprime_lista(Lista* lista);




int main(){
	Lista* lista = cria_lista();
	Aluno* pt_aluno;

	char nome[20];
	char fone[9];

	/*printf("Informe o seu nome: \n");
	scanf("%[^\n]s", nome);
	getchar();
	printf("Informe seu telefone: \n");
	scanf("%[^\n]s", fone);*/

	strcpy(nome, "Marcos");
	strcpy(fone, "1");

	add(lista, cria_aluno(nome, fone));

	strcpy(nome, "Maria");
	strcpy(fone, "2");

	add(lista, cria_aluno(nome, fone));

	strcpy(nome, "Paulo");
	strcpy(fone, "3");

	add(lista, cria_aluno(nome, fone));


	strcpy(nome, "Beatriz");
	strcpy(fone, "6");

	append(lista, cria_aluno(nome, fone));


	//pt_aluno = pop(lista, 2);

	pt_aluno = search(lista, "Paulo");

	
	libera_lista(lista);


}//end main()


void append(Lista* lista, Aluno* aluno){
	No* pt_no = cria_no(aluno);

	//lista vazia
	if(!lista->primeiro){
		lista->primeiro = pt_no;
	}else{
		//lista não estar vazia
		No* pt_aux = lista->primeiro;
	
		//proximo não for NULL
		while(pt_aux->proximo){
			pt_aux = pt_aux->proximo;
		}

		pt_aux->proximo = pt_no;
	}//end if

	lista->tamanho++;
}//end append()


//adiciona no início na lista
void add(Lista* lista, Aluno* aluno){

	No* pt_no = cria_no(aluno);

	pt_no->aluno = aluno;

	pt_no->proximo = lista->primeiro;
	lista->primeiro = pt_no;

	lista->tamanho++;
}//end add


Aluno* cria_aluno(const char* nome, const char* fone){
	Aluno* pt_aluno = (Aluno *) malloc(sizeof(Aluno));

	if(!pt_aluno){
		printf("Não foi possível alocar memória para aluno!\n");
		exit(1);
	}

	strcpy(pt_aluno->nome, nome);
	strcpy(pt_aluno->fone, fone);

	return pt_aluno;
}//end cria_aluno()


No* cria_no(Aluno* aluno){
	No* no = (No *) malloc(sizeof(No));

	no->proximo = NULL;
	no->aluno = aluno;

	return no;

}//end cria_no()


Lista* cria_lista(void){
	Lista* lista = (Lista *) malloc(sizeof(Lista));

	if(!lista){
		printf("Memória não alocada!\n");
		exit(1);
	}


	lista->primeiro = NULL;
	lista->tamanho = 0;

	return lista;
}//end cria_lista



void libera_lista(Lista* lista){
	No* pt_aux = lista->primeiro;


	while(pt_aux){
		lista->primeiro = lista->primeiro->proximo;
		libera_no(pt_aux);
		pt_aux = lista->primeiro;
	}

	free(lista);
}//end libera_lista();


void libera_no(No * no){
	free(no->aluno);
	free(no);
}//end libera_no()







// Imprime todos os elementos da lista
/*void imprime_lista(Lista* l) {
    No* atual = l->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}*/







