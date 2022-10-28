#include "../printf/include/ft_printf.h"
#include <stdlib.h>
#include <signal.h>

void handle_sigusr(int signum)
{
    (void)signum;
    ft_printf("%d\n", 1);
    usleep(60);
}

int main(void)
{
    // Server has to print quickly the string sent by client
    int i;
    struct sigaction sa;

    i = getpid();
    ft_printf("SERVER PID: %d\n", i);

    sa.sa_handler = &handle_sigusr;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
    {
        pause();
    }
    return 0;
}