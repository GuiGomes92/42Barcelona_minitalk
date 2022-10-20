#include "../ft_printf_lib/include/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handle_sigtstp(int sig)
{
    ft_printf("%d", sig);
    ft_printf("Stop not allowed\n");
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = &handle_sigtstp;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);
    return (0);
}