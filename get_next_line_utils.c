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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	if ((*s1 - *s2)== -128)
		return (1);
	return (*s1 - *s2);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	ptr_size;

	ptr_size = (int)(nmemb * size);
	if (size != 0 && nmemb != (ptr_size / size))
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	while (ptr_size--)
		alloc[ptr_size] = 0;
	return (alloc);
}