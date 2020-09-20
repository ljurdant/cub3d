/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:47:59 by ljurdant          #+#    #+#             */
/*   Updated: 2019/12/05 16:14:18 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dst == src)
		return (0);
	d = dst;
	s = src;
	if (d == 0 && s == 0)
		return (dst);
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
