/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:51:59 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/15 16:52:11 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	long	num;

	num = nb;
	if (num < 0)
	{
		num *= -1;
		write (fd, "-", 1);
	}
	if (num >= 0 && num <= 9)
	{
		num = num + '0';
		write (fd, &num, 1);
	}
	else if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
}
