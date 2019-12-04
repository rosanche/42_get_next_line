/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:15:23 by rosanche          #+#    #+#             */
/*   Updated: 2019/11/26 14:15:26 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	int	i;

	if (!(dest || src))
		return (NULL);
	if (src + n > dest && src + n <= dest + n)
	{
		i = n;
		while (--i >= 0)
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	}
	return (dest);
}

char	*ft_strchr(const char *s, unsigned char c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		v;
	char	*src;

	i = 0;
	v = 0;
	while (s1[i])
		i++;
	while (s2[v])
		v++;
	if (!s1 || !s2)
		return (NULL);
	if (!(src = (char *)malloc(sizeof(char) * (i + v +
						1))))
		return (NULL);
	i = 0;
	v = -1;
	while (s1[++v] && s1 + i != s2)
		src[i++] = s1[v];
	v = -1;
	while (s2[++v])
		src[i++] = s2[v];
	src[i] = '\0';
	return (src);
}

char	*ft_strnew(size_t size)
{
	char	*src;
	size_t	i;

	i = 0;
	if (!(src = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		src[i] = '\0';
		i++;
	}
	src[i] = '\0';
	return (src);
}
