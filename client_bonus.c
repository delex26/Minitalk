/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:06:45 by hben-mes          #+#    #+#             */
/*   Updated: 2023/01/16 22:46:24 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk_bonus.h"

void	ft_confirm_message(int signal)
{
	if (signal == SIGUSR1)
		write(1, "RECEIVED\n", 9);
}

void	ft_shoot(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		write(1, "error\n", 7);
	if (argc == 3)
	{
		signal(SIGUSR1, ft_confirm_message);
		pid = ft_atoi(argv[1]);
		ft_shoot(pid, '\n');
		while (argv[2][i])
			ft_shoot(pid, (unsigned char)argv[2][i++]);
		ft_shoot(pid, '\0');
	}
	return (0);
}
