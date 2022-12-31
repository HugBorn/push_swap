/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:46:03 by hborn             #+#    #+#             */
/*   Updated: 2022/12/31 15:33:08 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(List *list)
{
	Element *actual = list->first;
	Element *last = NULL;

    while (actual->next != NULL)
    {
        last = actual;
        actual = actual->next;
    }

    last->next = NULL;
    
    insertion(list, actual->number);
}

void reverse_rotate(List *list)
{
	Element *actual = list->first;
	int i = 0;
	int x = 0;

	while (actual->next != NULL)
	{
		if (i == 0)
			x = actual->number;
		if (i == 1)
			list->first = actual;
		actual = actual->next;
		i++;
	}
	
	i = actual->number;
	between(list, x, i);
}

void push(List *list1, List *list2)
{
	Element *first2 = list2->first;
	int x;

	x = 0;
	x = first2->number;
	suppression(list2);
	insertion(list1, x);
}
