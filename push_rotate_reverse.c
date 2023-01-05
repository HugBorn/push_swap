/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:46:03 by hborn             #+#    #+#             */
/*   Updated: 2023/01/05 17:39:13 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

List *rotate(List *list)
{
	Element *actual = list->first;
	Element *last = list->last;
	Element *newfirst  = malloc(sizeof(*newfirst));

	newfirst->number = last->number;
	newfirst->next = actual;
	last->prev->next = NULL;
	list->first = newfirst;
	set_last(list);
	// list->last = last->prev;
	free(last);

	return(list);
}

List *reverse_rotate(List *list)
{

	Element *first = list->first;
	Element *last = list->last;
	Element *newlast  = malloc(sizeof(*newlast));

	newlast->number = first->number;
	newlast->next = NULL;
	last->next = newlast;
	list->first = first->next;
	list->last = newlast;
	free(first);

	return (list);
}

void push(List *list1, List *list2)
{
	Element *first1 = list1->first;
	int x;

	x = first1->number;
	suppression(list1);
	insertion(list2, x);
	set_last(list1);
	set_last(list2);
}
