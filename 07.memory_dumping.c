//########################################//
// #7 Memory dumping                      //
//########################################//

#include <stdio.h>
#include <memory.h>
#include <fcntl.h>
#include <unistd.h>

struct example {
    int first;
    int second;
    char *tab;
};

typedef struct example example_t;

int main(int argc, char **argv)
{
    example_t ex;

    if (argc == 1) {
        printf("DUMPING\n");

        int fd = open("file.dat", O_CREAT | O_WRONLY | O_RDONLY);

        ex.first = 42;
        ex.second = -1;
        ex.tab = "Hello";

        write(fd, &ex, sizeof(ex));
    } else {
        printf("RECOVERING\n");

        int fd = open("file.dat", O_RDONLY);

        read(fd, &ex, sizeof(example_t));
    }
    printf("%d\n%d\n%p\n", ex.first, ex.second, ex.tab);

    // segfault lors si on passe par "RECOVERING"
    // car seule l'adresse est dumpé (et pas ce qui est en dessous)
    printf("%s\n", ex.tab);
}
