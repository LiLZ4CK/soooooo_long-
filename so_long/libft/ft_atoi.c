/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:24:21 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/07 18:49:15 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	signe(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	n;
	long	c;

	i = 0;
	j = 1;
	n = 0;
	c = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	j = signe(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		if (n < c && j == -1)
			return (0);
		if (n < c)
			return (-1);
		c = n;
		i++;
	}
	return (j * n);
}
