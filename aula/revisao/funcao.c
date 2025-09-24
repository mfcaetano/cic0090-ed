#include <stdio.h>

float calcula_media(float notas, float n2);
float calcula_media_referencia(float* notas, float* n2);


int main(){
  float notas = 8.0;
  float n2 = 5.0;
  
  printf("Média: %.2f \n", calcula_media(notas, n2));
  
  printf("Valor notas=%.2f n2=%.2f em main\n", notas, n2);
  
  
  printf("Média: %.2f \n", calcula_media_referencia(&notas, &n2));
  
  printf("Valor notas=%.2f n2=%.2f em main\n", notas, n2);
  
  
  
  return 0;
}

float calcula_media_referencia(float* notas, float* n2){
  *notas = 20;
  *n2 = 20;
  printf("Valor notas=%.2f n2=%.2f na funcao calcula_media_referencia\n", *notas, *n2);
  return (*notas + *n2)/2;
}


float calcula_media(float notas, float n2){
  notas = 10;
  n2 = 10;
  printf("Valor notas=%.2f n2=%.2f na funcao calcula_media\n", notas, n2);
  return (notas + n2)/2;
}


