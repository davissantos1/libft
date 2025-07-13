/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:13:28 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/13 20:18:18 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*next;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		next = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = next;
	}
}	
