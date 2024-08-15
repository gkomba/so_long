/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:41:00 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/15 08:26:32 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_handle_key(int keycode, t_win *mlx)
{
	t_map	vars;

	if (keycode == 65307 || keycode == 113)
	{
		mlx_destroy_window(mlx->init, mlx->new_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 65362 || keycode == 119)
		ft_move_to_up(mlx);
	else if (keycode == 65361 || keycode == 97)
		ft_move_to_left(mlx);
	else if (keycode == 65364 || keycode == 115)
		ft_move_to_down(mlx);
	else if (keycode == 65363 || keycode == 100)
		ft_move_to_rigth(mlx);
	ft_open_exit(mlx);
	render_map(mlx, &vars);
	return (0);
}

void	ft_move_to_up(t_win *mlx)
{
	t_map	vars;

	vars.i_lines = -1;
	mlx->x_pos = 0;
	mlx->y_pos = 0;
	while (mlx->map[++vars.i_lines])
	{
		vars.i_coluns = -1;
		while (mlx->map[vars.i_lines][++vars.i_coluns])
		{
			if (mlx->map[vars.i_lines][vars.i_coluns] == 'P')
			{
				mlx->x_pos = vars.i_lines;
				mlx->y_pos = vars.i_coluns;
			}
		}
	}
	return (ft_put_player_pos_up(mlx));
}

void	ft_move_to_left(t_win *mlx)
{
	t_map	vars;

	vars.i_lines = -1;
	mlx->x_pos = 0;
	mlx->y_pos = 0;
	while (mlx->map[++vars.i_lines])
	{
		vars.i_coluns = -1;
		while (mlx->map[vars.i_lines][++vars.i_coluns])
		{
			if (mlx->map[vars.i_lines][vars.i_coluns] == 'P')
			{
				mlx->x_pos = vars.i_lines;
				mlx->y_pos = vars.i_coluns;
			}
		}
	}
	return (ft_put_player_pos_left(mlx));
}

void	ft_move_to_down(t_win *mlx)
{
	t_map	vars;

	vars.i_lines = -1;
	mlx->x_pos = 0;
	mlx->y_pos = 0;
	while (mlx->map[++vars.i_lines])
	{
		vars.i_coluns = -1;
		while (mlx->map[vars.i_lines][++vars.i_coluns])
		{
			if (mlx->map[vars.i_lines][vars.i_coluns] == 'P')
			{
				mlx->x_pos = vars.i_lines;
				mlx->y_pos = vars.i_coluns;
			}
		}
	}
	return (ft_put_player_pos_down(mlx));
}

void	ft_move_to_rigth(t_win *mlx)
{
	t_map	vars;

	vars.i_lines = -1;
	mlx->x_pos = 0;
	mlx->y_pos = 0;
	while (mlx->map[++vars.i_lines])
	{
		vars.i_coluns = -1;
		while (mlx->map[vars.i_lines][++vars.i_coluns])
		{
			if (mlx->map[vars.i_lines][vars.i_coluns] == 'P')
			{
				mlx->x_pos = vars.i_lines;
				mlx->y_pos = vars.i_coluns;
			}
		}
	}
	return (ft_put_player_pos_rigth(mlx));
}
