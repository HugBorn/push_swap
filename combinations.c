/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:52:36 by hborn             #+#    #+#             */
/*   Updated: 2022/12/21 11:48:59 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


List1 *initialisation()
{
    List1 *list1 = malloc(sizeof(*list1));
    Element1 *element1 = malloc(sizeof(*element1));

    if (list1 == NULL || element1 == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element1->number = 0;
    element1->next = NULL;
    //element->prev = NULL;
    list1->first = element1;

    return list1;
}

int main()
{
    List1 *maListe1 = initialisation();

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

    return (0);
}
