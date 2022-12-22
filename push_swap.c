/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:45:32 by hborn             #+#    #+#             */
/*   Updated: 2022/12/22 11:38:43 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void insertion(List *list, int newnb)
{
    /* Création du nouvel élément */
    Element *new = malloc(sizeof(*new));
    if (list == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->number = newnb;

    /* Insertion de l'élément au début de la liste */
    new->next = list->first;
    list->first = new;
}

void suppression(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
        Element *aSupprimer = list->first;
        list->first = list->first->next;
        free(aSupprimer);
    }
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

void between(List *list, int newnb, int i)
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
}

void swap(List *list)
{
	Element *actual = list->first;
	int number;
	int i = 0;

	number = actual->number;
	while (i != 1)
	{
		i++;
		actual = actual->next;
	}
	i = actual->number;
	//printf("\n%d", i);
	between(list, number, i);
	suppression(list);

}
