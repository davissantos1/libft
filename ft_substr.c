/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:07:06 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/11 16:28:20 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_string;

	i = 0;
	if (start >= ft_strlen(s))
	{
		sub_string = (char *)malloc(1 * sizeof(char));
		sub_string[0] = '\0';
		return (sub_string);
	}
	sub_string = (char *)malloc((len + 1) * sizeof(char));
	if (sub_string == ((void *)0))
		return ((void *)0);
	while (s[start] && (i < len))
	{
		sub_string[i] = s[start];
		start++;
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
