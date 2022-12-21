/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:46:03 by hborn             #+#    #+#             */
/*   Updated: 2022/12/21 11:48:56 by hborn            ###   ########.fr       */
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
	Element *last = NULL;
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
