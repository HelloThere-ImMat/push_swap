/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:28:11 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 14:35:58 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	super_swap(t_pile *a, t_pile *b, int print)
{
	swap_a(a, 0);
	swap_b(b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
}

void	super_rotate(t_pile *a, t_pile *b, int print)
{
	rotate(a, 0);
	rotate(b, 0);
	if (print == 1)
		write(1, "rr\n", 3);
}

void	super_reverse_rotate(t_pile *a, t_pile *b, int print)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	if (print == 1)
		write(1, "rrr\n", 4);
}
