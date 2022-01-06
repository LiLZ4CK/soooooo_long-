/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:48:01 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/18 12:05:50 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*src;
	unsigned char	j;

	src = (char *) b;
	j = (unsigned char)c;
	while (len > 0)
	{
		len--;
		src[len] = j;
	}
	return (b);
}
