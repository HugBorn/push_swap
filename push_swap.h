/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:34:40 by hborn             #+#    #+#             */
/*   Updated: 2022/12/31 16:15:21 by hborn            ###   ########.fr       */
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
	Element *last;
};

List *initialisation();
int main(int ac, char *av[]);
int int_checker(char *number);
int	ft_atoi(const char *theString);
void machina(List *list1, List *list2);
void insertion(List *list, int newnb);
void suppression(List *list);
void afficherListe(List *list);
void between(List *list, int newnb, int i);
void swap(List *list);
void rotate(List *list);
void reverse_rotate(List *list);
void push(List *list1, List *list2);
void instructions(List *list1, List *list2);

#endif
