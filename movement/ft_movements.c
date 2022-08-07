/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.coins                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:33:17 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 18:17:05 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_walk_left(t_prgrm *vars, t_image *image)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)][(((vars->pos_square_x - 32)/32) - 1)] == '1')
		return ;
	else if (vars->map[((vars->pos_square_y - 32) / 32)][(((vars->pos_square_x - 32)/32) - 1)] == 'C')
		image->coins--;
	ft_printf("coins: %d\n", image->coins);
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[((vars->pos_square_y - 32) / 32)][(((vars->pos_square_x - 32) / 32) - 1)] = 'P';
	vars->pos_square_x = vars->pos_square_x - 32;
	ft_put_square(vars, image, 4);
	if (vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32)/32)] == 'E' && image->coins == 0)
		ft_close_program(vars, image);
}

void	ft_walk_right(t_prgrm *vars, t_image *image)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)][(((vars->pos_square_x - 32)/32) + 1)] == '1')
		return ;
	else if (vars->map[((vars->pos_square_y - 32) / 32)][(((vars->pos_square_x - 32)/32) + 1)] == 'C')
		image->coins--;
	ft_printf("coins: %d\n", image->coins);
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[((vars->pos_square_y - 32) / 32)][(((vars->pos_square_x - 32) / 32) + 1)] = 'P';
	vars->pos_square_x = vars->pos_square_x + 32;
	ft_put_square(vars, image, 4);
	if (vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32)/32)] == 'E' && image->coins == 0)
		ft_close_program(vars, image);
}

void	ft_walk_up(t_prgrm *vars, t_image *image)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)][((vars->pos_square_x - 32)/32)] == '1')
		return ;
	else if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)][((vars->pos_square_x - 32)/32)] == 'C')
		image->coins--;
	ft_printf("coins: %d\n", image->coins);
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[(((vars->pos_square_y - 32) / 32) - 1)][((vars->pos_square_x - 32) / 32)] = 'P';
	vars->pos_square_y = vars->pos_square_y - 32;
	ft_put_square(vars, image, 4);
	if (vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32)/32)] == 'E' && image->coins == 0)
		ft_close_program(vars, image);
}

void	ft_walk_down(t_prgrm *vars, t_image *image)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)][((vars->pos_square_x - 32)/32)] == '1')
		return ;
	else if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)][((vars->pos_square_x - 32)/32)] == 'C')
		image->coins--;
	ft_printf("coins: %d\n", image->coins);
	ft_put_square(vars, image, 0);
	vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32) / 32)] = '0';
	vars->map[(((vars->pos_square_y - 32) / 32) + 1)][((vars->pos_square_x - 32) / 32)] = 'P';
	vars->pos_square_y = vars->pos_square_y + 32;
	ft_put_square(vars, image, 4);
	if (vars->map[((vars->pos_square_y - 32) / 32)][((vars->pos_square_x - 32)/32)] == 'E' && image->coins == 0)
		ft_close_program(vars, image);
}

// Here I walk through the map to find the players x and y parameters.

void	ft_walk(t_prgrm *vars, t_image *image, int direction)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (ft_strchr(vars->map[y], 'P') == 0)
		y++;
	while (vars->map[y][x] != 'P')
		x++;
	// ft_free_struct(image);
	ft_put_values(vars, image);
	vars->pos_square_x = 32 + (x * 32);
	vars->pos_square_y = 32 + (y * 32);
	ft_printf("Positions: x %d, y %d\n", vars->pos_square_x, vars->pos_square_y);
	if (direction == 0)
		ft_walk_up(vars, image);
	else if (direction == 1)
		ft_walk_left(vars, image);
	else if (direction == 2)
		ft_walk_down(vars, image);
	else if (direction == 3)
		ft_walk_right(vars, image);
}
