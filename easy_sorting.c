/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:33:55 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/08 13:36:48 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_trio(t_pile *a)
{
	if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2] && a->tab[2] < a->tab[0])
		return ;
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
		&& a->tab[2] < a->tab[0])
		swap_a(a, 1);
	else if (a->tab[0] < a->tab[1] && a->tab[1] < a->tab[2]
		&& a->tab[2] > a->tab[0])
	{
		swap_a(a, 1);
		reverse_rotate(a, 1);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
		&& a->tab[2] > a->tab[0])
		rotate(a, 1);
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
		&& a->tab[2] < a->tab[0])
	{
		swap_a(a, 1);
		rotate(a, 1);
	}
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
		&& a->tab[2] > a->tab[0])
		reverse_rotate(a, 1);
	return ;
}

void	small_sorting(int arg_nbr, t_pile *a)
{
	if (arg_nbr == 1)
		return ;
	if (arg_nbr == 2)
	{
		if (a->tab[0] < a->tab[1])
			swap_a(a, 1);
		return ;
	}
	if (arg_nbr == 3)
	{
		sort_trio(a);
		return ;
	}
}

void	add_to_a(t_pile *a, t_pile *b)
{
	int	top_b;
	int	top_a;

	top_b = (b->nbr_count) - 1;
	top_a = (a->nbr_count) - 1;
	if (is_max(b->tab[top_b], *a) == 1)
	{
		push(b, a, 1);
		rotate(a, 1);
		return ;
	}
	if (is_min(b->tab[top_b], *a) == 1)
	{
		push(b, a, 1);
		return ;
	}
	while (b->tab[top_b] > a->tab[top_a] || b->tab[top_b] < a->tab[0])
		rotate(a, 1);
	push(b, a, 1);
}

void	medium_sorting(int arg_nbr, t_pile *a, t_pile *b)
{
	int		min;

	push(a, b, 1);
	if (arg_nbr == 5)
		push(a, b, 1);
	sort_trio(a);
	while (b->nbr_count > 0)
		add_to_a(a, b);
	min = get_min(a);
	get_min_to_top(min, a);
	return ;
}

void	ugly_sorting(t_pile *a_tmp, t_pile *sorted)
{
	int	i;

	i = 0;
	while (a_tmp->nbr_count > 0)
	{
		while (is_max(a_tmp->tab[(a_tmp->nbr_count) - 1], *a_tmp) == 0)
			rotate(a_tmp, 0);
		push(a_tmp, sorted, 0);
		i++;
	}
	return ;
}
