#include <stdio.h>

int main(){
    int n, sum, num;

    scanf("%d", &n);

    sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);

        sum += num;
    }

    printf("%d\n", sum);

}