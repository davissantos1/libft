/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:38:05 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/13 16:30:01 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_size(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i + 1]) && ((s[i] == c) && (s[i + 1] != c)))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_split_aux(char const *s, char c, size_t i, size_t sz)
{
	size_t	start;
	size_t	end;
	size_t	str;

	start = 0;
	str = i;
	while (str)
	{
		if ((s[start + 1]) && ((s[start] == c) && (s[start + 1] != c)))
			str--;
		start++;
	}
	str = i;
	end = start;
	while (str)
	{
		if ((s[end + 1]) && ((s[end] == c) && (s[end + 1] != c)))
			str--;
		end++;
	}
	return (ft_substr(s, start, end - start));
}

char	**ft_split(char const *s, char c)
{
	char	**split_s;
	size_t	sz;
	size_t	i;

	i = 0;
	sz = ft_split_size(s);
	split_s = (char **)malloc((sz + 1) * sizeof(char *));
	if (!split_s)
		return (NULL);
	split_s[sz] = NULL;
	while (i < sz)
	{
		split_s[i] = ft_split_aux(*s, c, i + 1, sz);
		i++;
	}
	return (split_s);
}
