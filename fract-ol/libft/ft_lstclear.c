/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:28:07 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:39:35 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_node	*actual;
	t_node	*to_delete;

	if (lst == NULL || del == NULL)
		return ;
	actual = *lst;
	while (actual != NULL)
	{
		to_delete = actual;
		actual = actual->next;
		del(to_delete->data);
		free(to_delete);
	}
	*lst = NULL;
}
