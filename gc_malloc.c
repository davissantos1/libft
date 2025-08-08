/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:55 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/08 19:59:29 by dasimoes         ###   ########.fr       */
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

void	*gc_malloc(size_t size, t_gc_tag tag)
{
	t_gc_node	*node;
	t_gc_node	*head;
	t_gc		*gc;
	void		*p;

	if (size == 0 || tag >= GC_COUNT)
		return (NULL);
	gc = gc_get();
	if (!gc)
		return (NULL);
	head = gc->lists[tag];
	p = malloc(size);
	if (!p)
		return (NULL);
	node = gc_create_node(p);
	if (!node)
		return (ft_free(p));
	if (!head)
	{
		gc->lists[tag] = node;
		return (p);
	}
	node->next = head;
	gc->lists[tag] = node;
	return (p);
}
