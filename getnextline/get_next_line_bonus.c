/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:17:47 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/29 20:43:41 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include "get_next_line.h"

char	*ft_free(char *stash, char *buff)
{
	free(stash);
	free(buff);
	return (NULL);
}

char	*ft_reader(int fd, char *stash)
{
	int		lidos;
	char	*buff;

	lidos = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	*buff = 0;
	while (lidos != 0)
	{
		lidos = read(fd, buff, BUFFER_SIZE);
		if (lidos < 0)
			return (ft_free(stash, buff));
		buff[lidos] = '\0';
		stash = ft_strjoin(stash, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (*stash == '\0' || lidos == -1)
		return (ft_free(stash, buff));
	free(buff);
	return (stash);
}

char	*ft_parser(char *stash)
{
	char	*resto;
	int		lens;
	int		lenl;

	lens = ft_strlen(stash);
	lenl = ft_strlenn(stash, '\n');
	resto = ft_strndup(stash + lenl + 1, lens - lenl);
	free (stash);
	if (!resto)
		return (NULL);
	return (resto);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPENFD_MAX];
	char		*linha;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_reader(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	linha = ft_strndup(stash[fd], ft_strlenn(stash[fd], '\n') + 1);
	if (!linha)
		return (NULL);
	stash[fd] = ft_parser(stash[fd]);
	return (linha);
}
