/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:35:47 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/14 15:38:05 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_init(int fd)
{
	char	*trash;

	trash = (char *) ft_callocc(BUFFER_SIZE + 1, 1);
	if (!trash)
		return (trash);
	trash[BUFFER_SIZE] = '\0';
	if (read(fd, trash, BUFFER_SIZE) <= 0)
	{
		free (trash);
		return (0);
	}
	return (trash);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*trash[1024];
	char		*res;

	i = 0;
	if (!trash[fd])
		trash[fd] = ft_init(fd);
	while (trash[fd])
	{
		if (trash[fd][i] == '\n')
		{
			res = output_res(trash[fd], i);
			if (trash[fd])
				trash[fd] = trim_trash(trash[fd], i);
			return (res);
		}
		else if (trash[fd][i] == '\0')
			trash[fd] = add_to_trash(trash[fd], fd, i);
		else
			i++;
	}
	return (0);
}
