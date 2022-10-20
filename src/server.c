#include "../ft_printf_lib/include/ft_printf.h"
#include <stdlib.h>

int main(void)
{
    int i;

    i = getpid();
    ft_printf("SERVER PID: %d\n", i);
    while (1)
    {
        pause();
    }
    return 0;
}