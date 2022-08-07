/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:47:17 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 22:45:05 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_prgrm *vars, t_image *image, int ecode)
{
	if (ecode == 1)
		ft_printf("Error occurred.\n");
	else if (ecode == 2)
		ft_printf("Invalid map.\n");
	ft_printf("%d\n", vars->pos_square_x);
	ft_close_program(vars, image);
}