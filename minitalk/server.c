/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:33:28 by marherra          #+#    #+#             */
/*   Updated: 2024/06/03 13:50:17 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	char	chr;

	if (nb > 9)
		ft_putnbr(nb / 10);
	chr = nb % 10 + '0';
	write(1, &chr, 1);
}

void	send_chr(int signal, siginfo_t *pid, void *opt)
{
	static int	chr;
	static int	i = 0;

	(void)opt;
	if (signal == SIGUSR1)
		chr = chr << 1 | 1;
	else
		chr = chr << 1;
	if (++i == 8)
		i = write(1, &chr, 1) - 1;
	kill(pid->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sg;

	write(1, "PID: ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sg.sa_sigaction = send_chr;
	sg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sg, 0);
	sigaction(SIGUSR2, &sg, 0);
	while (1)
		pause();
}
