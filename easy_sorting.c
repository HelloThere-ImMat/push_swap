/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:33:55 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/24 13:59:40 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_trio(t_pile *a)
{
	if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2] && a->tab[2] < a->tab[0])
		return ;
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] && a->tab[2] < a->tab[0])
		swap_a(a, 1);
	else if (a->tab[0] < a->tab[1] && a->tab[1] < a->tab[2] &&  a->tab[2] > a->tab[0])
	{
		swap_a(a, 1);
		reverse_rotate(a, 1);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] && a->tab[2] > a->tab[0])
		rotate(a, 1);
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] && a->tab[2] < a->tab[0])
	{
		swap_a(a, 1);
		rotate(a, 1);
	}
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] && a->tab[2] > a->tab[0])
		reverse_rotate(a, 1);
	return;
}

void small_sorting(int arg_nbr, t_pile *a)
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

void add_to_a(t_pile *a, t_pile *b, int *counter)
{
	t_pile full_pile;
	int top_b;

	full_pile = copy_tab(*a);
	top_b = (b->nbr_count) - 1;
	if (is_max(b->tab[top_b], full_pile) == 1)
		(*counter)++;
	else if (is_min(b->tab[top_b], full_pile) == 0 && is_max(b->tab[top_b], full_pile) == 0)
	{
		(*counter)++;
		while (b->tab[top_b] < a->tab[0])
		{
			reverse_rotate(a, 1);
			(*counter)++;
		}
	}
	push(b, a, 1);
}

void medium_sorting(int arg_nbr, t_pile *a, t_pile *b)
{
	int	counter;

	counter = 0;
	push(a, b, 1);
	if (arg_nbr == 5)
		push(a, b, 1);
	sort_trio(a);
	add_to_a(a, b, &counter);
	while (counter-- > 0)
		rotate(a, 1);
	counter = 0;
	if (arg_nbr == 5)
		add_to_a(a, b, &counter);
	while (counter-- > 0)
		rotate(a, 1);
	return ;
}

void ugly_sorting(t_pile *a, t_pile *sorted)
{
	while (a->nbr_count > 0)
	{
		while (is_min(a->tab[(a->nbr_count) - 1], *a) == 0)
			rotate(a, 0);
		push(a, sorted, 0);
	}
	while (sorted->nbr_count > 0)
		push(sorted, a, 0);
	return ;
}
