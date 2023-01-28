/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:41:10 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 17:19:42 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	while (quartile_is_in_pile(sub.min, sub.q1, *a) == 1)
		sort_quartile(sub.min, sub.q1, a, b);
	while (quartile_is_in_pile(sub.q1, sub.median, *a) == 1)
		sort_quartile(sub.q1, sub.median, a, b);
	while (quartile_is_in_pile(sub.median, sub.q3, *a) == 1)
		sort_quartile(sub.median, sub.q3, a, b);
	while (quartile_is_in_pile(sub.q3, sub.max, *a) == 1 || a->nbr_count != 0)
		sort_quartile(sub.q3, sub.max, a, b);
	while (b->nbr_count > 0)
		push(b, a, 1);
	get_min_to_top(sub.min, a);
}

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

//void	print_sub(t_subset sub)
//{
//	printf("min :%d, q1 : %d, median : %d, q3 :%d, max :%d\n",
//		sub.min, sub.q1, sub.median, sub.q3, sub.max);
//}
