#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->right = 0;
	node->left = 0;
	node->item = item;
	return (node);
}
