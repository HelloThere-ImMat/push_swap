/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:14:43 by mdorr             #+#    #+#             */
/*   Updated: 2023/02/07 12:33:12 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define INTMIN -2147483648
# define INTMAX 2147483647

typedef struct s_pile
{
	int	*tab;
	int	nbr_count;
	int	id;
}	t_pile;

typedef struct s_subset
{
	int	min;
	int	q0_5;
	int	q1;
	int	q1_5;
	int	median;
	int	q2_5;
	int	q3;
	int	q3_5;
	int	max;
}	t_subset;

//OPERATIONS

void			swap_b(t_pile *b, int print);
void			swap_a(t_pile *a, int print);
void			push(t_pile *src, t_pile *dest, int print);

//OPERATION2

void			rotate(t_pile *pile, int print);
void			reverse_rotate(t_pile *pile, int print);

//OPERATION3

void			super_swap(t_pile *a, t_pile *b, int print);
void			super_reverse_rotate(t_pile *a, t_pile *b, int print);
void			super_rotate(t_pile *a, t_pile *b, int print);

//UTILS

long long		ft_atoi(const char *nptr);
int				check_arg(int argc, char **argv);
int				check_for_doubles(int argc, char **argv);
int				ft_strcmp(char *s1, char *s2);

//PILE UTILS

t_pile			*copy_tab(const t_pile *original);
t_pile			*create_tab(int argc, char **argv, int a);
void			add_to_tab(int argc, char **argv, t_pile *a);
int				quartile_is_in_pile(int quartile_under,
					int quartile_over, t_pile a);

//SORTING UTILS

void			get_quartile_to_top(int quartile_under,
					int quartile_over, t_pile *a);
void			get_min_to_top(int min, t_pile *pile);
void			get_min_to_bottom(int min, t_pile *pile);
int				is_min(int nb, t_pile pile);
int				is_max(int nb, t_pile pile);

//SORTING UTILS 2

int				r_or_rr2(t_pile *a, t_pile *b, int top_a, int top_b);
void			add_to_b(t_pile *a, t_pile *b);
void			add_extreme_to_dest(t_pile *a, t_pile *b, int is_min);
void			add_to_a2(t_pile *a, t_pile *b);

//SORTING UTILS 3

int				is_in_quartile(int nbr, int under, int over);
void			get_first_half_to_b(t_pile *a, t_pile *b, t_subset sub);
void			get_second_half_to_b(t_pile *a, t_pile *b, t_subset sub);
void			finish_big_sorting(t_pile *a, t_pile *b, t_subset sub);

//SUBSET

int				get_subset(t_subset *sub, t_pile *a, t_pile *b);
void			find_subset(t_subset *sub, t_pile sorted);
void			find_big_subset(t_subset *sub, t_pile sorted);

//EASY SORTING

void			sort_trio(t_pile *a);
void			small_sorting(int argc, t_pile *a);
void			add_to_a(t_pile *a, t_pile *b, int *counter);
void			medium_sorting(int argc, t_pile *a, t_pile *b);
void			ugly_sorting(t_pile *a_tmp, t_pile *sorted);

//HARD SORTING

void			sort_quartile(int under, int over, t_pile *a, t_pile *b);
void			big_sorting(t_subset sub, t_pile *a, t_pile *b);
void			mega_sorting(t_subset sub, t_pile *a, t_pile *b);

//PUSH SWAP

void			print_tab(t_pile pile);
int				main(int argc, char **argv);
int				sort(int argc, t_pile *a, t_pile *b, t_subset *sub);
void			free_pile(t_pile *pile);

#endif
