//########################################//
// #5 Runtime stack allocation ?          //
//########################################//

#include <stdio.h>
#include <string.h>

struct example {
    int a;
    int b;
    char tab[];
};

typedef struct example example_t;

static example_t tmp2;

int main(void)
{
    example_t tmp;

    printf("%ld\n", sizeof(tmp)); // 8
    // What is char tab[] size?
    // => 0
    // char[] is equal to char[0] if it is not initialized
    // char str[] = "123" would produce a char[4] (including '\0'),
    // but otherwise it produces a char[0]

    // However, you can write in it. You'll face invalid writes or worse (undefined behavior)
    // For some reason, writing in a non-static memory space will cause a stack smashing
    // whereas writing in a static memory space will cause no error, but undefined behavior
    // more than undefined behavior, writing in a region of size 0 will override the following memory 
    // space, which can cause severe issues
    tmp2.tab[0] = 'a';
    tmp2.tab[1] = 'b';
    tmp2.tab[2] = 'c';
    tmp2.tab[3] = '\0';
    printf("%s\n", tmp2.tab);
    // Using memcpy or functions depending on memcpy will cause an overflow warning
    strcpy(tmp2.tab, "Hello!");
    printf("%s\n", tmp2.tab);
}