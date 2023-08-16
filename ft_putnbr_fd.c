/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:36:12 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/16 23:17:52 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	negative;

	negative = 1;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			putchar_fd('-', fd);
			negative = -1;
		}
		n = n * negative;
		while (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			n = n % 10;
		}
		putchar_fd(n % 10 + 48, fd);
	}
}
