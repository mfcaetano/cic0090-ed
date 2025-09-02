#include <stdio.h>

int main(){
	int a = 42;
	char b = 'Z';
	float c = 3.14;
	double d = 2.718281828;
	long long e = 123456789012345;

	int * pt_a;
	float * pt_b;  
	void * pt;
	char* pt_char;

	pt_a = &a; 

	*pt_a = 56; 

	pt_char = (char *) &a; 

	*pt_char = 'A';

	printf("%c\n", *pt_char);



	printf("%p %p %p \n\n", &pt_a, pt_a, &a);

	printf("tamanho %zu %zu %zu\n", sizeof(pt_a), sizeof(pt_b), sizeof(pt));

	printf("int: valor=%d, tam=%zu bytes, %p\n", a, sizeof(a), &a);
	printf("char: valor=%c, tam=%zu bytes, %p\n", b, sizeof(b), &b);
	printf("float: valor=%f, tam=%zu bytes, %p\n", c, sizeof(c), &c);
	printf("double: valor=%lf, tam=%zu bytes, %p\n", d, sizeof(d), &d);
	printf("long long: valor=%lld, tam=%zu bytes, %p\n", e, sizeof(e), &e);



}