/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:13:22 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/08 11:34:28 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: No Map Address", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		ft_init_map(argv[1]);
		ft_init_game(argv[1]);
	}
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Error: Too Many Arguments", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
