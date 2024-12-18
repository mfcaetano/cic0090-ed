#include <stdio.h>

int calcula_coca(float n){

    if(n == 1.0)
        return 0;
    else if (n > 1.0 && n < 2.0)
        return 1;

    return ((int) n / 3) + calcula_coca(n / 3);
}

int main(){
    int num;

    while(1){
        scanf("%d", &num);
        
        if (num == 0)
            break;
        
        printf("%d\n", calcula_coca(num));
    }
}