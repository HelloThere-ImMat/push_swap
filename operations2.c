/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:27:05 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/23 11:01:18 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_pile *pile, int print)
{
	int i;
	int	tmp;


	i = pile->nbr_count - 1;
	tmp = pile->tab[i];
	while (i > 0)
	{
		pile->tab[i] = pile->tab[i - 1];
		i--;
	}
	pile->tab[i] = tmp;
	if (print == 1 && pile->id == 1)
		write(1, "ra\n", 3);
	else if (print == 1 && pile->id == 2)
		write(1, "rb\n", 3);
}

void reverse_rotate(t_pile *pile, int print)
{
	int i;
	int i_max;
	int	tmp;

	i = 0;
	i_max = pile->nbr_count - 1;
	tmp = pile->tab[0];
	while (i < i_max)
	{
		pile->tab[i] = pile->tab[i + 1];
		i++;
	}
	pile->tab[i_max] = tmp;
	if (print == 1 && pile->id == 1)
		write(1, "rra\n", 4);
	else if (print == 1 && pile->id == 2)
		write(1, "rrb\n", 4);
}
