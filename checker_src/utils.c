/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:11:02 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 16:09:01 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (check_for_doubles(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
