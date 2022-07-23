/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:56:46 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/06/29 23:34:38 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_strljoin(char *s1, char const *s2, int bytes)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * bytes + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1 && (bytes - i))
	{
		new_str[i] = *s1;
		i++;
		s1++;
	}
	free(s1 - i);
	while (s2 != NULL && *s2 && (bytes - i))
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
		c %= 256;
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
