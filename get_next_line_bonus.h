/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:56:53 by tblaase           #+#    #+#             */
/*   Updated: 2021/08/06 12:12:32 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

void	ft_free(char **p);
int		ft_strlen(char *s);
int		ft_strchr(char *s, int c, int flag);
char	*ft_strnjoin(char *s1, char *s2, int n);
char	*ft_strndup(char *str, int n);
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_update_nl(char **next_line, int position);
char	*ft_output(char **next_line, int position, int bytes);
char	*get_next_line(int fd);

#endif
