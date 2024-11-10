#include <stdio.h>

#define PI 3.14

void outra_funcao();
const float area = 10.0; 
//#define area 10.0


int main(){

    float radius = 5.0;
    //float area =  PI * radius * radius;
    //float area = 20;

    //printf("Área do circulo é: %.2f\n", area);

    outra_funcao();


    return 0;
}

void outra_funcao(){
    //float area;
    printf("Área do circulo é: %.2f\n", area);
}