/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:49:05 by nherimam          #+#    #+#             */
/*   Updated: 2024/05/02 10:49:06 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	put_message_received(int signal, siginfo_t *info, void *s)
{
	static int	i;
	static int	bit;

	(void)s;
	if (signal == SIGUSR1)
	{
		kill (info->si_pid, SIGUSR1);
		i |= (0x01 << bit);
	}
	else
		kill (info->si_pid, SIGUSR2);
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
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (1);
	ft_printf ("%d\n", getpid ());
	sa.sa_flags = SA_SIGINFO;
	sigemptyset (&sa.sa_mask);
	sa.sa_sigaction = &put_message_received;
	while (argc == 1)
	{
		sigaction (SIGUSR1, &sa, NULL);
		sigaction (SIGUSR2, &sa, NULL);
		pause ();
	}
	return (0);
}
