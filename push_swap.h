/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:34:40 by hborn             #+#    #+#             */
/*   Updated: 2022/12/22 11:40:51 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __linkedlist_h__
#define __linkedlist_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;
struct Element
{
    int number;
    Element *next;
    Element *prev;
};

typedef struct List List;
struct List
{
    Element *first;
};

List *initialisation();
int main();
void insertion(List *list, int newnb);
void suppression(List *list);
void afficherListe(List *list);
void between(List *list, int newnb, int i);
void swap(List *list);
void rotate(List *list);
void reverse_rotate(List *list);
void push(List *list1, List *list2);

#endif
