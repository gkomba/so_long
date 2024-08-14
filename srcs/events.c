/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:41:00 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/14 16:45:35 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_handle_key(int keycode, t_win *mlx)
{
	t_map	vars;

	if (keycode == 65307)
	{
		//free_all_imgs(mlx);
		mlx_destroy_window(mlx->init, mlx->new_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 65362 || keycode == 119)
		ft_move_to_up(mlx);
	else if (keycode == 65361 || keycode == 97)
		ft_move_to_left(mlx);
	else if (keycode == 65364 || keycode == 115)
		ft_move_to_down(mlx);
	else if (keycode == 65363 || keycode == 100)
		ft_move_to_rigth(mlx);
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
	if (mlx->map[mlx->x_pos - 1][mlx->y_pos] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos - 1][mlx->y_pos] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos - 1][mlx->y_pos] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_back;
	ft_putendl_fd("Up", 1);
	render_map(mlx, &vars);
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
	if (mlx->map[mlx->x_pos][mlx->y_pos - 1] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos][mlx->y_pos - 1] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos][mlx->y_pos - 1] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_left;
	ft_putendl_fd("Left", 1);
	render_map(mlx, &vars);
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
	if (mlx->map[mlx->x_pos + 1][mlx->y_pos] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos + 1][mlx->y_pos] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos + 1][mlx->y_pos] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_front;
	ft_putendl_fd("Down", 1);
	render_map(mlx, &vars);
}

void	ft_move_to_rigth(t_win *mlx)
{
	t_map vars;

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
	if (mlx->map[mlx->x_pos][mlx->y_pos + 1] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos][mlx->y_pos + 1] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos][mlx->y_pos + 1] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_rigth;
	ft_putendl_fd("Rigth", 1);
	render_map(mlx, &vars);
}