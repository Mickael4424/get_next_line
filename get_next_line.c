/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:30:53 by mbouyer           #+#    #+#             */
/*   Updated: 2025/11/28 15:47:56 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *set_line(char *line_buffer);
{
    static char *left;
    
    left = ft_strrchr(buffer);
}
*/

char *fill_line_buffer(int fd, char *buffer)
{
	int bytes;
	char *text;
	char *stash;
	int i;

    bytes = 0;
    text = NULL;   
    stash = NULL;

	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
        text = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (text == NULL)
            return(NULL);
		if (ft_strrchr(buffer, '\n') != 0)
		{
			//left_c = ft_strrchr(text, '\n') + 1;
			i = 0;
			while (buffer[i] != '\n')
			{
				text[i] = buffer[i];
				i++;
			}
			text[i] = buffer[i];
            i++;
            text[i] = '\0';   
            free(buffer);
			break;
		}
		else if (ft_strrchr(text, '\0') != 0)
		{
			i = 0;
			while (buffer[i] != '\0')
			{
				text[i] = buffer[i];
				i++;
			}
			text[i] = buffer[i];
            i++;
            text[i] = '\0';
            free(buffer);
			break;
		}
        else
        {
            i = 0;
            while(buffer)
            {
                text[i] = buffer[i];
                i++;
            }
            free(buffer);
            break;
        }
		stash = ft_strjoin(stash, text);
        printf("%s", stash);
        if (stash == NULL)
        {
            free(stash);
            return (NULL);
        }
	}
    if (bytes <= 0)
    {
        free (buffer);
        return(NULL);
    }
    free(text);
	free(stash);
	return (NULL);
}

char *get_next_line(int fd)
{
	char *buffer;

    if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (buffer == NULL)
        return (NULL);
	fill_line_buffer(fd, buffer);
    free(buffer);
	return (NULL);
}

int main (void)
{	
	int fd;
    int count;
    char *next_line;
	
    fd = 0;
	count = 0;
    next_line = NULL;
	fd = open("cat.txt", O_RDONLY);
    if (fd == -1)
        printf("error opening");
        return (1);
    get_next_line(fd);
    /*
	while (1)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break;
        count++;
        printf("[%d]:%s\n", count, next_line);
        free (next_line);
        next_line = NULL;
    }
    */
	close(fd);
	return (0);
}

/*
utiliser une seule variable statique
utiliser argc / argv pour le fichier a inserer
chaque appel de fonction doit faire apparaitre une ligne
*/