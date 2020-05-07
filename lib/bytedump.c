#include <stdio.h>

void bytedump(void *mem, size_t bytes)
{
    unsigned char *rdmem = mem;

    for (int byte_index = 0; byte_index < bytes; ++byte_index) {
        for (int bit_index = 0; bit_index < sizeof(void *); ++bit_index) {
            printf("%u", rdmem[byte_index] >> bit_index & 1);
        }
        printf(" ");
    }
    printf("\n");
}

void rbytedump(void *mem, size_t bytes)
{
    unsigned char *rdmem = mem;

    for (int byte_index = bytes - 1; byte_index >= 0; --byte_index) {
        for (int bit_index = sizeof(void *) - 1; bit_index >= 0; --bit_index) {
            printf("%u", rdmem[byte_index] >> bit_index & 1);
        }
        printf(" ");
    }
    printf("\n");
}