/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:40:31 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/16 15:34:07 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize)
{
	size_t	i;
	size_t	z;

	z = 0;
	i = 0;
	while (src [z] != '\0')
		z++;
	if (dstsize == 0)
		return (z);
	if (dstsize != 0)
	{
		while (src [i] != '\0' && i < (dstsize - 1))
		{
			dst [i] = src [i];
			i++;
		}
	}
	dst[i] = '\0';
	return (z);
}
