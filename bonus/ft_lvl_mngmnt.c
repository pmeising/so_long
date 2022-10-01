/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvl_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:10:42 by pmeising          #+#    #+#             */
/*   Updated: 2022/10/02 00:21:43 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_set_lvl(t_prgrm *vars)
{
	if (ft_strchr(vars->argv[1], '1') != NULL)
		vars->lvl = 1;
	if (ft_strchr(vars->argv[1], '2') != NULL)
		vars->lvl = 2;
	if (ft_strchr(vars->argv[1], '3') != NULL)
		vars->lvl = 3;
	if (ft_strchr(vars->argv[1], '4') != NULL)
		vars->lvl = 4;
	if (ft_strchr(vars->argv[1], '5') != NULL)
		vars->lvl = 5;
}

void	ft_keep_lvls_running(int lvl, char *name, int moves, long time, char **envp)
{
	char	*map1;
	char	*map2;
	char	*DIR;
	char	*DIR_2;
	t_prgrm	vars;

	vars.envp = envp;
	vars.lvl = lvl + 1;
	DIR = "./lvl_maps/Lvl";
	DIR_2 = ".ber";
	map1 = ft_strjoin(DIR, ft_itoa(vars.lvl));
	map2 = ft_strjoin(map1, DIR_2);
	vars.mlx = mlx_init();
	ft_put_values(&vars);
	vars.username = name;
	vars.moves = moves;
	if ((vars.log_file = open("./log/record", O_RDWR | O_APPEND, 0644)) == -1)
		ft_printf("Couldn't open log file.\n Game ist not saved.\n");
	write(vars.log_file, ",", 1);
	write(vars.log_file, ft_itoa(moves), ft_strlen(ft_itoa(moves)));
	write(vars.log_file, ",", 1);
	write(vars.log_file, ft_itoa(time), ft_strlen(ft_itoa(time)));
	write(vars.log_file, "\n", 1);
	write(vars.log_file, ft_itoa(vars.lvl), 1);
	write(vars.log_file, ",", 1);
	write(vars.log_file, name, (ft_strlen(name) - 1));
	close(vars.log_file);
	ft_read_from_map(&vars, map2);
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
}
