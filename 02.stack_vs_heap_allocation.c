//#############################//
// #2 Stack vs Heap allocation //
//#############################//

#include <stdio.h>
#include <stdlib.h>

struct example {
    int a;
    int b;
    char *str;
};

typedef struct example example_t;

int main(void)
{
    example_t stack_tmp;
    example_t *heap_tmp = malloc(sizeof(example_t));

    printf("%ld\n", sizeof(stack_tmp)); // sizeof(example_t) = 16
    // A 16-bytes-long memory space is allocated on stack for the current function's scope
    // It will be freed as soon as the current function exits
    printf("%ld\n", sizeof(heap_tmp)); // sizeof(example_t *) = 8 (size of pointer)
    // A 16-bytes-long memory space is allocated on heap with malloc, but the heap_tmp variable 
    // is a 8-bytes-long stack-allocated memory space containing a pointer to (the address of) the 
    // 16-bytes-long heap-allocated memory space (example_t structure)
    printf("%ld\n", sizeof(*heap_tmp)); // sizeof(example_t) = 16
    // If we look at the value pointer to by heap_tmp pointer, we get the 16-bytes-long
    // heap-allocated memory space (example_t structure)
}