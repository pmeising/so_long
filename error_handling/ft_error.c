/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:17 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/09 22:11:54 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_prgrm *vars, int ecode)
{
	if (ecode == 0)
		ft_printf("CONGRATULATIONS! You won the game!\n");
	else if (ecode == 1)
		ft_printf("Invalid input syntax.\n");
	else if (ecode == 2)
		ft_printf("Invalid map.\n");
	else if (ecode == 3)
		ft_printf("Map not found.");
	ft_close_program(vars, ecode);
}