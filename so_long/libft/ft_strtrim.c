/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:59:07 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/26 23:57:41 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_cmp(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*trim;
	int		d;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && !ft_cmp((char *)set, s1[i]))
		i++;
	len = ft_strlen((char *)s1) - 1;
	while (len >= 0 && !ft_cmp((char *)set, s1[len]))
		len--;
	d = len - i;
	if (d < 0)
		d = 0;
	trim = (char *) malloc(d + 2);
	if (!trim)
		return (0);
	ft_memcpy(trim, s1 + i, d + 2);
	trim[d + 1] = '\0';
	return ((char *)trim);
}
