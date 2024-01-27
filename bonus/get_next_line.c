/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:31 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:31:33 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

char	*ft_tmp(char *tmp, char *buffer)
{
	tmp = buffer;
	if (!tmp)
	{
		tmp = malloc(sizeof(char) * 1);
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	return (tmp);
}

char	*ft_read(int fd, char *buffer)
{
	char	*buftmp;
	char	*tmp;
	int		bytes_count;

	tmp = NULL;
	buftmp = malloc(10 + 1 * sizeof(char));
	if (!buftmp)
		return (NULL);
	bytes_count = 1;
	while (bytes_count > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_count = read(fd, buftmp, 10);
		if (bytes_count == -1 || (bytes_count == 0 && ft_strlen(buffer) < 1))
			return (free(buftmp), NULL);
		buftmp[bytes_count] = '\0';
		tmp = ft_tmp(tmp, buffer);
		if (!tmp)
			return (NULL);
		buffer = ft_strjoin(tmp, buftmp);
		if (!buffer)
			return (free(buftmp), NULL);
	}
	return (free(buftmp), buffer);
}

char	*ft_line(char *buffer)
{
	char	*res;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i ++;
	res = malloc((i + ft_strchr(buffer, '\n') + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		res[i] = buffer[i];
		i ++;
	}
	if (buffer[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_next(char *buffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i] || !buffer[i + 1])
		return (free(buffer), NULL);
	res = malloc((ft_strlen(buffer) - i) * sizeof(*res));
	if (!res)
		return (NULL);
	i++;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	return (free(buffer), res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
