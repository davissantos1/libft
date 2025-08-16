/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:38:24 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/13 15:39:45 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_free_tag(t_gc *gc, t_gc_tag tag)
{
	t_gc_node	*tmp;

	if (!gc || tag >= GC_COUNT)
		return ;
	while (gc->lists[tag])
	{
		tmp = gc->lists[tag]->next;
		ft_free(&gc->lists[tag]->ptr);
		ft_free(&gc->lists[tag]);
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
	ft_free(gc);
}
