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

void	put_message_received(int signal)
{
	static char	*str;
	static int	i;
	static int	bit;

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
			ft_printf ("%s\n", str);
			str[0] = '\0';
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid ();
		ft_printf ("%d\n", pid);
		while (argc == 1)
		{
			signal (SIGUSR1, put_message_received);
			signal (SIGUSR2, put_message_received);
		}
	}
	return (0);
}
