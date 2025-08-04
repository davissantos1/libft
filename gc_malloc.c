#include "libft.h"

void	*gc_malloc_free_all(t_gc_malloc *head)
{
	t_gc_malloc *tmp;

	while (head)
	{
		tmp = head;
		if (head->ptr && head->tag)
			free(head->ptr);
		
		
	
void	*gc_malloc(size_t size, t_gc_tag tag)
{
	static t_gc *gc;
	t_gc_node	*head;

	head = gc->lists[tag];
	if (!gc)
	{
		gc = malloc(sizeof(t_gc));
		if (!gc)
			return (NULL);
	}
	if (!head)
	{
			head  = malloc(sizeof(t_gc_node));
			if (!head)
				return (NULL);
	}
	
}
	
