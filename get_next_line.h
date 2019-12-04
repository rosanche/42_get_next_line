/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:43:39 by rosanche          #+#    #+#             */
/*   Updated: 2019/12/02 11:09:38 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define EOL '\n'

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

int		get_next_line(const int fd, char **line);
int		eol_search(char **line, char *tmp, char *str);
int		found_eol(char *tmp, char *rpl, char **line, char *str);
int		return_result(char **line, char *tmp, char *str, const int fd);
int		ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
char	*ft_strchr(const char *s, unsigned char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif
