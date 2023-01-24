/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:41:10 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/24 18:18:59 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	r_or_rr(t_pile *a, t_pile *b, int top_a, int top_b)
{
	int i;
	int counter_1;
	int counter_2;

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
	int top_b;
	int top_a;
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

void get_min_to_top(int min, t_pile *pile)
{
	int i;
	int i2;

	i = 0;
	i2 = pile->nbr_count -1;
	while (pile->tab[i] != min)
		i++;
	while (pile->tab[i2] != min)
		i2--;
	if (i + 1 < pile->nbr_count - 1 - i2)
	{
		while (pile->tab[(pile->nbr_count) -1] != min)
			reverse_rotate(pile, 1);
	}
	else
	{
		while (pile->tab[(pile->nbr_count) -1] != min)
			rotate(pile, 1);
	}
}

void get_min_to_bottom(int min, t_pile *pile)
{
	int i;
	int i2;

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

void get_quartile_to_top(int quartile_under, int quartile_over, t_pile *a)
{
		int	i;
		int i2;
		int	tmp;

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

void print_sub(t_subset sub)
{
	printf("min :%d, q1 : %d, median : %d, q3 :%d, max :%d\n", sub.min, sub.q1, sub.median, sub.q3, sub.max);
}

void big_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	print_sub(sub);
	//printf("FIRST QUARTILE \n");
	while (quartile_is_in_pile(sub.min, sub.q1, *a) == 1)
	{
		get_quartile_to_top(sub.min, sub.q1, a);
		add_to_b(a, b);
	}
	//printf("SECOND QUARTILE \n");
	while (quartile_is_in_pile(sub.q1, sub.median, *a) == 1)
	{
		get_quartile_to_top(sub.q1, sub.median, a);
		add_to_b(a, b);
	}
	//printf("THIRD QUARTILE \n");
	while (quartile_is_in_pile(sub.median, sub.q3, *a) == 1)
	{
		get_quartile_to_top(sub.median, sub.q3, a);
		add_to_b(a, b);
	}
	//printf("FOURTH QUARTILE \n");
	while (quartile_is_in_pile(sub.q3, sub.max, *a) == 1 || a->nbr_count != 0)
	{
		get_quartile_to_top(sub.q3, sub.max + 1, a);
		add_to_b(a, b);
	}
	while (b->nbr_count > 0)
		push(b, a, 1);
	get_min_to_top(sub.min, a);
}

void	mega_sorting(t_subset sub, t_pile *a, t_pile *b)
{
	//printf("min : %d\n1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n7: %d\n8: %d\n9: %d\nmax : %d\n", sub.min, sub.s1, sub.s2, sub.s3, sub.s4, sub.s5, sub.s6, sub.s7, sub.s8, sub.s9, sub.max);
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
	while (quartile_is_in_pile(sub.s9, sub.max, *a) == 1)
	{
		get_quartile_to_top(sub.s9, sub.max, a);
		add_to_b(a, b);
	}
	while (b->nbr_count > 0)
		push(b, a, 1);
	get_min_to_top(sub.min, a);
}
