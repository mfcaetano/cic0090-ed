#include <stdio.h>
#include <string.h>

/* 
case: saveChangesInTheEditor
*/

int main(){
    char name[100000];
    int words;

    scanf("%s", name);


    words = 1;
    for(int i = 0; i < strlen(name); i++){
        
        if( name[i] >= 65 && name[i] <= 90){
            words++;
        }
    }

    printf("%d\n", words);

}