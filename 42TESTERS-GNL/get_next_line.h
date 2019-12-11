/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bothilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:39:00 by bothilie          #+#    #+#             */
/*   Updated: 2019/11/11 12:10:31 by bothilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_list
{
	char			*content;
	int				content_size;
	struct s_list	*next;
	int				f;
}				t_list;

typedef struct	s_gnl
{
	char	*buf;
	int		res;
	size_t	j;
}				t_gnl;

size_t			ft_strlen(const char *str);
int				ft_strclr(char *s);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_copyuntil(char **dst, char *src, char c);
t_list			*get_lst(t_list **file, int fd);
char			*ft_fill(char *s, char *buf, int res);
int				get_next_line(int fd, char **line);
#endif
