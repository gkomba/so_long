/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:33:40 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/15 07:48:19 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_open_exit(t_win *mlx)
{
	if (ft_count_chr_occurrency_on_map(mlx->map, 'C') == 0)
		mlx->image->img_exit = mlx->image->img_exit_open;
	else
		return ;
}

void	ft_get_exit(t_win *mlx)
{
	if (ft_count_chr_occurrency_on_map(mlx->map, 'C') == 0)
	{
		ft_putendl_fd("YOU WIN", 1);
		ft_free_matriz(mlx->map);
		mlx_destroy_window(mlx->init, mlx->new_win);
		exit(EXIT_SUCCESS);
	}
	else
		return ;
}

void	free_all_imgs(t_win *mlx)
{
	if (mlx->image->img_wall)
		mlx_destroy_image(mlx->init, mlx->image->img_wall);
	if (mlx->image->img_background)
		mlx_destroy_image(mlx->init, mlx->image->img_background);
	if (mlx->image->img_player_front)
		mlx_destroy_image(mlx->init, mlx->image->img_player_front);
	if (mlx->image->img_player_back)
		mlx_destroy_image(mlx->init, mlx->image->img_player_back);
	if (mlx->image->img_player_left)
		mlx_destroy_image(mlx->init, mlx->image->img_player_left);
	if (mlx->image->img_exit_close)
		mlx_destroy_image(mlx->init, mlx->image->img_exit_close);
	if (mlx->image->img_collectible)
		mlx_destroy_image(mlx->init, mlx->image->img_collectible);
	if (mlx->image->img_player_rigth)
		mlx_destroy_image(mlx->init, mlx->image->img_player_rigth);
	if (mlx->image->img_player_pos)
		mlx_destroy_image(mlx->init, mlx->image->img_player_pos);
	if (mlx->image->img_exit)
		mlx_destroy_image(mlx->init, mlx->image->img_exit);
}

void	ft_check_load_image(t_win *mlx)
{
	if (!mlx->image->img_wall || !mlx->image->img_background
		|| !mlx->image->img_player_front || !mlx->image->img_player_back
		|| !mlx->image->img_player_left || !mlx->image->img_exit_close
		|| !mlx->image->img_collectible || !mlx->image->img_player_rigth)
	{
		ft_free_matriz(mlx->map);
		free(mlx->init);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Failed to load one or more img", 2);
		exit(EXIT_FAILURE);
	}
	mlx->image->img_player_pos = mlx->image->img_player_front;
	mlx->image->img_exit = mlx->image->img_exit_close;
	if (!mlx->image->img_player_pos || !mlx->image->img_exit_open
		|| !mlx->image->img_exit)
	{
		ft_free_matriz(mlx->map);
		free(mlx->init);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Failed to load one or more img", 2);
		exit(EXIT_FAILURE);
	}
}
