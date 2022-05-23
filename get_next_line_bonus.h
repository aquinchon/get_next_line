/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:49 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/19 10:25:56 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FD_MAX 1024

/* Fonctions get_next_line*/
char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_cutline(char *buffer);
char	*ft_cpybuffer(char *buffer, char *buf_read);
char	*ft_resize_buffer(char *buffer);
/* Fonctions utiles */
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
