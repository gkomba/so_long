/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:13:22 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/06 19:40:00 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_get_map(char *map_addres)
{
	int		fd;
	int		i;
	char	*get_map_string;
	char	**get_map_matriz;

	fd = open(map_addres, O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
        exit (EXIT_FAILURE);
	}
	get_map_string = (char *)malloc(sizeof(char) * 1000000);
	if (!get_map_string)
	{
		perror("Erro ao alocar memória");
		close(fd);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (read(fd, &get_map_string[i], 1) > 0)
		i++;
	get_map_string[i] = '\0';
	close(fd);
	get_map_matriz = ft_split(get_map_string, '\n');
	if (!get_map_matriz)
	{
		perror("Erro ao dividir o mapa");
		free(get_map_string);
        exit (EXIT_FAILURE);
	}
	free(get_map_string);
	return (get_map_matriz);
}

int	main(int argc, char **argv)
{
	int i;
	char **map;
    ft_handle_map_extension(argv[1]);
	map = ft_get_map(argv[1]);
	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
	ft_free_matriz(map);
	exit(EXIT_SUCCESS);
}