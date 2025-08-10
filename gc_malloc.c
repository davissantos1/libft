/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:55 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/09 16:23:27 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc_node	*gc_create_node(void *p)
{
	t_gc_node	*node;

	node = malloc(sizeof(t_gc_node));
	if (!node)
		return (NULL);
	node->ptr = p;
	node->next = NULL;
	return (node);
}

void	*gc_malloc(t_gc *gc, size_t size, t_gc_tag tag)
{
	t_gc_node	*node;
	void		*p;

	if (size == 0 || tag >= GC_COUNT)
		return (NULL);
	if (!gc)
		return (NULL);
	p = malloc(size);
	if (!p)
		return (NULL);
	node = gc_create_node(p);
	if (!node)
		return (ft_free(&p));
	if (!gc->lists[tag])
		gc->lists[tag] = node;
	else
	{
		node->next = gc->lists[tag];
		gc->lists[tag] = node;
	}
	return (p);
}
