/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:06:20 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/23 11:06:22 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

# include <unistd.h>
# include <stdlib.h>

typedef struct  int_l{
    int index;
    int switch_to_buf;
    int bfidx;
}               int_t;

char	*get_next_line(int fd);
void    *ft_calloc(size_t nmemb, size_t nbr);
int     ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);

#endif