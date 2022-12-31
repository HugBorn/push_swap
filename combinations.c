/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:52:36 by hborn             #+#    #+#             */
/*   Updated: 2022/12/31 16:28:38 by hborn            ###   ########.fr       */
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

void machina(List *list1, List *list2)
{
	instructions(list1, list2);
}

void instructions(List *list1, List *list2)
{
	Element *actual1 = list1->first;
	Element *actual2 = list2->first;

	int i = 0;
	int j = 0;
	// int nb = 0;

	while (actual1->next != NULL)
	{
		actual1 = actual1->next;
		i++;
	}
	while (actual2->next != NULL)
	{
		actual1 = actual1->next;
		j++;
	}
	// SWAP
	if (list1 && list2 && i > 2 && j > 2)
	{
		swap(list1);
		swap(list2);
		write(1, "ss", 3);
	}
	if (list1 && i > 2)
	{
		swap(list1);
		write(1, "sa", 3);
	}
	if (list2 && j > 2)
	{
		swap(list2);
		write(1, "sb", 3);
	}
	printf("\n%s", "OK");
	// // PUSH
	// if (list1)
	// {
	// 	if (!list2)
	// 	{
    // 		nb = list1->first->number;
	// 		list2 = initialisation(nb);
	// 		suppression(list1);
	// 	}
	// 	else
	// 	{
	// 		push(list1, list2);
	// 		write(1, "pa", 3);
	// 	}
	// }
	// if (list2)
	// {
	// 	push(list2, list1);
	// 	write(1, "pb", 3);
	// }
	// // ROTATE
	// if (list1 && list2 && i > 1 && j > 1)
	// {
	// 	rotate(list1);
	// 	rotate(list2);
	// 	write(1, "rr", 3);
	// }
	// if (list1 && i > 1)
	// {
	// 	rotate(list1);
	// 	write(1, "ra", 3);
	// }
	// if (list2 && j > 1)
	// {
	// 	rotate(list2);
	// 	write(1, "rb", 3);
	// }
	// // REVERSE ROTATE
	// 	if (list1 && list2 && i > 1 && j > 1)
	// {
	// 	reverse_rotate(list1);
	// 	reverse_rotate(list2);
	// 	write(1, "rr", 3);
	// }
	// if (list1 && i > 1)
	// {
	// 	reverse_rotate(list1);
	// 	write(1, "ra", 3);
	// }
	// if (list2 && j > 1)
	// {
	// 	reverse_rotate(list2);
	// 	write(1, "rb", 3);
	// }
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
		while (i >= 1)
		{
			if (int_checker(av[i]) == 0)
			{
				write(1, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
			else
			{
				number = ft_atoi(av[i]);
    			insertion(list1, number);
			}
			i--;
		}
	}
	else
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	
	machina(list1, list2);

    // afficherListe(maListe1);
    // afficherListe(maListe2);

    return (0);
}
