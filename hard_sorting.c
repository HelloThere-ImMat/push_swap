/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:41:10 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/05 14:30:50 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_quartiles_to_b(t_pile *a, t_pile *b, t_subset sub)
{
	while (quartile_is_in_pile(sub.min + 1, sub.median, *a))
	{
		get_quartile_to_top(sub.min + 1, sub.median, a);
		if (is_in_quartile(a->tab[a->nbr_count - 1], sub.min, sub.q1))
		{
			push(a, b, 1);
			rotate(b, 1);
		}
		else if (is_in_quartile(a->tab[a->nbr_count - 1],
				sub.q1, sub.median))
			push(a, b, 1);
	}
	while (quartile_is_in_pile(sub.median, sub.max, *a) && a->nbr_count > 3)
	{
		get_quartile_to_top(sub.median, sub.max, a);
		if (is_in_quartile(a->tab[a->nbr_count - 1], sub.median, sub.q3))
		{
			push(a, b, 1);
			rotate(b, 1);
		}
		else if (is_in_quartile(a->tab[a->nbr_count - 1], sub.q3, sub.max))
			push(a, b, 1);
	}
}

void	get_big_quartiles_to_b(t_pile *a, t_pile *b, t_subset sub)
{
	get_first_half_to_b(a, b, sub);
	get_second_half_to_b(a, b, sub);
}

void	big_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	get_quartiles_to_b(a, b, sub);
	sort_trio(a);
	while (quartile_is_in_pile(sub.q3, sub.max, *b))
		add_to_a2(a, b);
	while (quartile_is_in_pile(sub.median, sub.q3, *b))
	{
		reverse_rotate(b, 1);
		add_to_a2(a, b);
	}
	while (quartile_is_in_pile(sub.q1, sub.median, *b))
		add_to_a2(a, b);
	while (quartile_is_in_pile(sub.min, sub.q1, *b) && b->nbr_count > 0)
		add_to_a2(a, b);
	get_min_to_top(sub.min, a);
}

void	mega_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	get_big_quartiles_to_b(a, b, sub);
	while (quartile_is_in_pile(sub.q3_5, sub.max, *b))
		add_to_a2(a, b);
	while (quartile_is_in_pile(sub.q3, sub.q3_5, *b))
	{
		reverse_rotate(b, 1);
		add_to_a2(a, b);
	}
	while (quartile_is_in_pile(sub.q2_5, sub.q3, *b))
		add_to_a2(a, b);
	while (quartile_is_in_pile(sub.median, sub.q2_5, *b))
	{
		reverse_rotate(b, 1);
		add_to_a2(a, b);
	}
	finish_big_sorting(a, b, sub);
	get_min_to_top(sub.min, a);
}

//printf("sub is :\n min : %d\n q0.5 : %d\n q1 : %d\n q1.5 : %d\n
//		med : %d\n q2.5 : %d\n q3 : %d\n q3.5 : %d\n
//	 	max : %d\n", sub.min, sub.q0_5, sub.q1, sub.q1_5, sub.median,
//		sub.q2_5, sub.q3, sub.q3_5, sub.max);