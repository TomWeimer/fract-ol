/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:10:17 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:35:21 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_init(void)
{
	t_list	*list;
	t_node	*node;

	list = malloc(sizeof(t_list));
	node = malloc(sizeof(t_node));
	if (!list || !node)
		return (NULL);
	node->data = 0;
	node->next = NULL;
	list->first = node;
	return (list);
}
