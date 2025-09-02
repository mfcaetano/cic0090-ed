#include <stdio.h>

int main() {
    int a = 42;
    char b = 'Z';
    float c = 3.14f;
    double d = 2.718281828;
    long long e = 123456789012345LL;

    int* ptr = &a;  // Pointer to int

    printf("int: value = %d, size = %zu bytes, address = %p\n", a, sizeof(a), &a);
    printf("char: value = %c, size = %zu bytes, address = %p\n", b, sizeof(b), &b);
    printf("float: value = %.2f, size = %zu bytes, address = %p\n", c, sizeof(c), &c);
    printf("double: value = %.9f, size = %zu bytes, address = %p\n", d, sizeof(d), &d);
    printf("long long: value = %lld, size = %zu bytes, address = %p\n", e, sizeof(e), &e);

    printf("Pointer to int: value = %p, size = %zu bytes, address = %p, points to = %d\n",
           ptr, sizeof(ptr), &ptr, *ptr);

    return 0;
}
