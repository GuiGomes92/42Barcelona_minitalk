#include "../printf/include/ft_printf.h"
#include "../printf/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handle_sigusr(int pid, char str)
{
    int i;
    ft_printf("%c:", str);
    i = 0;
    while (i < 8)
    {
        if (str & 0x80)
        {
            kill(pid, SIGUSR1);
            ft_printf("0");
        }
        else
        {
            kill(pid, SIGUSR2);
            ft_printf("1");
        }
        usleep(3000);
        str <<= 1;
        i++;
    }
    ft_printf("\n");
}

// Go over string
void main_handler(int pid, char *str)
{
    while (*str != '\0')
    {
        handle_sigusr(pid, *str);
        str++;
    }
    ft_printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        // Client takes server PID and String to send
        int pid = ft_atoi(argv[1]);
        main_handler(pid, argv[2]);
    }
    else
    {
        ft_printf("Wrong number of arguments!");
        exit(0);
    }
    return (0);
}