/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:55:28 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/04 21:47:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// MAXIMUM SET FOR ROWS TO 500 IN THIS FUNCTION.

void	ft_read_from_map(t_prgrm *vars, char *map)
{
	int		fd;
	char	*row_1;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_printf("Opening didn't work.\n");
	row_1 = get_next_line(fd);
	if (row_1 == NULL)
		ft_printf("File empty\n");
	ft_printf("Row %d: %s", vars->y, row_1);
	vars->x = ft_strlen(row_1) - 1;
	row_1[vars->x] = '\0';
	vars->map = malloc (500);
	vars->map[vars->y] = row_1;
	while (vars->map[vars->y] != NULL)
	{
		vars->y++;
		vars->map[vars->y] = get_next_line(fd);
		ft_printf("Row %d: %s", vars->y, vars->map[vars->y]);
		if (vars->map[vars->y] == NULL)
			break;
		if (vars->map[vars->y][vars->x] == '\n')
			vars->map[vars->y][vars->x] = '\0';
		if (ft_strlen(vars->map[vars->y]) != (size_t)vars->x)
			ft_error(1);
		ft_printf("Row %d: %s", vars->y, vars->map[vars->y]);
	}
	vars->map[vars->y] = NULL;
	ft_printf("y = %d, x = %d\n", vars->y, vars->x);
	ft_printf("%s\n%s\n%s\n", vars->map[0], vars->map[1], vars->map[2]);
}
