/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:38:14 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/08 09:45:34 by gkomba           ###   ########.fr       */
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
	char **map_to_fill;
	t_map vars;

	vars.i_lines = -1;
	vars.avoid = avoid;
	while (map[++vars.i_lines])
	{
		vars.i_coluns = -1;
		while (map[vars.i_lines][++vars.i_coluns])
		{
			if (map[vars.i_lines][vars.i_coluns] == fill)
			{
				vars.finded = 0;
				map_to_fill = ft_clone_map(map);
				flood_fill(map_to_fill, vars.i_lines, vars.i_coluns, &vars);
				ft_free_matriz(map_to_fill);
				if (vars.finded == 0)
					ft_error_sms_invalid_path(map, map_to_fill, fill);
			}
		}
	}
}