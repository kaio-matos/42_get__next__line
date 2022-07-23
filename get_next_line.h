/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:56:40 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/07/20 19:11:43 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strljoin(char *s1, char const *s2, int bytes);
char	*ft_strchr(const char *s, int c);

/**
 * @brief Write a function that returns a line read from a
 *		file descriptor
 * External funcs -> read, malloc, free
 * 
 * @param int The file descriptor to read from
 * @return Read line: correct behavior
 *      NULL: there is nothing else to read, or an error
 *      occurred
 */
char	*get_next_line(int fd);
#endif
