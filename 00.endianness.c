#include "mem.h"

int main(void)
{
    short x = 1;

    bytedump(&x, sizeof(x));
}