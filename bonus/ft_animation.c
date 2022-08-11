/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:56 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/11 16:45:06 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_to_window(t_prgrm *vars, t_image *image)
{
	if (image->xpm != NULL)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, image->xpm,
		vars->pos_square_x, vars->pos_square_y);
		mlx_destroy_image(vars->mlx, image->xpm);
	}
}

int	ft_loop(t_prgrm *vars, t_image *image)
{
	int		x;
	int		y;
	int		frame;
	int		speed;
	char	*path;

	speed = 30000;
	path = NULL;
	x = 0;
	y = 0;
	while (ft_strchr(vars->map[y], 'P') == 0)
		y++;
	while (vars->map[y][x] != 'P')
		x++;
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	if (vars->animate == 1)
	{
		vars->counter++;
		frame = vars->counter / speed;
		if (frame % 1)
		{
			path = "./Tiles/walk/01_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
		if (frame % 2)
		{
			path = "./Tiles/walk/02_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
		if (frame % 3)
		{
			path = "./Tiles/walk/03_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
		if (frame % 4)
		{
			path = "./Tiles/walk/04_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
		if (frame % 5)
		{
			path = "./Tiles/walk/05_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
		if (frame % 6)
		{
			path = "./Tiles/walk/06_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
		if (frame % 7)
		{
			path = "./Tiles/walk/07_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
		if (frame % 8)
		{
			path = "./Tiles/walk/08_r.xpm";
			image->xpm = mlx_xpm_file_to_image(vars->mlx, path, &image->size_x, &image->size_y);
			ft_put_to_window(vars, image);
		}
	}
	return (0);
}
