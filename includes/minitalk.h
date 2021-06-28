/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:49:39 by alvrodri          #+#    #+#             */
/*   Updated: 2021/06/28 10:36:10 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	int	length;
	int	c;
}				t_data;

int		is_digit(char c);
int		ft_atoi(const char *s);
void	ft_error(int message);
void	ft_bzero(void *s, size_t n);

#endif
