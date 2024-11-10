#include <stdio.h>
#include <stdlib.h>

int main(){
    int runs;
    int cat_a, cat_b, mouse;
    int dist_cat_a, dist_cat_b;

    scanf("%d", &runs);
    fflush(stdin);

    for(int i = 0; i < runs; i++){
        scanf("%d %d %d", &cat_a, &cat_b, &mouse);
        fflush(stdin);
mmm
        dist_cat_a = abs(cat_a - mouse);
        dist_cat_b = abs(cat_b - mouse);

        if (dist_cat_a == dist_cat_b){
            printf("Mouse C\n");
        }else if (dist_cat_a < dist_cat_b){
            printf("Cat A\n");
        }else{
            printf("Cat B\n");
        }
    }
}