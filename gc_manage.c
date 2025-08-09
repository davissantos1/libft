/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:53:02 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/09 14:27:41 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

t_gc	*gc_init(void)
{
	t_gc	*gc;
	int		i;

	i = 0;
	gc = malloc(sizeof(t_gc));
	if (!gc)
		return (NULL);
	while (i < GC_COUNT)
	{
		gc->lists[i] = NULL;
		i++;
	}
	return (gc);
}

void	gc_free_tag(t_gc *gc, t_gc_tag tag)
{
	t_gc_node	*tmp;

	if (!gc || tag >= GC_COUNT)
		return ;
	while (gc->lists[tag])
	{
		tmp = gc->lists[tag]->next;
		free(gc->lists[tag]->ptr);
		free(gc->lists[tag]);
		gc->lists[tag] = tmp;
	}
}

void	gc_free_all(t_gc **gc)
{
	int			i;

	i = 0;
	if (!gc || !*gc)
		return ;
	while (i < GC_COUNT)
		gc_free_tag(*gc, i++);
	free(*gc);
	*gc = NULL;
}
