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

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

# define TO_BUF <= BUFFER_SIZE

typedef struct  int_l{
    int index;
    int switch_to_buf;
    int bfidx;
}               int_t;

char	*get_next_line(int fd);
int     ft_strlen(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

#endif