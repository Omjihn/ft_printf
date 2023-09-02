/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:13 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/14 15:43:40 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_init(int fd);
char	*add_to_trash(char *trash, int fd, int i);
char	*output_res(char *trash, int end);
char	*trim_trash(char *trash, int i);
char	*ft_is_no_nl(char *trash, int i);
void	*ft_callocc(size_t nmemb, size_t size);

#endif
