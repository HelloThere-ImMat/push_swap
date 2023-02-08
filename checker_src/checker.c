/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:19:58 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/08 14:37:13 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_command(char *command)
{
	if (ft_strncmp("sa\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("sb\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("ss\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("pa\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("pb\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("ra\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("rb\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("rr\n", command, 3) == 0)
		return (0);
	else if (ft_strncmp("rra\n", command, 4) == 0)
		return (0);
	else if (ft_strncmp("rrb\n", command, 4) == 0)
		return (0);
	else if (ft_strncmp("rrr\n", command, 4) == 0)
		return (0);
	else
		write(2, "Error\n", 6);
	return (1);
}

t_list	*add_to_instruct(char *command, t_list *instructions)
{
	if (instructions == NULL)
	{
		instructions = ft_lstnew(command);
		if (instructions == NULL)
			return (NULL);
	}
	else
		ft_lstadd_back(&instructions, ft_lstnew(command));
	return (instructions);
}

void	which_instruction(char *instruct, t_pile *a, t_pile *b)
{
	if (ft_strncmp("sa\n", instruct, 3) == 0)
		swap_a(a, 0);
	else if (ft_strncmp("sb\n", instruct, 3) == 0)
		swap_b(b, 0);
	else if (ft_strncmp("ss\n", instruct, 3) == 0)
		super_swap(a, b, 0);
	else if (ft_strncmp("pa\n", instruct, 3) == 0)
		push(b, a, 0);
	else if (ft_strncmp("pb\n", instruct, 3) == 0)
		push(a, b, 0);
	else if (ft_strncmp("ra\n", instruct, 3) == 0)
		rotate(a, 0);
	else if (ft_strncmp("rb\n", instruct, 3) == 0)
		rotate(b, 0);
	else if (ft_strncmp("rr\n", instruct, 3) == 0)
		super_rotate(a, b, 0);
	else if (ft_strncmp("rra\n", instruct, 4) == 0)
		reverse_rotate(a, 0);
	else if (ft_strncmp("rrb\n", instruct, 4) == 0)
		reverse_rotate(b, 0);
	else if (ft_strncmp("rrr\n", instruct, 4) == 0)
		super_reverse_rotate(a, b, 0);
}

void	apply_instruct(t_list *instructions, t_pile *a, t_pile *b)
{
	while (instructions)
	{
		which_instruction(instructions->content, a, b);
		instructions = instructions->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*instructions;
	t_pile	a;
	t_pile	b;
	char	*command;

	instructions = NULL;
	if (check_arg(argc, argv) == 0)
		return (1);
	if (create_tab(argc, argv, &a, &b) == 0)
		return (1);
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		if (check_command(command) == 1)
			return (1);
		instructions = add_to_instruct(command, instructions);
		if (instructions == NULL)
			return (0);
	}
	apply_instruct(instructions, &a, &b);
	check_order(a);
	return (1);
}
