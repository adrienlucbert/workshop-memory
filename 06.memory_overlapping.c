//########################################//
// #6 Memory overlapping                  //
//########################################//

#include <stdio.h>
#include <memory.h>

struct example {
    int first;
    int second;
    char tab[0];
};

typedef struct example example_t;

static example_t tmp;
static example_t tmp2;

int main(void)
{
    memcpy(tmp.tab, "Hello", 6);

    printf("%p\n", &tmp.tab);
    printf("%p\n", &tmp2.first);
    // tmp.tab being of size 0, and tmp2 being just after tmp in memory,
    // tmp.tab and tmp.first have the same address
    // Thus, writing in tmp.tab means writing in tmp2.first
    printf("%s\n", (char *)&tmp2.first);
    // This demonstrates types are just helpers, they in no mean alter the
    // manner data is stored. A memory space of x bytes can store x bytes of
    // data, whether it is chars, ints, pointers, structures or anything.
    // Types are just a way to help manipulate and visualize data

    // We can dump memory byte per byte to see it. Memory space reserved for
    // tmp2 now contains bytes representing a sequence of chars
    for (size_t index = 0; index < sizeof(example_t); ++index)
        printf("%.8x[%c] ", *(((char *)&tmp2) + index), *(((char *)&tmp2) + index));
    // Notice after the '\0', memory contains some random stuff
    // Not being initialized means it can store residual data from previous use
}