/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:47:13 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/08 16:46:16 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_get_object_path(char object)
{
	if (object == 'P')
		return ("../assets/Player.xmp");
	else if (object == '0')
		return ("../assets/Background.xpm");
	else if (object == '1')
		return ("../assets/Walls.xpm");
	else if (object == 'E')
		return ("../assets/Exit.xpm");
	else if (object == 'C')
		return ("../assets/Colletible.xpm");
}