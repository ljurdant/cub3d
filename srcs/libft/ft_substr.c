/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:06:43 by ljurdant          #+#    #+#             */
/*   Updated: 2020/01/21 15:26:02 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) < start || len <= 0)
		return (ft_calloc(1, 1));
	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (0);
	while (len-- > 0)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
