/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:13:22 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/07 15:31:58 by gkomba           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		i;
	char	**map;

	if (argc < 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: No Map Address", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		ft_handle_map_extension(argv[1]);
		map = ft_get_map(argv[1]);
		ft_handle_map_components(map);
		ft_hande_map_form(map);
		ft_handle_map_walls(map);
		ft_handle_map_components_player(map);
		ft_handle_map_components_collectible(map);
		ft_handle_map_components_exit(map);
		i = -1;
		while (map[++i])
			printf("%s\n", map[i]);
		ft_free_matriz(map);
	}
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Too Many Arguments", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
