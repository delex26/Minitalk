/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:07:03 by hben-mes          #+#    #+#             */
/*   Updated: 2023/01/18 13:25:10 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	ft_knob(int sig, siginfo_t *info, void *p)
{
	static char	str[9];
	static int	count;
	static int	g_pid;
	int			n;

	p = NULL;
	n = info->si_pid;
	if (g_pid != info->si_pid)
	{
		g_pid = info->si_pid;
		count = 0;
	}
	if (sig == SIGUSR1)
		str[count++] = '1';
	else if (sig == SIGUSR2)
		str[count++] = '0';
	if (count == 8)
	{
		ft_convert(str, n);
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	sa.sa_sigaction = &ft_knob;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
