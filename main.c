/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:36:42 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/04 21:13:54 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_prgrm *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (0);
}

void	ft_mlx_pixel_put_fast(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addrs + (y * image->line_size + x * image->bpp / 8);
	*(unsigned int *)dst = color;
}

void	ft_create_image(t_prgrm *vars, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("Entering create image function.\n");
	ft_printf("vars->map[0]; %s\n", vars->map[0]);
	ft_printf("vars->map[0][0]: %c\n", vars->map[0][0]);
	ft_printf("1_0: %c\n", vars->map[1][0]);
	ft_printf("1_1: %c\n", vars->map[1][1]);
	while (vars->map[i] != NULL)
	{
		j = 0;
		vars->pos_square_y = vars->pos_square_y + 32;
		vars->pos_square_x = 0;
		while (vars->map[i][j] != '\0')
		{
			vars->pos_square_x = vars->pos_square_x + 32;
			ft_printf("In while: %c\n", vars->map[i][j]);
			if (vars->map[i][j] == '0')
				ft_put_square(vars, image, 0);
			else if (vars->map[i][j] == '1')
				ft_put_square(vars, image, 1);
			else if (vars->map[i][j] == 'C')
				ft_put_square(vars, image, 2);
			else if (vars->map[i][j] == 'E')
				ft_put_square(vars, image, 3);
			else if (vars->map[i][j] == 'P')
				ft_put_square(vars, image, 4);
			j++;
		}
		ft_printf("___________________\n");
		i++;
	}
}

void	ft_put_values(t_prgrm *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->pos_square_x = 0;
	vars->pos_square_y = 0;
	vars->map_source = NULL;
}

// xpm file to window, when destroy image/window, it doesn't delete the pointer.

int	main(int argc, char	**argv)
{
	t_prgrm	vars;
	t_image	image;

	if (argc < 2 || argc > 2)
		ft_error(1);
	ft_put_values(&vars);
	ft_read_from_map(&vars, argv[1]);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
	{
		printf("Connection failed.\n");
		exit(0);
	}
	ft_printf("Initialized connection to display...\n");
	vars.mlx_win = mlx_new_window(vars.mlx, (vars.x * 32) + 100, (vars.y * 32) + 100, "so_long");
	ft_printf("Window address: %p\n", vars.mlx_win);
	if (vars.mlx_win == NULL)
	{
		printf("Window could not be opened.\n");
		exit(0);
	}
	ft_printf("Opened window...\n");
	ft_create_image(&vars, &image);
	ft_hooks(&vars);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
}
