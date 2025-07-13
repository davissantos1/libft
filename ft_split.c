/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:38:05 by dasimoes          #+#    #+#             */
/*   Updated: 2025/07/13 20:57:50 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_size(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (!s || !*s)
		return (0);
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_split_aux(char const *s, char c, size_t index)
{
	size_t	start;
	size_t	string;
	size_t	i;

	i = 0;
	string = 0;
	while (s[i])
	{
		
		i++;
	}
	return (ft_substr(s, start, end - start));
}

char	**ft_split(char const *s, char c)
{
	char	**split_s;
	size_t	sz;
	size_t	i;

	i = 0;
	sz = ft_split_size(s, c);
	split_s = (char **)malloc((sz + 1) * sizeof(char *));
	if (!split_s)
		return (NULL);
	while (i < sz)
	{
		split_s[i] = ft_split_aux(s, c, i);
		if (!split_s[i])
		{
			while (i > 0)
				free(split_s[--i]);	
			free(split_s);
			return (NULL);
		}
		i++;
	}
	split_s[sz] = NULL;
	return (split_s);
}
