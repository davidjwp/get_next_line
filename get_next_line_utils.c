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







static char	*ft_word_cpy(char const *s, char c)
{
	char	*word_cpy;
	int		word_len;
	int		index;

	word_len = 0;
	while (s[word_len] != c && s[word_len])
		word_len++;
	/*word_cpy = ft_calloc(word_len, sizeof(char));
	*/index = 0;
	while (index < word_len)
	{
		word_cpy[index] = *s++;
		index++;
	}
	return (word_cpy);
}
/*
static int	ft_word_count(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			return (word_count);
		word_count++;
		while (*s != c && *s)
			s++;
	}
	return (word_count);
}
*/
char		**ft_split(char const *s, char c)
{
	char	**split;
	int		index;

	index = 0;
	/*split = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	*/while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			split[index] = ft_word_cpy(s, c);
	}
	return (split);
}