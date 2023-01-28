/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:16:50 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 16:00:32 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_pile(t_pile *pile)
{
	free(pile->tab);
	free(pile);
}

t_pile	*copy_tab(const t_pile *original)
{
	t_pile	*copy;
	int		i;

	i = 0;
	copy = (t_pile *)malloc(sizeof(t_pile));
	copy->nbr_count = original->nbr_count;
	copy->id = original->id;
	copy->tab = (int *) malloc(sizeof(int) * original->nbr_count);
	while (i < original->nbr_count)
	{
		copy->tab[i] = original->tab[i];
		i++;
	}
	return (copy);
}

void	add_to_tab(int argc, char **argv, t_pile *a)
{
	int	i;
	int	i2;
	int	tmp;

	i = argc;
	i2 = 0;
	while (i > 0)
	{
		tmp = ft_atoi(argv[i - 1]);
		a->tab[i2] = tmp;
		i--;
		i2++;
	}
}

int	create_tab(int argc, char **argv, t_pile *a, t_pile *b)
{
	a->tab = malloc(sizeof(int) * (argc - 1));
	b->tab = malloc(sizeof(int) * (argc - 1));
	a->nbr_count = argc - 1;
	b->nbr_count = 0;
	a->id = 1;
	b->id = 2;
	if (a->tab == NULL || b->tab == NULL)
	{
		write(2, "allocation error\n", 17);
		return (0);
	}
	add_to_tab(argc, argv, a);
	return (1);
}

//void	print_tab(t_pile pile)
//{
//	int	i;

//	if (pile.nbr_count == 0)
//		printf("Empty\n");
//	i = pile.nbr_count - 1;
//	while (i >= 0)
//	{
//		printf("the %d element is %d\n", i, pile.tab[i]);
//		i--;
//	}
//}
