/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:38:14 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/06 19:18:53 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_handle_extension(char *map)
{
    if (!(ft_strnstr(map, ".ber", ft_strlen(map))))
    {
        ft_putendl_fd("Error", 2);
        perror("Invalid Extension");
        exit (EXIT_FAILURE);
    }
    return ;
}