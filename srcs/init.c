/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:49:35 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/10 17:27:58 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_images(t_win *mlx, t_image *img);

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

void	ft_init_game(char *map_address)
{
	t_map	map;
	t_win	mlx;
	t_image	img;

	map.map = ft_get_map(map_address);
	map.wdth = (ft_strlen(map.map[0]) * OBJECT_SIZE);
	map.hgth = (ft_matriz_len(map.map) * OBJECT_SIZE);
	mlx.init = mlx_init();
	if (!mlx.init)
	{
		ft_free_matriz(map.map);
		ft_putendl_fd("Error", 2);
		perror("Error creating conection mlx");
		exit(EXIT_FAILURE);
	}
	mlx.new_win = mlx_new_window(mlx.init, map.wdth, map.hgth, "so_long");
	if (!mlx.new_win)
	{
		ft_free_matriz(map.map);
		free(mlx.init);
		ft_putendl_fd("Error", 2);
		perror("Error opening the window mlx");
		mlx_destroy_display(mlx.init);
		exit(EXIT_FAILURE);
	}
	ft_free_matriz(map.map);
	ft_init_images(&mlx, &img);
	render_map(map_address, &mlx, &map, &img);
	mlx_loop(mlx.init);
	mlx_destroy_window(mlx.init, mlx.new_win);
	mlx_destroy_display(mlx.init);
	free(mlx.init);
}

void	ft_init_images(t_win *mlx, t_image *img)
{
	img->img_background = mlx_xpm_file_to_image(mlx->init,
			"./assets/Background.xpm", &img->wdth, &img->hgth);
	img->img_collectible = mlx_xpm_file_to_image(mlx->init,
			"./assets/Collectible.xpm", &img->wdth, &img->hgth);
	img->img_exit = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_left.xpm", &img->wdth, &img->hgth);
	img->img_player = mlx_xpm_file_to_image(mlx->init,
			"./assets/Player/Player_front.xpm", &img->wdth, &img->hgth);
	img->img_wall = mlx_xpm_file_to_image(mlx->init, "./assets/Wall.xpm",
			&img->wdth, &img->hgth);
	if (!img->img_wall || !img->img_background || !img->img_player
		|| !img->img_collectible || !img->img_exit)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Failed to load one or more img", 2);
		exit(EXIT_FAILURE);
	}
}