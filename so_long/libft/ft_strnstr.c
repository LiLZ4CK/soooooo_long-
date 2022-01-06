/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:43:37 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/19 11:00:40 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*nd_finder(char *nd, char *hs, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < len && hs[i])
	{
		if (hs[i] == nd[j])
		{
			while (nd[j] && nd[j] == hs[i + j] && (j + i) < len)
			{
				if (nd[j + 1] == '\0')
				{
					return (hs + i);
				}
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;
	char	*nd;
	char	*hs;

	nd = (char *)needle;
	hs = (char *)haystack;
	i = 0;
	str = 0;
	if (needle[i] == '\0')
		return (hs);
	str = nd_finder(nd, hs, len);
	return (str);
}
