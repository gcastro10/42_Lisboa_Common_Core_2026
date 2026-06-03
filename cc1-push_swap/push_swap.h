/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:25:00 by gonca             #+#    #+#             */
/*   Updated: 2026/06/03 21:44:21 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#define OP_SA 0
#define OP_SB 1
#define OP_SS 2
#define OP_PA 3
#define OP_PB 4
#define OP_RA 5
#define OP_RB 6
#define OP_RR 7
#define OP_RRA 8
#define OP_RRB 9
#define OP_RRR 10

enum e_strategy { SIMPLE, MEDIUM, COMPLEX, ADAPTIVE };

typedef struct s_node {
  int value;
  struct s_node *prev;
  struct s_node *next;
} t_node;

typedef struct s_stack {
  t_node *top;
  t_node *bottom;
  int size;
} t_stack;

typedef struct s_ctx {
  t_stack a;
  t_stack b;
  long counts[11];
  int bench_on;
  int strategy;
  int disorder;
} t_ctx;

/* main.c */
void init_ctx(t_ctx *ctx);
void run_sort(t_ctx *ctx);
void free_ctx(t_ctx *ctx);
int is_sorted(t_stack *a);

/* utils.c */
void put_char(char c, int fd);
void put_str(char *s, int fd);
void put_nbr(int n, int fd);
void put_uint(unsigned int n, int fd);
void put_error(void);

/* parse.c */
int ft_strcmp(const char *a, const char *b);
int parse_int(const char *s, int *out);
int is_duplicate(int val, t_stack *a);
int parse_args(int argc, char **argv, t_ctx *ctx);
int parse_one(char *arg, t_ctx *ctx);

/* parse2.c */
int set_flag(char *arg, t_ctx *ctx);

/* stack.c */
t_node *node_new(int value);
void stack_push(t_stack *s, t_node *n);
t_node *stack_pop(t_stack *s);
void stack_clear(t_stack *s);
int *stack_to_array(t_stack *s);

/* ops_swap.c */
void do_swap(t_stack *s);
void sa(t_ctx *ctx);
void sb(t_ctx *ctx);
void ss(t_ctx *ctx);

/* ops_push.c */
void pa(t_ctx *ctx);
void pb(t_ctx *ctx);

/* ops_rotate.c */
void do_rotate(t_stack *s);
void ra(t_ctx *ctx);
void rb(t_ctx *ctx);
void rr(t_ctx *ctx);

/* ops_rrotate.c */
void do_rrotate(t_stack *s);
void rra(t_ctx *ctx);
void rrb(t_ctx *ctx);
void rrr(t_ctx *ctx);

/* ops_utils.c */
int find_min_pos(t_stack *s);
int find_max_pos(t_stack *s);
void rotate_to_top(t_ctx *ctx, int pos, int is_a);
void do_rotate_dir(t_ctx *ctx, int up, int is_a);

/* disorder.c */
int compute_disorder(t_stack *a);
long count_inversions(int *arr, int n);
long count_from(int *arr, int n, int i);

/* sort_simple.c */
void sort_simple(t_ctx *ctx);
void sort_2(t_ctx *ctx);
void sort_3(t_ctx *ctx);
void push_min_to_b(t_ctx *ctx);
void pa_all(t_ctx *ctx);

/* sort_medium.c */
void sort_medium(t_ctx *ctx);
void push_chunks(t_ctx *ctx);
void push_one(t_ctx *ctx, int *pushed);
void pull_back(t_ctx *ctx);
int chunk_size(int size);

/* sort_complex.c */
void sort_complex(t_ctx *ctx);
void rank_compress(t_stack *a);
int count_less(int *arr, int n, int v);
void radix_pass(t_ctx *ctx, int bit);
int max_bits(int n);

/* strategy.c */
void dispatch_sort(t_ctx *ctx);
int pick_strategy(int permille);
char *strat_name(int strat);
void print_bench(t_ctx *ctx);
long count_total(t_ctx *ctx);

/* strategy2.c */
void print_op_counts(t_ctx *ctx);
void set_op_names(char **n);

#endif
