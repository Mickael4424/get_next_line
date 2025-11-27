/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:38:14 by mbouyer           #+#    #+#             */
/*   Updated: 2025/11/27 16:32:48 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char *set_line(char *line_buffer);

char *fill_line_buffer(int fd, char *buffer)
{
	int char_to_read;
	char *text;
	char *stash;
	
	while ((char_to_read = read(fd, buffer, 42)) > 0 && buffer != '\n' && buffer != '\0')
	{
		text = ft_strdup(buffer);
		stash = ft_strjoin(stash, text);
	}
	printf("%s", stash);
	free(text);
	free(stash);
	return (NULL);
}

char *get_next_line(int fd)
{
	if (fd == -1)
		return NULL;
	char buffer[BUFFER_SIZE];
	fill_line_buffer(fd, buffer);
	return (NULL);
}

int main (void)
{	
	int fd;
	fd = open("cat.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (0);
}

/*
utiliser une seule variable statique
utiliser argc / argv pour le fichier a inserer
chaque appel de fonction doit faire apparaitre une ligne
*/