/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:48:58 by amirfatt          #+#    #+#             */
/*   Updated: 2023/06/09 14:53:08 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_line_before_n(char *stash);
char	*read_into_new_stash(char *old_stash);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *buff, char *stash);
char	*ft_strchr(const char *s, int c);
void	handle_error(char **line, char **stash);
void	handle_empty(char **stash);

#endif
