/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:53:02 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/08 20:00:38 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gc	*g_gc = NULL;

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

t_gc	*gc_get(void)
{
	if (!g_gc)
		g_gc = gc_init();
	return (g_gc);
}

void	gc_free_tag(t_gc_tag tag)
{
	t_gc_node	*tmp;

	if (!g_gc || tag >= GC_COUNT)
		return ;
	while (g_gc->lists[tag])
	{
		tmp = g_gc->lists[tag]->next;
		free(g_gc->lists[tag]->ptr);
		free(g_gc->lists[tag]);
		g_gc->lists[tag] = tmp;
	}
}

void	gc_free_all(void)
{
	int			i;

	i = 0;
	if (!g_gc)
		return ;
	while (i < GC_COUNT)
		gc_free_tag(i++);
	free(g_gc);
	g_gc = NULL;
}
