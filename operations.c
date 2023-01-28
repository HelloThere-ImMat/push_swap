/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:52 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 14:44:19 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile *a, int print)
{
	int	tmp;
	int	i_max;

	i_max = a->nbr_count - 1;
	if (a->nbr_count == 0 || a->nbr_count == 1)
		return ;
	tmp = a->tab[i_max];
	a->tab[i_max] = a->tab[i_max - 1];
	a->tab[i_max - 1] = tmp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_pile *b, int print)
{
	int	tmp;
	int	i_max;

	i_max = b->nbr_count - 1;
	if (b->nbr_count == 0 || b->nbr_count == 1)
		return ;
	tmp = b->tab[i_max];
	b->tab[i_max] = b->tab[i_max - 1];
	b->tab[i_max - 1] = tmp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	push(t_pile *src, t_pile *dest, int print)
{
	if (src->nbr_count == 0)
		return ;
	dest->nbr_count += 1;
	dest->tab[dest->nbr_count - 1] = src->tab[src->nbr_count - 1];
	src->nbr_count -= 1;
	if (print == 1 && dest->id == 1)
		write(1, "pa\n", 3);
	if (print == 1 && dest->id == 2)
		write(1, "pb\n", 3);
}
