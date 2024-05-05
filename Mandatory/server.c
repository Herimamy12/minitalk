/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:49:05 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/02 10:49:06 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_message_received(int signal)
{
	static int	i;
	static int	bit;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf ("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
		return (1);
	pid = getpid ();
	ft_printf ("%d\n", pid);
	while (argc == 1)
	{
		signal (SIGUSR1, put_message_received);
		signal (SIGUSR2, put_message_received);
		pause ();
	}
	return (0);
}
