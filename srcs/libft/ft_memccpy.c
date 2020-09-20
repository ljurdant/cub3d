/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:15:01 by ljurdant          #+#    #+#             */
/*   Updated: 2019/12/05 16:12:08 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- > 0)
	{
		d[i] = s[i];
		dst++;
		i++;
		if (s[i - 1] == (unsigned char)c)
			return (dst);
	}
	return (0);
}
