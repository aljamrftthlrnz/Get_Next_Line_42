/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:48:00 by amirfatt          #+#    #+#             */
/*   Updated: 2023/06/09 14:52:55 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	handle_empty(char **stash)
{
	if (!*stash)
	{
		*stash = (char *)malloc(sizeof(char));
		(*stash)[0] = '\0';
	}
	if (!*stash)
	{
		free(*stash);
		*stash = NULL;
	}
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*str_joined;
	size_t	i;
	size_t	j;

	handle_empty(&stash);
	if (!stash || !buff)
		return (NULL);
	str_joined = (char *)malloc(ft_strlen(buff) + ft_strlen(stash) + 2);
	if (!str_joined)
	{
		free(stash);
		return (NULL);
	}
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			str_joined[i] = stash[i];
	while (buff[j] != '\0')
		str_joined[i++] = buff[j++];
	str_joined[ft_strlen(buff) + ft_strlen(stash)] = '\0';
	free(stash);
	return (str_joined);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*read_into_new_stash(char *old_stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (old_stash[i] && old_stash[i] != '\n')
		i++;
	if (old_stash[i] == '\0')
	{
		free(old_stash);
		return (NULL);
	}
	i += (old_stash[i] == '\n');
	new_stash = (char *)malloc(ft_strlen(old_stash) - i + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while (old_stash[i + j])
	{
		new_stash[j] = old_stash[i + j];
		j++;
	}
	new_stash[j] = '\0';
	free(old_stash);
	return (new_stash);
}
