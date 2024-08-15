/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:54:21 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/15 07:51:19 by gkomba           ###   ########.fr       */
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
