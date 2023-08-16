/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:19:01 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/18 21:28:16 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

// int	in_set(char c, char const *set)
// {
// 	int	i;

// 	i = 0;
// 	while (set[i])
// 	{
// 		if (set[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	end_of_str(char const *s1, char const *set, int len)
// {
// 	int	last_index;

// 	last_index = len - 1;
// 	while (last_index >= 0)
// 	{
// 		if (!(in_set(s1[last_index], set)))
// 			return (last_index);
// 		last_index--;
// 	}
// 	return (0);
// }

// int	start_of_str(char const *s1, char const *set)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i])
// 	{
// 		if (!(in_set(s1[i], set)))
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

// void	strncpy1(char *dst, char const *src, int start, int end)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i] && i < end - start + 1)
// 	{
// 		dst[i] = src[start + i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		len;
// 	int		start;
// 	int		end;
// 	char	*result;

// 	len = 0;
// 	while (s1[len])
// 		len++;
// 	end = end_of_str(s1, set, len);
// 	printf("end = %d\n", end);
// 	start = start_of_str(s1, set);
// 	printf("Start = %d\n", start);
// 	if ((end - start) < 0)
// 	{
// 		result = (char *)malloc(1 * sizeof(char));
// 		if (result)
// 			result[0] = '\0';
// 		return (result);
// 	}
// 	result = (char *)malloc((end - start + 1) * sizeof(char));
// 	strncpy1(result, s1, start, end);
// 	return (result);
// }

int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	end_of_str(char const *s1, char const *set, int len)
{
	int	last_index;

	last_index = len - 1;
	while (last_index >= 0)
	{
		if (!(in_set(s1[last_index], set)))
			return (last_index);
		last_index--;
	}
	return (0);
}

int	start_of_str(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!(in_set(s1[i], set)))
			return (i);
		i++;
	}
	return (i);
}

void	strncpy1(char *dst, char const *src, int start, int end)
{
	int	i;

	i = 0;
	while (src[start + i] && start + i <= end)
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	end = end_of_str(s1, set, len);
	start = start_of_str(s1, set);
	if ((end - start) < 0)
	{
		result = (char *)malloc(1 * sizeof(char));
		if (result)
			result[0] = '\0';
		return (result);
	}
	result = (char *)malloc((end - start + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	strncpy1(result, s1, start, end);
	return (result);
}
