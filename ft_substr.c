/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:50:38 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/18 20:34:01 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int	get_len_str(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	index;

	if (len < 2147483647)
		new_str = (char *)malloc(len + 1);
	else
		new_str = (char *)malloc(get_len_str(s) + 1);
	if (get_len_str(s) <= start)
	{
		new_str[0] = '\0';
		return (new_str);
	}
	if (new_str == NULL)
		return (NULL);
	index = 0;
	while (index < len && s[start + index] != '\0')
	{
		new_str[index] = s[start + index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
