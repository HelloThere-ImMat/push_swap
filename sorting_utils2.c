/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:19:05 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/02 23:27:26 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_extreme_to_b(t_pile *a, t_pile *b, int is_mini)
{
	int	i;

	i = 0;
	if (is_mini == 1)
	{
		while (is_min(b->tab[i], *b) == 0)
			i++;
	}
	else
	{
		while (is_min(b->tab[i], *b) == 0)
			i++;
	}
	get_min_to_bottom(b->tab[i], b);
	push(a, b, 1);
	if (is_mini == 1)
		rotate(b, 1);
	return ;
}

void	add_to_b(t_pile *a, t_pile *b)
{
	int	top_b;
	int	top_a;
	int	i;

	top_b = (b->nbr_count) - 1;
	top_a = (a->nbr_count) - 1;
	if (is_max(a->tab[top_a], *b) == 1)
	{
		add_extreme_to_b(a, b, 0);
		return ;
	}
	else if (is_min(a->tab[top_a], *b) == 1)
	{
		add_extreme_to_b(a, b, 1);
		return ;
	}
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

int	rotate_count(t_pile *src, t_pile *dest, int top_src, int top_dest)
{
	int	i;
	int	counter;

	i = 0;
	while (src->tab[top_src] < dest->tab[top_dest]
		|| src->tab[top_src] > dest->tab[0])
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

int	reverse_rotate_count(t_pile *src, t_pile *dest, int top_src, int top_dest)
{
	int	i;
	int	counter;

	i = 0;
	while (src->tab[top_src] < dest->tab[top_dest]
		|| src->tab[top_src] > dest->tab[0])
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

int	r_or_rr(t_pile *src, t_pile *dest, int top_src, int top_dest)
{
	int	counter_1;
	int	counter_2;

	counter_1 = rotate_count(src, dest, top_src, top_dest);
	counter_2 = reverse_rotate_count(src, dest, top_src, top_dest);
	if (counter_2 >= counter_1)
		return (0);
	else
		return (1);
}
