/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:43:29 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/29 16:43:45 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	confirm_received(int signal)
{
	if (signal == SIGUSR1)
		ft_printf ("All message received\n");
}

void	send_char_to_bit(int pid, char set)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((set & (1 << bit)) != 0)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep (150);
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
		send_char_to_bit (pid, argv[2][i]);
		signal (SIGUSR1, confirm_received);
		i++;
	}
	send_char_to_bit (pid, '\0');
	return (0);
}
