/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:20:24 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/27 18:06:11 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "get_next_line.h"
#include <stdio.h>

typedef struct s_pile
{
	int	*tab;
	int nbr_count;
	int id;
}	t_pile;

//CHECKER

int	main (int argc, char **argv);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcpy(char *dest, char *src);
t_list	*ft_lstnew(char *command);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*add_to_instruct(char *command, t_list *instructions);
void	apply_instruct(t_list *instructions, t_pile *a, t_pile *b);

//OPERATIONS

void	swap_b(t_pile *b, int print);
void	swap_a(t_pile *a, int print);
void	push_a(t_pile *a, t_pile *b, int print);
void	push_b(t_pile *a, t_pile *b, int print);
void	push(t_pile *src, t_pile *dest, int print);


//OPERATION2

void	rotate(t_pile *pile, int print);
void	reverse_rotate(t_pile *pile, int print);

//OPERATION3

void	super_swap(t_pile *a, t_pile *b, int print);
void	super_reverse_rotate(t_pile *a, t_pile *b, int print);
void	super_rotate(t_pile *a, t_pile *b, int print);

//UTILS

int	ft_atoi(const char *nptr);
int	check_arg(int argc, char **argv);
int	check_for_doubles (int argc, char **argv);
int	ft_strcmp(char *s1, char *s2);

//PILE UTILS

t_pile copy_tab (t_pile pile);
void	add_to_tab(int	argc, char **argv, t_pile *a);
void   	print_tab(t_pile pile);
int	create_tab(int argc, t_pile *a, t_pile *b);
int	is_min (int	nb, t_pile pile);
int	is_max (int	nb, t_pile pile);

#endif
