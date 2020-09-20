/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:10:08 by ljurdant          #+#    #+#             */
/*   Updated: 2019/12/05 16:10:45 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*s1;
	size_t		i;

	i = 0;
	s1 = (void*)s;
	while (i < n)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	return (0);
}
