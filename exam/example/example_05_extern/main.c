#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    extern int32_t flag;

    printf("flag is %d!\n", flag);

    return 0;
}
