#include <stdio.h>
#include <stdlib.h>

int compara_floats(const void* n1, const void* n2){
  return *((float *) n2) > *((float *) n1); 
}//end compara_floats


int main(){
  int n;
  float* p_iras;
  
  scanf("%d", &n);
  
  p_iras = (float *) malloc(n*sizeof(float));
  
  for(int i = 0; i < n; i++)
    scanf("%f", &p_iras[i]);
  
  qsort(p_iras, n, sizeof(float), compara_floats);
  
  for(int i = 0; i < n; i++)
    printf("%.2f\n", p_iras[i]);
  
  free(p_iras);
  
}//end main
