/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 01:13:22 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/19 19:51:21 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>

int	count_words(const char *s, char c)
{
	int	count;
	int	i;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			in_word = 0;
		}
		i++;
		in_word = 1;
	}
	if (in_word)
		count++;
	return (count);
}

char	*get_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i++] = s[start++];
	}
	word[i] = '\0';
	return (word);
}

char	**get_result(char **result, char const *s, char c)
{
	int		i;
	int		start;
	int		word_number;

	i = 0;
	start = 0;
	word_number = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			result[word_number] = get_word(s, start, i);
			word_number++;
			start = i + 1;
		}
		i++;
	}
	if (i != start)
	{
		result[word_number] = get_word(s, start, i);
		word_number++;
	}
	result[word_number] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	result = get_result(result, s, c);
	return (result);
}
