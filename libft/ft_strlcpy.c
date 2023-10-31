/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:53:38 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/03 17:40:44 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*sc;
	size_t	i;

	i = 0;
	sc = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > 0)
	{
		while (sc[i] != '\0' && i < dstsize - 1)
		{
				dst[i] = sc[i];
				i++;
		}
	}
	dst[i] = '\0';
	while (sc[i] != '\0')
		i++;
	return (i);
}

/*int main (int argc, char **argv)
{
	printf("%lu\n",(ft_strlcpy(argv[1], argv[2], 5)));
	printf("%lu\n",(strlcpy(argv[1], argv[2], 5)));
}*/
