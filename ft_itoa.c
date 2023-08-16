/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:43:23 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/17 23:10:14 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	int_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	power(int base, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

char	*generate_result(int num, int negative, int length, int n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (num + negative + 1));
	if (!result)
		return (NULL);
	if (negative)
	{
		result[0] = '-';
		n = -n;
	}
	result[num + negative] = '\0';
	while (num > 0)
	{
		result[negative + length - num] = n / power(10, num - 1) + '0';
		n = n % power(10, num - 1);
		num--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		num;
	int		negative;
	int		length;

	if (n < 0)
		negative = 1;
	else
		negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = int_len(n);
	length = int_len(n);
	return (generate_result(num, negative, length, n));
}
