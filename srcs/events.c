/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:41:00 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/12 18:03:42 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_to_up(t_win *mlx)
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
	if (mlx->map[mlx->x_pos - 1][mlx->y_pos] == '1')
    {
        ft_putendl_fd("Wall", 2);
        return ;    
    }
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos - 1][mlx->y_pos] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_back;
	printf("Up\n");
}

void ft_move_to_left(t_win *mlx)
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
	if (mlx->map[mlx->x_pos][mlx->y_pos - 1] == '1')
    {
        ft_putendl_fd("Wall", 2);
        return ;    
    }
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos][mlx->y_pos - 1] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_left;
	printf("Left\n");
}

void ft_move_to_down(t_win *mlx)
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
	if (mlx->map[mlx->x_pos + 1][mlx->y_pos] == '1')
    {
        ft_putendl_fd("Wall", 2);
        return ;    
    }
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos + 1][mlx->y_pos] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_front;
	printf("Down\n");
}

void ft_move_to_rigth(t_win *mlx)
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
    {
        ft_putendl_fd("Wall", 2);
        return ;    
    }
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos][mlx->y_pos + 1] = 'P';
	mlx->image->img_player_pos = mlx->image->img_player_rigth;
	printf("Rigth\n");
}