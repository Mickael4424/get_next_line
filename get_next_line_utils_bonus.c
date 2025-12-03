/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:38:27 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/03 10:44:46 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char) c;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == cc)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == cc)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*dup_s;

	dup_s = (char *) malloc(ft_strlen(s) + 1);
	if (!dup_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[i] = 0;
	return (dup_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	k = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((k + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[j])
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
