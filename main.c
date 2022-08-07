/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:36:42 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 19:40:37 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_image_2(t_prgrm *vars, t_image *image, char c)
{
	if (c == '0')
		ft_put_square(vars, image, 0);
	else if (c == '1')
		ft_put_square(vars, image, 1);
	else if (c == 'C')
		ft_put_square(vars, image, 2);
	else if (c == 'E')
		ft_put_square(vars, image, 3);
	else if (c == 'P')
		ft_put_square(vars, image, 4);
}

void	ft_create_image(t_prgrm *vars, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		vars->pos_square_y = vars->pos_square_y + 32;
		vars->pos_square_x = 0;
		while (vars->map[i][j] != '\0')
		{
			vars->pos_square_x = vars->pos_square_x + 32;
			ft_create_image_2(vars, image, vars->map[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_put_values(t_prgrm *vars, t_image *image)
{
	vars->x = 0;
	vars->y = 0;
	vars->pos_square_x = 0;
	vars->pos_square_y = 0;
	vars->map_source = NULL;
	image->wall = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Wall.xpm", &image->size_x, &image->size_y);
	image->wall_flame = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Wall_with_flame.xpm", &image->size_x, &image->size_y);
	image->player = mlx_xpm_file_to_image(vars->mlx, "./Tiles/bear.xpm", &image->size_x, &image->size_y);
	image->floor = mlx_xpm_file_to_image(vars->mlx, "./Tiles/floor.xpm", &image->size_x, &image->size_y);
	image->c1 = mlx_xpm_file_to_image(vars->mlx, "./Tiles/coin_1.xpm", &image->size_x, &image->size_y);
	image->c2 = mlx_xpm_file_to_image(vars->mlx, "./Tiles/coin_2.xpm", &image->size_x, &image->size_y);
	image->exit = mlx_xpm_file_to_image(vars->mlx, "./Tiles/Exit.xpm", &image->size_x, &image->size_y);
	image->barrel = mlx_xpm_file_to_image(vars->mlx, "./Tiles/barrel.xpm", &image->size_x, &image->size_y);
}

// xpm file to window, when destroy image/window, it doesn't delete the pointer.

int	main(int argc, char	**argv)
{
	t_prgrm	vars;
	t_image	image;

	if (argc < 2 || argc > 2)
		ft_error(&vars, 1);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		perror("Connection to graphics unit failed.");
	ft_printf("Initialized connection to display...\n");
	ft_put_values(&vars, &image);
	ft_read_from_map(&vars, argv[1]);
	ft_check_map_border(&vars, &image);
	vars.mlx_win = mlx_new_window(vars.mlx, (vars.x * 32) + 64, (vars.y * 32) + 64, "so_long");
	ft_printf("Window address: %p\n", vars.mlx_win);
	if (vars.mlx_win == NULL)
		perror("Window initialization failed.");
	ft_printf("Opened window...\n");
	ft_create_image(&vars, &image);
	ft_hooks(&vars);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
