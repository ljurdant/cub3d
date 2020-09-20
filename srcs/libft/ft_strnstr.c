/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:07:35 by ljurdant          #+#    #+#             */
/*   Updated: 2019/12/05 16:56:30 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (len && *(haystack + i + j) != '\0')
	{
		while (len > 0 && *(haystack + i + j) != '\0' &&
			*(haystack + i + j) == *(needle + j))
		{
			j++;
			if (*(needle + j) == '\0')
				return ((char *)(haystack + i));
			len--;
		}
		len += j;
		j = 0;
		i++;
		len--;
	}
	return (NULL);
}
