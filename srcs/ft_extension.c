/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:40:13 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/26 16:53:24 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if ((i - 1 > 0 && str[i - 1] == 'b')
	&& (i - 2 > 0 && str[i - 2] == 'u')
	&& (i - 3 > 0 && str[i - 3] == 'c')
	&& (i - 4 > 0 && str[i - 4] == '.'))
		return ;
	ft_arg_errors(3);
}
