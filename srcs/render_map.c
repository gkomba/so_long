/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:47:13 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/15 08:40:05 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_image_on_map(t_win *mlx, t_map *map);

static void	render_image_on_map(t_win *mlx, t_map *map)
{
	if (mlx->map[map->i_lines][map->i_coluns] == '1')
		mlx_put_image_to_window(mlx->init, mlx->new_win, mlx->image->img_wall,
			mlx->x_pos, mlx->y_pos);
	else if (mlx->map[map->i_lines][map->i_coluns] == '0')
		mlx_put_image_to_window(mlx->init, mlx->new_win,
			mlx->image->img_background, mlx->x_pos, mlx->y_pos);
	else if (mlx->map[map->i_lines][map->i_coluns] == 'P')
		mlx_put_image_to_window(mlx->init, mlx->new_win,
			mlx->image->img_player_pos, mlx->x_pos, mlx->y_pos);
	else if (mlx->map[map->i_lines][map->i_coluns] == 'C')
		mlx_put_image_to_window(mlx->init, mlx->new_win,
			mlx->image->img_collectible, mlx->x_pos, mlx->y_pos);
	else if (mlx->map[map->i_lines][map->i_coluns] == 'E')
		mlx_put_image_to_window(mlx->init, mlx->new_win, mlx->image->img_exit,
			mlx->x_pos, mlx->y_pos);
}

void	render_map(t_win *mlx, t_map *map)
{
	mlx->y_pos = 0;
	map->i_lines = 0;
	while (mlx->map[map->i_lines] != NULL)
	{
		map->i_coluns = 0;
		mlx->x_pos = 0;
		while (mlx->map[map->i_lines][map->i_coluns] != '\0')
		{
			render_image_on_map(mlx, map);
			map->i_coluns++;
			mlx->x_pos += 45;
		}
		map->i_lines++;
		mlx->y_pos += 45;
	}
}
