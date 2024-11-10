#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char* str, int* count);

int main(){
    int n, m;
    int* pt_arr;
    int* pt_brr;
    char buffer [200];

    scanf("%d", &n);
    fflush(stdin);

    pt_arr = (int *) malloc(n*sizeof(int));

    if ( fgets(buffer, sizeof(buffer), stdin) != NULL ){
        size_t len = strlen(buffer);

        if ( len > 0 && buffer[len - 1] == '\n'){
            buffer[len - 1] = '\0';
        }
    }

    printf("%d\n", n);

    printf("%s\n", buffer);



    free(pt_arr);


}



char** split(const char* str, int* count){
    int capacity = 10;
    char* str_copy = strdup(str);

    if (!str_copy)
        return NULL;

    *count = 0;
    char **result = (char **) malloc(capacity*sizeof(char *));

    char* token = strtok(str_copy, " ");
    while(token){
        if ( *count >= capacity ){
            capacity *= 2;
            result = (char **) realloc(result, capacity * sizeof(char *));
        }

        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, " ");
    }

    free(str_copy);
    return result;
}//end split()