/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:33:24 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/08 13:10:25 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_handle_map_components_player(char **map)
{
	if (ft_count_chr_occurrency_on_map(map, 'P') < 1)
	{
		ft_free_matriz(map);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Map components. Has No Player on Map", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_count_chr_occurrency_on_map(map, 'P') > 1)
	{
		ft_free_matriz(map);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Map components.Has Many Player's On Map",
			2);
		exit(EXIT_FAILURE);
	}
}

void	ft_handle_map_components_exit(char **map)
{
	if (ft_count_chr_occurrency_on_map(map, 'E') < 1)
	{
		ft_free_matriz(map);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Map components. Has No Exit on Map", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_count_chr_occurrency_on_map(map, 'E') > 1)
	{
		ft_free_matriz(map);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Map components. Has Many Exit's On Map",
			2);
		exit(EXIT_FAILURE);
	}
}

void	ft_handle_map_components_collectible(char **map)
{
	if (ft_count_chr_occurrency_on_map(map, 'C') < 1)
	{
		ft_free_matriz(map);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Map components.Has No Collectible on Map",
			2);
		exit(EXIT_FAILURE);
	}
}

void	ft_is_followed_by_nl(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\0' || str[i + 1] == '\n')
			{
				free(str);
				ft_putendl_fd("Error", 2);
				ft_putendl_fd("Error: Error building the map", 2);
				exit(EXIT_FAILURE);
			}
		}
	}
}

	void	ft_error_sms_invalid_path(char **map, char **map_cloned, char chr)
{
	ft_free_matriz(map);
	ft_putendl_fd("Error", 2);
	if (chr == 'E')
		ft_putendl_fd("Error: No Path In The Map To Exit.", 2);
	else if (chr == 'C')
		ft_putendl_fd("Error: No Path In The Map To Colletible.", 2);
	exit(EXIT_FAILURE);
}