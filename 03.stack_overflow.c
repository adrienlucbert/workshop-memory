//#############################//
// #3 Stack overflow           //
//#############################//

void overflower(void)
{
    int tmp;
    // tmp is a 4-bytes-long stack-allocated memory space
    // Stack-allocations are freed at current function exit. However, overflower 
    // calling itself before exiting will never exit, and continue allocating memory 
    // on stack. The stack size being limited, it gets filled up in no time, and
    // a Stack Overflow exception is thrown.
    overflower();
}

int main(void)
{
    overflower();
}