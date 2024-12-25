/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:43:53 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/29 16:43:57 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_strcpy(char *newstr, char *str)
{
	while (*str)
		*newstr++ = *str++;
	*newstr = '\0';
}

char	*ft_concat(char *str, char add)
{
	int		i;
	char	*newstr;

	i = 0;
	while (str[i])
		i++;
	newstr = (char *)malloc(sizeof (char) * (i + 2));
	if (!newstr)
		return (NULL);
	ft_strcpy (newstr, str);
	newstr[i++] = add;
	newstr[i] = '\0';
	free (str);
	return (newstr);
}

void	put_message_received(int signal, siginfo_t *info, void *s)
{
	static int	i = 0;
	static int	bit = 0;
	static char	*str = NULL;

	if (!str)
		str = (char *)malloc(sizeof (char));
	if (!str)
		return ;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		str = ft_concat (str, (char)i);
		if (i == 0)
		{
			kill (info->si_pid, SIGUSR1);
			ft_printf ("%s\n", str);
			str[0] = '\0';
		}
		bit = 0;
		i = 0;
	}
	(void)s;
}

int	main(int argc, char **argv)
{
	struct sigaction	new_sa;

	(void)argv;
	if (argc == 1)
	{
		new_sa.sa_flags = SA_SIGINFO;
		new_sa.sa_sigaction = &put_message_received;
		ft_printf ("%d\n", getpid ());
		while (argc == 1)
		{
			sigaction (SIGUSR1, &new_sa, NULL);
			sigaction (SIGUSR2, &new_sa, NULL);
		}
	}
	return (0);
}
