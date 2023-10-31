/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:47:08 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/02 17:03:39 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (i < len)
		{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		}
	}
	else
	{
		while (i != len)
		{
			((unsigned char *)dst)[len - i - 1]
				= ((unsigned char *)src)[len - i - 1];
			i++;
		}
	}
	return (dst);
}

/*int main(int argc, char **argv)
{
	printf("%s\n",(memmove(argv[1], argv[2], 4)));
	printf("%s\n",(ft_memmove(argv[1], argv[2], 4)));
}*/
