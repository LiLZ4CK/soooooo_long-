/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:23:52 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/15 16:39:52 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ds;
	char	*sr;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	ds = (char *) dst;
	sr = (char *) src;
	i = 0;
	if (ds > sr)
	{
		while (len--)
			ds[len] = sr[len];
	}
	else
	{
		while (len--)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
