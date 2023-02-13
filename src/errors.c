/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:39:53 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/13 22:25:18 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/errors.h"
#include <stdio.h>

void	terminate(char *s)
{
	ft_putendl_fd(s,2);
//	exit(1);
}

int     ft_isalpha(int c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return (1);
        return (0);
}

void	check_is_number(char *arg)
{
	int i;

	i = 0;
	while(arg[i])
	{
		if(ft_isalpha(arg[i]))
		{
			printf("se va por aqui");
			terminate(ERR_ARG);
		}
		i++;
	}
}

void	error_control(char **argv)
{
	int i;

	i = 1;

	while(argv[i])
	{
		check_is_number(argv[i]);
		if(ft_atoi(argv[i]) && ft_atoi(argv[i]) > 0)
			i++;
		else
		{
			terminate(ERR_ARG);
			return ;
		}
	}
}

