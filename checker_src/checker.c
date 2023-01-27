/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:19:58 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/27 18:02:19 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//you need to protect those mallocs

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	r;

	r = 0;
	while (s1[r] != '\0' && s2[r] != '\0' && r < n)
	{
		if (s1[r] != s2[r])
		{
			return ((unsigned char)s1[r] - (unsigned char)s2[r]);
		}
		r++;
	}
	if (r < n)
	{
		return ((unsigned char)s1[r] - (unsigned char)s2[r]);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

t_list	*ft_lstnew(char *command)
{
	t_list	*new;
	int	len;

	len = ft_strlen(command);
	new = (t_list *)malloc(sizeof(t_list));
	new->content = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new->content, command);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_list	*add_to_instruct(char *command, t_list *instructions)
{
	if (instructions == NULL)
		instructions = ft_lstnew(command);
	else
		ft_lstadd_back(&instructions, ft_lstnew(command));
	return (instructions);
}

// void	free_everything(t_list *instructions, t_pile *a, t_pile *b)
// {
// 	return ;
// }

void	apply_instruct(t_list *instructions, t_pile *a, t_pile *b)
{
	while (instructions)
	{
		if (ft_strncmp("sa\n", instructions->content, 3) == 0)
			swap_a(a, 0);
		if (ft_strncmp("sb\n", instructions->content, 3) == 0)
			swap_b(b, 0);
		if (ft_strncmp("ss\n", instructions->content, 3) == 0)
			super_swap(a, b, 0);
		if (ft_strncmp("pa\n", instructions->content, 3) == 0)
			push(a, b, 0);
		if (ft_strncmp("pb\n", instructions->content, 3) == 0)
			push(a, b, 0);
		if (ft_strncmp("ra\n", instructions->content, 3) == 0)
			rotate(a, 0);
		if (ft_strncmp("rb\n", instructions->content, 3) == 0)
			rotate(b, 0);
		if (ft_strncmp("rr\n", instructions->content, 3) == 0)
			super_rotate(a, b, 0);
		if (ft_strncmp("rra\n", instructions->content, 4) == 0)
			reverse_rotate(a, 0);
		if (ft_strncmp("rrb\n", instructions->content, 4) == 0)
			reverse_rotate(b, 0);
		if (ft_strncmp("rrr\n", instructions->content, 4) == 0)
			super_reverse_rotate(a, b, 0);
		instructions = instructions->next;
	}
}

int	main (int argc, char **argv)
{
	t_list	*instructions;
	t_pile	a;
	t_pile	b;
	char	*command;

	instructions = NULL;
	if (check_arg(argc, argv) == 0)
		return (1);
	if (create_tab(argc, &a, &b) == 0)
		return (1);
	add_to_tab(argc, argv, &a);
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break;
		printf("%s", command);
		instructions = add_to_instruct(command, instructions);
	}
	print_tab(a);
	print_tab(b);
	apply_instruct(instructions, &a, &b);
	print_tab(a);
	print_tab(b);
	// printf("and now for the test of the list\n");
	// while (instructions)
	// {
	// 	printf("%s", instructions->content);
	// 	instructions = instructions->next;
	// }
	//free_everything(instructions, &a, &b);
	return (0);
}
