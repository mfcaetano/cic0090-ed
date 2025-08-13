#include <stdio.h>
#include <string.h>


int move(int* grid, int x, int y){
    if(grid[x, y] == -1)
        return -1;

    if(grid[x, y] == 1)
        return 1;

    if(grid[x, y] == 0){

        move(grid, x+1, y);
        move(grid, x, y+1);
        move(grid, x+1, y+1);
    }

}


int main(){
    int times, n;  
    char init[100];
    
    scanf("%d", &times);
   
    for (int i = 0; i < times; i++){
        scanf("%d", &n);

        int grid[2+2][n+2];
        memset(grid, -1, sizeof(grid));

        scanf("%s", init);
        for(int j = 1; j <= n; j++)
            grid[1][j] = (init[j-1] == '0' ? 0 : 1);

        scanf("%s", init);
        for(int j = 1; j <= n; j++)
            grid[2][j] = (init[j-1] == '0' ? 0 : 1);

        switch(move(grid, 1, 1)){
            case 0:
                printf("YES\n");
                break;
            case 1:
                printf("NO\n");
                break;
        }//end switch


        //print grid
        for(int l = 0; l < 4; l++){
            for(int c = 0; c < n+2; c++)
                printf("%d ", grid[l][c]);

            printf("\n");
        }
        printf("\n\n");


    }// for i



}