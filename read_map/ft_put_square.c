/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:03:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/04 21:01:42 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_square(t_prgrm *vars, t_image *image, int i)
{
	if (i == 0)
		image->file_addr = "./Tiles/Floor_tile_1.xpm";
	else if (i == 1)
		image->file_addr = "./Tiles/Wall.xpm";
	else if (i == 2)
		image->file_addr = "./Tiles/Treasure_chest.xpm";
	else if (i == 3)
		image->file_addr = "./Tiles/Door.xpm";
	else if (i == 4)
		image->file_addr = "./Tiles/Player.xpm";
	image->xpm = mlx_xpm_file_to_image(vars->mlx, image->file_addr, &image->size_x, &image->size_y);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, image->xpm, vars->pos_square_x, vars->pos_square_y);
}
