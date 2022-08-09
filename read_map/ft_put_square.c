/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:03:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/09 21:13:14 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_square(t_prgrm *vars, t_image *image, int i)
{
	if (i == 0)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/floor.xpm", &image->size_x, &image->size_y);
	else if (i == 1)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Wall.xpm", &image->size_x, &image->size_y);
	else if (i == 2)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/coin_1.xpm", &image->size_x, &image->size_y);
	else if (i == 3)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Exit.xpm", &image->size_x, &image->size_y);
	else if (i == 4)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_right.xpm", &image->size_x, &image->size_y);
	else if (i == 5)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_right_shine.xpm", &image->size_x, &image->size_y);
	else if (i == 6)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_left.xpm", &image->size_x, &image->size_y);
	else if (i == 7)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear_left_shine.xpm", &image->size_x, &image->size_y);
	else if (i == 8)
		image->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Flame.xpm", &image->size_x, &image->size_y);
	if (image->xpm != NULL)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, image->xpm, vars->pos_square_x, vars->pos_square_y);
		mlx_destroy_image(vars->mlx, image->xpm);
	}
}

void	ft_put_flames(t_prgrm *vars, t_image *image)
{
	vars->pos_square_x = ((vars->x / 2) * 32) + 32;
	vars->pos_square_y = 32;
	ft_put_square(vars, image, 8);
	vars->pos_square_x = ((vars->x / 2) * 32) + 32;
	vars->pos_square_y = (vars->y * 32);
	ft_put_square(vars, image, 8);
	vars->pos_square_x = 32;
	vars->pos_square_y = ((vars->y / 2) * 32) + 32;
	ft_put_square(vars, image, 8);
	vars->pos_square_x = vars->x * 32;
	vars->pos_square_y = ((vars->y / 2) * 32) + 32;
	ft_put_square(vars, image, 8);
	vars->pos_square_x = 0;
	vars->pos_square_y = 0;
}
