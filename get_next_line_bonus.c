/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:55:44 by tblaase           #+#    #+#             */
/*   Updated: 2021/08/27 17:31:26 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nelem, size_t elsize)
/* used to malloc buff, because might be uninit otherwise */
{
	char			*ptr;
	unsigned int	i;
	size_t			x;

	i = 0;
	x = nelem * elsize;
	ptr = (char *)malloc(x);
	if (ptr == NULL)
		return (0);
	while (i < x)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_update_nl(char **next_line, int position)
/* updates next_line to the not returned remainder */
{
	char	*tmp;
	int		len;

	len = ft_strlen(*next_line) - position;
	tmp = ft_strndup(*next_line + position, len);
	ft_free(&*next_line);
	*next_line = tmp;
	return (*next_line);
}

char	*ft_output(char **next_line, int position, int bytes)
/* gives the correct output if \n is found or EOF is reached */
{
	char	*line;

	if (((bytes == 0 || bytes == -1) && !*next_line) || position == -5)
	{
		if (*next_line)
			return (*next_line);
		return (NULL);
	}
	line = NULL;
	if (position == -1)
		position = ft_strlen(*next_line);
	else
		position++;
	line = ft_strndup(*next_line, position);
	if (position == ft_strlen(*next_line))
		ft_free(&*next_line);
	else
		*next_line = ft_update_nl(&*next_line, position);
	return (line);
}

char	*get_next_line(int fd)
/*
** reads into buff and hands the whole buff to next_line
** the *next_line[10240] instead of the *next_line enables me to run my code
** with different filedescriptors without loosing any data
** each time i use next_line in this function i use next_line[fd] insead
** the other functions work exactly the same for bonus and not-bonus part
*/
{
	static char	*next_line[10240];
	char		*buff;
	int			position;
	int			bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
		return (NULL);
	buff = NULL;
	position = ft_strchr(next_line[fd], '\n', 0);
	while (position == -1 && position != -5)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, 1);
		if (buff == NULL)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
			break ;
		next_line[fd] = ft_strnjoin(next_line[fd], buff, bytes);
		position = ft_strchr(next_line[fd], '\n', 1);
		ft_free(&buff);
	}
	ft_free(&buff);
	return (ft_output(&next_line[fd], position, bytes));
}
