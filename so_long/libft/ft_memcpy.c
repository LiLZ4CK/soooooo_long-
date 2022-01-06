/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:16:11 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/18 13:19:54 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*srcc;
	char	*destt;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	destt = (char *)dst;
	srcc = (char *)src;
	while (n > i)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dst);
}
