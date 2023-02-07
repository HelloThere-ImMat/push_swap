/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:19:05 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/05 15:20:00 by mdorr            ###   ########.fr       */
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
		if (r_or_rr2(b, a, top_b, top_a) == 0)
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
