/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:52:36 by hborn             #+#    #+#             */
/*   Updated: 2023/01/04 23:13:32 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>


List *initialisation(int nb)
{
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

	element->number = nb;
	element->next = NULL;
	list->first = element;
	list->last = element;

    return list;
}

int int_checker(char *number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (number[i] < 48 || number[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int list_checker(List *list)
{
	Element *actual = list->first;
	
	while (actual->next != NULL)
	{
		if (actual->number > actual->next->number)
			return (0);
		else
			actual = actual->next;
	}
	return (1);
}

int	ft_atoi(const char *theString)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (theString[i] != '\0')
	{
		if (theString[i] == '-')
		{
			sign *= -1;
			i++;
		}
		else if (theString[i] == '+')
			i++;
		while (theString[i] >= '0' && theString[i] <= '9')
		{
			num = num * 10 + (theString[i] - 48);
			i++;
		}
	}
	return (num * sign);
}

int length_checker(List *list)
{
	Element *actual = list->first;

	int i = 0;

	while (actual->next != NULL)
	{
		actual = actual->next;
		i++;
	}
	return (i);
}

int machina(List *list1, List *list2)
{
	Element *actual1 = list1->first;
	Element *actual2 = list2->first;
	Element *last1 = list1->last;
	Element *last2 = list2->last;
	int check = 0;

	// SWAP
	if (actual1->next != NULL && actual2->next != NULL && actual1->number > actual1->next->number && actual2->number < actual2->next->number)
	{
		swap(list1);
		swap(list2);
		write(1, "ss\n", 3);
		check = 1;
	}
	if (actual1->next != NULL && actual1->number > actual1->next->number)
	{
		swap(list1);
		write(1, "sa\n", 3);
		check = 1;
	}
	if (actual2->next != NULL && actual2->number < actual2->next->number)
	{
		swap(list2);
		write(1, "sb\n", 3);
		check = 1;
	}
	// ROTATE
	while (actual1->next != NULL && actual2->next != NULL && actual1->number > last1->number && actual2->number < last2->number)
	{
		rotate(list1);
		rotate(list2);
		write(1, "rr\n", 3);
		check = 1;
	}
	while (actual1->next != NULL && actual1->number > last1->number)
	{
		rotate(list1);
		write(1, "ra\n", 3);
		check = 1;
	}
	while (length_checker(list2) > 0 && actual2->number < last2->number)
	{
		rotate(list2);
		write(1, "rb\n", 3);
		check = 1;
	}
	// REVERSE ROTATE
	while (actual1->next != NULL && actual2->next != NULL && actual1->number > last1->number && actual2->number < last2->number)
	{
		reverse_rotate(list1);
		reverse_rotate(list2);
		write(1, "rrr\n", 4);
		check = 1;
	}
	while (actual1->next != NULL && actual1->number > last1->number)
	{
		reverse_rotate(list1);
		write(1, "rra\n", 4);
		set_last(list1);
		check = 1;
	}
	while (actual2->next != NULL && actual2->number < last2->number)
	{
		reverse_rotate(list2);
		write(1, "rrb\n", 4);
		check = 1;
	}
	return(check);
}

void pushpushpush(List *list1, List *list2, int nb)
{
	// PUSH
	if (list_checker(list1) == 0)
	{
		if (nb == 0)
		{
			between(list2, list1->first->number, 0);
			suppression(list2);
			suppression(list1);
			write(1, "pa\n", 3);
		}
		else
		{
			push(list1, list2);
			write(1, "pa\n", 3);
		}
	}
}

void coordinator(List *list1, List *list2)
{
	int nb = 0;

	while (list_checker(list1) == 0)
	{

		machina(list1, list2);

		pushpushpush(list1, list2, nb);
		nb++;

	}
	while (nb != 0)
	{

		printf("%s\n", "list1 :");
		afficherListe(list1);
		printf("%s\n", "list2 :");
   		afficherListe(list2);
		printf("%i\n", nb);
		
		machina(list1, list2);
		printf("nb : %i\n", nb);
		if (nb == 2)
		{
			insertion(list1, list2->first->number);
			suppression(list2);
			write(1, "pb\n", 3);
		}
		else
		{
			push(list2, list1);
			write(1, "pb\n", 3);
		}
		machina(list1, list2);
		
		nb--;
	}
}

int main(int ac, char* av[])
{
	int i;
	int number;

	i = 1;
	while (av[i])
		i++;
	i--;
    List *list1 = initialisation(ft_atoi(av[i--]));
    List *list2 = initialisation(0);

	if (ac > 1)
	{
		while (i > 0)
		{
			if (int_checker(av[i]) == 0)
			{
				write(1, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
			else
			{
				number = ft_atoi(av[i]);
    			list1 = insertion(list1, number);
			}
			i--;
		}
	}
	else
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	printf("%s\n", "list1 :");
	afficherListe(list1);
	printf("%s\n", "list2 :");
   	afficherListe(list2);

	coordinator(list1, list2);
	// machina(list1, list2);

	printf("%s\n", "list1 :");
	afficherListe(list1);
	printf("%s\n", "list2 :");
   	afficherListe(list2);

    return (0);
}
