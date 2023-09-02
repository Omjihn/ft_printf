/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:28 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/14 15:44:20 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_callocc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*cast;
	int		tmp_res;
	int		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tmp_res = nmemb * size;
	if (tmp_res / size != nmemb)
		return (NULL);
	ptr = malloc(tmp_res);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	cast = ptr;
	while (i < tmp_res)
	{
		cast[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_is_no_nl(char *trash, int i)
{
	int		j;
	char	*res;

	res = (char *) malloc (i + 2);
	if (!res)
		return (res);
	j = 0;
	while (trash[j])
	{
		res[j] = trash[j];
		j++;
	}
	res[j] = '\n';
	res[j + 1] = '\0';
	free (trash);
	return (res);
}

char	*add_to_trash(char *trash, int fd, int i)
{
	char	*new;
	int		j;

	new = (char *) ft_callocc(i + BUFFER_SIZE + 1, 1);
	if (!new)
	{
		free(trash);
		return (new);
	}
	if (read(fd, new + i, BUFFER_SIZE) == 0)
	{
		free (new);
		return (ft_is_no_nl(trash, i));
	}
	j = 0;
	while (trash[j])
	{
		new[j] = trash[j];
		j++;
	}
	free(trash);
	return (new);
}

char	*output_res(char *trash, int end)
{
	char	*res;
	int		i;

	res = (char *) malloc(end + 2);
	if (!res)
	{
		free(trash);
		return (0);
	}
	i = 0;
	while (i < end)
	{
		res[i] = trash[i];
		i++;
	}
	res[i] = '\n';
	i++;
	res[i] = '\0';
	return (res);
}

char	*trim_trash(char *trash, int i)
{
	char	*new_trash;
	int		j;

	if (trash[i + 1] == '\0')
	{
		free(trash);
		return (0);
	}
	j = i;
	while (trash[j])
		j++;
	new_trash = (char *) malloc((j - i) + 1);
	j = 0;
	i++;
	while (trash[i])
		new_trash[j++] = trash[i++];
	new_trash[j] = '\0';
	free(trash);
	return (new_trash);
}
