/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:44:05 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/09 21:37:31 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_helper_0(t_prgrm *vars, t_image *image)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) - 1)] == 'C')
	{
		vars->coins--;
		return (1);
		ft_printf("image: %d\n", image->bpp);
	}
	else
		return (0);
}

int	ft_helper_1(t_prgrm *vars, t_image *image)
{
	if (vars->map[((vars->pos_square_y - 32) / 32)]
		[(((vars->pos_square_x - 32) / 32) + 1)] == 'C')
	{
		vars->coins--;
		return (1);
		ft_printf("image: %d\n", image->bpp);
	}
	else
		return (0);
}

int	ft_helper_2(t_prgrm *vars, t_image *image)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) - 1)]
		[((vars->pos_square_x - 32) / 32)] == 'C')
	{
		vars->coins--;
		return (1);
		ft_printf("image: %d\n", image->bpp);
	}
	return (0);
}

int	ft_helper_3(t_prgrm *vars, t_image *image)
{
	if (vars->map[(((vars->pos_square_y - 32) / 32) + 1)]
		[((vars->pos_square_x - 32) / 32)] == 'C')
	{
		vars->coins--;
		return (1);
		ft_printf("image: %d\n", image->bpp);
	}
	return (0);
}
