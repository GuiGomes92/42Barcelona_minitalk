#include "../printf/include/ft_printf.h"
#include <stdlib.h>
#include <signal.h>

void handle_sigusr(int signum)
{
    if (signum == SIGUSR1)
        ft_putint(0);
    else
        ft_putint(1);
}

int main(void)
{
    // Server has to print quickly the string sent by client
    int i;
    struct sigaction sa;

    i = getpid();
    ft_printf("SERVER PID: %d\n", i);

    sa.sa_handler = handle_sigusr;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();
}