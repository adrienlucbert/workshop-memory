//########################################//
// #4.1 Manipulating stack-allocated data //
//########################################//

#include <stdio.h>

int *neverdothat(void)
{
    int data = 42;

    return (&data);
    // As soon as the function exists, all stack-allocated memory spaces are marked "free"
    // If they are used after the function exit, it produces an undefined behavior
    // Other data could override it any moment
    // GCC will eventually throw a warning saying "function returns address of local variable"
    // If it may work from time to time, it could just as well crash
    // DON'T DO THAT
}

int main(void)
{
    int data = *neverdothat();

    printf("%d\n", data);
}
