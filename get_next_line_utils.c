/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:30:47 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/23 19:30:49 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

static int check_buf(char *buf)
{
	int	index;

	index = 0;
	if (!buf)
		return (0);
	while (buf[index] != '\n')
		index++;
	if (index)
		return (1);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)ft_calloc(size + 1, sizeof(char));
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	join -= size;
	return (join);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	ptr_size;

	ptr_size = (int)(nmemb * size);
	if (size != 0 && nmemb != (ptr_size / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		reurn (NULL);
	while (ptr_size--)
		ptr[ptr_size] = 0;
	return (ptr);
}