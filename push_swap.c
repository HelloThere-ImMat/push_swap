#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile a;
	t_pile b;
	t_subset sub;

	if (check_arg(argc, argv) == 0)
		return (1);
	if (create_tab(argc, &a, &b) == 0)
		return (1);
	add_to_tab(argc, argv, &a);
	//printf("a before sorting :\n");
	//print_tab(a);
	if (argc <= 4)
		small_sorting(argc - 1, &a);
	else if (argc <= 6)
		medium_sorting(argc - 1, &a, &b);
	else if (argc <= 101)
	{
		if (get_subset(&sub,a, b) == 1)
			return (1);
		//big_sorting(sub, &a, &b);
	}
	else
	{
		if (get_subset(&sub,a, b) == 1)
			return (1);
		mega_sorting(sub, &a, &b);
	}
	// printf("a after sorting :\n");
	// print_tab(a);
	// printf("b after sorting :\n");
	// print_tab(b);
	//free(a.tab);
	//free(b.tab);
	return (0);
}
