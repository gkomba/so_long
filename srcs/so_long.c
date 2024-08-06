/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:13:22 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/06 17:23:09 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char    **ft_get_map(char **map_addres)
{
    int fd;
    char *get_map_string;
    char **get_map_matriz;
    int buffer_readed;

    fd = open(map_addres, O_RDONLY);
    get_map_string = (char *)malloc(sizeof(char) * 100);
    buffer_readed = read(fd, get_map_string, 100);
    get_map_matriz = ft_split(get_map_string, '\n');
    return (get_map_matriz);
}

int	main(int argc, char **argv)
{
    int i;
    char **map;
    map = ft_get_map(argv[1]);
    i = -1;
    while (map[++i])
        printf("%s\n", map[i]);
	exit(EXIT_SUCCESS);
}