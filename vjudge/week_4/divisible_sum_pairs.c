#include <stdio.h>
#include <stdlib.h>

/*
input:
6 3
1 3 2 6 1 2

output:
5
*/

int main(){
    int n, k;
    int* numbers;
    int divisible;
    scanf("%d %d", &n, &k);

    numbers = (int *) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    divisible = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if((numbers[i] + numbers[j]) % k == 0)
                divisible++;
        }//end for j
    }//end for i

    printf("%d\n", divisible);

    free(numbers);
}//end main
