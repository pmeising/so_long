/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_records.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:30:54 by pmeising          #+#    #+#             */
/*   Updated: 2022/10/02 00:43:00 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_sort_highscore(t_prgrm *vars)
{
	char	**string;

	ft_printf("Entereing in execve function.\n");
	string = malloc(sizeof(char) *50);
	string[0] = "sort";
	string[1] = "-n ./log/Highscores";
	string[2] = NULL;
	if (execve("./usr/bin/sort", string, vars->envp) == -1)
		ft_printf("After Execve function failed.\n");
}

void	ft_print_records(int lvl, char *name, int moves, long time)
{
	int	file;

	if ((file = open("./log/Highscores", O_RDWR | O_APPEND, 0644)) == -1)
		ft_printf("Couldn't open log file.\n Game ist not saved.\n");
	write(file, ft_itoa(time), ft_strlen(ft_itoa(time)));
	write(file, "	<- Time taken	", 15);
	write(file, name, (ft_strlen(name) - 1));
	write(file, "	Level: ", 8);
	write(file, ft_itoa(lvl), ft_strlen(ft_itoa(lvl)));
	write(file, "	Moves required: ", 17);
	write(file, ft_itoa(moves), ft_strlen(ft_itoa(moves)));
	write(file, "\n", 1);
	write(1, "Level: ", 7);
	write(1, ft_itoa(lvl), ft_strlen(ft_itoa(lvl)));
	write(1, "	", 1);
	write(1, name, (ft_strlen(name) - 1));
	write(1, "	Moves required: ", 17);
	write(1, ft_itoa(moves), ft_strlen(ft_itoa(moves)));
	write(1, "	Time taken: ", 13);
	write(1, ft_itoa(time), ft_strlen(ft_itoa(time)));
	write(1, "\n", 1);
}
