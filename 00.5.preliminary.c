
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int tab[] = { 1, 2, 3, 4 };
    char str[] = { 'a', 'b', 'c', 'd' };

    printf("tab diff: %lu\n", ((void *)tab + 1) - (void *)tab);
    printf("str diff: %lu\n", (str + 1) - str);

    printf("\n");

    printf("tab:\n\t%p\n\t%p\n", tab, tab + 1);
    printf("str:\n\t%p\n\t%p\n", str, str + 1);
    return (0);
}
