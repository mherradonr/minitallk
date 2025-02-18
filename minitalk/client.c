/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:48:18 by marherra          #+#    #+#             */
/*   Updated: 2024/06/03 13:50:08 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		g_confirm;

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (str[i++] - '0') + nb * 10;
	return (nb);
}

void	send_chr(char chr, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_confirm = 0;
		if (chr >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_confirm != 1)
			usleep(10);
	}
}

void	sig_usr_handler(int signal)
{
	(void)signal;
	g_confirm = 1;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (1);
	i = -1;
	while (argv[1][++i])
		if ((argv[1][i] < '0' || argv[1][i] > '9') || i > 9)
			return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &sig_usr_handler);
	i = 0;
	while (argv[2][i] && pid > 0)
		send_chr(argv[2][i++], pid);
}
