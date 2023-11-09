/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:40:42 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/09 15:45:47 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t originalSize, size_t newSize)
{
	void	*newptr;
	size_t	sizecopy;

	sizecopy = originalSize;
	if (newSize == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (newSize < originalSize)
		sizecopy = newSize;
	newptr = malloc(newSize);
	if (!newptr)
		return (NULL);
	if (ptr != NULL)
	{
		memcpy(newptr, ptr, sizecopy);
		free(ptr);
	}
	return (newptr);
}
