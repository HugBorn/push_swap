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

List *swap(List *list)
{
	Element *first = list->first;
	Element *second = first->next;
	Element *temp  = malloc(sizeof(*temp));

	temp->number = first->number;
	first->number = second->number;
	second->number = temp->number;

	free(temp);

	return(list);
}


List *rotate(List *list)
{
	Element *first = list->first;
	Element *last = list->last;
	Element *newfirst  = malloc(sizeof(*newfirst));

	newfirst->number = last->number;
	last->prev->next = NULL;

	newfirst->next = first;
	first->prev = newfirst;
	newfirst->prev = NULL;

	list->first = newfirst;
	list->last = last->prev;

	free(last);

	return(list);
}

List *reverse_rotate(List *list)
{

	Element *first = list->first;
	Element *last = list->last;
	Element *newlast  = malloc(sizeof(*newlast));

	newlast->number = first->number;
	newlast->prev = last;
	newlast->next = NULL;
	last->next = newlast;

	list->last = newlast;
	list->first = first->next;
	first->next->prev = NULL;

	free(first);

	return (list);
}

void push(List *list1, List *list2)
{
	Element *first1 = list1->first;
	int x;

	x = first1->number;
	insertion(list2, x);

	if (first1->next != NULL)
	{
		first1->next->prev = NULL;
		list1->first = first1->next;
		free(first1);
	}
}