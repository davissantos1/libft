/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:53:02 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/14 19:53:22 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gc_findptr_tag(void *ptr, t_gc *gc, t_gc_tag tag)
{
	t_gc_node	*head;

	head = gc->lists[tag];
	while (head)
	{
		if (head->ptr == ptr)
			return (head->ptr);
		head = head->next;
	}
	return (NULL);
}

void	*gc_findptr(void *ptr, t_gc *gc)
{
	t_gc_node	*head;
	size_t		index;

	index = 0;
	head = gc->lists[index];
	while (index < GC_COUNT)
	{
		head = gc_findptr_tag(ptr, gc, index);
		if (head)
			return (head);
		index++;
	}
	return (NULL);
}

void	gc_delptr(void *ptr, t_gc *gc, t_gc_tag tag)
{
	t_gc_node	*temp;
	t_gc_node	*head;

	if (!gc_findptr(ptr, gc))
		return;
	head = gc->lists[tag];
	while (head->ptr != ptr)
	{
		if ((head->next)->ptr == ptr)
			temp = head;	
		head = head->next;
	}
	temp->next = head->next;
	ft_free(&head->ptr);
	ft_free(&head);
}
