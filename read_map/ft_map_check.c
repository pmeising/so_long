/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 21:20:31 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/14 12:55:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_check(t_prgrm *vars, char *map)
{
	int		len;

	len = ft_strlen(map);
	if (!(map[len - 1] == 'r' && map[len - 2] == 'e' && map[len - 3] == 'b'
			&& map[len - 4] == '.'))
		ft_error(vars, 6);
}
