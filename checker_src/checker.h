/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:20:24 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/28 19:01:16 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"

typedef struct s_pile
{
	int	*tab;
	int	nbr_count;
	int	id;
}	t_pile;

//CHECKER

t_list	*add_to_instruct(char *command, t_list *instructions);
void	apply_instruct(t_list *instructions, t_pile *a, t_pile *b);
int		main(int argc, char **argv);

//OPERATIONS

void	swap_a(t_pile *a, int print);
void	swap_b(t_pile *b, int print);
void	push(t_pile *src, t_pile *dest, int print);

//OPERATIONS 2

void	rotate(t_pile *pile, int print);
void	reverse_rotate(t_pile *pile, int print);

//OPERATIONS 3

void	super_swap(t_pile *a, t_pile *b, int print);
void	super_rotate(t_pile *a, t_pile *b, int print);
void	super_reverse_rotate(t_pile *a, t_pile *b, int print);

//PILES UTILS

int		create_tab(int argc, char **argv, t_pile *a, t_pile *b);
void	add_to_tab(int argc, char **argv, t_pile *a);
void	free_pile(t_pile *pile);
t_pile	*copy_tab(const t_pile *original);

//UTILS

int		check_order(t_pile a);
int		check_arg(int argc, char **argv);
int		check_for_doubles(int argc, char **argv);
t_list	*ft_lstnew(char *command);
void	ft_lstadd_back(t_list **lst, t_list *new);

//STR UTILS

int		ft_atoi(const char *nptr);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcpy(char *dest, char *src);

#endif
