/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:34:40 by hborn             #+#    #+#             */
/*   Updated: 2023/01/04 22:24:10 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __linkedlist_h__
#define __linkedlist_h__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
int machina(List *list1, List *list2);
List *insertion(List *list, int newnb);
void suppression(List *list);
void afficherListe(List *list);
void between(List *list, int newnb, int i);
void swap(List *list);
void rotate(List *list);
void reverse_rotate(List *list);
void push(List *list1, List *list2);
int list_checker(List *list);
void set_last(List *list);
void pushpushpush(List *list1, List *list2, int nb);
void coordinator(List *list1, List *list2);



#endif