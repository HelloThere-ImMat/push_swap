/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:52 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/19 11:30:10 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_pile *a, int print)
{
	int tmp;
	int i_max;

	i_max = a->nbr_count - 1;
	if (a->nbr_count == 0 || a->nbr_count == 1)
		return ;
	tmp = a->tab[i_max];
	a->tab[i_max] = a->tab[i_max - 1];
	a->tab[i_max - 1] = tmp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void swap_b(t_pile *b, int print)
{
	int tmp;
	int i_max;

	i_max = b->nbr_count - 1;
	if (b->nbr_count == 0 || b->nbr_count == 1)
		return ;
	tmp = b->tab[i_max];
	b->tab[i_max] = b->tab[i_max - 1];
	b->tab[i_max - 1] = tmp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void push_a(t_pile *a, t_pile *b, int print)
{
	int i_maxA;
	int i_maxB;

	i_maxA = a->nbr_count - 1;
	i_maxB = b->nbr_count - 1;
	if (b->nbr_count == 0)
		return ;
	a->tab[i_maxA + 1] = b->tab[i_maxB];
	//b->tab[i_maxB - 1] = NULL;
	b->nbr_count -= 1;
	a->nbr_count += 1;
	if (print == 1)
		write(1, "pa\n", 3);
}

void push_b(t_pile *a, t_pile *b, int print)
{
	int i_maxA;
	int i_maxB;

	i_maxA = a->nbr_count - 1;
	i_maxB = b->nbr_count - 1;
	if (a->nbr_count == 0)
		return ;
	b->tab[i_maxB + 1] = a->tab[i_maxA];
	//b->tab[i_maxB - 1] = NULL;
	a->nbr_count -= 1;
	b->nbr_count += 1;
	if (print == 1)
		write(1, "pb\n", 3);
}
