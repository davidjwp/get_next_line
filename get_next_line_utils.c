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

void	*ft_calloc(size_t nmemb, size_t nbr)
{
	char 	*alloc;
	size_t	length;

	length = nmemb * nbr;
	if (!nbr != 0 && nmemb != length / nbr)
		return (NULL);
	alloc = malloc(nmemb * nbr);
	if (!alloc)
		return(NULL);
	while (length--)
		alloc[length] = 0;
	return (alloc);
}