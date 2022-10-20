#include "../ft_printf_lib/include/ft_printf.h"
#include "../ft_printf_lib/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

// void handle_sigtstp(int sig)
// {
//      ft_printf("%d", sig);
//      ft_printf("Stop not allowed\n");
// }

int main(int argc, char **argv)
{
    int pid = ft_atoi(argv[1]);
    if (argc == 2)
    {
        ft_printf("%i", pid);
    }
    kill(pid, SIGINT);

    // Check later with other videos:
    // struct sigaction sa;
    // sa.sa_handler = &handle_sigtstp;
    // sa.sa_flags = SA_RESTART;
    // sigaction(SIGTSTP, &sa, NULL);

    return (0);
}