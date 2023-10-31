/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:29 by cmansey           #+#    #+#             */
/*   Updated: 2022/10/28 14:37:10 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}

/*int main()
{
	printf("%s", (calloc(3 , 5)));
	printf("%s", (ft_calloc(3 , 5)));
}*/
