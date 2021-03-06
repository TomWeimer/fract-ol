/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:09:18 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:36:24 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_list_to_string(t_list *list, size_t len)
{
	char	*str;
	int		i;
	t_node	*actual;
	t_node	*to_delete;

	i = 0;
	if (list == NULL)
		return (NULL);
	actual = list->first;
	str = malloc(len + 1);
	while (len--)
	{
		if (list->first != NULL)
		{
			to_delete = actual;
			str[i] = actual->data;
			actual = actual->next;
			list->first = actual;
			free(to_delete);
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
