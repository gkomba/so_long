/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:38:14 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/07 19:11:40 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_handle_map_extension(char *map)
{
	if (!(ft_strnstr(map, ".ber", ft_strlen(map))))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Extension", 2);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_hande_map_form(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[++i])
	{
		if (len != ft_strlen(map[i]))
		{
			ft_free_matriz(map);
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Error: Invalid Map Form", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_handle_map_components(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (!(ft_has_only_this_chars_on_string(map[i], "10CEP")))
		{
			ft_free_matriz(map);
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Error: Invalid Map components", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_handle_map_walls(char **map)
{
	int	i;

	ft_map_is_surrounded_by_walls(map);
	i = -1;
	while (map[++i])
	{
		if ((map[i][0] != '1') || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			ft_free_matriz(map);
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Error: Invalid Map Walls", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_handle_map_path(char **map, char fill, char avoid)
{
	int i_lines;
	int i_coluns;
	char **map_to_fill;
	t_vars vars;

	i_lines = -1;
	vars.finded = 0;
	vars.avoid = avoid;
	vars.to_fill = fill;
	map_to_fill = ft_clone_map(map);
    int i = -1;
	while (map_to_fill[++i])
		printf("%s\n", map_to_fill[i]);
	while (map_to_fill[++i_lines])
	{
		i_coluns = -1;
		while (map_to_fill[i_lines][++i_coluns])
		{
			if (map_to_fill[i_lines][i_coluns] == vars.to_fill)
			{
				flood_fill(map_to_fill, i_lines, i_coluns, vars);
				if (vars.finded == 0)
				{
					ft_free_matriz(map);
					ft_free_matriz(map_to_fill);
					ft_putendl_fd("Error", 2);
					if (fill == 'E')
						ft_putendl_fd("Error: No Path In The Map To Exit.", 2);
					else if (fill == 'C')
						ft_putendl_fd("Error: No Path In The Map To Colletible.",
							2);
					//exit(EXIT_FAILURE);
				}
			}
		}
	}
	ft_free_matriz(map_to_fill);
}