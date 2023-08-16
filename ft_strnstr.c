/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:23:19 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/17 22:24:26 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int	string_length(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		haystack_len;
	int		needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	haystack_len = string_length(haystack);
	needle_len = string_length(needle);
	if (needle_len > haystack_len)
		return (NULL);
	i = 0;
	while (haystack[i + needle_len - 1] != '\0' && len >= i + needle_len)
	{
		if (strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
