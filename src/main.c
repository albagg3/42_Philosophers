/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/13 22:50:09 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/defines.h"


void	init_house(int argc, char **argv, t_house *house)
{
	(void)argc;
	(void)argv;
	(void)house;
//rellenar la structura numero de filosofos y decirle a cada filosofo cual es su tenedor, meter el resto de argumentos en las variables de la estructura. 
//crear los threads 1 por filosofo y crear las routinas y las condiciones.	
}

int main(int argc, char **argv)
{
//	struct timeval t;
//	gettimeofday(&t, NULL);
//	printf("seconds : %ld\n", t.tv_sec);
	t_house	house;

	printf("argc=%d", argc);
	if(argc == 5 || argc == 6)
	{
		error_control(argv);
		house.philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		init_house(argc, argv, &house);
	}
	else
	{
		terminate(ERR_NARG);
	}
}

