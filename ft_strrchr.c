/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:51:56 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/10 11:14:22 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;

	size = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *) &s[size]);
	while (size >= 0)
	{
		if (s[size] == c)
			return ((char *)&s[size]);
		size--;
	}
	return ((void *)0);
}
