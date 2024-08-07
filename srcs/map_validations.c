/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:38:14 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/07 09:40:53 by gkomba           ###   ########.fr       */
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

void	ft_handle_map_wals(char **map)
{
	int i;
	int end;
	int start;
    
    i = -1;
    while (map[++i])
    {
        start = 0;
        end = ft_strlen(map[i]);
        if ((map[i][start] != '1') || map[i][end - 1] != '1')
        {
            ft_free_matriz(map);
            ft_putendl_fd("Error", 2);
            ft_putendl_fd("Error: Invalid Map Wals", 2);
            exit(EXIT_FAILURE);
        }
    }
}