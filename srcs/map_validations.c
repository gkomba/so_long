/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:38:14 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/06 19:42:01 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_handle_map_extension(char *map)
{
    if (!(ft_strnstr(map, ".ber", ft_strlen(map))))
    {
        ft_putendl_fd("Error", 2);
        ft_putendl_fd("Error: Invalid Extension", 2);
        exit (EXIT_FAILURE);
    }
    return ;
}

void    ft_hande_map_