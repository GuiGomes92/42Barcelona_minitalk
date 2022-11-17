/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:46:45 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/11/17 20:01:45 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/include/ft_printf.h"
#include "../printf/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void	handle_sigusr(int pid, char str)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (str & 0x80)
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(-1);
		}
		usleep(300);
		str <<= 1;
		i++;
	}
}

void	main_handler(int pid, char *str)
{
	while (*str != '\0')
	{
		handle_sigusr(pid, *str);
		str++;
	}
	handle_sigusr(pid, '\0');
	if (ft_printf("\n") == -1)
		exit (-1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		main_handler(pid, argv[2]);
	}
	else
	{
		if (ft_printf("Wrong number of arguments!") == -1)
			exit (-1);
		exit(0);
	}
	return (0);
}
