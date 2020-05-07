//#############################//
// #1 Structure members offset //
//#############################//

#include <stdio.h> // printf
#include <stddef.h> // offsetof

// #define _offsetof(type, elem) ((size_t) & ((type *)0)->elem)

struct example {
    int a;
    int b;
    char *str;
    char end[0];
};

typedef struct example example_t;

int main(void)
{
    example_t tmp;

    printf("%ld\n", sizeof(tmp)); // 4 + 4 + 8 = 16 (sizeof(end) = 0)
    //     a     b      str    end
    // [[....][....][........][]]
    printf("%ld\n", offsetof(example_t, a)); // offset de a par rapport au début de la structure = 0
    //     a     b      str    end
    // [[....][....][........][]]
    //   ^ offset 0
    printf("%ld\n", offsetof(example_t, b)); // offset de b = 4
    //     a     b      str    end
    // [[....][....][........][]]
    //         ^ offset 4
    printf("%ld\n", offsetof(example_t, str)); // offset de str = 8
    //     a     b      str    end
    // [[....][....][........][]]
    //               ^ offset 8
    printf("%ld\n", offsetof(example_t, end)); // offset de end = 16
    //     a     b      str    end
    // [[....][....][........][]]
    //                         ^ offset 16
}
