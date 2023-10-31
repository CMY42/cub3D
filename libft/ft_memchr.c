/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:53:34 by cmansey           #+#    #+#             */
/*   Updated: 2022/10/28 14:38:45 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	size_t			i;
	unsigned char	*str;
	unsigned char	ndl;

	i = 0;
	str = (unsigned char *)s;
	ndl = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ndl)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int main (void)
{
	char str[] = "qwerty";
	printf("%s\n", (ft_memchr(str, 't', 4)));
	printf("%s\n", (memchr(str, 't', 4)));
}*/
