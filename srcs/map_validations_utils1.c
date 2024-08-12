/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:19:11 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/12 09:06:44 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_has_only_this_chars_on_string(char *str, char *map_components)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(ft_strchr(map_components, str[i])))
			return (0);
	}
	return (1);
}

int	ft_has_only_this_char_on_sring(char *str, char chr)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != chr)
			return (0);
	return (1);
}

void	ft_map_is_surrounded_by_walls(char **map)
{
	if (!(ft_has_only_this_char_on_sring(map[0], '1')))
	{
		ft_free_matriz(map);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Map Walls(above)", 2);
		exit(EXIT_FAILURE);
	}
	else if (!(ft_has_only_this_char_on_sring(map[ft_matriz_len(map) - 1],
				'1')))
	{
		ft_free_matriz(map);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Invalid Map Walls(below)", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_count_chr_occurrency_on_map(char **map, char chr)
{
	int	i_mtz;
	int	i_str;
	int	chr_occurrency;

	i_mtz = -1;
	chr_occurrency = 0;
	while (map[++i_mtz])
	{
		i_str = -1;
		while (map[i_mtz][++i_str])
		{
			if (map[i_mtz][i_str] == chr)
				chr_occurrency += 1;
		}
	}
	return (chr_occurrency);
}

char	**ft_clone_map(char **map)
{
	int		len;
	int		i;
	char	**matriz;

	len = ft_matriz_len(map);
	matriz = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (++i < len)
		matriz[i] = ft_strdup(map[i]);
	matriz[i] = 0;
	return (matriz);
}
