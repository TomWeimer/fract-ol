/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_node_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:37:08 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:37:36 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_new_node_back(t_list *list, char new_data)
{
	t_node	*new;
	t_node	*actual;

	new = malloc (sizeof(t_node));
	if (!list || !new)
	{
		printf("erreur");
		return ;
	}
	actual = list->first;
	while (actual->next != NULL)
		actual = actual->next;
	actual->next = new;
	new->data = new_data;
	new->next = NULL;
}
