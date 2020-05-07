
#include <stdio.h>

typedef struct example {
    int first;
    int second;
} example_t;

example_t **st_location(void);

#define g_st (*st_location())

void st_destroy(void)
{
    free(g_st);
}

example_t **st_location(void)
{
    static example_t *st = NULL;

    if (st == NULL) {
        st = malloc(sizeof(example_t));
        atexit(&st_destroy);
    }

    return (&st);
}

int main(void)
{
    // des lors qu'on ecris "g_st", la fonction st_location() est appelé
    g_st->first = 1;
    g_st->second = 42;
}
