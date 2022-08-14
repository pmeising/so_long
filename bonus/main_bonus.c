/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:36:42 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 17:00:07 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_create_image_2(t_prgrm *vars, char c)
{
	if (c == '0')
		ft_put_square(vars, 0);
	else if (c == '1')
		ft_put_square(vars, 1);
	else if (c == 'C')
		ft_put_square(vars, 2);
	else if (c == 'E')
		ft_put_square(vars, 3);
	else if (c == 'P')
		ft_put_square(vars, 4);
}

void	ft_create_image(t_prgrm *vars)
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
			ft_create_image_2(vars, vars->map[i][j]);
			j++;
		}
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
	vars->moves = 0;
	vars->counter = 0;
	vars->counter_vil = 0;
	vars->animate = 1;
	vars->i = 0;
	vars->dir = 1;
	vars->dir_vil = 1;
	vars->steps = 0;
	vars->villain = 0;
}

int	main(int argc, char	**argv)
{
	t_prgrm	vars;

	if (argc < 2 || argc > 2)
		ft_error(&vars, 1);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		perror("Error\nConnection to graphics unit failed.");
	ft_put_values(&vars);
	ft_read_from_map(&vars, argv[1]);
	ft_check_map_border(&vars);
	vars.mlx_win = mlx_new_window(vars.mlx, (vars.x * 32) + 64,
			(vars.y * 32) + 96, "so_long");
	if (vars.mlx_win == NULL)
		perror("Error\nWindow initialization failed.");
	ft_create_image(&vars);
	ft_put_flames(&vars);
	ft_put_villain(&vars);
	ft_hooks(&vars);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop_hook(vars.mlx, ft_loop, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
