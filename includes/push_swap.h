/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:36:15 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/30 13:45:33 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_pile
{
	int				nbr;
	int				index;
	int				groupe;
	struct s_pile	*next;
}				t_pile;

// in main.c
int			a_is_sorted(t_pile **a);
void		init_pile(t_pile **a, char **argv);
void		ft_free(t_pile **a, t_pile **b);

// in error_check.c
int			check_max(int argc, char **argv);
int			check_int(int argc, char **argv);
int			check_doubles(int argc, char **argv);
int			check_error(int argc, char **argv);
int			check_arguments(int argc, char **argv);

// in swap.c
void		sa(t_pile **a);
void		sb(t_pile **b);
void		sa_no_print(t_pile **a);
void		sb_no_print(t_pile **b);
void		ss(t_pile **a, t_pile **b);

// in push.c
void		pa(t_pile **a, t_pile **b);
void		pb(t_pile **a, t_pile **b);

// in rotate.c
void		ra(t_pile **a);
void		rb(t_pile **b);
void		ra_no_print(t_pile **a);
void		rb_no_print(t_pile **b);
void		rr(t_pile **a, t_pile **b);

// in reverse_rotate.c
void		rra(t_pile **a);
void		rrb(t_pile **b);
void		rra_no_print(t_pile **a);
void		rrb_no_print(t_pile **b);
void		rrr(t_pile **a, t_pile **b);

// in sort_small.c
void		same_sort(t_pile **a, t_pile **b);
void		sort_four(t_pile **a, t_pile **b);
void		sort_five(t_pile **a, t_pile **b);
void		sort_small(t_pile **a, t_pile **b);
void		sort_three(t_pile **a);

// in sort_big.c
void		sort(t_pile **a, t_pile **b, int size, int sizeb);
int			push_b(t_pile **a, t_pile **b, int median, int limit);
void		pre_sort(t_pile **a, t_pile **b, int size);
void		sort_big(t_pile **a, t_pile **b);

// in place_element.c
void		double_rotate(t_pile **a, t_pile **b, int count_ra, int count_rb);
int			put_element_on_top(t_pile **b, int element_index, int sizeb);
void		rotate_pour_encadrer(t_pile **a, int index_prev, int sizea);
void		encadrer_element(t_pile **a, int element_index, int size);

// in find_group_max.c
int			nb_group_max(t_pile **b, int group_max);
int			find_group_max(t_pile **b);

// in count_coups.c
int			ft_count_ra(t_pile **a, int element, int sizea);
int			ft_count_rb(t_pile **b, int element, int sizeb);
int			count_coups(int count_ra, int count_rb, int sizea, int sizeb);
int			find_elem(t_pile **a, t_pile **b, int sizea, int sizeb);

// in put_index.c
void		put_index(t_pile **a, int *tab, int size);
void		sort_tab(t_pile **a, int *tab, int size);
void		put_lst_in_tab(t_pile **a, int size);

/*~~~~~~~~~~~~~~~~~~~~~~~LIBFT~~~~~~~~~~~~~~~~~~~~~~~*/

// in libft_fct.c
int			ft_isdigit(int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_tolower(int c);
int			ft_isspace(int c);
long		ft_strtol(const char *str, char **endptr, int base);

// in libft_fct2.c
const char	*skip_whitespace(const char *p);
int			get_sign(const char **p);
int			get_base(const char **p, int base);
long		parse_number(const char **p, int base);
void		handle_overflow(long *result, int sign);

// in libft_fct3.c
void		ft_lstadd_front(t_pile **lst, t_pile *new);
int			ft_int(char chr, int var);
int			ft_uns(char chr, unsigned long long int var);
int			ft_conv(const char *str, int i, va_list args);
int			ft_printf(const char *str, ...);

// in libft_fct4.c
t_pile		*ft_lstlast(t_pile *lst);
int			ft_putchar_fd(char c, int fd);
int			num_len(long int nbr);
int			ft_putnbr_fd(int nbr, int fd);
int			ft_putunbr(unsigned long long int nbr);

// in libft_fct5.c
int			ft_strlen(char *str);
int			num_hexa_len(long long int nbr);
void		ft_print_base_l(unsigned long long int nbr);
int			ft_putnbr_base_low(unsigned long long int nbr);
void		ft_print_base_u(unsigned long long int nbr);

// in libft_fct6.c
int			ft_putnbr_base_up(unsigned long long int nbr);
int			ft_putstr_fd(char *s, int fd);
int			u_num_hexa_len(unsigned long long int nbr);
void		ft_putptr_hexa(unsigned long long int ptr);
int			ft_putptr(unsigned long long int ptr);

// in libft_fct7.c
void		ft_error(void);
long int	ft_atoi(const char *str);
t_pile		*ft_lstnew(int nbr);
void		ft_lstadd_back(t_pile **lst, t_pile *new);
int			ft_lstsize(t_pile *lst);

#endif
