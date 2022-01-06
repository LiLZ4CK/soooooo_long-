/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:53:12 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/20 18:36:33 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	len_len(int len, long n, int s)
{
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (s < 0)
		return (len + 1);
	return (len);
}

static char	*ft_tetoi(char *str, long num, int s)
{
	int	len;

	len = 0;
	len = len_len(len, num, s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
	}
	if (s < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		s;

	s = 1;
	num = n;
	str = 0;
	if (num < 0)
	{
		num *= -1;
		s = -1;
	}
	if (num == 0)
		return (ft_strdup("0"));
	str = ft_tetoi(str, num, s);
	return (str);
}
