/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:49:02 by alvrodri          #+#    #+#             */
/*   Updated: 2021/06/28 10:55:08 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	receive_message(int code)
{
	t_data	*data;

	data = get_data();
	data->length++;
	if (code == SIGUSR1)
		data->c += 0 << (8 - data->length);
	else if (code == SIGUSR2)
		data->c += 1 << (8 - data->length);
	if (data->length >= 8)
	{
		write(1, &data->c, 1);
		data->length = 0;
		data->c = 0;
	}
}

int	main(void)
{
	t_data	*data;

	data = get_data();
	data->length = 0;
	data->c = 0;
	printf("Server is running with pid %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, receive_message);
		signal(SIGUSR2, receive_message);
		pause();
	}
}
