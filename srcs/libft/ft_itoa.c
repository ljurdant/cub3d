/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:41:30 by ljurdant          #+#    #+#             */
/*   Updated: 2019/11/29 14:58:43 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(long nb)
{
	int power;

	power = 0;
	if (nb < 0)
	{
		power++;
		nb = -nb;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		power++;
	}
	return (power + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*nb;
	long	nl;

	nl = (long)n;
	if (!(nb = malloc(sizeof(char) * (ft_len(nl) + 1))))
		return (0);
	i = ft_len(nl) - 1;
	nb[i + 1] = '\0';
	if (nl < 0)
	{
		nb[0] = '-';
		nl = (-1) * nl;
	}
	while (nl / 10 > 0)
	{
		nb[i] = nl % 10 + 48;
		nl = nl / 10;
		i--;
	}
	nb[i] = nl + 48;
	return (nb);
}
