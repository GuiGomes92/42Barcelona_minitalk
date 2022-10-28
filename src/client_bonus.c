/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:46:45 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/10/28 19:46:48 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/include/ft_printf.h"
#include "../printf/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void received(int signum)
{
    static int byte_count = 0;

    if (signum == SIGUSR2)
        byte_count++;
    if (ft_printf("\r\e[1;34mSending [%d] bits\e[0m", byte_count) == -1)
        exit (-1);
    if (signum == SIGUSR1)
    {
        if (ft_printf("\r\e[1;34mDone at [%d] bits\e[0m", byte_count) == -1)
            exit (-1);
        exit (EXIT_SUCCESS);
    }
}

void handle_sigusr(int pid, char str)
{
    int i;
    int signal;
    int kill_response;

    i = 0;
    while (i < 8)
    {
        if (str & 0x80)
            signal = SIGUSR1;
        else
            signal = SIGUSR2;
        kill_response = kill(pid, signal);
        usleep(200);
        if (kill_response < 0)
            exit (-1);
        usleep(300);
        str <<= 1;
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 3)
    {
        signal(SIGUSR1, received);
        signal(SIGUSR2, received);
        int pid = ft_atoi(argv[1]);
        while (argv[2][i] != '\0')
        {
            handle_sigusr(pid, argv[2][i]);
            i++;
        }
        handle_sigusr(pid, '\0');
        ft_printf("\n");
    }
    else
    {
        ft_printf("Wrong number of arguments!");
        exit(0);
    }
    while (1)
        pause();
    return (0);
}
