#include <stdio.h>
#include <stdlib.h>

/*
input:
5 4
1 2 3 4 5

output:
5 1 2 3 4
*/

int main(){
    int n, d;
    int* numbers;
    int aux;

    scanf("%d %d", &n, &d);

    numbers = (int *) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);


    for(int i = 0; i < d; i++){
        //left rotation
        aux = numbers[0];
        for(int j = 0; j < n-1; j++)
            numbers[j] = numbers[j+1];
        numbers[n-1] = aux;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    free(numbers);
}
