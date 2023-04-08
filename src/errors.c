/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:39:53 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/08 14:31:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/errors.h"
#include <stdio.h>
#include <stdlib.h>

void	terminate(char *s)
{
	ft_putendl_fd(s,2);
	exit(1);
}

int	ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int	check_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	error_control(char **argv)
{
	int	i;

	i = 1;

	while (argv[i])
	{
		check_is_number(argv[i]);
		if (ft_atoi(argv[i]) && ft_atoi(argv[i]) > 0)
			i++;
		else
		{
			return (1);
		}
	}
	return (0);
}