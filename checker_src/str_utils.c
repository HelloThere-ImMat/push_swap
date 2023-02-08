/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:11:00 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/08 14:13:19 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long	ft_atoi(const char *nptr)
{
	int			a;
	long long	res;
	int			sign;

	a = 0;
	sign = 1;
	res = 0;
	while (nptr[a] != '\0')
	{
		while ((nptr[a] > 8 && nptr[a] < 14) || nptr[a] == 32)
			a++;
		if (nptr[a] == '-' || nptr[a] == '+')
		{
			if (nptr[a] == 45)
				sign = sign * -1;
			a++;
		}
		while (nptr[a] >= 48 && nptr[a] <= 57)
		{
			res = res * 10 + nptr[a] - '0';
			a++;
		}
		return (res * sign);
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	r;

	r = 0;
	while (s1[r] != '\0' && s2[r] != '\0' && r < n)
	{
		if (s1[r] != s2[r])
		{
			return ((unsigned char)s1[r] - (unsigned char)s2[r]);
		}
		r++;
	}
	if (r < n)
	{
		return ((unsigned char)s1[r] - (unsigned char)s2[r]);
	}
	else
	{
		return (0);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	e;

	e = 0;
	while (s1[e] != '\0' && s2[e] != '\0')
	{
		if (s1[e] != s2[e])
		{
			return (s1[e] - s2[e]);
		}
		e++;
	}
	return (s1[e] - s2[e]);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
