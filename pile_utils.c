#include "push_swap.h"

t_pile copy_tab (t_pile pile)
{
	t_pile new;
	int	i;

	new.nbr_count = pile.nbr_count;
	new.tab = malloc(sizeof(int) * pile.nbr_count);
	new.id = pile.id;
	i = 0;
	while (pile.tab[i])
	{
		new.tab[i] = pile.tab[i];
		i++;
	}
	return (new);
}

void add_to_tab(int	argc, char **argv, t_pile *a)
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

int	create_tab(int argc, t_pile *a, t_pile *b)
{
	a->tab = malloc(sizeof(int)*(argc - 1));
	b->tab = malloc(sizeof(int)*(argc - 1));
	a->nbr_count = argc - 1;
	b->nbr_count = 0;
	a->id = 1;
	b->id = 2;
	if (a->tab == NULL || b->tab == NULL)
	{
		write(2, "allocation error\n", 17);
		return (0);
	}
	return (1);
}

int is_min (int	nb, t_pile pile)
{
	int	i;

	i = 0;
	while  (i < pile.nbr_count)
	{
		if (pile.tab[i] < nb)
			return (0);
		i++;
	}
	return (1);
}

int is_max (int	nb, t_pile pile)
{
	int	i;

	i = 0;
	while  (i < pile.nbr_count)
	{
		if (pile.tab[i] > nb)
			return (0);
		i++;
	}
	return (1);
}

void    print_tab(t_pile pile)
{
	int     i;

	if (pile.nbr_count == 0)
		printf("Empty\n");
	i = pile.nbr_count - 1;
	while (i >= 0)
	{
		printf("the %d element is %d\n", i, pile.tab[i]);
		i--;
	}
}
