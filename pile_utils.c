/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:16:50 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/05 14:30:58 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*copy_tab(const t_pile *original)
{
	t_pile	*copy;
	int		i;

	i = 0;
	copy = (t_pile *)malloc(sizeof(t_pile));
	copy->nbr_count = original->nbr_count;
	copy->id = original->id;
	copy->tab = (int *) malloc(sizeof(int) * original->nbr_count);
	if (copy == NULL || copy->tab == NULL)
		return (NULL);
	while (i < original->nbr_count)
	{
		copy->tab[i] = original->tab[i];
		i++;
	}
	return (copy);
}

void	add_to_tab(int argc, char **argv, t_pile *a)
{
	int	i;
	int	i2;
	int	tmp;

	i = argc;
	i2 = 0;
	while (i > 0)
	{
		tmp = ft_atoi(argv[i - 1]);
		a->tab[i2] = tmp;
		i--;
		i2++;
	}
}

t_pile	*create_tab(int argc, char **argv, int a)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	new->tab = malloc(sizeof(int) * (argc - 1));
	if (a == 1)
	{
		new->nbr_count = argc -1;
		new->id = 1;
	}
	else
	{
		new->nbr_count = 0;
		new->id = 2;
	}
	if (new == NULL || new->tab == NULL)
		return (NULL);
	if (a == 1)
		add_to_tab(argc, argv, new);
	return (new);
}

int	quartile_is_in_pile(int quartile_under, int quartile_over, t_pile a)
{
	int	i;

	i = 0;
	while (i < a.nbr_count)
	{
		if (a.tab[i] >= quartile_under && a.tab[i] < quartile_over)
			return (1);
		else
			i++;
	}
	return (0);
}
