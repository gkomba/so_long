/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:22:57 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/15 15:31:51 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_win *mlx)
{
	free_all_imgs(mlx);
	if (mlx->img_exit_open)
		mlx_destroy_image(mlx->init, mlx->img_exit_open);
	ft_free_matriz(mlx->map);
	mlx_destroy_window(mlx->init, mlx->new_win);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit(EXIT_SUCCESS);
}

void	ft_put_player_pos_up(t_win *mlx)
{
	if (mlx->map[mlx->x_pos - 1][mlx->y_pos] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos - 1][mlx->y_pos] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos - 1][mlx->y_pos] = 'P';
	mlx->img_player_pos = mlx->img_player_back;
	mlx->steps += 1;
	ft_putnbr_fd(mlx->steps, 1);
	ft_putchar_fd(10, 1);
	ft_putendl_fd("Up", 1);
}

void	ft_put_player_pos_left(t_win *mlx)
{
	if (mlx->map[mlx->x_pos][mlx->y_pos - 1] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos][mlx->y_pos - 1] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos][mlx->y_pos - 1] = 'P';
	mlx->img_player_pos = mlx->img_player_left;
	mlx->steps += 1;
	ft_putnbr_fd(mlx->steps, 1);
	ft_putchar_fd(10, 1);
	ft_putendl_fd("Left", 1);
}

void	ft_put_player_pos_down(t_win *mlx)
{
	if (mlx->map[mlx->x_pos + 1][mlx->y_pos] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos + 1][mlx->y_pos] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos + 1][mlx->y_pos] = 'P';
	mlx->img_player_pos = mlx->img_player_front;
	mlx->steps += 1;
	ft_putnbr_fd(mlx->steps, 1);
	ft_putchar_fd(10, 1);
	ft_putendl_fd("Down", 1);
}

void	ft_put_player_pos_rigth(t_win *mlx)
{
	if (mlx->map[mlx->x_pos][mlx->y_pos + 1] == '1')
		return (ft_putendl_fd("Wall", 1));
	else if (mlx->map[mlx->x_pos][mlx->y_pos + 1] == 'E')
	{
		ft_get_exit(mlx);
		return (ft_putendl_fd("The Exit is Closed", 1));
	}
	mlx->map[mlx->x_pos][mlx->y_pos] = '0';
	mlx->map[mlx->x_pos][mlx->y_pos + 1] = 'P';
	mlx->img_player_pos = mlx->img_player_rigth;
	mlx->steps += 1;
	ft_putnbr_fd(mlx->steps, 1);
	ft_putchar_fd(10, 1);
	ft_putendl_fd("Rigth", 1);
}
