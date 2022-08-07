/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:03:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 17:18:15 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_square(t_prgrm *vars, t_image *image, int i)
{
	if (i == 0)
		image->xpm = image->floor;
	else if (i == 1)
		image->xpm = image->wall;
	else if (i == 2)
		image->xpm = image->c1;
	else if (i == 3)
		image->xpm = image->exit;
	else if (i == 4)
		image->xpm = image->player;
	else if (i == 5)
		image->xpm = image->wall_flame;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, image->xpm, vars->pos_square_x, vars->pos_square_y);
}
