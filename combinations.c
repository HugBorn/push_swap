/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hborn <hborn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:52:36 by hborn             #+#    #+#             */
/*   Updated: 2022/12/23 11:47:48 by hborn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>


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

char machina(List *list1, List *list2)
{
	swap(list1);
    
    
    rotate(list1);
    

    reverse_rotate(list1);
    

	push(list2, list1);
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

int main(char ac, char* av[])
{
	int i;
	int number;

	i = 1;
	while (av[i])
		i++;
	i -= 1;
    List *maListe1 = initialisation();
    List *maListe2 = initialisation();
	if (ac > 1)
	{
		while (i >= 1)
		{
			if (int_checker(av[i]) == 0)
			{
				// printf("%i\n", number);
				write(1, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
			else
			{
				number = ft_atoi(av[i]);
    			insertion(maListe1, number);
			}
			i--;
		}
	}
	else
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}

    afficherListe(maListe1);
    afficherListe(maListe2);
	
	machina(maListe1, maListe2);

    afficherListe(maListe1);
    afficherListe(maListe2);

    return (0);
}
