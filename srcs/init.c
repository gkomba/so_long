/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:49:35 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/15 15:31:37 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_map(char *map_address)
{
	t_map	map;

	ft_handle_map_extension(map_address);
	map.map = ft_get_map(map_address);
	ft_handle_map_components(map.map);
	ft_hande_map_form(map.map);
	ft_handle_map_walls(map.map);
	ft_handle_map_components_player(map.map);
	ft_handle_map_components_collectible(map.map);
	ft_handle_map_components_exit(map.map);
	ft_handle_map_path(map.map, 'C', 'E');
	ft_handle_map_path(map.map, 'E', 'G');
	ft_free_matriz(map.map);
}

void	ft_free_mlx(t_win *mlx)
{
	free_all_imgs(mlx);
	ft_free_matriz(mlx->map);
	mlx_destroy_window(mlx->init, mlx->new_win);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit(EXIT_FAILURE);
}

void	ft_mlx_init_game(t_win *mlx, t_map *map)
{
	mlx->init = mlx_init();
	if (!mlx->init)
	{
		ft_free_matriz(mlx->map);
		ft_putendl_fd("Error", 2);
		perror("Error creating conection mlx");
		exit(EXIT_FAILURE);
	}
	ft_init_images(mlx);
	mlx->new_win = mlx_new_window(mlx->init, map->wdth, map->hgth, "so_long");
	if (!mlx->new_win)
	{
		ft_putendl_fd("Error", 2);
		perror("Error opening the window mlx");
		ft_free_mlx(mlx);
	}
	render_map(mlx, map);
}

void	ft_init_game(char *map_address)
{
	t_map	map;
	t_win	mlx;

	mlx.map = ft_get_map(map_address);
	map.wdth = (ft_strlen(mlx.map[0]) * OBJECT_SIZE);
	map.hgth = (ft_matriz_len(mlx.map) * OBJECT_SIZE);
	mlx.steps = 0;
	ft_mlx_init_game(&mlx, &map);
	mlx_hook(mlx.new_win, 2, 1L << 0, ft_handle_key, &mlx);
	mlx_hook(mlx.new_win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.init);
	ft_free_mlx(&mlx);
}

void	ft_init_images(t_win *mlx)
{
	mlx->img_background = mlx_xpm_file_to_image(mlx->init,
			"./assets/Background.xpm", &mlx->wdth, &mlx->hgth);
	mlx->img_collectible = mlx_xpm_file_to_image(mlx->init,
			"./assets/Collectible.xpm", &mlx->wdth, &mlx->hgth);
	mlx->img_exit_close = mlx_xpm_file_to_image(mlx->init,
			"./assets/Exit_close.xpm", &mlx->wdth, &mlx->hgth);
	mlx->img_player_front = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_front.xpm", &mlx->wdth, &mlx->hgth);
	mlx->img_player_back = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_back.xpm", &mlx->wdth, &mlx->hgth);
	mlx->img_player_left = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_left.xpm", &mlx->wdth, &mlx->hgth);
	mlx->img_player_rigth = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_rigth.xpm", &mlx->wdth, &mlx->hgth);
	mlx->img_wall = mlx_xpm_file_to_image(mlx->init, "./assets/Wall.xpm",
			&mlx->wdth, &mlx->hgth);
	mlx->img_exit_open = mlx_xpm_file_to_image(mlx->init,
			"./assets/Exit_open.xpm", &mlx->wdth, &mlx->hgth);
	ft_check_load_image(mlx);
}
