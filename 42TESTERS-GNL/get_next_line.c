/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bothilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:40:19 by bothilie          #+#    #+#             */
/*   Updated: 2019/11/11 12:11:27 by bothilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_delete(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	new = ft_strdup(str + i + 1);
	ft_strdel(&str);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int		ft_copyuntil(char **dst, char *src, char c)
{
	t_gnl	var;
	char	*tmp;
	int		dest_size;
	int		i;

	var.j = -1;
	while (src[++var.j])
	{
		if (src[var.j] == c)
			break ;
	}
	var.res = var.j;
	tmp = ft_strdup(*dst);
	free(*dst);

	if (!(var.buf = ft_strnew(ft_strlen(tmp) + var.res)))
		return (-1);
	i = 0;
	dest_size = 0;
	while (var.buf[dest_size])
		dest_size++;
	while (i < var.res && src[i])
		var.buf[dest_size++] = src[i++];
	var.buf[dest_size] = '\0';
	*dst = var.buf;
	free(tmp);
	return (var.res);
}

t_list	*get_lst(t_list **file, int fd)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *file;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = "\0";
	new->content_size = fd;
	new->next = *file;
	*file = new;
	return (new);
}

char	*ft_fill(char *curr, char *buf, int res)
{
	char	*tmp;

	buf[res] = '\0';
	if (!(tmp = ft_strjoin(curr, buf)))
		return (NULL);
	free(curr);
	curr = NULL;
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char		*s;
	t_gnl			var;

	if (!line || !(var.buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		|| fd < 0 || read(fd, var.buf, 0) < 0 || BUFFER_SIZE <= 0 ||
		(!(*line = ft_strnew(1))))
		return (-1);
	if (!s)
		s = ft_strnew(1);
	var.j = 0;
	while ((var.res = read(fd, var.buf, BUFFER_SIZE)))
	{
		s = ft_fill(s, var.buf, var.res);
		if (ft_strchr(var.buf, '\n'))
			break ;
	}
	free(var.buf);
	var.j = ft_copyuntil(line, s, '\n');
	if (var.j == ft_strlen(s) && var.res != BUFFER_SIZE)
		return (ft_strclr(s));
	s = ft_delete(s);
	return (1);
}
