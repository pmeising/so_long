/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:51:36 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 19:52:09 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	ft_dest_images(t_prgrm *vars, t_image *image)
// {
// 	mlx_destroy_image(vars->mlx, image->exit);
// 	mlx_destroy_image(vars->mlx, image->floor);
// 	mlx_destroy_image(vars->mlx, image->player);
// }

// void	ft_free_struct( t_image *image)
// {
// 	free (image->c1);
// 	free (image->exit);
// 	free (image->floor);
// 	free (image->player);
// 	free (image->wall);
// }

int	ft_close_program(t_prgrm *vars, t_image *image)
{
	// mlx_destroy_image(vars->mlx, image->player);
	// mlx_destroy_image(vars->mlx, image->c1);
	// // mlx_destroy_image(vars->mlx, image->exit);
	// // mlx_destroy_image(vars->mlx, image->floor);
	// // mlx_destroy_image(vars->mlx, image->barrel);
	// // mlx_destroy_image(vars->mlx, image->c2);
	// // mlx_destroy_image(vars->mlx, image->wall_flame);
	// ft_printf("image: %p\n", image->floor);
	mlx_destroy_display(vars->mlx);
	// mlx_destroy_window(vars->mlx, vars->mlx_win);
	// ft_free_struct(image);
	// free (vars->mlx);
	// free (vars->mlx_win);
	ft_printf("%d, %d\n", vars->x, image->coins);
	exit (0);
}
