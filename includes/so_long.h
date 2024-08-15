/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:15:23 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/15 11:42:47 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define OBJECT_SIZE 45

typedef struct s_map
{
	char	**map;
	char	avoid;
	int		finded;
	int		i_lines;
	int		i_coluns;
	int		wdth;
	int		hgth;
}			t_map;

typedef struct s_win
{
	char	**map;
	void	*init;
	void	*new_win;
	void	*img;
	void	*img_wall;
	void	*img_exit;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_player_front;
	void	*img_player_back;
	void	*img_player_rigth;
	void	*img_player_left;
	void	*img_background;
	void	*img_collectible;
	void	*img_player_pos;
	int		y_pos;
	int		x_pos;
	int		wdth;
	int		hgth;
	int		steps;
}			t_win;

void		ft_init_game(char *map_address);
void		ft_init_map(char *map_addres);
char		**ft_get_map(char *map_addres);
char		**ft_build_map(char *get_map_string);
char		**ft_clone_map(char **map);
int			ft_handle_key(int keycode, t_win *mlx);
void		ft_init_images(t_win *mlx);
/*void		ft_init_image_background(t_win *mlx);
void		ft_init_image_wall(t_win *mlx);
void		ft_init_image_collectible(t_win *mlx);
void		ft_init_image_player(t_win *mlx);
void	ft_init_image_exit(t_win *mlx);*/
void		ft_check_load_image(t_win *mlx);
void		free_all_imgs(t_win *mlx);
void		ft_move_to_up(t_win *mlx);
void		ft_move_to_rigth(t_win *mlx);
void		ft_move_to_left(t_win *mlx);
void		ft_move_to_down(t_win *mlx);
void		ft_put_player_pos_up(t_win *mlx);
void		ft_put_player_pos_left(t_win *mlx);
void		ft_put_player_pos_down(t_win *mlx);
void		ft_put_player_pos_rigth(t_win *mlx);
void		ft_get_exit(t_win *mlx);
void		ft_open_exit(t_win *mlx);
void		render_map(t_win *mlx, t_map *map);
void		ft_is_followed_by_nl(char *str);
void		ft_handle_map_extension(char *map);
void		ft_hande_map_form(char **map);
void		ft_handle_map_components(char **map);
void		ft_handle_map_walls(char **map);
void		ft_handle_map_components_player(char **map);
void		ft_handle_map_components_exit(char **map);
void		ft_handle_map_components_collectible(char **map);
void		ft_map_is_surrounded_by_walls(char **map);
void		ft_handle_map_path(char **map, char fill, char avoid);
void		ft_error_sms_invalid_path(char **map, char **map_cloned, char chr);
void		flood_fill(char **map, int x, int y, t_map *vars);
int			ft_has_only_this_chars_on_string(char *str, char *map_components);
int			ft_has_only_this_char_on_sring(char *str, char chr);
int			ft_count_chr_occurrency_on_map(char **map, char chr);

#endif