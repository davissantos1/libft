/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:36:40 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/09 15:01:33 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_aux(unsigned char *pd, unsigned char const *ps, size_t n)
{
	size_t	i;

	i = 0;
	if (ps < pd)
	{
		while (n > 0)
		{
			n--;
			pd[n] = ps[n];
		}
	}
	else
	{
		while (i < n)
		{
			pd[i] = ps[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if ((!dest || !src) && n != 0)
		return ((void *)0);
	ft_aux(ptr_dest, ptr_src, n);
	return (dest);
}
