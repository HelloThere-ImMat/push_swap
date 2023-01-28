/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:38:31 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 14:45:29 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_quartile_to_top(int quartile_under, int quartile_over, t_pile *a)
{
	int	i;
	int	i2;
	int	tmp;

	if (a->nbr_count == 1)
		return ;
	i = 0;
	i2 = a->nbr_count - 1;
	while (a->tab[i] < quartile_under || a->tab[i] >= quartile_over)
		i++;
	while (a->tab[i2] < quartile_under || a->tab[i2] >= quartile_over)
		i2--;
	if (i + 1 < a->nbr_count - 1 - i2)
	{
		tmp = a->tab[i];
		while (a->tab[(a->nbr_count) - 1] != tmp)
			reverse_rotate(a, 1);
	}
	else
	{
		tmp = a->tab[i2];
		while (a->tab[(a->nbr_count) - 1] != tmp)
			rotate(a, 1);
	}
}

void	get_min_to_bottom(int min, t_pile *pile)
{
	int	i;
	int	i2;

	i = 0;
	i2 = pile->nbr_count -1;
	if (pile->nbr_count == 0)
		return ;
	while (pile->tab[i] != min)
		i++;
	while (pile->tab[i2] != min)
		i2--;
	if (i + 1 < pile->nbr_count - 1 - i2)
	{
		while (pile->tab[0] != min)
			reverse_rotate(pile, 1);
	}
	else
	{
		while (pile->tab[0] != min)
			rotate(pile, 1);
	}
}

void	get_min_to_top(int min, t_pile *pile)
{
	int	i;
	int	i2;

	i = 0;
	i2 = pile->nbr_count -1;
	while (pile->tab[i] != min)
		i++;
	while (pile->tab[i2] != min)
		i2--;
	if (i + 1 < pile->nbr_count - 1 - i2)
	{
		while (pile->tab[(pile->nbr_count) - 1] != min)
			reverse_rotate(pile, 1);
	}
	else
	{
		while (pile->tab[(pile->nbr_count) - 1] != min)
			rotate(pile, 1);
	}
}

int	is_max(int nb, t_pile pile)
{
	int	i;

	i = 0;
	while (i < pile.nbr_count)
	{
		if (pile.tab[i] > nb)
			return (0);
		i++;
	}
	return (1);
}

int	is_min(int nb, t_pile pile)
{
	int	i;

	i = 0;
	while (i < pile.nbr_count)
	{
		if (pile.tab[i] < nb)
			return (0);
		i++;
	}
	return (1);
}
