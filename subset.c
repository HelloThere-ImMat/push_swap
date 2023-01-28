/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:40:00 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 14:35:34 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_subset(t_subset *sub, t_pile *a, t_pile *b)
{
	t_pile	*sorted;
	t_pile	*a_tmp;

	a_tmp = copy_tab(a);
	sorted = copy_tab(b);
	ugly_sorting(a_tmp, sorted);
	if (a->nbr_count <= 100)
		find_subset(sub, *sorted);
	else
		find_big_subset(sub, *sorted);
	free_pile(a_tmp);
	free_pile(sorted);
	return (0);
}

void	find_subset(t_subset *sub, t_pile sorted)
{
	int	a_top;

	a_top = (sorted.nbr_count) - 1;
	sub->max = sorted.tab[0];
	sub->min = sorted.tab[a_top];
	sub->median = sorted.tab[a_top / 2];
	sub->q3 = sorted.tab[a_top / 4];
	sub->q1 = sorted.tab[3 * a_top / 4];
}

void	find_big_subset(t_subset *sub, t_pile sorted)
{
	int	a_top;
	int	chunk_amount;

	a_top = (sorted.nbr_count) - 1;
	chunk_amount = a_top / 10;
	sub->max = sorted.tab[0];
	sub->min = sorted.tab[a_top];
	sub->s9 = sorted.tab[chunk_amount];
	sub->s8 = sorted.tab[chunk_amount * 2];
	sub->s7 = sorted.tab[chunk_amount * 3];
	sub->s6 = sorted.tab[chunk_amount * 4];
	sub->s5 = sorted.tab[chunk_amount * 5];
	sub->s4 = sorted.tab[chunk_amount * 6];
	sub->s3 = sorted.tab[chunk_amount * 7];
	sub->s2 = sorted.tab[chunk_amount * 8];
	sub->s1 = sorted.tab[chunk_amount * 9];
}
