/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:40:31 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/28 16:34:12 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_nb(char *string, int len, int n)
{
	len = len - 1;
	if (n < 0)
	{
		n = -n;
		len--;
	}
	while (n > 0)
	{
		string[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*string;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (string);
	if (n < 0)
	{
		string[0] = '-';
		n = -n;
	}
	if (n == 0)
		string[0] = '0';
	else
		string = ft_nb(string, len, n);
	string[len] = '\0';
	return (string);
}

char	*ft_strdup(const char *src)
{
	int			i;
	int			j;
	char		*dest;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(*dest) * (i + 1));
	if (dest == NULL)
		return (0);
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
