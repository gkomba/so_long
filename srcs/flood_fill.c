/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:12:11 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/07 19:10:49 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void flood_fill(char **map, int x, int y, t_vars vars)
{
    if (x >= ft_strlen(map[0]) || x < 0 || y >= ft_matriz_len(map) || y < 0)
        return;
    if (map[x][y] == 'P')
    {
        vars.finded = 1;
        return ;
    }
    if (map[x][y] == '1' || map[x][y] == vars.avoid || map[x][y] == 'V')
        return ;
    map[x][y] = 'V';
    flood_fill(map, x + 1, y, vars);
    flood_fill(map, x - 1, y, vars);
    flood_fill(map, x, y + 1, vars);
    flood_fill(map, x, y - 1, vars);
}