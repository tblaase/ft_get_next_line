/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:53:00 by tblaase           #+#    #+#             */
/*   Updated: 2021/08/27 17:24:33 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>

void	gnl(int fd)
{
	char	*s;

	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = NULL;
}

int	main(void)
/*
** this function will call your get_next_line a number of times
** feel free to put your own testcases into the test.txt
** this functon will keep track of the runtime of your code
** the runtime measurement is far from perfect and sometimes produces far to low numbers
** so no guaranty for correct time values
** run it multiple times to get a aproximate runtime
*/
{
	int	fd;
	struct timeval	start, end;

	fd = open("test.txt", O_RDONLY);
	gettimeofday(&start, NULL);
	/* invalid fd */
	// gnl(1000);
	// gnl(-1);
	/* decide how many lines get printed */
	/*1*/gnl(fd);
	/*2*/gnl(fd);
	/*3*/gnl(fd);
	/*4*/gnl(fd);
	/*5*/gnl(fd);
	/*6*/gnl(fd);
	/*7*/gnl(fd);
	/*8*/gnl(fd);
	/*9*/gnl(fd);
	/*10*/gnl(fd);
	// /*11*/gnl(fd);
	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	long microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	// printf("\033[0;32m");
	printf("\n\033[0;32mThis code took %ld,%ld seconds to run.\033[0m\n", (microseconds / 1000000), (microseconds % 1000000));
	// printf("\033[0m");
	// system("leaks a.out");
	return (0);
}
