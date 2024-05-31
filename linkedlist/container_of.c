#if 1
#include <stdio.h>
#define container_of(ptr, type, member) \
    (type*)((char*)ptr-(unsigned long)&((type*)0)->member)


typedef struct
{
    int a;
    int b;
    int c;
} aaa;

int main() {
    aaa AAA = {1, 2, 3};
    int *temp = &AAA.c;
    aaa *p;
    p =  container_of(temp, aaa, c);
    printf("%d, %d, %d\n", p->a, p->b, p->c);
}

#endif

