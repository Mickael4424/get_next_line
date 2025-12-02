/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickael <mickael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:38:14 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/02 12:33:37 by mickael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

char *clean_stash(char *stash)
{
    char *new_stash;
    int i;
    int j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i]!= '\n')
        i++;
    if (!stash[i])
    {
        free (stash);
        return (NULL);
    }
    new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
    if (!new_stash)
        return (NULL);
    i++;
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

char *extract_stash(char *stash)
{
    char *line;
    int i;

    i = 0;
    if (!stash[0])
        return (NULL);
    while (stash[i] && stash [i] != '\n')
    {
        i++;
    }
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

char *read_stash(int fd, char *stash)
{
    char *temp_buffer;
    int bytes_read;

    temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp_buffer)
        return(NULL);
    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
        if(bytes_read <= 0)
            break;
        temp_buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, temp_buffer);
    }
    free(temp_buffer);
    if (bytes_read < 0 || (bytes_read == 0 && ft_strlen(stash) == 0))
    {    
        free(stash);
        return(NULL);
    }
    return (stash);
}   

char *get_next_line(int fd)
{
    static char* stash[FD_SIZE];
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
        return (NULL);
    if (!stash[fd])
        stash[fd] = ft_strdup("");
    stash[fd] = read_stash(fd, stash[fd]);
    if (!stash[fd])
        return (NULL);    
    line = extract_stash(stash[fd]);
    if (!line)
        return(NULL);
    stash[fd] = clean_stash(stash[fd]);
    return(line);
}
