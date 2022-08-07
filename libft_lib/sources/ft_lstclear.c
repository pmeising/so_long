/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:06:30 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:13:13 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*first;

	if (lst == NULL || del == NULL)
		return ;
	first = *lst;
	ptr = first->next;
	while (first != NULL)
	{
		ptr = first->next;
		del(first->content);
		free(first);
		first = ptr;
	}
	*lst = NULL;
}
