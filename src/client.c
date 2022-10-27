#include "../printf/include/ft_printf.h"
#include "../printf/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handle_sigusr(int pid, char str)
{
    int i;

    i = 0;
    while(i < 8)
    {
        if(str & 0x80)
        {
            kill(pid, SIGUSR1);
        }
        i++;

    }
}

void main_handler(int pid, char *str)
{
    while (str)
    {
        ft_printf("%c", str);
        handle_sigusr(pid, *str);
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        // Client takes server PID and String to send
        int pid = ft_atoi(argv[1]);
        ft_printf("%i", pid);
        main_handler(pid, argv[2]);
    }
    else
    {
        ft_printf("Wrong number of arguments!");
        exit(0);
    }
    return (0);
}