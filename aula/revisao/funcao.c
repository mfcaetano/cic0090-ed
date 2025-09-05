#include <stdio.h>

float calcula_media(float n1, float n2);
float calcula_media_referencia(float* n1, float* n2);


int main(){
  float n1 = 8.0;
  float n2 = 5.0;
  
  printf("Média: %.2f \n", calcula_media(n1, n2));
  
  printf("Valor n1=%.2f n2=%.2f em main\n", n1, n2);
  
  
  printf("Média: %.2f \n", calcula_media_referencia(&n1, &n2));
  
  printf("Valor n1=%.2f n2=%.2f em main\n", n1, n2);
  
  
  
  return 0;
}

float calcula_media_referencia(float* n1, float* n2){
  *n1 = 20;
  *n2 = 20;
  printf("Valor n1=%.2f n2=%.2f na funcao calcula_media_referencia\n", *n1, *n2);
  return (*n1 + *n2)/2;
}


float calcula_media(float n1, float n2){
  n1 = 10;
  n2 = 10;
  printf("Valor n1=%.2f n2=%.2f na funcao calcula_media\n", n1, n2);
  return (n1 + n2)/2;
}


