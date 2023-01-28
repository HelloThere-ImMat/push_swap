/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:41:10 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 16:36:43 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_or_rr(t_pile *a, t_pile *b, int top_a, int top_b)
{
	int	i;
	int	counter_1;
	int	counter_2;

	i = 0;
	while (a->tab[top_a] < b->tab[top_b] || a->tab[top_a] > b->tab[0])
	{
		rotate(b, 0);
		i++;
	}
	counter_1 = i;
	while (i > 0)
	{
		reverse_rotate(b, 0);
		i--;
	}
	while (a->tab[top_a] < b->tab[top_b] || a->tab[top_a] > b->tab[0])
	{
		reverse_rotate(b, 0);
		i++;
	}
	counter_2 = i;
	while (i > 0)
	{
		rotate(b, 0);
		i--;
	}
	if (counter_2 >= counter_1)
		return (0);
	else
		return (1);
}

void add_to_b(t_pile *a, t_pile *b)
{
	int	top_b;
	int	top_a;
	int	i;

	top_b = (b->nbr_count) - 1;
	top_a = (a->nbr_count) - 1;
	i = 0;
	if (is_max(a->tab[top_a], *b) == 1)
	{
		while (is_min(b->tab[i], *b) == 0)
			i++;
		get_min_to_bottom(b->tab[i], b);
		push(a, b, 1);
		return ;
	}
	else if (is_min(a->tab[top_a], *b) == 1)
	{
		while (is_min(b->tab[i], *b) == 0)
			i++;
		get_min_to_bottom(b->tab[i], b);
		push(a, b, 1);
		rotate(b, 1);
		return ;
	}
	i = 0;
	i = r_or_rr(a, b, top_a, top_b);
	while (a->tab[top_a] < b->tab[top_b] || a->tab[top_a] > b->tab[0])
	{
		if (i == 0)
			rotate(b, 1);
		else
			reverse_rotate(b, 1);
	}
	push(a, b, 1);
}

void	print_sub(t_subset sub)
{
	printf("min :%d, q1 : %d, median : %d, q3 :%d, max :%d\n",
		sub.min, sub.q1, sub.median, sub.q3, sub.max);
}

void	big_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	while (quartile_is_in_pile(sub.min, sub.q1, *a) == 1)
	{
		get_quartile_to_top(sub.min, sub.q1, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.q1, sub.median, *a) == 1)
	{
		get_quartile_to_top(sub.q1, sub.median, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.median, sub.q3, *a) == 1)
	{
		get_quartile_to_top(sub.median, sub.q3, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.q3, sub.max, *a) == 1 || a->nbr_count != 0)
	{
		get_quartile_to_top(sub.q3, sub.max, a);
		add_to_b(a, b);
	}
	while (b->nbr_count > 0)
		push(b, a, 1);
	get_min_to_top(sub.min, a);
}

void	mega_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	while (quartile_is_in_pile(sub.min, sub.s1, *a) == 1)
	{
		get_quartile_to_top(sub.min, sub.s1, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s1, sub.s2, *a) == 1)
	{
		get_quartile_to_top(sub.s1, sub.s2, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s2, sub.s3, *a) == 1)
	{
		get_quartile_to_top(sub.s2, sub.s3, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s3, sub.s4, *a) == 1)
	{
		get_quartile_to_top(sub.s3, sub.s4, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s4, sub.s5, *a) == 1)
	{
		get_quartile_to_top(sub.s4, sub.s5, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s5, sub.s6, *a) == 1)
	{
		get_quartile_to_top(sub.s5, sub.s6, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s6, sub.s7, *a) == 1)
	{
		get_quartile_to_top(sub.s6, sub.s7, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s7, sub.s8, *a) == 1)
	{
		get_quartile_to_top(sub.s7, sub.s8, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s8, sub.s9, *a) == 1)
	{
		get_quartile_to_top(sub.s8, sub.s9, a);
		add_to_b(a, b);
	}
	while (quartile_is_in_pile(sub.s9, sub.max, *a) == 1 || a->nbr_count != 0)
	{
		get_quartile_to_top(sub.s9, sub.max, a);
		add_to_b(a, b);
	}
	while (b->nbr_count > 0)
		push(b, a, 1);
	get_min_to_top(sub.min, a);
}
