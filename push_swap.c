/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:45:32 by hborn             #+#    #+#             */
/*   Updated: 2023/01/05 17:39:05 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void set_last(List *list)
// {
// 	Element *actual = list->first;

// 	while (actual->next != NULL)
// 		actual = actual->next;
// 	list->last = actual;
// }

List *insertion(List *list, int newnumber)
{
    Element *new = malloc(sizeof(*new));
	
    if (list == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->number = newnumber;

	new->next = list->first;
	new->next->prev = new;
	new->prev = NULL;
    list->first = new;
	return (list);
}

List *suppression(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
        Element *aSupprimer = list->first;
        list->first = aSupprimer->next;
        free(aSupprimer);
    }
	return (list);
}

void afficherListe(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actual = list->first;

    while (actual != NULL)
    {
        printf("%d -> ", actual->number);
        actual = actual->next;
    }
    printf("NULL\n");
}

List *between(List *list, int newnb, int i)
{
	Element *actual = list->first;
	Element *between = malloc(sizeof(*between));
	if (list == NULL ||  between == NULL)
	{
		exit(EXIT_FAILURE);
	}
	between->number = newnb;

	while (actual != NULL)
	{
		if (actual->number == i)
		{
			between->next = actual->next;
			actual->next = between;
		}
		actual = actual->next;
	}
	return (list);
}

