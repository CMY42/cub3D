/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:21:33 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/07 14:48:15 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != '\0')
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	long int		nb;

	i = ft_nb(n);
	nb = n;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		*str = '-';
		nb *= -1;
	}
	if (nb == 0)
		*str = '0';
	str[i] = '\0';
	i--;
	while (nb != '\0')
	{
		str[i] = nb % 10 + 48;
		i--;
		nb = nb / 10;
	}
	return (str);
}
