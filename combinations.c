/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:52:36 by hborn             #+#    #+#             */
/*   Updated: 2022/12/22 11:27:18 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


List *initialisation()
{
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->number = 0;
    element->next = NULL;
    list->first = element;

    return list;
}

int main()
{
    List *maListe1 = initialisation();
    List *maListe2 = initialisation();

    insertion(maListe1, 4);
    insertion(maListe1, 8);
    insertion(maListe1, 15);
    insertion(maListe1, 17);

    afficherListe(maListe1);
    
    swap(maListe1);
    
    afficherListe(maListe1);
    
    rotate(maListe1);
    
    afficherListe(maListe1);    

    reverse_rotate(maListe1);
    
    afficherListe(maListe1);

	push(maListe2, maListe1);

	afficherListe(maListe1);
	afficherListe(maListe2);

    return (0);
}
