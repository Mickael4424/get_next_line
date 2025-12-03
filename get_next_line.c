/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:30:53 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/03 15:57:16 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*extract_stash(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[0] || !stash)
		return (NULL);
	while (stash[i] && stash [i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*join_stash(char *new_stash, char *temp_buffer, char *stash)
{
	new_stash = ft_strjoin(stash, temp_buffer);
	if (!new_stash)
	{
		free(temp_buffer);
		return (NULL);
	}
	free(stash);
	return (new_stash);
}

char	*read_stash(int fd, char *stash)
{
	char	*temp_buffer;
	char	*new_stash;
	int		bytes_read;

	bytes_read = 1;
	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		new_stash = NULL;
		stash = join_stash(new_stash, temp_buffer, stash);
	}
	free(temp_buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!stash || stash[0] == '\0')))
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_stash(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
