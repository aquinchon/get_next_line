/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:26:35 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/19 12:27:09 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*mem;
	size_t	i;

	total = size * nmemb;
	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	if (total == 0)
		mem = malloc(1);
	else
		mem = malloc(total);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < total)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	if (c < 0)
		return (NULL);
	if (c > 255)
		return (NULL);
	while (*(tmp + i))
	{
		if (*(tmp + i) == c)
			return (tmp + i);
		i++;
	}
	if (*(tmp + i) == c)
		return (tmp + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	size;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
