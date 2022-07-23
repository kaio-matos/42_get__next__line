/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:56:44 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/07/20 19:39:11 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	countnl(const char *buffer, int bytes)
{
	int	i;

	i = 0;
	if (!buffer)
		return (i);
	while (i < bytes && buffer[i] && buffer[i] != '\n')
		i++;
	if (i < bytes && buffer[i] == '\n')
		i++;
	return (i);
}

int	concatenate(char **s, const char *rest)
{
	int		rest_until_nl;

	if (!(*rest))
		return (-1);
	rest_until_nl = countnl(rest, ft_strlen(rest));
	*s = ft_strljoin(*s, rest, ft_strlen(*s) + rest_until_nl);
	if (!(*s))
		return (-1);
	return (rest_until_nl);
}

int	deal_with_rest(char **rest, int new_stored)
{
	char	*tmp;

	if (!(*rest) || new_stored == -1)
		return (-1);
	if (new_stored < (int)ft_strlen(*rest))
	{
		tmp = *rest;
		*rest += new_stored;
		*rest = ft_strdup(*rest);
		if (!(*rest))
			return (-1);
		free(tmp);
		return (0);
	}
	free(*rest);
	*rest = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*str;
	int			bytes;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	str = NULL;
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0 || ft_strlen(rest))
	{
		buffer[bytes] = '\0';
		rest = ft_strljoin(rest, buffer, ft_strlen(rest) + bytes);
		if (deal_with_rest(&rest, concatenate(&str, rest)) == -1)
			return (NULL);
		if (ft_strchr(str, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (str);
}
