/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boufrouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:24:11 by boufrouk          #+#    #+#             */
/*   Updated: 2023/02/17 23:24:22 by boufrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*readili(int fd, char *tmp)
{
	int		i;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(tmp, '\n') && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || (tmp[0] == 0 && i == 0))
		{
			free(buf);
			free(tmp);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_thisline(char *t)
{
	int		n;
	char	*line;

	n = 0;
	if (!t)
		return (NULL);
	while (t[n] && t[n] != '\n')
		n++;
	if (t[n] == '\0')
		line = (char *)malloc(n + 1);
	else
		line = (char *)malloc(n + 2);
	if (!line)
		return (NULL);
	n = 0;
	while (t[n] && t[n] != '\n')
	{
		line[n] = t[n];
		n++;
	}
	if (t[n] == '\n')
		line[n++] = '\n';
	line[n] = '\0';
	return (line);
}

char	*rest(char *tmp)
{
	char	*rst;
	int		k;
	int		i;

	k = 0;
	while (tmp[k] && tmp[k] != '\n')
		k++;
	if (!tmp[k])
	{
		free(tmp);
		return (NULL);
	}
	k++;
	i = ft_strlen(&tmp[k]);
	rst = malloc(i + 1);
	if (!rst)
		return (NULL);
	i = 0;
	while (tmp[k])
		rst[i++] = tmp[k++];
	rst[i] = '\0';
	free(tmp);
	return (rst);
}

char	*get_next_line(int fd)
{
	char		*ln;
	static char	*tp;

	if (fd == -1)
		return (NULL);
	if (!tp)
		tp = ft_strdup("");
	tp = readili(fd, tp);
	if (!tp)
		return (NULL);
	ln = get_thisline(tp);
	tp = rest(tp);
	return (ln);
}

int main(){
	int fd ;
	fd = open("hH",O_RDONLY,777);
	//  while (get_next_line(fd))
	//  {
	 	printf("%s", get_next_line(fd));
		// printf("%s", get_next_line(fd));
		// printf("%s", get_next_line(fd));
		// printf("%s", get_next_line(fd));
		// printf("%s", get_next_line(fd));

		system("leaks a.out");
	return 0;
}
