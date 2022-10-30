/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:44:44 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/10/28 19:44:48 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/include/ft_printf.h"
#include <stdlib.h>
#include <signal.h>

int g_count;

static void handle_sigusr(int signum, siginfo_t *info, void *ucontext)
{
    static unsigned char c;

    (void)info;
    (void)ucontext;
    if (signum == SIGUSR1)
        c |= 1;
    g_count++;
    if (g_count == 8)
    {
        ft_putchar_fd(c, 1);
        g_count = 0;
    }
    c <<= 1;
}

int main(void)
{
    int i;
    struct sigaction sa;

    g_count = 0;
    i = getpid();
    ft_printf("SERVER PID: %d\n", i);
    sa.sa_sigaction = handle_sigusr;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}
