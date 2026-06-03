/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   disorder.c                                            :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long	count_from(int *arr, int n, int i)
{
	long	c;
	int		j;

	c = 0;
	j = i + 1;
	while (j < n)
	{
		if (arr[i] > arr[j])
			c++;
		j++;
	}
	return (c);
}

long	count_inversions(int *arr, int n)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < n)
	{
		total += count_from(arr, n, i);
		i++;
	}
	return (total);
}

int	compute_disorder(t_stack *a)
{
	int		*arr;
	long	mistakes;
	long	total;
	int		res;

	if (a->size <= 1)
		return (0);
	arr = stack_to_array(a);
	if (!arr)
		return (0);
	mistakes = count_inversions(arr, a->size);
	total = (long)a->size * (a->size - 1) / 2;
	res = (int)(mistakes * 1000 / total);
	free(arr);
	return (res);
}
