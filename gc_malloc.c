#include "libft.h"

void	*gc_create_node(t_gc *gc, size_t size, t_gc_tag tag)
{
	t_gc_node	*head;
	t_gc_node	*node;
	
	head = gc->lists[tag];
	if (!head)
	{
			head  = malloc(sizeof(t_gc_node));
			if (!head)
				return (NULL);
			head->ptr = malloc(size);
			if (!head->ptr)
				return (NULL);
			head->next = NULL;
			gc->lists[tag] = head;
			return (head->ptr);
	}
	node = malloc(sizeof(t_gc_node));
	if (!node)
		return (NULL);
	node->ptr = malloc(size);
	if (!node->ptr)
		return (NULL);
	node->next = NULL;
	ft_lstadd_back(head, node);
	return (node->ptr);
}

void	*gc_free_tag(t_gc_malloc *head)
{

}
void	*gc_free_all(t_gc_malloc *head)
{
		
		
}
	
void	*gc_malloc(size_t size, t_gc_tag tag)
{
	static t_gc *gc;
	t_gc_node	*node;

	if (!gc)
	{
		gc = malloc(sizeof(t_gc));
		if (!gc)
			return (NULL);
	}
	node = gc_create_node(gc, size, tag);

	
}
	
