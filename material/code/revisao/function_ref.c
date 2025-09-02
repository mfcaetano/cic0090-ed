#include <stdio.h>

float compute_pair_average(float grade1, float grade2);
float compute_array_average(const float* grades, int n);


// Passagem por valor
void modify_by_value(int x) {
    x = x + 10;
    printf("Dentro de modify_by_value: x = %d, endereço = %p\n", x, (void*)&x);

}

// Passagem por referência
void modify_by_reference(int* x) {
    *x = *x + 10;
    printf("Dentro de modify_by_reference: *x = %d, endereço = %p\n", *x, (void*)x);

}


int main(){
    int a = 5;
    int b = 5;
    
    printf("Antes de modify_by_value: a = %d, endereço = %p\n", a, &a);
    modify_by_value(a);
    printf("Depois de modify_by_value: a = %d, endereço = %p\n\n", a, &a);

    printf("Antes de modify_by_reference: b = %d, endereço = %p\n", b, &b);
    modify_by_reference(&b);
    printf("Depois de modify_by_reference: b = %d, endereço = %p\n\n", b, &b);    

    return 0;
}
