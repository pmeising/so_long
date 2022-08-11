/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:24:35 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/11 16:37:46 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft_lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "errno.h"

typedef struct s_prgrm
{
	void	*mlx;
	void	*mlx_win;
	char	*map_source;
	char	**map;
	int		pos_square_x;
	int		pos_square_y;
	int		x;
	int		y;
	int		coins;
	int		moves;
	int		animate;
	int		counter;
}					t_prgrm;

typedef struct	s_image
{
	char		*addrs;
	int			bpp;
	int			line_size;
	int			endian;
	char		*file_addr;
	int			size_x;
	int			size_y;
	void		*xpm;
	void		*one;
	void		*two;
	void		*three;
	void		*four;
	void		*five;
	void		*six;
	void		*seven;
	void		*eight;
}				t_image;

// READING MAP functions:

void	ft_read_from_map(t_prgrm *vars, char *map);
void	ft_check_map_border(t_prgrm *vars);
void	ft_put_square(t_prgrm *vars, t_image *image, int i);

// HOOK functions:

void	ft_hooks(t_prgrm *vars);
int		ft_key_hook(int keycode, t_prgrm *vars, t_image *image);
int		ft_close_program(t_prgrm *vars, int ecode);

// Walking the character

void	ft_walk(t_prgrm *vars, t_image *image, int direction);
void	ft_free_struct(t_image *image);

// Get next line functions

char	*get_next_line(int fd);

// ERROR management

void	ft_error(t_prgrm *vars, int ecode);

// Utils

void	ft_put_values(t_prgrm *vars);
void	ft_free_images(t_prgrm *vars, t_image *image);
void	ft_print_addr(t_image *image);
int		ft_helper_0(t_prgrm *vars, t_image *image);
int		ft_helper_1(t_prgrm *vars, t_image *image);
int		ft_helper_2(t_prgrm *vars, t_image *image);
int		ft_helper_3(t_prgrm *vars, t_image *image);
int		ft_helper_4(t_prgrm *vars);
int		ft_helper_5(t_prgrm *vars);
int		ft_helper_6(t_prgrm *vars);
int		ft_helper_7(t_prgrm *vars);
void	ft_put_flames(t_prgrm *vars, t_image *image);

// BONUS functions

int		ft_loop(t_prgrm *vars, t_image *image);

#endif