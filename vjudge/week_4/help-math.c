#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
case 1+1+3+1+3
case 3+2+1
case 2
 */

void split(const char* equation, int* numbers, int* size){
    char cnum[10];

    for(int i = 0, j = 0; i < strlen(equation); i++ ){
        //ASCII +
        if(equation[i] == 43){
            numbers[(*size)++] = atoi(cnum);
            cnum[0] = '\0';
            j = 0;
        }else{
            cnum[j++] = equation[i];
            cnum[j] = '\0';
        }

    }

    numbers[(*size)++] = atoi(cnum);
}//end split

void bubble_sort(int* numbers, int len){
    int aux;

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len-1; j++){
            if(numbers[j] > numbers[j+1]){
                aux = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = aux;
            }
        }

    }

}//end sort



int main(){
    char equation[10000];
    int numbers[200];
    int len = 0;

    
    scanf("%s", equation);

    split(equation, numbers, &len);
    
    bubble_sort(numbers, len);

    if(len == 1)
        printf("%d\n", numbers[0]);
    else{
        for(int i = 0; i < len-1; i++)
            printf("%d+", numbers[i]);

        printf("%d\n", numbers[len-1]);
    }
}//end main