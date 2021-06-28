/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:47:29 by alvrodri          #+#    #+#             */
/*   Updated: 2021/06/28 10:41:00 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

char	*pass_to_binary(char c)
{
	int		i;
	char	*ret;

	if (c > 127 || c < 0)
		ft_error(printf("Only ascii characters allowed.\n"));
	ret = malloc(sizeof(char) * 8);
	if (!ret)
		return (NULL);
	ft_bzero(ret, 8);
	i = 0;
	while (i < 7)
	{
		ret[7 - i] = (c >> i) & 1;
		i++;
	}
	return (ret);
}

void	send_char(int pid, char n)
{
	if (n == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error(printf("Your pid is invalid.\n"));
	}
	else if (n == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error(printf("Your pid is invalid.\n"));
	}
}

void	send_message(int pid, char *str)
{
	char	*binary;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		binary = pass_to_binary(str[i]);
		while (j < 8)
		{
			if (binary[j] == 0)
				send_char(pid, 0);
			else
				send_char(pid, 1);
			usleep(50);
			j++;
		}
		free(binary);
		i++;
	}
}

void	check_syntax(char **argv)
{
	int	i;

	i = 0;
	while (argv[0][i])
	{
		if (!is_digit(argv[0][i]))
			ft_error(printf("Your pid is invalid.\n"));
		i++;
	}
}

int	main(int argc, char **argv)
{
	sigset_t	sig;

	if (argc != 3)
		ft_error(printf("Usage: %s <pid> <message>\n", argv[0]));
	check_syntax(argv + 1);
	sigemptyset(&sig);
	sigaddset(&sig, SIGUSR1);
	send_message(ft_atoi(argv[1]), argv[2]);
}
