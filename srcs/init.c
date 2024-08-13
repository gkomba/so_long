/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:49:35 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/13 18:29:27 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_images(t_win *mlx);

char	**ft_get_map(char *map_addres)
{
	int		fd;
	int		i;
	char	*get_map_string;

	fd = open(map_addres, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		perror("Error opening the file");
		exit(EXIT_FAILURE);
	}
	get_map_string = (char *)malloc(sizeof(char) * 1000000);
	if (!get_map_string)
	{
		ft_putendl_fd("Error", 2);
		perror("Error allocating memory");
		close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (read(fd, &get_map_string[i], 1) > 0)
		i++;
	get_map_string[i] = '\0';
	close(fd);
	return (ft_build_map(get_map_string));
}

char	**ft_build_map(char *get_map_string)
{
	char	**get_map_matriz;

	ft_is_followed_by_nl(get_map_string);
	if (ft_strlen(get_map_string) >= 3)
	{
		get_map_matriz = ft_split(get_map_string, '\n');
		if (!get_map_matriz)
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Error splitting the map", 2);
			free(get_map_string);
			free(get_map_string);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(get_map_string);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Error building the map", 2);
		exit(EXIT_FAILURE);
	}
	free(get_map_string);
	return (get_map_matriz);
}

void	ft_init_map(char *map_address)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(map));
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

int	ft_handle_key(int keycode, t_win *mlx)
{
	t_map	vars;

	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->init, mlx->new_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 65362)
		ft_move_to_up(mlx);
	else if (keycode == 65361)
		ft_move_to_left(mlx);
	else if (keycode == 65364)
		ft_move_to_down(mlx);
	else if (keycode == 65363)
		ft_move_to_rigth(mlx);
	return (0);
}

void	ft_init_game(char *map_address)
{
	t_map	map;
	t_win	mlx;
	t_image	img;

	ft_memset(&map, 0, sizeof(map));
	mlx.map = ft_get_map(map_address);
	map.wdth = (ft_strlen(mlx.map[0]) * OBJECT_SIZE);
	map.hgth = (ft_matriz_len(mlx.map) * OBJECT_SIZE);
	mlx.init = mlx_init();
	if (!mlx.init)
	{
		ft_free_matriz(mlx.map);
		ft_putendl_fd("Error", 2);
		perror("Error creating conection mlx");
		exit(EXIT_FAILURE);
	}
	mlx.new_win = mlx_new_window(mlx.init, map.wdth, map.hgth, "so_long");
	if (!mlx.new_win)
	{
		ft_free_matriz(mlx.map);
		free(mlx.init);
		ft_putendl_fd("Error", 2);
		perror("Error opening the window mlx");
		mlx_destroy_display(mlx.init);
		exit(EXIT_FAILURE);
	}
	ft_init_images(&mlx);
	render_map(&mlx, &map);
	mlx_hook(mlx.new_win, 2, 1L << 0, ft_handle_key, &mlx);
	mlx_loop(mlx.init);
	mlx_destroy_window(mlx.init, mlx.new_win);
	mlx_destroy_display(mlx.init);
	free(mlx.init);
}

void	ft_init_images(t_win *mlx)
{
	mlx->image->img_background = NULL;/*137004 = 123513*/
	mlx->image->img_background = mlx_xpm_file_to_image(mlx->init,
			"./assets/Background.xpm", &mlx->image->wdth, &mlx->image->hgth);
	mlx->image->img_collectible = NULL; /*123513 = 118610*/
	mlx->image->img_collectible = mlx_xpm_file_to_image(mlx->init,
			"./assets/Collectible.xpm", &mlx->image->wdth, &mlx->image->hgth);
	mlx->image->img_exit_close = NULL;  /*118610 = 111193*/
	mlx->image->img_exit_close = mlx_xpm_file_to_image(mlx->init,
			"./assets/Exit_close.xpm", &mlx->image->wdth, &mlx->image->hgth);
	mlx->image->img_player_front = NULL; /*111193 = 90324*/
	mlx->image->img_player_front = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_front.xpm", &mlx->image->wdth,
			&mlx->image->hgth);
	//mlx->image->img_player_back = NULL;
	mlx->image->img_player_back = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_back.xpm", &mlx->image->wdth,
			&mlx->image->hgth);
	//mlx->image->img_player_left = NULL;
	mlx->image->img_player_left = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_left.xpm", &mlx->image->wdth,
			&mlx->image->hgth);
	//mlx->image->img_player_rigth = NULL;
	mlx->image->img_player_rigth = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_rigth.xpm", &mlx->image->wdth,
			&mlx->image->hgth);
	//mlx->image->img_wall = NULL;
	mlx->image->img_wall = mlx_xpm_file_to_image(mlx->init, "./assets/Wall.xpm",
			&mlx->image->wdth, &mlx->image->hgth);
	mlx->image->img_exit_open = NULL;
	mlx->image->img_exit_open = mlx_xpm_file_to_image(mlx->init,
			"./assets/Exit_open.xpm", &mlx->image->wdth, &mlx->image->hgth);
	if (!mlx->image->img_wall || !mlx->image->img_background
		|| !mlx->image->img_player_front || !mlx->image->img_player_back
		|| !mlx->image->img_player_left || !mlx->image->img_exit_close
		|| !mlx->image->img_collectible || !mlx->image->img_player_rigth)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Failed to load one or more img", 2);
		exit(EXIT_FAILURE);
	}
	mlx->image->img_player_pos = NULL;
	mlx->image->img_player_pos = mlx->image->img_player_front;
	mlx->image->img_exit = NULL;
	mlx->image->img_exit = mlx->image->img_exit_close;
	if (!mlx->image->img_player_pos || !mlx->image->img_exit_open
		|| !mlx->image->img_exit)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Failed to load one or more img", 2);
		exit(EXIT_FAILURE);
	}
}
