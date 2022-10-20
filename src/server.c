#include "../ft_printf_lib/include/ft_printf.h"
#include <stdlib.h>
#include <signal.h>

void handle_sigusr1()
{
    ft_printf("From Sigur");
}

int main(void)
{
    // Server has to print quickly the string sent by client
    int i;
    struct sigaction sa;

    i = getpid();
    ft_printf("SERVER PID: %d\n", i);

    sa.sa_handler = &handle_sigusr1;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    while (1)
    {
        pause();
    }
    return 0;
}