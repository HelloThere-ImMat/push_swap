/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:08:26 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 14:16:30 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile		a;
	t_pile		b;
	t_subset	sub;

	if (check_arg(argc, argv) == 0)
		return (1);
	if (create_tab(argc, argv, &a, &b) == 0)
		return (1);
	if (argc <= 4)
		small_sorting(argc - 1, &a);
	else if (argc <= 6)
		medium_sorting(argc - 1, &a, &b);
	else if (argc <= 101)
	{
		if (get_subset(&sub, &a, &b) == 1)
			return (1);
		big_sorting(sub, &a, &b);
	}
	else
	{
		if (get_subset(&sub, &a, &b) == 1)
			return (1);
		mega_sorting(sub, &a, &b);
	}
	return (0);
}
