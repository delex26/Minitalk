/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:35:15 by hben-mes          #+#    #+#             */
/*   Updated: 2023/01/24 12:56:21 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

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
		pid = ft_atoi(argv[1]);
		ft_shoot(pid, '\n');
		while (argv[2][i] != '\0')
		{
			ft_shoot(pid, argv[2][i]);
			i++;
		}
	}
	return (0);
}
