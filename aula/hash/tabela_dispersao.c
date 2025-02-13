#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
	char key[50];
	int value;

	struct Node* next;
} Node;

typedef struct{
	Node** buckets;
	int size;
} HashTable;


void print_hash_table(HashTable* table);

unsigned int hash_function(const HashTable* table, const char* key);

HashTable* create_hash_table(int size);

void insert(HashTable* table, const char* key, int value);

int search(HashTable* table, const char* key, int* value);

void free_hash_table(HashTable* table);



unsigned int hash_function(const HashTable* table, const char* key){
	unsigned int hash = 0;

	while(*key){
		hash = (hash * 31) + *key; // Medoto de Horner com base 31
		key++;
	}//end while

	return hash % table->size;
}//end hash_function()


HashTable* create_hash_table(int size){
	HashTable* table = (HashTable *) malloc(sizeof(HashTable));

	if(table){
		table->buckets = (Node **) malloc(size * sizeof(Node *));

		table->size = size;

		if(table->buckets){
			for(int i = 0; i < size; i++)
				table->buckets[i] = NULL;
		}//end if table->buckets

	}//end if table

	return table;
}//end create_hash_table()


void insert(HashTable* table, const char* key, int value){
	unsigned int index = hash_function(table, key);

	Node* new_node = (Node* ) malloc(sizeof(Node));

	if(!new_node){
		printf("Erro ao alocar memoria\n");
		return;
	}

	strcpy(new_node->key, key);
	new_node->value = value;

	new_node->next = table->buckets[index];
	table->buckets[index] = new_node; 

}//end insert()


int search(HashTable* table, const char* key, int* value){
	unsigned int index = hash_function(table, key);
	Node* current = table->buckets[index];

	while(current){

		if( strcmp(current->key, key) == 0 ) {
			*value = current->value;
			return 1;
		}

		current = current->next;

	}//end while

	return 0;
}//end search()

void free_hash_table(HashTable* table){
	Node* current = NULL;

	for(int i = 0; i < table->size; i++){
		current = table->buckets[i];

		while(current){
			Node* aux = current;
			current = current->next;
			free(aux);
		}//end while()
	}//end for i

	free(table->buckets);
	free(table);

}//end free_hahs_table()



// Exibe a tabela hash
void print_hash_table(HashTable* table) {

    for (int i = 0; i < table->size; i++) {
        printf("Bucket %d:", i);
        Node* current = table->buckets[i];
        while (current) {
            printf(" -> [%s, %d]", current->key, current->value);
            current = current->next;
        }
        printf(" -> NULL\n");
    }//end for

}//end print_hash_table()

int main(){
	HashTable* table = create_hash_table(17);

	insert(table, "Alice", 25);
	insert(table, "Bob", 30);
	insert(table, "Charlie", 35);
	insert(table, "David", 40);
	insert(table, "Eve", 45);


	print_hash_table(table);

	int value;

	if(search(table, "Bob", &value)){
		printf("Encontrado: Bob -> %d\n", value);
	} else{
		printf("Bob não encontrado \n");
	}


	if(search(table, "Zoe", &value)){
		printf("Encontrado: Zoe -> %d\n", value);
	} else{
		printf("Zoe não encontrado \n");
	}

	free_hash_table(table);

	return 0;

}//end main()

