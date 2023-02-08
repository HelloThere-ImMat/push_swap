/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:11:02 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/08 14:26:12 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_int(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == 45)
		i++;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
		{
			write(2, "Error", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_order(t_pile a)
{
	int	i;

	i = 0;
	while (i < a.nbr_count - 1)
	{
		if (a.tab[i] < a.tab[i + 1])
		{
			write(1, "KO\n", 3);
			return (0);
		}
		i++;
	}
	write(1, "OK\n", 3);
	return (1);
}

int	check_for_doubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (check_int(argv[i]) == 0)
			return (0);
		if (ft_atoi(argv[i]) < INTMIN || ft_atoi(argv[i]) > INTMAX)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (check_for_doubles(argc, argv) == 0)
		return (0);
	return (1);
}

t_list	*ft_lstnew(char *command)
{
	t_list	*new;
	int		len;

	len = ft_strlen(command);
	new = (t_list *)malloc(sizeof(t_list));
	new->content = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new->content, command);
	new->next = NULL;
	return (new);
}
