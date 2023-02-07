/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:40:00 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/07 15:14:25 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_subset(t_subset *sub, t_pile *a, t_pile *b)
{
	t_pile	*sorted;
	t_pile	*a_tmp;

	a_tmp = copy_tab(a, a->nbr_count);
	sorted = copy_tab(b, a->nbr_count);
	if (a_tmp == NULL || sorted == NULL)
		return (1);
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
	chunk_amount = sorted.nbr_count / 8;
	sub->max = sorted.tab[0];
	sub->min = sorted.tab[a_top];
	sub->q3_5 = sorted.tab[chunk_amount];
	sub->q3 = sorted.tab[chunk_amount * 2];
	sub->q2_5 = sorted.tab[chunk_amount * 3];
	sub->median = sorted.tab[chunk_amount * 4];
	sub->q1_5 = sorted.tab[chunk_amount * 5];
	sub->q1 = sorted.tab[chunk_amount * 6];
	sub->q0_5 = sorted.tab[chunk_amount * 7];
}
