/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:47:13 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/10 14:08:43 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map(char *map_address, t_win *mlx, t_map *map, t_image *img)
{
	map->map = ft_get_map(map_address);
	mlx->y_pos = 0;
	map->i_lines = 0;
	while (map->map[map->i_lines] != NULL)
	{
		map->i_coluns = 0;
		mlx->x_pos = 0;
		while (map->map[map->i_lines][map->i_coluns] != '\0')
		{
			if (map->map[map->i_lines][map->i_coluns] == '1')
				mlx_put_image_to_window(mlx->init, mlx->new_win, img->img_wall,
					mlx->x_pos, mlx->y_pos);
			else if (map->map[map->i_lines][map->i_coluns] == '0')
				mlx_put_image_to_window(mlx->init, mlx->new_win,
					img->img_background, mlx->x_pos, mlx->y_pos);
			else if (map->map[map->i_lines][map->i_coluns] == 'P')
				mlx_put_image_to_window(mlx->init, mlx->new_win,
					img->img_player, mlx->x_pos, mlx->y_pos);
			else if (map->map[map->i_lines][map->i_coluns] == 'C')
				mlx_put_image_to_window(mlx->init, mlx->new_win,
					img->img_collectible, mlx->x_pos, mlx->y_pos);
			else if (map->map[map->i_lines][map->i_coluns] == 'E')
				mlx_put_image_to_window(mlx->init, mlx->new_win, img->img_exit,
					mlx->x_pos, mlx->y_pos);
			map->i_coluns++;
			mlx->x_pos += 45;
		}
		map->i_lines++;
		mlx->y_pos += 45;
	}
}