/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:17 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/06 23:44:56 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_prgrm *vars, int ecode)
{
	if (ecode == 1)
		ft_printf("Error occurred.\n");
	else if (ecode == 2)
		ft_printf("Invalid map.\n");
	free(vars->mlx_win);
	free(vars->mlx);
	free(vars->map);
	exit (0);
}