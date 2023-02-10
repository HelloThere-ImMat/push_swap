/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:11:02 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/10 16:21:55 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_for_doubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == 45 || arg[i] == 43)
		i++;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_int(argv[i]) == 0)
			return (0);
		if (ft_atoi(argv[i]) < INTMIN || ft_atoi(argv[i++]) > INTMAX)
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (check_for_doubles(argc, argv) == 0)
		return (0);
	return (1);
}
