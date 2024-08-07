/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:19:11 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/07 09:19:46 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_has_only_this_chars_on_string(char *str, char *map_components)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(ft_strchr(map_components, str[i])))
			return (0);
	}
	return (1);
}
