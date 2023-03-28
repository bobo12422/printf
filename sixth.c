#include <stdio.h>

int main() {
    char c = 'a';
    int n = 42;
    double d = 3.14159;

    printf("How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print.\n");

    printf("The address of variable c is %p\n", (void*)&c);
    printf("The address of variable n is %p\n", (void*)&n);
    printf("The address of variable d is %p\n", (void*)&d);

    return 0;
}

