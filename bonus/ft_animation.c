/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:56 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/11 20:32:03 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_to_window(t_prgrm *vars)
{
	if (vars->xpm != NULL)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->xpm,
		vars->pos_square_x, vars->pos_square_y);
		mlx_destroy_image(vars->mlx, vars->xpm);
	}
}

// void	ft_put_square_loop(t_prgrm *vars, int i)
// {
// 	if (i == 0)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 1)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 2)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 3)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 4)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 5)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 6)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 7)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_r.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 8)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/01_l.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 9)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/02_l.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 10)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/03_l.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 11)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/04_l.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 12)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/05_l.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 13)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/06_l.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 14)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/07_l.xpm", &vars->size_x, &vars->size_y);
// 	else if (i == 15)
// 		vars->xpm = mlx_xpm_file_to_image(vars->mlx, "./Tiles/walk/08_l.xpm", &vars->size_x, &vars->size_y);
// 	if (vars->xpm != NULL)
// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->xpm, vars->pos_square_x, vars->pos_square_y);
// 		mlx_destroy_image(vars->mlx, vars->xpm);
// 	}
// }

int	ft_loop(t_prgrm *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (ft_strchr(vars->map[y], 'P') == 0)
		y++;
	while (vars->map[y][x] != 'P')
		x++;
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	usleep(100000);
	vars->counter++;
	if (vars->animate == 1 && vars->dir == 1)
	{
		if (vars->counter == 8)
			vars->counter = 0;
		ft_put_square_loop(vars, vars->counter);
	}
	else if (vars->animate == 1 && vars->dir == 2)
	{
		if (vars->counter == 8)
			vars->counter = 0;
		ft_put_square_loop(vars, vars->counter + 8);
	}
	return (0);
}
