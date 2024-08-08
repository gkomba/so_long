/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:49:35 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/08 11:50:13 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	ft_init_map(char *map_name)
{
	char **map;

	ft_handle_map_extension(map_name);
	map = ft_get_map(map_name);
	ft_handle_map_components(map);
	ft_hande_map_form(map);
	ft_handle_map_walls(map);
	ft_handle_map_components_player(map);
	ft_handle_map_components_collectible(map);
	ft_handle_map_components_exit(map);
	ft_handle_map_path(map, 'C', 'E');
	ft_handle_map_path(map, 'E', 'G');
	ft_free_matriz(map);
}

void	ft_init_game(char *map_name)
{
	t_map map;
	t_win mlx;

	map.map = ft_get_map(map_name);
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
		perror("Error opening the windw mlx");
		mlx_destroy_display(mlx.init);
		exit(EXIT_FAILURE);
	}
	ft_free_matriz(map.map);
	mlx_loop(mlx.init);
	mlx_destroy_window(mlx.init, mlx.new_win);
	mlx_destroy_display(mlx.init);
	free(mlx.init);
}