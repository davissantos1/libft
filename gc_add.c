/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:27:31 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/15 19:54:53 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gc_addptr(void *p, t_gc *gc, t_gc_tag tag)
{
	t_gc_node	*node;

	if (gc_findptr(p, gc))
		return (p);
	node = gc_create_node(ptr);
	if (!node)
		return (NULL);
	if (!gc->lists[tag])
		gc->lists[tag] = node;
	else
	{
		node->next = gc->lists[tag];
		gc->lists[tag] = node;
	}
	return (p);
}

void	*gc_addmtx(void *mtx, t_gc *gc, t_gc_tag tag)
{
	char 	**matrix;
	void	*temp;
	int		index;

	index = 0;
	matrix = (char **)mtx;
	while (matrix[index])
	{
		temp = gc_addptr(matrix[index], gc, tag);
		if (!temp)
		{
			while (matrix[index] && index > 0)
			{
				gc_delptr(matrix[index], gc, tag);
				index--;
			}
			return (NULL);
		}
		index++;
	}
	return (mtx);
}

void		*gc_addlst(void *head, t_gc *gc, t_gc_tag tag)
{
	t_list		*list;
	t_list		*temp;
	void		*added;

	list = (t_list *)head;
	temp = (t_list *)head;
	while (list)
	{
		added = gc_addptr(list, gc, tag);
		if (!added)
		{
			ft_lstclear(&temp, free);
			return (NULL);
		}
		list = list->next;
	}
	return (head);
}

void		*gc_addbtree(void *root, t_gc *gc, t_gc_tag tag);
{
	void	*temp;

	if (!root)
		return (NULL);
	temp = gc_addptr(root, gc, tag);
	temp = gc_addptr(root->item, gc, tag);
	gc_addbtree(root->left, gc, tag);
	gc_addbtree(root->right, gc, tag);
	return (root);
}
