/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:55:28 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 21:21:29 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map_player(t_prgrm *vars)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while ((i > 0 && i < (vars->y - 1)) && vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == 'P')
				p++;
			if (vars->map[i][0] != '1' || vars->map[i][vars->x - 1] != '1')
				ft_error(vars, 2);
			if (vars->map[i][j] != '1' && vars->map[i][j] != '0' &&
				vars->map[i][j] != 'C' && vars->map[i][j] != 'E' &&
				vars->map[i][j] != 'P' && vars->map[i][j] != 'V')
				ft_error(vars, 2);
			j++;
		}
		i++;
	}
	if (p != 1)
		ft_error(vars, 2);
}

void	ft_check_map_items(t_prgrm *vars)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	vars->coins = 0;
	e = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while ((i > 0 && i < (vars->y - 1)) && vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == 'C')
			{
				vars->coins++;
			}
			if (vars->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (vars->coins < 1 || e < 1)
		ft_error(vars, 2);
}

void	ft_check_map_border(t_prgrm *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		if (ft_strlen(vars->map[j]) != (size_t)vars->x)
			ft_error(vars, 2);
		while ((i == 0 || i == (vars->y -1)) && vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] != '1')
				ft_error(vars, 2);
			j++;
		}
		i++;
	}
	ft_check_map_items(vars);
	ft_check_map_player(vars);
}

// in this fuction I find each new line character in the string and replace 
// it with an end of line character.

void	ft_replace_new_line(t_prgrm *vars)
{
	int	i;

	i = 0;
	while (vars->map[vars->y][i] != '\0')
	{
		if (vars->map[vars->y][i] == '\n')
		{
			vars->map[vars->y][i] = '\0';
			return ;
		}
		i++;
	}
}

// MAXIMUM SET FOR ROWS TO 500 IN THIS FUNCTION.

void	ft_read_from_map(t_prgrm *vars, char *map)
{
	int		fd;
	char	*row_1;

	ft_map_check(vars, map);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(vars, 3);
	row_1 = get_next_line(fd);
	if (row_1 == NULL)
		ft_error(vars, 4);
	vars->x = ft_strlen(row_1) - 1;
	row_1[vars->x] = '\0';
	vars->map = malloc(500);
	vars->map[vars->y] = row_1;
	while (vars->map[vars->y] != NULL)
	{
		vars->y++;
		vars->map[vars->y] = get_next_line(fd);
		if (vars->map[vars->y] == NULL)
			break ;
		if (ft_strchr(vars->map[vars->y], '\n') != 0)
			ft_replace_new_line(vars);
	}
	close(fd);
}
