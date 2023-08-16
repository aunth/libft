/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaslian <vmaslian@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:46:32 by vmaslian          #+#    #+#             */
/*   Updated: 2023/07/18 19:09:17 by vmaslian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	index;
	void	*allocated;

	if (count == SIZE_MAX || size == SIZE_MAX || count * size >= SIZE_MAX
		|| ((int)count < 0 && (int)size != 0)
		|| ((int)size < 0 && (int)count != 0))
		return (NULL);
	allocated = malloc(count * size);
	if (allocated == NULL)
		return (NULL);
	index = 0;
	while (index < count * size)
	{
		((unsigned char *)allocated)[index] = (unsigned char)0;
		index++;
	}
	return (allocated);
}
