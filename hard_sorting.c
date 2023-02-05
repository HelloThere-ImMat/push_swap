/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:41:10 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/03 00:03:51 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_count2(t_pile *src, t_pile *dest, int top_src, int top_dest)
{
	int	i;
	int	counter;

	i = 0;
	while (src->tab[top_src] > dest->tab[top_dest]
		|| src->tab[top_src] < dest->tab[0])
	{
		rotate(dest, 0);
		i++;
	}
	counter = i;
	while (i > 0)
	{
		reverse_rotate(dest, 0);
		i--;
	}
	return (counter);
}

int	reverse_rotate_count2(t_pile *src, t_pile *dest, int top_src, int top_dest)
{
	int	i;
	int	counter;

	i = 0;
	while (src->tab[top_src] > dest->tab[top_dest]
		|| src->tab[top_src] < dest->tab[0])
	{
		reverse_rotate(dest, 0);
		i++;
	}
	counter = i;
	while (i > 0)
	{
		rotate(dest, 0);
		i--;
	}
	return (counter);
}

int	r_or_rr2(t_pile *src, t_pile *dest, int top_src, int top_dest)
{
	int	counter_1;
	int	counter_2;

	counter_1 = rotate_count2(src, dest, top_src, top_dest);
	counter_2 = reverse_rotate_count2(src, dest, top_src, top_dest);
	if (counter_2 >= counter_1)
		return (0);
	else
		return (1);
}

int	is_in_quartile(int nbr, int under, int over)
{
	if (nbr >= under && nbr < over)
		return (1);
	else
		return (0);
}

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
	// printf("Apres avoir bouger la premiere moitie vers b\n");
	// print_tab(*a);
	// print_tab(*b);
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
	// printf("Apres avoir bouger la seconde moitie vers b\n");
	// print_tab(*a);
	// print_tab(*b);
}

void	add_to_a2(t_pile *a, t_pile *b)
{
	int	top_b;
	int	top_a;

	top_b = (b->nbr_count) - 1;
	top_a = (a->nbr_count) - 1;
	if (a->nbr_count == 0)
		push(b, a, 1);
	else
	{
		if (r_or_rr2(b, a, top_b, top_a) == 1)
		{
			while (b->tab[top_b] > a->tab[top_a] || b->tab[top_b] < a->tab[0])
				rotate(a, 1);
		}
		else
		{
			while (b->tab[top_b] > a->tab[top_a] || b->tab[top_b] < a->tab[0])
				reverse_rotate(a, 1);
		}
		push(b, a, 1);
	}
}

void	print_sub(t_subset sub)
{
	printf("min :%d, q1 : %d, median : %d, q3 :%d, max :%d\n",
		sub.min, sub.q1, sub.median, sub.q3, sub.max);
}

void	big_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	// printf("Bonjour\n");
	// print_tab(*a);
	// print_tab(*b);
	get_quartiles_to_b(a, b, sub);
	sort_trio(a);
	// printf("bla\n");
	// print_sub(sub);
	while (quartile_is_in_pile(sub.q3, sub.max, *b))
		add_to_a2(a, b);
	// printf("apres avoir rajouter MAX sur A\n");
	// print_tab(*a);
	// print_tab(*b);
	while (quartile_is_in_pile(sub.median, sub.q3, *b))
	{
		reverse_rotate(b, 1);
		add_to_a2(a, b);
	}
	//printf("apres avoir rajouter Q3 sur A\n");
	while (quartile_is_in_pile(sub.q1, sub.median, *b))
		add_to_a2(a, b);
	//printf("apres avoir rajouter MED sur A\n");
	while (quartile_is_in_pile(sub.min, sub.q1, *b) && b->nbr_count > 0)
		add_to_a2(a, b);
	//printf("apres avoir rajouter Q1 sur A\n");
	get_min_to_top(sub.min, a);

}

// void	big_sorting(t_subset sub, t_pile *a, t_pile *b)
// {
// 	while (quartile_is_in_pile(sub.min, sub.q1, *a) == 1)
// 		sort_quartile(sub.min, sub.q1, a, b);
// 	while (quartile_is_in_pile(sub.q1, sub.median, *a) == 1)
// 		sort_quartile(sub.q1, sub.median, a, b);
// 	while (quartile_is_in_pile(sub.median, sub.q3, *a) == 1)
// 		sort_quartile(sub.median, sub.q3, a, b);
// 	while (quartile_is_in_pile(sub.q3, sub.max, *a) == 1 || a->nbr_count != 0)
// 		sort_quartile(sub.q3, sub.max, a, b);
// 	while (b->nbr_count > 0)
// 		push(b, a, 1);
// 	get_min_to_top(sub.min, a);
// }

void	sort_quartile(int under, int over, t_pile *a, t_pile *b)
{
	get_quartile_to_top(under, over, a);
	add_to_b(a, b);
}

void	mega_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	while (quartile_is_in_pile(sub.min, sub.s1, *a) == 1)
		sort_quartile(sub.min, sub.s1, a, b);
	while (quartile_is_in_pile(sub.s1, sub.s2, *a) == 1)
		sort_quartile(sub.s1, sub.s2, a, b);
	while (quartile_is_in_pile(sub.s2, sub.s3, *a) == 1)
		sort_quartile(sub.s2, sub.s3, a, b);
	while (quartile_is_in_pile(sub.s3, sub.s4, *a) == 1)
		sort_quartile(sub.s3, sub.s4, a, b);
	while (quartile_is_in_pile(sub.s4, sub.s5, *a) == 1)
		sort_quartile(sub.s4, sub.s5, a, b);
	while (quartile_is_in_pile(sub.s5, sub.s6, *a) == 1)
		sort_quartile(sub.s5, sub.s6, a, b);
	while (quartile_is_in_pile(sub.s6, sub.s7, *a) == 1)
		sort_quartile(sub.s6, sub.s7, a, b);
	while (quartile_is_in_pile(sub.s7, sub.s8, *a) == 1)
		sort_quartile(sub.s7, sub.s8, a, b);
	while (quartile_is_in_pile(sub.s8, sub.s9, *a) == 1)
		sort_quartile(sub.s8, sub.s9, a, b);
	while (quartile_is_in_pile(sub.s9, sub.max, *a) == 1 || a->nbr_count != 0)
		sort_quartile(sub.s9, sub.max, a, b);
	while (b->nbr_count > 0)
		push(b, a, 1);
	get_min_to_top(sub.min, a);
}

