/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:34:40 by hborn             #+#    #+#             */
/*   Updated: 2022/12/21 11:48:55 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __linkedlist_h__
#define __linkedlist_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct Element1 Element1;
struct Element1
{
    int number;
    Element1 *next;
    Element1 *prev;
};

typedef struct List1 List1;
struct List1
{
    Element1 *first;
};

typedef struct Element2 Element2;
struct Element2
{
    int number;
    Element2 *next;
    Element2 *prev;
};

typedef struct List2 List2;
struct List2
{
    Element2 *first;
};

List1 *initialisation();
int main();
void insertion(List1 *list1, int newnb);
void suppression(List1 *list1);
void afficherListe(List1 *list1);
void between(List1 *list1, int newnb, int i);
void swap(List1 *list1);
void rotate(List1 *list1);
void reverse_rotate(List1 *list1);


#endif
