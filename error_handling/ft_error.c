/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:17 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/13 19:53:24 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_prgrm *vars, int ecode)
{
	if (ecode == 0)
		ft_printf("CONGRATULATIONS! You won the game!\n");
	else if (ecode == 1)
		ft_printf("Error\nInvalid input syntax.\n");
	else if (ecode == 2)
		ft_printf("Error\nInvalid map.\n");
	else if (ecode == 3)
		ft_printf("Error\nMap not found.");
	else if (ecode == 4)
		ft_printf("Error\nEmpty map.\n");
	else if (ecode == 5)
	{
		vars->animate = 0;
		ft_game_over(vars);
	}
	ft_close_program(vars, ecode);
}