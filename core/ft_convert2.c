/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:15 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/17 18:34:27 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_gnl_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(const char *src, int n)
{
	int			j;
	char		*dest;

	j = 0;
	dest = (char *)malloc(sizeof(*dest) * (n + 1));
	if (dest == NULL)
		return (0);
	while (j < n)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strlen(char *s, int j)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	if (j == 1)
		c = '\n';
	while (s && s[i] && s[i] != c)
		i++;
	if (c == '\n' && s && s[i] && s[i] == '\n')
		i++;
	return (i);
}

char	*test(char *s1, char *dest)
{
	free(s1);
	if (dest)
	{
		if (dest[0] == '\0')
		{
			free(dest);
			dest = NULL;
		}
	}
	return (dest);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		t;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ((ft_strlen(s1, 1) + ft_strlen(s2, 0)) + 1));
	if (dest)
	{
		while (s1 && s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		t = 0;
		while (s2 && s2[t] && s2[t] != '\n')
		{
			dest[i + t] = s2[t];
			t++;
		}
		dest[i + t] = '\n';
		if (s2 && s2[t] && s2[t] == '\n')
			t++;
		dest[i + t] = '\0';
	}
	return (test(s1, dest));
}
