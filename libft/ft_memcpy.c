/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:17:20 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/03 14:59:24 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*str;
	char		*strdst;
	size_t		i;

	str = src;
	strdst = dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		strdst[i] = str[i];
		i++;
	}
	return (dst);
}

/*int main(int argc, char **argv)
{
	printf("%s\n",(memcpy(argv[1], argv[2], 7)));
	printf("%s\n",(ft_memcpy(argv[1], argv[2], 7)));
}*/
