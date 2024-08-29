/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:17:59 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/29 20:39:36 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	p;

	i = 0;
	p = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == p)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strndup(char *s, int len)
{
	char	*dup;
	int		i;

	if (s == NULL)
		return (NULL);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*big;
	int		i;
	int		len;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	i = -1;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	big = (char *)malloc((len + 1) * sizeof(char));
	if (!big)
		return (NULL);
	while (s1[++i])
		big[i] = s1[i];
	while (s2[j])
		big[i++] = s2[j++];
	big[i] = '\0';
	free (s1);
	return (big);
}

int	ft_strlenn(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
