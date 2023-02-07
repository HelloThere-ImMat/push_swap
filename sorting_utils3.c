/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:10:09 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/05 14:27:30 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_quartile(int nbr, int under, int over)
{
	if (nbr >= under && nbr < over)
		return (1);
	else
		return (0);
}

void	get_first_half_to_b(t_pile *a, t_pile *b, t_subset sub)
{
	while (quartile_is_in_pile(sub.min + 1, sub.q1, *a))
	{
		get_quartile_to_top(sub.min + 1, sub.q1, a);
		if (is_in_quartile(a->tab[a->nbr_count - 1], sub.min, sub.q0_5))
		{
			push(a, b, 1);
			rotate(b, 1);
		}
		else if (is_in_quartile(a->tab[a->nbr_count - 1], sub.q0_5, sub.q1))
			push(a, b, 1);
	}
	while (quartile_is_in_pile(sub.q1, sub.median, *a))
	{
		get_quartile_to_top(sub.q1, sub.median, a);
		if (is_in_quartile(a->tab[a->nbr_count - 1], sub.q1, sub.q1_5))
		{
			push(a, b, 1);
			rotate(b, 1);
		}
		else if (is_in_quartile(a->tab[a->nbr_count - 1], sub.q1_5, sub.median))
			push(a, b, 1);
	}
}

void	get_second_half_to_b(t_pile *a, t_pile *b, t_subset sub)
{
	while (quartile_is_in_pile(sub.median, sub.q3, *a))
	{
		get_quartile_to_top(sub.median, sub.q3, a);
		if (is_in_quartile(a->tab[a->nbr_count - 1], sub.median, sub.q2_5))
		{
			push(a, b, 1);
			rotate(b, 1);
		}
		else if (is_in_quartile(a->tab[a->nbr_count - 1], sub.q2_5, sub.q3))
			push(a, b, 1);
	}
	while (quartile_is_in_pile(sub.q3, sub.max, *a))
	{
		get_quartile_to_top(sub.q3, sub.max, a);
		if (is_in_quartile(a->tab[a->nbr_count - 1], sub.q3, sub.q3_5))
		{
			push(a, b, 1);
			rotate(b, 1);
		}
		else if (is_in_quartile(a->tab[a->nbr_count - 1], sub.q3_5, sub.max))
			push(a, b, 1);
	}
}

void	finish_big_sorting(t_pile *a, t_pile *b, t_subset sub)
{
	while (quartile_is_in_pile(sub.q1_5, sub.median, *b))
		add_to_a2(a, b);
	while (quartile_is_in_pile(sub.q1, sub.q1_5, *b))
	{
		reverse_rotate(b, 1);
		add_to_a2(a, b);
	}
	while (quartile_is_in_pile(sub.q0_5, sub.q1, *b))
		add_to_a2(a, b);
	while (quartile_is_in_pile(sub.min, sub.q0_5, *b) && b->nbr_count > 0)
		add_to_a2(a, b);
}
