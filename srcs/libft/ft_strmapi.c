/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:03:29 by ljurdant          #+#    #+#             */
/*   Updated: 2020/01/16 22:39:52 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*str;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	while (len > 0)
	{
		str[i] = f(i, s[i]);
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
