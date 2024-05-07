/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:48:51 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/02 10:48:53 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	confirm_received(int signal)
{
	if (signal == SIGUSR1)
		ft_printf ("received bit 1\n");
	else
		ft_printf ("received bit 0\n");
}

void	send_char_to_bit (int pid, char set)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((set & (0x01 << bit)) != 0)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep (100);
		bit++;
	}
	
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		return (1);
	i = 0;
	pid = ft_atol (argv[1]);
	while (argv[2][i] != '\0')
	{
		signal (SIGUSR1, confirm_received);
		signal (SIGUSR2, confirm_received);
		send_char_to_bit (pid, argv[2][i]);
		i++;
	}
	send_char_to_bit (pid, '\n');
	return (0);
}
