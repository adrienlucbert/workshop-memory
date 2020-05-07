//########################################//
// #4.2 Manipulating stack-allocated data //
//########################################//

#include <stdio.h>

struct example {
    int x;
    int y;
};

typedef struct example example_t;

void init_example(example_t *data)
{
    data->x = 4;
    data->y = 2;
}

void init_int(int *data)
{
    *data = 42;
}

int main(void)
{
    example_t data;
    int integer;

    init_example(&data);
    init_int(&integer);
    // This is totally possible. Create stack-allocated memory spaces and pass their
    // address to a function to do stuff with them (initialize them, for instance).
    // Just keep in mind you mustn't use these variables after the current function exits.
    printf("%d\n", integer);
    printf("(%d;%d)\n", data.x, data.y);
}