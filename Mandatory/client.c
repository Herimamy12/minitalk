/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:48:51 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/02 10:48:53 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		i++;
	}
	send_char_to_bit (pid, '\0');
	return (0);
}
