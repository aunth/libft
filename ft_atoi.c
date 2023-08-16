/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:12:24 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/17 23:40:46 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <libc.h>

int	strcmp_recursive(const char *str1, const char *str2)
{
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	else if (*str1 == *str2)
		return (strcmp_recursive(str1 + 1, str2 + 1));
	else
		return (*str1 - *str2);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	if (strcmp_recursive(str, "-2147483648") == 0)
		return (-2147483648);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == 11
		|| str[i] == 10 || str[i] == 12 || str[i] == 13 || str[i] == 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
