/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickael <mickael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:38:09 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/02 12:27:23 by mickael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef FD_SIZE
# define FD_SIZE 1064
#endif

char    *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *str, size_t	n);
void	*ft_calloc(size_t	nmemb, size_t	size);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif