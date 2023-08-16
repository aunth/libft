/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:12:49 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/17 20:33:12 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	length(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	len = length(s);
	ptr = NULL;
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			ptr = (char *)&s[len];
			break ;
		}
		len--;
	}
	return (ptr);
}
