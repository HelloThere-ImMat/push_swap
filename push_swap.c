/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:08:26 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 20:02:32 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(int argc, t_pile *a, t_pile *b, t_subset *sub)
{
	if (argc <= 4)
		small_sorting(argc - 1, a);
	else if (argc <= 6)
		medium_sorting(argc - 1, a, b);
	else if (argc <= 101)
	{
		if (get_subset(sub, a, b) == 1)
			return (1);
		big_sorting(*sub, a, b);
	}
	else
	{
		if (get_subset(sub, a, b) == 1)
			return (1);
		mega_sorting(*sub, a, b);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile		*a;
	t_pile		*b;
	t_subset	sub;

	if (check_arg(argc, argv) == 0)
		return (1);
	a = create_tab(argc, argv, 1);
	b = create_tab(argc, argv, 0);
	if (a == NULL || b == NULL)
	{
		write(2, "allocation error\n", 17);
		return (1);
	}
	if (sort(argc, a, b, &sub) == 1)
	{
		free_pile(a);
		free_pile(b);
		write(2, "allocation error\n", 17);
		return (1);
	}
	free_pile(a);
	free_pile(b);
	return (0);
}

void	free_pile(t_pile *pile)
{
	free(pile->tab);
	free(pile);
}
